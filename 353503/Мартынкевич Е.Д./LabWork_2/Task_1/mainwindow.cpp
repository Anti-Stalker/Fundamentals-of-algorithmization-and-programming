#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    central_widget = new QWidget;
    this->setCentralWidget(central_widget);

    QRegularExpression regExp("([0-2][0-9]|3[0-1])\\.(0[0-9]|1[0-2])\\.\\d{4}");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regExp, this);
    QIntValidator* intValidator = new QIntValidator(this);

    table = new QTableWidget(0, 8, this);
    QStringList stolbzi{"Date", "Day of week" , "Next day", "Previous day","Is leap","Week number","Duration","Next birthday"};
    table->setHorizontalHeaderLabels(stolbzi);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    bearthday = new Date("18.01.2006");

    bearthday_edit = new QLineEdit(this);
    bearthday_edit->setFixedWidth(200);
    bearthday_edit->setValidator(validator);
    bearthday_edit->setPlaceholderText("dd.mm.yyyy");
    bearthday_label = new QLabel;
    bearthday_label->setText("Ваш день рождения: " + bearthday->day_string);
    bearthday_button = new QPushButton("Изменить");

    open_table_button = new QPushButton("Открыть файл");

    add_date_label = new QLabel("Добавить дату");
    add_date_edit = new QLineEdit(this);
    add_date_edit->setValidator(validator);
    add_date_edit->setFixedWidth(200);
    add_date_edit->setPlaceholderText("dd.mm.yyyy");
    add_date_button = new QPushButton("Добавить");
    add_date_button->setEnabled(false);

    del_date_label = new QLabel("Удалить дату по номеру");
    del_date_edit = new QLineEdit(this);
    del_date_edit->setFixedWidth(200);
    del_date_edit->setValidator(intValidator);
    del_date_button = new QPushButton("Удалить");
    del_date_button->setEnabled(false);

    new_file_button = new QPushButton;
    new_file_button->setText("Создать файл");
    opened_file_name = new QLabel("Файл не открыт");

    close_file_button = new QPushButton("Закрыть файл");

    change_date_label = new QLabel("Новая дата", this);
    number_date_label = new QLabel("Номер изменяемой даты", this);
    number_date_edit = new QLineEdit(this);
    number_date_edit->setFixedWidth(200);
    number_date_edit->setValidator(intValidator);
    change_date_edit = new QLineEdit(this);
    change_date_edit->setFixedWidth(200);
    change_date_edit->setValidator(validator);
    change_date_edit->setPlaceholderText("dd.mm.yyyy");
    change_date_button = new QPushButton("Изменить", this);
    change_date_button->setEnabled(false);

    layout = new QGridLayout;
    layout->addWidget(table, 0, 0, 31, 1);

    layout->addWidget(bearthday_label, 0, 1);
    layout->addWidget(bearthday_edit, 1, 1);
    layout->addWidget(bearthday_button, 2, 1);

    layout->addWidget(add_date_label, 4, 1);
    layout->addWidget(add_date_edit, 5, 1);
    layout->addWidget(add_date_button, 6, 1);

    layout->addWidget(del_date_label, 8, 1);
    layout->addWidget(del_date_edit, 9, 1);
    layout->addWidget(del_date_button, 10, 1);

    layout->addWidget(change_date_label, 12, 1);
    layout->addWidget(change_date_edit, 13, 1);
    layout->addWidget(number_date_label, 14, 1);
    layout->addWidget(number_date_edit, 15, 1);
    layout->addWidget(change_date_button, 16, 1);

    layout->addWidget(opened_file_name, 27, 1);
    layout->addWidget(new_file_button, 28, 1);
    layout->addWidget(open_table_button, 29, 1);
    layout->addWidget(close_file_button, 30, 1);
    central_widget->setLayout(layout);

    connect(bearthday_button, &QPushButton::clicked, this, &MainWindow::BearthdayButtonClick);
    connect(open_table_button, &QPushButton::clicked, this, &MainWindow::OpenFile);
    connect(add_date_button, &QPushButton::clicked, this, &MainWindow::AddDateButtonClick);
    connect(del_date_button, &QPushButton::clicked, this, &MainWindow::DelDateButtonClick);
    connect(new_file_button, &QPushButton::clicked, this, &MainWindow::CreateFileButtonClick);
    connect(close_file_button, &QPushButton::clicked, this, &MainWindow::CloseFileButtonClick);
    connect(change_date_button, &QPushButton::clicked, this, &MainWindow::ChangeDateButtonClick);
}

MainWindow::~MainWindow()
{
    delete bearthday,

    delete layout;
    delete table;

    delete bearthday_edit;
    delete add_date_edit;
    delete del_date_edit;
    delete change_date_edit;
    delete number_date_edit;

    delete bearthday_label;
    delete add_date_label;
    delete del_date_label;
    delete opened_file_name;
    delete number_date_label;
    delete change_date_label;

    delete bearthday_button;
    delete open_table_button;
    delete add_date_button;
    delete del_date_button;
    delete new_file_button;
    delete change_date_button;
    delete close_file_button;

    delete ui;
}

void MainWindow::BearthdayUpdateTable(Date *bday)
{
    for (int i = 0; i < dates.size(); i++) {
        table->setItem(i, 7, new QTableWidgetItem(QString::number(dates[i].daysTillYourBithday(*bday))));
    }
    bearthday_label->setText("Ваш день рождения: " + bearthday->day_string);
}

void MainWindow::OpenFile()
{
    dates.clear();
    opened_file = QFileDialog::getOpenFileName(nullptr, "Выберите файл", "", "Текстовые файлы (*.dates);;Все файлы (*)");

    QFile file(opened_file);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Ошибка", "Файл не выбран");
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        dates.append(Date(line));
    }

    add_date_button->setEnabled(true);
    del_date_button->setEnabled(true);
    change_date_button->setEnabled(true);
    int lastSlashIndex = opened_file.lastIndexOf('/');
    opened_file_name->setText("Открыт файл:\n" + opened_file.mid(lastSlashIndex + 1));
    table->setHorizontalHeaderLabels(headers);

    UpdateTable();
    file.close();
}

void MainWindow::UpdateTable()
{
    table->setRowCount(0);
    for(int i = 0; i < dates.size(); ++i) {
        table->insertRow(table->rowCount());
        table->setItem(i, 0, new QTableWidgetItem(dates[i].day_string));
        table->setItem(i, 1, new QTableWidgetItem(dates[i].DayOfWeekString()));
        table->setItem(i, 2, new QTableWidgetItem(dates[i].nextDay().day_string));
        table->setItem(i, 3, new QTableWidgetItem(dates[i].previousDay().day_string));
        table->setItem(i, 4, new QTableWidgetItem(QString::number(dates[i].isLeapYear(dates[i].getYear()))));
        table->setItem(i, 5, new QTableWidgetItem(QString::number(dates[i].weekNumber())));
        int dur = dates[i].duration(dates[i == dates.size() - 1?0:i+1]);
        table->setItem(i, 6, new QTableWidgetItem(QString::number(dur)));
        table->setItem(i, 7, new QTableWidgetItem(QString::number(dates[i].daysTillYourBithday(*bearthday))));
    }
    add_date_label->setText(QString("Добавить дату"));
}

void MainWindow::BearthdayButtonClick()
{
    Date *new_bearthday = new Date(bearthday_edit->text());
    if (new_bearthday->is_correct_date) {
        bearthday = new_bearthday;
        BearthdayUpdateTable(bearthday);
    }
    else {
        QMessageBox::critical(nullptr, "Ошибка", "Неверная дата");
        delete new_bearthday;
    }
    bearthday_edit->setText("");
}

void MainWindow::AddDateButtonClick()
{
    Date *new_date = new Date(add_date_edit->text());
    if (new_date->is_correct_date) {
        AddDate(new_date);
        QFile file(opened_file);

        if (!file.open(QIODevice::Append | QIODevice::Text)) {
            QMessageBox::critical(nullptr, "Ошибка", "Файл не выбран");
        }
        QTextStream stream(&file);
        stream << new_date->day_string << '\n';
        file.close();

    }
    else {
        QMessageBox::critical(nullptr, "Ошибка", "Неверная дата");
    }
    add_date_edit->setText("");
}

void MainWindow::DelDateButtonClick()
{
    if (//del_date_edit->text() != "" &&
        del_date_edit->text().toInt() <= dates.size()) {
        table->removeRow(del_date_edit->text().toInt()-1);
        dates.erase(dates.begin() + del_date_edit->text().toInt() - 1);
    }
    else {
        QMessageBox::critical(nullptr, "Ошибка", "Неверный номер");
    }
    del_date_edit->setText("");
    UpdateFile();

}


void MainWindow::AddDate(Date *new_date)
{
    dates.push_back(*new_date);
    UpdateTable();
}

void MainWindow::ClearAddDateEdit()
{
    add_date_edit->setText("");
}

void MainWindow::CreateFileButtonClick()
{
    QString defaultPath = QDir::homePath();
    QString filter = tr("Text Files (*.txt);;All Files (*)");

    opened_file = QFileDialog::getSaveFileName(this, tr("Создать файл"), defaultPath, filter);
    if (opened_file != "") {
        opened_file += ".dates";
    }

    if (!opened_file.isEmpty())
    {
        QFile file(opened_file);
        if (file.open(QIODevice::WriteOnly))
        {
            add_date_button->setEnabled(true);
            del_date_button->setEnabled(true);
            change_date_button->setEnabled(true);
            int lastSlashIndex = opened_file.lastIndexOf('/');
            opened_file_name->setText("Открыт файл:\n" + opened_file.mid(lastSlashIndex + 1));
            table->setHorizontalHeaderLabels(headers);
            file.close();
        }
        else
        {
            QMessageBox::critical(nullptr, "Ошибка", "Ошибка создания файла");
        }
    }
    else
    {
        QMessageBox::critical(nullptr, "Ошибка", "Ошибка создания файла");
    }
}

void MainWindow::CloseFileButtonClick()
{
    if (opened_file != "") {
        opened_file ="";
        opened_file_name->setText("Файл не открыт");
        add_date_button->setEnabled(false);
        del_date_button->setEnabled(false);
        change_date_button->setEnabled(false);
        table->clear();
        table->setRowCount(0);
        dates.clear();
        table->setHorizontalHeaderLabels(headers);
    }
}

void MainWindow::ChangeDateButtonClick()
{
    int number = number_date_edit->text().toInt();
    QString string_date = change_date_edit->text();

    if (number <= dates.size() && Date(string_date).is_correct_date) {
        dates[number-1] = Date(string_date);
    }
    else {
        QMessageBox::critical(nullptr, "Ошибка", "Неверные данные");
    }
    change_date_edit->setText("");
    number_date_edit->setText("");
    UpdateTable();
    UpdateFile();
}

void MainWindow::UpdateFile()
{
    QFile file(opened_file);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        for (int i = 0; i < dates.size(); i++) {
            stream << dates[i].day_string << '\n';
        }
        file.close();
    }
}
