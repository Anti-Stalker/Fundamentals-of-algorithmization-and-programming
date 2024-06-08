#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateLabels);
    startTime = 0;
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect(ui->endButton, &QPushButton::clicked, this, &MainWindow::stopTimer);
    currKeyboard = getGermanKeyboard();
    setNewKeyBoard();
    on_comboBox_currentIndexChanged(0);

    ui->label_accuracy->setAlignment(Qt::AlignCenter);
    ui->label_symbols->setAlignment(Qt::AlignCenter);
    ui->label_timer->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Keyboards
QVector<QVector<QString>> MainWindow::getGermanKeyboard()
{
    QVector<QVector<QString>> germanKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "ß", "´", "q", "w", "e", "r", "t", "z", "u", "i", "o", "p", "ü", "+", "a", "s", "d", "f", "g", "h", "j", "k", "l", "ö", "ä", "^", "shift", "#", "y", "x", "c", "v", "b", "n", "m", ",", ".", "-", "shift", "space", "caps"},
        {"!", "\"", "§", "$", "%", "&&", "/", "(", ")", "=", "?", "`", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{", "}", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", "°", "shift", "|", "Y", "X", "C", "V", "B", "N", "M", ";", ":", "_", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "ß", "´", "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "Ü", "+", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", "^", "shift", "#", "Y", "X", "C", "V", "B", "N", "M", ",", ".", "-", "shift", "space", "caps"},
        {"!", "\"", "§", "$", "%", "&&", "/", "(", ")", "=", "?", "`", "q", "w", "e", "r", "t", "z", "u", "i", "o", "p", "ü", "*", "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", "°", "shift", "|", "y", "x", "c", "v", "b", "n", "m", ";", ":", "_", "shift", "space", "caps"}};
    return germanKeyboard;
}

QVector<QVector<QString>> MainWindow::getFranchKeyboard()
{
    QVector<QVector<QString>> franchKeyboard = {
        {"&&", "é", "\"", "'", "(", "-", "è", "_", "ç", "à", ")", "=", "a", "z", "e", "r", "t", "y", "u", "i", "o", "p", "^", "$", "q", "s", "d", "f", "g", "h", "j", "k", "l", "m", "ù", "²", "shift", "*", "w", "x", "c", "v", "b", "n", ",", ";", ":", "!", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "°", "+", "A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P", "¨", "£", "Q", "S", "D", "F", "G", "H", "J", "K", "L", "M", "%", "~", "shift", "µ", "W", "X", "C", "V", "B", "N", "?", ".", "/", "§", "shift", "space", "caps"},
        {"&&", "É", "\"", "'", "(", "-", "È", "_", "Ç", "À", ")", "=", "A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P", "^", "$", "Q", "S", "D", "F", "G", "H", "J", "K", "L", "M", "Ù", "²", "shift", "*", "W", "X", "C", "V", "B", "N", ",", ";", ":", "!", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "°", "+", "a", "z", "e", "r", "t", "y", "u", "i", "o", "p", "¨", "£", "q", "s", "d", "f", "g", "h", "j", "k", "l", "m", "%", "~", "shift", "", "w", "x", "c", "v", "b", "n", "?", ".", "/", "§", "shift", "space", "caps"}};
    return franchKeyboard;
}

QVector<QVector<QString>> MainWindow::getArabicKeyboard()
{
    QVector<QVector<QString>> arabicKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "ض", "ص", "ث", "ق", "ف", "غ", "ع", "ه", "خ", "ح", "ج", "د", "ش", "س", "ي", "ب", "ل", "ا", "ت", "ن", "م", "ك", "ط", "ذ", "shift", "\\", "ئ", "ء", "ؤ", "ر", "ﻻ", "ى", "ة", "و", "ز", "ظ", "shift", "space", "caps"},
        {"!", "@", "#", "$", "%", "^", "&&", "*", ")", "(", "_", "+", "َّ", "ً", "ُ", "ٌ", "ﻹ", "إ", "`", "÷", "×", "؛", "<", ">", "ِ", "ٍ", "]", "[", "ﻷ", "أ", "ـ", "،", "/", ":", "\"", "ّ", "shift", "…", "~", "ْ", "}", "{", "ﻵ", "آ", "'", ",", ".", "؟", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "ض", "ص", "ث", "ق", "ف", "غ", "ع", "ه", "خ", "ح", "ج", "د", "ش", "س", "ي", "ب", "ل", "ا", "ت", "ن", "م", "ك", "ط", "ذ", "shift", "\\", "ئ", "ء", "ؤ", "ر", "ﻻ", "ى", "ة", "و", "ز", "ظ", "shift", "space", "caps"},
        {"!", "@", "#", "$", "%", "^", "&&", "*", ")", "(", "_", "+", "َ", "ً", "ُ", "ٌ", "ﻹ", "إ", "`", "÷", "×", "؛", "<", ">", "ِ", "ٍٍ", "]", "[", "ﻷ", "أ", "ـ", "،", "/", ":", "\"", "ّ", "shift", "…", "~", "ْ", "}", "{", "ﻵ", "آ", "'", ",", ".", "؟", "shift", "space", "caps"}};
    return arabicKeyboard;
}

QVector<QVector<QString>> MainWindow::getEnglishKeyboard()
{
    QVector<QVector<QString>> englishKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]", "a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "'", "`", "shift", "\\", "z", "x", "c", "v", "b", "n", "m", ",", ".", "/", "shift", "space", "caps"},
        {"!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "{", "}", "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"", "~", "shift", "|", "Z", "X", "C", "V", "B", "N", "M", "<", ">", "?", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "[", "]", "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", "`", "shift", "\\", "Z", "X", "C", "V", "B", "N", "M", ",", ".", "/", "shift", "space", "caps"},
        {"!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "{", "}", "a", "s", "d", "f", "g", "h", "j", "k", "l", ":", "\"", "~", "shift", "|", "z", "x", "c", "v", "b", "n", "m", "<", ">", "?", "shift", "space", "caps"}};
    return englishKeyboard;
}

QVector<QVector<QString>> MainWindow::getBelarussianKeyboard()
{
    QVector<QVector<QString>> belarussianKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "й", "ц", "у", "к", "е", "н", "г", "ш", "ў", "з", "х", "'", "ф", "ы", "в", "а", "п", "р", "о", "л", "д", "ж", "э", "ё", "shift", "\\", "я", "ч", "с", "м", "і", "т", "ь", "б", "ю", ".", "shift", "space", "caps"},
        {"!", "\"", "№", ";", "%", ":", "?", "*", "(", ")", "_", "+", "Й", "Ц", "У", "К", "Е", "Н", "Г", "Ш", "Ў", "З", "Х", "'", "Ф", "Ы", "В", "А", "П", "Р", "О", "Л", "Д", "Ж", "Э", "Ё", "shift", "/", "Я", "Ч", "С", "М", "І", "Т", "Ь", "Б", "Ю", ".", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "Й", "Ц", "У", "К", "Е", "Н", "Г", "Ш", "Ў", "З", "Х", "'", "Ф", "Ы", "В", "А", "П", "Р", "О", "Л", "Д", "Ж", "Э", "Ё", "shift", "\\", "Я", "Ч", "С", "М", "І", "Т", "Ь", "Б", "Ю", ".", "shift", "space", "caps"},
        {"!", "\"", "№", ";", "%", ":", "?", "*", "(", ")", "_", "+", "й", "ц", "у", "к", "е", "н", "г", "ш", "ў", "з", "х", "'", "ф", "ы", "в", "а", "п", "р", "о", "л", "д", "ж", "э", "ё", "shift", "/", "я", "ч", "с", "м", "і", "т", "ь", "б", "ю", ",", "shift", "space", "caps"}};
    return belarussianKeyboard;
}

QVector<QVector<QString>> MainWindow::getHerbewKeyboard()
{
    QVector<QVector<QString>> herbewKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "/", "'", "ק", "ר", "א", "ט", "ו", "ן", "ם", "פ", "]", "[", "ש", "ד", "ג", "כ", "ע", "י", "ח", "ל", "ך", "ף", ",", ";", "shift", "\\", "ז", "ס", "ב", "ה", "נ", "מ", "צ", "ת", "ץ", ".", "shift", "space", "caps"},
        {"!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "}", "{", "A", "S", "D", "F", "G", "H", "J", "K", "L", ":", "\"", "~", "shift", "|", "Z", "X", "C", "V", "B", "N", "M", ">", "<", "?", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "]", "[", "A", "S", "D", "F", "G", "H", "J", "K", "L", ";", "'", ";", "shift", "\\", "Z", "X", "C", "V", "B", "N", "M", ">", "<", ".", "shift", "space", "caps"},
        {"!", "@", "#", "$", "%", "^", "&&", "*", "(", ")", "_", "+", "/", "'", "ק", "ר", "א", "ט", "ו", "ן", "ם", "פ", "}", "{", "ש", "ד", "ג", "כ", "ע", "י", "ח", "ל", "ך", "ף", "\"", "~", "shift", "|", "ז", "ס", "ב", "ה", "נ", "מ", "צ", "ת", "ץ", "?", "shift", "space", "caps"}};
    return herbewKeyboard;
}

QVector<QVector<QString>> MainWindow::getChinaseKeyboard()
{
    QVector<QVector<QString>> chinaseKeyboard = {
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "【", "】", "a", "s", "d", "f", "g", "h", "j", "k", "l", "；", "‘", "`", "shift", "、", "z", "x", "c", "v", "b", "n", "m", "，", "。", "/", "shift", "space", "caps"},
        {"！", "@", "#", "￥", "%", "…", "&&", "*", "（", "）", "——", "+", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "『", "』", "A", "S", "D", "F", "G", "H", "J", "K", "L", "：", "“", "～", "shift", "|", "Z", "X", "C", "V", "B", "N", "M", "《", "》", "？", "shift", "space", "caps"},
        {"1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "【", "】", "A", "S", "D", "F", "G", "H", "J", "K", "L", "；", "’", "`", "shift", "、", "Z", "X", "C", "V", "B", "N", "M", "，", "。", "/", "shift", "space", "caps"},
        {"！", "@", "#", "￥", "%", "…", "&&", "*", "（", "）", "——", "+", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "『", "』", "a", "s", "d", "f", "g", "h", "j", "k", "l", "：", "”", "～", "shift", "|", "z", "x", "c", "v", "b", "n", "m", "《", "》", "？", "shift", "space", "caps"}};
    return chinaseKeyboard;
}

QVector<QPushButton *> MainWindow::getButtons()
{
    QVector<QPushButton *> buttons = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, ui->button_9,
                                      ui->button_10, ui->button_11, ui->button_12, ui->button_13, ui->button_14, ui->button_15, ui->button_16,
                                      ui->button_17, ui->button_18, ui->button_19, ui->button_20, ui->button_21, ui->button_22, nullptr,
                                      ui->button_24, ui->button_25, ui->button_26, ui->button_27, ui->button_28, ui->button_29, ui->button_30,
                                      ui->button_31, ui->button_32, ui->button_33, ui->button_34, ui->button_35, ui->button_36, nullptr,
                                      ui->button_38, ui->button_39, ui->button_40, ui->button_41, ui->button_42, ui->button_43, ui->button_44,
                                      ui->button_45, ui->button_46, ui->button_47, ui->button_48, ui->button_49, ui->button_50, ui->button_51,
                                      ui->button_52, ui->button_53, ui->button_54, ui->button_55, ui->button_56, ui->button_57, ui->button_58,
                                      ui->button_59, ui->button_60, ui->button_61, ui->button_62, nullptr, nullptr, ui->button_65, ui->button_66};
    return buttons;
}

void MainWindow::setNewKeyBoard()
{
    QVector<QPushButton *> currButtons = getButtons();
    int index;
    if (!isCaps && !isShift)
        index = 0;
    if (!isCaps && isShift)
        index = 1;
    if (isCaps && !isShift)
        index = 2;
    if (isCaps && isShift)
        index = 3;
    int j = 0;
    for (int i = 0; i < 66; ++i)
    {
        if (currButtons[i] != nullptr && currButtons[i] && (i != 9 - 1) && (i != 22 - 1) && (i != 36 - 1))
        {
            currButtons[i]->setText(currKeyboard[index][j]);
            j++;
        }
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    indexOfLanguage = index;
    if (index == 0)
    {
        currKeyboard = getGermanKeyboard();
        ui->training->setAlignment(Qt::AlignLeft);
        testString = "qwertzuiopü asdfghjklöä yxcvbnm ";
    }
    else if (index == 1)
    {
        currKeyboard = getFranchKeyboard();
        ui->training->setAlignment(Qt::AlignLeft);
        testString = "azertyuiop qsdfghjklmù wxcvbn ";
    }
    else if (index == 2)
    {
        currKeyboard = getArabicKeyboard();
        ui->training->setAlignment(Qt::AlignLeft);
        testString = "ضصثقفغعهخحجد شسيبلاتنمكط ئءؤرلاىةوزظ ";
    }
    else if (index == 3)
    {
        currKeyboard = getEnglishKeyboard();
        ui->training->setAlignment(Qt::AlignLeft);
        testString = "qwertyuiop asdfghjkl zxcvbnm ";
    }
    else if (index == 4)
    {
        currKeyboard = getBelarussianKeyboard();
        ui->training->setAlignment(Qt::AlignLeft);
        testString = "йцукенгшўзх фывапролджэ ячсмітьбю ";
    }
    else if (index == 5)
    {
        currKeyboard = getHerbewKeyboard();
        ui->training->setAlignment(Qt::AlignLeft);
        testString = "/'קראטוןםפ שדגכעיחלךף זסבהנמצתץ ";
    }
    else if (index == 6)
    {
        currKeyboard = getChinaseKeyboard();
        ui->training->setAlignment(Qt::AlignLeft);
        testString = "莫济里 ";
    }
    QString t = "";
    for (auto simb : testString)
    {
        t += "<font color=\"black\">" + QString(simb) + "</font>";
    }
    ui->training->setText(t);
    ui->label_accuracy->setText("100%");
    ui->label_symbols->setText("0");
    ui->label_timer->setText("00:00:00");
    setNewKeyBoard();
    on_endButton_clicked();
    setFocus();
}

void MainWindow::on_fileButton_clicked()
{
    ui->training->clear();
    on_endButton_clicked();
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open file"), "//", tr("Text documents (*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {   
        testString = "File selection error";
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    file.close();
    QString t = "";
    for (auto simb : text)
    {
        t += "<font color=\"black\">" + QString(simb) + "</font>";
    }
    ui->training->setText(t);
    testString = text;
    setFocus();
}

void MainWindow::on_startButton_clicked()
{
    oldStr = "";
    isActiveTrain = true;
    currIndOfText = 0;
    cntAllStmbol = 0;
    cntCorrectSymbol = 0;
    setFocus();
    QString t = "";
    for (auto simb : testString)
    {
        t += "<font color=\"black\">" + QString(simb) + "</font>";
    }
    ui->training->setText(t);
}

void MainWindow::on_endButton_clicked()
{
    isActiveTrain = false;
    timer->stop();
    setFocus();
}

void MainWindow::startTimer()
{
    if (testString != "")
    {
    startTime = QDateTime::currentMSecsSinceEpoch();
    ui->label_accuracy->setText("100%");
    ui->label_symbols->setText("0");
    ui->label_timer->setText("00:00:00");
    timer->start(100);
    }
}

void MainWindow::stopTimer()
{
    isActiveTrain = false;
    timer->stop();
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Training results");
    msgBox.setText("<html>"
                   "<b>Time: " + ui->label_timer->text() + "</b><br>"
                   "<b>Symbols per minute: " + ui->label_symbols->text() + "</b><br>"
                   "<b>Accuracy: " + ui->label_accuracy->text() + "</b><br>"
                   "</html>");
    msgBox.exec();
}

void MainWindow::updateLabels()
{
    qint64 currentTime = QDateTime::currentMSecsSinceEpoch();
    qint64 elapsedTime = currentTime - startTime;
    int milliseconds = elapsedTime;
    int minutes = (milliseconds / 1000) / 60;
    int seconds = (milliseconds / 1000) % 60;
    int ms = (milliseconds % 1000) / 10;
    ui->label_timer->setText(QString("%1:%2:%3").arg(minutes, 2, 10, QChar('0')).arg(seconds, 2, 10, QChar('0')).arg(ms, 2, 10, QChar('0')));

    int tenthsOfSeconds = static_cast<int>(elapsedTime / 100);
    int sym = cntCorrectSymbol * ((long double)600 / tenthsOfSeconds);
    if (sym < 0)
    {
        sym = 0;
    }
    ui->label_symbols->setText(QString::number(sym));

    int acc = 0;
    if (cntAllStmbol)
        acc = (long double)cntCorrectSymbol / cntAllStmbol * 100;
    ui->label_accuracy->setText(QString("%1%").arg(acc));
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QVector<QPushButton *> currButtons = getButtons();
    if (event->key() == Qt::Key_Backspace || event->key() == Qt::Key_Delete ||
        event->key() == Qt::Key_Left || event->key() == Qt::Key_Right ||
        event->key() == Qt::Key_Up || event->key() == Qt::Key_Down ||
        event->key() == Qt::Key_Tab || (event->nativeScanCode() == 36) /*event->key() == Qt::Key_Enter*/)
    {
        if (event->nativeScanCode() == 22)
        {
            if (currIndOfText > 0)
            {
                currIndOfText--;
            }
            else
            {
                currIndOfText = 0;
            }
            changeColorAtIndex(currIndOfText, "black");
        }
        QString backgroundColor = "red";
        QString textColor = "#000000";
        QString styleSheet = QString("QPushButton:disabled {border-radius: 20px; border: 2px solid black; background-color: %1; color: %2;}").arg(backgroundColor, textColor);
        currButtons[event->nativeScanCode() - 1]->setStyleSheet(styleSheet);
        setNewKeyBoard();
        return;
    }

    int code = event->nativeScanCode();
    if (code == -1)
    {
        return;
    }

    if (code == 66)
    {
        isCaps = !isCaps;
        QString backgroundColor = "red";
        QString borderColor = isCaps ? "red" : "black";
        QString textColor = "#000000";
        QString styleSheet = QString("QPushButton:disabled {border-radius: 20px; border: 2px solid %1; background-color: %2; color: %3;}").arg(borderColor, backgroundColor, textColor);
        currButtons[code - 1]->setStyleSheet(styleSheet);
        setNewKeyBoard();
    }

    if (code == 50 || code == 62 && code != 66)
    {
        QString backgroundColor = "blue";
        QString textColor = "#000000";
        QString styleSheet = QString("QPushButton:disabled {border-radius: 20px; border: 2px solid black; background-color: %1; color: %2;}").arg(backgroundColor, textColor);
        currButtons[49]->setStyleSheet(styleSheet);
        currButtons[61]->setStyleSheet(styleSheet);
        isShift = true;
        setNewKeyBoard();
    }

    if (code >= 1 && code < 66 && code != 62 && code != 50)
    {
        if (!isActiveTrain && testString != "" && event->nativeScanCode() != 64)
        {
            on_startButton_clicked();
            startTimer();
        }

        QPushButton *button = currButtons[code - 1];
        if (button != nullptr)
        {
            QString backgroundColor = "cyan";
            QString textColor = "#000000";
            QString styleSheet = QString("QPushButton:disabled {border-radius: 20px; border: 2px solid black; background-color: %1; color: %2;}").arg(backgroundColor, textColor);
            button->setStyleSheet(styleSheet);
            if (isActiveTrain && (currIndOfText < testString.size() - 1))
                checkIsCorrectSymbol(event->text());
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    int code = event->nativeScanCode();
    QVector<QPushButton *> currButtons = getButtons();
    if (code < 67 && currButtons[code - 1] != nullptr && currButtons[code - 1])
    {
        if (code != 66)
        {
            if (code == 50 || code == 62)
            {
                QString styleSheet = "QPushButton:disabled {border-radius: 20px; border: 2px solid black; background-color: #f0f0f0; color: #000000;}";
                currButtons[49]->setStyleSheet(styleSheet);
                currButtons[61]->setStyleSheet(styleSheet);
                isShift = false;
                setNewKeyBoard();
            }
            else
            {
                QString styleSheet = "QPushButton:disabled {border-radius: 20px; border: 2px solid black; background-color: #f0f0f0; color: #000000;}";
                currButtons[code - 1]->setStyleSheet(styleSheet);
            }
        }
        else
        {
            QString styleSheet = QString("QPushButton:disabled {border-radius: 20px; border: 2px solid %1; background-color: #f0f0f0; color: #000000;}").arg(isCaps ? "red" : "black");
            currButtons[code - 1]->setStyleSheet(styleSheet);
        }
    }
    if (isActiveTrain && (currIndOfText >= testString.size() - 1))
    {
        on_endButton_clicked();
        testString = "";
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Training results");
        msgBox.setText("<html>"
                       "<b>Time: " + ui->label_timer->text() + "</b><br>"
                       "<b>Symbols per minute: " + ui->label_symbols->text() + "</b><br>"
                       "<b>Accuracy: " + ui->label_accuracy->text() + "</b><br>"
                       "</html>");
        msgBox.exec();
    }
}

void MainWindow::changeColorAtIndex(int index, const QString &color)
{
    oldStr = ui->training->text();
    ui->training->setText(oldStr.first(index * 28) + "<font color=" + "\"" + color + "\"" + ">" + oldStr[index * 28 + 20] + "</font>" +
                          oldStr.last(oldStr.size() - index * 28 - 28));
}

void MainWindow::checkIsCorrectSymbol(QString ch)
{
    if (currIndOfText >= 30)
    {
        QString subStr = testString.mid(30, testString.size() - 30);
        testString = subStr;
        currIndOfText -= 30;
        QString t = "";
        for (auto simb : testString)
        {
            t += "<font color=\"black\">" + QString(simb) + "</font>";
        }
        ui->training->setText(t);
    }
    if (testString[currIndOfText] == ch)
    {
        cntCorrectSymbol++;
        changeColorAtIndex(currIndOfText, "green");
    }
    else
    {
        changeColorAtIndex(currIndOfText, "red  ");
    }
    cntAllStmbol++;
    currIndOfText++;
}