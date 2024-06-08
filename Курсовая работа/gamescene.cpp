#include "gamescene.h"
#include "game.h"
#include <QKeyEvent>
#include <QDebug>
#include <QDir>
#include <QPainter>
#include <algorithm>
#include <queue>
#include <stack>

Point GameScene::nearestNeighbor()
{
    Point bestPosition(-1, -1);
    int minHeight = INT_MAX;

    for (int rotation = 0; rotation < 4; ++rotation) {
        for (int x = 0; x < Game::BOARD_WIDTH; ++x) {

            std::vector<Point> tempBlocks(game.m_a, game.m_a + Game::COUNT_OF_BLOCKS);
            for (int i = 0; i < rotation; ++i) {
                for (int j = 0; j < Game::COUNT_OF_BLOCKS; ++j) {
                    int px = tempBlocks[1].x;
                    int py = tempBlocks[1].y;
                    int nx = tempBlocks[j].y - py;
                    int ny = tempBlocks[j].x - px;
                    tempBlocks[j].x = px - nx;
                    tempBlocks[j].y = py + ny;
                }
            }

            for (int y = 0; y < Game::BOARD_HEIGHT; ++y) {
                bool canPlace = true;
                for (int i = 0; i < Game::COUNT_OF_BLOCKS; ++i) {
                    int nx = tempBlocks[i].x + x;
                    int ny = tempBlocks[i].y + y;
                    if (nx < 0 || nx >= Game::BOARD_WIDTH || ny >= Game::BOARD_HEIGHT || game.m_field[ny][nx] != 0) {
                        canPlace = false;
                        break;
                    }
                }

                if (canPlace) {
                    int currentHeight = 0;
                    for (int i = 0; i < Game::BOARD_WIDTH; ++i) {
                        int columnHeight = 0;
                        for (int j = 0; j < Game::BOARD_HEIGHT; ++j) {
                            if (game.m_field[j][i] != 0) {
                                columnHeight = Game::BOARD_HEIGHT - j;
                                break;
                            }
                        }
                        currentHeight += columnHeight;
                    }

                    if (currentHeight < minHeight) {
                        minHeight = currentHeight;
                        bestPosition = Point(x, y);
                    }
                }
            }
        }
    }

    return bestPosition;
}

void GameScene::applyBestMove()
{
    Point bestMove = nearestNeighbor();
    if (bestMove.x != -1 && bestMove.y != -1) {
        for (int i = 0; i < Game::COUNT_OF_BLOCKS; ++i) {
            game.m_a[i].x = bestMove.x;
            game.m_a[i].y = bestMove.y;
        }
        game.m_rotate = false;
        game.m_dx = 0;
    }
}

void GameScene::breadthFirstSearch()
{
    std::vector<std::vector<bool>> visited(Game::BOARD_HEIGHT, std::vector<bool>(Game::BOARD_WIDTH, false));
    std::queue<Point> bfsQueue;

    Point startVertex(Game::BOARD_WIDTH / 2, 0);

    visited[startVertex.y][startVertex.x] = true;
    bfsQueue.push(startVertex);

    while (!bfsQueue.empty()) {
        Point currentVertex = bfsQueue.front();
        bfsQueue.pop();

        for (int dy = -1; dy <= 1; ++dy) {
            for (int dx = -1; dx <= 1; ++dx) {
                if (dx == 0 && dy == 0) continue;

                int nx = currentVertex.x + dx;
                int ny = currentVertex.y + dy;

                if (nx >= 0 && nx < Game::BOARD_WIDTH && ny >= 0 && ny < Game::BOARD_HEIGHT && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    bfsQueue.push(Point(nx, ny));
                }
            }
        }
    }

    int emptyRowsCount = 0;
    for (int y = 0; y < Game::BOARD_HEIGHT; ++y) {
        bool isEmpty = true;
        for (int x = 0; x < Game::BOARD_WIDTH; ++x) {
            if (game.m_field[y][x] != 0) {
                isEmpty = false;
                break;
            }
        }
        if (isEmpty) {
            ++emptyRowsCount;
        }
    }
    qDebug() << "Number of empty rows that can be filled: " << emptyRowsCount;
}


std::vector<Point> GameScene::depthFirstSearch(Point start, Point end)
{
    std::vector<std::vector<bool>> visited(Game::BOARD_HEIGHT, std::vector<bool>(Game::BOARD_WIDTH, false));
    std::vector<std::vector<Point>> parent(Game::BOARD_HEIGHT, std::vector<Point>(Game::BOARD_WIDTH, Point(-1, -1)));
    std::stack<Point> dfsStack;

    visited[start.y][start.x] = true;
    dfsStack.push(start);

    while (!dfsStack.empty()) {
        Point currentVertex = dfsStack.top();
        dfsStack.pop();

        if (currentVertex == end) {
            std::vector<Point> path;
            for (Point at = end; at.x != -1 && at.y != -1; at = parent[at.y][at.x]) {
                path.push_back(at);
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        std::vector<Point> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (const auto& dir : directions) {
            int nx = currentVertex.x + dir.x;
            int ny = currentVertex.y + dir.y;

            if (nx >= 0 && nx < Game::BOARD_WIDTH && ny >= 0 && ny < Game::BOARD_HEIGHT &&
                !visited[ny][nx] && game.m_field[ny][nx] == 0) {
                visited[ny][nx] = true;
                parent[ny][nx] = currentVertex;
                dfsStack.push(Point(nx, ny));
            }
        }
    }

    return {};
}


GameScene::GameScene(QObject *parent) : QGraphicsScene(parent), game(), timePerFrame(1000.0f/60.0f)
{
    setSceneRect(0,0, Game::RESOLUTION.width(), Game::RESOLUTION.height());
    srand(time(0));

    m_frame = new QGraphicsPixmapItem(game.m_frame);
    m_background = new QGraphicsPixmapItem(game.m_background);
    m_tiles = new QGraphicsPixmapItem(game.m_tile);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &GameScene::update);
}

void GameScene::start()
{
    game.reset();
    timer->start(timePerFrame);
}

void GameScene::stop()
{
    timer->stop();
}

void GameScene::renderScene()
{
    QString fileName = QDir::currentPath() + QDir::separator() + "game_scene.png";
    QRect rect = sceneRect().toAlignedRect();
    QImage image(rect.size(), QImage::Format_ARGB32);
    image.fill(Qt::transparent);
    QPainter painter(&image);
    render(&painter);
    image.save(fileName);
    qDebug() << "saved " << fileName;
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat())
    {
        switch(event->key())
        {
        case Qt::Key_A:
        case Qt::Key_Left:
            if (game.m_state == Game::State::Active)
            {
                game.m_dx = -1;
            }
            break;
        case Qt::Key_D:
        case Qt::Key_Right:
            if (game.m_state == Game::State::Active)
            {
                game.m_dx = 1;
            }
            break;
        case Qt::Key_W:
        case Qt::Key_Up:
            if (game.m_state == Game::State::Active)
            {
                game.m_rotate = true;
            }
            break;
        case Qt::Key_S:
        case Qt::Key_Down:
            if (game.m_state == Game::State::Active)
            {
                game.m_delay = Game::SPEED_UP;
            }
            break;
        case Qt::Key_R:
            if (game.m_gameOver)
            {
                game.reset();
            }
            break;
        case Qt::Key_X:
            if (game.m_state == Game::State::Active)
            {
                applyBestMove();
            }
            break;

        case Qt::Key_Q:
            if (game.m_state == Game::State::Active)
            {
                breadthFirstSearch();
            }
            break;
        case Qt::Key_E:
        {
            Point startVertex(Game::BOARD_WIDTH / 2, 0);
            Point endVertex(Game::BOARD_WIDTH / 2, Game::BOARD_HEIGHT - 1);
            std::vector<Point> path = depthFirstSearch(startVertex, endVertex);
            if (!path.empty()) {
                qDebug() << "Path found:";
                for (const Point& p : path) {
                    qDebug() << "(" << p.x << "," << p.y << ")";
                }
            } else {
                qDebug() << "No path found";
            }
            break;
        }
        default:
            break;
        }
    }

    QGraphicsScene::keyPressEvent(event);
}

void GameScene::keyReleaseEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat())
    {
        switch(event->key())
        {
        case Qt::Key_A:
        case Qt::Key_D:
        case Qt::Key_Right:
        case Qt::Key_Left:
            game.m_dx = 0;
            break;
        case Qt::Key_W:
        case Qt::Key_Up:
            game.m_rotate = false;
            break;
        case Qt::Key_S:
        case Qt::Key_Down:
            game.m_delay = Game::SPEED;
            break;
        default:
            break;
        }
    }
    QGraphicsScene::keyReleaseEvent(event);
}


void GameScene::drawScore()
{
    QGraphicsPixmapItem* scorePixmapItem = new QGraphicsPixmapItem(game.m_scorePixmap.scaled(150,164));
    addItem(scorePixmapItem);
    scorePixmapItem->moveBy(480,50);
    QString scoreText = QString::number(game.m_score);

    int unityPartVal = 0;
    int decimalPartValue = 0;
    int hendredthPartValue = 0;

    if(scoreText.length() == 1)
    {
        unityPartVal = scoreText.toInt();
        decimalPartValue = 0;
        hendredthPartValue = 0;
    }
    else if(scoreText.length() == 2)
    {
        unityPartVal = scoreText.last(1).toInt();
        decimalPartValue = scoreText.first(1).toInt();
        hendredthPartValue = 0;
    }
    else if(scoreText.length() == 3)
    {
        unityPartVal = scoreText.last(1).toInt();
        hendredthPartValue = scoreText.first(1).toInt();
        QString copyVal = scoreText;
        copyVal.chop(1);
        decimalPartValue = copyVal.last(1).toInt();
    }

    QGraphicsPixmapItem* unityPartScoreItem = new QGraphicsPixmapItem(game.m_numbersPixmap.copy(unityPartVal*32, 0, 32, 32));
    unityPartScoreItem->moveBy(Game::RESOLUTION.width()-32, scorePixmapItem->y()+180);
    addItem(unityPartScoreItem);

    QGraphicsPixmapItem* decimalPartScoreItem = new QGraphicsPixmapItem(game.m_numbersPixmap.copy(decimalPartValue*32, 0, 32, 32));
    decimalPartScoreItem->moveBy(Game::RESOLUTION.width()-2*32, scorePixmapItem->y()+180);
    addItem(decimalPartScoreItem);

    QGraphicsPixmapItem* hundrethPartScoreItem = new QGraphicsPixmapItem(game.m_numbersPixmap.copy(hendredthPartValue*32, 0, 32, 32));
    hundrethPartScoreItem->moveBy(Game::RESOLUTION.width()-3*32, scorePixmapItem->y()+180);
    addItem(hundrethPartScoreItem);
}

void GameScene::drawGameState()
{
    if (game.m_gameOver)
    {
        game.m_state = Game::State::Game_Over;

        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(game.m_gameOverBackground.scaled(640, 960));
        addItem(item);

        QGraphicsPixmapItem* restartTextItem = new QGraphicsPixmapItem(game.m_restartTextPixmap);
        addItem(restartTextItem);
        restartTextItem->setPos(180, 570);
    }
}


void GameScene::drawActiveFigure()
{
    for (int i = 0; i < Game::COUNT_OF_BLOCKS; i++)
    {
        QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(game.m_tile.copy(game.m_colorNum * Game::BLOCK_SIZE.width(), 0,
                                                                                   Game::BLOCK_SIZE.width(), Game::BLOCK_SIZE.height()));
        addItem(pixmapItem);
        pixmapItem->setPos(game.m_a[i].x * Game::BLOCK_SIZE.width(), game.m_a[i].y * Game::BLOCK_SIZE.height());
        pixmapItem->moveBy(m_frame->pos().x(), m_frame->pos().y());
    }
}

void GameScene::moveFigure()
{
    for (int i = 0; i < Game::COUNT_OF_BLOCKS ;i++)
    {
        game.m_b[i]= game.m_a[i];
        game.m_a[i].x += game.m_dx;
    }

    if (!game.check())
    {
        for (int i = 0; i < Game::COUNT_OF_BLOCKS; i++)
        {
            game.m_a[i] = game.m_b[i];
        }
    }
}

void GameScene::drawBackground()
{
    m_background = new QGraphicsPixmapItem(game.m_background.scaled(sceneRect().width(), sceneRect().height()));
    addItem(m_background);

    m_frame = new QGraphicsPixmapItem(game.m_frame);
    addItem(m_frame);
    m_frame->moveBy(15, 31);
}

void GameScene::rotateFigure()
{
    if (game.m_rotate)
    {
        Point p = game.m_a[1];
        for (int i = 0; i < Game::COUNT_OF_BLOCKS; i++)
        {
            int x = game.m_a[i].y-p.y;
            int y = game.m_a[i].x-p.x;
            game.m_a[i].x = p.x - x;
            game.m_a[i].y = p.y + y;
        }
        if (!game.check())
        {
            for (int i = 0; i < Game::COUNT_OF_BLOCKS; i++)
            {
                game.m_a[i] = game.m_b[i];
            }
        }
        game.m_rotate = false;
    }
}

void GameScene::update()
{
    if(game.m_state == Game::State::Active)
    {
        game.m_timer += (timePerFrame);
    }

    moveFigure();
    rotateFigure();

    if ( game.m_timer > game.m_delay)
    {
        for (int i = 0; i < Game::COUNT_OF_BLOCKS; i++)
        {
            game.m_b[i] = game.m_a[i];
            game.m_a[i].y+=1;
        }

        if (!game.check())
        {
            for (int i = 0; i < Game::COUNT_OF_BLOCKS; i++)
            {
                game.m_field[game.m_b[i].y][game.m_b[i].x] = game.m_colorNum;
            }

            game.m_colorNum = (rand() % (Game::COUNT_OF_COLORS - 1)) + 1;
            int n= rand() % Game::COUNT_OF_FIGURES;
            for (int i = 0; i < Game::COUNT_OF_BLOCKS; i++)
            {
                game.m_a[i].x = (game.m_figures[n][i] % 2) + game.BOARD_WIDTH/2-1;
                game.m_a[i].y = game.m_figures[n][i] / 2;
                if(game.m_field[game.m_a[i].y][game.m_a[i].x])
                {
                    qDebug() << "Game Over";
                    game.m_gameOver = true;
                }
            }
        }

        game.m_timer=0;
    }

    int k = game.BOARD_HEIGHT-1;
    for (int i = game.BOARD_HEIGHT-1; i > 0; i--)
    {
        int count = 0;
        for (int j = 0; j < game.BOARD_WIDTH;j++)
        {
            if (game.m_field[i][j])
            {
                count++;
            }
            game.m_field[k][j]= game.m_field[i][j];
        }
        if (count < game.BOARD_WIDTH)
        {
            k--;
        }
        else
        {
            game.addScore(1);

        }
    }

    game.m_dx=0; game.m_rotate=false;

    clear();

    drawBackground();

    for (int i=0;i<game.BOARD_HEIGHT;i++)
    {
        for (int j=0;j<game.BOARD_WIDTH;j++)
        {
            if (game.m_field[i][j]==0) continue;
            QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(game.m_tile.copy(game.m_field[i][j]*45, 0, 45, 45));
            addItem(pixmapItem);
            pixmapItem->setPos(j * Game::BLOCK_SIZE.width(), i * Game::BLOCK_SIZE.height());
            pixmapItem->moveBy(m_frame->pos().x(), m_frame->pos().y());
        }

    }

    drawActiveFigure();

    drawScore();

    drawGameState();
}

void GameScene::countingSortByEmptyCells(std::vector<int>& arr)
{
    int maxElement = *std::max_element(arr.begin(), arr.end());

    std::vector<int> count(maxElement + 1, 0);
    std::vector<int> output(arr.size());

    for (size_t i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= maxElement; i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

