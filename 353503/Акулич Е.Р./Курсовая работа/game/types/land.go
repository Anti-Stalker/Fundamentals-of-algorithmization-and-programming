package types

type LandType string

const (
	Snow         LandType = "snow"
	Grass        LandType = "grass"
	Sand         LandType = "sand"
	Swamp        LandType = "swamp"
	Dirt         LandType = "dirt"
	Water        LandType = "water"
	Subterranean LandType = "subterranean"
)

type Land struct {
	Type   LandType `json:"type"`
	Frames []string `json:"frames"`
}
