#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "Locals.h"
#include "QMessageBox"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->gridLayout->addWidget(keyboard, 7, 0, 7, 5);

    on_languageChangeComboBox_currentIndexChanged(Local::FRA);
    setFocus();

    ui->startButton->setStyleSheet("QPushButton {"
                                   "  background-color: #008631;"
                                   "}"
                                   "QPushButton:disabled {"
                                   "  background-color: #CCCCCC;"
                                   "  color: #666666;"
                                   "}");
    ui->openTestButton->setStyleSheet("QPushButton {"
                                      "  background-color: #008631;"
                                      "}"
                                      "QPushButton:disabled {"
                                      "  background-color: #CCCCCC;"
                                      "  color: #666666;"
                                      "}");
    ui->languageChangeComboBox->setStyleSheet("QComboBox {"
                                              "  background-color: #008631;"
                                              "}"
                                              "QComboBox:disabled {"
                                              "  background-color: #CCCCCC;"
                                              "  color: #666666;"
                                              "}");
    setButtons();

    buttonsMap = QMap<int, QPushButton*>{
        {49, ui->But_Tilda},
        {10, ui->But_1},
        {11, ui->But_2},
        {12, ui->But_3},
        {13, ui->But_4},
        {14, ui->But_5},
        {15, ui->But_6},
        {16, ui->But_7},
        {17, ui->But_8},
        {18, ui->But_9},
        {19, ui->But_0},
        {20, ui->But_Minus},
        {21, ui->But_Equals},
        {24, ui->But_Q},
        {25, ui->But_W},
        {26, ui->But_E},
        {27, ui->But_R},
        {28, ui->But_T},
        {29, ui->But_Y},
        {30, ui->But_U},
        {31, ui->But_I},
        {32, ui->But_O},
        {33, ui->But_P},
        {34, ui->But_leftSquare},
        {35, ui->But_RightSquare},
        {51, ui->But_BackSlash},
        {38, ui->But_A},
        {39, ui->But_S},
        {40, ui->But_D},
        {41, ui->But_F},
        {42, ui->But_G},
        {43, ui->But_H},
        {44, ui->But_J},
        {45, ui->But_K},
        {46, ui->But_L},
        {47, ui->But_TochkaZap},
        {48, ui->But_UpKov},
        {52, ui->But_Z},
        {53, ui->But_X},
        {54, ui->But_C},
        {55, ui->But_V},
        {56, ui->But_B},
        {57, ui->But_N},
        {58, ui->But_M},
        {59, ui->But_Zap},
        {60, ui->But_Dot},
        {61, ui->But_Slash},
        {100, ui->But_Space}
    };

    updateTimer->start(100);
    connect(updateTimer, &QTimer::timeout, this, &MainWindow::updateInfo);
    timer->start();


    //ui->testLabel->setFont(QFont("arial", 40));

    //this->setFixedSize(this->size());

    //setWindowTitle("Тренажёр");
}

MainWindow::~MainWindow()
{
    delete ui;
}


QString MainWindow::ButtonColors(int key){
    switch(key){
    case 49:
    case 10:
    case 24:
    case 38:
    case 52:
        return "background-color: green";
    default:
        return "";
    }
}
void MainWindow::keyPressEvent(QKeyEvent *event){
    if (!isTesting) return;
    keyPressEventTaked(event);
    if (codeSymbolNumber.contains(event->nativeScanCode()))
    {
        workWithEvent(event);
        return;
    }
    if (event->key() == Qt::Key_Space)
    {
        workWithEvent(event);
        return;
    }
    if (codeSymbolNumber.contains(event->text().toInt())) {
        QKeyEvent* newEvent = new QKeyEvent(QEvent::KeyPress, 0, Qt::KeyboardModifier::NoModifier, keys[currLocal][codeSymbolNumber[event->text().toInt()]]);
        workWithEvent(newEvent);
        delete newEvent;
    }

}

void MainWindow::on_languageChangeComboBox_currentIndexChanged(int index)
{
    setKeys(index);
    currTest = QStringList();
    ui->testLabel->setText("");
    currLocal = index;
    setFocus();
    setButtons();
}

void MainWindow::on_startButton_clicked()
{
    if(isTesting){
        isTesting = false;
        state = "Начать";
        setButtons();
        setFocus();
        ui->testLabel->setText("");
    }
    else{
        state = "Закончить";
        words = 0;
        rightSymbols = 0;
        allSymbols = 0;
        if (currTest.size() == 0)
        {
            QMessageBox::critical(0,tr("Ошибка"),tr("Выберите тест!"),QMessageBox::Ok|QMessageBox::NoButton);
            return;
        }
        isTesting = true;
        currNeededSimb = 0;
        currTestNum = 0;
        setText();
        setButtons();
        setFocus();
        timer->restart();
    }
    ui->startButton->setText(state);
}


void MainWindow::on_openTestButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открытие"), "//", tr("Текстовые документы (*.txt)"));
    QFile openedFile(fileName);
    QTextStream in(&openedFile);

    if (!openedFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    if (in.atEnd())
    {
        QMessageBox::critical(0,tr("Ошибка"),tr("Пустой файл!"),QMessageBox::Ok|QMessageBox::NoButton);
        return;
    }

    currTest;
    while (!in.atEnd())
        currTest.append(in.readLine());
    if (!checkTest())
    {
        QMessageBox::critical(0,tr("Ошибка"),tr("Недопустимые символы!"),QMessageBox::Ok|QMessageBox::NoButton);
        currTest = QStringList();
        return;
    }


    setButtons();


    setFocus();
}

bool MainWindow::checkTest()
{
    for (auto str : currTest)
    {
        if (str.size() > 30) return false;
        for (auto simb : str)
        {
            if (!allowedSimbols[currLocal].contains(QString(simb)) && simb != '\n')
                return false;
        }
    }
    return true;
}

void MainWindow::setButtons()
{
    if(currTest.size() == 0){
        ui->startButton->setDisabled(true);
    }
    else{
        ui->startButton->setDisabled(false);
    }
    //ui->startButton->setDisabled(currTest.size() == 0 || isTesting);
    //ui->stopButton->setEnabled(isTesting);
    ui->openTestButton->setDisabled(isTesting);
    ui->languageChangeComboBox->setDisabled(isTesting);
    setFocus();
}

void MainWindow::updateInfo()
{
    if (!isTesting) return;
    ui->progressBar->setValue(100. * rightSymbols / (allSymbols == 0 ? 1 : allSymbols));
    ui->label->setText(QString::number((float)timer->elapsed() / 1000));
    ui->label_2->setText(QString::number(1. * words * 60000 / timer->elapsed()));
}

void MainWindow::workWithEvent(QKeyEvent *event)
{
    QString a = keys[currLocal][codeSymbolNumber[event->nativeScanCode()]],
        b = QString(ui->testLabel->text()[currNeededSimb * 28 + 20]) ;
        //b = "j";
    QString oldText = ui->testLabel->text();
    QString eventText = event->text();
    qDebug() << oldText;
    QString frst;
    for(int i =0; i < currNeededSimb * 28; i++){
        frst += oldText[i];
    }
    QString lst;
    //for(int i = 0; i < (oldText.size() - currNeededSimb * 28 - 28); i++){
    //    lst[] += oldText[oldText.size() - 1 - i];
    //}
    int howMuch = oldText.size() - currNeededSimb * 28 - 28;
    for(int i = (oldText.size() - howMuch); i < oldText.size(); i++){
        lst += oldText[i];
    }
    qDebug() << "\n\n";
    qDebug() << lst;
    ui->testLabel->setText(
        //frst + " --" + oldText[currNeededSimb * 28 + 20] + "-- " + lst
        frst +
        "<font color=" +
        (event->text() == b || a == b ? "\"green\"" : "\"red  \"") +
        ">" + oldText[currNeededSimb * 28 + 20] + "</font>" +
        lst
    );//"<font color=\"black\">j</font>
    //oldText[currNeededSimb * 28 + 22]

    allSymbols++;
    if (event->text() == QString(ui->testLabel->text()[currNeededSimb * 28 + 20]) || a == b) rightSymbols++;

    words = 1. * rightSymbols / 5;

    currNeededSimb++;
    if (currNeededSimb == currTest[currTestNum].size())
    {
        currNeededSimb = 0;
        currTestNum++;
        if (currTestNum == currTest.size() - 1)
        {
            on_startButton_clicked();
            QMessageBox::information(0,tr("Успех"),tr("Тест пройден!"),QMessageBox::Ok|QMessageBox::NoButton);
            return;
        }
        setText();
    }
    setFocus();
}

void MainWindow::setText()
{
    QString text = "";
    for (auto simb : currTest[currTestNum])
    {
        text += "<font color=\"black\">" + QString(simb) + "</font>";
    }
    ui->testLabel->setText(text);
}

void MainWindow::keyPressEventTaked(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space) {
        QPushButton *button = buttonsMap[100];
        button->setStyleSheet("background-color: green");
        QTimer::singleShot(200, button, [button]() {
            button->setStyleSheet("");
        });
        setFocus();
        return;
    }
    int key = event->nativeScanCode();
    if (buttonsMap.contains(key)) {
        QPushButton *button = buttonsMap[key];
        button->setStyleSheet("background-color: green");
        QTimer::singleShot(200, button, [button]() {
            button->setStyleSheet("");
        });
        setFocus();
        return;
    }
    key = event->text().toInt();
    if (buttonsMap.contains(key)) {
        QPushButton *button = buttonsMap[key];
        button->setStyleSheet("background-color: green");
        QTimer::singleShot(200, button, [button]() {
            button->setStyleSheet("");
        });
    }
    setFocus();
}

void MainWindow::setKeys(int local)
{
    for (auto key : buttonsMap.keys()) buttonsMap[key]->setText(keys[local][codeSymbolNumber[key]]);
}

void MainWindow::handleButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());

    int buttonIndex = buttonsMap.key(button);

    QKeyEvent *keyEvent = new QKeyEvent(QEvent::KeyPress, 0, Qt::KeyboardModifier::NoModifier, QString::number(buttonIndex));

    QCoreApplication::postEvent(parentWidget(), keyEvent);
    setFocus();
}
