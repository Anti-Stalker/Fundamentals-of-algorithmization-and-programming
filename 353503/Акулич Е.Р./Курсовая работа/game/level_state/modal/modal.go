package modal

import (
	"game_try/game/types"
	"os"

	"github.com/hajimehoshi/ebiten/v2"
)

type Modal interface {
	GetImage() *ebiten.Image
	HandleClick(x, y int)
}

type ModalType string

type ModalState struct {
	ActiveModal Modal
	AssetsStore types.AssetsStorer
}

func (ms *ModalState) SetNotificationModal(text string, x, y float64) error {
	m, err := NewNotificationModal(text, ms.AssetsStore, x, y, func() {
		ms.ActiveModal = nil
	})
	if err != nil {
		return err
	}

	ms.ActiveModal = m
	return nil
}

func (ms *ModalState) SetNotificationGameEndModal(text string, x, y float64) error {
	m, err := NewNotificationModal(text, ms.AssetsStore, x, y, func() {
		os.Exit(0)
	})
	if err != nil {
		return err
	}

	ms.ActiveModal = m
	return nil
}
