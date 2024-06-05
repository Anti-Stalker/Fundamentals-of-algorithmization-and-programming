package types

type ArmyShop struct {
	Creatures []Creature `json:"creatures"`
	Cost      []Resource `json:"cost"`
}
