#pragma once
#include "level.h"
#include "ui_level.h"

Level::Level(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Level)
{
    ui->setupUi(this);
    ui->lineEdit->setGeometry(1500, 70, 142, 25);
    ui->lineEdit_2->setGeometry(1500, 120, 142, 25);
    setAutoFillBackground(true);
    ui->stackedWidget->setCurrentIndex(0);

    QFile file("../filword/Статистика.txt");
    file.open(QFile::ReadOnly);
    QTextStream inp(&file);
    inp >> player.money >> player.sumMoney >> player.solvedLevel >> player.sumHint
        >> player.sumTime;
    file.close();

    QFile file1("../filword/russian-nouns.txt");
    file1.open(QFile::ReadOnly);
    QTextStream in(&file1);
    int k = 0;
    wordsSize[2] = -1;
    while (!in.atEnd()) {
        in >> words[k];
        if (words[k].size() > 2) {
            allWords->addWord(words[k]);
        }
        if (words[k].size() > words[k - 1].size()) {
            wordsSize[words[k - 1].size()] = k - 1;
        }
        k++;
    }

    wordsSize[words[k - 1].size()] = k - 1;

    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->resize(1050, 1000);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    srand(time(0));

    ui->lineEdit->setText("00:00");
    ui->lineEdit_2->setText(QString::number(player.money) + " монет");
    levelTimer = new QTimer(this);
    connect(levelTimer, SIGNAL(timeout()), this, SLOT(Timer_slot()));
}

Level::~Level()
{
    delete ui;
}

void Level::updateStatistic()
{
    QFile file("../Документы/Статистика.txt");
    file.open(QFile::WriteOnly);
    QTextStream out(&file);
    out << player.money << "\n"
        << player.sumMoney << "\n"
        << player.solvedLevel << "\n"
        << player.sumHint << "\n"
        << player.sumTime;
    file.close();
}

void Level::Timer_slot()
{
    levelTime++;
    int min = levelTime / 60;
    QString strMin;
    if (min < 10) {
        strMin = "0" + QString::number(min);
    } else {
        strMin = QString::number(min);
    }
    int sec = levelTime % 60;
    QString strSec;
    if (sec < 10) {
        strSec = "0" + QString::number(sec);
    } else {
        strSec = QString::number(sec);
    }
    ui->lineEdit->setText(strMin + ":" + strSec);
}

void Level::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

bool Level::exist(int i, int j, int siz)
{
    if (i < 0 || i > siz - 1 || j < 0 || j > siz - 1) {
        return false;
    }
    return true;
}

void Level::generateLevel(int siz, int numWord)
{
    for (int i = 0; i < siz; i++) {
        for (int j = 0; j < siz; j++) {
            intLevel[i][j] = -1;
        }
    }
    cells.clear();
    for (int i = 0; i < numWord + 1; i++) {
        for (int j = 0; j < lengthWord[i]; j++) {
            wordCells[i][j] = {-1, -1};
        }
        lengthWord[i] = 0;
    }
    for (int i = 0; i < siz; i++) {
        for (int j = 0; j < siz; j++) {
            freedom[i][j] = true;
        }
    }

    int randStart = rand() % 4;
    switch (randStart) {
    case 0:
        corner = {1, 1};
        break;
    case 1:
        corner = {-1, 1};
        break;
    case 2:
        corner = {1, -1};
        break;
    case 3:
        corner = {-1, -1};
        break;
    }

    for (int i = 1; i < siz - 1; i++) {
        for (int j = 1; j < siz - 1; j++) {
            cells.insert({4, {i * corner.first, j * corner.second}});
            deadlockness[i][j] = 4;
        }
    }
    for (int i = 1; i < siz - 1; i++) {
        cells.insert({3, {i * corner.first, 0}});
        deadlockness[i][0] = 3;
        cells.insert({3, {i * corner.first, (siz - 1) * corner.second}});
        deadlockness[i][siz - 1] = 3;
        cells.insert({3, {0, i * corner.second}});
        deadlockness[0][i] = 3;
        cells.insert({3, {(siz - 1) * corner.first, i * corner.second}});
        deadlockness[siz - 1][i] = 3;
    }
    cells.insert({2, {0, 0}});
    deadlockness[0][0] = 2;
    cells.insert({2, {0, (siz - 1) * corner.second}});
    deadlockness[0][siz - 1] = 2;
    cells.insert({2, {(siz - 1) * corner.first, 0}});
    deadlockness[siz - 1][0] = 2;
    cells.insert({2, {(siz - 1) * corner.first, (siz - 1) * corner.second}});
    deadlockness[siz - 1][siz - 1] = 2;

    for (int i = 0; i < numWord; i++) {
        if (cells.empty()) {
            break;
        }

        std::pair<int, int> currCell = {(*cells.begin()).second.first * corner.first,
                                        (*cells.begin()).second.second * corner.second};

        freedom[currCell.first][currCell.second] = false;
        cells.erase({deadlockness[currCell.first][currCell.second],
                     {currCell.first * corner.first, currCell.second * corner.second}});

        for (int p = 0; p < 4; p++) {
            if (exist(currCell.first + deltaCell[p].first,
                      currCell.second + deltaCell[p].second,
                      siz)
                && freedom[currCell.first + deltaCell[p].first]
                          [currCell.second + deltaCell[p].second]) {
                cells.erase({deadlockness[currCell.first + deltaCell[p].first]
                                         [currCell.second + deltaCell[p].second],
                             {(currCell.first + deltaCell[p].first) * corner.first,
                              (currCell.second + deltaCell[p].second) * corner.second}});

                deadlockness[currCell.first + deltaCell[p].first]
                            [currCell.second + deltaCell[p].second]--;

                cells.insert({deadlockness[(currCell.first + deltaCell[p].first)]
                                          [(currCell.second + deltaCell[p].second)],
                              {(currCell.first + deltaCell[p].first) * corner.first,
                               (currCell.second + deltaCell[p].second) * corner.second}});
            }
        }
        wordCells[i][0] = {currCell.first, currCell.second};
        intLevel[currCell.first][currCell.second] = i;

        int deltaLengthWord = rand() % 5 - 2;
        lengthWord[i] = (cells.size() + 1) / (numWord - i) + deltaLengthWord;
        if (lengthWord[i] < 3) {
            lengthWord[i] = 3;
        }
        if (lengthWord[i] > 10) {
            lengthWord[i] = 10;
        }
        if (int(cells.size() + 1) - lengthWord[i] < 3) {
            if (cells.size() > 9) {
                lengthWord[i] = cells.size() - 2;
            } else {
                lengthWord[i] = cells.size() + 1;
                numWord = i + 1;
            }
        }
        for (int j = 1; j < lengthWord[i]; j++) {
            int mindeadlockness = 4;
            for (int p = 0; p < 4; p++) {
                if (exist(currCell.first + deltaCell[p].first,
                          currCell.second + deltaCell[p].second,
                          siz)
                    && deadlockness[currCell.first + deltaCell[p].first]
                                   [currCell.second + deltaCell[p].second]
                           < mindeadlockness
                    && freedom[currCell.first + deltaCell[p].first]
                              [currCell.second + deltaCell[p].second]) {
                    mindeadlockness = deadlockness[currCell.first + deltaCell[p].first]
                                                  [currCell.second + deltaCell[p].second];
                }
            }
            int numPossibleCells = 0;
            std::pair<int, int> possibleCells[5];
            for (int p = 0; p < 4; p++) {
                if (exist(currCell.first + deltaCell[p].first,
                          currCell.second + deltaCell[p].second,
                          siz)
                    && deadlockness[currCell.first + deltaCell[p].first]
                                   [currCell.second + deltaCell[p].second]
                           == mindeadlockness
                    && freedom[currCell.first + deltaCell[p].first]
                              [currCell.second + deltaCell[p].second]) {
                    possibleCells[numPossibleCells] = {currCell.first + deltaCell[p].first,
                                                       currCell.second + deltaCell[p].second};
                    numPossibleCells++;
                }
            }

            if (numPossibleCells == 0) {
                generateLevel(siz, numWord);
                return;
            }
            int indexNextCell = rand() % numPossibleCells;
            wordCells[i][j] = possibleCells[indexNextCell];
            currCell = wordCells[i][j];
            freedom[currCell.first][currCell.second] = false;
            intLevel[currCell.first][currCell.second] = i;
            cells.erase({deadlockness[currCell.first][currCell.second],
                         {currCell.first * corner.first, currCell.second * corner.second}});

            for (int p = 0; p < 4; p++) {
                if (exist(currCell.first + deltaCell[p].first,
                          currCell.second + deltaCell[p].second,
                          siz)
                    && freedom[currCell.first + deltaCell[p].first]
                              [currCell.second + deltaCell[p].second]) {
                    cells.erase({deadlockness[currCell.first + deltaCell[p].first]
                                             [currCell.second + deltaCell[p].second],
                                 {(currCell.first + deltaCell[p].first) * corner.first,
                                  (currCell.second + deltaCell[p].second) * corner.second}});
                    deadlockness[currCell.first + deltaCell[p].first]
                                [currCell.second + deltaCell[p].second]--;
                    cells.insert({deadlockness[(currCell.first + deltaCell[p].first)]
                                              [(currCell.second + deltaCell[p].second)],
                                  {(currCell.first + deltaCell[p].first) * corner.first,
                                   (currCell.second + deltaCell[p].second) * corner.second}});
                }
            }
        }
    }
    fillLevel(numWord);
}

void Level::fillLevel(int numWord)
{
    for (int i = 0; i < numWord; i++) {
        int indexWord = rand() % (wordsSize[lengthWord[i]] - wordsSize[lengthWord[i] - 1])
                        + wordsSize[lengthWord[i] - 1] + 1;
        QString currWord = words[indexWord];
        listWords.insert(currWord);
        sortWordLength.insert({-1 * lengthWord[i], i});
        //qDebug() << currWord;
        bool reverse = rand() % 2;
        if (!i) {
            if (corner == std::make_pair(1, 1)) {
                reverse = true;
            }
            if (corner == std::make_pair(-1, -1)) {
                reverse = false;
            }
        }
        if (reverse) {
            for (int j = 0; j < lengthWord[i] / 2; j++) {
                std::swap(wordCells[i][j], wordCells[i][lengthWord[i] - j - 1]);
            }
        }
        for (int j = 0; j < lengthWord[i]; j++) {
            std::pair<int, int> currCell = wordCells[i][j];
            charLevel[currCell.first][currCell.second] = currWord[j];
        }
    }
}

void Level::on_pushButton_2_clicked()
{
    ui->tableWidget->setRowCount(siz);
    ui->tableWidget->setColumnCount(siz);
    listWords.clear();
    sortWordLength.clear();
    for (int i = 0; i < 15; i++) {
        showLetters[i] = 0;
        lengthWord[i] = 0;
    }
    listFoundWords.clear();
    generateLevel(siz, numWord);
    int lettersiz = ui->tableWidget->columnWidth(0);
    for (int i = 0; i < siz; i++) {
        for (int j = 0; j < siz; j++) {
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(charLevel[i][j]));
            ui->tableWidget->item(i, j)->setTextAlignment(Qt::AlignCenter);
            QFont font = ui->tableWidget->item(i, j)->font();
            font.setPointSize(lettersiz * 0.5);
            ui->tableWidget->item(i, j)->setFont(font);
        }
    }
    ui->lineEdit->setText("00:00");
    hints = 0;
    levelTime = 0;
    levelTimer->start(1000);
    for (int i = 0; i < siz; i++) {
        for (int j = 0; j < siz; j++) {
            ui->tableWidget->item(i, j)->setBackground(QColor(255, 255, 255));
        }
    }
    if (otherLevelFlag) {
        bonusCell = {rand() % siz, rand() % siz};
        ui->tableWidget->item(bonusCell.first, bonusCell.second)->setBackground(Qt::yellow);
        bonusMoney = -10;
    } else {
        bonusCell = {-1, -1};
        bonusMoney = 0;
    }
}

void Level::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    mouseFlag = true;
    mousePos = ui->tableWidget->mapFromGlobal(QCursor::pos());
    mouseCell = {mousePos.y() / ui->tableWidget->columnWidth(0),
                 mousePos.x() / ui->tableWidget->columnWidth(0)};
    if (mousePos.y() >= 0 && mousePos.x() >= 0
        && ui->tableWidget->item(mouseCell.first, mouseCell.second)
        && (ui->tableWidget->item(mouseCell.first, mouseCell.second)->background().color()
                == QColor(255, 255, 255)
            || ui->tableWidget->item(mouseCell.first, mouseCell.second)->background().color()
                   == Qt::yellow)) {
        ui->tableWidget->item(mouseCell.first, mouseCell.second)
            ->setBackground(colors[listWords.size() - 1]);
        enterCells[numEnterCells] = mouseCell;
        numEnterCells++;
        enterWord += ui->tableWidget->item(mouseCell.first, mouseCell.second)->text();
    }
}

void Level::mouseMoveEvent(QMouseEvent *event)
{
    if (mouseFlag) {
        mousePos = ui->tableWidget->mapFromGlobal(QCursor::pos());
        mouseCell = {mousePos.y() / ui->tableWidget->columnWidth(0),
                     mousePos.x() / ui->tableWidget->columnWidth(0)};
        if (mousePos.y() >= 0 && mousePos.x() >= 0
            && ui->tableWidget->item(mouseCell.first, mouseCell.second)) {
            if (ui->tableWidget->item(mouseCell.first, mouseCell.second)->background().color()
                    != QColor(255, 255, 255)
                && ui->tableWidget->item(mouseCell.first, mouseCell.second)->background().color()
                       != Qt::yellow) {
                for (int i = numEnterCells - 1; i >= 0; i--) {
                    if (enterCells[i] == mouseCell) {
                        numEnterCells = i + 1;
                        break;
                    }
                    if (enterCells[i] == bonusCell) {
                        ui->tableWidget->item(enterCells[i].first, enterCells[i].second)
                            ->setBackground(Qt::yellow);
                    } else {
                        ui->tableWidget->item(enterCells[i].first, enterCells[i].second)
                            ->setBackground(QColor(255, 255, 255));
                    }
                    auto it = enterWord.end();
                    it--;
                    enterWord.erase(it);
                    numEnterCells = i;
                }
            } else {
                ui->tableWidget->item(mouseCell.first, mouseCell.second)
                    ->setBackground(colors[listWords.size() - 1]);
                enterCells[numEnterCells] = mouseCell;
                numEnterCells++;
                enterWord += ui->tableWidget->item(mouseCell.first, mouseCell.second)->text();
            }
        } else {
            mouseReleaseEvent(event);
        }
    }
}

void Level::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    bool wordFlag = true, bonusCellFlag = false;
    if (enterCells[0] == bonusCell) {
        bonusCellFlag = true;
    }
    int index = intLevel[enterCells[0].first][enterCells[0].second];
    for (int i = 1; i < numEnterCells; i++) {
        if (intLevel[enterCells[i].first][enterCells[i].second] != index) {
            wordFlag = false;
        }
        if (enterCells[i] == bonusCell) {
            bonusCellFlag = true;
        }
    }
    if (listWords.find(enterWord) != listWords.end()) {
        if (wordFlag && numEnterCells == lengthWord[index]) {
            listWords.erase(enterWord);
            sortWordLength.erase({-1 * lengthWord[index], index});
            if (bonusCellFlag) {
                bonusMoney += 5;
            }
            if (listWords.empty()) {
                levelTimer->stop();
                player.money += bonusMoney;
                ui->lineEdit_2->setText(QString::number(player.money) + " монет");
                player.sumMoney += bonusMoney;
                msgBox.setText("Уровень пройден!\nЗатраченное время: " + QString::number(levelTime)
                               + "\nЗаработанные монеты: " + QString::number(bonusMoney + 20));
                msgBox.exec();
                numEnterCells = 0;
                mouseFlag = false;
                enterWord = "";
                player.money += 20;
                ui->lineEdit_2->setText(QString::number(player.money) + " монет");
                player.sumMoney += 20;
                player.sumTime += levelTime;
                player.solvedLevel++;
                player.sumHint += hints;
                updateStatistic();
                on_pushButton_2_clicked();
            } else {
                for (int i = 0; i < numEnterCells; i++) {
                    ui->tableWidget->item(enterCells[i].first, enterCells[i].second)
                        ->setForeground(QBrush(Qt::black));
                }
                if (bonusCellFlag) {
                    do {
                        bonusCell = {rand() % siz, rand() % siz};
                    } while (
                        ui->tableWidget->item(bonusCell.first, bonusCell.second)->background().color()
                        != QColor(255, 255, 255));
                    ui->tableWidget->item(bonusCell.first, bonusCell.second)
                        ->setBackground(Qt::yellow);
                }
                /*msgBox.setText("NPC получает по ебалу");
                msgBox.exec();*/
            }
        } else {
            msgBox.setText("Попробуйте ввести это слово по-другому");
            msgBox.exec();
            for (int i = 0; i < numEnterCells; i++) {
                ui->tableWidget->item(enterCells[i].first, enterCells[i].second)
                    ->setBackground(QColor(255, 255, 255));
                if (enterCells[i] == bonusCell) {
                    ui->tableWidget->item(enterCells[i].first, enterCells[i].second)
                        ->setBackground(Qt::yellow);
                }
            }
        }
    } else {
        if (allWords->findWord(enterWord)) {
            if (listFoundWords.find(enterWord) == listFoundWords.end()) {
                listFoundWords.insert(enterWord);
                player.money += 10;
                ui->lineEdit_2->setText(QString::number(player.money) + " монет");
                player.sumMoney += 10;
                updateStatistic();
                msgBox.setText("Ура, Вы нашли дополнительное слово!");
                msgBox.exec();
            } else {
                msgBox.setText("Это слово уже было найдено");
                msgBox.exec();
            }
        }
        for (int i = 0; i < numEnterCells; i++) {
            ui->tableWidget->item(enterCells[i].first, enterCells[i].second)
                ->setBackground(QColor(255, 255, 255));
            if (enterCells[i] == bonusCell) {
                ui->tableWidget->item(enterCells[i].first, enterCells[i].second)
                    ->setBackground(Qt::yellow);
            }
        }
    }
    numEnterCells = 0;
    mouseFlag = false;
    enterWord = "";
}

void Level::on_pushButton_3_clicked()
{
    if (player.money >= 50) {
        int wordIndex = (*sortWordLength.begin()).second;
        if (showLetters[wordIndex] == lengthWord[wordIndex]) {
            sortWordLength.erase(sortWordLength.begin());
            if (sortWordLength.empty()) {
                msgBox.setText("Все буквы уже открыты");
                msgBox.exec();
                return;
            } else {
                showLetters[wordIndex]--;
                msgBox.setText("Слово уже открыто");
                msgBox.exec();
            }
        }
        hints++;
        ui->tableWidget
            ->item(wordCells[wordIndex][showLetters[wordIndex]].first,
                   wordCells[wordIndex][showLetters[wordIndex]].second)
            ->setForeground(QBrush(Qt::red));
        showLetters[wordIndex]++;
        player.money -= 50;
        updateStatistic();
        ui->lineEdit_2->setText(QString::number(player.money) + " монет");
    } else {
        msgBox.setText("Нужно больше золота");
        msgBox.exec();
    }
}

void Level::on_pushButton_4_clicked()
{
    if (player.money >= 50) {
        if (levelTime < 30) {
            levelTime = 0;
        } else {
            levelTime -= 30;
        }
        player.money -= 50;
        updateStatistic();
        ui->lineEdit_2->setText(QString::number(player.money) + " монет");
        int min = levelTime / 60;
        QString strMin;
        if (min < 10) {
            strMin = "0" + QString::number(min);
        } else {
            strMin = QString::number(min);
        }
        int sec = levelTime % 60;
        QString strSec;
        if (sec < 10) {
            strSec = "0" + QString::number(sec);
        } else {
            strSec = QString::number(sec);
        }
        ui->lineEdit->setText(strMin + ":" + strSec);
    } else {
        msgBox.setText("Нужно больше золота");
        msgBox.exec();
    }
}

void Level::on_pushButton_5_clicked()
{
    otherLevelFlag = false;
    ui->stackedWidget->setCurrentIndex(2);
}

void Level::on_pushButton_6_clicked()
{
    otherLevelFlag = true;
    ui->stackedWidget->setCurrentIndex(2);
}

void Level::on_pushButton_7_clicked()
{
    siz = 3;
    numWord = 3;
    on_pushButton_2_clicked();
    ui->stackedWidget->setCurrentIndex(3);
}

void Level::on_pushButton_8_clicked()
{
    siz = 4;
    numWord = 4;
    on_pushButton_2_clicked();
    ui->stackedWidget->setCurrentIndex(3);
}

void Level::on_pushButton_9_clicked()
{
    siz = 5;
    numWord = 6;
    on_pushButton_2_clicked();
    ui->stackedWidget->setCurrentIndex(3);
}

void Level::on_pushButton_11_clicked()
{
    siz = 6;
    numWord = 7;
    on_pushButton_2_clicked();
    ui->stackedWidget->setCurrentIndex(3);
}

void Level::on_pushButton_10_clicked()
{
    siz = 7;
    numWord = 9;
    on_pushButton_2_clicked();
    ui->stackedWidget->setCurrentIndex(3);
}

void Level::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Level::on_pushButton_13_clicked()
{
    MainWindow::close();
}

void Level::on_pushButton_14_clicked()
{
    ui->textBrowser->setText(
        "Количество монет: " + QString::number(player.money) + "\n"
        + "Сумма монет за все время: " + QString::number(player.sumMoney) + "\n"
        + "Количество решенных уровней: " + QString::number(player.solvedLevel) + "\n"
        + "Среднее количество использованных подсказок: "
        + QString::number(player.solvedLevel ? double(player.sumHint) / player.solvedLevel : 0)
        + "\n" + "Среднее время решения: "
        + QString::number(player.solvedLevel ? double(player.sumTime) / player.solvedLevel : 0)
        + "\n");
    ui->stackedWidget->setCurrentIndex(4);
    //qDebug() << player.money;
}

void Level::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
