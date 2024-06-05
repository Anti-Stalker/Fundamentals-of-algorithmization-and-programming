#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPixmap>
#include <QRandomGenerator>
namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
    QPalette getPaletteW();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

signals:
    void openPlay();
    void openSolve();
    void openInfo();
private:
    Ui::Menu *ui;
    QPixmap logo;
    QVector<std::pair<QColor, QColor>> colors;
};

#endif // MENU_H
