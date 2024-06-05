package maps

import (
	"fmt"
	"game_try/game/types"

	"github.com/hajimehoshi/ebiten/v2"
)

type GameMap struct {
	Grid               types.Grid
	Height             int
	Width              int
	MapStaticView      *ebiten.Image
	ImpassabilityGrid  types.ImpassabilityGrid
	CreaturesBlockGrid types.ImpassabilityGrid
	GatesBlockGrid     types.ImpassabilityGrid
}

func NewGameMap(grid types.Grid, msv *ebiten.Image) (*GameMap, error) {
	if len(grid) == 0 {
		return nil, fmt.Errorf("map init - empty grid")
	}
	if len(grid[0]) == 0 {
		return nil, fmt.Errorf("map init - empty row")
	}
	gbg := make(types.ImpassabilityGrid, len(grid))
	for i := range gbg {
		gbg[i] = make([]bool, len(grid[i]))
	}

	ig := make(types.ImpassabilityGrid, len(grid))
	for i := range ig {
		ig[i] = make([]bool, len(grid[i]))
	}

	cbg := make(types.ImpassabilityGrid, len(grid))
	for i := range cbg {
		cbg[i] = make([]bool, len(grid[i]))
	}

	IndicatePassability(grid, ig)
	IndicateCreaturesBlock(grid, cbg)
	IndicateGatesBlock(grid, gbg)
	PrintDepugPassabilityGrid(ig, cbg, gbg)

	return &GameMap{
		Grid:               grid,
		Height:             len(grid),
		Width:              len(grid[0]),
		ImpassabilityGrid:  ig,
		CreaturesBlockGrid: cbg,
		MapStaticView:      msv,
		GatesBlockGrid:     gbg,
	}, nil

}

func (m *GameMap) IsImpassableAt(p types.GridPosition) bool {
	if !m.IsInsideMap(p) {
		return true
	}
	return m.ImpassabilityGrid[p.Y][p.X] || m.CreaturesBlockGrid[p.Y][p.X] || m.GatesBlockGrid[p.Y][p.X]
}

func (m *GameMap) IsInsideMap(p types.GridPosition) bool {
	if len(m.Grid) <= p.Y || p.Y < 0 {
		return false
	}
	if len(m.Grid[p.Y]) <= p.X || p.X < 0 {
		return false
	}
	return true
}

func (m *GameMap) GetCell(p types.GridPosition) *types.Cell {
	if !m.IsInsideMap(p) {
		return nil
	}
	return &m.Grid[p.Y][p.X]
}

func (m *GameMap) ClearCreatureBlocking(p types.GridPosition) {
	if !m.IsInsideMap(p) {
		return
	}

	if p.Y-1 >= 0 {
		m.CreaturesBlockGrid[p.Y-1][p.X] = false
	}
	if p.X+1 < len(m.CreaturesBlockGrid) {
		m.CreaturesBlockGrid[p.Y][p.X+1] = false
	}
	if p.X-1 >= 0 {
		m.CreaturesBlockGrid[p.Y][p.X-1] = false
	}
	if p.Y-1 >= 0 && p.X+1 < len(m.CreaturesBlockGrid) {
		m.CreaturesBlockGrid[p.Y-1][p.X+1] = false
	}
	if p.Y-1 >= 0 && p.X-1 >= 0 {
		m.CreaturesBlockGrid[p.Y-1][p.X-1] = false
	}
}

func (m *GameMap) ClearGatesBlocking(p types.GridPosition) {
	if !m.IsInsideMap(p) {
		return
	}

	m.GatesBlockGrid[p.Y+1][p.X] = false

	m.GatesBlockGrid[p.Y+1][p.X+1] = false

	m.GatesBlockGrid[p.Y+1][p.X-1] = false

}
