package level_state

import (
	"fmt"
	"game_try/game/level_state/modal"
	"game_try/game/maps"
	"game_try/game/types"
	"time"
)

type LevelState struct {
	Map              *maps.GameMap
	Hero             types.Hero
	TickCount        int
	AssetsStore      types.AssetsStorer
	Modals           modal.ModalState
	pathTo           types.GridPosition
	path             []types.GridPosition
	arrow            types.Arrow
	needToMarkTheWay bool
	lastMapClickTime time.Time
	isHeroMoving     bool
	heroMoveStamp    time.Time
}

func (ls *LevelState) paveTheWay(p types.GridPosition) {
	if !ls.Map.IsInsideMap(p) {
		ls.needToMarkTheWay = false
		return
	}
	if ls.Map.IsImpassableAt(p) || p.IsEqual(ls.Hero.Position) {
		ls.needToMarkTheWay = false
		return
	}

	if p.IsEqual(ls.pathTo) {
		return
	}

	ls.path = ls.Map.GetPath(ls.Hero.Position, p)
	if len(ls.path) == 0 {
		ls.needToMarkTheWay = false
		return
	}
	ls.pathTo = p
	ls.needToMarkTheWay = true
}

func (ls *LevelState) HandleMapClick(x, y int) {
	if ls.isHeroMoving {
		return
	}

	if ls.Modals.ActiveModal != nil {
		if x >= 285 && x <= 350 && y >= 350 && y <= 390 {
			ls.Modals.ActiveModal.HandleClick(x, y)
		}
		return
	}

	p := types.GridPosition{
		X: x / types.CellSize,
		Y: y / types.CellSize,
	}

	if !ls.Map.IsInsideMap(p) {
		return
	}

	if p.IsEqual(ls.Hero.Position) {
		return
	}

	if !ls.lastMapClickTime.IsZero() && p.IsEqual(ls.pathTo) {
		if time.Since(ls.lastMapClickTime) < time.Millisecond*100 {
			ls.lastMapClickTime = time.Now()
			return
		} else {
			ls.startHeroMovement()
			return
		}
	}

	ls.lastMapClickTime = time.Now()
	ls.paveTheWay(p)
}

func (ls *LevelState) startHeroMovement() {
	ls.lastMapClickTime = time.Time{}
	ls.isHeroMoving = true
	ls.needToMarkTheWay = false
}

func (ls *LevelState) UpdateState() {
	ls.TickCount++
	if ls.isHeroMoving {
		if ls.heroMoveStamp.IsZero() {
			ls.heroMoveStamp = time.Now()
		}

		if time.Since(ls.heroMoveStamp) > time.Millisecond*40 {
			path := ls.Map.GetPath(ls.Hero.Position, ls.pathTo)
			ls.Hero.ChangeDirection(path[1])
			if len(path) == 0 {
				ls.isHeroMoving = false
				ls.heroMoveStamp = time.Time{}
				return
			}

			ls.Hero.Position = path[1]
			ls.heroMoveStamp = time.Now()

			if ls.Hero.Position.IsEqual(ls.pathTo) {
				ls.isHeroMoving = false
				ls.heroMoveStamp = time.Time{}
				ls.checkCellInteractions()
			}
		}
	}
}

func (ls *LevelState) checkCellInteractions() {
	cell := ls.Map.GetCell(ls.Hero.Position)
	if cell.Artifact != nil {
		err := ls.Modals.SetNotificationModal("You picked up the artifact", 55, 80)
		if err != nil {
			fmt.Printf("can't set notification modal: %v", err)
		}
		ls.Hero.Artifacts = append(ls.Hero.Artifacts, *cell.Artifact)
		cell.Artifact = nil
	} else if cell.Creature != nil {
		if ls.Hero.CalculatePower(ls.Hero.Position) > cell.Creature.CalculatePower() {
			ls.Hero.SubstractArmyLosses(cell.Creature.Killings)
			ls.Map.ClearCreatureBlocking(ls.Hero.Position)
			cell.Creature = nil
			ls.Hero.PrintState()
		} else {
			err := ls.Modals.SetNotificationGameEndModal("You lost the battle! Game over!", 55, 80)
			if err != nil {
				fmt.Printf("can't set notification modal: %v", err)
			}
		}
	} else if cell.Resource != nil {
		ls.Hero.CalculateResources(cell.Resource.AddRes)
		cell.Resource = nil
		ls.Hero.PrintState()
	} else if cell.Building != nil {
		if cell.Building.Power != 0 {
			err := ls.Modals.SetNotificationModal("You get +1000 army power", 80, 80)
			if err != nil {
				fmt.Printf("can't set notification modal: %v", err)
			}
			ls.Hero.Building = append(ls.Hero.Building, *cell.Building)
			cell.Building.Power = 0
		} else {
			err := ls.Modals.SetNotificationModal("You have already visited this place", 50, 80)
			if err != nil {
				fmt.Printf("can't set notification modal: %v", err)
			}
		}

		ls.Hero.PrintState()
	} else if cell.ArmyShop != nil {
		bought := ls.Hero.TryBuyArmy(cell.ArmyShop)
		if bought {
			cell.ArmyShop = nil
			err := ls.Modals.SetNotificationModal("You successfuly bought the army", 60, 80)
			if err != nil {
				fmt.Printf("can't set notification modal: %v", err)
			}
		} else {
			text := "Not enough resources\nif you want to buy cyclops you \nshould to find 2 gold and 1 crystall"
			for _, c := range cell.ArmyShop.Creatures {
				if c.Name == "angels" {
					text = "Not enough resources\nif you want to buy angels you \nshould to find 3 gems"

					break
				}
			}
			err := ls.Modals.SetNotificationModal(text, 40, 60)
			if err != nil {
				fmt.Printf("can't set notification modal: %v", err)
			}
		}
		ls.Hero.PrintState()
	} else if cell.Power != 0 {
		if cell.Power == 1000 {
			err := ls.Modals.SetNotificationModal("You get +1000 army power", 80, 80)
			if err != nil {
				fmt.Printf("can't set notification modal: %v", err)
			}
			ls.Hero.PowerFromBuildings += cell.Power
			cell.Power = 1
		} else {
			err := ls.Modals.SetNotificationModal("You have already visited this place", 50, 80)
			if err != nil {
				fmt.Printf("can't set notification modal: %v", err)
			}
		}
		ls.Hero.PrintState()

	} else if cell.Gates != nil {
		if ls.Hero.ArtifactCheck(cell.Gates) {
			err := ls.Modals.SetNotificationModal("You opened the gate", 80, 80)
			if err != nil {
				fmt.Printf("can't set notification modal: %v", err)
			}
			ls.Map.ClearGatesBlocking(ls.Hero.Position)
		} else {
			err := ls.Modals.SetNotificationModal("if you want to get through this gate \n you need to find a sword,\n shield and armor", 50, 80)
			if err != nil {
				fmt.Printf("can't set notification modal: %v", err)
			}
		}
	} else if cell.WinPoint != nil {
		err := ls.Modals.SetNotificationGameEndModal("CONGRATULATIONS!!!YOU WIN", 50, 80)
		if err != nil {
			fmt.Printf("can't set notification modal: %v", err)
		}
	}
}
