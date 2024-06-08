#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(&timer,SIGNAL(timeout()),this,SLOT(menu()));
    timer.start(1);
}

MainWindow::~MainWindow()
{

}

void MainWindow::WriteAndSaveText()
{
    QString text = QInputDialog::getText(nullptr, "Text input", "Write the text. To stop input push Enter button");
    QFile file("СорокаЛаб20.txt");
    QTextStream in(&file);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    for(int i=0;i<text.length();++i){
        in << text.at(i);
    }
    file.close();
    QMessageBox::information(this,"File saved","Data saved succesfully");
}

void MainWindow::ReadText()
{
    QFile file("СорокаЛаб20.txt");
    QTextStream in(&file);

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString text;
    while(!in.atEnd()){
        QChar ch;
        in >> ch;
        text+=ch;
    }
    file.close();
    QMessageBox::information(this,"Text in file",text);
}

void MainWindow::WriteAndSaveArray()
{
    bool pushed=false;

    QFile file("СорокаЛаб20_0.txt");
    QTextStream in(&file);
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    int size=QInputDialog::getInt(nullptr, "Array size", "Write array size", 0, 1, INT_MAX, 1, &pushed);

    while(size--)
    {
        QString text = QInputDialog::getText(nullptr, "Array element", "Write array element (Character must be ASCII and should standalone)");
        if(text.size()!=1)
        {
            QMessageBox::warning(this,"Error","Incorrect input. Write again");
            size++;
            continue;
        }
        if(size-1)
            in<<text<<separator;
        else
            in<<text;
    }

    file.close();
    QMessageBox::information(this,"File saved","Data saved succesfully");
}

void MainWindow::ReadArray()
{
    QFile file("СорокаЛаб20_0.txt");
    QTextStream in(&file);

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QString text;
    while(!in.atEnd())
    {
        QChar ch;
        in >> ch;
        if(ch!=separator)
        {
            text+=ch;
        }
        else
            text+=" ";
    }
    file.close();
    QMessageBox::information(this,"Text in file",text);

}

void MainWindow::WriteAndSaveStructTXT()
{
    bool pushed=false;

    QFile file("СорокаЛаб20_1.txt");
    QTextStream in(&file);
    file.open(QIODevice::Append | QIODevice::Text);


    std::string s=QInputDialog::getText(nullptr, "Struct fields[1/7]", "Write name").toStdString();
    while(!check_name(s))
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input. Write again");
        s=QInputDialog::getText(nullptr, "Struct fields[1/7]", "Write name").toStdString();
    }


    ship.name=new char [s.size()+1];
    for(int i=0;i<s.size();i++)
        ship.name[i]=s[i];
    ship.name[s.size()]='\0';

    s=QInputDialog::getText(nullptr, "Struct fields[2/7]", "Write type of ship(W - warship P - passenger C - cargo F - fishing Y - yacht U-undefined)").toStdString();
    while(!check_type(s))
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input. Write again");
        s=QInputDialog::getText(nullptr, "Struct fields[2/7]", "Write type of ship(W - warship P - passenger C - cargo F - fishing Y - yacht U-undefined)").toStdString();
    }
    ship.type=s[0];

    s=QInputDialog::getText(nullptr, "Struct fields[3/7]", "Write amount of staff [1,"+QString::fromStdString(std::to_string(INT_MAX))+"]").toStdString();
    while(!check_staff(s))
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input. Write again");
        s=QInputDialog::getText(nullptr, "Struct fields[3/7]", "Write amount of staff [1,"+QString::fromStdString(std::to_string(INT_MAX))+"]").toStdString();
    }
    ship.human=stoi(s);

    s=QInputDialog::getText(nullptr, "Struct fields[4/7]", "Write cost of ship(>=0)").toStdString();
    while(!check_cost(s))
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input. Write again");
        s=QInputDialog::getText(nullptr, "Struct fields[4/7]", "Write cost of ship (>=0)").toStdString();
    }
    ship.price=stod(s);

    s=QInputDialog::getText(nullptr, "Struct fields[5/7]", "Write lifting capacity [1,"+QString::fromStdString(std::to_string(LLONG_MAX))+"]").toStdString();
    while(!check_lifting(s))
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input. Write again");
        s=QInputDialog::getText(nullptr, "Struct fields[5/7]", "Write lifting capacity [1,"+QString::fromStdString(std::to_string(LLONG_MAX))+"]").toStdString();
    }
    ship.attribut[0]=stoll(s);


    s=QInputDialog::getText(nullptr, "Struct fields[6/7]", "Write water diplacement [1,"+QString::fromStdString(std::to_string(LLONG_MAX))+"]").toStdString();
    while(!check_capacity(s))
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input. Write again");
        s=QInputDialog::getText(nullptr, "Struct fields[6/7]", "Write water diplacement [1,"+QString::fromStdString(std::to_string(LLONG_MAX))+"]").toStdString();
    }
    ship.attribut[1]=stoll(s);

    s=QInputDialog::getText(nullptr, "Struct fields[7/7]", "Write condition of the vessel (sank or not). If it sank write 1 otherwise 0").toStdString();
    while(!check_capacity(s))
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input. Write again");
        s=QInputDialog::getText(nullptr, "Struct fields[7/7]", "Write condition of the vessel (sank or not). If it sank write 1 otherwise 0").toStdString();
    }
    ship.zdoh=stoi(s);

    QString text="\n";
    int i=0;
    while(ship.name[i]!='\0')
    {
        text+=ship.name[i++];
    }
    text+=" "+(QString)(ship.type);
    text+=" "+std::to_string(ship.human);
    text+=" "+std::to_string(ship.price);
    text+=" "+std::to_string(ship.attribut[0]);
    text+=" "+std::to_string(ship.attribut[1]);
    text+=" "+std::to_string(ship.zdoh);
    in<<text;
    file.close();
    QMessageBox::information(this,"File saved","Data saved succesfully");

}

void MainWindow::ReadStructTXT()
{
    QFile file("CорокаЛаб20_1.txt");
    QTextStream in(&file);

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    QString text;
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList data = line.split(" ", Qt::SkipEmptyParts);
        qDebug()<<data.size();
        if(data.size()==0)
            continue;
        if (data.size() != 7||!check_name(data[0].toStdString())||!check_type(data[1].toStdString())||
            !check_staff(data[2].toStdString())||!check_cost(data[3].toStdString())||!check_lifting(data[4].toStdString())
            ||!check_capacity(data[5].toStdString())||!check_sank(data[6].toStdString())) {
            QMessageBox::warning(nullptr,"Error","Incorrect format of data");
            return;
        }

        ship.name=new char [data[0].size()+1];
        for(int i=0;i<data[0].size();i++)
            ship.name[i]=data[0][i].toLatin1();
        ship.name[data[0].size()]='\0';

        ship.type=data[1][0].toLatin1();
        ship.human=data[2].toInt();
        ship.price=data[3].toDouble();
        ship.attribut[0]=data[4].toLongLong();
        ship.attribut[1]=data[5].toLongLong();
        ship.zdoh=data[6].toInt();
        text=data[0]+ "|"+data[1]+"|"+data[2]+"|"+data[3]+"|"+data[4]+"|"+data[5]+"|"+data[6]+"\n";
    }
    file.close();
    QMessageBox::information(this,"Text in file",text);

}

void MainWindow::WriteAndSaveStructBIN()
{
    std::ofstream file("СорокаЛаб20_2.bin", std::ios::binary | std::ios::app);
    std::string s=QInputDialog::getText(nullptr, "Struct fields[1/7]", "Write name").toStdString();
    while(!check_name(s))
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input. Write again");
        s=QInputDialog::getText(nullptr, "Struct fields[1/7]", "Write name").toStdString();
    }


    ship.name=new char [s.size()+1];
    for(int i=0;i<s.size();i++)
        ship.name[i]=s[i];
    ship.name[s.size()]='\0';

    s=QInputDialog::getText(nullptr, "Struct fields[2/7]", "Write type of ship(W - warship P - passenger C - cargo F - fishing Y - yacht U-undefined)").toStdString();
    while(!check_type(s))
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input. Write again");
        s=QInputDialog::getText(nullptr, "Struct fields[2/7]", "Write type of ship(W - warship P - passenger C - cargo F - fishing Y - yacht U-undefined)").toStdString();
    }
    ship.type=s[0];

    s=QInputDialog::getText(nullptr, "Struct fields[3/7]", "Write amount of staff [1,"+QString::fromStdString(std::to_string(INT_MAX))+"]").toStdString();
    while(!check_staff(s))
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input. Write again");
        s=QInputDialog::getText(nullptr, "Struct fields[3/7]", "Write amount of staff [1,"+QString::fromStdString(std::to_string(INT_MAX))+"]").toStdString();
    }
    ship.human=stoi(s);

    s=QInputDialog::getText(nullptr, "Struct fields[4/7]", "Write cost of ship(>=0)").toStdString();
    while(!check_cost(s))
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input. Write again");
        s=QInputDialog::getText(nullptr, "Struct fields[4/7]", "Write cost of ship (>=0)").toStdString();
    }
    ship.price=stod(s);

    s=QInputDialog::getText(nullptr, "Struct fields[5/7]", "Write lifting capacity [1,"+QString::fromStdString(std::to_string(LLONG_MAX))+"]").toStdString();
    while(!check_lifting(s))
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input. Write again");
        s=QInputDialog::getText(nullptr, "Struct fields[5/7]", "Write lifting capacity [1,"+QString::fromStdString(std::to_string(LLONG_MAX))+"]").toStdString();
    }
    ship.attribut[0]=stoll(s);


    s=QInputDialog::getText(nullptr, "Struct fields[6/7]", "Write water diplacement [1,"+QString::fromStdString(std::to_string(LLONG_MAX))+"]").toStdString();
    while(!check_capacity(s))
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input. Write again");
        s=QInputDialog::getText(nullptr, "Struct fields[6/7]", "Write water diplacement [1,"+QString::fromStdString(std::to_string(LLONG_MAX))+"]").toStdString();
    }
    ship.attribut[1]=stoll(s);

    s=QInputDialog::getText(nullptr, "Struct fields[7/7]", "Write condition of the vessel (sank or not). If it sank write 1 otherwise 0").toStdString();
    while(!check_capacity(s))
    {
        QMessageBox::warning(nullptr,"Error","Incorrect input. Write again");
        s=QInputDialog::getText(nullptr, "Struct fields[7/7]", "Write condition of the vessel (sank or not). If it sank write 1 otherwise 0").toStdString();
    }
    ship.zdoh=stoi(s);

    file.write(reinterpret_cast<const char*>(&ship), sizeof(korabliki));
    file.close();
    QMessageBox::information(this,"File saved","Data saved succesfully");

}

void MainWindow::ReadStructBIN()
{
    std::ifstream file("СорокаЛаб20_2.bin", std::ios::binary);

    QString text;
    korabliki s;
    while (!file.eof()) {
        file.read(reinterpret_cast<char*>(&s), sizeof(korabliki));
        if (file.eof()) break;

        int i=0;
        while(s.name[i]!='\0')
            text+=s.name[i++];
        text+=";"+std::to_string(s.type)+";"+std::to_string(s.human)+";"+std::to_string(s.price)+";"+std::to_string(s.attribut[0])
                +";"+std::to_string(s.attribut[1])+";"+std::to_string(s.zdoh)+"\n";
    }
    file.close();

    QMessageBox::information(this,"Text in file",text);
}

void MainWindow::WriteAndSaveSentences()
{
    QString text = QInputDialog::getText(nullptr, "Text input", "Write the text. To stop input push Enter button");
    QFile file("СорокаЛаб20_3.txt");
    QTextStream in(&file);
    file.open(QIODevice::Append | QIODevice::Text);

    in<<text<<'\n';
    file.close();
    QMessageBox::information(this,"File saved","Data saved succesfully");
}

void MainWindow::ReadSentences()
{
    QFile file("СорокаЛаб20_3.txt");
    QTextStream in(&file);

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString text;
    while(!in.atEnd()){
        QString line = in.readLine();
        text+=line;
    }
    file.close();
    QMessageBox::information(this,"Text in file",text);

}

void MainWindow::menu()
{
    bool u=true;
    int pb;

    while(u)
    {


        bool pushed=false;
        pb=QInputDialog::getInt(nullptr, "MENU:", "1. Написать и сохранить текст\n2. Считать текст из файла\n"
                                                              "3. Написать и сохранить массив char\n4. Считать массив из файла\n"
                                                              "5. Написать и сохранить структуру в текстовый файл\n6. Считать структуру из текстового файла\n"
                                                              "7. Написать и сохранить структуру в бинарный файл\n8. Считать структуру из бинарного файла\n"
                                                              "9. Написать и сохранить предложение\n10.Считать все предложения из файла\n"
                                                              "11. Выход\n\nВведите номер пункта:", 0, 1, 11, 1, &pushed);

        switch(pb)
        {
        case 1:
            WriteAndSaveText();
            break;
        case 2:
            ReadText();
            break;
        case 3:
            WriteAndSaveArray();
            break;
        case 4:
            ReadArray();
            break;
        case 5:
            WriteAndSaveStructTXT();
            break;
        case 6:
            ReadStructTXT();
            break;
        case 7:
            WriteAndSaveStructBIN();
            break;
        case 8:
            ReadStructBIN();
            break;
        case 9:
            WriteAndSaveSentences();
            break;
        case 10:
            ReadSentences();
            break;
        case 11:
            exit(0);
            break;
        default:
            break;
        }
    }
}
