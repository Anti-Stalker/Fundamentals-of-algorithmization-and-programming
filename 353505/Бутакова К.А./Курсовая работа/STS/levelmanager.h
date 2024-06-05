#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <QWidget>
#include <QMainWindow>
class CombatZone;
class QGraphicsScene;
class rightUi;
class QHBoxLayout;
class QCloseEvent;
class QSoundEffect;

class LevelManager : public QMainWindow
{
    Q_OBJECT
private:
    CombatZone*Field;
    QGraphicsScene *scene;
    rightUi *right;
    QHBoxLayout *mainLayout;
    QWidget *w;
public:
    LevelManager(QMainWindow *parent = 0);
    void CreateBattleField(int player, int enemy, int map, int obstacle);
    QSoundEffect *bgm;

protected:
    void closeEvent(QCloseEvent *event);

signals:
    void backToMenu();

public slots:
    void startLevel(LevelManager* lv);
    void StopEvent(bool t){this->setEnabled(!t);}

private slots:
    void ExitGame(QString msg);
};

#endif
