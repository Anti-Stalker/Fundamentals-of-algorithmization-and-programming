#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentWidget(ui->startMenu);
    ui->profileStackedWidget->setCurrentWidget(ui->selectPLayer);
    ui->playersProfiles_stacked->setCurrentWidget(ui->profiles_SelectPlayer);

    ui->tableWidget_2->verticalHeader()->hide();
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->profilesTable->verticalHeader()->hide();
    ui->profilesTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->profilesTable->setSelectionMode(QAbstractItemView::SingleSelection);

    readFromFile();


    // гифки

    QMovie *lina = new QMovie("../../Resources/images/Heroes/Lina/Lina.gif");
    ui->LinaGif->setScaledContents(true);
    ui->LinaGif->setMovie(lina);
    lina->start();

    QMovie *phoenix = new QMovie("../../Resources/images/Heroes/Phoenix/Phoenix.gif");
    ui->PhoenixGif->setScaledContents(true);
    ui->PhoenixGif->setMovie(phoenix);
    phoenix->start();

    QMovie *venomancer = new QMovie("../../Resources/images/Heroes/Venomancer/Venomancer.gif");
    ui->VenomancerGif->setScaledContents(true);
    ui->VenomancerGif->setMovie(venomancer);
    venomancer->start();

    QMovie *drowRanger = new QMovie("../../Resources/images/Heroes/DrowRanger/DrowRanger.gif");
    ui->DrowRangerGif->setScaledContents(true);
    ui->DrowRangerGif->setMovie(drowRanger);
    drowRanger->start();

    QMovie *dragonKnight = new QMovie("../../Resources/images/Heroes/DragonKnight/DragonKnight.gif");
    ui->DragonKnightGif->setScaledContents(true);
    ui->DragonKnightGif->setMovie(dragonKnight);
    dragonKnight->start();


    movie = new QMovie("../../Resources/images/wallpaper.gif");
    processLabel = new QLabel(this);
    processLabel->setMovie(movie);
    movie->start();

    processLabel->setGeometry(0, 0, this->width(), this->height());
    processLabel->setScaledContents(true);

    this->setCentralWidget(ui->stackedWidget); // чтобы stackedWidget был наверху

    ui->LinaChoosed->hide();
    ui->PhoenixChoosed->hide();
    ui->VenomancerChoosed->hide();
    ui->DRChoosed->hide();
    ui->DKChoosed->hide();

    QGraphicsDropShadowEffect *effect1 = new QGraphicsDropShadowEffect;
    effect1->setBlurRadius(50);
    effect1->setXOffset(5);
    effect1->setYOffset(5);
    effect1->setColor(QColor(0, 0, 0, 255));

    QGraphicsDropShadowEffect *effect2 = new QGraphicsDropShadowEffect;
    effect2->setBlurRadius(50);
    effect2->setXOffset(5);
    effect2->setYOffset(5);
    effect2->setColor(QColor(0, 0, 0, 255));

    QGraphicsDropShadowEffect *effect3 = new QGraphicsDropShadowEffect;
    effect3->setBlurRadius(50);
    effect3->setXOffset(5);
    effect3->setYOffset(5);
    effect3->setColor(QColor(0, 0, 0, 255));

    QGraphicsDropShadowEffect *effect4 = new QGraphicsDropShadowEffect;
    effect4->setBlurRadius(50);
    effect4->setXOffset(5);
    effect4->setYOffset(5);
    effect4->setColor(QColor(0, 0, 0, 255));

    QGraphicsDropShadowEffect *effect5 = new QGraphicsDropShadowEffect;
    effect5->setBlurRadius(50);
    effect5->setXOffset(5);
    effect5->setYOffset(5);
    effect5->setColor(QColor(0, 0, 0, 255));

    ui->LinaChoosed->setGraphicsEffect(effect1);
    ui->PhoenixChoosed->setGraphicsEffect(effect2);
    ui->VenomancerChoosed->setGraphicsEffect(effect3);
    ui->DRChoosed->setGraphicsEffect(effect4);
    ui->DKChoosed->setGraphicsEffect(effect5);

    ui->player2_heroGif->setScaledContents(true);
    ui->player2Gif->setScaledContents(true);
    ui->player1_heroGif->setScaledContents(true);
    ui->player1Gif->setScaledContents(true);

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &MainWindow::countdown);

    items.push_back({"Healing salve", QPixmap("../../Resources/images/Items/Healing_salve.jpg"), 100, "Восстанавливает здоровье на 100"});
    items.push_back({"Enchanted mango", QPixmap("../../Resources/images/Items/Enchanted_mango.png"), 100, "Восстанавливает ману на 100"});
    items.push_back({"Bracer", QPixmap("../../Resources/images/Items/Bracer.jpg"), 250, "Увеличивает максимальное здоровье на 75 и восстанавливает его"});
    items.push_back({"Null talisman", QPixmap("../../Resources/images/Items/Null_talisman.jpg"), 250, "Увеличивает максимальное количество маны на 75 и восстанавливает её"});
    items.push_back({"Diffusal blade", QPixmap("../../Resources/images/Items/Diffusal_blade.jpg"), 450, "Сжигает 100 маны у противника"});
    items.push_back({"Dagon", QPixmap("../../Resources/images/Items/Dagon.jpg"), 500, "Наносит противнику 100 урона"});
    items.push_back({"Aether lense", QPixmap("../../Resources/images/Items/Aether_lens.png"), 800, "Увеличивает максимальное количество маны на 250 и восстанавливает её"});
    items.push_back({"Heart of tarrasque", QPixmap("../../Resources/images/Items/Heart_of_tarrasque.jpg"), 800, "Увеличивает максимальное здоровье на 250 и восстанавливает его"});
    items.push_back({"Linkens sphere", QPixmap("../../Resources/images/Items/Linkens_sphere.jpg"), 900, "Следующее заклинание противника не наносит вам урон"});
    items.push_back({"Kaya", QPixmap("../../Resources/images/Items/Kaya.jpg"), 400, "Увеличивает урон от способностей на 15%"});
    items.push_back({"Manta style", QPixmap("../../Resources/images/Items/Manta_style.jpg"), 500, "Развеивает все отрицательные эффекты"});

    ui->item1sold->hide();
    ui->item2sold->hide();
    ui->item3sold->hide();

    ui->profilesTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->profilesTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    ui->tableWidget_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget_2->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// СТОРОННИЕ ФУНКЦИИ

void MainWindow::readFromFile() { // чтение информации с файла db.txt
    QFile file("../../db/PlayersDataBase.txt");

    int n = ui->tableWidget_2->rowCount();

    if (playersCount) {
        for (int i = 0; i < n; i++) {
            ui->tableWidget_2->removeRow(0);
            ui->profilesTable->removeRow(0);
        }
        playersCount = 0;
        players.clear();
    }



    if (!file.open(QIODevice::ReadOnly)) {
        return;
    } else {

    }


    QTextStream in(&file);
    while (!in.atEnd()) {

        QString line = in.readLine();

        if (line.isEmpty()) {
            continue;
        }

        QString name = "";
        QString gamePlayed = "";
        QString winGames = "";

        int i = 0;


        while (line[i] != ';') {
            name += line[i];
            i++;
        }

        i++;

        while (line[i] != ';') {
            gamePlayed += line[i];
            i++;
        }

        i++;

        while (line[i] != ';') {
            winGames += line[i];
            i++;
        }

        i++;


        players.push_back(new Player(name, gamePlayed.toInt(), winGames.toInt()));

        ui->tableWidget_2->insertRow(playersCount);
        ui->profilesTable->insertRow(playersCount);

        QTableWidgetItem *col1Item1 = new QTableWidgetItem(players[playersCount]->getName());
        ui->tableWidget_2->setItem(playersCount,0,col1Item1);

        QTableWidgetItem *col1Item2 = new QTableWidgetItem(players[playersCount]->getName());
        ui->profilesTable->setItem(playersCount,0,col1Item2);

        QTableWidgetItem *col2Item1 = new QTableWidgetItem(QString::number(players[playersCount]->getGamePlayed()));
        ui->tableWidget_2->setItem(playersCount,1,col2Item1);

        QTableWidgetItem *col2Item2 = new QTableWidgetItem(QString::number(players[playersCount]->getGamePlayed()));
        ui->profilesTable->setItem(playersCount,1,col2Item2);

        QTableWidgetItem *col3Item1 = new QTableWidgetItem(players[playersCount]->winRate());
        ui->tableWidget_2->setItem(playersCount,2,col3Item1);

        QTableWidgetItem *col3Item2 = new QTableWidgetItem(players[playersCount]->winRate());
        ui->profilesTable->setItem(playersCount,2,col3Item2);

        playersCount++;

        ui->profilesStatus->hide();
        ui->profilesStatus_2->hide();
    }
}

bool MainWindow::isPlayerExist(QString name) { // проверка на то, есть ли игрок в базе данных
    for (int i = 0; i < playersCount; i++) {
        if (players[i]->getName() == name) {
            return true;
        }
    }

    return false;
}

bool MainWindow::isPlayerNameCorrect(QString name) { // проверка на коррекность никнейма
    bool isSpace = true;

    for (int i = 0; i < name.length(); i++) {
        if (name[i] != ' ') {
            isSpace = false;
        }
    }

    if (isSpace || name.isEmpty()) {
        QMessageBox::critical(0, "Ошибка добавления профиля", "Имя не может быть пустым или содержать только пробелы");
        return false;
    }

    if (name[0] == ' ') {
        QMessageBox::critical(0, "Ошибка добавления профиля", "Имя не может начинаться с пробела");
        return false;
    }

    QRegularExpression regex("^[\\p{L}0-9 ]+$");
    if(!regex.match(name).hasMatch()) {
        QMessageBox::critical(0, "Ошибка добавления профиля", "Имя должно содержать только буквы, цифры и пробелы");
        return false;
    }

    return true;
}

void MainWindow::rewriteFile() { // перезапись файла
    QFile file("../../db/PlayersDataBase.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }

    QTextStream out(&file);

    for (int i = 0; i < players.size(); i++) {
        out << players[i]->getName() << ";" << players[i]->getGamePlayed() << ";" << players[i]->getWinGames() << ";\n";
    }
}

// ГЛАВНОЕ МЕНЮ

void MainWindow::on_pushButton_11_clicked() // начать игру
{
    ui->playerChoosin_label->setText("Игрок #1 выбирает профиль игрока");
    ui->stackedWidget->setCurrentWidget(ui->playersScreen);
}

void MainWindow::on_playersProfiles_button_clicked() // посмотреть профиля игроков
{
    ui->stackedWidget->setCurrentWidget(ui->playersProfiles);
}

void MainWindow::on_pushButton_12_clicked() // выйти из игры
{
    QApplication::quit();
}

// ВКЛАДКА ВЫБОРА ПЕРСОНАЖА

void MainWindow::on_pushButton_clicked() // выход в главное меню
{
    ui->stackedWidget->setCurrentWidget(ui->startMenu);

    ui->lineEdit->clear();

    int rowCount = ui->tableWidget_2->rowCount();
    int columnCount = ui->tableWidget_2->columnCount();

    for (int row = 0; row < rowCount; ++row)
    {
        for (int column = 0; column < columnCount; ++column)
        {
            QTableWidgetItem* item = ui->tableWidget_2->item(row, column);

            if (item != nullptr)
            {
                item->setFlags(item->flags() | Qt::ItemIsEnabled);
                item->setForeground(Qt::black);
            }
        }
    }

    selectedProfilesForGame.clear();
    currentPlayers.clear();
    currentChoosing = 0;
}

void MainWindow::on_pushButton_4_clicked() // переход на вкладку добавления игрока
{
    ui->lineEdit->clear();
    ui->profileStackedWidget->setCurrentWidget(ui->addPLayer);
    ui->playerChoosin_label->hide();

}

    // ВКЛАДКА ВЫБОРА ПЕРСОНАЖА -> ВКЛАДКА ДОБАВЛЕНИЯ ИГРОКА
void MainWindow::on_addPlayer_cancel_clicked() // отмена +  переход на вкладку выбора профиля
{
    ui->profileStackedWidget->setCurrentWidget(ui->selectPLayer);
    ui->lineEdit->clear();
    ui->label_3->show();

}


void MainWindow::on_pushButton_2_clicked() //добавление игрока + переход на вкладку выбора игрока
{
    QString name = ui->lineEdit->text();

    if (isPlayerExist(name)) {
        QMessageBox::critical(0, "Ошибка добавления профиля", "Профиль с таким же именем уже существует!\nВыберите другое имя");
        return;
    }

    if(isPlayerNameCorrect(name)) {

        ui->profileStackedWidget->setCurrentWidget(ui->selectPLayer); // переход на вкладку с выбором персонажа
        ui->playerChoosin_label->show();

        ui->tableWidget_2->insertRow(playersCount);
        ui->profilesTable->insertRow(playersCount);

        players.push_back(new Player(name, 0, 0));


        QTableWidgetItem *col1Item1 = new QTableWidgetItem(name);
        ui->tableWidget_2->setItem(playersCount,0,col1Item1);

        QTableWidgetItem *col1Item2 = new QTableWidgetItem(name);
        ui->profilesTable->setItem(playersCount,0,col1Item2);

        QTableWidgetItem *col2Item1 = new QTableWidgetItem(QString::number(players[playersCount]->getGamePlayed()));
        ui->tableWidget_2->setItem(playersCount,1,col2Item1);

        QTableWidgetItem *col2Item2 = new QTableWidgetItem(QString::number(players[playersCount]->getGamePlayed()));
        ui->profilesTable->setItem(playersCount,1,col2Item2);

        QTableWidgetItem *col3Item1 = new QTableWidgetItem(players[playersCount]->winRate());
        ui->tableWidget_2->setItem(playersCount,2,col3Item1);

        QTableWidgetItem *col3Item2 = new QTableWidgetItem(players[playersCount]->winRate());
        ui->profilesTable->setItem(playersCount,2,col3Item2);

        ui->profilesStatus->hide();
        ui->profilesStatus_2->hide();

        QFile file("../../db/PlayersDataBase.txt");

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            return;
        }

        QTextStream out(&file);
        out << players[playersCount]->getName() << ";" << players[playersCount]->getGamePlayed() << ";" << players[playersCount]->getWinGames() << ";\n";

        playersCount++;
    }

}
    // КОНЕЦ ФУНКЦИЙ ДЛЯ 'ВКЛАДКА ДОБАВЛЕНИЯ ИГРОКА'

void MainWindow::on_profiles_returnToMenu_clicked() // выход в главное меню
{
    ui->stackedWidget->setCurrentWidget(ui->startMenu);

    ui->playersProfiles_stacked->setCurrentWidget(ui->profiles_SelectPlayer);
    ui->playersProfiles_addLineEdit->clear();
}

void MainWindow::on_tableWidget_2_cellClicked(int row, int column) // активация кнопок при нажатии на строку таблицы
{
    QTableWidgetItem* item = ui->tableWidget_2->item(row, column);

    if (item != nullptr && !(item->flags() & Qt::ItemIsEnabled))
        return;

    ui->pushButton_5->setEnabled(true);
    ui->label_3->setText("Выбранный профиль: "+players[row]->getName());
}

// ВКЛАДКА ПРОСМОТРА ПРОФИЛЕЙ

void MainWindow::on_profilesTable_cellClicked(int row, int column) // активация кнопкок при нажатии на строку таблицы
{
    ui->editProfile_button->setEnabled(true);
    ui->deleteProfile_button->setEnabled(true);
    ui->sort_button->setEnabled(true);

    selectedProfile = row;
}


void MainWindow::on_deleteProfile_button_clicked() // удаление профиля
{
    int selectedRow = ui->profilesTable->currentRow();

    players.erase(players.begin() + selectedRow);

    ui->profilesTable->removeRow(selectedRow);
    ui->tableWidget_2->removeRow(selectedRow);

    playersCount--;
    rewriteFile();

    if (playersCount == 0) {
        ui->editProfile_button->setEnabled(false);
        ui->deleteProfile_button->setEnabled(false);
        ui->sort_button->setEnabled(false);

        ui->profilesStatus->show();
        ui->profilesStatus_2->show();
    }
}

void MainWindow::on_createProfile_button_clicked() // переход на вкладку ДОБАВЛЕНИЕ ПРОФИЛЯ
{
    ui->playersProfiles_stacked->setCurrentWidget(ui->profiles_createPlayer);
}

    // ВКЛАДКА ПРОСМОТРА ПРОФИЛЕЙ -> ВКЛАДКА ДОБАВЛЕНИЯ ПРОФИЛЯ

void MainWindow::on_playersProfiles_addButton_clicked() // добавление профиля + переход на вкладку ВКЛАДКА ПРОСМОТРА ПРОФИЛЕЙ
{
    QString name = ui->playersProfiles_addLineEdit->text();

    if (isPlayerExist(name)) {
        QMessageBox::critical(0, "Ошибка добавления профиля", "Профиль с таким же именем уже существует!\nВыберите другое имя");
        return;
    }

    if(isPlayerNameCorrect(name)) {

        ui->playersProfiles_stacked->setCurrentWidget(ui->profiles_SelectPlayer); // переход на вкладку ВКЛАДКА ПРОСМОТРА ПРОФИЛЕЙ
        ui->playerChoosin_label->show();

        ui->tableWidget_2->insertRow(playersCount);
        ui->profilesTable->insertRow(playersCount);

        players.push_back(new Player(name, 0, 0));


        QTableWidgetItem *col1Item1 = new QTableWidgetItem(name);
        ui->tableWidget_2->setItem(playersCount,0,col1Item1);

        QTableWidgetItem *col1Item2 = new QTableWidgetItem(name);
        ui->profilesTable->setItem(playersCount,0,col1Item2);

        QTableWidgetItem *col2Item1 = new QTableWidgetItem(QString::number(players[playersCount]->getGamePlayed()));
        ui->tableWidget_2->setItem(playersCount,1,col2Item1);

        QTableWidgetItem *col2Item2 = new QTableWidgetItem(QString::number(players[playersCount]->getGamePlayed()));
        ui->profilesTable->setItem(playersCount,1,col2Item2);

        QTableWidgetItem *col3Item1 = new QTableWidgetItem(players[playersCount]->winRate());
        ui->tableWidget_2->setItem(playersCount,2,col3Item1);

        QTableWidgetItem *col3Item2 = new QTableWidgetItem(players[playersCount]->winRate());
        ui->profilesTable->setItem(playersCount,2,col3Item2);

        ui->profilesStatus->hide();
        ui->profilesStatus_2->hide();

        QFile file("../../db/PlayersDataBase.txt");

        if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
            return;
        }

        QTextStream out(&file);
        out << players[playersCount]->getName() << ";" << players[playersCount]->getGamePlayed() << ";" << players[playersCount]->getWinGames() << ";\n";

        playersCount++;
    }
}

void MainWindow::on_playersProfiles_addCancel_clicked() // отмена
{
    ui->playersProfiles_stacked->setCurrentWidget(ui->profiles_SelectPlayer); // переход на вкалдку ВКЛАДКА ПРОСМОТРА ПРОФИЛЕЙ
    ui->playersProfiles_addLineEdit->clear();
}

    // конец функций для ВКЛАДКА ДОБАВЛЕНИЯ ПРОФИЛЯ


void MainWindow::on_editProfile_button_clicked() // переход на вкладку ИЗМЕНЕНИЕ ПРОФИЛЯ
{
    ui->playersProfiles_stacked->setCurrentWidget(ui->profiles_editPlayer);
    ui->playersProfiles_editLineEdit->setText(players[selectedProfile]->getName()); // выписывание имя профиля для дальнейшего изменения
}

    // ВКЛАДКА ПРОСМОТРА ПРОФИЛЕЙ -> ИЗМЕНЕНИЯ ПРОФИЛЯ

void MainWindow::on_playersProfiles_editButton_clicked()
{

    QString name = ui->playersProfiles_editLineEdit->text();

    if (isPlayerExist(name)) {
        QMessageBox::critical(0, "Ошибка добавления профиля", "Профиль с таким же именем уже существует!\nВыберите другое имя");
        return;
    }

    if(isPlayerNameCorrect(name)) {

        ui->playersProfiles_stacked->setCurrentWidget(ui->profiles_SelectPlayer); // переход на вкладку ВКЛАДКА ПРОСМОТРА ПРОФИЛЕЙ
        ui->playerChoosin_label->show();

        players[selectedProfile]->setName(name);

        QTableWidgetItem *col1Item1 = new QTableWidgetItem(name);
        ui->tableWidget_2->setItem(selectedProfile,0,col1Item1);

        QTableWidgetItem *col1Item2 = new QTableWidgetItem(name);
        ui->profilesTable->setItem(selectedProfile,0,col1Item2);

        QTableWidgetItem *col2Item1 = new QTableWidgetItem(QString::number(players[selectedProfile]->getGamePlayed()));
        ui->tableWidget_2->setItem(selectedProfile,1,col2Item1);

        QTableWidgetItem *col2Item2 = new QTableWidgetItem(QString::number(players[selectedProfile]->getGamePlayed()));
        ui->profilesTable->setItem(selectedProfile,1,col2Item2);

        QTableWidgetItem *col3Item1 = new QTableWidgetItem(players[selectedProfile]->winRate());
        ui->tableWidget_2->setItem(selectedProfile,2,col3Item1);

        QTableWidgetItem *col3Item2 = new QTableWidgetItem(players[selectedProfile]->winRate());
        ui->profilesTable->setItem(selectedProfile,2,col3Item2);

        rewriteFile();
    }
}


void MainWindow::on_playersProfiles_editCancel_clicked()
{
    ui->playersProfiles_stacked->setCurrentWidget(ui->profiles_SelectPlayer);
}

    // конец функций для ВКЛАДКА ИЗМЕНЕНИЯ ПРОФИЛЯ

void MainWindow::on_pushButton_5_clicked()
{
    int selectedRow = ui->tableWidget_2->currentRow();

    selectedProfilesForGame.push_back(players[selectedRow]->getName());
    currentPlayers.push_back(players[selectedRow]);
    currentChoosing++;

    ui->playerChoosin_label->setText("Игрок #2 выбирает профиль игрока");

    for (int column = 0; column < 3; ++column)
    {
        QTableWidgetItem* item = ui->tableWidget_2->item(selectedRow, column);

        if (item != nullptr)
        {
            item->setFlags(item->flags() & ~Qt::ItemIsEnabled);

            item->setForeground(Qt::gray);
        }
    }

    ui->label_3->setText("Выбранный профиль:");
    ui->pushButton_5->setEnabled(false);

    if (currentChoosing == 2) {
        ui->stackedWidget->setCurrentWidget(ui->selectHeroes);
        currentChoosing = 0;

        int rowCount = ui->tableWidget_2->rowCount();
        int columnCount = ui->tableWidget_2->columnCount();

        for (int row = 0; row < rowCount; ++row)
        {
            for (int column = 0; column < columnCount; ++column)
            {
                QTableWidgetItem* item = ui->tableWidget_2->item(row, column);

                if (item != nullptr)
                {
                    item->setFlags(item->flags() | Qt::ItemIsEnabled);
                    item->setForeground(Qt::black);
                }
            }
        }

        ui->player1_label->setText(selectedProfilesForGame[0]);
        ui->player2_label->setText(selectedProfilesForGame[1]);
        ui->playerChoosingHero_label->setText("Игрок '"+selectedProfilesForGame[0]+"' выбирает персонажа");


    }



}


void MainWindow::on_endGame_button_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите завершить игру? Игра не будет засчитана.",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        ui->stackedWidget->setCurrentWidget(ui->startMenu);
    }

    ui->LinaChoosed->hide();
    ui->PhoenixChoosed->hide();
    ui->VenomancerChoosed->hide();
    ui->DRChoosed->hide();
    ui->DKChoosed->hide();

    ui->pushButton_3->setEnabled(true);
    ui->PhoenixChoose_button->setEnabled(true);
    ui->VenomancerChoose_button->setEnabled(true);
    ui->DRChoose_button->setEnabled(true);
    ui->DKChoose_button->setEnabled(true);

    heroes.clear();
    currentHeroChoosing = 0;
}



void MainWindow::on_pushButton_3_clicked()
{
    ui->LinaChoosed->show();
    ui->pushButton_3->setEnabled(false);


    heroes.push_back(Lina());
    currentHeroChoosing++;

    QMovie *lina = new QMovie("../../Resources/images/Heroes/Lina/Lina.gif");


    if (currentHeroChoosing == 2) {
        ui->player2_hero->setText("Играет за Lina");
        ui->player2_heroGif->setMovie(lina);
        ui->player2Gif->setMovie(lina);
        ui->stackedWidget->setCurrentWidget(ui->preGameMenu);
    } else {
        ui->player1_hero->setText("Играет за Lina");
        ui->player1_heroGif->setMovie(lina);
        ui->player1Gif->setMovie(lina);
        ui->playerChoosingHero_label->setText("Игрок '"+selectedProfilesForGame[1]+"' выбирает персонажа");
    }

    lina->start();
}


void MainWindow::on_LinaDetails_button_clicked()
{
    linaDetails.exec();
}


void MainWindow::on_PhoenixChoose_button_clicked()
{
    ui->PhoenixChoosed->show();
    ui->PhoenixChoose_button->setEnabled(false);

    QMovie *phoenix = new QMovie("../../Resources/images/Heroes/Phoenix/Phoenix.gif");



    heroes.push_back(Phoenix());
    currentHeroChoosing++;

    if (currentHeroChoosing == 2) {
        ui->player2_hero->setText("Играет за Phoenix");
        ui->player2_heroGif->setMovie(phoenix);
        ui->player2Gif->setMovie(phoenix);
        ui->stackedWidget->setCurrentWidget(ui->preGameMenu);
    } else {
        ui->player1_hero->setText("Играет за Phoenix");
        ui->player1_heroGif->setMovie(phoenix);
        ui->player1Gif->setMovie(phoenix);
        ui->playerChoosingHero_label->setText("Игрок '"+selectedProfilesForGame[1]+"' выбирает персонажа");
    }

    phoenix->start();
}


void MainWindow::on_PhoenixDetails_button_clicked()
{
    phoenixDetails.exec();
}


void MainWindow::on_VenomancerChoose_button_clicked()
{
    ui->VenomancerChoosed->show();
    ui->VenomancerChoose_button->setEnabled(false);

    QMovie *venomancer = new QMovie("../../Resources/images/Heroes/Venomancer/Venomancer.gif");

    heroes.push_back(Venomancer());
    currentHeroChoosing++;

    if (currentHeroChoosing == 2) {
        ui->player2_hero->setText("Играет за Venomancer");
        ui->player2_heroGif->setMovie(venomancer);
        ui->player2Gif->setMovie(venomancer);
        ui->stackedWidget->setCurrentWidget(ui->preGameMenu);
    } else {
        ui->player1_hero->setText("Играет за Venomancer");
        ui->player1_heroGif->setMovie(venomancer);
        ui->player1Gif->setMovie(venomancer);
        ui->playerChoosingHero_label->setText("Игрок '"+selectedProfilesForGame[1]+"' выбирает персонажа");
    }

    venomancer->start();
}


void MainWindow::on_VenomancerDetails_button_clicked()
{
    venomancerDetails.exec();
}


void MainWindow::on_DRDetails_button_clicked()
{
    drowRangerDetails.exec();
}


void MainWindow::on_DRChoose_button_clicked()
{
    ui->DRChoosed->show();
    ui->DRChoose_button->setEnabled(false);

    QMovie *drowRanger = new QMovie("../../Resources/images/Heroes/DrowRanger/DrowRanger.gif");

    heroes.push_back(DrowRanger());
    currentHeroChoosing++;

    if (currentHeroChoosing == 2) {
        ui->player2_hero->setText("Играет за Drow Ranger");
        ui->player2_heroGif->setMovie(drowRanger);
        ui->player2Gif->setMovie(drowRanger);
        ui->stackedWidget->setCurrentWidget(ui->preGameMenu);
    } else {
        ui->player1_hero->setText("Играет за Drow Ranger");
        ui->player1_heroGif->setMovie(drowRanger);
        ui->player1Gif->setMovie(drowRanger);
        ui->playerChoosingHero_label->setText("Игрок '"+selectedProfilesForGame[1]+"' выбирает персонажа");
    }

    drowRanger->start();
}


void MainWindow::on_DKChoose_button_clicked()
{
    ui->DKChoosed->show();
    ui->DKChoose_button->setEnabled(false);

    QMovie *dragonKnight = new QMovie("../../Resources/images/Heroes/DragonKnight/DragonKnight.gif");

    heroes.push_back(DragonKnight());
    currentHeroChoosing++;

    if (currentHeroChoosing == 2) {
        ui->player2_hero->setText("Играет за Dragon Knight");
        ui->player2_heroGif->setMovie(dragonKnight);
        ui->player2Gif->setMovie(dragonKnight);
        ui->stackedWidget->setCurrentWidget(ui->preGameMenu);
    } else {
        ui->player1_hero->setText("Играет за Dragon Knight");
        ui->player1_heroGif->setMovie(dragonKnight);
        ui->player1Gif->setMovie(dragonKnight);
        ui->playerChoosingHero_label->setText("Игрок '"+selectedProfilesForGame[1]+"' выбирает персонажа");
    }

    dragonKnight->start();
}


void MainWindow::on_DKDetails_button_clicked()
{
    dragonKnightDetails.exec();
}


void MainWindow::on_pushButton_7_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Подтверждение", "Вы уверены, что хотите завершить игру? Игра не будет засчитана.",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        ui->stackedWidget->setCurrentWidget(ui->startMenu);
    } else {
        return;
    }

    ui->LinaChoosed->hide();
    ui->PhoenixChoosed->hide();
    ui->VenomancerChoosed->hide();
    ui->DRChoosed->hide();
    ui->DKChoosed->hide();

    ui->pushButton_3->setEnabled(true);
    ui->PhoenixChoose_button->setEnabled(true);
    ui->VenomancerChoose_button->setEnabled(true);
    ui->DRChoose_button->setEnabled(true);
    ui->DKChoose_button->setEnabled(true);

    heroes.clear();
    currentHeroChoosing = 0;
    clearGame();
}


void MainWindow::on_pushButton_8_clicked()
{
    if (heroes[0].getName() == "Lina") {
        linaDetails.exec();
    } else if (heroes[0].getName() == "Phoenix") {
        phoenixDetails.exec();
    } else if (heroes[0].getName() == "Venomancer") {
        venomancerDetails.exec();
    } else if (heroes[0].getName() == "Drow Ranger") {
        drowRangerDetails.exec();
    } else {
        dragonKnightDetails.exec();
    }
}




void MainWindow::on_startGame_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stageAnnouncement);
    isStageAnnouncement = true;
    ui->nextStage->setText("Cтадия "+QString::number(stageCount)+": ФАРМ");
    ui->player1Name->setText(selectedProfilesForGame[0]);
    ui->player2Name->setText(selectedProfilesForGame[1]);

    ui->player1_HP->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
    ui->player1_Mana->setText(QString::number(heroes[0].getCurrentMana())+" / "+QString::number(heroes[0].getMana()));
    ui->player2_HP->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));
    ui->player2_Mana->setText(QString::number(heroes[1].getCurrentMana())+" / "+QString::number(heroes[1].getMana()));

    stageCount = 1;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (isStageAnnouncement) {
        if (event->text() == "w" || event->text() == "W" || event->text() == "ц" || event->text() == "Ц") {
            isPlayer1Ready = true;
            ui->player1Ready->setText("ГОТОВ");
            ui->player1Ready->setStyleSheet("QLabel { color : green; }");
        }

        if (event->text() == "o" || event->text() == "O" || event->text() == "щ" || event->text() == "Щ") {
            isPlayer2Ready = true;
            ui->player2Ready->setText("ГОТОВ");
            ui->player2Ready->setStyleSheet("QLabel { color : green; }");
        }

        if (isPlayer1Ready && isPlayer2Ready) {
            if (stageCount % 3 == 1) {
                farmStages = 0;
                farmStageFinished = false;
                ui->player1Status->clear();
                ui->player2Status->clear();

                isStageAnnouncement = false;
                processLabel->clear();

                ui->farm_player1->setText(selectedProfilesForGame[0]);
                ui->farm_player2->setText(selectedProfilesForGame[1]);

                ui->gold->setText("Золото за попадание: " + QString::number(goldFarm));

                ui->stackedWidget->setCurrentWidget(ui->farmStage);

                count = 3;
                timer->start(1000);
            } else if (stageCount % 3 == 2) {
                isStageAnnouncement = false;

                std::vector<int> numbers {0, 1, 2, 3, 4, 5, 6, 7, 9, 10}; // нужно добавить 8, чтобы вернуть линкен сферу

                std::random_shuffle(numbers.begin(), numbers.end());

                currentShop.push_back(numbers[0]);
                currentShop.push_back(numbers[1]);
                currentShop.push_back(numbers[2]);

                ui->shopBuying->setText(selectedProfilesForGame[0]+" выбирает, что купить");
                ui->shopGold->setText("Количество золота у "+selectedProfilesForGame[0]+": "+QString::number(heroes[0].getGold()));

                QPixmap item1(items[numbers[0]].image);
                ui->shop_item1img->setPixmap(item1);

                QPixmap item2(items[numbers[1]].image);
                ui->shop_item2img->setPixmap(item2);

                QPixmap item3(items[numbers[2]].image);
                ui->shop_item3img->setPixmap(item3);

                ui->player1Items->setText("Предметы "+selectedProfilesForGame[0]);
                ui->player2Items->setText("Предметы "+selectedProfilesForGame[1]);

                ui->stackedWidget->setCurrentWidget(ui->shopStage);
            } else if (stageCount % 3 == 0){
                isStageAnnouncement = false;

                ui->player1NameInBattle->setText(selectedProfilesForGame[0]+" ("+heroes[0].getName()+")");
                ui->player2NameInBattle->setText(selectedProfilesForGame[1]+" ("+heroes[1].getName()+")");

                currentRound = 1;

                ui->rounds->setText("Раунд "+QString::number(currentRound)+" / "+QString::number(rounds));

                ui->player1_HPInBattle->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
                ui->player1_HP->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
                ui->player2_HPInBattle->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));
                ui->player2_HP->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));

                ui->player1_ManaInBattle->setText(QString::number(heroes[0].getCurrentMana())+" / "+QString::number(heroes[0].getMana()));
                ui->player1_Mana->setText(QString::number(heroes[0].getCurrentMana())+" / "+QString::number(heroes[0].getMana()));
                ui->player2_ManaInBattle->setText(QString::number(heroes[1].getCurrentMana())+" / "+QString::number(heroes[1].getMana()));
                ui->player2_Mana->setText(QString::number(heroes[1].getCurrentMana())+" / "+QString::number(heroes[1].getMana()));

                ui->player1_ab1inBattle->setPixmap(heroes[0].getAbilities()[0].image);
                ui->player1_ab2inBattle->setPixmap(heroes[0].getAbilities()[1].image);
                ui->player1_ab3inBattle->setPixmap(heroes[0].getAbilities()[2].image);

                ui->player2_ab1inBattle->setPixmap(heroes[1].getAbilities()[0].image);
                ui->player2_ab2inBattle->setPixmap(heroes[1].getAbilities()[1].image);
                ui->player2_ab3inBattle->setPixmap(heroes[1].getAbilities()[2].image);

                ui->queue->setText("Очередь "+selectedProfilesForGame[0]);

                ui->logs->clear();
                ui->logs->setText(ui->logs->text()+"# РАУНД "+QString::number(currentRound)+" #\n");

                if (heroes[0].getIsPeriodic()) {
                    heroes[0].getDamage(heroes[0].getPeriodicDamage());
                    ui->logs->setText(ui->logs->text()+selectedProfilesForGame[0]+" получает периодический урон в размере "+QString::number(heroes[0].getPeriodicDamage())+"\n");
                    heroes[0].decreasePeriodic();
                    ui->player1_HPInBattle->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
                    ui->player1_HP->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));

                }

                if (!(heroes[0].getIsSilenced() || heroes[0].getIsStanned())) {
                    if (!P1ab1CD){
                        ui->player1_useAb1->setEnabled(true);
                    }
                    if (!P1ab2CD) {
                        ui->player1_useAb2->setEnabled(true);
                    }
                    if (!P1ab3CD) {
                        ui->player1_useAb3->setEnabled(true);
                    }
                }

                if (heroes[0].items.size() >= 1) {
                    ui->player1_useItem1->setEnabled(true);
                    ui->player1_aboutItem1->setEnabled(true);
                }
                if (heroes[0].items.size() >= 2) {
                    ui->player1_useItem2->setEnabled(true);
                    ui->player1_aboutItem2->setEnabled(true);
                }
                if (heroes[0].items.size() == 3)  {
                    ui->player1_useItem3->setEnabled(true);
                    ui->player1_aboutItem3->setEnabled(true);
                }

                ui->player2_useItem1->setEnabled(false);
                ui->player2_useItem2->setEnabled(false);
                ui->player2_useItem3->setEnabled(false);

                ui->stackedWidget->setCurrentWidget(ui->battleStage);
            }
        }
    } else if (isFarmStage) {
        if ((event->text() == "w" || event->text() == "W" || event->text() == "ц" || event->text() == "Ц") && !isFinished1) {
            stop_rect1();
            isFinished1 = true;
            finishedBoth++;
        }

        if ((event->text() == "o" || event->text() == "O" || event->text() == "щ" || event->text() == "Щ") && !isFinished2) {
            stop_rect2();
            isFinished2 = true;
            finishedBoth++;
        }

        if (finishedBoth == 2) {
            finishedBoth = 0;
            count = 3; // начальное значение обратного отсчёта
            timer = new QTimer(this);
            // Подключение сигнала timeout к слоту
            connect(timer, &QTimer::timeout, this, &MainWindow::countdown);

            // Запуск таймера с интервалом в 1 секунду
            timer->start(1000);
        }
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if (isFarmStage) {

        painter.drawRect(10, 210, 500, 300);
        painter.drawRect(770, 210, 500, 300);

        painter.setBrush(Qt::black);

        painter.drawRect(10, 310, 500, 100);
        painter.drawRect(770, 310, 500, 100);

        // Установка жёлтого цвета для прямоугольника
        painter.setBrush(Qt::yellow);

        painter.drawRect(yellowRectPos1.x(), yellowRectPos1.y(), yellowRectSize, 100);
        painter.drawRect(yellowRectPos2.x(), yellowRectPos2.y(), yellowRectSize, 100);
    }
}

void MainWindow::countdown()
{
    if (farmStages == 3) {
        farmStageFinished = true;
        ui->labelTimer->clear();
        ui->farmStarting->setText("ФАРМ ОКОНЧЕН!");
        ui->farmGoldPlayer1->setText(selectedProfilesForGame[0]+" заработал "+QString::number(player1Received)+" золота");
        ui->farmGoldPlayer2->setText(selectedProfilesForGame[1]+" заработал "+QString::number(player2Received)+" золота");
        goldFarm += 50;
        speed = 1.0;
        if (yellowRectSize != 30) {
            yellowRectSize -= 5;
        }
        ui->player1Gold->setText("Золото: "+QString::number(heroes[0].getGold()));
        ui->player2Gold->setText("Золото: "+QString::number(heroes[1].getGold()));

        isFarmStage = false;

        isPlayer1Ready = false;
        ui->player1Ready->setText("НЕ ГОТОВ");
        ui->player1Ready->setStyleSheet("QLabel { color : red; }");

        isPlayer2Ready = false;
        ui->player2Ready->setText("НЕ ГОТОВ");
        ui->player2Ready->setStyleSheet("QLabel { color : red; }");

        stageCount++;

        player1Received = 0;
        player2Received = 0;

        ui->nextStage->setText("Cтадия "+QString::number(stageCount)+": МАГАЗИН");
        farmStages = 0;

        QTimer::singleShot(3000, this, &MainWindow::delay);

        return;
    }
    if (!farmStageFinished) {
    if (count != 0) {
        ui->labelTimer->setText(QString::number(count));
    } else {
        ui->labelTimer->setText("GO!");
    }
    count--;
    if (count < 0) {
        timer->stop();
        isFarmStage = true;
        farmStages++;
        ui->player1Status->clear();
        ui->player2Status->clear();
        startAnimation1();
        startAnimation2();
        speed +=0.5;
    }
    }
}

void MainWindow::stop_rect1()
{
    if (animationGroup1->state() == QAbstractAnimation::Running) {
        animationGroup1->stop();
        QPoint currentPos = rect1->pos();
        if (currentPos.x() > yellowRectPos1.x()-20 && currentPos.x() < yellowRectPos1.x()+yellowRectSize) {
            ui->player1Status->setText("ОТЛИЧНО!");
            heroes[0].addGold(goldFarm);
            player1Received += goldFarm;
        } else {
            ui->player1Status->setText("ПРОМАХ");
        }
    }
}

void MainWindow::stop_rect2()
{
    if (animationGroup2->state() == QAbstractAnimation::Running) {
        animationGroup2->stop();
        QPoint currentPos = rect2->pos();
        if (currentPos.x() > yellowRectPos2.x()-20 && currentPos.x() < yellowRectPos2.x()+yellowRectSize) {
            ui->player2Status->setText("ОТЛИЧНО!");
            heroes[1].addGold(goldFarm);
            player2Received += goldFarm;
        } else {
            ui->player2Status->setText("ПРОМАХ");
        }
    }
}

void MainWindow::startAnimation1()
{

    isFinished1 = false;

    if (rect1 != nullptr) {
        delete rect1;
    }

    rect1 = new AnimatedRect(this);
    rect1->move(10, 110);
    rect1->show();


    // Создание анимации для движения вперед
    QPropertyAnimation *animation1 = new QPropertyAnimation(rect1, "pos");
    animation1->setDuration(1000/speed); // продолжительность анимации в миллисекундах
    animation1->setStartValue(QPoint(10, 310)); // начальная позиция
    animation1->setEndValue(QPoint(480, 310)); // конечная позиция

    // Создание анимации для движения назад
    QPropertyAnimation *animation2 = new QPropertyAnimation(rect1, "pos");
    animation2->setDuration(1000/speed); // продолжительность анимации в миллисекундах
    animation2->setStartValue(QPoint(480, 310)); // начальная позиция
    animation2->setEndValue(QPoint(10, 310)); // конечная позиция

    QPropertyAnimation *animation3 = new QPropertyAnimation(rect1, "pos");
    animation3->setDuration(1000/speed); // продолжительность анимации в миллисекундах
    animation3->setStartValue(QPoint(10, 310)); // начальная позиция
    animation3->setEndValue(QPoint(480, 310)); // конечная позиция

    // Создание группы анимаций
    animationGroup1 = new QSequentialAnimationGroup;
    animationGroup1->addAnimation(animation1);
    animationGroup1->addAnimation(animation2);
    animationGroup1->addAnimation(animation3);

    connect(animationGroup1, &QSequentialAnimationGroup::finished, this, &MainWindow::onAnimationFinished1);
    // Запуск анимации
    animationGroup1->start(QAbstractAnimation::DeleteWhenStopped);

    QTime time = QTime::currentTime();
    srand((uint)time.msec());

    // Генерация случайной позиции для прямоугольника
    int randomX = rand() % (430 - 10 + 1) + 10; // случайное число в диапазоне от 10 до 480
    yellowRectPos1 = QPoint(randomX, 310);


    // Перерисовка окна
    update();

}

void MainWindow::startAnimation2()
{

    isFinished2 = false;

    if (rect2 != nullptr) {
        delete rect2;
    }

    rect2 = new AnimatedRect(this);
    rect2->move(10, 110);
    rect2->show();

    // Создание анимации для движения вперед
    QPropertyAnimation *animation1 = new QPropertyAnimation(rect2, "pos");
    animation1->setDuration(1000/speed); // продолжительность анимации в миллисекундах
    animation1->setStartValue(QPoint(770, 310)); // начальная позиция
    animation1->setEndValue(QPoint(1240, 310)); // конечная позиция

    // Создание анимации для движения назад
    QPropertyAnimation *animation2 = new QPropertyAnimation(rect2, "pos");
    animation2->setDuration(1000/speed); // продолжительность анимации в миллисекундах
    animation2->setStartValue(QPoint(1240, 310)); // начальная позиция
    animation2->setEndValue(QPoint(770, 310)); // конечная позиция

    QPropertyAnimation *animation3 = new QPropertyAnimation(rect2, "pos");
    animation3->setDuration(1000/speed); // продолжительность анимации в миллисекундах
    animation3->setStartValue(QPoint(770, 310)); // начальная позиция
    animation3->setEndValue(QPoint(1240, 310)); // конечная позиция

    // Создание группы анимаций
    animationGroup2 = new QSequentialAnimationGroup;
    animationGroup2->addAnimation(animation1);
    animationGroup2->addAnimation(animation2);
    animationGroup2->addAnimation(animation3);

    connect(animationGroup2, &QSequentialAnimationGroup::finished, this, &MainWindow::onAnimationFinished2);
    // Запуск анимации
    animationGroup2->start(QAbstractAnimation::DeleteWhenStopped);

    QTime time = QTime::currentTime();
    srand((uint)time.msec());

    // Генерация случайной позиции для прямоугольника
    int randomX = rand() % (430 - 10 + 1) + 770; // случайное число в диапазоне от 10 до 480
    yellowRectPos2 = QPoint(randomX, 310);


    // Перерисовка окна
    update();
}

void MainWindow::onAnimationFinished1() {
        isFinished1=true;
        ui->player1Status->setText("ПРОМАХ");

        count = 3; // начальное значение обратного отсчёта
        // Подключение сигнала timeout к слоту
        finishedBoth = 0;

        // Запуск таймера с интервалом в 1 секунду
        timer->start(1000);
}


void MainWindow::onAnimationFinished2() {
    if (isFinished1) {
        isFinished2=true;
        ui->player2Status->setText("ПРОМАХ");

        count = 3; // начальное значение обратного отсчёта
        // Подключение сигнала timeout к слоту
        finishedBoth = 0;
        timer->start(1000);
    }
}

void MainWindow::delay() {
    rect1->stopPaint();
    rect2->stopPaint();

    processLabel->setMovie(movie);
    movie->start();

    ui->farmGoldPlayer1->clear();
    ui->farmGoldPlayer2->clear();
    ui->farmStarting->setText("ДО НАЧАЛА ФАРМА");

    isStageAnnouncement = true;

    ui->stackedWidget->setCurrentWidget(ui->stageAnnouncement);
}

void MainWindow::on_shop_item1info_clicked()
{
    QMessageBox details;

    details.setWindowTitle(items[currentShop[0]].name);

    QPixmap pixmap(items[currentShop[0]].image);
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText(items[currentShop[0]].desc+"\nСтоимость: "+QString::number(items[currentShop[0]].cost));

    details.exec();
}


void MainWindow::on_shop_item2info_clicked()
{
    QMessageBox details;

    details.setWindowTitle(items[currentShop[1]].name);

    QPixmap pixmap(items[currentShop[1]].image);
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText(items[currentShop[1]].desc+"\nСтоимость: "+QString::number(items[currentShop[1]].cost));

    details.exec();
}


void MainWindow::on_shop_item3info_clicked()
{
    QMessageBox details;

    details.setWindowTitle(items[currentShop[2]].name);

    QPixmap pixmap(items[currentShop[2]].image);
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText(items[currentShop[2]].desc+"\nСтоимость: "+QString::number(items[currentShop[2]].cost));

    details.exec();
}


void MainWindow::on_pushButton_6_clicked()
{
    if (currentlyBuying == 1) {
        currentlyBuying = 0;

        currentShop.clear();

        ui->shop_item1buy->setEnabled(true);
        ui->shop_item2buy->setEnabled(true);
        ui->shop_item3buy->setEnabled(true);

        ui->item1sold->hide();
        ui->item2sold->hide();
        ui->item3sold->hide();

        ui->player1Gold->setText("Золото: "+QString::number(heroes[0].getGold()));
        ui->player2Gold->setText("Золото: "+QString::number(heroes[1].getGold()));

        isStageAnnouncement = true;

        isPlayer1Ready = false;
        ui->player1Ready->setText("НЕ ГОТОВ");
        ui->player1Ready->setStyleSheet("QLabel { color : red; }");

        isPlayer2Ready = false;
        ui->player2Ready->setText("НЕ ГОТОВ");
        ui->player2Ready->setStyleSheet("QLabel { color : red; }");

        stageCount++;
        ui->nextStage->setText("Cтадия "+QString::number(stageCount)+": БИТВА");


        ui->stackedWidget->setCurrentWidget(ui->stageAnnouncement);
    } else {
        currentShop.clear();
        currentlyBuying++;
        std::vector<int> numbers {0, 1, 2, 3, 4, 5, 6, 7, 9, 10}; // тоже нужно вернуть 8, чтобы вернуть линкен сферу

        std::random_shuffle(numbers.begin(), numbers.end());

        currentShop.push_back(numbers[0]);
        currentShop.push_back(numbers[1]);
        currentShop.push_back(numbers[2]);

        ui->shopBuying->setText(selectedProfilesForGame[1]+" выбирает, что купить");
        ui->shopGold->setText("Количество золота у "+selectedProfilesForGame[1]+": "+QString::number(heroes[1].getGold()));

        QPixmap item1(items[numbers[0]].image);
        ui->shop_item1img->setPixmap(item1);

        QPixmap item2(items[numbers[1]].image);
        ui->shop_item2img->setPixmap(item2);

        QPixmap item3(items[numbers[2]].image);
        ui->shop_item3img->setPixmap(item3);

        ui->shop_item1buy->setEnabled(true);
        ui->shop_item2buy->setEnabled(true);
        ui->shop_item3buy->setEnabled(true);

        ui->item1sold->hide();
        ui->item2sold->hide();
        ui->item3sold->hide();
    }
}


void MainWindow::on_shop_item1buy_clicked()
{
    int ind = currentShop[0];
    if (currentlyBuying == 0) {
        int sz = heroes[0].items.size();
        qDebug() << sz;
        if (sz == 3) {
            QMessageBox::critical(this, "Недостаточно места", "Недостаточно места в инвентаре");
        } else {
            if (items[ind].cost <= heroes[0].getGold()) {
                heroes[0].removeGold(items[ind].cost);
                ui->shopGold->setText("Количество золота у "+selectedProfilesForGame[0]+": "+QString::number(heroes[0].getGold()));

                heroes[0].items.push_back(ind);
                sz++;

                updateInvent();

                ui->item1sold->show();
                ui->shop_item1buy->setEnabled(false);
            } else {
                QMessageBox::critical(this, "Недостаточно денег", "Недостаточно денег для данной покупки");
            }
        }
    } else {
        int sz = heroes[1].items.size();
        if (sz == 3) {
            QMessageBox::critical(this, "Недостаточно места", "Недостаточно места в инвентаре");
        } else {
            if (items[ind].cost <= heroes[1].getGold()) {
                heroes[1].removeGold(items[ind].cost);
                ui->shopGold->setText("Количество золота у "+selectedProfilesForGame[1]+": "+QString::number(heroes[1].getGold()));

                heroes[1].items.push_back(ind);
                sz++;

                updateInvent();

                ui->item1sold->show();
                ui->shop_item1buy->setEnabled(false);
            } else {
                QMessageBox::critical(this, "Недостаточно денег", "Недостаточно денег для данной покупки");
            }
        }
    }
}


void MainWindow::on_player1_about1_buttonInShop_clicked()
{
    aboutItem(0, 0);
}


void MainWindow::on_shop_item2buy_clicked()
{
    int ind = currentShop[1];
    if (currentlyBuying == 0) {
        int sz = heroes[0].items.size();
        if (sz == 3) {
            QMessageBox::critical(this, "Недостаточно места", "Недостаточно места в инвентаре");
        } else {
            if (items[ind].cost <= heroes[0].getGold()) {
                heroes[0].removeGold(items[ind].cost);
                ui->shopGold->setText("Количество золота у "+selectedProfilesForGame[0]+": "+QString::number(heroes[0].getGold()));

                heroes[0].items.push_back(ind);
                sz++;

                updateInvent();

                ui->item2sold->show();
                ui->shop_item2buy->setEnabled(false);
            } else {
                QMessageBox::critical(this, "Недостаточно денег", "Недостаточно денег для данной покупки");
            }
        }
    } else {
        int sz = heroes[1].items.size();
        if (sz == 3) {
            QMessageBox::critical(this, "Недостаточно места", "Недостаточно места в инвентаре");
        } else {
            if (items[ind].cost <= heroes[1].getGold()) {
                heroes[1].removeGold(items[ind].cost);
                ui->shopGold->setText("Количество золота у "+selectedProfilesForGame[1]+": "+QString::number(heroes[1].getGold()));

                heroes[1].items.push_back(ind);
                sz++;

                updateInvent();

                ui->item2sold->show();
                ui->shop_item2buy->setEnabled(false);
            } else {
                QMessageBox::critical(this, "Недостаточно денег", "Недостаточно денег для данной покупки");
            }
        }
    }
}


void MainWindow::on_shop_item3buy_clicked()
{
    int ind = currentShop[2];
    if (currentlyBuying == 0) {
        int sz = heroes[0].items.size();
        if (sz == 3) {
            QMessageBox::critical(this, "Недостаточно места", "Недостаточно места в инвентаре");
        } else {
            if (items[ind].cost <= heroes[0].getGold()) {
                heroes[0].removeGold(items[ind].cost);
                ui->shopGold->setText("Количество золота у "+selectedProfilesForGame[0]+": "+QString::number(heroes[0].getGold()));

                heroes[0].items.push_back(ind);
                sz++;

                updateInvent();

                ui->item3sold->show();
                ui->shop_item3buy->setEnabled(false);
            } else {
                QMessageBox::critical(this, "Недостаточно денег", "Недостаточно денег для данной покупки");
            }
        }
    } else {
        int sz = heroes[1].items.size();
        if (sz == 3) {
            QMessageBox::critical(this, "Недостаточно места", "Недостаточно места в инвентаре");
        } else {
            if (items[ind].cost <= heroes[1].getGold()) {
                heroes[1].removeGold(items[ind].cost);
                ui->shopGold->setText("Количество золота у "+selectedProfilesForGame[1]+": "+QString::number(heroes[1].getGold()));

                heroes[1].items.push_back(ind);
                sz++;

                updateInvent();

                ui->item3sold->show();
                ui->shop_item3buy->setEnabled(false);
            } else {
                QMessageBox::critical(this, "Недостаточно денег", "Недостаточно денег для данной покупки");
            }
        }
    }
}


void MainWindow::on_player1_about2_buttonInShop_clicked()
{
    aboutItem(0, 1);
}


void MainWindow::on_player1_about3_buttonInShop_clicked()
{
    aboutItem(0, 2);
}


void MainWindow::on_player2_about1_buttonInShop_clicked()
{
    aboutItem(1, 0);
}


void MainWindow::on_player2_about2_buttonInShop_clicked()
{
    aboutItem(1, 1);
}


void MainWindow::on_player2_about3_buttonInShop_clicked()
{
    aboutItem(1, 2);
}

void MainWindow::on_player1_aboutAb1_clicked()
{
    if (heroes[0].getName() == "Lina") {
        linaDetails.on_Ab_1_clicked();
    } else if (heroes[0].getName() == "Phoenix") {
        phoenixDetails.on_Ab_1_clicked();
    } else if (heroes[0].getName() == "Venomancer") {
        venomancerDetails.on_Ab_1_clicked();
    } else if (heroes[0].getName() == "Drow Ranger") {
        drowRangerDetails.on_Ab_1_clicked();
    } else {
        dragonKnightDetails.on_Ab_1_clicked();
    }
}


void MainWindow::on_player1_aboutAb2_clicked()
{
    if (heroes[0].getName() == "Lina") {
        linaDetails.on_Ab_2_clicked();
    } else if (heroes[0].getName() == "Phoenix") {
        phoenixDetails.on_Ab_2_clicked();
    } else if (heroes[0].getName() == "Venomancer") {
        venomancerDetails.on_Ab_2_clicked();
    } else if (heroes[0].getName() == "Drow Ranger") {
        drowRangerDetails.on_Ab_2_clicked();
    } else {
        dragonKnightDetails.on_Ab_2_clicked();
    }
}


void MainWindow::on_player1_aboutAb3_clicked()
{
    if (heroes[0].getName() == "Lina") {
        linaDetails.on_Ab_3_clicked();
    } else if (heroes[0].getName() == "Phoenix") {
        phoenixDetails.on_Ab_3_clicked();
    } else if (heroes[0].getName() == "Venomancer") {
        venomancerDetails.on_Ab_3_clicked();
    } else if (heroes[0].getName() == "Drow Ranger") {
        drowRangerDetails.on_Ab_3_clicked();
    } else {
        dragonKnightDetails.on_Ab_3_clicked();
    }
}


void MainWindow::on_player2_aboutAb1_clicked()
{
    if (heroes[1].getName() == "Lina") {
        linaDetails.on_Ab_1_clicked();
    } else if (heroes[1].getName() == "Phoenix") {
        phoenixDetails.on_Ab_1_clicked();
    } else if (heroes[1].getName() == "Venomancer") {
        venomancerDetails.on_Ab_1_clicked();
    } else if (heroes[1].getName() == "Drow Ranger") {
        drowRangerDetails.on_Ab_1_clicked();
    } else {
        dragonKnightDetails.on_Ab_1_clicked();
    }
}


void MainWindow::on_player2_aboutAb2_clicked()
{
    if (heroes[1].getName() == "Lina") {
        linaDetails.on_Ab_2_clicked();
    } else if (heroes[1].getName() == "Phoenix") {
        phoenixDetails.on_Ab_2_clicked();
    } else if (heroes[1].getName() == "Venomancer") {
        venomancerDetails.on_Ab_2_clicked();
    } else if (heroes[1].getName() == "Drow Ranger") {
        drowRangerDetails.on_Ab_2_clicked();
    } else {
        dragonKnightDetails.on_Ab_2_clicked();
    }
}


void MainWindow::on_player2_aboutAb3_clicked()
{
    if (heroes[1].getName() == "Lina") {
        linaDetails.on_Ab_3_clicked();
    } else if (heroes[1].getName() == "Phoenix") {
        phoenixDetails.on_Ab_3_clicked();
    } else if (heroes[1].getName() == "Venomancer") {
        venomancerDetails.on_Ab_3_clicked();
    } else if (heroes[1].getName() == "Drow Ranger") {
        drowRangerDetails.on_Ab_3_clicked();
    } else {
        dragonKnightDetails.on_Ab_3_clicked();
    }
}


void MainWindow::on_player1_useAb1_clicked() // первый игрок использует способность 1
{
    Ability ab = heroes[0].getAbilities()[0]; // способность 1

    if (ab.manaCost <= heroes[0].getCurrentMana()) {
        ui->player1_useAb1->setEnabled(false);
        ui->player1_useAb2->setEnabled(false);
        ui->player1_useAb3->setEnabled(false);

        P1ab1used = true;

        heroes[0].removeMana(ab.manaCost); // отнимается мана у игрока 1
        heroes[1].getDamage(ab.damage); // второй игрок получает урон
        ui->logs->setText(ui->logs->text()+selectedProfilesForGame[0]+" нанёс "+QString::number(ab.damage)+" урона игроку "+selectedProfilesForGame[1]+"\n");
        if (heroes[1].getCurrentHP() <= 0) {
            heroes[1].setCurrentHP(0);
            winner(0);
        }
        ui->player2_HPInBattle->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth())); // показ здоровья второго игрока
        ui->player2_HP->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));
        ui->player1_ManaInBattle->setText(QString::number(heroes[0].getCurrentMana())+" / "+QString::number(heroes[0].getMana())); // показ здоровья второго игрока
        ui->player1_Mana->setText(QString::number(heroes[0].getCurrentMana())+" / "+QString::number(heroes[0].getMana()));
        if (ab.silence != 0) {
            heroes[1].setSilence(ab.silence);
            ui->player2_Status->setText("Наложено безмолвие на 1 раунд");
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[0]+" наложил безмолвие на "+selectedProfilesForGame[1]+" на один раунд\n");
        }
        if (ab.stan != 0) {
            heroes[1].setStanned(ab.stan);
            ui->player2_Status->setText("Оглушён на 1 раунд");
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[0]+" оглушил "+selectedProfilesForGame[1]+" на один раунд\n");
        }

        if (ab.periodic != 0) {
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[0]+" наложил периодический урон в размере "+QString::number(ab.periodic)+" на "+selectedProfilesForGame[1]+" на количество раундов: "+QString::number(ab.periodicFor)+"\n");
            heroes[1].setPeriodic(ab.periodicFor);
            heroes[1].addPeriodicDamage(ab.periodic);
        }

        P1ab1CD = ab.cooldown;

        if (P1ab1CD != 0) {
            ui->player1_ab1CD->setText(QString::number(P1ab1CD));
        }
    } else {
        QMessageBox::critical(this, "Недостаточно маны", "Недостаточно маны, чтобы применить способность");
    }
}


void MainWindow::on_player1_useAb2_clicked()
{
    Ability ab = heroes[0].getAbilities()[1];

    if (ab.manaCost <= heroes[0].getCurrentMana()) {
        ui->player1_useAb1->setEnabled(false);
        ui->player1_useAb2->setEnabled(false);
        ui->player1_useAb3->setEnabled(false);

        P1ab2used = true;

        heroes[0].removeMana(ab.manaCost);
        heroes[1].getDamage(ab.damage);
        ui->logs->setText(ui->logs->text()+selectedProfilesForGame[0]+" нанёс "+QString::number(ab.damage)+" урона игроку "+selectedProfilesForGame[1]+"\n");
        if (heroes[1].getCurrentHP() <= 0) {
            heroes[1].setCurrentHP(0);
            winner(0);
        }
        ui->player2_HPInBattle->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));
        ui->player2_HP->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));
        ui->player1_ManaInBattle->setText(QString::number(heroes[0].getCurrentMana())+" / "+QString::number(heroes[0].getMana()));
        ui->player1_Mana->setText(QString::number(heroes[0].getCurrentMana())+" / "+QString::number(heroes[0].getMana()));
        if (ab.silence != 0) {
            heroes[1].setSilence(ab.silence);
            ui->player2_Status->setText("Наложено безмолвие на 1 раунд");
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[0]+" наложил безмолвие на "+selectedProfilesForGame[1]+" на один раунд\n");
        }
        if (ab.stan != 0) {
            heroes[1].setStanned(ab.stan);
            ui->player2_Status->setText("Оглушён на 1 раунд");
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[0]+" оглушил "+selectedProfilesForGame[1]+" на один раунд\n");
        }

        if (ab.periodic != 0) {
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[0]+" наложил периодический урон в размере "+QString::number(ab.periodic)+" на "+selectedProfilesForGame[1]+" на количество раундов: "+QString::number(ab.periodicFor)+"\n");
            heroes[1].setPeriodic(ab.periodicFor);
            heroes[1].addPeriodicDamage(ab.periodic);
        }

        P1ab2CD = ab.cooldown;

        if (P1ab2CD != 0) {
            ui->player1_ab2CD->setText(QString::number(P1ab2CD));
        }
    } else {
        QMessageBox::critical(this, "Недостаточно маны", "Недостаточно маны, чтобы применить способность");
    }


}


void MainWindow::on_player1_useAb3_clicked()
{
    Ability ab = heroes[0].getAbilities()[2];

    if (ab.manaCost <= heroes[0].getCurrentMana()) {
        ui->player1_useAb1->setEnabled(false);
        ui->player1_useAb2->setEnabled(false);
        ui->player1_useAb3->setEnabled(false);

        P1ab3used = true;

        heroes[0].removeMana(ab.manaCost);
        heroes[1].getDamage(ab.damage);
        ui->logs->setText(ui->logs->text()+selectedProfilesForGame[0]+" нанёс "+QString::number(ab.damage)+" урона игроку "+selectedProfilesForGame[1]+"\n");
        if (heroes[1].getCurrentHP() <= 0) {
            heroes[1].setCurrentHP(0);
            winner(0);
        }
        ui->player2_HPInBattle->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));
        ui->player2_HP->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));
        ui->player1_ManaInBattle->setText(QString::number(heroes[0].getCurrentMana())+" / "+QString::number(heroes[0].getMana()));
        ui->player1_Mana->setText(QString::number(heroes[0].getCurrentMana())+" / "+QString::number(heroes[0].getMana()));
        if (ab.silence != 0) {
            heroes[1].setSilence(ab.silence);
            ui->player2_Status->setText("Наложено безмолвие на 1 раунд");
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[0]+" наложил безмолвие на "+selectedProfilesForGame[1]+" на один раунд\n");
        }
        if (ab.stan != 0) {
            heroes[1].setStanned(ab.stan);
            ui->player2_Status->setText("Оглушён на 1 раунд");
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[0]+" оглушил "+selectedProfilesForGame[1]+" на один раунд\n");
        }

        if (ab.periodic != 0) {
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[0]+" наложил периодический урон в размере "+QString::number(ab.periodic)+" на "+selectedProfilesForGame[1]+" на количество раундов: "+QString::number(ab.periodicFor)+"\n");
            heroes[1].setPeriodic(ab.periodicFor);
            heroes[1].addPeriodicDamage(ab.periodic);
        }

        P1ab3CD = ab.cooldown;

        if (P1ab3CD != 0) {
            ui->player1_ab3CD->setText(QString::number(P1ab3CD));
        }
    } else {
        QMessageBox::critical(this, "Недостаточно маны", "Недостаточно маны, чтобы применить способность");
    }


}


void MainWindow::on_player2_useAb1_clicked()
{
    Ability ab = heroes[1].getAbilities()[0];

    if (ab.manaCost <= heroes[1].getCurrentMana()) {
        ui->player2_useAb1->setEnabled(false);
        ui->player2_useAb2->setEnabled(false);
        ui->player2_useAb3->setEnabled(false);

        P2ab1used = true;

        heroes[1].removeMana(ab.manaCost);
        heroes[0].getDamage(ab.damage);
        ui->logs->setText(ui->logs->text()+selectedProfilesForGame[1]+" нанёс "+QString::number(ab.damage)+" урона игроку "+selectedProfilesForGame[0]+"\n");
        if (heroes[0].getCurrentHP() <= 0) {
            heroes[0].setCurrentHP(0);
            winner(1);
        }
        ui->player1_HPInBattle->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
        ui->player1_HP->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
        ui->player2_ManaInBattle->setText(QString::number(heroes[1].getCurrentMana())+" / "+QString::number(heroes[1].getMana()));
        ui->player2_Mana->setText(QString::number(heroes[1].getCurrentMana())+" / "+QString::number(heroes[1].getMana()));
        if (ab.silence != 0) {
            heroes[0].setSilence(ab.silence);
            ui->player1_Status->setText("Наложено безмолвие на 1 раунд");
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[1]+" наложил безмолвие на "+selectedProfilesForGame[0]+" на один раунд\n");
        }
        if (ab.stan != 0) {
            heroes[0].setStanned(ab.stan);
            ui->player1_Status->setText("Оглушён на 1 раунд");
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[1]+" оглушил "+selectedProfilesForGame[0]+" на один раунд\n");
        }

        if (ab.periodic != 0) {
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[1]+" наложил периодический урон в размере "+QString::number(ab.periodic)+" на "+selectedProfilesForGame[0]+" на количество раундов: "+QString::number(ab.periodicFor)+"\n");
            heroes[0].setPeriodic(ab.periodicFor);
            heroes[0].addPeriodicDamage(ab.periodic);
        }

        P2ab1CD = ab.cooldown;

        if (P2ab1CD != 0) {
            ui->player2_ab1CD->setText(QString::number(P2ab1CD));
        }
    } else {
        QMessageBox::critical(this, "Недостаточно маны", "Недостаточно маны, чтобы применить способность");
    }


}


void MainWindow::on_player2_useAb2_clicked()
{


    Ability ab = heroes[1].getAbilities()[1];

    if (ab.manaCost <= heroes[1].getCurrentMana()) {
        ui->player2_useAb1->setEnabled(false);
        ui->player2_useAb2->setEnabled(false);
        ui->player2_useAb3->setEnabled(false);

        P2ab2used = true;

        heroes[1].removeMana(ab.manaCost);
        heroes[0].getDamage(ab.damage);
        ui->logs->setText(ui->logs->text()+selectedProfilesForGame[1]+" нанёс "+QString::number(ab.damage)+" урона игроку "+selectedProfilesForGame[0]+"\n");
        if (heroes[0].getCurrentHP() <= 0) {
            heroes[0].setCurrentHP(0);
            winner(1);
        }
        ui->player1_HPInBattle->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
        ui->player1_HP->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
        ui->player2_ManaInBattle->setText(QString::number(heroes[1].getCurrentMana())+" / "+QString::number(heroes[1].getMana()));
        ui->player2_Mana->setText(QString::number(heroes[1].getCurrentMana())+" / "+QString::number(heroes[1].getMana()));
        if (ab.silence != 0) {
            heroes[0].setSilence(ab.silence);
            ui->player1_Status->setText("Наложено безмолвие на 1 раунд");
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[1]+" наложил безмолвие на "+selectedProfilesForGame[0]+" на один раунд\n");
        }
        if (ab.stan != 0) {
            heroes[0].setStanned(ab.stan);
            ui->player1_Status->setText("Оглушён на 1 раунд");
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[1]+" оглушил "+selectedProfilesForGame[0]+" на один раунд\n");
        }

        if (ab.periodic != 0) {
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[1]+" наложил периодический урон в размере"+QString::number(ab.periodic)+" на "+selectedProfilesForGame[0]+" на количество раундов: "+QString::number(ab.periodicFor)+"\n");
            heroes[0].setPeriodic(ab.periodicFor);
            heroes[0].addPeriodicDamage(ab.periodic);
        }

        P2ab2CD = ab.cooldown;

        if (P2ab2CD != 0) {
            ui->player2_ab2CD->setText(QString::number(P2ab2CD));
        }
    } else {
        QMessageBox::critical(this, "Недостаточно маны", "Недостаточно маны, чтобы применить способность");
    }
}


void MainWindow::on_player2_useAb3_clicked()
{
    Ability ab = heroes[1].getAbilities()[2];

    if (ab.manaCost <= heroes[1].getCurrentMana()) {
        ui->player2_useAb1->setEnabled(false);
        ui->player2_useAb2->setEnabled(false);
        ui->player2_useAb3->setEnabled(false);

        P2ab3used = true;

        heroes[1].removeMana(ab.manaCost);
        heroes[0].getDamage(ab.damage);
        ui->logs->setText(ui->logs->text()+selectedProfilesForGame[1]+" нанёс "+QString::number(ab.damage)+" урона игроку "+selectedProfilesForGame[0]+"\n");
        if (heroes[0].getCurrentHP() <= 0) {
            heroes[0].setCurrentHP(0);
            winner(1);
        }
        ui->player1_HPInBattle->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
        ui->player1_HP->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
        ui->player2_ManaInBattle->setText(QString::number(heroes[1].getCurrentMana())+" / "+QString::number(heroes[1].getMana()));
        ui->player2_Mana->setText(QString::number(heroes[1].getCurrentMana())+" / "+QString::number(heroes[1].getMana()));
        if (ab.silence) {
            heroes[0].setSilence(ab.silence);
            ui->player1_Status->setText("Наложено безмолвие на 1 раунд");
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[1]+" наложил безмолвие на "+selectedProfilesForGame[0]+" на один раунд\n");
        }
        if (ab.stan) {
            heroes[0].setStanned(ab.stan);
            ui->player1_Status->setText("Оглушён на 1 раунд");
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[1]+" оглушил "+selectedProfilesForGame[0]+" на один раунд\n");
        }

        if (ab.periodic) {
            ui->logs->setText(ui->logs->text()+selectedProfilesForGame[1]+" наложил периодический урон в размере"+QString::number(ab.periodic)+" на "+selectedProfilesForGame[0]+" на количество раундов: "+QString::number(ab.periodicFor)+"\n");
            heroes[0].setPeriodic(ab.periodicFor);
            heroes[0].addPeriodicDamage(ab.periodic);

        }

        P2ab3CD = ab.cooldown;

        if (P2ab3CD != 0) {
            ui->player2_ab3CD->setText(QString::number(P2ab3CD));
        }
    } else {
        QMessageBox::critical(this, "Недостаточно маны", "Недостаточно маны, чтобы применить способность");
    }
}


void MainWindow::on_pushButton_14_clicked() // закончить ход
{
    if (currentRound == rounds) {

        rounds += 2;
        currentRound = 1;

        if (heroes[1].getIsSilenced()) {
            heroes[1].setSilence(0);
            ui->player2_Status->clear();
        }
        if (heroes[1].getIsStanned()) {
            heroes[1].setStanned(0);
            ui->player2_Status->clear();
        }

        if (P2ab1CD && !P2ab1used) {
            P2ab1CD--;
            if (!P2ab1CD) {
                ui->player2_ab1CD->clear();
            } else {
                ui->player2_ab1CD->setText(QString::number(P2ab1CD));
            }
        } else {
            P2ab1used = false;
        }

        if (P2ab2CD && !P2ab2used) {
            P2ab2CD--;
            if (!P2ab2CD) {
                ui->player2_ab2CD->clear();
            } else {
                ui->player2_ab2CD->setText(QString::number(P2ab2CD));
            }
        } else {
            P2ab2used = false;
        }

        if (P2ab3CD && !P2ab3used) {
            P2ab3CD--;
            if (!P2ab3CD) {
                ui->player2_ab3CD->clear();
            } else {
                ui->player2_ab3CD->setText(QString::number(P2ab3CD));
            }
        } else {
            P2ab3used = false;
        }

        ui->player1Gold->setText("Золото: "+QString::number(heroes[0].getGold()));
        ui->player2Gold->setText("Золото: "+QString::number(heroes[1].getGold()));

        isStageAnnouncement = true;

        isPlayer1Ready = false;
        ui->player1Ready->setText("НЕ ГОТОВ");
        ui->player1Ready->setStyleSheet("QLabel { color : red; }");

        isPlayer2Ready = false;
        ui->player2Ready->setText("НЕ ГОТОВ");
        ui->player2Ready->setStyleSheet("QLabel { color : red; }");

        stageCount++;
        ui->nextStage->setText("Cтадия "+QString::number(stageCount)+": ФАРМ");

        battleOrder = 0;

        ui->stackedWidget->setCurrentWidget(ui->stageAnnouncement);

    } else {
        currentRound++;
        ui->logs->setText(ui->logs->text()+"# РАУНД "+QString::number(currentRound)+" #\n");
        ui->rounds->setText("Раунд "+QString::number(currentRound)+" / "+QString::number(rounds));

        if (battleOrder == 0) { // переключение очереди на второго игрока
            battleOrder = 1;

            if (heroes[0].getIsSilenced()) {
                heroes[0].setSilence(0);
                ui->player1_Status->clear();
            }
            if (heroes[0].getIsStanned()) {
                heroes[0].setStanned(0);
                ui->player1_Status->clear();
            }

            ui->queue->setText("Очередь " + selectedProfilesForGame[1]);

            if (heroes[1].getIsPeriodic()) {
                heroes[1].getDamage(heroes[1].getPeriodicDamage());
                if (heroes[1].getCurrentHP() <= 0) {
                    heroes[1].setCurrentHP(0);
                    winner(0);
                }
                ui->logs->setText(ui->logs->text()+selectedProfilesForGame[1]+" получает периодический урон в размере "+QString::number(heroes[1].getPeriodicDamage())+"\n");
                heroes[1].decreasePeriodic();
                ui->player2_HPInBattle->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));
                ui->player2_HP->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));
            }

            if (P1ab1CD && !P1ab1used) {
                P1ab1CD--;
                if (!P1ab1CD) {
                    ui->player1_ab1CD->clear();
                } else {
                    ui->player1_ab1CD->setText(QString::number(P1ab1CD));
                }
            } else {
                P1ab1used = false;
            }

            if (P1ab2CD && !P1ab2used) {
                P1ab2CD--;
                if (!P1ab2CD) {
                    ui->player1_ab2CD->clear();
                } else {
                    ui->player1_ab2CD->setText(QString::number(P1ab2CD));
                }
            } else {
                P1ab2used = false;
            }

            if (P1ab3CD && !P1ab3used) {
                P1ab3CD--;
                if (!P1ab3CD) {
                    ui->player1_ab3CD->clear();
                } else {
                    ui->player1_ab3CD->setText(QString::number(P1ab3CD));
                }
            } else {
                P1ab3used = false;
            }

            if (!(heroes[1].getIsSilenced() || heroes[1].getIsStanned())) {
                if (!P2ab1CD){
                    ui->player2_useAb1->setEnabled(true);
                }
                if (!P2ab2CD) {
                    ui->player2_useAb2->setEnabled(true);
                }
                if (!P2ab3CD) {
                    ui->player2_useAb3->setEnabled(true);
                }
            }

            ui->player1_useAb1->setEnabled(false);
            ui->player1_useAb2->setEnabled(false);
            ui->player1_useAb3->setEnabled(false);

            ui->player1_useItem1->setEnabled(false);
            ui->player1_useItem2->setEnabled(false);
            ui->player1_useItem3->setEnabled(false);

            if (heroes[1].items.size() >= 1) {
                ui->player2_useItem1->setEnabled(true);
                ui->player2_aboutItem1->setEnabled(true);
            }
            if (heroes[1].items.size() >= 2) {
                ui->player2_useItem2->setEnabled(true);
                ui->player2_aboutItem2->setEnabled(true);
            }
            if (heroes[1].items.size() == 3)  {
                ui->player2_useItem3->setEnabled(true);
                ui->player2_aboutItem3->setEnabled(true);
            }
        } else { // переключение очереди на первого игрока
            battleOrder = 0;

            if (heroes[1].getIsSilenced()) {
                heroes[1].setSilence(0);
                ui->player2_Status->clear();
            }
            if (heroes[1].getIsStanned()) {
                heroes[1].setStanned(0);
                ui->player2_Status->clear();
            }

            ui->queue->setText("Очередь " + selectedProfilesForGame[0]);

            if (heroes[0].getIsPeriodic()) {
                heroes[0].getDamage(heroes[0].getPeriodicDamage());
                ui->logs->setText(ui->logs->text()+selectedProfilesForGame[0]+" получает периодический урон в размере "+QString::number(heroes[0].getPeriodicDamage())+"\n");
                heroes[0].decreasePeriodic();
                ui->player1_HPInBattle->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
                ui->player1_HP->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
                if (heroes[0].getCurrentHP() <= 0) {
                    heroes[0].setCurrentHP(0);
                    winner(1);
                }
            }

            if (P2ab1CD && !P2ab1used) {
                P2ab1CD--;
                if (!P2ab1CD) {
                    ui->player2_ab1CD->clear();
                } else {
                    ui->player2_ab1CD->setText(QString::number(P2ab1CD));
                }
            } else {
                P2ab1used = false;
            }

            if (P2ab2CD && !P2ab2used) {
                P2ab2CD--;
                if (!P2ab2CD) {
                    ui->player2_ab2CD->clear();
                } else {
                    ui->player2_ab2CD->setText(QString::number(P2ab2CD));
                }
            } else {
                P2ab2used = false;
            }

            if (P2ab3CD && !P2ab3used) {
                P2ab3CD--;
                if (!P2ab3CD) {
                    ui->player2_ab3CD->clear();
                } else {
                    ui->player2_ab3CD->setText(QString::number(P2ab3CD));
                }
            } else {
                P2ab3used = false;
            }

            if (!(heroes[0].getIsSilenced() || heroes[0].getIsStanned())) {
                if (!P1ab1CD){
                    ui->player1_useAb1->setEnabled(true);
                }
                if (!P1ab2CD) {
                    ui->player1_useAb2->setEnabled(true);
                }
                if (!P1ab3CD) {
                    ui->player1_useAb3->setEnabled(true);
                }
            }

            ui->player2_useAb1->setEnabled(false);
            ui->player2_useAb2->setEnabled(false);
            ui->player2_useAb3->setEnabled(false);

            ui->player2_useItem1->setEnabled(false);
            ui->player2_useItem2->setEnabled(false);
            ui->player2_useItem3->setEnabled(false);

            if (heroes[0].items.size() >= 1) {
                ui->player1_useItem1->setEnabled(true);
                ui->player1_aboutItem1->setEnabled(true);
            }
            if (heroes[0].items.size() >= 2) {
                ui->player1_useItem2->setEnabled(true);
                ui->player1_aboutItem2->setEnabled(true);
            }
            if (heroes[0].items.size() == 3)  {
                ui->player1_useItem3->setEnabled(true);
                ui->player1_aboutItem3->setEnabled(true);
            }
        }
    }
}

void MainWindow::useItem(int player, int item, int enemy, int button) {
    int ind = heroes[player].items[item];

    if (ind == 0) {
        heroes[player].addHP(100);
        if (heroes[player].getCurrentHP()>heroes[player].getHealth()) {
            heroes[player].setCurrentHP(heroes[player].getHealth());
        }
        ui->logs->setText(ui->logs->text()+selectedProfilesForGame[player]+" восстановил 100 HP\n");
        if (player == 0) {
            ui->player1_HPInBattle->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
            ui->player1_HP->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
        } else {
            ui->player2_HPInBattle->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));
            ui->player2_HP->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));
        }
    } else if (ind == 1) {
        heroes[player].addMana(100);
        if (heroes[player].getCurrentMana()>heroes[player].getMana()) {
            heroes[player].setCurrentMana(heroes[player].getMana());
        }
        ui->logs->setText(ui->logs->text()+selectedProfilesForGame[player]+" восстановил 100 маны\n");
        if (player == 0) {
            ui->player1_ManaInBattle->setText(QString::number(heroes[0].getCurrentMana())+" / "+QString::number(heroes[0].getMana()));
            ui->player1_Mana->setText(QString::number(heroes[0].getCurrentMana())+" / "+QString::number(heroes[0].getMana()));
        } else {
            ui->player2_ManaInBattle->setText(QString::number(heroes[1].getCurrentMana())+" / "+QString::number(heroes[1].getMana()));
            ui->player2_Mana->setText(QString::number(heroes[1].getCurrentMana())+" / "+QString::number(heroes[1].getMana()));
        }
    } else if (ind == 2) {
        heroes[player].addHP(75);
        heroes[player].addMaxHP(75);
        ui->logs->setText(ui->logs->text()+selectedProfilesForGame[player]+" увеличил максимальное здоровье на 75\n");
        if (player == 0) {
            ui->player1_HPInBattle->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
            ui->player1_HP->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
        } else {
            ui->player2_HPInBattle->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));
            ui->player2_HP->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));
        }
    } else if (ind == 3) {
        heroes[player].addMana(75);
        heroes[player].addMaxMana(75);
        ui->logs->setText(ui->logs->text()+selectedProfilesForGame[player]+" увеличил максимальную ману на 75\n");
        if (player == 0) {
            ui->player1_ManaInBattle->setText(QString::number(heroes[0].getCurrentMana())+" / "+QString::number(heroes[0].getMana()));
            ui->player1_Mana->setText(QString::number(heroes[0].getCurrentMana())+" / "+QString::number(heroes[0].getMana()));
        } else {
            ui->player2_ManaInBattle->setText(QString::number(heroes[1].getCurrentMana())+" / "+QString::number(heroes[1].getMana()));
            ui->player2_Mana->setText(QString::number(heroes[1].getCurrentMana())+" / "+QString::number(heroes[1].getMana()));
        }
    } else if (ind == 4) {
        heroes[enemy].removeMana(100);
        ui->logs->setText(ui->logs->text()+selectedProfilesForGame[player]+" сжёг "+selectedProfilesForGame[enemy]+" 100 маны\n");
        if (heroes[enemy].getCurrentMana() < 0) {
            heroes[enemy].setCurrentMana(0);
        }
        if (enemy == 0) {
            ui->player1_ManaInBattle->setText(QString::number(heroes[0].getCurrentMana())+" / "+QString::number(heroes[0].getMana()));
            ui->player1_Mana->setText(QString::number(heroes[0].getCurrentMana())+" / "+QString::number(heroes[0].getMana()));
        } else {
            ui->player2_ManaInBattle->setText(QString::number(heroes[1].getCurrentMana())+" / "+QString::number(heroes[1].getMana()));
            ui->player2_Mana->setText(QString::number(heroes[1].getCurrentMana())+" / "+QString::number(heroes[1].getMana()));
        }
    } else if (ind == 5) {
        heroes[enemy].getDamage(100);
         ui->logs->setText(ui->logs->text()+selectedProfilesForGame[player]+" нанёс "+selectedProfilesForGame[enemy]+" 100 урона\n");
        if (heroes[enemy].getCurrentHP() < 0) {
            heroes[enemy].setCurrentHP(0);
            winner(player);
        }

        if (enemy == 0) {
            ui->player1_HPInBattle->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
            ui->player1_HP->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
        } else {
            ui->player2_HPInBattle->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));
            ui->player2_HP->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));
        }

    } else if (ind == 6) {
        heroes[player].addMana(250);
        heroes[player].addMaxMana(250);
        ui->logs->setText(ui->logs->text()+selectedProfilesForGame[player]+" увеличил максимальную ману на 250\n");
        if (player == 0) {
            ui->player1_ManaInBattle->setText(QString::number(heroes[0].getCurrentMana())+" / "+QString::number(heroes[0].getMana()));
            ui->player1_Mana->setText(QString::number(heroes[0].getCurrentMana())+" / "+QString::number(heroes[0].getMana()));
        } else {
            ui->player2_ManaInBattle->setText(QString::number(heroes[1].getCurrentMana())+" / "+QString::number(heroes[1].getMana()));
            ui->player2_Mana->setText(QString::number(heroes[1].getCurrentMana())+" / "+QString::number(heroes[1].getMana()));
        }
    } else if (ind == 7) {
        heroes[player].addHP(250);
        heroes[player].addMaxHP(250);
        ui->logs->setText(ui->logs->text()+selectedProfilesForGame[player]+" увеличил максимальное здоровье на 250\n");
        if (player == 0) {
            ui->player1_HPInBattle->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
            ui->player1_HP->setText(QString::number(heroes[0].getCurrentHP())+" / "+QString::number(heroes[0].getHealth()));
        } else {
            ui->player2_HPInBattle->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));
            ui->player2_HP->setText(QString::number(heroes[1].getCurrentHP())+" / "+QString::number(heroes[1].getHealth()));
        }
    } else if (ind == 8) {
        heroes[player].turnLinked();
        ui->logs->setText(ui->logs->text()+selectedProfilesForGame[player]+" использовал Linked sphere, следующее заклинание противника будет поглащено\n");
    } else if (ind == 9) {
        heroes[player].useKaya();
        ui->logs->setText(ui->logs->text()+selectedProfilesForGame[player]+" увеличил урон заклинаний на 15%\n");
    } else if (ind == 10) {
        heroes[player].setSilence(0);
        heroes[player].setStanned(0);
        heroes[player].setPeriodic(0);
        heroes[player].setPeriodicDamage(0);
        if (player == 0) {
            ui->player1_Status->clear();
            if (!P1ab1CD) {
                ui->player1_useAb1->setEnabled(true);
            }
            if (!P1ab2CD) {
                ui->player1_useAb2->setEnabled(true);
            }
            if (!P1ab3CD) {
                ui->player1_useAb3->setEnabled(true);
            }
        } else {
            ui->player2_Status->clear();
            if (!P2ab1CD) {
                ui->player2_useAb1->setEnabled(true);
            }
            if (!P2ab2CD) {
                ui->player2_useAb2->setEnabled(true);
            }
            if (!P2ab3CD) {
                ui->player2_useAb3->setEnabled(true);
            }
        }
        ui->logs->setText(ui->logs->text()+selectedProfilesForGame[player]+" сбросил все отрицательные эффекты\n");
    }

    if (ind != 8) {
        int sz1 = heroes[0].items.size();
        int sz2 = heroes[1].items.size();
        if (button == 1) {
            if (player == 0) {
                heroes[0].items.erase(heroes[0].items.begin());
                updateInvent();
            } else {
                heroes[1].items.erase(heroes[1].items.begin());
                updateInvent();
            }
        } else if (button == 2) {
            if (player == 0) {
                heroes[0].items.erase(heroes[0].items.begin() + 1);
                updateInvent();
            } else {
                heroes[1].items.erase(heroes[1].items.begin() + 1);
                updateInvent();
            }
        } else {
            if (player == 0) {
                heroes[0].items.erase(heroes[0].items.begin() + 2);
                updateInvent();
            } else {
                heroes[1].items.erase(heroes[1].items.begin() + 2);
                updateInvent();
            }
        }
        if (player == 0) {
            if (2 >= sz1) {
                ui->player1_useItem3->setEnabled(false);
            }
            if (1 >= sz1) {
                ui->player1_useItem2->setEnabled(false);
            }
            if (0 >= sz1) {
                ui->player2_useItem1->setEnabled(false);
            }
        } else {
            if (2 >= sz2) {
                ui->player2_useItem3->setEnabled(false);
            }
            if (1 >= sz2) {
                ui->player2_useItem2->setEnabled(false);
            }
            if (0 >= sz2) {
                ui->player2_useItem1->setEnabled(false);
            }
        }
    }
}


void MainWindow::on_player1_useItem1_clicked()
{
    useItem(0, 0, 1, 1);
}


void MainWindow::on_player1_useItem2_clicked()
{
    useItem(0, 1, 1, 2);
}


void MainWindow::on_player1_useItem3_clicked()
{
    useItem(0, 2, 1, 3);
}


void MainWindow::on_player2_useItem1_clicked()
{
    useItem(1, 0, 0, 1);
}


void MainWindow::on_player2_useItem2_clicked()
{
    useItem(1, 1, 0, 2);
}


void MainWindow::on_player2_useItem3_clicked()
{
    useItem(1, 2, 0, 3);
}

void MainWindow::updateInvent() {
    int sz = heroes[0].items.size();

    int ind;
    if (2 < sz) {
        ind = heroes[0].items[2];
        ui->player1_item3inShop->setPixmap(items[ind].image);
        ui->player1_about3_buttonInShop->setEnabled(true);
        ui->player1_item3->setPixmap(items[ind].image);
        ui->player1_about3_button->setEnabled(true);
        ui->player1_item3inBattle->setPixmap(items[ind].image);
        ui->player1_aboutItem3->setEnabled(true);
    } else {
        ui->player1_item3inShop->setText("Пусто");
        ui->player1_about3_buttonInShop->setEnabled(false);
        ui->player1_item3->setText("Пусто");
        ui->player1_about3_button->setEnabled(false);
        ui->player1_item3inBattle->setText("Пусто");
        ui->player1_aboutItem3->setEnabled(false);
        ui->player1_useItem3->setEnabled(false);
    }


    if (1 < sz) {
        ind = heroes[0].items[1];
        ui->player1_item2inShop->setPixmap(items[ind].image);
        ui->player1_about2_buttonInShop->setEnabled(true);
        ui->player1_item2->setPixmap(items[ind].image);
        ui->player1_about2_button->setEnabled(true);
        ui->player1_item2inBattle->setPixmap(items[ind].image);
        ui->player1_aboutItem2->setEnabled(true);
    } else {
        ui->player1_item2inShop->setText("Пусто");
        ui->player1_about2_buttonInShop->setEnabled(false);
        ui->player1_item2->setText("Пусто");
        ui->player1_about2_button->setEnabled(false);
        ui->player1_item2inBattle->setText("Пусто");
        ui->player1_aboutItem2->setEnabled(false);
        ui->player1_useItem2->setEnabled(false);
    }


    if (0 < sz) {
        ind = heroes[0].items[0];
        ui->player1_item1inShop->setPixmap(items[ind].image);
        ui->player1_about1_buttonInShop->setEnabled(true);
        ui->player1_item1->setPixmap(items[ind].image);
        ui->player1_about1_button->setEnabled(true);
        ui->player1_item1inBattle->setPixmap(items[ind].image);
        ui->player1_aboutItem1->setEnabled(true);
    } else {
        ui->player1_item1inShop->setText("Пусто");
        ui->player1_about1_buttonInShop->setEnabled(false);
        ui->player1_item1->setText("Пусто");
        ui->player1_about1_button->setEnabled(false);
        ui->player1_item1inBattle->setText("Пусто");
        ui->player1_aboutItem1->setEnabled(false);
        ui->player1_useItem1->setEnabled(false);
    }


    // для второго игрока

    sz = heroes[1].items.size();

    if (2 < sz) {
        ind = heroes[1].items[2];
        ui->player2_item3inShop->setPixmap(items[ind].image);
        ui->player2_about3_buttonInShop->setEnabled(true);
        ui->player2_item3->setPixmap(items[ind].image);
        ui->player2_about3_button->setEnabled(true);
        ui->player2_item3inBattle->setPixmap(items[ind].image);
        ui->player2_aboutItem3->setEnabled(true);
    } else {
        ui->player2_item3inShop->setText("Пусто");
        ui->player2_about3_buttonInShop->setEnabled(false);
        ui->player2_item3->setText("Пусто");
        ui->player2_about3_button->setEnabled(false);
        ui->player2_item3inBattle->setText("Пусто");
        ui->player2_aboutItem3->setEnabled(false);
        ui->player2_useItem3->setEnabled(false);
    }

    if (1 < sz) {
        ind = heroes[1].items[1];
        ui->player2_item2inShop->setPixmap(items[ind].image);
        ui->player2_about2_buttonInShop->setEnabled(true);
        ui->player2_item2->setPixmap(items[ind].image);
        ui->player2_about2_button->setEnabled(true);
        ui->player2_item2inBattle->setPixmap(items[ind].image);
        ui->player2_aboutItem2->setEnabled(true);
    } else {
        ui->player2_item2inShop->setText("Пусто");
        ui->player2_about2_buttonInShop->setEnabled(false);
        ui->player2_item2->setText("Пусто");
        ui->player2_about2_button->setEnabled(false);
        ui->player2_item2inBattle->setText("Пусто");
        ui->player2_aboutItem2->setEnabled(false);
        ui->player2_useItem2->setEnabled(false);
    }

    if (0 < sz) {
        ind = heroes[1].items[0];
        ui->player2_item1inShop->setPixmap(items[ind].image);
        ui->player2_about1_buttonInShop->setEnabled(true);
        ui->player2_item1->setPixmap(items[ind].image);
        ui->player2_about1_button->setEnabled(true);
        ui->player2_item1inBattle->setPixmap(items[ind].image);
        ui->player2_aboutItem1->setEnabled(true);
    } else {
        ui->player2_item1inShop->setText("Пусто");
        ui->player2_about1_buttonInShop->setEnabled(false);
        ui->player2_item1->setText("Пусто");
        ui->player2_about1_button->setEnabled(false);
        ui->player2_item1inBattle->setText("Пусто");
        ui->player2_useItem1->setEnabled(false);
        ui->player2_aboutItem1->setEnabled(false);
        ui->player2_useItem1->setEnabled(false);
    }
}

void MainWindow::winner(int win) {
    ui->winnerName->setText("Победитель: "+selectedProfilesForGame[win]);
    ui->winnerHero->setText("Играяя за "+heroes[win].getName());

    QMovie *hero = new QMovie(heroes[win].getImage());
    ui->winerHeroGIf->setScaledContents(true);
    ui->winerHeroGIf->setMovie(hero);
    hero->start();

    ui->winnerHP->setText(QString::number(heroes[win].getCurrentHP())+" / "+QString::number(heroes[win].getHealth()));
    ui->winnerMana->setText(QString::number(heroes[win].getCurrentMana())+" / "+QString::number(heroes[win].getMana()));

    ui->stackedWidget->setCurrentWidget(ui->winner);

    currentPlayers[win]->addGame();
    currentPlayers[win]->addWin();

    if (win == 0) {
        currentPlayers[1]->addGame();
    } else {
        currentPlayers[0]->addGame();
    }

    rewriteFile();
    readFromFile();
}


void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->startMenu);
    clearGame();
}


void MainWindow::on_sort_button_clicked()
{

    if (sortState == 0) {
        tempPlayers.clear();
        for (Player* player : players) {
            tempPlayers.push_back(new Player(*player));
        }
        shellSortDescending();
        sortState = 1;
        ui->sort_button->setText("Сортировать (по возрастанию)");
    } else if (sortState == 1) {
        shellSortAscending();
        sortState = 2;
        ui->sort_button->setText("Отменить сортировку");
    } else {
        players.clear();
        for (Player* tempPlayer : tempPlayers) {
            players.push_back(new Player(*tempPlayer));
        }
        sortState = 0;
        ui->sort_button->setText("Сортировать (по убыванию)");
    }

    rewriteFile();
    readFromFile();
}


void MainWindow::shellSortDescending()
{
    int n = players.size();


    for (int gap = n/2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < n; i += 1)
        {

            Player* temp = players[i];

            int j;
            for (j = i; j >= gap && players[j - gap]->winRate() < temp->winRate(); j -= gap)
                players[j] = players[j - gap];

            players[j] = temp;
        }
    }

}

void MainWindow::shellSortAscending() {
    int n = players.size();

    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            Player* temp = players[i];

            int j;
            // Измените условие здесь, чтобы сортировать по возрастанию
            for (j = i; j >= gap && players[j - gap]->winRate() > temp->winRate(); j -= gap)
                players[j] = players[j - gap];

            players[j] = temp;
        }
    }
}

void MainWindow::clearGame() {
    selectedProfilesForGame.clear();
    currentShop.clear();
    currentPlayers.clear();
    tempPlayers.clear();

    timer->stop();


    currentHeroChoosing = 0;
    currentChoosing = 0;
    stageCount = 0;


    rect1->stopPaint();
    delete rect1;
    rect1 = nullptr;

    rect2->stopPaint();
    delete rect2;
    rect2 = nullptr;
    animationGroup1 = nullptr;
    animationGroup2 = nullptr;
    //isFinished1 = false;
    //isFinished2 = false;
    farmStageFinished = false;
    goldFarm = 100;
    player1Received = 0;
    player2Received = 0;
    yellowRectSize = 70;
    currentlyBuying = 0;
    currentRound = 1;
    rounds = 2;
    P1ab1CD = 0;
    P1ab2CD = 0;
    P1ab3CD = 0;

    P1ab1used = false;
    P1ab2used = false;
    P1ab3used = false;

    P2ab1CD = 0;
    P2ab2CD = 0;
    P2ab3CD = 0;

    P2ab1used = false;
    P2ab2used = false;
    P2ab3used = false;

    battleOrder = 0;

    int rowCount = ui->tableWidget_2->rowCount();
    int columnCount = ui->tableWidget_2->columnCount();

    for (int row = 0; row < rowCount; ++row)
    {
        for (int column = 0; column < columnCount; ++column)
        {
            QTableWidgetItem* item = ui->tableWidget_2->item(row, column);

            if (item != nullptr)
            {
                item->setFlags(item->flags() | Qt::ItemIsEnabled);
                item->setForeground(Qt::black);
            }
        }
    }

    ui->LinaChoosed->hide();
    ui->PhoenixChoosed->hide();
    ui->VenomancerChoosed->hide();
    ui->DRChoosed->hide();
    ui->DKChoosed->hide();

    ui->pushButton_3->setEnabled(true);
    ui->PhoenixChoose_button->setEnabled(true);
    ui->VenomancerChoose_button->setEnabled(true);
    ui->DRChoose_button->setEnabled(true);
    ui->DKChoose_button->setEnabled(true);

    if (heroes.size() >= 1) {
        heroes[0].items.clear();
    }
    if  (heroes.size() == 2) {
        heroes[1].items.clear();
    }
    updateInvent();
    heroes.clear();


    isFarmStage = false;
    isStageAnnouncement = false;
}

void MainWindow::on_player1Sur_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Подтверждение", selectedProfilesForGame[0]+", вы уверены, что хотите сдаться? Игра будет засчитана как поражение.",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        winner(1);
    } else {
        return;
    }
}


void MainWindow::on_player2Sur_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Подтверждение", selectedProfilesForGame[1]+", вы уверены, что хотите сдаться? Игра будет засчитана как поражение.",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        winner(0);
    } else {
        return;
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Подтверждение", selectedProfilesForGame[0]+", вы уверены, что хотите сдаться? Игра будет засчитана как поражение.",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        winner(1);
    } else {
        return;
    }
}


void MainWindow::on_pushButton_13_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Подтверждение", selectedProfilesForGame[1]+", вы уверены, что хотите сдаться? Игра будет засчитана как поражение.",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        winner(0);
    } else {
        return;
    }
}


void MainWindow::on_player1_aboutItem1_clicked()
{
    aboutItem(0, 0);
}


void MainWindow::on_player1_aboutItem2_clicked()
{
    aboutItem(0, 1);
}


void MainWindow::on_player1_aboutItem3_clicked()
{
    aboutItem(0, 2);
}


void MainWindow::on_player2_aboutItem1_clicked()
{
    aboutItem(1, 0);
}


void MainWindow::on_player2_aboutItem2_clicked()
{
    aboutItem(1, 1);
}


void MainWindow::on_player2_aboutItem3_clicked()
{
    aboutItem(1, 2);
}

void MainWindow::aboutItem(int player, int item) {
    int ind = heroes[player].items[item];
    QMessageBox details;

    details.setWindowTitle(items[ind].name);

    QPixmap pixmap(items[ind].image);
    details.setIconPixmap(pixmap.scaled(64, 64, Qt::KeepAspectRatio));

    details.setText(items[ind].desc+"\nСтоимость: "+QString::number(items[ind].cost));

    details.exec();
}

void MainWindow::on_player1_about1_button_clicked()
{
    aboutItem(0, 0);
}


void MainWindow::on_player1_about2_button_clicked()
{
    aboutItem(0, 1);
}


void MainWindow::on_player1_about3_button_clicked()
{
    aboutItem(0, 2);
}


void MainWindow::on_player2_about1_button_clicked()
{
    aboutItem(1, 0);
}


void MainWindow::on_player2_about2_button_clicked()
{
    aboutItem(1, 1);
}


void MainWindow::on_player2_about3_button_clicked()
{
    aboutItem(1, 2);
}

void MainWindow::on_pushButton_9_clicked()
{
    if (heroes[1].getName() == "Lina") {
        linaDetails.exec();
    } else if (heroes[1].getName() == "Phoenix") {
        phoenixDetails.exec();
    } else if (heroes[1].getName() == "Venomancer") {
        venomancerDetails.exec();
    } else if (heroes[1].getName() == "Drow Ranger") {
        drowRangerDetails.exec();
    } else {
        dragonKnightDetails.exec();
    }
}

