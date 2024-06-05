#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{

    ui->setupUi(this);
    colors.push_back(std::make_pair(QColor("#F7ADA9"), QColor("#F9DEC1")));
    colors.push_back(std::make_pair(QColor("#45CEFC"), QColor("#B5ECFD")));
    colors.push_back(std::make_pair(QColor("#AF93D5"), QColor("#F4BEEC")));
    colors.push_back(std::make_pair(QColor("#90DFE5"), QColor("#88F2BF")));
    colors.push_back(std::make_pair(QColor("#F58A8A"), QColor("#FCD350")));
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
    QString styleSheet =
        "QPushButton {"
        "   background-color: white;"
        "   border-radius: 20%;"
        "   color: black;"
        "   font-size: 20px;"
        "}"
        "QPushButton:hover {"
        "   background-color: lightgray;"
        "}"
        "QPushButton:pressed {"
        "   background-color: gainsboro;"
        "}";
    ui->pushButton->setStyleSheet(styleSheet);
    ui->pushButton_2->setStyleSheet(styleSheet);
    ui->pushButton_3->setStyleSheet(styleSheet);

    // Установите стили для оставшихся кнопок
    int index = 0;
    ui->pushButton_4->setStyleSheet(QString("QPushButton { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 %1, stop:1 %2); }").arg(colors[index].first.name(), colors[index].second.name()));
    index = 1;
    ui->pushButton_5->setStyleSheet(QString("QPushButton { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 %1, stop:1 %2); }").arg(colors[index].first.name(), colors[index].second.name()));
    index = 2;
    ui->pushButton_6->setStyleSheet(QString("QPushButton { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 %1, stop:1 %2); }").arg(colors[index].first.name(), colors[index].second.name()));
    index = 3;
    ui->pushButton_7->setStyleSheet(QString("QPushButton { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 %1, stop:1 %2); }").arg(colors[index].first.name(), colors[index].second.name()));
    index = 4;
    ui->pushButton_8->setStyleSheet(QString("QPushButton { background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 %1, stop:1 %2); }").arg(colors[index].first.name(), colors[index].second.name()));

    logo = QPixmap(":img/menuLogo2.png");
    logo = logo.scaled(500, 600, Qt::AspectRatioMode::KeepAspectRatio, Qt::TransformationMode::SmoothTransformation);
    ui->label->setPixmap(logo);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->frame->setFrameShape(QFrame::NoFrame);


}
Menu::~Menu()
{
    delete ui;
}

QPalette Menu::getPaletteW()
{
    return this->palette();
}

void Menu::on_pushButton_clicked()
{
    emit openPlay();
    this->close();
}





void Menu::on_pushButton_3_clicked()
{
    emit openSolve();
    this->close();
}


void Menu::on_pushButton_2_clicked()
{
    emit openInfo();

    this->close();
}


void Menu::on_pushButton_4_clicked()
{
    int randomIndex = 0;
    QPalette palette;
    QLinearGradient gradient(0, 0, 0, 400);
    QColor c1 = colors[randomIndex].first;
    QColor c2 = colors[randomIndex].second;
    gradient.setColorAt(0, c1);
    gradient.setColorAt(1, c2);

    this->setAutoFillBackground(true);
    palette.setBrush(QPalette::Window, gradient);
    this->setPalette(palette);
}


void Menu::on_pushButton_5_clicked()
{
    int randomIndex = 1;
    QPalette palette;
    QLinearGradient gradient(0, 0, 0, 400);
    QColor c1 = colors[randomIndex].first;
    QColor c2 = colors[randomIndex].second;
    gradient.setColorAt(0, c1);
    gradient.setColorAt(1, c2);

    this->setAutoFillBackground(true);
    palette.setBrush(QPalette::Window, gradient);
    this->setPalette(palette);
}


void Menu::on_pushButton_6_clicked()
{
    int randomIndex = 2;
    QPalette palette;
    QLinearGradient gradient(0, 0, 0, 400);
    QColor c1 = colors[randomIndex].first;
    QColor c2 = colors[randomIndex].second;
    gradient.setColorAt(0, c1);
    gradient.setColorAt(1, c2);

    this->setAutoFillBackground(true);
    palette.setBrush(QPalette::Window, gradient);
    this->setPalette(palette);
}


void Menu::on_pushButton_7_clicked()
{
    int randomIndex = 3;
    QPalette palette;
    QLinearGradient gradient(0, 0, 0, 400);
    QColor c1 = colors[randomIndex].first;
    QColor c2 = colors[randomIndex].second;
    gradient.setColorAt(0, c1);
    gradient.setColorAt(1, c2);

    this->setAutoFillBackground(true);
    palette.setBrush(QPalette::Window, gradient);
    this->setPalette(palette);
}


void Menu::on_pushButton_8_clicked()
{
    int randomIndex = 4;
    QPalette palette;
    QLinearGradient gradient(0, 0, 0, 400);
    QColor c1 = colors[randomIndex].first;
    QColor c2 = colors[randomIndex].second;
    gradient.setColorAt(0, c1);
    gradient.setColorAt(1, c2);

    this->setAutoFillBackground(true);
    palette.setBrush(QPalette::Window, gradient);
    this->setPalette(palette);
}

