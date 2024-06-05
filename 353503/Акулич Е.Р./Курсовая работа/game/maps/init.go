package maps

import (
	"fmt"
	"game_try/game/types"
)

func IndicatePassability(mg types.Grid, ig types.ImpassabilityGrid) {
	for mgRowIndex, mgRow := range mg {
		for mgCellIndex, mgCell := range mgRow {
			var pg types.ImpassabilityGrid

			if mgCell.Landscape != nil && mgCell.Landscape.ImpassabilityGrid != nil {
				pg = mgCell.Landscape.ImpassabilityGrid
			} else if mgCell.Building != nil && mgCell.Building.ImpassabilityGrid != nil {
				pg = mgCell.Building.ImpassabilityGrid
			} else {
				continue
			}

			for pgRowIndex, pgRow := range pg {
				for pgCellIndex, pgCell := range pgRow {
					if pgCell {
						mgUnpassableRowIndex := mgRowIndex + pgRowIndex
						if mgUnpassableRowIndex >= len(ig) {
							continue
						}
						mgUnpassableCellIndex := mgCellIndex + pgCellIndex
						if mgUnpassableCellIndex >= len(ig[mgUnpassableRowIndex]) {
							continue
						}
						ig[mgRowIndex+pgRowIndex][mgCellIndex+pgCellIndex] = true
					}
				}
			}
		}
	}
}

func IndicateCreaturesBlock(mg types.Grid, cbg types.ImpassabilityGrid) {
	for mgRowIndex, mgRow := range mg {
		for mgCellIndex, mgCell := range mgRow {
			if mgCell.Creature != nil {
				if mgRowIndex-1 >= 0 {
					cbg[mgRowIndex-1][mgCellIndex] = true
				}
				if mgCellIndex+1 < len(cbg) {
					cbg[mgRowIndex][mgCellIndex+1] = true
				}
				if mgCellIndex-1 >= 0 {
					cbg[mgRowIndex][mgCellIndex-1] = true
				}
				if mgRowIndex-1 >= 0 && mgCellIndex+1 < len(cbg) {
					cbg[mgRowIndex-1][mgCellIndex+1] = true
				}
				if mgRowIndex-1 >= 0 && mgCellIndex-1 >= 0 {
					cbg[mgRowIndex-1][mgCellIndex-1] = true
				}
			}
		}
	}

}
func IndicateGatesBlock(mg types.Grid, gbg types.ImpassabilityGrid) {
	for mgRowIndex, mgRow := range mg {
		for mgCellIndex, mgCell := range mgRow {
			if mgCell.Gates != nil {

				gbg[mgRowIndex+1][mgCellIndex] = true

				gbg[mgRowIndex+1][mgCellIndex+1] = true

				gbg[mgRowIndex+1][mgCellIndex-1] = true

			}
		}
	}

}

func PrintDepugPassabilityGrid(ig types.ImpassabilityGrid, cbg types.ImpassabilityGrid, gbg types.ImpassabilityGrid) {
	for i, row := range ig {
		fmt.Print(i+1, " ")
		for j, cell := range row {
			if cell || cbg[i][j] || gbg[i][j] {
				fmt.Print("X")
			} else {
				fmt.Print(".")
			}
		}
		fmt.Println()
	}
	fmt.Println()
}
