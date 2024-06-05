package types

type LevelStartState struct {
	Hero   Hero `json:"hero"`
	Height int  `json:"height"`
	Width  int  `json:"width"`
	Grid   Grid `json:"grid"`
}
