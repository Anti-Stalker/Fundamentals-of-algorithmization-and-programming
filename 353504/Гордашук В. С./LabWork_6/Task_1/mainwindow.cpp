#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    State state1 = {100, 30.5, "state1", true, "qwe"};

    State state2;
    state2.population = 200;
    state2.area = 40.7;
    strcpy(state2.name, "state2");
    state2.independent = true;
    strcpy(state2.currency, "ZZZ");

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->setRowCount(4);
    ui->tableWidget->setColumnCount(1);

    State *state3 = new State;
    state3->population = 300;
    state3->area = 50.64;
    strcpy(state3->name, "state3");
    state3->independent = false;
    strcpy(state3->currency, "VVV");

    State state4;
    State &refstate4 = state4;
    refstate4.population = 400;
    refstate4.area = 90.132;
    strcpy(refstate4.name, "state4");
    refstate4.independent = true;
    strcpy(state4.currency, "LAG");

    ui->curerncy->setMaxLength(3);
    QRegularExpression regExp("[a-zA-Z]*");
    ui->curerncy->setValidator(new QRegularExpressionValidator(regExp, this));

    QTableWidgetItem *item1 = new QTableWidgetItem;
    item1->setText(printState(state1));
    ui->tableWidget->setItem(0, 0, item1);
    QTableWidgetItem *item2 = new QTableWidgetItem;
    item2->setText(printState(state2));
    ui->tableWidget->setItem(1, 0, item2);
    QTableWidgetItem *item3 = new QTableWidgetItem;
    item3->setText(printState(state3));
    ui->tableWidget->setItem(2, 0, item3);
    QTableWidgetItem *item4 = new QTableWidgetItem;
    item4->setText(printState(refstate4));
    ui->tableWidget->setItem(3, 0, item4);

}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::printState(State state)
{
    QString independ = "true";
    if (state.independent == 0) independ = "false";
    return QString::number(state.population) + " | " + QString::number(state.area) + " | " + state.name + " | " + independ + " | " + state.currency;
}

QString MainWindow::printState(State *state)
{
    QString independ = "true";
    if (state->independent == 0) independ = "false";
    return QString::number(state->population) + " | " + QString::number(state->area) + " | " + state->name + " | " + independ + " | " + state->currency;
}

void MainWindow::on_create_clicked()
{
    State state;
    bool ok;
    int popul = ui->population->text().toInt(&ok);
    if (ok)
    {
        state.population = popul;
    }
    else
    {
        ui->result->setText("Неверное значение");
        return;
    }
    double area = ui->area->text().toDouble(&ok);
    if (ok)
    {
        state.area = area;
    }
    else
    {
        ui->result->setText("Неверное значение");
        return;
    }
    if (ui->name->text().size() >= 20 || ui->name->text().size() == 0)
    {
        ui->result->setText("Неверное значение");
        return;
    }
    else
    {
        QString text = ui->name->text();
        strncpy(state.name, text.toStdString().c_str(), sizeof(state.name));
    }
    state.independent = ui->independence->isChecked();
    QString text = ui->curerncy->text();
    strncpy(state.currency, text.toStdString().c_str(), sizeof(state.currency));
    QTableWidgetItem *item = new QTableWidgetItem;
    item->setText(printState(state));
    ++i;
    ui->tableWidget->setRowCount(i);
    ui->tableWidget->setItem(i - 1, 0, item);
}

