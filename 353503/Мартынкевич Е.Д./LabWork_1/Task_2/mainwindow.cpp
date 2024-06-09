#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new PainterEffects();
    ui->graphicsView->setScene(scene);

    timer = new QTimer;
    timer_for_rot = new QTimer;

    connect(timer, &QTimer::timeout, this, &MainWindow::update_scene);
    connect(scene, &PainterEffects::signal_of_changin_smf, this, &MainWindow::setInfo);
    timer->start(100);

    ui->create->setChecked(true);
    scene->set_create(1);

    ui->figures->setCurrentIndex(0);
    scene->set_actual_figure_type(PainterEffects::TriangleT);

    ui->centre->setText("x: 0 y: 0");
    ui->perimetr->setText("perimeter: 0");
    ui->square->setText("square: 0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_scene()
{
    timer->stop();
    scene->setSceneRect(0,0, ui->graphicsView->width() - 20, ui->graphicsView->height() - 20);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    timer->start(100);
    QMainWindow::resizeEvent(event);
}

void MainWindow::on_figures_activated(int index)
{
    this->on_create_clicked();
    ui->create->setChecked(true);

    switch(index) {
    case 0:
        scene->set_actual_figure_type(PainterEffects::TriangleT);
        break;
    case 1:
        scene->set_actual_figure_type(PainterEffects::RectT);
        break;
    case 2:
        scene->set_actual_figure_type(PainterEffects::RhombusT);
        break;
    case 3:
        scene->set_actual_figure_type(PainterEffects::CircleT);
        break;
    case 4:
        scene->set_actual_figure_type(PainterEffects::star5);
        break;
    case 5:
        scene->set_actual_figure_type(PainterEffects::star6);
        break;
    case 6:
        scene->set_actual_figure_type(PainterEffects::star7);
        break;
    case 7:
        scene->set_actual_figure_type(PainterEffects::star8);
        break;
    }
}


void MainWindow::on_change_clicked()
{
    scene->set_create(0);
}


void MainWindow::on_create_clicked()
{
    scene->set_create(1);
}

void MainWindow::setInfo()
{
    if(scene->get_actual_figure()) {
        QPointF centre = scene->get_actual_figure()->mapToScene(scene->get_actual_figure()->boundingRect().center());
        ui->centre->setText("x: " + QString::number(centre.x()) + " y: " + QString::number(centre.y()));
        ui->perimetr->setText("perimetr: " + QString::number(scene->get_actual_figure()->perimetr()));
        ui->square->setText("square: " + QString::number(scene->get_actual_figure()->square()));
    }
    else {
        ui->centre->setText("x: 0 y: 0");
        ui->perimetr->setText("perimetr: 0");
        ui->square->setText("square: 0");
    }
}

void MainWindow::paintEvent(QPaintEvent *) {
    //setInfo();
}


void MainWindow::on_radio2_pressed()
{
    connect(timer_for_rot, SIGNAL(timeout()), this, SLOT(rotateLeft()));
    timer_for_rot->start(10);
}


void MainWindow::on_radio1_pressed()
{
    connect(timer_for_rot, SIGNAL(timeout()), this, SLOT(rotateRight()));
    timer_for_rot->start(10);


}

void MainWindow::rotateRight()
{
    if(scene->get_actual_figure()) {
        scene->get_actual_figure()->setTransformOriginPoint(mapToParent(scene->get_actual_figure()->boundingRect().center()));
        scene->get_actual_figure()->setRotation(--scene->get_actual_figure()->rotation_angle);

        scene->update();
    }
}

void MainWindow::rotateLeft()
{
    if(scene->get_actual_figure()) {
        scene->get_actual_figure()->setTransformOriginPoint(mapToParent(scene->get_actual_figure()->boundingRect().center()));
        scene->get_actual_figure()->setRotation(++scene->get_actual_figure()->rotation_angle);


        scene->update();
    }
}


void MainWindow::on_radio1_released()
{
    disconnect(timer_for_rot, SIGNAL(timeout()), this, SLOT(rotateRight()));
    timer_for_rot->stop();
}


void MainWindow::on_radio2_released()
{
    disconnect(timer_for_rot, SIGNAL(timeout()), this, SLOT(rotateLeft()));
    timer_for_rot->stop();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->modifiers() == Qt::ControlModifier) {
        scene->is_ctrl_pressed = true;
        setCursor(Qt::OpenHandCursor);
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    scene->is_ctrl_pressed = false;
    setCursor(Qt::ArrowCursor);
}
