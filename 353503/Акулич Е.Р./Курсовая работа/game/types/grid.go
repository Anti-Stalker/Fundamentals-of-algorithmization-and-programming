package types

const CellSize = 32

type GridPosition struct {
	Y int `json:"y"`
	X int `json:"x"`
}

func (gp GridPosition) IsEqual(other GridPosition) bool {
	return gp.X == other.X && gp.Y == other.Y
}

type Grid [][]Cell

type Cell struct {
	Land      *Land      `json:"land"`
	Resource  *Resource  `json:"resources"`
	Landscape *Landscape `json:"landscape"`
	Artifact  *Artifact  `json:"artifact"`
	Building  *Building  `json:"building"`
	Creature  *Creature  `json:"creature"`
	Gates     []Artifact `json:"gates"`
	WinPoint  *Building  `json:"winpoint"`
	ArmyShop  *ArmyShop  `json:"armyShop"`
	Power     int        `ison:"power"`
}

type ImpassabilityGrid [][]bool
