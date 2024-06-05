package types

type Landscape struct {
	Type              string            `json:"type"`
	Name              string            `json:"name"`
	ImageStart        GridPosition      `json:"imageStart"`
	ImpassabilityGrid ImpassabilityGrid `json:"impassabilityGrid"`
}
