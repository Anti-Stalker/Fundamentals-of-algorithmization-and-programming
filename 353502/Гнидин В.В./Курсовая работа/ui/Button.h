//
// Created by volodya-petarda on 5/3/24.
//
#ifndef NEURALNETWORK_BUTTON_H
#define NEURALNETWORK_BUTTON_H
#include <QObject>
#include <QPushButton>

class Button : public QPushButton
{
    Q_OBJECT
public:
    Button(int row, QWidget *parent = 0) : QPushButton(parent), m_row(row)
    {
        connect(this, SIGNAL(clicked()), this, SLOT(onClicked()));
    }

    signals:
            void clicked(int row);

private slots:
    void onClicked()
    {
        emit clicked(m_row);
    }
private:
    int m_row;
};


#endif //NEURALNETWORK_BUTTON_H
