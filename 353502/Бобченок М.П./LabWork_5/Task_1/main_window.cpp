//
// Created by u on 28.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_main_window.h" resolved

#include "main_window.h"
#include "ui_main_window.h"



void main_window::setText(const QString& lan)
{
    for (int i = 0; i < 32; i++)
        labels[i]->setText(lan.mid(i, 1));
}

void main_window::open()
{
    QString f = QFileDialog::getOpenFileName(this, "Load a file", "../texts");

    std::ifstream fin(f.toStdString());
    if (!fin.is_open())
        return;

    text = "";
    while (!fin.eof())
    {
        std::string r;
        std::getline(fin, r);
        text += QString::fromStdString(r + "\n");
    }
}

void main_window::updateWindow()
{
    QString style = "background-color: white;\n"
                    "font: 400 41pt \"Ubuntu\";\n"
                    "border: 4px solid black;";

    while (!st.empty() && (*st.begin()).first < cur_time)
    {
        auto u = *st.begin(); st.erase(st.begin());
        if (u.first < cur_time)
        {
            int kol = 0;
            for (auto p : st)
            {
                if (p.second == u.second)
                    kol++;
            }
            if (kol < 2)
                labels[u.second]->setStyleSheet(style);
            st.erase(u);
        }
    }

    if (text.size() >= cur)
    {
        ui->text->setText("<span style='color:green'>" + text.mid(0, cur) + "</span><span style='color:black'>" + text.mid(cur, text.size() - cur) + "</span>");
        ui->text->setWordWrap(true);
    }

    cur_time += 50;
    if (!working)
    {
        t = 0;

        if (ui->language->currentIndex() != comboIndex)
        {
            comboIndex = ui->language->currentIndex();
            cur = 0;

            file = "../texts/";
            switch (ui->language->currentIndex())
            {
                case 0:
                    setText(en);
                    file += "en";
                    break;
                case 1:
                    setText(ru);
                    file += "ru";
                    break;
                case 2:
                    setText(de);
                    file += "de";
                    break;
                case 3:
                    setText(fr);
                    file += "fr";
                    break;
                case 4:
                    setText(ar);
                    file += "ar";
                    break;
                case 5:
                    setText(by);
                    file += "by";
                    break;
                case 6:
                    setText(he);
                    file += "he";
                    break;
                case 7:
                    setText(zh);
                    file += "zh";
                    break;
            }

            file += ".txt";

            std::ifstream fin(file);
            if (!fin.is_open())
                return;

            text = "";
            while (!fin.eof())
            {
                std::string r;
                std::getline(fin, r);
                text += QString::fromStdString(r + "\n");
            }
        }

        ui->timer->setText("0");
        int tm = 1000 * sm / 200;
        ui->sm->setText(QString::number((double)tm / 100));
        int ac = 0;
        if (cor > 0)
            ac = 100 * cor / (cor + wrong);
        ui->accuracy->setText(QString::number(ac));
        return;
    }

    t += 50;

    int ac = 0;
    if (cor > 0)
        ac = 100 * cor / (cor + wrong);
    ui->accuracy->setText(QString::number(ac));

    int tm = 100000 * sm / t;
    ui->sm->setText(QString::number((double)tm / 100));
    ui->timer->setText(QString::number(range - t / 1000));
    if (range - t / 1000 == 0)
        working = false;
}

main_window::main_window(QWidget *parent) :
        QWidget(parent), ui(new Ui::main_window)
{
    ui->setupUi(this);

    ar += " ";
    allLan[0] = en;
    allLan[1] = ru;
    allLan[2] = de;
    allLan[3] = fr;
    allLan[4] = ar;
    allLan[5] = by;
    allLan[6] = he;
    allLan[7] = zh;

    labels.push_back(ui->l1);
    labels.push_back(ui->l2);
    labels.push_back(ui->l3);
    labels.push_back(ui->l4);
    labels.push_back(ui->l5);
    labels.push_back(ui->l6);
    labels.push_back(ui->l7);
    labels.push_back(ui->l8);
    labels.push_back(ui->l9);
    labels.push_back(ui->l10);
    labels.push_back(ui->l11);
    labels.push_back(ui->l12);
    labels.push_back(ui->l13);
    labels.push_back(ui->l14);
    labels.push_back(ui->l15);
    labels.push_back(ui->l16);
    labels.push_back(ui->l17);
    labels.push_back(ui->l18);
    labels.push_back(ui->l19);
    labels.push_back(ui->l20);
    labels.push_back(ui->l21);
    labels.push_back(ui->l22);
    labels.push_back(ui->l23);
    labels.push_back(ui->l24);
    labels.push_back(ui->l25);
    labels.push_back(ui->l26);
    labels.push_back(ui->l27);
    labels.push_back(ui->l28);
    labels.push_back(ui->l29);
    labels.push_back(ui->l30);
    labels.push_back(ui->l31);
    labels.push_back(ui->l32);
    labels.push_back(ui->space);

    connect(ui->load, SIGNAL(clicked(bool)), this, SLOT(open()));

    auto *timer = new QTimer(this);
    timer->setInterval(50);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateWindow()));
    timer->start();
}

void main_window::keyPressEvent(QKeyEvent *event)
{

    for (int i = 0; i < labels.size(); i++)
        if (keys[i] == event->key())
        {
            int pos;
            if (working)
                pos = cur;
            else
                pos = 0;
            if (pos < text.size() && (text.mid(pos, 1) == allLan[ui->language->currentIndex()].mid(i, 1) ||
                                                (text.mid(pos, 1) == "\n" && allLan[ui->language->currentIndex()].mid(i, 1) == " ")))
            {
                if (t == 0)
                {
                    cor = 0;
                    wrong = 0;
                    working = true;
                    cur = 0;
                    sm = 0;
                }
                QString style = "background-color: green;\n"
                                "font: 400 41pt \"Ubuntu\";\n"
                                "border: 4px solid black;";
                st.insert({cur_time + 50, i});
                labels[i]->setStyleSheet(style);

                sm++;
                cur++;
                cor++;
            }
            else
            {
                QString style = "background-color: red;\n"
                                "font: 400 41pt \"Ubuntu\";\n"
                                "border: 4px solid black;";
                st.insert({cur_time + 50, i});
                labels[i]->setStyleSheet(style);

                if (working)
                    wrong++;
            }
        }
}

main_window::~main_window() {
    delete ui;
}
