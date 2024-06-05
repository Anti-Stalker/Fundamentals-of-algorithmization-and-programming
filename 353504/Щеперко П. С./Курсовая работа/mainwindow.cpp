#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //объединение кнопок в группы
    comboBoxes = {ui->caliber_366TKM_CartridgeComboBox,
                  ui->caliber_545x39mm_CartridgeComboBox,
                  ui->caliber_762x54mmR_CartridgeComboBox,
                  ui->caliber_9x18mm_CartridgeComboBox,
                  ui->caliber_9x19mm_CartridgeComboBox};
    comboBoxes_2 = {ui->caliber_366TKM_CartridgeComboBox_2,
                    ui->caliber_545x39mm_CartridgeComboBox_2,
                    ui->caliber_762x54mmR_CartridgeComboBox_2,
                    ui->caliber_9x18mm_CartridgeComboBox_2,
                    ui->caliber_9x19mm_CartridgeComboBox_2};

    //объединение виджетов сравнения в группу
    comparedWidgets = {ui->caliberLabel_2,
                       ui->caliberComboBox_2,
                       ui->cartridgeLabel_2,
                       ui->caliber_366TKM_CartridgeComboBox_2,
                       ui->caliber_545x39mm_CartridgeComboBox_2,
                       ui->caliber_762x54mmR_CartridgeComboBox_2,
                       ui->caliber_9x18mm_CartridgeComboBox_2,
                       ui->caliber_9x19mm_CartridgeComboBox_2,
                       ui->muzzleVelocityLabel_2,
                       ui->muzzleVelocityLineEdit_2,
                       ui->ballisticCoefficientLabel_2,
                       ui->ballisticCoefficientLineEdit_2,
                       ui->diameterLabel_2,
                       ui->diameterLineEdit_2,
                       ui->weightLabel_2,
                       ui->weightLineEdit_2,
                       ui->airDensityLabel_2,
                       ui->airDensityLineEdit_2,
                       ui->tableWidget_2,
                       ui->calculatingMethodLabel_2,
                       ui->verticalLayoutWidget_2};

    comboBoxesMap = {{"comboBoxes", comboBoxes}, {"comboBoxes_2", comboBoxes_2}};

    methods = {ui->rungeKuttaRadioButton,
               ui->trapezoidMethodRadioButton,
               ui->simpsonMethodRadioButton};
    methods_2 = {ui->rungeKuttaRadioButton_2,
                 ui->trapezoidMethodRadioButton_2,
                 ui->simpsonMethodRadioButton_2};
    methodsMap = {{"methods", methods}, {"methods_2", methods_2}};

    ui->rungeKuttaRadioButton->click();
    ui->rungeKuttaRadioButton_2->click();

    ShowComboBox(_366TKM);
    ShowComboBox(_366TKM, "_2");

    //установление изначального текста
    SetPropertiesText(770, 0.135, 9.55, 6.5);
    SetPropertiesText(770, 0.135, 9.55, 6.5, "_2");

    ui->airDensityLineEdit->setText("1.225");
    ui->airDensityLineEdit_2->setText("1.225");


    SetComparedWidgetsStatus(Qt::Unchecked);

    ui->rangeLineEdit->setText("1000");
    ui->rowsLineEdit->setText("10");

    calculator = new Calculator;

    SetTableWidgets(ui->tableWidget);
    SetTableWidgets(ui->tableWidget_2);

    ui->windSpeedVerticalSlider->setRange(VERT_SLIDER_MIN, VERT_SLIDER_MAX);

    ui->trajectoryGraph->xAxis->setLabel("Range");
    ui->trajectoryGraph->yAxis->setLabel("Drop");
    ui->trajectoryGraph->setInteraction(QCP::iRangeDrag, true);
    ui->trajectoryGraph->setInteraction(QCP::iRangeZoom, true);

    psoPixmap = new QPixmap(":/scope/scope_reticles/PSO-1.png");
    acogPixmap = new QPixmap(":/scope/scope_reticles/ACOG.png");
    reticleItem = new QGraphicsPixmapItem(*psoPixmap);
    scene = new QGraphicsScene;
    scene->setSceneRect(SCENE_INITIAL_X, SCENE_INITIAL_Y, SCENE_WIDTH, SCENE_HEIGHT);
    ui->reticleView->setFrameStyle(QFrame::NoFrame);
    ui->reticleView->setScene(scene);
    scene->addItem(reticleItem);

    shotPoint.first = new QGraphicsEllipseItem(INITIAL_SHOT_POINT_POS, INITIAL_SHOT_POINT_POS, POINT_SIZE, POINT_SIZE);
    shotPoint.first->setBrush(Qt::green);
    scene->addItem(shotPoint.first);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete calculator;
    delete psoPixmap;
    delete acogPixmap;
    delete reticleItem;
    delete scene;
}

inline void MainWindow::ShowComboBox(Calibr calibr, QString suffix)
{
    for (auto comboBox : comboBoxesMap["comboBoxes" + suffix]) {
        comboBox->hide();
    }
    comboBoxesMap["comboBoxes" + suffix][calibr]->show();
}

inline void MainWindow::SetPropertiesText(double muzzleVelocity,
                                   double ballisticCoefficient,
                                   double diameter,
                                   double weight,
                                   QString suffix)
{
    findChild<QLineEdit *>("muzzleVelocityLineEdit" + suffix)->setText(QString::number(muzzleVelocity));
    findChild<QLineEdit *>("ballisticCoefficientLineEdit" + suffix)->setText(QString::number(ballisticCoefficient));
    findChild<QLineEdit *>("diameterLineEdit" + suffix)->setText(QString::number(diameter));
    findChild<QLineEdit *>("weightLineEdit" + suffix)->setText(QString::number(weight));
}

inline void MainWindow::SetTableRowHeight(QTableWidget *table){
    for (int i = 0; i < table->rowCount(); ++i)
        table->setRowHeight(i, TABLE_ROW_HEIGHT);
}

inline void MainWindow::SetTableWidgets(QTableWidget *table)
{
    table->setRowCount(ui->rowsLineEdit->text().toInt());
    table->setColumnCount(TABLE_COLUMN_COUNT);

    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    SetTableRowHeight(table);
    for (int i = 0; i < table->rowCount(); ++i)
        table->setRowHeight(i, TABLE_ROW_HEIGHT);

    QStringList headers;
    headers << "Distance" << "Velocity" << "Energy" << "Drop" << "Time of flight";
    table->setHorizontalHeaderLabels(headers);
    table->horizontalHeader()->setFixedHeight(TABLE_HORIZ_HEADER_HEIGHT);
    table->verticalHeader()->setFixedWidth(TABLE_VERT_HEADER_WIDTH);
}

inline IntegrationMethod MainWindow::ClickedMethod(QString suffix)
{
    QVector<QRadioButton *> methods = methodsMap["methods" + suffix];
    for (int i = 0; i < methods.size(); ++i) {
        if (methods[i]->isChecked())
            return static_cast<IntegrationMethod>(i);
    }
}

inline void MainWindow::SetComparedWidgetsStatus(Qt::CheckState status)
{
    for(QWidget* widget : comparedWidgets) {
        widget->setEnabled(status);
    }
}

void MainWindow::on_caliberComboBox_activated(int index)
{
    switch (index) {
    case _366TKM:
        ShowComboBox(_366TKM);
        SetPropertiesText(770, 0.135, 9.55, 6.5);
        break;
    case _545x39mm:
        ShowComboBox(_545x39mm);
        SetPropertiesText(880, 0.209, 5.62, 3.02);
        break;
    case _762x54mmR:
        ShowComboBox(_762x54mmR);
        SetPropertiesText(785, 0.425, 7.92, 12.2);
        break;
    case _9x18mm:
        ShowComboBox(_9x18mm);
        SetPropertiesText(298, 0.097, 9.27, 5.9);
        break;
    case _9x19mm:
        ShowComboBox(_9x19mm);
        SetPropertiesText(365, 0.105, 9.0, 6.0);
        break;
    }
}

void MainWindow::on_caliber_366TKM_CartridgeComboBox_activated(int index)
{
    switch (index) {
    case EKO:
        SetPropertiesText(770, 0.135, 9.55, 6.5);
        break;
    case FMJ:
        SetPropertiesText(580, 0.202, 9.55, 13);
        break;
    case Geksa:
        SetPropertiesText(550, 0.241, 9.55, 15.5);
        break;
    }
}

void MainWindow::on_caliber_545x39mm_CartridgeComboBox_activated(int index)
{
    switch (index) {
    case BT:
        SetPropertiesText(880, 0.209, 5.62, 3.02);
        break;
    case HP:
        SetPropertiesText(884, 0.246, 5.62, 3.56);
        break;
    case PS:
        SetPropertiesText(890, 0.235, 5.62, 3.4);
        break;
    case US:
        SetPropertiesText(303, 0.355, 5.62, 5.15);
        break;
    }
}

void MainWindow::on_caliber_762x54mmR_CartridgeComboBox_activated(int index)
{
    switch (index) {
    case BS:
        SetPropertiesText(785, 0.425, 7.92, 12.2);
        break;
    case T_46M:
        SetPropertiesText(800, 0.289, 7.92, 9.6);
        break;
    case LPS:
        SetPropertiesText(865, 0.334, 7.92, 9.6);
        break;
    case SNB:
        SetPropertiesText(875, 0.342, 7.92, 9.8);
        break;
    }
}

void MainWindow::on_caliber_9x18mm_CartridgeComboBox_activated(int index)
{
    switch (index) {
    case Pst:
        SetPropertiesText(298, 0.097, 9.27, 5.9);
        break;
    case SP7:
        SetPropertiesText(420, 0.069, 9.27, 4.2);
        break;
    case SP8:
        SetPropertiesText(250, 0.083, 9.27, 5.0);
        break;
    }
}

void MainWindow::on_caliber_9x19mm_CartridgeComboBox_activated(int index)
{
    switch (index) {
    case GT:
        SetPropertiesText(365, 0.105, 9.0, 6.0);
        break;
    case Luger_CCI:
        SetPropertiesText(420, 0.131, 9.0, 7.46);
        break;
    case RIP:
        SetPropertiesText(381, 0.075, 9.0, 5.97);
        break;
    }
}

void MainWindow::on_gunsightComboBox_currentIndexChanged(int index)
{
    enum Scope { PSO_1, ACOG };

    scene->removeItem(reticleItem);
    delete reticleItem;

    switch (index) {
    case PSO_1:
        reticleItem = new QGraphicsPixmapItem(*psoPixmap);
        scene->addItem(reticleItem);
        break;
    case ACOG:
        reticleItem = new QGraphicsPixmapItem(*acogPixmap);
        scene->addItem(reticleItem);
        break;
    }
}

void MainWindow::on_windSpeedVerticalSlider_valueChanged(int value)
{
    calculator->windSpeed = value;
}

void MainWindow::on_comparisonCheckBox_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked) {
        SetComparedWidgetsStatus(Qt::Checked);
    } else {
        SetComparedWidgetsStatus(Qt::Unchecked);
    }
}

void MainWindow::on_caliberComboBox_2_activated(int index)
{
    switch (index) {
    case _366TKM:
        ShowComboBox(_366TKM, "_2");
        SetPropertiesText(770, 0.135, 9.55, 6.5, "_2");
        break;
    case _545x39mm:
        ShowComboBox(_545x39mm, "_2");
        SetPropertiesText(880, 0.209, 5.62, 3.02, "_2");
        break;
    case _762x54mmR:
        ShowComboBox(_762x54mmR, "_2");
        SetPropertiesText(785, 0.425, 7.92, 12.2, "_2");
        break;
    case _9x18mm:
        ShowComboBox(_9x18mm, "_2");
        SetPropertiesText(298, 0.097, 9.27, 5.9, "_2");
        break;
    case _9x19mm:
        ShowComboBox(_9x19mm, "_2");
        SetPropertiesText(365, 0.105, 9.0, 6.0, "_2");
        break;
    }
}

void MainWindow::on_caliber_366TKM_CartridgeComboBox_2_activated(int index)
{
    switch (index) {
    case EKO:
        SetPropertiesText(770, 0.135, 9.55, 6.5, "_2");
        break;
    case FMJ:
        SetPropertiesText(580, 0.202, 9.55, 13, "_2");
        break;
    case Geksa:
        SetPropertiesText(550, 0.241, 9.55, 15.5, "_2");
        break;
    }
}

void MainWindow::on_caliber_545x39mm_CartridgeComboBox_2_activated(int index)
{
    switch (index) {
    case BT:
        SetPropertiesText(880, 0.209, 5.62, 3.02, "_2");
        break;
    case HP:
        SetPropertiesText(884, 0.246, 5.62, 3.56, "_2");
        break;
    case PS:
        SetPropertiesText(890, 0.235, 5.62, 3.4, "_2");
        break;
    case US:
        SetPropertiesText(303, 0.355, 5.62, 5.15, "_2");
        break;
    }
}

void MainWindow::on_caliber_762x54mmR_CartridgeComboBox_2_activated(int index)
{
    switch (index) {
    case BS:
        SetPropertiesText(785, 0.425, 7.92, 12.2, "_2");
        break;
    case T_46M:
        SetPropertiesText(800, 0.289, 7.92, 9.6, "_2");
        break;
    case LPS:
        SetPropertiesText(865, 0.334, 7.92, 9.6, "_2");
        break;
    case SNB:
        SetPropertiesText(875, 0.342, 7.92, 9.8, "_2");
        break;
    }
}

void MainWindow::on_caliber_9x18mm_CartridgeComboBox_2_activated(int index)
{
    switch (index) {
    case Pst:
        SetPropertiesText(298, 0.097, 9.27, 5.9, "_2");
        break;
    case SP7:
        SetPropertiesText(420, 0.069, 9.27, 4.2, "_2");
        break;
    case SP8:
        SetPropertiesText(250, 0.083, 9.27, 5.0, "_2");
        break;
    }
}

void MainWindow::on_caliber_9x19mm_CartridgeComboBox_2_activated(int index)
{
    switch (index) {
    case GT:
        SetPropertiesText(365, 0.105, 9.0, 6.0, "_2");
        break;
    case Luger_CCI:
        SetPropertiesText(420, 0.131, 9.0, 7.46, "_2");
        break;
    case RIP:
        SetPropertiesText(381, 0.075, 9.0, 5.97, "_2");
        break;
    }
}

inline void MainWindow::SetCalculatorValues(QString suffix)
{
    calculator->ballisticCoefficient
        = findChild<QLineEdit *>("ballisticCoefficientLineEdit" + suffix)->text().toDouble();
    calculator->velocity
        = findChild<QLineEdit *>("muzzleVelocityLineEdit" + suffix)->text().toDouble();
    calculator->diameter = findChild<QLineEdit *>("diameterLineEdit" + suffix)->text().toDouble()
                           / 1000.0; //перевод в метры
    calculator->weight = findChild<QLineEdit *>("weightLineEdit" + suffix)->text().toDouble()
                         / 1000.0; //перевод в граммы
    calculator->airDensity = findChild<QLineEdit *>("airDensityLineEdit" + suffix)->text().toDouble();
    calculator->range = findChild<QLineEdit *>("rangeLineEdit")->text().toUShort();
    calculator->rows = findChild<QLineEdit *>("rowsLineEdit")->text().toUShort();
    calculator->windRatio = 1;
}

inline void MainWindow::SetTrajectory(QCPGraph *&graph, QColor color)
{
    graph = ui->trajectoryGraph->addGraph();
    graph->setPen(QPen(color));
    graph->setData(calculator->distance, calculator->drop);
    ui->trajectoryGraph->rescaleAxes();
    ui->trajectoryGraph->replot();
}

inline void MainWindow::DrawPoint(QColor color, QGraphicsEllipseItem *&ellipse)
{
    const int dx = calculator->deviation / (calculator->range * 100 / 1000) * SEGMENT_PIXEL_COUNT;
    const int dy = calculator->drop.back() * 100 / (calculator->range * 100 / 1000) * SEGMENT_PIXEL_COUNT;
    ellipse = new QGraphicsEllipseItem(INITIAL_SHOT_POINT_POS + dx, INITIAL_SHOT_POINT_POS - dy, POINT_SIZE, POINT_SIZE);

    ellipse->setBrush(color);
    scene->addItem(ellipse);
}

inline void MainWindow::SetTableAlignCenter(QTableWidget *table)
{
    for (int i = 0; i < table->rowCount(); ++i) {
        for (int j = 0; j < table->columnCount(); ++j) {
            table->item(i, j)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

inline void MainWindow::SetTableValues(QTableWidget *table)
{
    table->setRowCount(ui->rowsLineEdit->text().toInt());
    for (int i = 0; i < table->rowCount(); ++i) {
        table->setItem(i,
                                 0,
                                 new QTableWidgetItem(
                                     QString::number(calculator->bulletConditions[i].distance) + " m"));
        table->setItem(i,
                                 1,
                                 new QTableWidgetItem(
                                     QString::number(calculator->bulletConditions[i].velocity) + " m/s"));
        table->setItem(i,
                                 2,
                                 new QTableWidgetItem(
                                     QString::number(calculator->bulletConditions[i].energy) + " j"));
        table->setItem(i,
                                 3,
                                 new QTableWidgetItem(
                                     QString::number(calculator->bulletConditions[i].drop) + " cm"));
        table->setItem(i,
                                 4,
                                 new QTableWidgetItem(QString::number(
                                     calculator->bulletConditions[i].timeOfFlight) + " s"));
    }
    SetTableAlignCenter(table);
    SetTableRowHeight(table);
}

void MainWindow::on_calculatePushButton_clicked()
{
    calculator->distance.clear();
    calculator->drop.clear();
    for (; ui->trajectoryGraph->graphCount() > 0;) {
        ui->trajectoryGraph->removeGraph(0);
    }
    scene->removeItem(shotPoint.first);
    delete shotPoint.first;
    if (shotPoint.second != nullptr) {
        scene->removeItem(shotPoint.second);
        delete shotPoint.second;
        shotPoint.second = nullptr;
    }
    SetCalculatorValues();
    calculator->CalculateBulletConditions(ClickedMethod());

    SetTableValues(ui->tableWidget);
    SetTrajectory(graph.first, Qt::green);

    DrawPoint(Qt::green, shotPoint.first);

    if (ui->comparisonCheckBox->isChecked()) {
        SetCalculatorValues("_2");
        calculator->CalculateBulletConditions(ClickedMethod("_2"));
        SetTableValues(ui->tableWidget_2);
        SetTrajectory(graph.second, Qt::red);
        DrawPoint(Qt::red, shotPoint.second);
    }
}