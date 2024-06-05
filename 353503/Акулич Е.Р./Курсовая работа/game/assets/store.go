package assets

import (
	"bytes"
	"fmt"
	"game_try/game/types"
	"image"
	_ "image/png"
	"os"
	"path/filepath"

	"github.com/hajimehoshi/ebiten/v2"
	"golang.org/x/image/font/opentype"
)

type AssetsStore struct {
	store map[string]*ebiten.Image
	font  *opentype.Font
}

func NewAssetsStore() *AssetsStore {
	return &AssetsStore{store: make(map[string]*ebiten.Image)}
}

func (as *AssetsStore) GetFont() (*opentype.Font, error) {
	if as.font != nil {
		return as.font, nil
	}

	path := filepath.Join("assets", "ui", "fonts", "main.ttf")

	b, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("can't read font file(%s): %w", path, err)
	}

	f, err := opentype.Parse(b)
	if err != nil {
		return nil, fmt.Errorf("can't parse font file(%s): %w", path, err)
	}
	as.font = f

	return f, nil
}

func (as *AssetsStore) GetLand(land types.Land) (*ebiten.Image, error) {
	frameKey := fmt.Sprintf("%s:%s", land.Type, land.Frames[0])
	img, ok := as.store[frameKey]
	if !ok {
		img, err := as.loadLand(land)
		if err != nil {
			return nil, fmt.Errorf("can't load land(%s) frame(%s): %w", land.Type, land.Frames[0], err)
		}
		as.store[frameKey] = img
		return img, nil
	}
	return img, nil
}

func (as *AssetsStore) loadLand(land types.Land) (*ebiten.Image, error) {
	if len(land.Frames) == 0 {
		return nil, fmt.Errorf("no frames for land(%s)", land.Type)
	}
	dir, err := os.Getwd()
	if err != nil {
		return nil, err
	}
	framePath := filepath.Join(dir, "assets", "lands", string(land.Type), land.Frames[0]+".png")
	b, err := os.ReadFile(framePath)
	if err != nil {
		return nil, fmt.Errorf("can't read file(%s): %w", framePath, err)
	}
	img, _, err := image.Decode(bytes.NewReader(b))
	if err != nil {
		return nil, fmt.Errorf("can't decode image(%s): %w", framePath, err)
	}
	eImg := ebiten.NewImageFromImage(img)
	return eImg, nil
}

func (as *AssetsStore) GetHero(hero types.Hero) (types.HeroFrames, error) {
	heroFrames := types.HeroFrames{}

	var err error
	heroFrames.StayRight, err = as.getEbitenHeroStayImage(hero, types.Right)
	if err != nil {
		return types.HeroFrames{}, err
	}
	heroFrames.StayLeft, err = as.getEbitenHeroStayImage(hero, types.Left)
	if err != nil {
		return types.HeroFrames{}, err
	}
	heroFrames.StayTop, err = as.getEbitenHeroStayImage(hero, types.Top)
	if err != nil {
		return types.HeroFrames{}, err
	}
	heroFrames.StayBottom, err = as.getEbitenHeroStayImage(hero, types.Bottom)
	if err != nil {
		return types.HeroFrames{}, err
	}
	heroFrames.StayTopLeft, err = as.getEbitenHeroStayImage(hero, types.TopLeft)
	if err != nil {
		return types.HeroFrames{}, err
	}
	heroFrames.StayTopRight, err = as.getEbitenHeroStayImage(hero, types.TopRight)
	if err != nil {
		return types.HeroFrames{}, err
	}
	heroFrames.StayBottomLeft, err = as.getEbitenHeroStayImage(hero, types.BottomLeft)
	if err != nil {
		return types.HeroFrames{}, err
	}
	heroFrames.StayBottomRight, err = as.getEbitenHeroStayImage(hero, types.BottomRight)
	if err != nil {
		return types.HeroFrames{}, err
	}

	return heroFrames, nil
}

func (as *AssetsStore) getEbitenHeroStayImage(hero types.Hero, direction types.HeroDirection) (*ebiten.Image, error) {
	imgKey := filepath.Join("assets", "heroes", string(hero.Name), "stay", fmt.Sprintf("%s.png", direction))
	if img, ok := as.store[imgKey]; ok {
		return img, nil
	}

	dir, err := os.Getwd()
	if err != nil {
		return nil, err
	}
	path := filepath.Join(dir, imgKey)
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("can't read hero img path(%s): %w", imgKey, err)
	}

	img, _, err := image.Decode(bytes.NewReader(b))
	if err != nil {
		return nil, fmt.Errorf("can't decode image(%s): %w", path, err)
	}
	eImg := ebiten.NewImageFromImage(img)
	as.store[imgKey] = eImg

	return eImg, nil
}

func (as *AssetsStore) GetArrowCursor() (*ebiten.Image, error) {
	imgKey := filepath.Join("assets", "cursor", "arrow.png")
	if img, ok := as.store[imgKey]; ok {
		return img, nil
	}
	dir, err := os.Getwd()
	if err != nil {
		return nil, err
	}

	path := filepath.Join(dir, imgKey)
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("can't read cursor img path(%s): %w", imgKey, err)
	}

	img, _, err := image.Decode(bytes.NewReader(b))
	if err != nil {
		return nil, fmt.Errorf("can't decode image(%s): %w", path, err)
	}
	eImg := ebiten.NewImageFromImage(img)
	as.store[imgKey] = eImg

	return eImg, nil

}

func (as *AssetsStore) GetHorseCursor() (*ebiten.Image, error) {
	imgKey := filepath.Join("assets", "cursor", "horse.png")
	if img, ok := as.store[imgKey]; ok {
		return img, nil
	}
	dir, err := os.Getwd()
	if err != nil {
		return nil, err
	}

	path := filepath.Join(dir, imgKey)
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("can't read cursor img path(%s): %w", imgKey, err)
	}

	img, _, err := image.Decode(bytes.NewReader(b))
	if err != nil {
		return nil, fmt.Errorf("can't decode image(%s): %w", path, err)
	}
	eImg := ebiten.NewImageFromImage(img)
	as.store[imgKey] = eImg

	return eImg, nil

}

func (as *AssetsStore) GetPath() (*ebiten.Image, error) {
	imgKey := filepath.Join("assets", "pathmarking", "green", "gcross.png")
	if img, ok := as.store[imgKey]; ok {
		return img, nil
	}
	dir, err := os.Getwd()
	if err != nil {
		return nil, err
	}

	path := filepath.Join(dir, imgKey)
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("can't read cross img path(%s): %w", imgKey, err)
	}

	img, _, err := image.Decode(bytes.NewReader(b))
	if err != nil {
		return nil, fmt.Errorf("can't decode image(%s): %w", path, err)
	}
	eImg := ebiten.NewImageFromImage(img)
	as.store[imgKey] = eImg

	return eImg, nil

}

func (as *AssetsStore) GetCreature(creature types.Creature) ([]*ebiten.Image, error) {
	var frames []*ebiten.Image

	for i := 0; i < creature.FramesCount; i++ {
		frame, err := as.getEbitenCreatureImage(creature, i)
		if err != nil {
			return nil, err
		}
		frames = append(frames, frame)
	}

	return frames, nil
}

func (as *AssetsStore) getEbitenCreatureImage(creature types.Creature, frameNumber int) (*ebiten.Image, error) {
	imgKey := filepath.Join("assets", "creatures", string(creature.Name), fmt.Sprintf("%d.png", frameNumber))
	if img, ok := as.store[imgKey]; ok {
		return img, nil
	}

	dir, err := os.Getwd()
	if err != nil {
		return nil, err
	}
	path := filepath.Join(dir, imgKey)
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("can't read creature img path(%s): %w", imgKey, err)
	}

	img, _, err := image.Decode(bytes.NewReader(b))
	if err != nil {
		return nil, fmt.Errorf("can't decode image(%s): %w", path, err)
	}
	eImg := ebiten.NewImageFromImage(img)
	as.store[imgKey] = eImg

	return eImg, nil
}

func (as *AssetsStore) GetLandscape(landscape types.Landscape) (*ebiten.Image, error) {
	imgKey := filepath.Join("assets", "landscapes", string(landscape.Type), string(landscape.Name)+".png")
	if img, ok := as.store[imgKey]; ok {
		return img, nil
	}

	dir, err := os.Getwd()
	if err != nil {
		return nil, err
	}
	path := filepath.Join(dir, imgKey)
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("can't read landscape img path(%s): %w", imgKey, err)
	}

	img, _, err := image.Decode(bytes.NewReader(b))
	if err != nil {
		return nil, fmt.Errorf("can't decode image(%s): %w", path, err)
	}
	eImg := ebiten.NewImageFromImage(img)
	as.store[imgKey] = eImg

	return eImg, nil
}

func (as *AssetsStore) GetArrow(arrow types.Arrow) (types.ArrowFrames, error) {
	arrowFrames := types.ArrowFrames{}
	var err error
	arrowFrames.ArrowUp, err = as.getEbitenArrowImage(arrow, types.Up)
	if err != nil {
		return types.ArrowFrames{}, err
	}
	arrowFrames.ArrowLeft, err = as.getEbitenArrowImage(arrow, types.East)
	if err != nil {
		return types.ArrowFrames{}, err
	}
	arrowFrames.ArrowRight, err = as.getEbitenArrowImage(arrow, types.West)
	if err != nil {
		return types.ArrowFrames{}, err
	}
	arrowFrames.ArrowDown, err = as.getEbitenArrowImage(arrow, types.Down)
	if err != nil {
		return types.ArrowFrames{}, err
	}
	arrowFrames.ArrowUpRight, err = as.getEbitenArrowImage(arrow, types.UpRight)
	if err != nil {
		return types.ArrowFrames{}, err
	}
	arrowFrames.ArrowUpLeft, err = as.getEbitenArrowImage(arrow, types.UpLeft)
	if err != nil {
		return types.ArrowFrames{}, err
	}
	arrowFrames.ArrowDownRight, err = as.getEbitenArrowImage(arrow, types.DownRight)
	if err != nil {
		return types.ArrowFrames{}, err
	}
	arrowFrames.ArrowDownLeft, err = as.getEbitenArrowImage(arrow, types.DownLeft)
	if err != nil {
		return types.ArrowFrames{}, err
	}

	return arrowFrames, nil
}
func (as *AssetsStore) getEbitenArrowImage(arrow types.Arrow, direction types.ArrowDirection) (*ebiten.Image, error) {
	imgKey := filepath.Join("assets", "pathmarking", "green", fmt.Sprintf("g%s.png", direction))
	if img, ok := as.store[imgKey]; ok {
		return img, nil
	}

	dir, err := os.Getwd()
	if err != nil {
		return nil, err
	}

	path := filepath.Join(dir, imgKey)
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("can't read arrow img path(%s): %w", imgKey, err)
	}

	img, _, err := image.Decode(bytes.NewReader(b))
	if err != nil {
		return nil, fmt.Errorf("can't decode image(%s): %w", path, err)
	}
	eImg := ebiten.NewImageFromImage(img)
	as.store[imgKey] = eImg
	return eImg, nil

}

func (as *AssetsStore) GetArtifacts(artifact types.Artifact) (*ebiten.Image, error) {
	frame, err := as.getEbitenArtifactImage(artifact)
	if err != nil {
		return nil, err
	}
	return frame, nil
}
func (as *AssetsStore) getEbitenArtifactImage(artifact types.Artifact) (*ebiten.Image, error) {
	imgKey := filepath.Join("assets", "artifacts", fmt.Sprintf("%s.png", artifact.Type))
	if img, ok := as.store[imgKey]; ok {
		return img, nil
	}

	dir, err := os.Getwd()
	if err != nil {
		return nil, err
	}
	path := filepath.Join(dir, imgKey)
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("can't read artifact img path(%s): %w", imgKey, err)
	}

	img, _, err := image.Decode(bytes.NewReader(b))
	if err != nil {
		return nil, fmt.Errorf("can't decode image(%s): %w", path, err)
	}
	eImg := ebiten.NewImageFromImage(img)
	as.store[imgKey] = eImg
	return eImg, nil
}

func (as *AssetsStore) GetResources(res types.Resource) ([]*ebiten.Image, error) {
	var frames []*ebiten.Image
	for i := 0; i < 8; i++ {
		frameNumber := fmt.Sprintf("%d", i)
		frame, err := as.getEbitenResourceImage(res.Type, frameNumber)
		if err != nil {
			return nil, err
		}
		frames = append(frames, frame)
	}

	return frames, nil
}

func (as *AssetsStore) getEbitenResourceImage(rType types.ResourceType, frame string) (*ebiten.Image, error) {
	imgKey := filepath.Join("assets", "resources", string(rType), frame+".png")
	if img, ok := as.store[imgKey]; ok {
		return img, nil
	}

	dir, err := os.Getwd()
	if err != nil {
		return nil, err
	}
	path := filepath.Join(dir, imgKey)
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("can't read resource img path(%s): %w", imgKey, err)
	}

	img, _, err := image.Decode(bytes.NewReader(b))
	if err != nil {
		return nil, fmt.Errorf("can't decode image(%s): %w", path, err)
	}
	eImg := ebiten.NewImageFromImage(img)
	as.store[imgKey] = eImg
	return eImg, nil
}

func (as *AssetsStore) GetBuildings(building types.Building) ([]*ebiten.Image, error) {
	framesCnt := 1
	if building.Type == "dynamic" {
		framesCnt = 8
	}

	var frames []*ebiten.Image
	for i := 0; i < framesCnt; i++ {
		frame, err := as.getEbitenBuildingImage(building, i)
		if err != nil {
			return nil, err
		}
		frames = append(frames, frame)
	}

	return frames, nil
}

func (as *AssetsStore) getEbitenBuildingImage(build types.Building, frameNumber int) (*ebiten.Image, error) {
	imgKey := filepath.Join("assets", "building", string(build.Name), fmt.Sprintf("%d.png", frameNumber))
	if img, ok := as.store[imgKey]; ok {
		return img, nil
	}

	dir, err := os.Getwd()
	if err != nil {
		return nil, err
	}
	path := filepath.Join(dir, imgKey)
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("can't read building img path(%s): %w", imgKey, err)
	}

	img, _, err := image.Decode(bytes.NewReader(b))
	if err != nil {
		return nil, fmt.Errorf("can't decode image(%s): %w", path, err)
	}
	eImg := ebiten.NewImageFromImage(img)
	as.store[imgKey] = eImg

	return eImg, nil
}

func (as *AssetsStore) GetModal() (types.ModalImgs, error) {
	modalBorders := types.ModalImgs{}
	var err error

	tlImgKey := filepath.Join("assets", "ui", "modal", "DiBoxTL.png")
	modalBorders.TopLeftEdge, err = as.loadImage(tlImgKey)
	if err != nil {
		return types.ModalImgs{}, err
	}

	trImgKey := filepath.Join("assets", "ui", "modal", "DiBoxTR.png")
	modalBorders.TopRightEdge, err = as.loadImage(trImgKey)
	if err != nil {
		return types.ModalImgs{}, err
	}

	blImgKey := filepath.Join("assets", "ui", "modal", "DiBoxBL.png")
	modalBorders.BottomLeftEdge, err = as.loadImage(blImgKey)
	if err != nil {
		return types.ModalImgs{}, err
	}

	brImgKey := filepath.Join("assets", "ui", "modal", "DiBoxBR.png")
	modalBorders.BottomRightEdge, err = as.loadImage(brImgKey)
	if err != nil {
		return types.ModalImgs{}, err
	}

	tImgKey := filepath.Join("assets", "ui", "modal", "DiBoxT.png")
	modalBorders.Top, err = as.loadImage(tImgKey)
	if err != nil {
		return types.ModalImgs{}, err
	}

	bImgKey := filepath.Join("assets", "ui", "modal", "DiBoxB.png")
	modalBorders.Bottom, err = as.loadImage(bImgKey)
	if err != nil {
		return types.ModalImgs{}, err
	}

	lImgKey := filepath.Join("assets", "ui", "modal", "DiBoxL.png")
	modalBorders.Left, err = as.loadImage(lImgKey)
	if err != nil {
		return types.ModalImgs{}, err
	}

	rImgKey := filepath.Join("assets", "ui", "modal", "DiBoxR.png")
	modalBorders.Right, err = as.loadImage(rImgKey)
	if err != nil {
		return types.ModalImgs{}, err
	}

	bgImgKey := filepath.Join("assets", "ui", "modal", "background.png")
	modalBorders.Background, err = as.loadImage(bgImgKey)
	if err != nil {
		return types.ModalImgs{}, err
	}

	okImgKey := filepath.Join("assets", "ui", "modal", "ok.png")
	modalBorders.Ok, err = as.loadImage(okImgKey)
	if err != nil {
		return types.ModalImgs{}, err
	}

	return modalBorders, nil
}

func (as *AssetsStore) loadImage(imgKey string) (*ebiten.Image, error) {
	if img, ok := as.store[imgKey]; ok {
		return img, nil
	}

	dir, err := os.Getwd()
	if err != nil {
		return nil, err
	}
	path := filepath.Join(dir, imgKey)
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, fmt.Errorf("can't read img path(%s): %w", imgKey, err)
	}

	img, _, err := image.Decode(bytes.NewReader(b))
	if err != nil {
		return nil, fmt.Errorf("can't decode image(%s): %w", path, err)
	}
	eImg := ebiten.NewImageFromImage(img)
	as.store[imgKey] = eImg

	return eImg, nil
}
