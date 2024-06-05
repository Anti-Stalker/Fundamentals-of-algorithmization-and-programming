package game

import (
	"game_try/game/level_state"

	"github.com/hajimehoshi/ebiten/v2"
)

type Homm3Game struct {
	translations map[string]string
	levelState   *level_state.LevelState
}

func (g *Homm3Game) Layout(outsideWidth, outsideHeight int) (int, int) {
	return 32 * 20, 32 * 20
}

func (g *Homm3Game) Update() error {
	if ebiten.IsMouseButtonPressed(ebiten.MouseButtonLeft) {
		g.levelState.HandleMapClick(ebiten.CursorPosition())
	}
	g.levelState.UpdateState()
	return nil
}

func (g *Homm3Game) Draw(screen *ebiten.Image) {
	img, err := g.levelState.Draw()
	if err != nil {
		panic(err)
	}

	// ebitenutil.DebugPrint(mapImg, fmt.Sprintf("%f", ebiten.CurrentFPS()))

	dio := &ebiten.DrawImageOptions{}
	screen.DrawImage(img, dio)
}

func NewHoMM3Game(level *level_state.LevelState, translations map[string]string) (*Homm3Game, error) {
	return &Homm3Game{
		levelState:   level,
		translations: translations,
	}, nil
}
