#include "mainwindow.h"
#include "building.h"
#include "qlabel.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QStackedWidget>
#include <QMovie>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene())
    , scene2(new QGraphicsScene())
    , coinSimulator(new CoinSimulation())
{
    ui->setupUi(this);
    connect(ui->simulateButton, &QPushButton::clicked, this, &MainWindow::simulateCoinToss);
    ui->graphicsView->setScene(scene);
    ui->graphicsView_2->setScene(scene2);
//дизайн--------------------------------------------------------------------------------------------
    // Создаем объект QMovie и загружаем анимацию
    QMovie *movie = new QMovie("/home/ubuntu/Рабочий стол/курсач/картинки/loading-48.gif");

    // Находим QLabel по его имени
    QLabel *label = findChild<QLabel*>("animatedLabel");

    // Проверяем, что QLabel найден
    if (label)
    {
        // Устанавливаем анимацию для QLabel
        label->setMovie(movie);
        // Запускаем анимацию

        movie->start();
    }
QLabel *label_2 = findChild<QLabel*>("label_2");
if (label_2)
{
    // Создаем объект QMovie и загружаем первую анимацию
    QMovie *movie= new QMovie("/home/ubuntu/Рабочий стол/курсач/картинки/e02ce86bcfd6d1d6c2f775afb3ec8c01_w200.gif");
    // Устанавливаем анимацию для QLabel
    label_2->setMovie(movie);
    // Запускаем анимацию
    movie->start();
}
else
{
    qDebug() << "Error: QLabel 1 not found!";
}
    QStringList colorNames = { "Орел график 1", "Решка график 2", "Орел график 2","Решка график 1" }; // Пример списка цветов
    QListWidget *listWidget = ui->listWidget_4;

    for (int i = 0; i < colorNames.size(); ++i) {
        QString colorName = colorNames.at(i);
        QListWidgetItem *item = new QListWidgetItem(colorName, listWidget);

        // Создаем квадрат цвета слева от текста
        QColor color;
        if (colorName == "Орел график 1") {
            color = Qt::red;
        } else if (colorName == "Решка график 2") {
            color = Qt::green;
        } else if (colorName == "Орел график 2") {
            color = Qt::blue;
        }
        else if (colorName == "Решка график 1") {
            color = Qt::white;
        }
        QPixmap pixmap(20, 20);
        pixmap.fill(color);
        QIcon icon(pixmap);
        item->setIcon(icon);
    }

    // Изменяем стиль элементов QListWidget
    QStringList styleSheet;
    styleSheet << "QListWidget_3::item { padding-left: 20px; }"; // Устанавливаем отступ слева
    listWidget->setStyleSheet(styleSheet.join("\n"));
//---------------------------------------------------------------------------------------------------------
    ui->numTossesEdit->setPlaceholderText("Число подбросов");
    ui->tiltEdit->setPlaceholderText("Угол броска");
    ui->forceEdit->setPlaceholderText("Сила броска");
    ui->massEdit->setPlaceholderText("Масса");
    connect(ui->towergame, SIGNAL(clicked()), this, SLOT(startGame()));
    srand(time(nullptr));
 //---------------------------------------------------------------------------------------------------------
    // Создаем новую сцену
    scene3 = new QGraphicsScene(this);

    // Добавляем сцену в QGraphicsView
    ui->graphicsView_3->setScene(scene3);

    // Инициализируем сцену
    setupScene();

    // Устанавливаем начальное количество денег
    initialMoney = 15000;
    money = initialMoney;

    // Выводим информацию о деньгах в QLabel
    ui->moneyLabel->setText(QString("Деньги: %1 $").arg(money));
    updatePopulationLabel();

    randomPopulation = QRandomGenerator::global()->bounded(1600, 2000);

    ui->victorywinLabel->setText(QString("Для победы нужно: %1 чел").arg(randomPopulation));

    scene4 = new QGraphicsScene();
    ui->graphicsView_4->setScene(scene4);
    // Добавляем поле для боулинга
    addBowlingField();
    totalPinsKnockedDownOverall = 0;
    totalThrows = 0;
    firstThrow = true;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete scene2;
    delete scene3;
    delete scene4;
    delete coinSimulator;
}
void MainWindow::on_Start_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_comboBox_activated(int index)
{
    if (index == 1) {
        ui->stackedWidget->setCurrentWidget(ui->page_3);
    }
    if(index==2){

         ui->stackedWidget->setCurrentWidget(ui->page_4);
    }
    if(index==3){

         ui->stackedWidget->setCurrentWidget(ui->page_5);
    }
    if(index==4){

        ui->stackedWidget->setCurrentWidget(ui->page_6);
    }
}
//монета------------------------------------------------------------------------
void MainWindow::simulateCoinToss() {
    // Получаем значения из всех QLineEdit
    QString numTossesStr = ui->numTossesEdit->text();
    QString tiltStr = ui->tiltEdit->text();
    QString forceStr = ui->forceEdit->text();
    QString massStr = ui->massEdit->text();

    // Проверяем, что все значения введены
    if (numTossesStr.isEmpty() || tiltStr.isEmpty() || forceStr.isEmpty() || massStr.isEmpty()) {
        QMessageBox::warning(this, "Недостаточно данных", "Пожалуйста, заполните все поля перед запуском симуляции.");

        return;
    }

    // Проверяем, что все значения являются числами
    bool ok;
    int numTosses = numTossesStr.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите числовое значение для количества подбросов.");
         ui->numTossesEdit->clear();
        return;
    }
    double tilt = tiltStr.toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите числовое значение для угла броска.");
        ui->tiltEdit->clear();
        return;
    }
    double force = forceStr.toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите числовое значение для силы броска.");
        ui->forceEdit->clear();
        return;
    }
    double mass = massStr.toDouble(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Ошибка", "Пожалуйста, введите числовое значение для массы.");
        ui->massEdit->clear();
        return;
    }

    // Проверяем, что количество подбросов находится в допустимом диапазоне
    if (numTosses <= 0 || numTosses > 9999) {
        QMessageBox::warning(this, "Неверное значение", "Пожалуйста, введите число от 1 до 9999 для количества подбросов.");
        ui->numTossesEdit->clear();
        return;
    }

    // Все проверки пройдены, можно выполнять симуляцию
    plotCoinTossProbabilityGraph(numTosses, tilt, force, mass);

    double probabilityOfHeads = coinSimulator->simulateCoinTossProbability(tilt, numTosses, force, mass);
    double probabilityOfTails = 1.0 - probabilityOfHeads;

    ui->resultsTextEdit->clear();
    ui->resultsTextEdit->append("Результаты бросков монеты:");
    ui->resultsTextEdit->append(QString("Вероятность выпадения орла: %1").arg(probabilityOfHeads));
    ui->resultsTextEdit->append(QString("Вероятность выпадения решки: %1").arg(probabilityOfTails));

    plotForceProbabilityGraph(numTosses, tilt, mass);
}
void MainWindow::plotCoinTossProbabilityGraph(int maxTosses, double tilt, double force, double mass) {
    // Очистка сцены от предыдущих графиков
    scene->clear();



    // Создание объекта для хранения предыдущей точки графика
    QPointF prevPointHeads;
    QPointF prevPointTails;

    // Вычисление вероятности для каждого количества подбросов и построение графика
    for (int numTosses = 1; numTosses <= maxTosses; ++numTosses) {
        double probabilityOfHeads = coinSimulator->simulateCoinTossProbability(tilt, numTosses, force, mass);
        double probabilityOfTails = 1.0 - probabilityOfHeads;

        // Расчет координат точек для текущего количества подбросов
        double x = numTosses * 10; // Произвольный масштаб для x
        double yHeads = probabilityOfHeads * 100; // Произвольный масштаб для y
        double yTails = probabilityOfTails * 100; // Произвольный масштаб для y

        // Создание новых точек графика для орла и решки
        QPointF currentPointHeads(x, yHeads);
        QPointF currentPointTails(x, yTails);

        // Построение линий между текущими и предыдущими точками графика для орла
        if (!prevPointHeads.isNull()) {
            scene->addLine(QLineF(prevPointHeads, currentPointHeads), QPen(Qt::blue));
        }

        // Построение линий между текущими и предыдущими точками графика для решки
        if (!prevPointTails.isNull()) {
            scene->addLine(QLineF(prevPointTails, currentPointTails), QPen(Qt::white));
        }

        // Сохранение текущих точек в качестве предыдущих для следующей итерации
        prevPointHeads = currentPointHeads;
        prevPointTails = currentPointTails;
    }
}
void MainWindow::plotForceProbabilityGraph(int maxTosses, double tilt, double mass) {
    // Очистка сцены от предыдущих графиков
    scene2->clear();

    // Масштабирование для X и Y
    double xScale = 100; // Масштаб по оси X
    double yScale = 100; // Масштаб по оси Y

    // Смещение для X и Y
    double xOffset = 50; // Смещение по оси X
    double yOffset = 250; // Смещение по оси Y

    // Создание объекта для хранения предыдущей точки графика
    QPointF prevPointHeads;
    QPointF prevPointTails;

    // Вычисление силы и вероятности для каждого количества подбросов и построение графика
    for (int numTosses = 1; numTosses <= maxTosses; ++numTosses) {
        double force = numTosses; // Произвольное значение силы
        double probabilityOfHeads = coinSimulator->simulateCoinTossProbability(tilt, numTosses, force, mass); // Вероятность выпадения орла
        double probabilityOfTails = 1.0 - probabilityOfHeads; // Вероятность выпадения решки

        // Расчет координат точек для текущего значения силы и вероятности с учетом масштаба и смещения для орла
        double xHeads = force * xScale + xOffset; // Значение силы с учетом масштаба и смещения по оси X для орла
        double yHeads = probabilityOfHeads * yScale + yOffset; // Вероятность выпадения орла с учетом масштаба и смещения по оси Y для орла

        // Расчет координат точек для текущего значения силы и вероятности с учетом масштаба и смещения для решки
        double xTails = force * xScale + xOffset; // Значение силы с учетом масштаба и смещения по оси X для решки
        double yTails = probabilityOfTails * yScale + yOffset; // Вероятность выпадения решки с учетом масштаба и смещения по оси Y для решки

        // Создание новых точек графика для орла и для решки
        QPointF currentPointHeads(xHeads, yHeads);
        QPointF currentPointTails(xTails, yTails);

        // Построение линий между текущими и предыдущими точками графика для орла
        if (!prevPointHeads.isNull()) {
            scene2->addLine(QLineF(prevPointHeads, currentPointHeads), QPen(Qt::red));
        }

        // Построение линий между текущими и предыдущими точками графика для решки
        if (!prevPointTails.isNull()) {
            scene2->addLine(QLineF(prevPointTails, currentPointTails), QPen(Qt::green));
        }

        // Сохранение текущих точек в качестве предыдущих для следующей итерации
        prevPointHeads = currentPointHeads;
        prevPointTails = currentPointTails;
    }
}
void MainWindow::on_back_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
//для игры статегической---------------------------------------------
void MainWindow::on_back_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::startGame()
{
    // Получим текст из поля ввода количества шагов
    QString stepText = ui->stepEdit->text().trimmed(); // Уберем лишние пробелы в начале и конце

    // Проверим, не пустое ли поле ввода
    if (stepText.isEmpty()) {
        QMessageBox::critical(this, "Ошибка", "Пожалуйста, введите количество шагов.");
        return;
    }

    // Создадим валидатор, чтобы проверить, является ли ввод целым числом
    QIntValidator validator;
    int pos = 0; // Позиция первого недопустимого символа
    if (validator.validate(stepText, pos) != QValidator::Acceptable) {
        QMessageBox::critical(this, "Ошибка", "Пожалуйста, введите целочисленное значение.");
        // Очистим поле ввода
        ui->stepEdit->clear();
        return;
    }
    // Преобразуем текст в целое число
    numEvents = stepText.toInt();
    // Увеличиваем счетчик игр
    gameCount++;

    // Выводим номер текущей игры в textEdit
    ui->towerinfoEdit->append("Игра " + QString::number(gameCount));
    // Инициализируем здоровье башен
    playerFortressStrength = getRandomNumber(minFortressStrength, maxFortressStrength);
    computerFortressStrength = getRandomNumber(minFortressStrength, maxFortressStrength);

    for (int i = 0; i < numEvents; ++i) {
        // Показываем текущее состояние игры
        ui->towerinfoEdit->append("Шаг " + QString::number(i + 1) + ": Здоровье вашей башни: " + QString::number(playerFortressStrength));
        ui->towerinfoEdit->append("Шаг " + QString::number(i + 1) + ": Здоровье компьютерной башни: " + QString::number(computerFortressStrength));

        // Игрок делает свой ход
        playerAction();

        // Компьютер делает свой ход
        int computerDefenseStrategy = getDefenseStrategy();
        int computerAttackStrategy = getAttackStrategy();
        int computerAction = getComputerAction(computerDefenseStrategy, computerAttackStrategy);
        if (computerAction == 1) {
            attackRandomEnemy(playerFortressStrength);
        } else {
            if (!defendFortress(computerDefenseStrategy, computerFortressStrength)) {
                // Если оборона не удалась, выводим сообщение
                ui->towerinfoEdit->append("Компьютер не смог успешно защитить свою башню.");
            }
        }

        // Проверяем, не разрушена ли башня игрока или компьютера
        if (playerFortressStrength <= 0 || computerFortressStrength <= 0) {
            break;
        }
    }

    // Выводим результаты
    ui->towerinfoEdit->append("Количество успешных оборон вашей башни: " + QString::number(numEvents - playerFortressStrength) + "/" + QString::number(numEvents));
    ui->towerinfoEdit->append("Количество успешных оборон компьютерной башни: " + QString::number(numEvents - computerFortressStrength) + "/" + QString::number(numEvents));
    QString resultMessage = determineResult(numEvents - playerFortressStrength, numEvents - computerFortressStrength);
    ui->towerinfoEdit->append(resultMessage);
    QMessageBox::information(this, "Результат", resultMessage);

    // Выводим вероятности победы при атаке и защите
    ui->towerinfoEdit->append("Вероятность победы при атаке: " + QString::number(attackWinProbability));
    ui->towerinfoEdit->append("Вероятность победы при защите: " + QString::number(defenseWinProbability));
}
void MainWindow::playerAction()
{
    // Получаем выбранные стратегии укрепления крепости и атаки
    int defenseStrategy = getDefenseStrategy();
    int attackStrategy = getAttackStrategy();

    // Выполняем атаки компьютера (случайно)
    int computerAction = getComputerAction(defenseStrategy, attackStrategy);
    if (computerAction == 1) {
        attackRandomEnemy(computerFortressStrength);
    } else {
        if (!defendFortress(defenseStrategy, playerFortressStrength)) {
            // Если оборона не удалась, выводим сообщение
            ui->towerinfoEdit->append("Вы не смогли успешно защитить свою башню.");
        }
    }
}

int MainWindow::getRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void MainWindow::attackRandomEnemy(int& fortressStrength)
{

        // Выбираем случайный тип атаки
        int attackType = getRandomNumber(1, 5); // Увеличили количество стратегий атаки до 5
        switch (attackType) {
        case 1:
            attackLightInfantry(fortressStrength);
            break;
        case 2:
            attackHeavyCavalry(fortressStrength);
            break;
        case 3:
            attackMagic(fortressStrength);
            break;
        case 4:
            attackArchers(fortressStrength); // Новая стратегия атаки: лучники
            break;
        case 5:
            attackCatapults(fortressStrength); // Новая стратегия атаки: катапульты
            break;
        }

        // Обновляем вероятности после каждой атаки
        int defenseStrategy = getDefenseStrategy();
        int attackStrategy = getAttackStrategy();
        updateProbabilities(playerFortressStrength, computerFortressStrength, defenseStrategy, attackStrategy);
    }

void MainWindow::attackLightInfantry(int& fortressStrength)
{
    // Атака легкой пехоты
    int damage = getRandomNumber(10, 30);
    fortressStrength -= damage;
    ui->towerinfoEdit->append("Нападение легкой пехоты: -" + QString::number(damage) + " ед. здоровья у крепости");
}

void MainWindow::attackHeavyCavalry(int& fortressStrength)
{
    // Атака тяжелой кавалерии
    int damage = getRandomNumber(30, 50);
    fortressStrength -= damage;
    ui->towerinfoEdit->append("Атака тяжелой кавалерии: -" + QString::number(damage) + " ед. здоровья у крепости");
}

void MainWindow::attackMagic(int& fortressStrength)
{
    // Использование магии
    int damage = getRandomNumber(50, 80);
    fortressStrength -= damage;
    ui->towerinfoEdit->append("Использование магии: -" + QString::number(damage) + " ед. здоровья у крепости");
}

void MainWindow::attackArchers(int& fortressStrength)
{
    // Атака лучниками
    int damage = getRandomNumber(20, 40);
    fortressStrength -= damage;
    ui->towerinfoEdit->append("Атака лучниками: -" + QString::number(damage) + " ед. здоровья у крепости");
}

void MainWindow::attackCatapults(int& fortressStrength)
{
    // Атака катапультами
    int damage = getRandomNumber(40, 60);
    fortressStrength -= damage;
    ui->towerinfoEdit->append("Атака катапультами: -" + QString::number(damage) + " ед. здоровья у крепости");
}

int MainWindow::getDefenseStrategy()
{
    // Получаем выбранную стратегию укрепления крепости
    QInputDialog dialog(this);
    dialog.setWindowTitle("Выбор стратегии укрепления крепости");
    dialog.setLabelText("Выберите стратегию укрепления крепости:\n1. Стандартная стратегия\n2. Агрессивная стратегия\n3. Оборонительная стратегия\n4. Стратегия бронирования\n5. Стратегия ловушек\n6. Стратегия мобильности");
    dialog.setInputMode(QInputDialog::IntInput);
    dialog.setIntRange(1, 6);
    dialog.setFixedSize(400, 200); // Установите размеры диалогового окна
    return dialog.exec();
}

int MainWindow::getAttackStrategy()
{
    // Получаем выбранную стратегию атаки
    QInputDialog dialog(this);
    dialog.setWindowTitle("Выбор стратегии атаки");
    dialog.setLabelText("Выберите стратегию атаки:\n1. Стандартная стратегия атаки\n2. Стратегия атаки огненными шарами\n3. Стратегия атаки призраками\n4. Стратегия атаки лучниками\n5. Стратегия атаки катапультами");
    dialog.setInputMode(QInputDialog::IntInput);
    dialog.setIntRange(1, 5);
    dialog.setFixedSize(400, 200); // Установите размеры диалогового окна
    return dialog.exec();
}
bool MainWindow::defendFortress(int defenseStrategy, int& fortressStrength)
{
    // Определяем, успешна ли оборона в соответствии с выбранной стратегией
    switch (defenseStrategy) {
    case 1: // Стандартная стратегия
        if (fortressStrength > 0) {
            fortressStrength += 10; // Увеличиваем здоровье башни на 10 единиц
            return true;
        }
        break;
    case 2: // Агрессивная стратегия
        if (fortressStrength > 50) {
            fortressStrength += 20; // Увеличиваем здоровье башни на 20 единиц
            return true;
        }
        break;
    case 3: // Оборонительная стратегия
        if (fortressStrength > 100) {
            fortressStrength += 30; // Увеличиваем здоровье башни на 30 единиц
            return true;
        }
        break;
    case 4: // Стратегия бронирования
        if (fortressStrength > 75) {
            fortressStrength += 25; // Увеличиваем здоровье башни на 25 единиц
            return true;
        }
        break;
    case 5: // Стратегия ловушек
        // Для этой стратегии всегда возвращаем true, так как здоровье башни не изменяется
        return true;
    case 6: // Стратегия мобильности
        if (fortressStrength > 25) {
            fortressStrength += 15; // Увеличиваем здоровье башни на 15 единиц
            return true;
        }
        break;
    default:
        return false;
    }
    return false;
}

QString MainWindow::determineResult(int playerDefenses, int computerDefenses)
{
    // Определяем результат игры
    if (playerDefenses > computerDefenses) {
        return "Вы выиграли!";
    } else if (playerDefenses < computerDefenses) {
        return "Вы проиграли...";
    } else {
        return "Ничья.";
    }
}
void MainWindow::updateProbabilities(int playerFortressStrength, int computerFortressStrength, int defenseStrategy, int attackStrategy) {
    // Вычисляем результат текущей игры
    bool playerWon = playerFortressStrength > computerFortressStrength;
    bool computerWon = computerFortressStrength > playerFortressStrength;

    // Создаем новый экземпляр GameResult
    GameResult result;
    result.playerWon = playerWon;
    result.computerWon = computerWon;

    // Добавляем результат текущей игры в историю
    gameResults.push_back(result);

    // Обновляем вероятности на основе истории результатов игры
    int numPlayerWins = 0;
    int numComputerWins = 0;
    for (const auto& gameResult : gameResults) {
        if (gameResult.playerWon) {
            numPlayerWins++;
        } else if (gameResult.computerWon) {
            numComputerWins++;
        }
    }

    // Обновляем вероятности на основе истории результатов игры
    attackWinProbability = static_cast<double>(numPlayerWins) / gameResults.size();
    defenseWinProbability = static_cast<double>(numComputerWins) / gameResults.size();
}

double MainWindow::computeAttackWinProbability() {
    return attackWinProbability;
}

double MainWindow::computeDefenseWinProbability() {
    return defenseWinProbability;
}

int MainWindow::getComputerAction(int defenseStrategy, int attackStrategy) {
    // Получаем текущее состояние игры
    int playerFortressStrength = getPlayerFortressStrength();
    int computerFortressStrength = getComputerFortressStrength();

    // Обновляем вероятности на основе текущего состояния игры
    updateProbabilities(playerFortressStrength, computerFortressStrength, defenseStrategy, attackStrategy);

    // Принимаем решение на основе вероятностей
    if (attackWinProbability > defenseWinProbability) {
        return 1; // Атака
    } else {
        return 2; // Защита
    }
}

int MainWindow::getPlayerFortressStrength() {
    return playerFortressStrength;
}

int MainWindow::getComputerFortressStrength() {
    return computerFortressStrength;
}
//игра эволюция городов-----------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::on_back_3_clicked()
{
 ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    // Получаем координаты нажатия мыши в системе координат представления
    QPoint viewPos = event->pos();

    // Проверяем, находится ли нажатие в пределах области сцены
    if (!ui->graphicsView_3->rect().contains(viewPos)) {
        QMainWindow::mousePressEvent(event);
        return;
    }

    // Преобразуем координаты представления в координаты сцены
    QPointF scenePos = ui->graphicsView_3->mapToScene(viewPos);

    // Получаем горизонтальную и вертикальную полосы прокрутки
    QScrollBar *horizontalScrollBar = ui->graphicsView_3->horizontalScrollBar();
    QScrollBar *verticalScrollBar = ui->graphicsView_3->verticalScrollBar();

    // Проверяем, существуют ли полосы прокрутки
    if (horizontalScrollBar && verticalScrollBar) {
        // Учитываем сдвиг сцены в области представления
        scenePos.rx() -= horizontalScrollBar->value();
        scenePos.ry() -= verticalScrollBar->value();
    }

    // Преобразуем координаты сцены в индексы строки и столбца ячейки
    int row = (scenePos.y() - startY) / (cellSize + spacing);
    int col = (scenePos.x() - startX) / (cellSize + spacing);

    // Проверяем, находится ли нажатие в пределах допустимой области сетки
    if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
        // Запоминаем выбранную ячейку для последующего использования при добавлении объекта
        selectedCell = QPoint(row, col);

        // Удаляем предыдущую подсветку (если есть)
        for (auto item : scene3->items()) {
            if (dynamic_cast<QGraphicsRectItem *>(item)) {
                scene3->removeItem(item);
                delete item;
            }
        }

        // Вычисляем координаты верхнего левого угла выбранной ячейки
        int x = startX + col * (cellSize + spacing);
        int y = startY + row * (cellSize + spacing);

        // Создаем прямоугольник для подсветки выбранной ячейки
        QGraphicsRectItem *highlight = new QGraphicsRectItem(x, y, cellSize, cellSize);
        highlight->setPen(QPen(Qt::red, 2));
        highlight->setBrush(Qt::NoBrush);
        scene3->addItem(highlight);
        ui->lineEdit->setText(QString("%1 %2").arg(row).arg(col));

    }

    // Передаем событие дальше для стандартной обработки
    QMainWindow::mousePressEvent(event);
}


void MainWindow::setupScene()
{
    // Очищаем сцену перед добавлением новых элементов
    scene3->clear();



    // Создаем прямоугольники и добавляем их на сцену
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            // Вычисляем координаты верхнего левого угла прямоугольника
            int x = startX + col * (cellSize + spacing);
            int y = startY + row * (cellSize + spacing);

            // Создаем закругленный прямоугольник и добавляем его на сцену
            QPainterPath path;
            path.addRoundedRect(x, y, cellSize, cellSize, cornerRadius, cornerRadius);
            scene3->addPath(path, QPen(Qt::black));
        }
    }
}

void MainWindow::on_addbuilding_clicked()
{

    QString buildingType = ui->comboBox_2->currentText();

    if (buildingType == "Постройки ") {
        QMessageBox::critical(this, "Ошибка", "Выберите конкретную постройку из списка.");
        return;
    }

    int col = selectedCell.y();
    int row = selectedCell.x();


    int x = startX + col * (cellSize + spacing);
    int y = startY + row * (cellSize + spacing);

    // Проверяем, что выбранная ячейка находится в пределах допустимой области 4x4
    if (row < 0 || row >= 4 || col < 0 || col >= 4) {
        QMessageBox::critical(this, "Ошибка", "Выбранная ячейка находится за пределами допустимой области.");
        return;
    }

    // Проверяем достаточно ли денег для постройки
    int buildingCost = getBuildingCost(buildingType);
    if (buildingCost > money) {
        QMessageBox::critical(this, "Ошибка", "Недостаточно средств для постройки этого здания.");
        return;
    }

    // Если в клетке уже есть здание, выводим сообщение об ошибке
    bool buildingExists = false;
    for (auto item : scene3->items()) {
        QPointF itemPos = item->pos();
        int itemRow = (itemPos.y() - startY) / (cellSize + spacing);
        int itemCol = (itemPos.x() - startX) / (cellSize + spacing);
        if (itemRow == row && itemCol == col && dynamic_cast<Building*>(item)) {
            buildingExists = true;
            break;
        }
    }

    if (buildingExists) {
        QMessageBox::critical(this, "Ошибка", "В выбранной клетке уже есть здание. Выберите другую клетку.");
        return;
    }

    x += cellSize / 2;
    y += cellSize / 2;

    Building *building = new Building(buildingType, getBuildingPopulation(buildingType), buildingCost);
    building->setPos(x, y);
    scene3->addItem(building);

    // Обновляем информацию о деньгах
    money -= buildingCost;

    // Выводим информацию о постройке в QTextEdit
    QString message = QString("Добавлено здание типа '%1' в ячейку [%2, %3]\nЧисленность: %4\n Цена: %5")
                          .arg(buildingType)
                          .arg(row)
                          .arg(col)
                          .arg(building->getPopulation())
                          .arg(building->getCost());
    ui->textEdit->append(message);

    // Обновляем информацию о деньгах в QLabel
    ui->moneyLabel->setText(QString("Деньги: %1 $").arg(money));

    simulateDisasterEvent();
    // Обновляем информацию о численности населения в QLabel
    updatePopulationLabel();

    if (getTotalPopulation() >= randomPopulation) {
        handleVictory(); // Обработка выигрыша и начало новой игры
        return;
    }

    if (buildingCost > money || money == 0) {
        gamesPlayed++; // Увеличиваем счетчик игр

        // Устанавливаем начальное количество денег на следующую игру
        money = initialMoney;

        int totalBuildings = getTotalBuildingsCount();
        int totalPopulation = getTotalPopulation();
        int totalCost = getTotalCityCost();

        QString cityInfo = QString("Игра #%1 завершена.\nГород состоит из %2 зданий\nОбщая численность населения: %3 чел\nОбщая стоимость города: %4 $\n")
                               .arg(gamesPlayed)
                               .arg(totalBuildings)
                               .arg(totalPopulation)
                               .arg(totalCost);
        ui->textEdit->append(cityInfo);
        QMessageBox::information(this, "Game over", cityInfo);
        removeAllBuildings();
        // Обновляем информацию о деньгах на случай, если они израсходованы
        ui->moneyLabel->setText(QString("Деньги: %1 $").arg(money));
        updatePopulationLabel();
    }
}
void MainWindow::handleVictory()
{
    gamesPlayed++; // Увеличение счетчика игр
    QString victoryMessage = QString("Вы выиграли! Город достиг заданного числа жителей. Игра #%1").arg(gamesPlayed);
    QMessageBox::information(this, "Поздравляем!", victoryMessage);
    ui->textEdit->append(victoryMessage);

    // Сброс текущего города и начало новой игры
    removeAllBuildings(); // Удаление всех зданий
    money = initialMoney; // Обнуление количества денег
    ui->moneyLabel->setText(QString("Деньги: %1 $").arg(money)); // Обновление информации о деньгах
    // Запуск процесса создания нового города
    setupScene(); // Создание нового города
    updatePopulationLabel(); // Обновление информации о численности населения
}
void MainWindow::updatePopulationLabel()
{
    int population = 0;
    for (auto item : scene3->items()) {
        Building *building = dynamic_cast<Building*>(item);
        if (building) {
            population += building->getPopulation();
        }
    }

    ui->populationLabel->setText(QString("Численность населения: %1 чел").arg(population));
}

int MainWindow::getBuildingPopulation(QString type)
{
    if (type == "House") {
        return 100; // Количество жителей в доме
    } else if (type == "Factory") {
        return 120; // Количество работников на фабрике
    } else if (type == "Store") {
        return 100; // Количество работников в магазине
    } else if (type == "Park") {
        return 80; // В парке нет постоянных жителей
    } else if (type == "Ski Resort") {
        return 300; // В горнолыжном курорте нет постоянных жителей
    } else if (type == "Forest") {
        return 90;
    }
    return 0; // Если тип неизвестен, возвращаем 0
}

int MainWindow::getBuildingCost(QString type)
{
    if (type == "House") {
        return 1000; // Стоимость постройки дома
    } else if (type == "Factory") {
        return 1700; // Стоимость постройки фабрики
    } else if (type == "Store") {
        return 1900; // Стоимость постройки магазина
    } else if (type == "Park") {
        return 1500; // Стоимость постройки парка
    } else if (type == "Ski Resort") {
        return 2000; // Стоимость постройки горнолыжного курорта
    } else if (type == "Forest") {
        return 0; // Лес строится бесплатно
    }
    return 0; // Если тип неизвестен, возвращаем 0
}
// Функция для подсчета общего количества зданий на сцене
int MainWindow::getTotalBuildingsCount()
{
    int count = 0;
    for (auto item : scene3->items()) {
        if (dynamic_cast<Building*>(item)) {
            count++;
        }
    }
    return count;
}

// Функция для подсчета общей численности населения
int MainWindow::getTotalPopulation()
{
    int totalPopulation = 0;
    for (auto item : scene3->items()) {
        Building *building = dynamic_cast<Building*>(item);
        if (building) {
            totalPopulation += building->getPopulation();
        }
    }
    return totalPopulation;
}

// Функция для подсчета общей стоимости города
int MainWindow::getTotalCityCost()
{
    int totalCost = 0;
    for (auto item : scene3->items()) {
        Building *building = dynamic_cast<Building*>(item);
        if (building) {
            totalCost += building->getCost();
        }
    }
    return totalCost;
}
void MainWindow::removeAllBuildings()
{
    QList<QGraphicsItem*> itemsToRemove;
    for (auto item : scene3->items()) {
        if (dynamic_cast<Building*>(item)) {
            itemsToRemove.append(item);
        }
    }
    for (auto item : itemsToRemove) {
        scene3->removeItem(item);
        delete item;
    }
}

void MainWindow::simulateDisasterEvent()
{
    // Генерируем случайное число от 0 до 1
    double randomValue = QRandomGenerator::global()->generateDouble();

    // Определяем текущее состояние города
    int currentState = 0; // Пусть по умолчанию это будет состояние "Без катастроф"

    // Определяем новое состояние города на основе вероятностей из матрицы переходов
    double sum = 0.0;
    for (int newState = 0; newState < 3; ++newState) {
        sum += transitionMatrix[currentState][newState];
        if (randomValue <= sum) {
            currentState = newState;
            break;
        }
    }

    // Теперь у нас есть новое состояние города, в котором произошла катастрофа
    if (currentState == 0) {
        // Без катастроф
        ui->textEdit->append("Катастрофы не произошло. Город в безопасности.\n");
    } else if (currentState == 1) {
        // Землетрясение
        QMessageBox::critical(this, "Информация о катастрофе", "Произошло землетрясение: жертв 80 чел");
        handleEarthquake();

    } else if (currentState == 2) {
        // Пожар
        QMessageBox::critical(this, "Информация о катастрофе", "Произошел пожар: жертв 50 чел");

        handleFire();
    }
}

void MainWindow::handleFire()
{
    QString position = ui->lineEdit->text();
    QStringList coordinates = position.split(" ");
    if (coordinates.size() == 2) {
        int row = coordinates[0].toInt();
        int col = coordinates[1].toInt();


        Building *selectedBuilding = nullptr;
        // Находим здание, которое находится в выбранной ячейке
        for (auto item : scene3->items()) {
            QPointF itemPos = item->pos();
            int itemRow = (itemPos.y() - startY) / (cellSize + spacing);
            int itemCol = (itemPos.x() - startX) / (cellSize + spacing);
            if (itemRow == row && itemCol == col && dynamic_cast<Building*>(item)) {
                selectedBuilding = dynamic_cast<Building*>(item);
                break;
            }
        }

        if (selectedBuilding) {
            // Уменьшаем численность населения в выбранном здании на 50 при пожаре
            int currentPopulation = selectedBuilding->getPopulation();
            int reducedPopulation = 50;
            selectedBuilding->setPopulation(currentPopulation - reducedPopulation);

            // Обновляем информацию о численности населения
            updatePopulationLabel();

            // Выводим информацию о пострадавшем здании в QTextEdit
            QString message = QString("При пожаре пострадало здание типа '%1' в ячейке [%2, %3].\nЧисло жертв: %4\n")
                                  .arg(selectedBuilding->getType())
                                  .arg(row)
                                  .arg(col)
                                  .arg(reducedPopulation);
            ui->textEdit->append(message);
        }
    }
}


void MainWindow::handleEarthquake()
{
    QString position = ui->lineEdit->text();
    QStringList coordinates = position.split(" ");
    if (coordinates.size() == 2) {
        int row = coordinates[0].toInt();
        int col = coordinates[1].toInt();



        Building *selectedBuilding = nullptr;
        // Находим здание, которое находится в выбранной ячейке
        for (auto item : scene3->items()) {
            QPointF itemPos = item->pos();
            int itemRow = (itemPos.y() - startY) / (cellSize + spacing);
            int itemCol = (itemPos.x() - startX) / (cellSize + spacing);
            if (itemRow == row && itemCol == col && dynamic_cast<Building*>(item)) {
                selectedBuilding = dynamic_cast<Building*>(item);
                break;
            }
        }

        if (selectedBuilding) {
            // Уменьшаем численность населения в выбранном здании на 80 при землетрясении
            int currentPopulation = selectedBuilding->getPopulation();
            int reducedPopulation = 80;
            selectedBuilding->setPopulation(currentPopulation - reducedPopulation);

            // Обновляем информацию о численности населения
            updatePopulationLabel();

            // Выводим информацию о пострадавшем здании в QTextEdit
            QString message = QString("При землетрясении пострадало здание типа '%1' в ячейке [%2, %3].\nЧисло жертв: %4\n")
                                  .arg(selectedBuilding->getType())
                                  .arg(row)
                                  .arg(col)
                                  .arg(reducedPopulation);
            ui->textEdit->append(message);
        }
    }
}
//боулинг------------------------------------------------------------------------------------------------------------------------------------
void MainWindow::addBowlingField()
{
    qreal pinMass = 2.0;
    // Создаем полигон, представляющий трапецию
    polygon1 << QPointF(197, 0) << QPointF(603, 0) << QPointF(800, 400) << QPointF(0, 400);

    // Создаем QGraphicsPolygonItem с трапецией
    QGraphicsPolygonItem* bowlingField = new QGraphicsPolygonItem(polygon1);
    scene4->addItem(bowlingField);

    // Рассчитываем позиции кеглей
    qreal trapezoidBase = 800; // Длина основания трапеции
    qreal pinWidth = 60; // Ширина кегли
    qreal pinSpacing = 10; // Промежуток между кеглями
    int pinCount = 4; // Количество кеглей

    // Вычисляем ширину ряда кеглей
    qreal rowWidth = pinCount * pinWidth + (pinCount - 1) * pinSpacing;

    // Начальная координата X для центрирования
    qreal startX = (trapezoidBase - rowWidth) / 2;

    // Начальная координата Y
    qreal startY = -45; // или любая другая координата, которую вы хотите

    // Устанавливаем Z-позицию для кеглей (большее значение для кеглей, чтобы они были на переднем плане)
    qreal pinZValue = 1;

    // Создаем кегли и добавляем их на сцену
    for (int i = 0; i < pinCount; ++i) {
        qreal x = startX + (pinWidth + pinSpacing) * i;
        qreal y = startY;
        BowlingPin* pin = new BowlingPin(x, y, pinWidth, pinWidth, pinMass);
        pin->setZValue(pinZValue); // Устанавливаем Z-позицию кегли
        scene4->addItem(pin);
        // Сохраняем указатель на кеглю в векторе для последующего удаления при столкновении
        pins.append(pin);
    }

    // Создаем прямоугольник
    QRectF rectangle(197, 0, 406, -140); // Прямоугольник с координатами и размерами

    // Создаем QGraphicsRectItem с прямоугольником
    QGraphicsRectItem* rectangleItem = new QGraphicsRectItem(rectangle);
    scene4->addItem(rectangleItem);

    // Начальные координаты и радиус шара
    qreal ballX = (polygon1.at(0).x() + polygon1.at(1).x()) / 2; // X-координата шара на середине большего расстояния трапеции
    qreal ballY = 350; // Y-координата шара (может быть любой, зависит от вашего предпочтения)
    ballRadius = 40; // Радиус шара

    // Создайте шар и установите его массу
    ballItem = new QGraphicsEllipseItem(ballX - ballRadius, ballY - ballRadius, 2 * ballRadius, 2 * ballRadius);
    ballItem->setBrush(Qt::blue); // Цвет шара
    ballItem->setZValue(pinZValue); // Установите Z-позицию шара
    scene4->addItem(ballItem);

    remainingPins = pinCount;

    ui->bowlingEdit->append("Координаты кеглей:");
    for (int i = 0; i < pins.size(); ++i) {
        BowlingPin *pin = pins.at(i);
        ui->bowlingEdit->append(QString("Кегля %1: (%2, %3)").arg(i).arg(pin->x()).arg(pin->y()));
    }
}

void MainWindow::moveBall()
{
    qreal currentX = ballItem->x();
    qreal currentY = ballItem->y();
    int angle = ui->angleedit->text().toInt();
    speed = ui->speedballedit->text().toDouble();

    qreal angleRadians = qDegreesToRadians(static_cast<qreal>(angle));
    qreal newX = currentX + speed * qCos(angleRadians);
    qreal newY = currentY + speed * qSin(angleRadians);
    ballItem->setPos(newX, newY);

    int pinsKnockedDownThisTurn = 0;

    for (int i = 0; i < pins.size(); ++i) {
        BowlingPin *pin = pins.at(i);
        if (ballItem->collidesWithItem(pin)) {
            scene4->removeItem(pin);
            delete pin;
            pins.removeAt(i);
            remainingPins--;
            pinsKnockedDownThisTurn++;
        }
    }

    totalPinsKnockedDown += pinsKnockedDownThisTurn;
    totalPinsKnockedDownOverall += pinsKnockedDownThisTurn;

    if ((newY >= -370 && newY <= -339)) {
        timer->stop();
        totalThrows++;

        QTimer::singleShot(2000, this, [this]() {
            qreal ballX = 0;
            qreal ballY = 0;
            ballItem->setPos(ballX, ballY);

            ui->bowlingEdit->append(QString("\nСуммарное количество бросков: %1").arg(totalThrows));
            if(totalThrows==3){
                totalThrows=1;
            }
            ui->bowlingEdit->append("Шар вернулся в начальное положение!");
            ui->bowlingEdit->append(QString("Кегля сбита! Осталось кеглей: %1").arg(remainingPins));
            ui->bowlingEdit->append(QString("Суммарно сбито кеглей: %1").arg(totalPinsKnockedDown));
            ui->bowlingEdit->append(QString("Общее количество сбитых кеглей за все броски: %1").arg(totalPinsKnockedDownOverall));

            if (firstThrow) {
                if (totalPinsKnockedDown == 10) {
                    ui->bowlingEdit->append("STRIKE!");
                    resetGame();
                } else {
                    firstThrow = false;
                }
            } else {
                if (totalPinsKnockedDownOverall == 10) {
                    ui->bowlingEdit->append("SPARE!");
                }
                resetGame();
            }
        });
    }
}

void MainWindow::resetGame() {
    totalPinsKnockedDown = 0;
    totalThrows = 0;
    firstThrow = true;
}

void MainWindow::addPinsToField(int pinCount)
{
    qreal pinMass = 2.0;
    qreal pinWidth = 60; // Ширина кегли
    qreal pinSpacing = 10; // Промежуток между кеглями

    // Вычисляем ширину ряда кеглей
    qreal trapezoidBase = 800; // Длина основания трапеции
    qreal rowWidth = pinCount * pinWidth + (pinCount - 1) * pinSpacing;

    // Начальная координата X для центрирования
    qreal startX = (trapezoidBase - rowWidth) / 2;

    // Начальная координата Y
    qreal startY = -45; // или любая другая координата, которую вы хотите

    // Устанавливаем Z-позицию для кеглей (большее значение для кеглей, чтобы они были на переднем плане)
    qreal pinZValue = 1;

    // Создаем кегли и добавляем их на сцену
    for (int i = 0; i < pinCount; ++i) {
        qreal x = startX + (pinWidth + pinSpacing) * i;
        qreal y = startY;
        BowlingPin* pin = new BowlingPin(x, y, pinWidth, pinWidth, pinMass);
        pin->setZValue(pinZValue); // Устанавливаем Z-позицию кегли
        scene4->addItem(pin);
        // Сохраняем указатель на кеглю в векторе для последующего удаления при столкновении
        pins.append(pin);
    }

    remainingPins += pinCount;

    // Вывод отладочной информации о координатах кеглей
    ui->bowlingEdit->append(QString("Добавлено %1 кеглей:").arg(pinCount));
    for (int i = 0; i < pinCount; ++i) {
        BowlingPin *pin = pins.at(i);
        ui->bowlingEdit->append(QString("Кегля %1: (%2, %3)").arg(i).arg(pin->x()).arg(pin->y()));
    }
}
void MainWindow::on_startBowling_clicked()
{
    if (ui->angleedit->text().isEmpty() || ui->speedballedit->text().isEmpty() ) {
        QMessageBox::warning(this, "Ошибка", "Заполните все поля: угол, скорость и массу шара.");
        return;
    }
    // Проверка валидности скорости
    bool isSpeedValid = false;
    double speed = ui->speedballedit->text().toDouble(&isSpeedValid);
    if (!isSpeedValid || speed <= 0 || speed > 30) {
        QMessageBox::warning(this, "Ошибка", "Скорость должна быть в диапазоне от 1 до 30.");
        ui->speedballedit->clear();
        return;
    }
    int angle = ui->angleedit->text().toInt();
    if (angle < 240 || angle > 300) {
        QMessageBox::warning(this, "Ошибка", "Угол должен быть в диапазоне от 240 до 300 градусов.");
        return;
    }

    if (firstThrow) {
        totalPinsKnockedDown = 0;
        totalThrows = 0;
    }

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::moveBall);

    int duration = 20000;
    timer->start(400);
    timer->setInterval(duration / 400);
}

void MainWindow::on_addPinsButton_clicked()
{
    // Получаем количество кеглей из QLineEdit
    int pinCount = ui->addpinedit->text().toInt();

    // Вызываем функцию добавления кеглей в поле
    addPinsToField(pinCount);
}
void MainWindow::on_back_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

