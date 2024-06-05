package types

type Creature struct {
	Name        string     `json:"name"`
	Count       int        `json:"count"`
	Power       int        `json:"power"`
	Killings    []Creature `json:"killings"`
	FramesCount int        `json:"framesCount"`
}

func (c *Creature) CalculatePower() int {
	return c.Power * c.Count
}
