#include "ui_gamewidget.h"
#include "gamewidget.h"
#include <QRandomGenerator>

GameWidget::GameWidget(bool mode, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{

    srand(time(NULL));

    mod = mode;



    timerLabel = new QLabel();


    updateTimer = new QTimer(this);

    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
 // updateTimer->start(1000);
    timerLabel->setText(QTime(0, elapsedSeconds / 60, elapsedSeconds % 60).toString("mm:ss"));








    colors.push_back(std::make_pair(QColor("#F7ADA9"), QColor("#F9DEC1")));
    colors.push_back(std::make_pair(QColor("#45CEFC"), QColor("#B5ECFD")));
    colors.push_back(std::make_pair(QColor("#AF93D5"), QColor("#F4BEEC")));
    int randomIndex = QRandomGenerator::global()->bounded(colors.size());
    QPalette palette;
    QLinearGradient gradient(0, 0, 0, 400);
    QColor c1 = colors[randomIndex].first;
    QColor c2 = colors[randomIndex].second;
    gradient.setColorAt(0, c1);
    gradient.setColorAt(1, c2);

    this->setAutoFillBackground(true);
    palette.setBrush(QPalette::Window, gradient);
    this->setPalette(palette);




    ui->setupUi(this);

    setMinimumHeight(400);
    setMinimumWidth(600);


    scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);

    connect(this, &QWidget::show, this, &GameWidget::initializeScene);
    shown = false;
    gridSize = 9;
    ansField.resize(gridSize);
    gridTiles.resize(gridSize);
    numbersField.resize(gridSize);
    for (int i = 0; i < gridSize; ++i) {
        gridTiles[i].resize(gridSize);
        numbersField[i].resize(gridSize);
        ansField[i].resize(gridSize);
    }


    for (int i = 1; i <= 9; ++i) {
        QPushButton* button = new QPushButton(QString::number(i));
        button->setObjectName("button" + QString::number(i));
        QFont font = button->font();
        font.setPointSize(20);
        button->setFont(font);

        buttons.push_back(button);
    }

    backB = new QPushButton("");
    connect(backB, &QPushButton::clicked, this, &GameWidget::on_backB_clicked);


    timerB = new QPushButton("");
    connect(timerB, &QPushButton::clicked, this, &GameWidget::on_timerB_clicked);

    clearAllB = new QPushButton("Clear all");
    connect(clearAllB, &QPushButton::clicked, this, &GameWidget::on_clearAllB_clicked);



    clrTile = new QPushButton("");
    connect(clrTile, &QPushButton::clicked, this, &GameWidget::clrTile_Clicked);

    generateB = new QPushButton("");
    connect(generateB, &QPushButton::clicked, this, &GameWidget::generateB_Clicked);
    if(mod){
        solveB = new QPushButton("Solve");
        connect(solveB, &QPushButton::clicked, this, &GameWidget::on_solveB_clicked);
    }


    for (int i = 0; i < buttons.size(); ++i) {
        connect(buttons[i], &QPushButton::clicked, this, &GameWidget::buttonClicked);
    }

    if(!mod){
        starLabel1 = new QLabel;
        starLabel2 = new QLabel;
        starLabel3 = new QLabel;
        difficultyLabel = new QLabel;
        helpB1 = new QPushButton;
        helpB2 = new QPushButton;
        connect(helpB1, &QPushButton::clicked, this, &GameWidget::on_helpB1_clicked);
        connect(helpB2, &QPushButton::clicked, this, &GameWidget::on_helpB2_clicked);
    }
    resizeFunction();



}

void GameWidget::on_backB_clicked()
{
    stopTimer();
    emit backToMenu();
    this->close();
}

void GameWidget::on_solveB_clicked()
{
    Solver* solver = new Solver();
    std::stack<Node>* solution;
    Node next;

    if (!(solver->initialize()))
    {
       qDebug() << "Could not initialize matrix" ;
       delete solver;

    }
    qDebug() << "Initialized matrix" ;
    int puzzle[9][9];
    for (int i = 0;i < 9;i++)
    {
        for (int j = 0;j < 9;j++)
        {
            puzzle[i][j] = 0;
        }
    }
       solution = solver->solve(numbersField);
       if (solution != nullptr)
       {
           while(!solution->empty())
           {
               next = solution->top();
               puzzle[next.row][next.column] = next.value+1;
               solution->pop();
           }
       }
       else
       {
           QMessageBox* messageBox = new QMessageBox();
           messageBox->setIcon(QMessageBox::Information);
           messageBox->setText("Solution could not be found");
           messageBox->setWindowTitle("Error");

           QString styleSheet = "QMessageBox {"
                                "background-color: white;"
                                "border-radius: 10px;"
                                "}"
                                "QMessageBox QLabel {"
                                "color: #333333;"
                                "font-size: 12pt;"
                                "}";

           messageBox->setStyleSheet(styleSheet);

           messageBox->setStandardButtons(QMessageBox::Ok);
           messageBox->exec();
           return;
       }

       qDebug()<< "Solution: " ;
       for (int i=0;i<9;i++)
       {
           for (int j=0;j<9;j++)
           {
               qDebug()<<QString::number(puzzle[i][j]) + " ";
           }

            qDebug()<<"";
       }
       delete solution;
       solution = nullptr;

    if (solution !=nullptr)
    {
       while(!solution->empty())
           solution->pop();
       delete solution;
    }
    if (solver!=NULL)
       delete solver;

    for(int i = 0; i < 9; i++)
       for(int j = 0; j < 9; j++)
       {
           numbersField[i][j] = puzzle[i][j];
           gridTiles[i][j]->setNumber(numbersField[i][j]);
       }


}

void GameWidget::on_clearAllB_clicked()
{

    for (int i = 0; i < gridSize; ++i)
       for(int j  = 0; j < gridSize; ++j)
       {
           gridTiles[i][j]->removeHilight();
           gridTiles[i][j]->selected(false);
           gridTiles[i][j]->setIsChangeable(true);
       }
    selectedCol = -1;
    selectedRow = -1;
    for(int i = 0; i < gridSize; i++)
       for(int j = 0; j < gridSize; j++)
       {
           numbersField[i][j] = 0;
           gridTiles[i][j]->setNumber(-1);

       }
}

void GameWidget::buttonClicked() {
   /* isStarActive[0] = true;
    isStarActive[1] = true;
    isStarActive[2] = true;*/
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
       QString buttonName = button->objectName();
       QString buttonNumberString = buttonName.right(buttonName.length() - QString("button").length());
       int buttonNumber = buttonNumberString.toInt();
       qDebug() << "Button clicked:" << buttonNumberString;

       if(selectedRow != -1 && selectedCol!= -1){

            if(!gridTiles[selectedRow][selectedCol]->getIsChaneable())
            {
               return;
            }
            gridTiles[selectedRow][selectedCol]->setNumber(buttonNumber);

            numbersField[selectedRow][selectedCol]=buttonNumber;
            if(!mod){
            if(gridTiles[selectedRow][selectedCol]->getNumber()!=-1 &&  gridTiles[selectedRow][selectedCol]->getNumber()!=ansField[selectedRow][selectedCol])
            {

                for(int k = 0; k < 3; k++)
                {
                   if(isStarActive[k])
                   {
                       isStarActive[k] = false;
                       qDebug()<<k;
                       break;
                   }
                   if(!isStarActive[k])
                   {
                       continue;
                   }
                }

            }

            if(ansField[selectedRow][selectedCol] == buttonNumber)
               gridTiles[selectedRow][selectedCol]->setIsChangeable(false);

            int notCorrect = 0;
            for (int i = 0; i < gridSize; ++i)
               for(int j  = 0; j < gridSize; ++j)
               {
                   gridTiles[i][j]->removeHilight();
                   gridTiles[i][j]->selected(false);
                   if(gridTiles[i][j]->getNumber()!=-1 &&  gridTiles[i][j]->getNumber()!=ansField[i][j])
                   {
                       notCorrect++;
                       if(!mod){
                            gridTiles[i][j]->setIncorrect();

                       }

                   }
                   if(gridTiles[i][j]->getNumber()==-1 ||  gridTiles[i][j]->getNumber()!=ansField[i][j])
                   {
                       notCorrect++;
                   }
               }



            if(notCorrect == 0)
            {
               QMessageBox* messageBox = new QMessageBox();
               messageBox->setText("Win");
               messageBox->setWindowTitle("Win");

               QString styleSheet = "QMessageBox {"
                                    "background-color: white;"
                                    "border-radius: 10px;"
                                    "}"
                                    "QMessageBox QLabel {"
                                    "color: #333333;"
                                    "font-size: 50pt;"
                                    "}";

               messageBox->setStyleSheet(styleSheet);

               messageBox->setStandardButtons(QMessageBox::Ok);
               messageBox->setFixedSize(400, 200);

               messageBox->exec();
               this->generateB_Clicked();
            }
            }

        }
        resizeFunction();

        if(!mod){
            int curS = 0;
            for(curS = 0; curS < 3; curS++)
            {
               if(isStarActive[curS])
               {
                   break;
               }
            }
            if(curS == 3)
            {
               QMessageBox* messageBox = new QMessageBox();
               messageBox->setText("Game over");
               messageBox->setWindowTitle("nt");

               QString styleSheet = "QMessageBox {"
                                    "background-color: white;"
                                    "border-radius: 10px;"
                                    "}"
                                    "QMessageBox QLabel {"
                                    "color: #333333;"
                                    "font-size: 50pt;"
                                    "}";

               messageBox->setStyleSheet(styleSheet);

               messageBox->setStandardButtons(QMessageBox::Ok);
               messageBox->setFixedSize(400, 200);

               messageBox->exec();
               this->generateB_Clicked();
            }
        }
        selectedCol = -1;
        selectedRow = -1;

    }


}

void GameWidget::clrTile_Clicked()
{


       if(selectedRow != -1 && selectedCol!= -1){
           if(!gridTiles[selectedRow][selectedCol]->getIsChaneable())
           {
                return;
           }
           gridTiles[selectedRow][selectedCol]->setNumber(-1);

           numbersField[selectedRow][selectedCol]= 0;
           for (int i = 0; i < gridSize; ++i)
               for(int j  = 0; j < gridSize; ++j)
               {
                   if(gridTiles[i][j]->isCorrect())
                   gridTiles[i][j]->removeHilight();
                   gridTiles[i][j]->selected(false);
               }
           gridTiles[selectedRow][selectedCol]->removeHilight();
           selectedCol = -1;
           selectedRow = -1;

       }
       resizeFunction();

}


void GameWidget::generateB_Clicked()
{

   /* int randomIndex = QRandomGenerator::global()->bounded(colors.size());
    QPalette palette;
    QLinearGradient gradient(0, 0, 0, 400);
    QColor c1 = colors[randomIndex].first;
    QColor c2 = colors[randomIndex].second;
    gradient.setColorAt(0, c1);
    gradient.setColorAt(1, c2);
    this->setAutoFillBackground(true);
    palette.setBrush(QPalette::Window, gradient);
    this->setPalette(palette);*/


    isStarActive[0] = true;
    isStarActive[1] = true;
    isStarActive[2] = true;

    for (int i = 0; i < gridSize; ++i)
    for(int j  = 0; j < gridSize; ++j)
    {
        gridTiles[i][j]->removeHilight();
        gridTiles[i][j]->selected(false);
        gridTiles[i][j]->setIsChangeable(true);
    }
    selectedCol = -1;
    selectedRow = -1;

    generator = new Generator();
    if(lvlReaded > 100){
        generator->createSeed();
        generator->genPuzzle();
        generator->calculateDifficulty();
        generator->printGrid(numbersField, ansField);
    }
    else
    {
        int t;
        generator->genGetInfo(numbersField, ansField,t, lvlReaded);
        lvlReaded++;
    }
    difficultyLabel -> setText(QString::number(generator->getDifficulty()));

    for(int i = 0; i < gridSize; i++)
       for(int j = 0; j < gridSize; j++)
       {
           gridTiles[i][j]->setNumber(numbersField[i][j]);
           if(numbersField[i][j] != -1)
           {
               gridTiles[i][j]->setIsChangeable(false);
           }
       }
    delete generator;
    if(!mod)
    {
       restartTimer();
    }


    resizeFunction();
  /*  QString filename = "/home/user/SudokuGameDev/randomLevels.txt";
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
       QTextStream out(&file);
       out<<generator->getDifficulty()<<'\n';
       for(int i = 0; i < gridSize; i++){
           for(int j = 0; j < gridSize; j++) {
               if(numbersField[i][j] == -1)
                   out << "_";
               else
                   out << numbersField[i][j];
           }
           out << '\n';
       }


       out << '\n';
       for(int i = 0; i < gridSize; i++){
           for(int j = 0; j < gridSize; j++) {
                out << ansField[i][j];
           }
           out << '\n';
       }
       out << '\n';
       file.close();
       qDebug() << "Запись успешно добавлена в конец файла randomLevels.txt.";
    } else {
       qWarning("Не удалось открыть файл randomLevels.txt для записи.");
    }

    file.close();*/
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::setPaletteW(QPalette palette)
{
    Palette = palette;
    this->setPalette(Palette);
}

void GameWidget::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);

    if (!shown) {
        shown = true;
        initializeScene();
    }
}
void GameWidget::initializeScene() {
    QSize viewSize = ui->graphicsView->viewport()->size();
    scene->setSceneRect(0, 0, viewSize.width(), viewSize.height());
    tileSize = scene->sceneRect().height() / 9;


    for (int i = 0; i < gridSize; ++i)
        for(int j  = 0; j < gridSize; ++j)
        {
            gridTiles[i][j] = new Tile(i, j, tileSize);
            connect(gridTiles[i][j], &Tile::tileClicked, this, &GameWidget::hilightArea);
            scene->addItem(gridTiles[i][j]);
        }

    QPen pen;
    pen.setWidth(5);
    QGraphicsLineItem *line = new QGraphicsLineItem(0, 3 * tileSize, 9 * tileSize,3 * tileSize);
    QGraphicsLineItem *line1 = new QGraphicsLineItem(0, 6 * tileSize, 9 * tileSize,6 * tileSize);
    QGraphicsLineItem *line2 = new QGraphicsLineItem(3 * tileSize, 0, 3 * tileSize,9 * tileSize);
    QGraphicsLineItem *line3 = new QGraphicsLineItem(6 * tileSize, 0, 6 * tileSize, 9 * tileSize);
    line->setPen(pen);
    line1->setPen(pen);
    line2->setPen(pen);
    line3->setPen(pen);
    scene->addItem(line);
    scene->addItem(line1);
    scene->addItem(line2);
    scene->addItem(line3);

    if(!mod)
        generateB_Clicked();
    resizeFunction();
}


void GameWidget::hilightArea(Tile* tile){

    for (int i = 0; i < gridSize; ++i)
        for(int j  = 0; j < gridSize; ++j)
        {
            if(gridTiles[i][j]->isCorrect())
                gridTiles[i][j]->removeHilight();
            gridTiles[i][j]->selected(false);
        }
    selectedRow = tile->getRow();
    selectedCol = tile->getCol();
    int subAreaX = selectedRow / (int)sqrt(gridSize);
    int subAreaY = selectedCol / (int)sqrt(gridSize);
    for (int i = 0; i < gridSize; ++i)
     for (int j = 0; j < gridSize; ++j)
        {
            if(i == selectedRow || j == selectedCol || (i >= subAreaX * (int)sqrt(gridSize) && i < (subAreaX+1) * (int)sqrt(gridSize) && j >= subAreaY * (int)sqrt(gridSize) && j < (subAreaY+1) * (int)sqrt(gridSize))){
                if(gridTiles[i][j]->isCorrect())
                    gridTiles[i][j]->hilight();
                gridTiles[i][j]->selected(true);
            }
        }
    if(gridTiles[selectedRow][selectedCol]->isCorrect())
        gridTiles[selectedRow][selectedCol]->hilightInsertion();
}

void GameWidget::stopTimer()
{
    updateTimer->stop();
}

void GameWidget::restartTimer()
{
    elapsedSeconds = 0;
    updateTimer->start(1000);
}

void GameWidget::startTimer()
{
    updateTimer->start(1000);
}

void GameWidget::updateTime()
{
    ++elapsedSeconds;
    timerLabel->setText(QTime(0, elapsedSeconds / 60, elapsedSeconds % 60).toString("mm:ss"));
}

void GameWidget::on_timerB_clicked()
{
    if (updateTimer->isActive())
    {
        updateTimer->stop();
    }
    else
        updateTimer->start(1000);
}

void GameWidget::on_helpB1_clicked()
{
    QVector<std::pair<int, int>> chosen;
    for (int i = 0; i < gridSize; ++i){
        for(int j  = 0; j < gridSize; ++j)
        {
            if(gridTiles[i][j]->getNumber() == -1)
            {
                std::pair<int, int> t{i, j};
                chosen.push_back(t);
            }
        }
    }
    if(chosen.size()==0)
        return;
    int randomIndex = QRandomGenerator::global()->bounded(chosen.size());
    qDebug()<<"ch"<<randomIndex;
    int Row = chosen[randomIndex].first;
    int Col = chosen[randomIndex].second;
    gridTiles[Row][Col]->setNumber(ansField[Row][Col]);
    gridTiles[Row][Col]->setIsChangeable(false);
    numbersField[Row][Col]= ansField[Row][Col];

    int notCorrect = 0;
    for (int i = 0; i < gridSize; ++i)
        for(int j  = 0; j < gridSize; ++j)
        {


            if(gridTiles[i][j]->getNumber()==-1 ||  gridTiles[i][j]->getNumber()!=ansField[i][j])
            {
                notCorrect++;
            }
        }
    if(notCorrect == 0)
    {
        QMessageBox* messageBox = new QMessageBox();
        messageBox->setText("Win");
        messageBox->setWindowTitle("Win");

        QString styleSheet = "QMessageBox {"
                             "background-color: white;"
                             "border-radius: 10px;"
                             "}"
                             "QMessageBox QLabel {"
                             "color: #333333;"
                             "font-size: 50pt;"
                             "}";

        messageBox->setStyleSheet(styleSheet);

        messageBox->setStandardButtons(QMessageBox::Ok);
        messageBox->setFixedSize(400, 200);

        messageBox->exec();
        this->generateB_Clicked();
    }
    resizeFunction();
}

void GameWidget::on_helpB2_clicked()
{
    if(selectedRow != -1 && selectedCol!= -1){
        if(!gridTiles[selectedRow][selectedCol]->getIsChaneable())
        {
            return;
        }
        gridTiles[selectedRow][selectedCol]->setNumber(ansField[selectedRow][selectedCol]);
        gridTiles[selectedRow][selectedCol]->setIsChangeable(false);
        numbersField[selectedRow][selectedCol]= ansField[selectedRow][selectedCol];
        for (int i = 0; i < gridSize; ++i)
            for(int j  = 0; j < gridSize; ++j)
            {
                if(gridTiles[i][j]->isCorrect())
                    gridTiles[i][j]->removeHilight();
                gridTiles[i][j]->selected(false);
            }
        gridTiles[selectedRow][selectedCol]->removeHilight();
        selectedCol = -1;
        selectedRow = -1;

    }
    resizeFunction();

    int notCorrect = 0;
    for (int i = 0; i < gridSize; ++i)
        for(int j  = 0; j < gridSize; ++j)
        {


            if(gridTiles[i][j]->getNumber()==-1 ||  gridTiles[i][j]->getNumber()!=ansField[i][j])
            {
                notCorrect++;
            }
        }
    if(notCorrect == 0)
    {
        QMessageBox* messageBox = new QMessageBox();
        messageBox->setText("Win");
        messageBox->setWindowTitle("Win");

        QString styleSheet = "QMessageBox {"
                             "background-color: white;"
                             "border-radius: 10px;"
                             "}"
                             "QMessageBox QLabel {"
                             "color: #333333;"
                             "font-size: 50pt;"
                             "}";

        messageBox->setStyleSheet(styleSheet);

        messageBox->setStandardButtons(QMessageBox::Ok);
        messageBox->setFixedSize(400, 200);

        messageBox->exec();
        this->generateB_Clicked();
    }
    resizeFunction();
}

void GameWidget::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    resizeFunction();
}
void GameWidget::resizeFunction()
{

    QSize wSize = this->size();
    double viewSize = std::min(wSize.height(), wSize.width());

    ui->graphicsView->setGeometry(wSize.width()/2 - viewSize * 0.4, wSize.height()/2 - viewSize * 0.4 , viewSize * 0.8, viewSize * 0.8);
    ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    double bHArea = wSize.height() * 0.8;
    double bSize = bHArea / 9;
    double brdrR = bSize * 0.9 / 2.1;
    double yDiff = 0;
    for(int i = 0; i < buttons.size(); i++)
    {
        buttons[i]->setFixedSize(bSize * 0.9, bSize * 0.9);
        buttons[i]->setParent(this);
        QString styleSheet = QString("QPushButton { background-color: white; color: black; border-radius: %1%; border-style: none; } QPushButton:pressed { background-color: lightgray; color: white; }").arg(brdrR);
        buttons[i]->setStyleSheet(styleSheet);

        if (i % 3 == 0 && i > 0) {
            yDiff += bSize ;
        }
        buttons[i]->move(wSize.width()/2 + viewSize * 0.5 + 1.3 * bSize * (i % 3), wSize.height()/2 - viewSize * 0.2 + 1.3 * yDiff);
    }
    QString styleSheet = QString("QPushButton { background-color: white; color: black; border-radius: %1%; border-style: none; } QPushButton:pressed { background-color: lightgray; color: white; }").arg(brdrR);


    QPixmap clearButtonIcon(":img/clearButtonIcon.png");
    clrTile->setIcon(clearButtonIcon);
//
    if(!mod){
        int labelWidth = bSize * 0.9 * 3;
        int labelHeight = bSize * 0.9;
        int buttonSize = bSize * 0.7;


        int centerX = wSize.width() / 2 + viewSize * 0.5;
        int centerY = wSize.height() / 2 - viewSize * 0.4;


        timerLabel->setFixedSize(labelWidth, labelHeight);
        timerLabel->setParent(this);
        timerLabel->move(centerX - labelWidth / 2 + viewSize * 0.2, centerY - labelHeight / 2 + viewSize * 0.05);
        timerLabel->setFont(QFont("Arial", 40, QFont::Bold));
        timerLabel->setStyleSheet("color: gray; qproperty-alignment: AlignVCenter;");


        timerB->setFixedSize(buttonSize, buttonSize);
        timerB->setParent(this);
        timerB->move(centerX - buttonSize / 2 + viewSize * 0.03, centerY - buttonSize / 2 + viewSize * 0.05);
        timerB->setIcon(QPixmap(":img/play.png"));
        timerB->setStyleSheet(QString("QPushButton { background-color: white; color: black; border-radius: %1%; border-style: none; } QPushButton:pressed { background-color: lightgray; color: white; }").arg(brdrR * 0.7));
    }
//
    QPixmap exitButtonIcon(":/img/exitIcon.png");
    exitButtonIcon = exitButtonIcon.scaled(QSize(bSize * 0.9, bSize * 0.9), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    backB->setIcon(exitButtonIcon);
    backB->setIconSize(exitButtonIcon.size() * 2);

    backB->setParent(this);
    backB->setFixedSize(bSize * 0.9, bSize * 0.9);
    backB->setStyleSheet(styleSheet);
    backB->move(wSize.width()/2 - viewSize * 0.59, wSize.height()/2 - viewSize * 0.4  + bSize * 2);

    if(mod){
        clearAllB->setParent(this);
        clearAllB->setFixedSize(bSize * 0.9, bSize * 0.9);
        clearAllB->setStyleSheet(styleSheet);
        clearAllB->move(wSize.width()/2 - viewSize * 0.59, wSize.height()/2 - viewSize * 0.4 + bSize * 7);
    }
    clrTile->setParent(this);
    clrTile->setFixedSize(bSize * 0.9, bSize * 0.9);
    clrTile->setStyleSheet(styleSheet);
    clrTile->move(wSize.width()/2 + viewSize * 0.5 + 1.3 * bSize , wSize.height()/2 - viewSize * 0.2 + bSize * 4);

    if(mod){
        solveB->setParent(this);
        solveB->setFixedSize(bSize * 0.9, bSize * 0.9);
        solveB->setStyleSheet(styleSheet);
        solveB->move(wSize.width()/2 - viewSize * 0.59, wSize.height()/2 - viewSize * 0.4 + bSize * 8);
    }
    else{
        QPixmap playIcon(":/img/play-button.png");
        playIcon = playIcon.scaled(QSize(bSize * 0.9, bSize * 0.9), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        generateB->setIcon(playIcon);
        generateB->setParent(this);
        generateB->setFixedSize(bSize * 0.9, bSize * 0.9);
        generateB->setStyleSheet(styleSheet);
        generateB->setIconSize(playIcon.size());
        generateB->move(wSize.width()/2 - viewSize * 0.59, wSize.height()/2 - viewSize * 0.4 + bSize * 8);
    }

    if (!mod) {
        QPixmap starIcon(":/img/star.png");
        QPixmap starIcon2(":/img/notActiveStar.png");
        if(!isStarActive[0])
            starLabel1->setPixmap(starIcon2.scaled(bSize * 0.9, bSize * 0.9, Qt::KeepAspectRatio));
        else
             starLabel1->setPixmap(starIcon.scaled(bSize * 0.9, bSize * 0.9, Qt::KeepAspectRatio));
        if(!isStarActive[1])
            starLabel2->setPixmap(starIcon2.scaled(bSize * 0.9, bSize * 0.9, Qt::KeepAspectRatio));
        else
             starLabel2->setPixmap(starIcon.scaled(bSize * 0.9, bSize * 0.9, Qt::KeepAspectRatio));
        if(!isStarActive[2])
            starLabel3->setPixmap(starIcon2.scaled(bSize * 0.9, bSize * 0.9, Qt::KeepAspectRatio));
        else
             starLabel3->setPixmap(starIcon.scaled(bSize * 0.9, bSize * 0.9, Qt::KeepAspectRatio));

        QPixmap ideaIcon(":/img/idea.png");
        QPixmap questionIcon(":/img/question.png");

        ideaIcon = ideaIcon.scaled(QSize(bSize * 0.9, bSize * 0.9), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        helpB1->setIcon(ideaIcon);
        helpB1->setParent(this);
        helpB1->setFixedSize(bSize * 0.9, bSize * 0.9);
        helpB1->setStyleSheet(styleSheet);
        helpB1->setIconSize(ideaIcon.size() );
        helpB1->move(wSize.width()/2 - viewSize * 0.59, wSize.height()/2 - viewSize * 0.4  + bSize * 4);



        questionIcon = questionIcon.scaled(QSize(bSize * 0.9, bSize * 0.9), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        helpB2->setIcon(questionIcon);
        helpB2->setParent(this);
        helpB2->setFixedSize(bSize * 0.9, bSize * 0.9);
        helpB2->setStyleSheet(styleSheet);
        helpB2->setIconSize(questionIcon.size() );
        helpB2->move(wSize.width()/2 - viewSize * 0.59, wSize.height()/2 - viewSize * 0.4  + bSize * 6);

        starLabel1->setParent(this);
        starLabel1->setFixedSize(bSize * 0.9, bSize * 0.9);
        starLabel1->move(wSize.width() / 2 - viewSize * 0.59, wSize.height() / 2 - viewSize * 0.4);


        starLabel2->setParent(this);
        starLabel2->setFixedSize(bSize * 0.9, bSize * 0.9);
        starLabel2->move(wSize.width() / 2 - viewSize * 0.59 - bSize * 1, wSize.height() / 2 - viewSize * 0.4);


        starLabel3->setParent(this);
        starLabel3->setFixedSize(bSize * 0.9, bSize * 0.9);
        starLabel3->move(wSize.width() / 2 - viewSize * 0.59 - bSize * 2, wSize.height() / 2 - viewSize * 0.4);

        difficultyLabel->setParent(this);
        difficultyLabel->setFont(QFont("Arial", 40, QFont::Bold));
        difficultyLabel->setStyleSheet("color: gray; qproperty-alignment: AlignVCenter; border: 5px solid gray;");
        int labelWidth = bSize * 0.9 * 3 * 1.062;
        int labelHeight = bSize * 0.9;
        difficultyLabel->setFixedSize(labelWidth, labelHeight);
        difficultyLabel->setAlignment(Qt::AlignCenter);
        difficultyLabel->move(wSize.width() / 2 - viewSize * 0.59 - bSize * 2, wSize.height() / 2 - viewSize * 0.4 + bSize);
    }
}
