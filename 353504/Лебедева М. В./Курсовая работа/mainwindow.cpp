#include "mainwindow.h"

#include <QDateTime>
#include <QInputDialog>
#include <QMapIterator>
#include <QRandomGenerator>

#include <queue>
#include <vector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);
    setWindowTitle("MineSweeper ;)");
    widget->setStyleSheet("background-color:mediumslateblue");

    //настроим макеты
    totalLayout = new QVBoxLayout;
    firstLayout = new QHBoxLayout;
    firstLayout->setSpacing(50);//промежуток между элементами в первом горизонтальном макете
    buttonsLayout = new QGridLayout;//сеточный макет для основной игры
    buttonsLayout->setSpacing(0);//кнопочки впритык без отступов
    //buttonsLayout->setContentsMargins(0, 0, 0, 0);//кнопочки впритык без отступов
    totalLayout->addLayout(firstLayout);//добавляем горизонтальный макет
    totalLayout->addLayout(buttonsLayout);//под ним основное игровое поле
    widget->setLayout(totalLayout);

    //начальные данные
    time = 0;
    disabledButtons = 0;
    gameDifficulty = 0;
    endOfGame = false;

    //настроим верхний макет игры
    //выбор сложности игры
    gameDifficulties = createComboBox();
    firstLayout->addWidget(gameDifficulties);

    //настроим статистику
    showStatistic = new QPushButton("Statistics");
    showStatistic->setStyleSheet("background-color:powderblue");
    showStatistic->setEnabled(false);//кнопка пока что недоступна
    connect(showStatistic, &QPushButton::clicked,this, [&](){showTop10(gameDifficulty);});
    firstLayout->addWidget(showStatistic);

    //настроим кнопку перезапуска игры
    resetButton = new QPushButton("Reset game");
    resetButton->setStyleSheet("background-color:powderblue");
    //resetButton->setFont(font);
    connect(resetButton, &QPushButton::clicked, this, [&](){reset();});
    firstLayout->addWidget(resetButton);

    //отображение количества флагов==мин на макете
    flags = new QLabel;
    flags->setText("Flags: 10");
    firstLayout->addWidget(flags);

    //настроим время игры
    timeLabel = new QLabel("00:00");
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()),this, SLOT(tick()));
    firstLayout->addWidget(timeLabel);

    //настроим кнопку для отображения правил игры
    showRules = new QPushButton("?");
    showRules->setStyleSheet("background-color:powderblue");
    rules.setWindowTitle("Rules of the Game:");
    rules.setFixedSize(500, 250);
    rules.setReadOnly(true);
    rules.setPlainText("“Mineweeper” is a simple game that develops attention, memory\n"
                       "and logic. The goal is to open all the cells on the field without\n"
                       "exploding” a single mine. To find explosive squares, you can use\n"
                       "the following tips:\n\n"
                       "1. The numbers in the cells show the number of mines hidden in eight adjacent cells;\n"
                       "2. If there are empty cells near an open cell, they will open automatically;\n"
                       "3. If you realize that a bomb is hidden in a certain cell, mark it with a flag;\n"
                       "4. When you open a cell with a mine, the game ends with a loss.\n\n"
                       "To win the game you need to open all the cells on the field, marking all the cells with a bomb with a flag.\n\n\n"
                       "Good luck!");
    connect(showRules, &QPushButton::clicked, this, [&](){rules.show();});
    firstLayout->addWidget(showRules);

    //настроим топ 10 игр(статистика)
    top10 = new QMessageBox;
    top10->setWindowTitle("Top 10");
    QPushButton *ok = new QPushButton("Ok");
    QPushButton *resetTop10 = new QPushButton("Reset Top 10");
    connect(resetTop10, &QPushButton::pressed, this, [&](){
        if(gameDifficulty == 0) statisticEasy.clear();
        else if(gameDifficulty == 1) statisticHard.clear();
        top10->setText("");
    });
    top10->addButton(resetTop10,QMessageBox::ResetRole);
    top10->addButton(ok, QMessageBox::AcceptRole);

    //установим основное игровое поле
    setButtons(8, 10, 50);
    setMines();
    setNumbers();
}

MainWindow::~MainWindow()
{

}

void MainWindow::clearButtons()//убирает все кнопки с игрового поля
{
    while(buttonsLayout->count()){
        for(int i=0; i<buttonsLayout->count(); ++i){
            QWidget *tempWidget = buttonsLayout->itemAt(i++)->widget();
            totalLayout->removeWidget(tempWidget);
            delete tempWidget;
        }
    }
    delete buttons;
    delete buttonText;
}

void MainWindow::setButtons(int n, int m, int size)
{
    buttonRows = n;
    buttonColumns = m;
    buttons = new MyButton **[n];
    buttonText = new QString*[n];
    for(int i=0;i<n;i++) {
        buttons[i]= new MyButton*[m];
        buttonText[i] = new QString[m];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            buttonText[i][j] = '-';
        }
    }

    switch(gameDifficulty) {//регулируем количество мин, количество флагов в зависимости от уровня сложности
    case 0:
        countOfMines = 10;
        countOfFlags = 10;
        break;
    case 1:
        countOfMines = 40;
        countOfFlags = 40;
        break;
    case 2:
        countOfMines = 99;
        countOfFlags = 99;
        break;
    }

    //создадим и добавим кнопочки на поле
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            buttons[i][j] = new MyButton(this);
            buttons[i][j]->setMinimumSize(size, size);
            buttons[i][j]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);//для свободного расширения кнопки относительно изменения размер окна

            connect(buttons[i][j], SIGNAL(clicked()), this, SLOT(buttonClicked()));
            connect(buttons[i][j], SIGNAL(rightClick()), this, SLOT(rightButtonClicked()));

            if((i+j)%2==0) {
                buttons[i][j]->setStyleSheet("background-color:slateblue");
            }
            else {
                buttons[i][j]->setStyleSheet("background-color:steelblue");
            }
            buttonsLayout->addWidget(buttons[i][j], i, j);
        }
    }
}

void MainWindow::setMines()//установим мины
{
    int cm = countOfMines;
    QVector<QVector<bool>> isPrime(buttonRows, QVector<bool>(buttonColumns, true));
    sieveOfEratosthenes(isPrime, cm);
    while(cm>0) {
        QTime time = QTime::currentTime();
        //настройка мин по времени
        srand((uint)time.msec());
        int x = QRandomGenerator::global()->bounded(buttonRows);
        int y = QRandomGenerator::global()->bounded(buttonColumns);
        if (buttonText[x][y] == 'X' || !isPrime[x][y]){ //если на этой позиции уже есть бомба или число непростое, то пропускаем текущую итерацию цикла
            continue;
        }
        buttonText[x][y] = 'X';
        --cm; 
    }
    //после установки мин, вызываем метод проверки на эйлеров цикл.
    if (isEulerianCycle()) {
        qDebug() << "Установка мин прошла успешно, найден эйлеров цикл.";
    }
    else {
        qDebug() << "Установка мин не удалась, эйлеров цикл не найден.";
    }
}

void MainWindow::setNumbers()//установим цифры
{
    for(int i=0; i<buttonRows; ++i){
        for(int j=0; j<buttonColumns; ++j){
            if(buttonText[i][j] == 'X'){
                continue;
            }
            int dm = 0; //количество бомб вокруг кнопки
            for(int x=i-1; x<i+2; ++x){
                for(int y=j-1; y<j+2; ++y){
                    if(x<0 || x>buttonRows-1 || y<0 || y>buttonColumns-1){ //когда мы не на игровом поле
                        continue;
                    }
                    if(buttonText[x][y] == "X"){
                        ++dm;
                    }
                }
            }
            if(dm != 0){
                buttonText[i][j] = QString::number(dm);
            }
        }
    }
}

void MainWindow::onEmptyButtonClicked(int i, int j)//устанавливает кнопку на соответствующий цвет и выключает ее
{
    BFS(i, j);
}

void MainWindow::mineClicked()//если мы нажмем на бомбу
{
    endOfGame = true;
    timer->stop();
    flags->setText("You lost!");

    for(int i=0; i<buttonRows; ++i){ //раскрашивает все кнопки, содержащие бомбы
        for(int j=0; j<buttonColumns; ++j){
            if(buttonText[i][j] == "X"){
                buttons[i][j]->setStyleSheet("background-color:tomato");
                buttons[i][j]->setText(buttonText[i][j]);
            }
        }
    }
    showStatistic->setEnabled(true);
}

void MainWindow::win()
{
    endOfGame = true;
    timer->stop();
    flags->setText("You win!");

    for(int i=0; i<buttonRows; ++i){ //раскрашивает их в соответствии с содержимым кнопок
        for(int j=0; j<buttonColumns; ++j){
            if(buttonText[i][j] == "X"){
                buttons[i][j]->setStyleSheet("background-color:tomato");
                buttons[i][j]->setText(buttonText[i][j]);
            }
            else{
                if(buttonText[i][j] == "-"){
                    buttons[i][j]->setStyleSheet("background-color:azure");
                }
                else{
                    buttons[i][j]->setStyleSheet("background-color:azure");
                    buttons[i][j]->setText(buttonText[i][j]);
                }
            }
        }
    }
    //запросить имя, которое мы храним (максимум 10)
    QString name = QInputDialog::getText(this, "Best Results", "Your Result: " +
                                                                   QString::number(time) + "s\nName:");
    if(gameDifficulty == 0){
        statisticEasy[time] = name;
        if(statisticEasy.size() > 10){
            auto it = statisticEasy.end();
            statisticEasy.erase(--it);
        }
    }
    else if(gameDifficulty == 1){
        statisticMedium[time] = name;
        if(statisticMedium.size() > 10){
            auto it = statisticMedium.end();
            statisticMedium.erase(--it);
        }
    }
    else {
        statisticHard[time] = name;
        if(statisticHard.size() > 10){
            auto it = statisticHard.end();
            statisticHard.erase(--it);
        }
    }
    showTop10(gameDifficulty);
    showStatistic->setEnabled(true);
}

void MainWindow::reset()//сбрасывает все, в зависимости от текущего уровня сложности
{
    endOfGame = false;
    time = 0;
    timer->stop();
    timeLabel->setText("0:0");
    showStatistic->setEnabled(false);
    disabledButtons = 0;

    if(gameDifficulty == 0){
        clearButtons();
        setButtons(8, 10, 50);
        setMines();
        setNumbers();
        flags->setText("Flags: 10");
        long long combinations = binomialCoeff(8 * 10, 10);
        qDebug() << "Количество возможных комбинаций мин: " << combinations;
    }
    else if(gameDifficulty == 1){
        clearButtons();
        setButtons(14, 18, 40);
        setMines();
        setNumbers();
        flags->setText("Flags: 40");
        qDebug() << "Количество возможных комбинаций мин: 52943745040875642664766168844732965572506114525";
    }
    else {
        clearButtons();
        setButtons(20, 24, 30);
        setMines();
        setNumbers();
        flags->setText("Flags: 99");
        qDebug() << "Количество возможных комбинаций мин: 560220999337421345429058985775821108059290502723897901281458809527214479570631168198385673295159633481600";
    }
}

void MainWindow::showTop10(int gameDifficulty)
{
    if(gameDifficulty == 0){
        QMapIterator<double, QString> it(statisticEasy);
        top10->setText("Level: Easy\n\n");
        for(int i=1; i<11; ++i){
            if(it.hasNext()){
                it.next();
                top10->setText(top10->text() + QString::number(i) + ". " + it.value() + ": " + QString::number(it.key()) + "s\n");
            }
            else{
                break;
            }
        }
    }
    else if(gameDifficulty == 1){
        QMapIterator<double, QString> it(statisticMedium);
        top10->setText("Level: Medium\n\n");
        for(int i=1; i<11; ++i){
            if(it.hasNext()){
                it.next();
                top10->setText(top10->text() + QString::number(i) + ". " + it.value() + ": " + QString::number(it.key()) + "s\n");
            }
            else{
                break;
            }
        }
    }
    else if(gameDifficulty==2){
        QMapIterator<double, QString> it(statisticHard);
        top10->setText("Level: Hard\n\n");
        for(int i=1; i<11; ++i){
            if(it.hasNext()){
                it.next();
                top10->setText(top10->text() + QString::number(i) + ". " + it.value() + ": " + QString::number(it.key()) + "s\n");
            }
            else{
                break;
            }
        }
    }
    top10->exec();
}

QComboBox *MainWindow::createComboBox()
{
    QComboBox *box = new QComboBox;
    box->setStyleSheet("background-color:powderblue");
    box->addItem("Easy");
    box->addItem("Medium");
    box->addItem("Hard");
    connect(box, SIGNAL(currentIndexChanged(int)), this, SLOT(difficultyChanged()));
    return box;
}

void MainWindow::BFS(int i, int j)
{
    std::queue<std::pair<int, int>> q;
    q.push({i, j});

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if(x<0 || x>buttonRows-1 || y<0 || y>buttonColumns-1 || buttonText[x][y] == "X" || !buttons[x][y]->isEnabled()){
            continue;
        }

        if(buttonText[x][y] == '-'){//если пустая кнопка
            buttons[x][y]->setStyleSheet("background-color:azure");
            buttons[x][y]->setEnabled(false);
            ++disabledButtons;

            for(int dx=-1; dx<=1; ++dx){
                for(int dy=-1; dy<=1; ++dy){
                    q.push({x+dx, y+dy});
                }
            }
        }

        if(buttonText[x][y] != '-'){//если на кнопке есть номер (это не может быть бомба, это обеспечивается в другой части программы)
            buttons[x][y]->setStyleSheet("background-color:wheat");
            buttons[x][y]->setText(buttonText[x][y]);
            buttons[x][y]->setEnabled(false);
            ++disabledButtons;
        }
    }
}

long long MainWindow::binomialCoeff(int n, int k)
{
    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(k + 1, 0.0));

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= fmin(i, k); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1.0;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}

void MainWindow::DFS(int x, int y, QVector<QVector<bool> > &visited)
{
    if (x >= 0 && x < buttonRows && y >= 0 && y < buttonColumns && buttonText[x][y] != 'X' && !visited[x][y]) {
        visited[x][y] = true;
        for (int dx = -1; dx <= 1; ++dx) {
            for (int dy = -1; dy <= 1; ++dy) {
                DFS(x + dx, y + dy, visited);
            }
        }
    }
}

bool MainWindow::isEulerianCycle()
{
    QVector<QVector<bool>> visited(buttonRows, QVector<bool>(buttonColumns, false));
    bool startedDFS = false;

    for (int i = 0; i < buttonRows && !startedDFS; ++i) {
        for (int j = 0; j < buttonColumns && !startedDFS; ++j) {
            if (buttonText[i][j] != 'X') {
                int degree = 0;
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        int nx = i + dx;
                        int ny = j + dy;
                        if (nx >= 0 && nx < buttonRows && ny >= 0 && ny < buttonColumns && buttonText[nx][ny] != 'X') {
                            ++degree;
                        }
                    }
                }
                if (degree % 2 != 0) {
                    return false;
                }
                DFS(i, j, visited);
                startedDFS = true;
            }
        }
    }

    for (int i = 0; i < buttonRows; ++i) {
        for (int j = 0; j < buttonColumns; ++j) {
            if (buttonText[i][j] != 'X' && !visited[i][j]) {
                return false;
            }
        }
    }

    return true;
}

double MainWindow::signedArea(int x1, int y1, int x2, int y2, int x3, int y3)
{//функция для вычисления знаковой площади треугольника
    return 0.5 * (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
}

bool MainWindow::clockwise(int x1, int y1, int x2, int y2, int x3, int y3)
{//функция для определения, находятся ли три точки в одном направлении по часовой стрелке
    return signedArea(x1, y1, x2, y2, x3, y3) < 0;
}

void MainWindow::sieveOfEratosthenes(QVector<QVector<bool> > &isPrime, int cm)
{
    isPrime[0][0] = false;
    for(int p=2; p*p<=cm; p++) {
        if(isPrime[p][p] == true) {
            for(int i=p*p; i<=cm; i += p)
                isPrime[i/buttonRows][i%buttonColumns] = false;
        }
    }
}

void MainWindow::difficultyChanged()//изменение сложности сбрасывает игру
{
    gameDifficulty = gameDifficulties->currentIndex();
    reset();
}

void MainWindow::buttonClicked()//при нажатии кнопки
{
    if(endOfGame) {
        return;
    }
    if(!timer->isActive()){//запустим таймер
        timer->start(80);
    }
    int x,y;
    QPushButton *tmp = (QPushButton*)sender();
    if(tmp->styleSheet() == "background-color:brown") {//если флажок
        return;
    }
    for(int i=0;i<buttonRows;i++) {
        for(int j=0;j<buttonColumns;j++) {
            if(buttons[i][j]==tmp) {
                x = i;
                y = j;
                break;
            }
        }
    }
    if(buttonText[x][y]!='X') {//если не мина
        onEmptyButtonClicked(x, y);
        if( disabledButtons == ((buttonRows*buttonColumns) - countOfMines) ){//контроль
            win();//выиграли
        }
    }
    else{
        // Проверяем, расположены ли мины вокруг выбранной ячейки по часовой стрелке
        for(int dx = -1; dx <= 1; dx++) {
            for(int dy = -1; dy <= 1; dy++) {
                if(dx == 0 && dy == 0) continue; // Пропускаем выбранную ячейку
                int nx = x + dx, ny = y + dy;
                if(nx >= 0 && nx < buttonRows && ny >= 0 && ny < buttonColumns) { // Проверяем, что ячейка находится в пределах поля
                    if(buttonText[nx][ny] == 'X' && clockwise(x, y, nx, ny, x+dx, y+dy)) {
                        mineClicked();//мина расположена по часовой стрелке от выбранной ячейки
                    }
                }
            }
        }
        mineClicked();//проиграли
    }
}

void MainWindow::rightButtonClicked()//щелчок правой кнопкой мыши (режим флага)
{
    if(!timer->isActive()){
        timer->start(80);
    }
    int x, y;
    QPushButton *tmp = (QPushButton*)sender();
    if(tmp->styleSheet() == "background-color:brown") {//если у него уже есть флаг, мы восстанавливаем его исходный цвет
        for(int i=0;i<buttonRows;i++) {//находим координаты кнопки
            for(int j=0;j<buttonColumns;j++) {
                if(buttons[i][j]==tmp) {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        if((x+y)%2==0) {
            buttons[x][y]->setStyleSheet("background-color:slateblue");
        }
        else {
            buttons[x][y]->setStyleSheet("background-color:steelblue");
        }
        ++countOfFlags;
        flags->setText("Flags: " + QString::number(countOfFlags));
    }
    else {//если на нем нет флага, мы его установим
        tmp->setStyleSheet("background-color:brown");
        --countOfFlags;
        flags->setText("Flags: " + QString::number(countOfFlags));
    }
}

void MainWindow::tick()//нужно измерить время
{
    time += 0.1;
    timeLabel->setText(QString::number(time));
}
