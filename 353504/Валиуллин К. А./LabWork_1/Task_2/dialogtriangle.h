#ifndef DIALOGTRIANGLE_H
#define DIALOGTRIANGLE_H

#include <QMessageBox>
#include <QDialog>
#include <QDebug>

namespace Ui {
class DialogTriangle;
}

struct TriangleCoordinates {
    int x1, y1, x2, y2, x3, y3;
};

class DialogTriangle : public QDialog
{
    Q_OBJECT

public:
    DialogTriangle(QWidget *parent = nullptr);
    ~DialogTriangle();
    double distance(int x1, int y1, int x2, int y2);
    bool isTriangleExists(const TriangleCoordinates &coordinates), ZOV;

signals:
    void triangleValues(const TriangleCoordinates &coordinates);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::DialogTriangle *ui;
};

#endif // DIALOGTRIANGLE_H
