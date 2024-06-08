#ifndef LEVELGENERATOR_H
#define LEVELGENERATOR_H

#include <QVector>
#include <utility>
#include <QPainter>
#include <QGraphicsScene>

enum class TileType {
    Empty,
    Wall,
    Character,
    Enemy,
    BonusShield,
    BonusFreeze,
    BonusCoin,
    Spike,
    Goal,
    Coin,
    OutOfBounds
};

struct Tile {
    TileType type;
};

class LevelGenerator {
public:
    LevelGenerator(int width, int height);
    void generateMaze(int startX, int startY);
    QVector<QVector<TileType>> generateLevel() const;
    int getWidth() const;
    int getHeight() const;
    TileType getTileType(int x, int y) const;
    int getNumCoins() const;
    void incrementCoins();
    TileType tileTypeAt(int x, int y) const;
    bool isAreaFree(int startX, int startY, int width, int height) const;
    void placeBonus(TileType bonusType);
    void placeEntities(TileType entityType, int count);
    void placeSpikes(int spikeCount1, int spikeCount2, int spikeCount3);
    void paintTile(QPainter &painter, int x, int y);
    void updateTileColor(int x, int y, TileType type);

    int m_width;
    int m_height;

public slots:
    void setTileType(int x, int y, TileType type);

private:
    QVector<QVector<TileType>> m_tiles;
    int m_numCoins;
    QGraphicsScene* m_scene;
};

#endif // LEVELGENERATOR_H

