#include "widget.h"
#include "ui_widget.h"

/* Функция для получения рандомного числа
     * в диапазоне от минимального до максимального
     * */
static int randomBetween(int low, int high)
{
    return (rand()%((high + 1) - low) + low);
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Косметическая подготовка приложения
    //this->resize(840,840);          // Устанавливаем размеры окна приложения
    //this->setFixedSize(840,840);
    this->showMaximized();

    scene = new QGraphicsScene(this);   // Инициализируем графическую сцену
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов

    ui->graphicsView->resize(1500,930);  // Устанавливаем размер graphicsView
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    //scene->setSceneRect(0,0,900,500); // Устанавливаем размер сцены

    QPixmap pixBoard("/home/oblachko/Projects/CourseProject/background.jpg");
    pixBoard = pixBoard.scaled((this->size()), Qt::KeepAspectRatioByExpanding);
    QGraphicsPixmapItem *ite = new QGraphicsPixmapItem(pixBoard);
    //scene->setBackgroundBrush(pixBoard);
    scene->addItem(ite); //вот тут установка фона

    timer=new QTimer();


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    item->setPos(500,500);
    /*    item->setPos(randomBetween(30, 470),    // Устанавливаем случайную позицию элемента
                 randomBetween(30,470));*/
    scene->addItem(item);    // Добавляем элемент на графическую сцену
    fishes(it);
    //if(eat(it))
        //item->growFish();
}

void Widget::fishes(Fishes *it)
{
    for(int i=0; i<N; ++i)
    {
        it = new Fishes();
        if(rand()%2==0)
        it->setPos(0,randomBetween(30,930));
        else
        it->setPos(1500,randomBetween(30,930));

        scene->addItem(it);
        it->pathGeneration();
    }
}

bool Widget::eat(Fishes *it)
{
    bool xinside=*(it->midxi)>=*(item->xj)&&*(it->midxi)<=(*(item->xj)+*(item->wj));
    bool yinside=*(it->midyi)>=*(item->yj)&&*(it->midyi)<=(*(item->yj)+*(item->hj));
    bool bigger=*(it->wi)<=*(item->wj);
    if(bigger&&xinside&&yinside)
    {
        item->points+=10;
        it->destroyed();
        return true;
    }
    else
    {
        item->destroyed();
        return false;
    }
}

void Widget::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    item->setPos((event->pos()));
}


void Widget::on_exitButton_clicked()
{
    exit(true);
}

