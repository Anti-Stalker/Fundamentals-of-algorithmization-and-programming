#ifndef END_H
#define END_H

#include <QWidget>
#include <QPainter>
#include <QFile>

namespace Ui {
class End;
}

class End : public QWidget
{
    Q_OBJECT

public:
    explicit End(QWidget *parent = nullptr);
    ~End();
    int finalScore;
    void printFinal();
    void openFile(int a);
    void shellSort(QVector<int> &a, int n);
    QVector<int> scores;
    int interpolationSearch(QVector<int> &a, int n, int x);

private:
    Ui::End *ui;
    QString fileText;

protected:
    void paintEvent(QPaintEvent *event) override;
private slots:
    void on_pushButton_clicked();
};

#endif // END_H
