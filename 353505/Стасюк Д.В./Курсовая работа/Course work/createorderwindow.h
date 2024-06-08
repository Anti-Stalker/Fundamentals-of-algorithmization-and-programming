#ifndef CREATEORDERWINDOW_H
#define CREATEORDERWINDOW_H

#include <QMainWindow>
#include <modelviewer.h>
#include <orders.h>
#include <QQmlApplicationEngine>

struct Model {
    QString name;
    QString path;
    int id;

    Model(QString n, QString p, int _id): name(n), path(p), id(_id) {};
};

struct Material {
    QString name;
    float pricePerPice;

    Material(std::string n, float pp): name(QString::fromStdString(n)), pricePerPice(pp) {};
};


namespace Ui {
class CreateOrderWindow;
}

class CreateOrderWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CreateOrderWindow(QWidget *parent = nullptr, QQmlApplicationEngine *eng = nullptr, Orders *ords=nullptr);
    ~CreateOrderWindow();

private slots:
    void on_materialComboBox_textActivated(const QString &arg1);

    void on_modelComboBox_textActivated(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::CreateOrderWindow *ui;
    QList<Model> *modelList;
    QList<Material> *materialList;
    QQmlApplicationEngine *engine;
    Orders *orders;
};

#endif // CREATEORDERWINDOW_H
