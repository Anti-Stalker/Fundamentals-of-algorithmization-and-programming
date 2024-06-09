#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    FillButtons();

    keysButton.at(0)->setText("1");

    ui->label->setPixmap(QPixmap("/home/v/proga/Labs/Lab_5/Task_1/Keyboard.jpeg"));

    TextToInput = textToEnter.English;
    languageOnKeys = allLanguages.English;
    ui->label_Fortext->setText(TextToInput);
    for (int i = 0; i < keysButton.size(); ++i) {
        keysButton.at(i)->setText(languageOnKeys.at(2 * i));
    }

    Timer = new QTimer(this);

    connect(Timer, SIGNAL(timeout()), this, SLOT(UpdateInfo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FillButtons()
{
    keysButton = {ui->pushButton, ui->pushButton_2, ui->pushButton_3, ui->pushButton_4, ui->pushButton_5, ui->pushButton_6, ui->pushButton_7, ui->pushButton_8, ui->pushButton_9, ui->pushButton_10,ui->pushButton_11,ui->pushButton_12,
                  ui->pushButton11, ui->pushButton12, ui->pushButton13, ui->pushButton14, ui->pushButton15, ui->pushButton16, ui->pushButton17, ui->pushButton18, ui->pushButton19, ui->pushButton20, ui->pushButton_13,
                  ui->pushButton21, ui->pushButton22, ui->pushButton23, ui->pushButton24, ui->pushButton25, ui->pushButton26, ui->pushButton27, ui->pushButton28, ui->pushButton29, ui->pushButton30};
}

void MainWindow::Addtext()
{
    QString NewText = "";
    int RandFrom = rand() % 10;
    int RandTo = rand() % 30;
    if(RandTo < RandFrom){
        RandTo += 20;
    }

    for(int i = RandFrom; i < RandTo; ++i){
        NewText += TextToInput.at(i);
    }

    TextToInput += NewText;
    ui->label_Fortext->setText(TextToInput);
}

void MainWindow::UpdateInfo()
{
    PassedTime += Timer->interval();
    accuracy = CorrectButtons / PressedButtons;
    SymbolsInMin = CorrectButtons / PassedTime * 1000;

    ui->Timer->setNum(PassedTime / 1000);
    ui->Accuracy->setText(QString().setNum(accuracy * 100));
    ui->Speed->setNum(SymbolsInMin);
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    Timer->stop();
    IsActive = false;

    PassedTime = 0;
    PressedButtons = 0;
    CorrectButtons = 0;

    switch (index) {
    case 0:
        languageOnKeys = allLanguages.English;
        TextToInput = textToEnter.English;
        break;
    case 1:
        languageOnKeys = allLanguages.Arabic;
        TextToInput = textToEnter.Arabic;
        break;
    case 2:
        languageOnKeys = allLanguages.Belarusian;
        TextToInput = textToEnter.Belarusian;
        break;
    case 3:
        languageOnKeys = allLanguages.Franch;
        TextToInput = textToEnter.Franch;
        break;
    case 4:
        languageOnKeys = allLanguages.German;
        TextToInput = textToEnter.German;
        break;
    case 5:
        languageOnKeys = allLanguages.Huinya;
        TextToInput = textToEnter.Huinya;
        break;
    default:
        break;
    }
    ui->lineInput->clear();
    ui->label_Fortext->setText(TextToInput);

    for (int i = 0; i < keysButton.size(); ++i) {
        keysButton.at(i)->setText(languageOnKeys.at(2 * i));
    }
}

void MainWindow::on_lineInput_textEdited(const QString &text)
{
    if(!IsActive){
        Timer->start(10);
        IsActive = true;
    }

    PressedButtons++;
    QString Last = text.at(text.size() - 1);

    QString temp = text;
    if(Last != TextToInput.at(text.size() - 1)){
        temp.removeLast();

        if(temp.size() == 0){
            ui->lineInput->clear();
            return;
        }

        ui->lineInput->setText(temp);
    }
    else{
        if(temp.size() == TextToInput.size() - 2){
            Addtext();
        }

        CorrectButtons++;
    }
}


void MainWindow::on_Start_clicked()
{
    Timer->start(10);
}


void MainWindow::on_Stop_clicked()
{
    Timer->stop();
    IsActive = false;
}

