#include "dialogtriangle.h"
#include "ui_dialogtriangle.h"

DialogTriangle::DialogTriangle(QWidget *parent) :
    QDialog(parent), ui(new Ui::DialogTriangle)
{
    ui->setupUi(this);
}

DialogTriangle::~DialogTriangle()
{
    delete ui;
}

void DialogTriangle::on_buttonBox_accepted()
{
    TriangleCoordinates coordinates;
    coordinates.x1 = ui->spinBox->value();
    coordinates.y1 = ui->spinBox_2->value();
    coordinates.x2 = ui->spinBox_3->value();
    coordinates.y2 = ui->spinBox_4->value();
    coordinates.x3 = ui->spinBox_5->value();
    coordinates.y3 = ui->spinBox_6->value();

    ZOV = isTriangleExists(coordinates);

    if(ZOV) {
        emit triangleValues(coordinates);
    }
    else {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setWindowTitle("Ошибка");
        msgBox.setText("Неправильный ввод. Треугольник с данными координатами не существует!");
        msgBox.addButton("Бывает", QMessageBox::AcceptRole);
        msgBox.exec();
    }
}

double DialogTriangle::distance(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    return std::sqrt(dx * dx + dy * dy);
}

bool DialogTriangle::isTriangleExists(const TriangleCoordinates &coordinates) {
    double side1 = distance(coordinates.x1, coordinates.y1, coordinates.x2, coordinates.y2);
    double side2 = distance(coordinates.x2, coordinates.y2, coordinates.x3, coordinates.y3);
    double side3 = distance(coordinates.x3, coordinates.y3, coordinates.x1, coordinates.y1);
    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        return false;
    }
    if (side1 + side2 > side3 && side2 + side3 > side1 && side3 + side1 > side2) {
        return true;
    }
    return false;
}
