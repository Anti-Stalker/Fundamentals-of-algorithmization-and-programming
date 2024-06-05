package main

import (
	_ "embed"
	"game_try/game"
	"game_try/game/assets"
	"game_try/game/level_parse"
	"game_try/game/types"
	"log"

	"encoding/json"

	"github.com/hajimehoshi/ebiten/v2"
)

//go:embed levels/test_level.json
var level []byte

//go:embed configs/translations/all.json
var translationsYaml []byte

const language = "ru"

func main() {
	ebiten.SetWindowSize(32*20, 32*20)
	ebiten.SetWindowTitle("Heroes of Might and Magic III")

	var translations map[string]map[string]string
	err := json.Unmarshal(translationsYaml, &translations)
	if err != nil {
		log.Fatal(err)
	}

	translationsForLang := map[string]string{}
	for k, t := range translations {
		translationsForLang[k] = t[language]
	}

	assetsStore := assets.NewAssetsStore()

	var lvl types.LevelStartState
	err = json.Unmarshal(level, &lvl)
	if err != nil {
		log.Fatal(err)
	}

	levelState, err := level_parse.GenerateLevel(lvl, assetsStore)
	if err != nil {
		log.Fatal(err)
	}

	homm3Game, err := game.NewHoMM3Game(levelState, translationsForLang)
	if err != nil {
		log.Fatal(err)
	}

	if err = ebiten.RunGame(homm3Game); err != nil {
		log.Fatal(err)
	}
}
