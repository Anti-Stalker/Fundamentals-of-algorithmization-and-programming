#ifndef DIALOGHEXAGON_H
#define DIALOGHEXAGON_H

#include <QDialog>

namespace Ui {
class DialogHexagon;
}

class DialogHexagon : public QDialog
{
    Q_OBJECT

public:
    DialogHexagon(QWidget *parent = nullptr);
    ~DialogHexagon();

signals:
    void transmitValue(int side);

private slots:    
    void on_buttonBox_accepted();

private:
    Ui::DialogHexagon *ui;

};

#endif // DIALOGHEXAGON_H
