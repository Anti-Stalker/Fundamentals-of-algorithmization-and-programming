package maps

import (
	"game_try/game/types"
	"math"
)

func (m *GameMap) GetNeighbors(p types.GridPosition) []types.GridPosition {
	var neighbors []types.GridPosition

	if s0p := (types.GridPosition{X: p.X, Y: p.Y - 1}); !m.IsImpassableAt(s0p) {
		neighbors = append(neighbors, s0p)
	}
	if s1p := (types.GridPosition{X: p.X + 1, Y: p.Y}); !m.IsImpassableAt(s1p) {
		neighbors = append(neighbors, s1p)
	}
	if s2p := (types.GridPosition{X: p.X, Y: p.Y + 1}); !m.IsImpassableAt(s2p) {
		neighbors = append(neighbors, s2p)
	}
	if s3p := (types.GridPosition{X: p.X - 1, Y: p.Y}); !m.IsImpassableAt(s3p) {
		neighbors = append(neighbors, s3p)
	}

	// ↖
	if d0p := (types.GridPosition{X: p.X - 1, Y: p.Y - 1}); !m.IsImpassableAt(d0p) {
		neighbors = append(neighbors, d0p)
	}
	// ↗
	if d1p := (types.GridPosition{X: p.X + 1, Y: p.Y - 1}); !m.IsImpassableAt(d1p) {
		neighbors = append(neighbors, d1p)
	}
	// ↘
	if d2p := (types.GridPosition{X: p.X + 1, Y: p.Y + 1}); !m.IsImpassableAt(d2p) {
		neighbors = append(neighbors, d2p)
	}
	// ↙
	if d3p := (types.GridPosition{X: p.X - 1, Y: p.Y + 1}); !m.IsImpassableAt(d3p) {
		neighbors = append(neighbors, d3p)
	}

	return neighbors
}

func (m *GameMap) GetPath(from types.GridPosition, to types.GridPosition) []types.GridPosition {
	// A* algorithm

	parents := make(map[types.GridPosition]types.GridPosition)

	nodesF := make(map[types.GridPosition]float64)
	nodesG := make(map[types.GridPosition]float64)

	openSet := make(map[types.GridPosition]struct{})
	closedSet := make(map[types.GridPosition]struct{})

	nodesF[from] = 0
	nodesG[from] = 0

	openSet[from] = struct{}{}

	for len(openSet) > 0 {
		var current types.GridPosition
		var currentF float64
		for k := range openSet {
			if currentF == 0 || nodesF[k] < currentF {
				current = k
				currentF = nodesF[k]
			}
		}

		if current == to {
			path := []types.GridPosition{current}
			for current != from {
				current = parents[current]
				path = append([]types.GridPosition{current}, path...)
			}
			return path
		}

		delete(openSet, current)
		closedSet[current] = struct{}{}

		for _, neighbor := range m.GetNeighbors(current) {
			if _, ok := closedSet[neighbor]; ok {
				continue
			}

			var tentativeG float64
			if neighbor.X-current.X == 0 || neighbor.Y-current.Y == 0 {
				tentativeG = nodesG[current] + 1
			} else {
				tentativeG = nodesG[current] + 1.41421356237
			}

			if _, ok := openSet[neighbor]; !ok {
				openSet[neighbor] = struct{}{}
			} else if tentativeG >= nodesG[neighbor] {
				continue
			}

			parents[neighbor] = current
			nodesG[neighbor] = tentativeG
			nodesF[neighbor] = nodesG[neighbor] + OctileDistance(to.X-neighbor.X, to.Y-neighbor.Y)
		}
	}

	return nil
}

func OctileDistance(dx, dy int) float64 {
	f := math.Sqrt2 - 1
	if dx < dy {
		return f*float64(dx) + float64(dy)
	}
	return f*float64(dy) + float64(dx)
}
