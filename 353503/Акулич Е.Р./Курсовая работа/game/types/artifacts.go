package types

type ArtifactType string

const (
	Helm   ArtifactType = "helm"
	Boots  ArtifactType = "boots"
	Armor  ArtifactType = "armor"
	Sword  ArtifactType = "sword"
	Shield ArtifactType = "shield"
	Ring   ArtifactType = "ring"
)

type Artifact struct {
	Type  ArtifactType `json:"type"`
	Power int          `json:"power"`
}
