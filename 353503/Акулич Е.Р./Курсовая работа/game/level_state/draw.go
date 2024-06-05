package level_state

import (
	"errors"
	"fmt"
	"game_try/game/types"

	"github.com/hajimehoshi/ebiten/v2"
)

func (ls *LevelState) Draw() (*ebiten.Image, error) {
	frame := ebiten.NewImageFromImage(ls.Map.MapStaticView)

	img, err := ls.DrawArtifact(frame)
	if err != nil {
		return nil, err
	}

	img, err = ls.DrawCreature(img)
	if err != nil {
		return nil, err
	}

	img, err = ls.DrawResources(img)
	if err != nil {
		return nil, err
	}

	img, err = ls.DrawBuilding(img)
	if err != nil {
		return nil, err
	}

	img, err = ls.DrowHero(img)
	if err != nil {
		return nil, err
	}

	if ls.needToMarkTheWay {
		img, err = ls.MarkTheWay(img)
		if err != nil {
			return nil, err
		}
	}

	if ls.Modals.ActiveModal != nil {
		modalImg := ls.Modals.ActiveModal.GetImage()
		dio := ebiten.DrawImageOptions{}
		tx := (types.CellSize*ls.Map.Width - modalImg.Bounds().Dx()) / 2
		ty := (types.CellSize*ls.Map.Height - modalImg.Bounds().Dy()) / 2
		dio.GeoM.Translate(float64(tx), float64(ty))
		img.DrawImage(modalImg, &dio)
	}

	return img, nil
}

func (ls *LevelState) MarkTheWay(levelFrame *ebiten.Image) (*ebiten.Image, error) {
	arrows, err := ls.AssetsStore.GetArrow(ls.arrow)
	if err != nil {
		return nil, err
	}

	for i := 1; i < len(ls.path)-1; i++ {
		currentCell := ls.path[i]
		nextCell := ls.path[i+1]

		var arrowImg *ebiten.Image

		switch {
		case currentCell.X == nextCell.X && nextCell.Y == currentCell.Y-1:
			arrowImg = arrows.ArrowUp
		case nextCell.X == currentCell.X-1 && currentCell.Y == nextCell.Y:
			arrowImg = arrows.ArrowLeft
		case currentCell.X == nextCell.X && nextCell.Y == currentCell.Y+1:
			arrowImg = arrows.ArrowDown
		case currentCell.X == nextCell.X-1 && currentCell.Y == nextCell.Y:
			arrowImg = arrows.ArrowRight
		case currentCell.X == nextCell.X-1 && currentCell.Y == nextCell.Y+1:
			arrowImg = arrows.ArrowUpRight
		case currentCell.X == nextCell.X-1 && currentCell.Y == nextCell.Y-1:
			arrowImg = arrows.ArrowDownRight
		case currentCell.X == nextCell.X+1 && currentCell.Y == nextCell.Y-1:
			arrowImg = arrows.ArrowDownLeft
		case currentCell.X == nextCell.X+1 && currentCell.Y == nextCell.Y+1:
			arrowImg = arrows.ArrowUpLeft
		}

		dio := ebiten.DrawImageOptions{}
		dio.GeoM.Translate(float64(currentCell.X)*types.CellSize, float64(currentCell.Y)*types.CellSize)
		levelFrame.DrawImage(arrowImg, &dio)
	}

	crossImg, err := ls.AssetsStore.GetPath()
	if err != nil {
		return nil, err
	}
	if crossImg == nil {
		return nil, fmt.Errorf("no cross image found: %w", err)
	}
	dio := ebiten.DrawImageOptions{}
	dio.GeoM.Translate(float64(ls.pathTo.X)*types.CellSize, float64(ls.pathTo.Y)*types.CellSize)
	levelFrame.DrawImage(crossImg, &dio)

	return levelFrame, nil
}

func (ls *LevelState) DrawResources(levelFrame *ebiten.Image) (*ebiten.Image, error) {
	for y, row := range ls.Map.Grid {
		for x, cell := range row {
			if cell.Resource == nil {
				continue
			}

			resourceImgs, err := ls.AssetsStore.GetResources(*cell.Resource)
			if err != nil {
				return nil, fmt.Errorf("can't get resource(%s) image: %w", cell.Resource.Type, err)
			}
			if resourceImgs == nil {
				return nil, fmt.Errorf("no assets found for resource(%s)", cell.Resource.Type)
			}

			frameIndex := (ls.TickCount / 20) % len(resourceImgs)
			resourceImg := resourceImgs[frameIndex]

			dio := ebiten.DrawImageOptions{}
			tx := (x - cell.Resource.ImageStart.X) * types.CellSize
			ty := (y - cell.Resource.ImageStart.Y) * types.CellSize
			dio.GeoM.Translate(float64(tx), float64(ty))
			levelFrame.DrawImage(resourceImg, &dio)
		}
	}
	return levelFrame, nil
}

func (ls *LevelState) DrawBuilding(levelFrame *ebiten.Image) (*ebiten.Image, error) {
	for y, row := range ls.Map.Grid {
		for x, cell := range row {
			if cell.Building == nil {
				continue
			}

			buildingImgs, err := ls.AssetsStore.GetBuildings(*cell.Building)
			if err != nil {
				return nil, fmt.Errorf("can't get building(%s) image: %w", cell.Building.Name, err)
			}
			if buildingImgs == nil {
				return nil, fmt.Errorf("no assets found for building(%s)", cell.Building.Name)
			}

			frameIndex := (ls.TickCount / 20) % len(buildingImgs)
			buildingImg := buildingImgs[frameIndex]

			dio := ebiten.DrawImageOptions{}
			tx := (x - cell.Building.ImageStart.X) * types.CellSize
			ty := (y - cell.Building.ImageStart.Y) * types.CellSize
			dio.GeoM.Translate(float64(tx), float64(ty))
			levelFrame.DrawImage(buildingImg, &dio)
		}
	}
	return levelFrame, nil
}

func (ls *LevelState) DrawCreature(levelFrame *ebiten.Image) (*ebiten.Image, error) {
	for y, row := range ls.Map.Grid {
		for x, cell := range row {
			if cell.Creature == nil {
				continue
			}

			creatureImgs, err := ls.AssetsStore.GetCreature(*cell.Creature)
			if err != nil {
				return nil, fmt.Errorf("can't get creature(%s) image: %w", cell.Creature.Name, err)
			}
			if creatureImgs == nil {
				return nil, fmt.Errorf("no assets found for creature(%s)", cell.Creature.Name)
			}

			frameIndex := (ls.TickCount / 15) % len(creatureImgs)
			creatureImg := creatureImgs[frameIndex]

			dio := ebiten.DrawImageOptions{}
			tx := x * types.CellSize
			ty := y * types.CellSize
			dio.GeoM.Scale(0.8, 0.8)
			dio.GeoM.Translate(float64(tx-types.CellSize/2), float64(float64(ty)-float64(types.CellSize)/1.6))
			levelFrame.DrawImage(creatureImg, &dio)
		}
	}

	return levelFrame, nil
}

func (ls *LevelState) DrawArtifact(levelFrame *ebiten.Image) (*ebiten.Image, error) {
	for y, row := range ls.Map.Grid {
		for x, cell := range row {
			if cell.Artifact == nil {
				continue
			}

			artifactImg, err := ls.AssetsStore.GetArtifacts(*cell.Artifact)
			if err != nil {
				return nil, fmt.Errorf("can't get artifact(%s) image: %w", cell.Artifact.Type, err)
			}
			if artifactImg == nil {
				return nil, fmt.Errorf("no assets found for artifact(%s)", cell.Artifact.Type)
			}

			dio := ebiten.DrawImageOptions{}
			tx := x * types.CellSize
			ty := y * types.CellSize
			dio.GeoM.Scale(0.6, 0.6)
			dio.GeoM.Translate(float64(tx), float64(ty))
			levelFrame.DrawImage(artifactImg, &dio)
		}
	}

	return levelFrame, nil
}

func (ls *LevelState) DrowHero(levelFrame *ebiten.Image) (*ebiten.Image, error) {
	frames, err := ls.AssetsStore.GetHero(ls.Hero)
	if err != nil {
		return nil, err
	}
	var frame *ebiten.Image
	switch ls.Hero.Direction {
	case types.Top:
		frame = frames.StayTop
	case types.Bottom:
		frame = frames.StayBottom
	case types.Left:
		frame = frames.StayLeft
	case types.Right:
		frame = frames.StayRight
	case types.TopLeft:
		frame = frames.StayTopLeft
	case types.TopRight:
		frame = frames.StayTopRight
	case types.BottomLeft:
		frame = frames.StayBottomLeft
	case types.BottomRight:
		frame = frames.StayBottomRight
	default:
		return nil, errors.New("hero invalid direction")
	}

	dio := ebiten.DrawImageOptions{}
	tx := float64((ls.Hero.Position.X - 1) * types.CellSize)
	ty := float64((ls.Hero.Position.Y-1)*types.CellSize) - (types.CellSize * 0.20)
	dio.GeoM.Translate(tx, ty)
	levelFrame.DrawImage(frame, &dio)
	return levelFrame, nil
}
