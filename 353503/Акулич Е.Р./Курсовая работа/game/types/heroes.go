package types

import "fmt"

type HeroDirection string

const (
	Top         HeroDirection = "top"
	Left        HeroDirection = "left"
	Right       HeroDirection = "right"
	Bottom      HeroDirection = "bottom"
	TopLeft     HeroDirection = "top-left"
	TopRight    HeroDirection = "top-right"
	BottomLeft  HeroDirection = "bottom-left"
	BottomRight HeroDirection = "bottom-right"
)

func (h *Hero) ChangeDirection(other GridPosition) {
	switch {
	case h.Position.X == other.X && h.Position.Y == other.Y+1:
		//arrowImg = arrows.ArrowUp
		h.Direction = Top
	case other.X == h.Position.X-1 && h.Position.Y == other.Y:
		//arrowImg = arrows.ArrowLeft
		h.Direction = Left
	case h.Position.X == other.X && other.Y == h.Position.Y+1:
		//arrowImg = arrows.ArrowDown
		h.Direction = Bottom
	case h.Position.X == other.X-1 && h.Position.Y == other.Y:
		//arrowImg = arrows.ArrowRight
		h.Direction = Right
	case h.Position.X == other.X-1 && h.Position.Y == other.Y+1:
		//arrowImg = arrows.ArrowUpRight
		h.Direction = TopRight
	case h.Position.X == other.X-1 && h.Position.Y == other.Y-1:
		//arrowImg = arrows.ArrowDownRight
		h.Direction = BottomRight
	case h.Position.X == other.X+1 && h.Position.Y == other.Y-1:
		//arrowImg = arrows.ArrowDownLeft
		h.Direction = BottomLeft
	case h.Position.X == other.X+1 && h.Position.Y == other.Y+1:
		//arrowImg = arrows.ArrowUpLeft
		h.Direction = TopLeft
	}

}

type HeroType string

const Legionary HeroType = "legionary"

type Hero struct {
	Name               HeroType      `json:"name"`
	Position           GridPosition  `json:"position"`
	Direction          HeroDirection `json:"direction"`
	Army               []Creature    `json:"army"`
	Artifacts          []Artifact    `json:"artifacts"`
	Resources          []Resource    `json:"resources"`
	Building           []Building    `json:"buildings"`
	PowerFromBuildings int           `json:"powerfrombuildings"`
}

func (h *Hero) PrintState() {
	fmt.Printf("Hero State:\nArmy: %v\nResources: %v\nBuildings: %v\nArtivacts: %v\nPFB: %v \n",
		h.Army, h.Resources, h.Building, h.Artifacts, h.PowerFromBuildings)
}

func (h *Hero) CalculatePower(p GridPosition) int {
	var power int
	for _, creature := range h.Army {
		power += creature.Power * creature.Count
	}
	for _, artifact := range h.Artifacts {
		power += artifact.Power
	}
	for _, building := range h.Building {
		power += building.Power
	}
	power += h.PowerFromBuildings
	return power
}

func (h *Hero) CalculateResources(addResource []Resource) {
	for _, addRes := range addResource {
		for i, res := range h.Resources {
			if res.Type == addRes.Type {
				if result := h.Resources[i].Count + addRes.Count; result > 0 {
					h.Resources[i].Count = result
				}
			}
		}
	}
}

func (h *Hero) TryBuyArmy(shop *ArmyShop) bool {
	isEnoughResources := true

shopCostLoop:
	for _, sr := range shop.Cost {
		rFound := false
		for _, hr := range h.Resources {
			if hr.Type == sr.Type {
				if hr.Count < sr.Count {
					isEnoughResources = false
					break shopCostLoop
				}
				rFound = true
				break
			}
		}
		if !rFound {
			isEnoughResources = false
			break
		}
	}

	if isEnoughResources {
		for _, cr := range shop.Creatures {
			found := false

			for i, hr := range h.Army {
				if cr.Name == hr.Name {
					h.Army[i].Count += cr.Count
					found = true
					break
				}
			}

			if !found {
				h.Army = append(h.Army, cr)
			}
		}

		for _, r := range shop.Cost {
			for i, res := range h.Resources {
				if res.Type == r.Type {
					h.Resources[i].Count -= r.Count
				}
			}
		}
		return true
	}
	return false
}
func (h *Hero) ArtifactCheck(artifactGate []Artifact) bool {
	q1 := false
	q2 := false
	for _, artifactGt := range artifactGate {
		for _, art := range h.Artifacts {
			if (artifactGt.Type == art.Type) && art.Type == "shield" {
				q1 = true
			}

			if (artifactGt.Type == art.Type) && art.Type == "armor" {
				q2 = true
			}
		}
	}

	return q1 && q2

}

func (h *Hero) SubstractArmyLosses(armyLosses []Creature) {
	for _, lossCreature := range armyLosses {
		for i, creature := range h.Army {
			if creature.Name == lossCreature.Name {
				if result := h.Army[i].Count - lossCreature.Count; result > 0 {
					h.Army[i].Count = result
				} else {
					h.Army[i].Count = 0
				}
			}
		}
	}
}
