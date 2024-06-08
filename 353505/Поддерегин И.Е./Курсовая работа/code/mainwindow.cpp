    #include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setVisibilityNewGame(false);
    ui->textLabel->setText("Добро пожаловать в парусный спорт!");
}

void MainWindow::setVisibilityNewGame(bool b){
    ui->graphicsView->setVisible(b);
    ui->startBttn->setVisible(b);
    ui->bonusText->setVisible(b);
    ui->loseLabel->setVisible(b);
    ui->scoreLabel->setVisible(b);
    ui->scoreLabel2->setVisible(b);
    ui->textLabel->setVisible(!b);
    ui->label->setVisible(!b);
    ui->line->setVisible(!b);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_triggered()
{
    score=0;
    ui->scoreLabel2->setText("0");
    ui->graphicsView->setSceneRect(0, 0, 801, 801);
    playScene = new QGraphicsScene(0, 0, 800, 800, this);
    ui->graphicsView->setScene(playScene);
    playScene->addRect(playScene->sceneRect());
    ui->graphicsView->setBackgroundBrush(QColor(0,255,255));

    playerBoat = new Boat();
    playScene->addItem(playerBoat);

    playerBoat->setRotation(-45);
    playerBoat->setPos(i,j);
    playerBoat->setVisible(false);

    leftTimer = new QTimer(this);
    rightTimer = new QTimer(this);
    //boat

    playerSail = new Sail();
    playScene->addItem(playerSail);

    playerSail->setRotation(-45);
    playerSail->setPos(i,j);
    playerSail->setVisible(false);
    //sail

    playerSailL = new SailL();
    playScene->addItem(playerSailL);

    playerSailL->setRotation(45);
    playerSailL->setPos(i,j);
    playerSailL->setVisible(false);
    //sailL

    spawnTimer= new QTimer();
    connect(spawnTimer,SIGNAL(timeout()),this,SLOT(spawnTimerSlot()));

    //
    //bots
    setVisibilityNewGame(true);
}


void MainWindow::on_startBttn_clicked()
{
    playerBoat->setVisible(true);
    playerSail->setVisible(true);
    ui->startBttn->setVisible(false);

    leftTimer->start(1);
    rightTimer->start(1);

    connect(rightTimer,SIGNAL(timeout()),this,SLOT(rightTimerSlot()));
    connect(leftTimer,SIGNAL(timeout()),this,SLOT(leftTimerSlot()));

    connect((artificialTimer+0),SIGNAL(timeout()),this,SLOT(artificialTimerSlot1()));
    connect((artificialTimer+1),SIGNAL(timeout()),this,SLOT(artificialTimerSlot2()));
    connect((artificialTimer+2),SIGNAL(timeout()),this,SLOT(artificialTimerSlot3()));
    connect((artificialTimer+3),SIGNAL(timeout()),this,SLOT(artificialTimerSlot4()));
    connect((artificialTimer+4),SIGNAL(timeout()),this,SLOT(artificialTimerSlot5()));
    connect((artificialTimer+5),SIGNAL(timeout()),this,SLOT(artificialTimerSlot6()));
    connect((artificialTimer+6),SIGNAL(timeout()),this,SLOT(artificialTimerSlot7()));
    connect((artificialTimer+7),SIGNAL(timeout()),this,SLOT(artificialTimerSlot8()));
    connect((artificialTimer+8),SIGNAL(timeout()),this,SLOT(artificialTimerSlot9()));
    connect((artificialTimer+9),SIGNAL(timeout()),this,SLOT(artificialTimerSlot10()));

    for (int p=0;p<10;++p){
        playScene->addItem(artificialBoat+p);
        (artificialBoat+p)->setPos(0,0);
        (artificialBoat+p)->setRotation(180);
        playScene->addItem(artificialSail+p);
        playScene->addItem(artificialSailL+p);
        (artificialSail+p)->setPos(0,0);
        (artificialSailL+p)->setPos(0,0);
        (artificialSail+p)->setRotation(-110);
        (artificialSailL+p)->setRotation(110);

    }
}

void MainWindow::leftTimerSlot()
{
    i+=c;
    i2+=c;
    playerBoat->setPos(i2,j2);
    playerSailL->setPos(i2,j2);
    playerBoat->setRotation(45);

    playerSail->setVisible(false);
    playerSailL->setVisible(true);

    if (i> 650|| i<-90){
        nullScene();
    }
    bool b= (playerBoat->collidesWithItem(artificialBoat)||playerBoat->collidesWithItem(artificialBoat+1)||
     playerBoat->collidesWithItem(artificialBoat+2)||playerBoat->collidesWithItem(artificialBoat+3)||
     playerBoat->collidesWithItem(artificialBoat+4)||playerBoat->collidesWithItem(artificialBoat+5)||
     playerBoat->collidesWithItem(artificialBoat+6)||playerBoat->collidesWithItem(artificialBoat+7)||
              playerBoat->collidesWithItem(artificialBoat+8)||playerBoat->collidesWithItem(artificialBoat+9));
    if (b &&inCollision==false){

        QList<QGraphicsItem*> list= playerBoat->collidingItems();
        int coef = -1;
        for (int p=0;p<10;++p){
            list[0]->setVisible(false);
            list[1]->setVisible(false);
            list[2]->setVisible(false);
            if(!(artificialBoat+p)->isVisible())
            {
                coef =p;
            }
        }
        if (!(artificialBoat +coef)->starboard){
            list[0]->setVisible(false);
            list[1]->setVisible(false);
            list[2]->setVisible(false);
            bonus();
            inCollision =true;
            QTimer::singleShot(2500,[]{
                inCollision=false;
            });
        }else{
            nullScene();
        }

      // не съедает левый парус
    }
}

void MainWindow::rightTimerSlot()
{
    i-=c;
    i2-=c;

    playerBoat->setPos(i,j);
    playerSail->setPos(i,j);
    playerBoat->setRotation(-45);

    playerSail->setVisible(true);
    playerSailL->setVisible(false);

    if (i> 670|| i<-90){
        nullScene();
    }
    if ((playerBoat->collidesWithItem(artificialBoat)||playerBoat->collidesWithItem(artificialBoat+1)||
        playerBoat->collidesWithItem(artificialBoat+2)||playerBoat->collidesWithItem(artificialBoat+3)||
        playerBoat->collidesWithItem(artificialBoat+4)||playerBoat->collidesWithItem(artificialBoat+5)||
        playerBoat->collidesWithItem(artificialBoat+6)||playerBoat->collidesWithItem(artificialBoat+7)||
        playerBoat->collidesWithItem(artificialBoat+8)||playerBoat->collidesWithItem(artificialBoat+9))
        && inCollision==false){

        bonus();
        QList<QGraphicsItem*> list= playerBoat->collidingItems();
        list[0]->setVisible(false);
        list[1]->setVisible(false);
        list[2]->setVisible(false);
        inCollision =true;
        QTimer::singleShot(2500,[]{
            inCollision=false;
        });
        //не съедает левый парус
    }
}


void MainWindow::artificialTimerSlot1()
{
    int temp=0;
    artificialTimersFunc(temp);
}
void MainWindow::artificialTimerSlot2()
{
    int temp=1;
    artificialTimersFunc(temp);
}
void MainWindow::artificialTimerSlot3()
{
    int temp=2;
    artificialTimersFunc(temp);
}
void MainWindow::artificialTimerSlot4()
{
}
void MainWindow::artificialTimerSlot5()
{
    int temp=4;
    artificialTimersFunc(temp);
}
void MainWindow::artificialTimerSlot6()
{
    int temp=5;
    artificialTimersFunc(temp);
}
void MainWindow::artificialTimerSlot7()
{
    int temp=6;
    artificialTimersFunc(temp);
    /*(artificialBoat+temp)->w+=c;
    (artificialBoat+temp)->q=300;
    (artificialBoat+temp)->setPos(300,(artificialBoat+temp)->w);
    (artificialSail+temp)->setVisible(false);
    (artificialBoat+temp)->starboard =false;
    (artificialSailL+temp)->setPos((artificialBoat+temp)->q-3,(artificialBoat+temp)->w-123);
    if((artificialBoat+temp)->w>1000){
        (artificialBoat+temp)->w=0;
        (artificialTimer+temp)->stop();
    }*/
}
void MainWindow::artificialTimerSlot8()
{
    int temp=7;
    artificialTimersFunc(temp);
    /*(artificialBoat+temp)->w+=c;
    (artificialBoat+temp)->q=700;
    (artificialBoat+temp)->setPos(700,(artificialBoat+temp)->w);
    (artificialSail+temp)->setVisible(false);
    (artificialBoat+temp)->starboard =false;
    (artificialSailL+temp)->setPos((artificialBoat+temp)->q-3,(artificialBoat+temp)->w-123);
    if((artificialBoat+temp)->w>1000){
        (artificialBoat+temp)->w=0;
        (artificialTimer+temp)->stop();
    }*/
}
void MainWindow::artificialTimerSlot9()
{
    int temp=8;
    artificialTimersFunc(temp);
}
void MainWindow::artificialTimerSlot10()
{
    int temp=9;
    artificialTimersFunc(temp);
}

void MainWindow::artificialTimersFunc(int temp)
{
    (artificialBoat+temp)->w+=c;
    (artificialBoat+temp)->setPos((artificialBoat+temp)->q,(artificialBoat+temp)->w);
    (artificialSail+temp)->setPos((artificialBoat+temp)->q-110,(artificialBoat+temp)->w+40);
    (artificialSailL+temp)->setPos((artificialBoat+temp)->q-3,(artificialBoat+temp)->w-123);
    if((artificialBoat+temp)->w>1000){
        (artificialBoat+temp)->w=0;
        (artificialTimer+temp)->stop();
    }
}
void MainWindow::spawnTimerSlot()
{
    if(l<quantityOfAIBoats){
        generatePos();
        //(artificialBoat+l)->q=l*80 +110;////////////////////////////////////////////////////здес 110-860
        (artificialBoat+l)->setPos((artificialBoat+l)->q,k);
        (artificialBoat+l)->setRotation(180);
        (artificialBoat+l)->setVisible(true);

        switch(l){
            case 0:
            {
            caseFunc();
            break;
            }
            case 1:
            {
            caseFunc();
                break;
            }
            case 2:
            {
                caseFunc();
                break;
            }
            case 3:
            {
                caseFunc();
                break;
            }
            case 4:
            {
                caseFunc();
                break;
            }
            case 5:
            {
                caseFunc();
                break;
            }
            case 6:
            {
                caseFunc();
                break;
            }
            case 7:
            {
                caseFunc();
                break;
            }
            case 8:
            {
                caseFunc();
                break;
            }
            case 9:
            {
                caseFunc();
                l=-1;
                break;
            }
        }
        l+=1;
    }
}

void MainWindow::caseFunc()
{


    (artificialBoat+l)->starboard=Get();
    if((artificialBoat+l)->starboard){
        (artificialSail+l)->setVisible(true);
        (artificialSailL+l)->setVisible(false);
    }else{
        (artificialSailL+l)->setVisible(true);
        (artificialSail+l)->setVisible(false);
    }
    (artificialTimer+l)->start(1);
}

void MainWindow::nullScene()
{
    ui->loseLabel->setText("Вы проиграли!");

    leftTimer->stop();
    rightTimer->stop();
    (artificialTimer+0)->stop();
    (artificialTimer+1)->stop();
    (artificialTimer+2)->stop();
    (artificialTimer+3)->stop();
    (artificialTimer+4)->stop();
    (artificialTimer+5)->stop();
    (artificialTimer+6)->stop();
    (artificialTimer+7)->stop();
    (artificialTimer+8)->stop();
    (artificialTimer+9)->stop();
    i=290;
    i2= 410;
    j=650;
    j2=525;


    disconnect(rightTimer,SIGNAL(timeout()),this,SLOT(rightTimerSlot()));
    disconnect(leftTimer,SIGNAL(timeout()),this,SLOT(leftTimerSlot()));

    disconnect((artificialTimer+0),SIGNAL(timeout()),this,SLOT(artificialTimerSlot10()));
    disconnect((artificialTimer+1),SIGNAL(timeout()),this,SLOT(artificialTimerSlot10()));
    disconnect((artificialTimer+2),SIGNAL(timeout()),this,SLOT(artificialTimerSlot10()));
    disconnect((artificialTimer+3),SIGNAL(timeout()),this,SLOT(artificialTimerSlot10()));
    disconnect((artificialTimer+4),SIGNAL(timeout()),this,SLOT(artificialTimerSlot10()));
    disconnect((artificialTimer+5),SIGNAL(timeout()),this,SLOT(artificialTimerSlot10()));
    disconnect((artificialTimer+6),SIGNAL(timeout()),this,SLOT(artificialTimerSlot10()));
    disconnect((artificialTimer+7),SIGNAL(timeout()),this,SLOT(artificialTimerSlot10()));
    disconnect((artificialTimer+8),SIGNAL(timeout()),this,SLOT(artificialTimerSlot10()));
    disconnect((artificialTimer+9),SIGNAL(timeout()),this,SLOT(artificialTimerSlot10()));

    disconnect(spawnTimer,SIGNAL(timeout()),this,SLOT(spawnTimerSlot()));

}

void MainWindow::generatePos()
{

    int checker=0;
        for (int p=0; p<20;++p){
            if (Get()){
                (artificialBoat+l)->q +=coordinatesArr[p];
                ++checker;
        }

    }

        if (checker==0 || (l>0&&(artificialBoat+l)->q==(artificialBoat+l-1)->q)){
        generatePos();
        }else{
        (artificialBoat+l)->q/=checker;
        }
}

void MainWindow::bonus()
{
    ++score;
     ui->scoreLabel->setText("Счёт: ");
    ui->scoreLabel2->setText(QString::number(score));
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key()== Qt::Key_D){
        leftTimer->stop();
        rightTimer->start(1);

        playerBoat->starboard=true;
        if(!spawnTimer->isActive()){
            spawnTimer->start(3012);
        }
    }
    if (e->key()== Qt::Key_A){
        rightTimer->stop();
        leftTimer->start(1);

        playerBoat->starboard=false;

        if(!spawnTimer->isActive()){
            spawnTimer->start(3013);
        }
    }
}




void MainWindow::on_action_3_triggered()
{
    nullScene();
    setVisibilityNewGame(false);
    QMessageBox::StandardButton reply = QMessageBox::information(this,"Обучение", "Наветренная сторона - сторона в которую дует ветер, "
                                                                                   "Подветренная сторона - сторона в которую не дует ветер. "
                                                                                           "Подветренная яхта - яхта находящаяся с подветренной стороны. "
                                                                                           "Яхта на правом галсе, когда её наветренная сторона правая. "
                                                                                           "Яхта на левом галсе, когда её наветренная сторона левая. "
                                                                                   "Подветренная яхта имеет право дороги по отношению к подветренной. "
                                                                                   "Правый галс имеет право дороги по отношению к левому галсу. "
                                                                                           "Сбивайте лодки, нарушающие правила расхождения и зарабатывайте очки, "
                                                                                   "чтобы нарушителей становилось меньше."
                                                                                   "Выбрать галс можно с помощью клавиш A и D НА АНГЛИЙСКОЙ РАСКЛАДКЕ. "
                                                                                   "A - левый галс "
                                                                                   "D - правый. "
                                                                                   "И запомните: море ошибок не прощает. ",
                                                              QMessageBox::Ok);

}

