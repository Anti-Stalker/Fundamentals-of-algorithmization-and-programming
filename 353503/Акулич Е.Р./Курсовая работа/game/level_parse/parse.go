package level_parse

import (
	"fmt"

	"game_try/game/level_state"
	"game_try/game/level_state/modal"
	"game_try/game/maps"
	"game_try/game/types"
	_ "image/png"

	"github.com/hajimehoshi/ebiten/v2"
)

func GenerateLevel(level types.LevelStartState, assetsStore types.AssetsStorer) (*level_state.LevelState, error) {
	staticView, err := drawMapStaticView(level, assetsStore)
	if err != nil {
		return nil, fmt.Errorf("can't draw map surface: %w", err)
	}

	lMap, err := maps.NewGameMap(level.Grid, staticView)
	if err != nil {
		return nil, fmt.Errorf("can't create map: %w", err)
	}

	return &level_state.LevelState{
		Map:         lMap,
		Hero:        level.Hero,
		AssetsStore: assetsStore,
		Modals:      modal.ModalState{AssetsStore: assetsStore},
	}, nil
}

func drawMapStaticView(level types.LevelStartState, assetsStore types.AssetsStorer) (*ebiten.Image, error) {
	img := ebiten.NewImage(level.Width*types.CellSize, level.Height*types.CellSize)

	for rowIndex, row := range level.Grid {
		for cellIndex, cell := range row {
			err := drawLand(img, cell, cellIndex, rowIndex, assetsStore)
			if err != nil {
				return nil, err
			}
		}
	}

	for rowIndex, row := range level.Grid {
		for cellIndex, cell := range row {
			err := drawLandscape(img, cell, cellIndex, rowIndex, assetsStore)
			if err != nil {
				return nil, err
			}
		}
	}

	for rowIndex, row := range level.Grid {
		for cellIndex, cell := range row {
			err := drawBuilding(img, cell, cellIndex, rowIndex, assetsStore)
			if err != nil {
				return nil, err
			}
		}
	}

	return img, nil
}

func drawLand(img *ebiten.Image, cell types.Cell, x int, y int, assetsStore types.AssetsStorer) error {
	if len(cell.Land.Frames) == 0 {
		return fmt.Errorf("no frames for land(%d:%d)", x, y)
	}
	frameImg, err := assetsStore.GetLand(*cell.Land)
	if err != nil {
		return fmt.Errorf("can't get land(%s) frame(%s): %w", cell.Land.Type, cell.Land.Frames[0], err)
	}
	if frameImg == nil {
		return fmt.Errorf("no assets found for ground(%s) frame(%s)", cell.Land.Type, cell.Land.Frames[0])
	}
	dio := ebiten.DrawImageOptions{}
	dio.GeoM.Translate(float64(x*types.CellSize), float64(y*types.CellSize))
	img.DrawImage(frameImg, &dio)
	return nil
}

func drawBuilding(img *ebiten.Image, cell types.Cell, x int, y int, assetsStore types.AssetsStorer) error {
	if cell.Building == nil || cell.Building.Type == "dynamic" {
		return nil
	}

	buildingImgs, err := assetsStore.GetBuildings(*cell.Building)
	if err != nil {
		return fmt.Errorf("can't get building(%s) image: %w", cell.Building.Name, err)
	}
	if buildingImgs == nil {
		return fmt.Errorf("no assets found for landscape(%s)", cell.Building.Name)
	}
	dio := ebiten.DrawImageOptions{}
	tx := float64((x - cell.Building.ImageStart.X) * types.CellSize)
	ty := float64((y - cell.Building.ImageStart.Y) * types.CellSize)
	dio.GeoM.Translate(tx, ty)
	img.DrawImage(buildingImgs[0], &dio)
	return nil
}

func drawLandscape(img *ebiten.Image, cell types.Cell, x int, y int, assetsStore types.AssetsStorer) error {
	if cell.Landscape == nil {
		return nil
	}
	landscapeImg, err := assetsStore.GetLandscape(*cell.Landscape)
	if err != nil {
		return fmt.Errorf("can't get landscape(%s) image: %w", cell.Landscape.Name, err)
	}
	if landscapeImg == nil {
		return fmt.Errorf("no assets found for landscape(%s)", cell.Landscape.Name)
	}
	dio := ebiten.DrawImageOptions{}
	tx := float64((x - cell.Landscape.ImageStart.X) * types.CellSize)
	ty := float64((y - cell.Landscape.ImageStart.Y) * types.CellSize)
	dio.GeoM.Translate(tx, ty)
	img.DrawImage(landscapeImg, &dio)
	return nil
}
