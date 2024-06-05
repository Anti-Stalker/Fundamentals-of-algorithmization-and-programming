package types

type ResourceType string

const (
	Gold     ResourceType = "gold"
	Wood     ResourceType = "wood"
	Crystals ResourceType = "crystals"
	Gems     ResourceType = "gems"
	Mercury  ResourceType = "mercury"
	Ore      ResourceType = "ore"
	Sulfur   ResourceType = "sulfur"
)

type Resource struct {
	Type       ResourceType `json:"type"`
	Count      int          `json:"count"`
	ImageStart GridPosition `json:"imageStart"`
	AddRes     []Resource   `json:"addres"`
}
