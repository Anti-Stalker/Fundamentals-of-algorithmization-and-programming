#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    formTriangle = new DialogTriangle(this);
    formTriangle->setFixedSize(320,240);
    formCircle = new DialogCircle(this);
    formCircle->setFixedSize(265,184);
    formRhombus = new DialogRhombus(this);
    formRhombus->setFixedSize(360,167);
    formSquare = new DialogSquare(this);
    formSquare->setFixedSize(240,167);
    formRectangle = new DialogRectangle(this);
    formRectangle->setFixedSize(272,164);
    formStar = new DialogStar(this);
    formStar->setFixedSize(379,236);
    formHexagon = new DialogHexagon(this);
    formHexagon->setFixedSize(255,137);
    formOval = new DialogOval(this);
    formOval->setFixedSize(311,192);
    formSetXY = new DialogSetXY(this);
    formSetXY->setFixedSize(272,164);
    timer = new QTimer();
    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete formTriangle;
    delete formCircle;
    delete formRhombus;
    delete formSquare;
    delete formRectangle;
    delete formStar;
    delete formHexagon;
    delete formOval;
    delete formSetXY;
}

void MainWindow::ReceiveValuesOfStar(valuesOfStar &values)
{
    typeOfStar = values.tip;
    sideOfStar = values.side;
}

void MainWindow::on_chooseFigure_currentIndexChanged(int index)
{
    QString currentText = ui->chooseFigure->currentText();
    if (currentText == "Треугольник") {
        clearPreviosFigure();
        figure = new FigureTriangle();
        FigureTriangle* triangle = dynamic_cast<FigureTriangle*>(figure);
        connect(formTriangle, &DialogTriangle::triangleValues,
                triangle, &FigureTriangle::receiveTriangleValues);
        dialogStatus = formTriangle->exec();
        if (dialogStatus == QDialog::Accepted) {
            scene->addItem(figure);
            setProperties();
            figure->setFlag(QGraphicsItem::ItemIsMovable);
        } else {
            delete triangle;
        }
    }
    else if (currentText == "Круг") {
        clearPreviosFigure();
        figure = new FigureCircle();
        FigureCircle* circle = dynamic_cast<FigureCircle*>(figure);
        connect(formCircle, &DialogCircle::circleValue,
                circle, &FigureCircle::receiveRadius);
        connect(formCircle, &DialogCircle::transmitRotation,
                circle, &FigureCircle::receiveRotation);
        dialogStatus = formCircle->exec();
        if (dialogStatus == QDialog::Accepted) {
            scene->addItem(figure);
            setProperties();
            figure->setFlag(QGraphicsItem::ItemIsMovable);
        } else {
            delete circle;
        }
    }
    else if (currentText == "Квадрат") {
        clearPreviosFigure();
        figure = new FigureSquare();
        FigureSquare* square = dynamic_cast<FigureSquare*>(figure);
        connect(formSquare, &DialogSquare::transmitValue,
                square, &FigureSquare::receiveValues);
        dialogStatus = formSquare->exec();
        if (dialogStatus == QDialog::Accepted) {
            scene->addItem(figure);
            setProperties();
            figure->setFlag(QGraphicsItem::ItemIsMovable);
        } else {
            delete square;
        }
    }
    else if (currentText == "Прямоугольник") {
        clearPreviosFigure();
        figure = new FigureRectangle();
        FigureRectangle* rectangle = dynamic_cast<FigureRectangle*>(figure);
        connect(formRectangle, &DialogRectangle::transmitValues,
                rectangle, &FigureRectangle::receiveValues);
        dialogStatus = formRectangle->exec();
        if (dialogStatus == QDialog::Accepted) {
            scene->addItem(figure);
            setProperties();
            figure->setFlag(QGraphicsItem::ItemIsMovable);
        } else {
            delete rectangle;
        }
    }
    else if (currentText == "Ромб") {
        clearPreviosFigure();
        figure = new FigureRhombus();
        FigureRhombus* rhombus = dynamic_cast<FigureRhombus*>(figure);
        connect(formRhombus, &DialogRhombus::rhombusValues,
                rhombus, &FigureRhombus::receiveRhombus);
        dialogStatus = formRhombus->exec();
        if (dialogStatus == QDialog::Accepted) {
            scene->addItem(figure);
            setProperties();
            figure->setFlag(QGraphicsItem::ItemIsMovable);
        } else {
            delete rhombus;
        }
    }
    else if (currentText == "Звезда") {
        clearPreviosFigure();
        connect(formStar, &DialogStar::transmitValues,
                this, &MainWindow::ReceiveValuesOfStar);
        dialogStatus = formStar->exec();
        if (typeOfStar == -2) {
            figure = new FigureStar5();
            FigureStar5* star = dynamic_cast<FigureStar5*>(figure);
            connect(this, &MainWindow::transmitSideOfStar,
                    star, &FigureStar5::receiveValue);
        }
        else if (typeOfStar == -3) {
            figure = new FigureStar6();
            FigureStar6* star = dynamic_cast<FigureStar6*>(figure);
            connect(this, &MainWindow::transmitSideOfStar,
                    star, &FigureStar6::receiveValue);
        }
        else if (typeOfStar == -4) {
            figure = new FigureStar8();
            FigureStar8* star = dynamic_cast<FigureStar8*>(figure);
            connect(this, &MainWindow::transmitSideOfStar,
                    star, &FigureStar8::receiveValue);
        }
        emit transmitSideOfStar(sideOfStar);
        if (dialogStatus == QDialog::Accepted) {
            scene->addItem(figure);
            setProperties();
            figure->setFlag(QGraphicsItem::ItemIsMovable);
        }
    }
    else if (currentText == "Шестиугольник") {
        clearPreviosFigure();
        FigureHexagon* hexagon = new FigureHexagon();
        connect(formHexagon, &DialogHexagon::transmitValue,
                hexagon, &FigureHexagon::receiveValue);
        dialogStatus = formHexagon->exec();
        if (dialogStatus == QDialog::Accepted) {
            figure = hexagon;
            scene->addItem(figure);
            setProperties();
            figure->setFlag(QGraphicsItem::ItemIsMovable);
        } else {
            delete hexagon;
        }
    }
    else if (currentText == "Овал") {
        clearPreviosFigure();
        FigureOval* oval = new FigureOval();
        connect(formOval, &DialogOval::transmitValues,
                oval, &FigureOval::receiveValues);
        dialogStatus = formOval->exec();
        if (dialogStatus == QDialog::Accepted) {
            figure = oval;
            scene->addItem(figure);
            setProperties();
            figure->setFlag(QGraphicsItem::ItemIsMovable);
        } else {
            delete oval;
        }
    }
}

void MainWindow::moveUpSlot()
{
    if(figure) {
        figure->moveUp();
        setProperties();
    }
}

void MainWindow::moveDownSlot()
{
    if(figure) {
        figure->moveDown();
        setProperties();
    }
}

void MainWindow::moveRightSlot()
{
    if (figure) {
        figure->moveRight();
        setProperties();
    }
}

void MainWindow::moveLeftSlot()
{
    if(figure) {
        figure->moveLeft();
        setProperties();
    }
}

void MainWindow::downScaleSlot() {
    if (figure) {
        figure->downScale();
        setProperties();
    }
}

void MainWindow::upScaleSlot() {
    if (figure) {
        figure->upScale();
        setProperties();
    }
}

void MainWindow::clearPreviosFigure()
{
    scene->clear();
    figure = nullptr;
    ui->Perimetr->setText("0");
    ui->Square->setText("0");
    ui->PosX->setText("0");
    ui->PosY->setText("0");
}

void MainWindow::on_buttonClearAll_clicked()
{
    scene->clear();
    figure = nullptr;
    ui->chooseFigure->setCurrentIndex(-1);
    ui->Perimetr->setText("0");
    ui->Square->setText("0");
    ui->PosX->setText("0");
    ui->PosY->setText("0");
}

void MainWindow::setProperties()
{
    ui->Perimetr->setText(QString::number(figure->findPerimeter(), 'f', 2));
    ui->Square->setText(QString::number(figure->findSquare(), 'f', 2));
    ui->PosX->setText(QString::number(figure->showPosition().x));
    ui->PosY->setText(QString::number(figure->showPosition().y));
}

void MainWindow::on_buttonUpScale_pressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::upScaleSlot);
    timer->start(10);
}

void MainWindow::on_buttonUpScale_released()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::upScaleSlot);
    timer->stop();
}

void MainWindow::on_buttonDownScale_pressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::downScaleSlot);
    timer->start(10);
}

void MainWindow::on_buttonDownScale_released()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::downScaleSlot);
    timer->stop();
}

void MainWindow::on_buttonRight_pressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::moveRightSlot);
    timer->start(10);
}

void MainWindow::on_buttonRight_released()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::moveRightSlot);
    timer->stop();
}

void MainWindow::on_buttonUp_pressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::moveUpSlot);
    timer->start(10);
}

void MainWindow::on_buttonUp_released()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::moveUpSlot);
    timer->stop();
}

void MainWindow::on_buttonLeft_pressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::moveLeftSlot);
    timer->start(10);
}


void MainWindow::on_buttonLeft_released()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::moveLeftSlot);
    timer->stop();
}

void MainWindow::on_buttonDown_pressed()
{
    connect(timer, &QTimer::timeout, this, &MainWindow::moveDownSlot);
    timer->start(10);
}

void MainWindow::on_buttonDown_released()
{
    disconnect(timer, &QTimer::timeout, this, &MainWindow::moveDownSlot);
    timer->stop();
}

void MainWindow::on_setXY_clicked()
{
    connect(formSetXY, &DialogSetXY::transmitValue,
            figure, &Figure::receiveValues);
    formSetXY->exec();
    figure->setPosition();
    setProperties();
}

void MainWindow::on_focusButton_clicked()
{
    ui->graphicsView->centerOn(figure);
}

void MainWindow::on_buttonRightRotation_clicked()
{
    if (figure) {
        figure->rotateRight();
        setProperties();
    }
}

void MainWindow::on_buttonLeftRotation_clicked()
{
    if (figure) {
        figure->rotateLeft();
        setProperties();
    }
}

void MainWindow::on_buttonLeftRotation_pressed()
{
    connect(timer, &QTimer::timeout, figure, &Figure::rotateLeft);
    timer->start(10);
}

void MainWindow::on_buttonLeftRotation_released()
{
    disconnect(timer, &QTimer::timeout, figure, &Figure::rotateLeft);
    timer->stop();
}

void MainWindow::on_buttonRightRotation_pressed()
{
    connect(timer, &QTimer::timeout, figure, &Figure::rotateRight);
    timer->start(10);
}

void MainWindow::on_buttonRightRotation_released()
{
    disconnect(timer, &QTimer::timeout, figure, &Figure::rotateRight);
    timer->stop();
}
