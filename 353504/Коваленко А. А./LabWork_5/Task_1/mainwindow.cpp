#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , keyboard(new Keyboard)
{
    ui->setupUi(this);

    ui->graphicsView->setScene(keyboard);
    ui->graphicsView->setSceneRect(0, 0, 1190, 390);

    cursor = ui->mainText->textCursor();
    cursor.setCharFormat(format);

    connect(&timer, &QTimer::timeout, this, &MainWindow::slotSecondsUpdate);

    currText
        = "Гэтую мову доўга ніхто не хацеў лічыць за сапраўдную, усе лічылі беларускую толькі дыялектам, але мы змаглі даказаць, што беларуская мова існуе. "
          "Тое, што было дасягнута такой працай, ні ў якім разе нельга забываць, мову трэба шанаваць і вывучаць, як мы зараз гэта робім у школах. "
          "Беларуская мова з'яўляецца доказам таго, што я - беларус. Дзякуючы беларускай мове я магу спакойна размаўляць з усімі людзьмі ў краіне, таму што кожны ведае дзяржаўную мову. "
          "Гэта развівае маю камунікабельнасць і аб'ядноўвае мяне з усімі людзьмі ў краіне. ";
    mask.fill('c', currText.size());
    printText();
    isProcess = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (!isProcess) {
        isProcess = true;
        timer.start(100);
        seconds = 0;
        words = 0;
        mistakes = 0;
        currIndex = 0;
    }

    QString keyText = e->text();
        if (e->key() == Qt::Key_Return || e->key() == Qt::Key_Enter) {
            keyText = "\n"; // Используем символ новой строки для Enter
        }

        keyboard->hightlight(keyText);
        qDebug() << keyText;

        if (!keyText.isEmpty() && keyText != '\b') {
            if (currIndex == currText.size()) {
                isProcess = false;
                timer.stop();
                mask.fill('c', currText.size());

                keyboard->antiHighlight();


            double accurancy = currText.size() >= mistakes
                                   ? (currText.size() - mistakes) * 100 / currText.size()
                                   : 0;
            QMessageBox::information(this,
                                     "Тренировка окончена",
                                     "Количесвто слов: " + QString::number(words)
                                         + "\nСредняя скорость: "
                                         + QString::number(60 * words / seconds)
                                         + " Слов в минуту\nАккуратность: "
                                         + QString::number(accurancy)
                                         + "%\nВремя: " + QString::number(seconds) + " c");

        } else if (e->text() == currText[currIndex]) {
            mask[currIndex] = 'g';
            currIndex++;
            if (e->text() == " ") {
                words++;
            }
        } else {
            mask[currIndex] = 'r';
            currIndex++;
            mistakes++;
        }
    } else if (e->key() == Qt::Key_Backspace) {
        if (currIndex != 0) {
            currIndex--;
            mask[currIndex] = 'c';
        }
    }
    printText();
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
    keyboard->antiHighlight();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    isProcess = false;
    timer.stop();
    mask.fill('c', currText.size());

    keyboard->initKeboard(index);
    if (index == bel) {
        currText
            = "Гэтую мову доўга ніхто не хацеў лічыць за сапраўдную, усе лічылі беларускую толькі дыялектам, але мы змаглі даказаць, што беларуская мова існуе. "
              "Тое, што было дасягнута такой працай, ні ў якім разе нельга забываць, мову трэба шанаваць і вывучаць, як мы зараз гэта робім у школах. "
              "Беларуская мова з'яўляецца доказам таго, што я - беларус. Дзякуючы беларускай мове я магу спакойна размаўляць з усімі людзьмі ў краіне, таму што кожны ведае дзяржаўную мову. "
              "Гэта развівае маю камунікабельнасць і аб'ядноўвае мяне з усімі людзьмі ў краіне. ";
    } else if (index == arab) {
        currText = "الجميع يعرف لغة الدولة. وهذا ينمي مهاراتي في التواصل ويوحدني مع جميع";
    } else if (index == ger) {
        currText = "Lange Zeit wollte niemand diese Sprache als eine echte Sprache betrachten, jeder hielt Weißrussisch nur für einen Dialekt, "
                   "aber wir konnten beweisen, dass die weißrussische Sprache existiert.";
    } else if (index == fre) {
        currText = "Pendant longtemps, personne n'a voulu considérer cette langue comme une langue réelle, "
                   "tout le monde considérait le biélorusse comme un simple dialecte, mais nous avons pu prouver que la langue biélorusse existe.";
    } else if (index == chin) {
        currText = "zui4 jia1 lv3 you2 mu4 de di4 zhong1 guo2 cheng2 wei2 ya4 zhou1 ";
    } else if (index == heb) {
        currText = "לא רצה להתייחס לשפה זו כשפה אמיתית, כולם ראו";
    } else if (index == ru) {
        currText = "Никто долгое время не хотел считать этот язык настоящим, все считали белорусский язык всего лишь диалектом, но мы смогли доказать, что белорусский язык существует. "
                   "Никогда не следует забывать то, что было достигнуто таким упорным трудом, язык следует ценить и изучать, как мы это делаем сейчас в школах. "
                   "Белорусский язык — доказательство того, что я белорус. Благодаря белорусскому языку я могу спокойно общаться со всеми жителями страны. ";
    }
    mask.fill('c', currText.size());
    printText();
}

void MainWindow::on_OpenButton_clicked()
{
    isProcess = false;
    timer.stop();
    mask.fill('c', currText.size());

    QString sourseFile = QFileDialog::getOpenFileName(nullptr, "Open Dialog", "", "*.txt");
    QFile file(sourseFile);
    if ((file.exists()) && (file.open(QIODevice::ReadOnly))) {
        currText = file.readAll();
        ui->mainText->setText(currText);
        mask.fill('c', currText.size());
        file.close();

    } else {
        QMessageBox::critical(this, "Ошибка!", "Файл не открыт или не существует!");
    }
}

void MainWindow::slotSecondsUpdate()
{
    seconds += 0.1;
    ui->TimerLabel->setText(QString::number(seconds));
    ui->WPMLabel->setText(QString::number(static_cast<int>(60 * words / seconds)));
    if (mistakes != 0) {
        double accurancy = currText.size() >= mistakes
                               ? (currText.size() - mistakes) * 100 / currText.size()
                               : 0;
        ui->accurancy->setText(QString::number(accurancy) + "%");
    } else {
        ui->accurancy->setText("100%");
    }
}

void MainWindow::printText()
{
    ui->mainText->clear();
    for (int i = 0; i < currText.size(); i++) {
        if (mask[i] == 'c') {
            format.setForeground(Qt::gray);
        } else if (mask[i] == 'r') {
            format.setForeground(Qt::darkRed);
        } else if (mask[i] == 'g') {
            format.setForeground(Qt::darkGreen);
        }
        cursor.setCharFormat(format);
        cursor.insertText(QString(currText[i]));
    }
}
