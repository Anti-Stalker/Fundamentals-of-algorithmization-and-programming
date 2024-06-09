#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &MainWindow::timerTick);
    connect(ui->lineEdit_input, &InputManager::keyPressed, this, &MainWindow::buttonPressed);
    connect(ui->lineEdit_input, &InputManager::keyReleased, this, &MainWindow::buttonReleased);
    initKeyboard();
    setKeyboard(0);
    textManager = new TextManager(&dictionary, &trainingText, ui);
    textManager->SetDictionary(0);
    on_pushButton_reset_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_start_clicked()
{
    timer->start(1000);
    ui->lineEdit_input->setReadOnly(false);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_stop_clicked()
{
    timer->stop();
    ui->textEdit_input->setText("");
    ui->lineEdit_input->setText("");
    ui->label_elapsed_value->setText("00:00");
    ui->lineEdit_input->setReadOnly(true);
    words = 0;
    symbols = 0;
    correctSymbols = 0;
    seconds = 0;
    ui->stackedWidget->setCurrentIndex(0);
    on_pushButton_reset_clicked();
}

void MainWindow::on_pushButton_load_clicked()
{
    on_pushButton_stop_clicked();
    textManager->LoadTest();
}

void MainWindow::on_pushButton_reset_clicked()
{
    textManager->Generate();
    ui->pushButton_start->setEnabled(true);
}

void MainWindow::timerTick()
{
    ++seconds;
    ui->label_elapsed_value->setText((seconds / 60 > 9 ? QString::number(seconds / 60) : "0" + QString::number((seconds / 60))) + ":"
                                     + (seconds % 60 > 9 ? QString::number(seconds % 60) : "0" + QString::number((seconds % 60))));
    ui->label_wpm_value->setText(QString::number((60. * words) / (seconds + 1)));
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    locale = index;
    textManager->SetDictionary(locale);
    setKeyboard(locale);
    on_pushButton_reset_clicked();
}

void MainWindow::on_spinBox_valueChanged(int)
{
    on_pushButton_reset_clicked();
}

void MainWindow::buttonPressed(int code, bool sp)
{
    if (sp && ui->lineEdit_input && !ui->lineEdit_input->text().isEmpty())
    {
        QString str(ui->lineEdit_input->text().back());
        QString key;
        if (str != " ")
        {
            for (int j = 0; j < 66 && key.isEmpty(); ++j)
            {
                if(keys[j] != nullptr && keys[j])
                {
                    if (str == keyboard[locale][j + 1])
                    {
                        code = j + 1;
                    }
                }
            }
            if (locale == 2 || (code != -1 && keys[code - 1]->text() != str))
            {
                code = -1;
            }
        }
        if (ui->textEdit_input->toPlainText().endsWith(' '))
        {
            ++words;
        }
        if (ui->lineEdit_input->text().size() != 0 && ui->lineEdit_input->text().back() == ui->lineEdit_train->text().front())
        {
            if (str == " ")
            {
                ui->textEdit_input->insertHtml("<span style='background-color: rgba(0, 128, 0, 0.1);'>&nbsp;</span>");
            }
            else
            {
                ui->textEdit_input->insertHtml("<font color='green'>" + str + "</font>");
            }
            ++correctSymbols;

            QString nextText = ui->lineEdit_train->text();
            nextText.remove(0, 1);
            ui->lineEdit_train->setText(nextText);
            textManager->AddTextToNext();

            ++symbols;
            ui->label_accuracy_value->setText(QString::number(100. * correctSymbols / symbols) + " %");

            if(ui->lineEdit_train->text() == "")
            {
                timer->stop();
                QMessageBox::information(nullptr, "Information", "Training completed!\n\nAccuracy: " + ui->label_accuracy_value->text() + "\nWords per minute: " + ui->label_wpm_value->text() + "\nElapsed time: " + ui->label_elapsed_value->text());
                on_pushButton_stop_clicked();
            }
        }
        else
        {
            if (str == " ")
            {
                ui->textEdit_input->insertHtml("<span style='background-color: rgba(128, 0, 0, 0.1);'>&nbsp;</span>");
            }
            else
            {
                ui->textEdit_input->insertHtml("<font color='red'>" + str + "</font>");
            }
            ++symbols;
            ui->label_accuracy_value->setText(QString::number(100. * correctSymbols / symbols) + " %");
        }
    }
    if (code == -1)
    {
        return;
    }
    if(code < 67 && keys[code - 1] != nullptr && keys[code - 1])
    {
        if (code == 66)
        {
            keys[code - 1]->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
        }
        else if (code == 50 || code == 62)
        {
            keys[50 - 1]->setStyleSheet("QPushButton:disabled {background-color: green;color: #000000;}");
            keys[62 - 1]->setStyleSheet("QPushButton:disabled {background-color: green;color: #000000;}");
        }
        else
        {
            keys[code - 1]->setStyleSheet("QPushButton:disabled {background-color: green;color: #000000;}");
        }
    }
    if(ui->lineEdit_train->text() == "" || ui->lineEdit_input->isReadOnly())
    {
        buttonReleased(code);
    }
}

void MainWindow::buttonReleased(int code)
{
    if(code < 67 && keys[code - 1] != nullptr && keys[code - 1])
    {
        if (code != 66)
        {
            if (code == 50 || code == 62)
            {
                keys[50 - 1]->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
                keys[62 - 1]->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
            }
            else
            {
                keys[code - 1]->setStyleSheet("QPushButton:disabled {background-color: #f0f0f0;color: #000000;}");
            }
        }
    }
}

void MainWindow::setKeyboard(int index)
{
    for (int  i = 0; i < 66; ++i)
    {
        if(keys[i] != nullptr && keys[i])
        {
            keys[i]->setText(keyboard[index][i + 1]);
        }
    }
}

void MainWindow::initKeyboard()
{
    keys = {
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        ui->pushButton_10,
        ui->pushButton_11,
        ui->pushButton_12,
        ui->pushButton_13,
        ui->pushButton_14,
        ui->pushButton_15,
        ui->pushButton_16,
        ui->pushButton_17,
        ui->pushButton_18,
        ui->pushButton_19,
        ui->pushButton_20,
        ui->pushButton_21,
        nullptr,
        nullptr,
        ui->pushButton_24,
        ui->pushButton_25,
        ui->pushButton_26,
        ui->pushButton_27,
        ui->pushButton_28,
        ui->pushButton_29,
        ui->pushButton_30,
        ui->pushButton_31,
        ui->pushButton_32,
        ui->pushButton_33,
        ui->pushButton_34,
        ui->pushButton_35,
        nullptr,
        nullptr,
        ui->pushButton_38,
        ui->pushButton_39,
        ui->pushButton_40,
        ui->pushButton_41,
        ui->pushButton_42,
        ui->pushButton_43,
        ui->pushButton_44,
        ui->pushButton_45,
        ui->pushButton_46,
        ui->pushButton_47,
        ui->pushButton_48,
        ui->pushButton_49,
        ui->pushButton_50,
        ui->pushButton_51,
        ui->pushButton_52,
        ui->pushButton_53,
        ui->pushButton_54,
        ui->pushButton_55,
        ui->pushButton_56,
        ui->pushButton_57,
        ui->pushButton_58,
        ui->pushButton_59,
        ui->pushButton_60,
        ui->pushButton_61,
        ui->pushButton_62,
        nullptr,
        nullptr,
        ui->pushButton_65,
        ui->pushButton_66
    };

    keyboard.resize(7);

    QString str = R"TOKEN(1 2 3 4 5 6 7 8 9 0 - = ض ص ث ق ف غ ع ه خ ح ج د ش س ي ب ل ا ت ن م ك ط ذ \ ئ ء ؤ ر لا ى ة و ز ظ
1 2 3 4 5 6 7 8 9 0 - = й ц у к е н г ш ў з х ' ф ы в а п р о л д ж э ё \ я ч с м і т ь б ю .
1 2 3 4 5 6 7 8 9 0 - = q w e r t y u i o p [ ] a s d f g h j k l ; ' ` \ z x c v b n m , . /
1 2 3 4 5 6 7 8 9 0 - = q w e r t y u i o p [ ] a s d f g h j k l ; ' ` \ z x c v b n m , . /
! é " ' ( - è _ ç à ) = a z e r t y u i o p ^ $ q s d f g h j k l m ù ² * w x c v b n , ; : !
1 2 3 4 5 6 7 8 9 0 ß ´ q w e r t z u i o p ü + a s d f g h j k l ö ä ^ # y x c v b n m , . -
1 2 3 4 5 6 7 8 9 0 - = / ' ק ר א ט ו ן ם פ ] [ ש ד ג כ ע י ח ל ך ף , ; \ ז ס ב ה נ מ צ ת ץ .)TOKEN";

    QStringList langs = str.split("\n");
    for(int i = 0; i < langs.count(); ++i)
    {
        if (langs[i].isEmpty())
        {
            break;
        }
        QStringList keys = langs[i].split(" ");

        int k = 10;
        int n = 0;
        while(k < 62)
        {
            if (k == 22 || k == 36)
            {
                k += 2;
                continue;
            }
            if (k == 50)
            {
                ++k;
                continue;
            }
            keyboard[i][k] = keys[n];
            ++k;
            ++n;
        }
        keyboard[i][66] = "caps";
        keyboard[i][65] = "space";
        keyboard[i][50] = "shift";
        keyboard[i][62] = "shift";
    }
}
