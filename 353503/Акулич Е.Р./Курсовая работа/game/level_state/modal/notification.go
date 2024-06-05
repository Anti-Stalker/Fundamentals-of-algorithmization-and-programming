package modal

import (
	"game_try/game/types"

	"github.com/hajimehoshi/ebiten/v2"
	txt "github.com/hajimehoshi/ebiten/v2/text"
	"golang.org/x/image/font"
	"golang.org/x/image/font/opentype"
)

const Notification ModalType = "notification"

type NotificationModal struct {
	ModalType ModalType
	img       *ebiten.Image
	cb        func()
}

func NewNotificationModal(text string, assetsStore types.AssetsStorer, x, y float64, cb func()) (*NotificationModal, error) {
	m := &NotificationModal{
		ModalType: Notification,
		img:       ebiten.NewImage(320, 192),
		cb:        cb,
	}

	f, err := assetsStore.GetFont()
	if err != nil {
		return nil, err
	}

	mImgs, err := assetsStore.GetModal()
	if err != nil {
		return nil, err
	}

	m.img.DrawImage(mImgs.Background, &ebiten.DrawImageOptions{})

	dio := ebiten.DrawImageOptions{}
	m.img.DrawImage(mImgs.TopLeftEdge, &dio)
	dio = ebiten.DrawImageOptions{}
	dio.GeoM.Translate(0, 64)
	m.img.DrawImage(mImgs.Left, &dio)
	dio = ebiten.DrawImageOptions{}
	dio.GeoM.Translate(0, 64*2)
	m.img.DrawImage(mImgs.BottomLeftEdge, &dio)
	for i := 1.0; i < 4; i++ {
		dio = ebiten.DrawImageOptions{}
		dio.GeoM.Translate(64*i, 0)
		m.img.DrawImage(mImgs.Top, &dio)
	}
	for i := 1.0; i < 4; i++ {
		dio = ebiten.DrawImageOptions{}
		dio.GeoM.Translate(64*i, 64*2)
		m.img.DrawImage(mImgs.Bottom, &dio)
	}
	dio = ebiten.DrawImageOptions{}
	dio.GeoM.Translate(64*4, 0)
	m.img.DrawImage(mImgs.TopRightEdge, &dio)
	dio = ebiten.DrawImageOptions{}
	dio.GeoM.Translate(64*4, 64)
	m.img.DrawImage(mImgs.Right, &dio)
	dio = ebiten.DrawImageOptions{}
	dio.GeoM.Translate(64*4, 64*2)
	m.img.DrawImage(mImgs.BottomRightEdge, &dio)
	dio = ebiten.DrawImageOptions{}
	dio.GeoM.Translate(125, 64*2)
	m.img.DrawImage(mImgs.Ok, &dio)

	ff, err := opentype.NewFace(f, &opentype.FaceOptions{
		Size:    float64(50),
		DPI:     20,
		Hinting: font.HintingFull,
	})
	if err != nil {
		return nil, err
	}

	dio = ebiten.DrawImageOptions{}
	dio.ColorM.Scale(255, 255, 255, 255)
	dio.GeoM.Translate(x, y)
	txt.DrawWithOptions(m.img, text, ff, &dio)

	return m, nil
}

func (nm *NotificationModal) GetImage() *ebiten.Image {
	return nm.img
}

func (nm *NotificationModal) HandleClick(x, y int) {
	nm.cb()
}
