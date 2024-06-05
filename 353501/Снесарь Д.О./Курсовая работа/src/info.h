#ifndef INFO_H
#define INFO_H

#include <QWidget>

namespace Ui {
class Info;
}

class Info : public QWidget
{
    Q_OBJECT

public:
    explicit Info(QWidget *parent = nullptr);
    ~Info();
    void setPaletteW(QPalette palette);
    QPalette Palette;
private slots:
    void on_pushButton_clicked();
signals:
signals:
    void backMenu();
private:
    Ui::Info *ui;
};

#endif // INFO_H
