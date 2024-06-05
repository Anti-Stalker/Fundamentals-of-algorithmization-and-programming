package types

import (
	"github.com/hajimehoshi/ebiten/v2"
	"golang.org/x/image/font/opentype"
)

type AssetsStorer interface {
	GetLand(land Land) (*ebiten.Image, error)
	GetHero(hero Hero) (HeroFrames, error)
	GetLandscape(landscape Landscape) (*ebiten.Image, error)
	GetPath() (*ebiten.Image, error)
	GetHorseCursor() (*ebiten.Image, error)
	GetArrowCursor() (*ebiten.Image, error)
	GetArrow(direction Arrow) (ArrowFrames, error)
	GetArtifacts(artifact Artifact) (*ebiten.Image, error)
	GetBuildings(building Building) ([]*ebiten.Image, error)
	GetCreature(creature Creature) ([]*ebiten.Image, error)
	GetResources(res Resource) ([]*ebiten.Image, error)
	GetModal() (ModalImgs, error)
	GetFont() (*opentype.Font, error)
}

type ModalImgs struct {
	TopLeftEdge     *ebiten.Image
	TopRightEdge    *ebiten.Image
	BottomLeftEdge  *ebiten.Image
	BottomRightEdge *ebiten.Image
	Top             *ebiten.Image
	Bottom          *ebiten.Image
	Left            *ebiten.Image
	Right           *ebiten.Image
	Background      *ebiten.Image
	Ok              *ebiten.Image
}

type HeroFrames struct {
	StayTop         *ebiten.Image
	StayBottom      *ebiten.Image
	StayLeft        *ebiten.Image
	StayRight       *ebiten.Image
	StayTopLeft     *ebiten.Image
	StayTopRight    *ebiten.Image
	StayBottomLeft  *ebiten.Image
	StayBottomRight *ebiten.Image
	RunTop          []*ebiten.Image
	RunBottom       []*ebiten.Image
	RunLeft         []*ebiten.Image
	RunRight        []*ebiten.Image
	RunTopLeft      []*ebiten.Image
	RunTopRight     []*ebiten.Image
	RunBottomLeft   []*ebiten.Image
	RunBottomRight  []*ebiten.Image
}

type ArrowFrames struct {
	ArrowUp        *ebiten.Image
	ArrowRight     *ebiten.Image
	ArrowDown      *ebiten.Image
	ArrowLeft      *ebiten.Image
	ArrowUpRight   *ebiten.Image
	ArrowUpLeft    *ebiten.Image
	ArrowDownRight *ebiten.Image
	ArrowDownLeft  *ebiten.Image
}
