#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>

class GameScene;
class MenuScene;
class QSoundEffect;

class View : public QGraphicsView
{
    Q_OBJECT
public:
    explicit View(QWidget* parent = nullptr);

signals:

private:
    void createConnections();
    GameScene* m_gameScene;
    MenuScene* m_menuScene;

private slots:
    void start();
    void menu();

protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
};


#endif // VIEW_H
