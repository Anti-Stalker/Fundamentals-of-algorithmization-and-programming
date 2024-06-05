package types

type Building struct {
	Type              string            `json:"type"`
	Name              string            `json:"name"`
	ImageStart        GridPosition      `json:"imageStart"`
	ImpassabilityGrid ImpassabilityGrid `json:"impassabilityGrid"`
	Power             int               `json:"power"`
	Army              []Creature        `json:"army"`
}
