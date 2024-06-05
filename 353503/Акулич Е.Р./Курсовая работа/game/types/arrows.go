package types

type ArrowDirection string

const (
	Up        ArrowDirection = "up"
	West      ArrowDirection = "right"
	East      ArrowDirection = "left"
	Down      ArrowDirection = "down"
	UpRight   ArrowDirection = "northwest"
	UpLeft    ArrowDirection = "northeast"
	DownRight ArrowDirection = "southwest"
	DownLeft  ArrowDirection = "southeast"
)

type Arrow struct {
	Direction ArrowDirection
}
