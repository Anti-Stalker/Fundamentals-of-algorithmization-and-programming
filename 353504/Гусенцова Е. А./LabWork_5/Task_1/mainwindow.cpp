#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Light = new QTimer(this);
    Timer = new QTimer(this);
    connect(Light, SIGNAL(timeout()), this, SLOT(Light_slot()));
    connect(Timer, SIGNAL(timeout()), this, SLOT(Timer_slot()));
    ui->textEdit->setText(Text[0]);
    fmt = ui->textEdit->currentCharFormat();
    //qDebug() << alphabet[3][29] << alphabet[3][40] << alphabet[3][28] << alphabet[3][39];
    key[96] = 0;
    key[49] = 1;
    key[50] = 2;
    key[51] = 3;
    key[52] = 4;
    key[53] = 5;
    key[54] = 6;
   key[55] = 7;
    key[56] = 8;
    key[57] = 9;
    key[48] = 10;
    key[45] = 11;
    key[61] = 12;
    key[81] = 13;
    key[87] = 14;
    key[69] = 15;
    key[82] = 16;
    key[84] = 17;
    key[89] = 18;
    key[85] = 19;
    key[73] = 20;
    key[79] = 21;
    key[80] = 22;
    key[91] = 23;
    key[93] = 24;
    key[65] = 25;
    key[83] = 26;
    key[68] = 27;
    key[70] = 28;
    key[71] = 29;
    key[72] = 30;
    key[74] = 31;
    key[75] = 32;
    key[76] = 33;
    key[59] = 34;
    key[39] = 35;
    key[90] = 36;
    key[88] = 37;
    key[67] = 38;
    key[86] = 39;
    key[66] = 40;
    key[78] = 41;
    key[77] = 42;
    key[44] = 43;
    key[46] = 44;
    key[47] = 45;
    key[Qt::Key_Space] = 46;
    buttons[0] = ui->Button1;
    buttons[1] = ui->Button2;
    buttons[2] = ui->Button3;
    buttons[3] = ui->Button4;
    buttons[4] = ui->Button5;
    buttons[5] = ui->Button6;
    buttons[6] = ui->Button7;
    buttons[7] = ui->Button8;
    buttons[8] = ui->Button9;
    buttons[9] = ui->Button10;
    buttons[10] = ui->Button11;
    buttons[11] = ui->Button12;
    buttons[12] = ui->Button13;
    buttons[13] = ui->Button14;
    buttons[14] = ui->Button15;
    buttons[15] = ui->Button16;
    buttons[16] = ui->Button17;
    buttons[17] = ui->Button18;
    buttons[18] = ui->Button19;
    buttons[19] = ui->Button20;
    buttons[20] = ui->Button21;
    buttons[21] = ui->Button22;
    buttons[22] = ui->Button23;
    buttons[23] = ui->Button24;
    buttons[24] = ui->Button25;
    buttons[25] = ui->Button26;
    buttons[26] = ui->Button27;
    buttons[27] = ui->Button28;
    buttons[28] = ui->Button29;
    buttons[29] = ui->Button30;
    buttons[30] = ui->Button31;
    buttons[31] = ui->Button32;
    buttons[32] = ui->Button33;
    buttons[33] = ui->Button34;
    buttons[34] = ui->Button35;
    buttons[35] = ui->Button36;
    buttons[36] = ui->Button37;
    buttons[37] = ui->Button38;
    buttons[38] = ui->Button39;
    buttons[39] = ui->Button40;
    buttons[40] = ui->Button41;
    buttons[41] = ui->Button42;
    buttons[42] = ui->Button43;
    buttons[43] = ui->Button44;
    buttons[44] = ui->Button45;
    buttons[45] = ui->Button46;
    buttons[46] = ui->Button47;
}

void MainWindow::Timer_slot()
{
    sec += 50;
}

void MainWindow::Light_slot()
{
    if (light_flag) {
        buttons[curr_button]->setStyleSheet("background-color: #C7EABA;");
        flag2 = true;
        light_flag = false;
    }
    light_flag = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_activated(int index)
{
    alphabet_index = index;
    ui->textEdit->setText(Text[index]);
    for (int i = 0; i < 47; i++) {
        buttons[i]->setText(alphabet[index][i]);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (flag && flag2 && event->key() < 100000) {
        all++;
        curr_button = key[event->key()];
        if (alphabet[alphabet_index][key[event->key()]] == Text[alphabet_index][right]) {
            right_text = Text[alphabet_index].mid(0, right + 1);
            other_text = Text[alphabet_index].mid(right + 1, Text[alphabet_index].size());
            ui->textEdit->clear();
            fmt.setForeground(QBrush(Qt::green));
            ui->textEdit->setCurrentCharFormat(fmt);
            ui->textEdit->append(right_text);
            fmt.clearForeground();
            ui->textEdit->setCurrentCharFormat(fmt);
            ui->textEdit->append(other_text);
            right++;
            buttons[key[event->key()]]->setStyleSheet("background-color: green;");
            flag2 = false;
            if (right == Text[alphabet_index].size()) {
                on_finish_clicked();

            }
        } else {
            qDebug() << alphabet[alphabet_index][key[event->key()]] << Text[alphabet_index][right];
            buttons[key[event->key()]]->setStyleSheet("background-color: red;");

            flag2 = false;
        }
        qDebug() << event->key();
    }
}

void MainWindow::on_start_clicked()
{
    if (!flag) {
        ui->textEdit->setText(Text[alphabet_index]);
        sec = 0;
        right = 0;
        all = 0;
        Timer->start(50);
        flag = true;
        ui->start->setEnabled(false);
        ui->finish->setEnabled(true);
        ui->comboBox->setEnabled(false);
    }
}

void MainWindow::on_finish_clicked()
{
    if (flag) {
        flag = false;
        buttons[curr_button]->setStyleSheet("background-color: #C7EABA;");
        flag2 = true;
        Timer->stop();
        if (all == 0) {
            msgbox.setText("Время: " + QString::number(double(sec) / 1000)
                           + "\nКоличество символов в минуту: "
                           + QString::number(double(right) / sec * 60000)
                           + "\nТочность: " + QString::number(0));
        } else {
            msgbox.setText("Время: " + QString::number(double(sec) / 1000)
                           + "\nКоличество символов в минуту: "
                           + QString::number(double(right) / sec * 60000)
                           + "\nТочность: " + QString::number(double(right) / all * 100));
        }
        ui->comboBox->setEnabled(true);
        ui->start->setEnabled(true);
        ui->finish->setEnabled(false);
        msgbox.exec();
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (!flag2) {
         buttons[curr_button]->setStyleSheet("background-color: #C7EABA;");
           flag2 = true;
    }
}
