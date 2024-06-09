#include "mainwindow.h"
#include "QLineEdit"
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      central_widget(new QWidget(this)),
      keyboard_widget(new KeyboardWidget(this)),
      dynamic_text(new DynamicText(this)),
      layout(new QGridLayout),
      words_info(new QLabel(this)),
      timer(new QElapsedTimer()),
      qtimer(new QTimer()),
      restart_button(new QPushButton("Начать сначала", this)),
      open_file_button(new QPushButton("Открыть текст", this)),
      combo_box(new QComboBox(this))
{
    QStringList options = { "russian", "english", "belarussian", "hebrew", "french"};
    combo_box->addItems(options);

    connect(open_file_button, &QPushButton::clicked, this, &MainWindow::openText);
    connect(dynamic_text, &DynamicText::TextChangedSignal, keyboard_widget, &KeyboardWidget::setPressButton);
    connect(restart_button, &QPushButton::clicked, this, &MainWindow::restart);
    connect(qtimer, &QTimer::timeout, this, &MainWindow::updateInfo);
    connect(combo_box, &QComboBox::currentTextChanged, keyboard_widget, &KeyboardWidget::setLanguage);

    open_file_button->setFocusPolicy(Qt::NoFocus);
    restart_button->setFocusPolicy(Qt::NoFocus);
    combo_box->setFocusPolicy(Qt::NoFocus);

    qtimer->start(10);

    layout->addWidget(combo_box, 0, 0);
    layout->addWidget(open_file_button, 1, 0);
    layout->addWidget(restart_button, 2, 0);
    layout->addWidget(words_info, 3, 0);
    layout->addWidget(dynamic_text, 4, 0, Qt::AlignVCenter);
    layout->addWidget(keyboard_widget, 5, 0, Qt::AlignVCenter);

    central_widget->setLayout(layout);
    setCentralWidget(central_widget);

    restart();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (!dynamic_text->isEnd()) {
        dynamic_text->keyPress(event);
    }
}

void MainWindow::updateInfo()
{
    if (dynamic_text->getSymbCount() == 0) {
        timer->start();
    }

    if (!dynamic_text->isEnd()) {
        time = timer->elapsed() / 1000.0;
    }

    words_info->setText("Набрано слов: " +  QString::number(dynamic_text->getWordCount()) + "\n" +
                        "Набрано символов: " + QString::number(dynamic_text->getSymbCount()) + "\n" +
                        "Точность: " + QString::number(dynamic_text->getAccuracy()) + "%\n" +
                        "Прошло время: " + QString::number(time) + "c\n" +
                        "Слов в минуту: " + QString::number(dynamic_text->getWordCount() / time * 60) + "\n" +
                        "Символов в минуту: " + QString::number(dynamic_text->getSymbCount() / time * 60) + "\n");
}

void MainWindow::restart()
{
    dynamic_text->setTemplate(current_template);
    dynamic_text->showText();
    updateInfo();
}

void MainWindow::openText()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Открыть файл", "", "(*.txt)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Не удалось открыть файл";
        }

        QTextStream in(&file);
        QString text = in.readAll();
        current_template = text;
        restart();

        file.close();
    }
}


