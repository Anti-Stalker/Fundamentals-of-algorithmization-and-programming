#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>

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
    QDoubleValidator* doubleValidator = new QDoubleValidator(this);

    courier_table = new QTableWidget(0, 5, this);
    zakaz_table = new QTableWidget(0, 6, this);
    bad_zakaz_table = new QTableWidget(0, 5, this);
    QStringList stolbzi_bad{"Номер", "Адресс" , "Дата", "Время","Масса"};
    QStringList stolbzi_zakaz{"Номер", "Адресс" , "Дата", "Время","Масса","Курьер"};
    QStringList stolbzi_courier{"Номер", "ФИО" , "Начало работы", "Конец работы", "Грузподьемность"};
    courier_table->setHorizontalHeaderLabels(stolbzi_courier);
    courier_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    zakaz_table->setHorizontalHeaderLabels(stolbzi_zakaz);
    zakaz_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    bad_zakaz_table->setHorizontalHeaderLabels(stolbzi_bad);
    bad_zakaz_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    bad_zakaz_table->setVisible(true);
    zakaz_table->setVisible(true);
    courier_table->setVisible(true);

    constructor_zakaz_label = new QLabel("конструктор заказа");
    number_zakaz_edit = new QLineEdit(this);
    number_zakaz_edit->setFixedWidth(200);
    number_zakaz_edit->setPlaceholderText("номер заказа");
    number_zakaz_edit->setValidator(intValidator);
    adress_zakaz_edit = new QLineEdit(this);
    adress_zakaz_edit->setFixedWidth(200);
    adress_zakaz_edit->setPlaceholderText("адресс заказа");
    data_zakaz_edit = new QLineEdit(this);
    data_zakaz_edit->setFixedWidth(200);
    data_zakaz_edit->setPlaceholderText("дата доставки заказа");
    time_zakaz_edit = new QLineEdit(this);
    time_zakaz_edit->setFixedWidth(200);
    time_zakaz_edit->setPlaceholderText("время доставки заказа");
    massa_zakaz_edit = new QLineEdit(this);
    massa_zakaz_edit->setFixedWidth(200);
    massa_zakaz_edit->setValidator(intValidator);
    massa_zakaz_edit->setPlaceholderText("вес заказа");

    constructor_courier_label = new QLabel("конструктор курьера");
    number_courier_edit = new QLineEdit(this);
    number_courier_edit->setFixedWidth(200);
    number_courier_edit->setPlaceholderText("номер курьера");
    number_courier_edit->setValidator(intValidator);
    fio_courier_edit = new QLineEdit(this);
    fio_courier_edit->setFixedWidth(200);
    fio_courier_edit->setPlaceholderText("фио курьера");
    begin_time_courier_edit = new QLineEdit(this);
    begin_time_courier_edit->setFixedWidth(200);
    begin_time_courier_edit->setPlaceholderText("начало работы курьера");
    end_time_courier_edit = new QLineEdit(this);
    end_time_courier_edit->setFixedWidth(200);
    end_time_courier_edit->setPlaceholderText("конец работы курьера");
    min_mass_courier_edit = new QLineEdit(this);
    min_mass_courier_edit->setFixedWidth(200);
    min_mass_courier_edit->setValidator(doubleValidator);
    min_mass_courier_edit->setPlaceholderText("грузоподьемность");

    add_zakaz_button = new QPushButton("добавить заказ");
    add_courier_button = new QPushButton("добавить курьера");
    add_zakaz_button->setEnabled(false);
    add_courier_button->setEnabled(false);

    change_label = new QLabel("Изменение");

    change_zakaz_edit = new QLineEdit(this);
    change_zakaz_edit->setFixedWidth(200);
    change_zakaz_edit->setPlaceholderText("Номер измен./удал. заказа");

    change_courier_edit = new QLineEdit(this);
    change_courier_edit->setFixedWidth(200);
    change_courier_edit->setPlaceholderText("Номер измен./удал. курьера");

    change_zakaz_button = new QPushButton("Изменить заказ");
    change_courier_button = new QPushButton("Изменить курьера");
    change_zakaz_button->setEnabled(false);
    change_courier_button->setEnabled(false);

    delete_label = new QLabel("Удаление");

    delete_zakaz_button = new QPushButton("Удалить заказ");
    delete_courier_button = new QPushButton("Удалить курьера");
    delete_zakaz_button->setEnabled(false);
    delete_courier_button->setEnabled(false);

    new_file_zakaz_button = new QPushButton("Создать файл заказа");
    open_table_zakaz_button = new QPushButton("Открыть файл заказа");
    close_file_zakaz_button = new QPushButton("Закрыть файл заказа");

    new_file_courier_button = new QPushButton("Создать файл курьеров");
    open_table_courier_button = new QPushButton("Открыть файл курьеров");
    close_file_courier_button = new QPushButton("Закрыть файл курьеров");

    opened_zakaz_file_label = new QLabel("Файл не открыт");
    opened_courier_file_label = new QLabel("Файл не открыт");

    layout = new QGridLayout;

    layout->addWidget(zakaz_table, 0, 0, 11, 1);
    layout->addWidget(courier_table, 11, 0, 11, 1);
    layout->addWidget(bad_zakaz_table, 22, 0, 11, 1);

    layout->addWidget(constructor_zakaz_label, 0, 1);
    layout->addWidget(number_zakaz_edit, 1, 1);
    layout->addWidget(adress_zakaz_edit, 2, 1);
    layout->addWidget(data_zakaz_edit, 3, 1);
    layout->addWidget(time_zakaz_edit, 4, 1);
    layout->addWidget(massa_zakaz_edit, 5, 1);

    layout->addWidget(constructor_courier_label, 0, 2);
    layout->addWidget(number_courier_edit, 1, 2);
    layout->addWidget(fio_courier_edit, 2, 2);
    layout->addWidget(begin_time_courier_edit, 3, 2);
    layout->addWidget(end_time_courier_edit, 4, 2);
    layout->addWidget(min_mass_courier_edit, 5, 2);

    layout->addWidget(add_zakaz_button, 7, 1);
    layout->addWidget(add_courier_button, 7, 2);

    layout->addWidget(change_label, 10, 1, 1, 1);
    layout->addWidget(change_zakaz_edit, 11, 1);
    layout->addWidget(change_courier_edit, 11, 2);
    layout->addWidget(change_zakaz_button, 12, 1);
    layout->addWidget(change_courier_button, 12, 2);

    layout->addWidget(delete_label, 14, 1, 1, 1);
    layout->addWidget(delete_zakaz_button, 15, 1);
    layout->addWidget(delete_courier_button, 15, 2);

    layout->addWidget(new_file_zakaz_button, 19, 1);
    layout->addWidget(new_file_courier_button, 19, 2);
    layout->addWidget(close_file_zakaz_button, 20, 1);
    layout->addWidget(close_file_courier_button, 20, 2);
    layout->addWidget(open_table_zakaz_button, 21, 1);
    layout->addWidget(open_table_courier_button, 21, 2);

    layout->addWidget(opened_zakaz_file_label, 24, 1);
    layout->addWidget(opened_courier_file_label, 24, 2);

    central_widget->setLayout(layout);

    connect(open_table_zakaz_button, &QPushButton::clicked, this, &MainWindow::OpenZakazFile);
    connect(open_table_courier_button, &QPushButton::clicked, this, &MainWindow::OpenCourierFile);
    connect(close_file_zakaz_button, &QPushButton::clicked, this, &MainWindow::CloseZakazFile);
    connect(close_file_courier_button, &QPushButton::clicked, this, &MainWindow::CloseCourierFile);
    connect(new_file_zakaz_button, &QPushButton::clicked, this, &MainWindow::NewZakazFile);
    connect(new_file_courier_button, &QPushButton::clicked, this, &MainWindow::NewCourierFile);

    connect(add_zakaz_button, &QPushButton::clicked, this, &MainWindow::AddZakazButtonClick);
    connect(add_courier_button, &QPushButton::clicked, this, &MainWindow::AddCourierButtonClick);
    connect(change_zakaz_button, &QPushButton::clicked, this, &MainWindow::ChangeZakazButtonClick);
    connect(change_courier_button, &QPushButton::clicked, this, &MainWindow::ChangeCourierButtonClick);
    connect(delete_zakaz_button, &QPushButton::clicked, this, &MainWindow::DeleteZakazButtonClick);
    connect(delete_courier_button, &QPushButton::clicked, this, &MainWindow::DeleteCourierButtonClick);
}

MainWindow::~MainWindow()
{
    delete ui;

    delete layout;
    delete zakaz_table;
    delete bad_zakaz_table;
    delete courier_table;
    delete central_widget;

    delete constructor_zakaz_label;
    delete constructor_courier_label;

    delete number_zakaz_edit;
    delete adress_zakaz_edit;
    delete data_zakaz_edit;
    delete time_zakaz_edit;
    delete massa_zakaz_edit;

    delete number_courier_edit;
    delete fio_courier_edit;
    delete begin_time_courier_edit;
    delete end_time_courier_edit;
    delete min_mass_courier_edit;

    delete add_zakaz_button;
    delete add_courier_button;

    delete change_label;

    delete change_zakaz_edit;
    delete change_courier_edit;

    delete change_zakaz_button;
    delete change_courier_button;

    delete delete_label;

    delete delete_zakaz_button;
    delete delete_courier_button;

    delete new_file_zakaz_button;
    delete close_file_zakaz_button;
    delete open_table_zakaz_button;

    delete new_file_courier_button;
    delete close_file_courier_button;
    delete open_table_courier_button;

    delete opened_zakaz_file_label;
    delete opened_courier_file_label;
}

void MainWindow::OpenZakazFile()
{
    zakazes.clear();
    opened_zakaz_file_string = QFileDialog::getOpenFileName(nullptr, "Выберите файл", "", "Текстовые файлы (*.zakaz);;Все файлы (*)");

    QFile file(opened_zakaz_file_string);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Ошибка", "Файл не выбран");
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        int number;
        QString adress;
        QDate data;
        QString da;
        QTime time;
        QString ti;
        int massa;
        in >> number >> adress >> da >> ti >> massa;

        data = QDate::fromString(da, "dd.MM.yyyy");
        time = QTime::fromString(ti, "hh:mm:ss");

        if (data.isValid() && time.isValid()) {
            zakazes.push_back(Zakaz(number, adress, data, time, massa));
        }
        else {
            QMessageBox::critical(nullptr, "Ошибка", "Некорректный ввод");
        }
    }

    add_zakaz_button->setEnabled(true);
    delete_zakaz_button->setEnabled(true);
    change_zakaz_button->setEnabled(true);
    int lastSlashIndex = opened_zakaz_file_string.lastIndexOf('/');
    opened_zakaz_file_label->setText("Открыт файл:\n" + opened_zakaz_file_string.mid(lastSlashIndex + 1));
    zakaz_table->setHorizontalHeaderLabels(headers);

    UpdateTable();
    file.close();
}

void MainWindow::OpenCourierFile()
{
    courieres.clear();
    opened_courier_file_string = QFileDialog::getOpenFileName(nullptr, "Выберите файл", "", "Текстовые файлы (*.courier);;Все файлы (*)");

    QFile file(opened_courier_file_string);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(nullptr, "Ошибка", "Файл не выбран");
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        int number;
        QString fio;
        QTime begin_time;
        QString beg;
        QTime end_time;
        QString end;
        double min_mass;

        in >> number >> fio >> beg >> end >> min_mass;

        begin_time = QTime::fromString(beg, "hh:mm:ss");
        end_time = QTime::fromString(end, "hh:mm:ss");

        if (begin_time.isValid() && end_time.isValid()) {
            courieres.push_back(Courier(number, fio, begin_time, end_time, min_mass));
        }
        else {
            QMessageBox::critical(nullptr, "Ошибка", "Некорректный ввод");
        }
    }

    add_courier_button->setEnabled(true);
    delete_courier_button->setEnabled(true);
    change_courier_button->setEnabled(true);
    int lastSlashIndex = opened_courier_file_string.lastIndexOf('/');
    opened_courier_file_label->setText("Открыт файл:\n" + opened_courier_file_string.mid(lastSlashIndex + 1));
    courier_table->setHorizontalHeaderLabels(headers);

    UpdateTable();
    file.close();
}

void MainWindow::CloseZakazFile()
{
    UpdateZakazFile();
    QStringList stolbzi_zakaz{"Номер", "Адресс" , "Дата", "Время","Масса","Курьер"};

    if (opened_zakaz_file_string != "") {
        opened_zakaz_file_string ="";
        opened_zakaz_file_label->setText("Файл не открыт");
        add_zakaz_button->setEnabled(false);
        delete_zakaz_button->setEnabled(false);
        change_zakaz_button->setEnabled(false);
        zakaz_table->clear();
        zakaz_table->setRowCount(0);
        zakazes.clear();
        zakaz_table->setHorizontalHeaderLabels(stolbzi_zakaz);
    }
}

void MainWindow::CloseCourierFile()
{
    UpdateCourierFile();
    QStringList stolbzi_courier{"Номер", "ФИО" , "Начало работы", "Конец работы", "Грузподьемность"};

    if (opened_courier_file_string != "") {
        opened_courier_file_string ="";
        opened_courier_file_label->setText("Файл не открыт");
        add_courier_button->setEnabled(false);
        delete_courier_button->setEnabled(false);
        change_courier_button->setEnabled(false);
        courier_table->clear();
        courier_table->setRowCount(0);
        courieres.clear();
        courier_table->setHorizontalHeaderLabels(stolbzi_courier);
    }
}

void MainWindow::NewZakazFile()
{
    QString defaultPath = QDir::homePath();
    QString filter = tr("Text Files (*.txt);;All Files (*)");

    opened_zakaz_file_string = QFileDialog::getSaveFileName(this, tr("Создать файл"), defaultPath, filter);
    if (opened_zakaz_file_string != "") {
        opened_zakaz_file_string += ".zakaz";
    }

    if (!opened_zakaz_file_string.isEmpty())
    {
        QFile file(opened_zakaz_file_string);
        if (file.open(QIODevice::WriteOnly))
        {
            add_zakaz_button->setEnabled(true);
            delete_zakaz_button->setEnabled(true);
            change_zakaz_button->setEnabled(true);
            int lastSlashIndex = opened_zakaz_file_string.lastIndexOf('/');
            opened_zakaz_file_label->setText("Открыт файл:\n" + opened_zakaz_file_string.mid(lastSlashIndex + 1));
            zakaz_table->setHorizontalHeaderLabels(headers);
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

void MainWindow::NewCourierFile()
{
    QString defaultPath = QDir::homePath();
    QString filter = tr("Text Files (*.txt);;All Files (*)");

    opened_courier_file_string = QFileDialog::getSaveFileName(this, tr("Создать файл"), defaultPath, filter);
    if (opened_courier_file_string != "") {
        opened_courier_file_string += ".courier";
    }

    if (!opened_courier_file_string.isEmpty())
    {
        QFile file(opened_courier_file_string);
        if (file.open(QIODevice::WriteOnly))
        {
            add_courier_button->setEnabled(true);
            delete_courier_button->setEnabled(true);
            change_courier_button->setEnabled(true);
            int lastSlashIndex = opened_courier_file_string.lastIndexOf('/');
            opened_courier_file_label->setText("Открыт файл:\n" + opened_courier_file_string.mid(lastSlashIndex + 1));
            courier_table->setHorizontalHeaderLabels(headers);
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

void MainWindow::AddZakazButtonClick()
{
    QDate data = QDate::fromString(data_zakaz_edit->text(), "dd.MM.yyyy");
    QTime time = QTime::fromString(time_zakaz_edit->text(), "hh:mm:ss");
    QString number_string = number_zakaz_edit->text();
    int number = number_string.toInt();
    QString adress = adress_zakaz_edit->text();
    QString massa_string = massa_zakaz_edit->text();
    int massa = massa_string.toInt();

    if (data.isValid() && time.isValid() && adress != "" && number_string != "" && massa_string != "") {
        Zakaz good(number, adress, data, time, massa);
        zakazes.push_back(good);
        UpdateTable();
    }
    else {
        QMessageBox::critical(nullptr, "Неверные данные", "Неверные данные");
    }

    number_zakaz_edit->setText("");
    adress_zakaz_edit->setText("");
    data_zakaz_edit->setText("");
    time_zakaz_edit->setText("");
    massa_zakaz_edit->setText("");
}

void MainWindow::AddCourierButtonClick()
{

    QTime begin_time = QTime::fromString(begin_time_courier_edit->text(), "hh:mm:ss");
    QTime end_time = QTime::fromString(end_time_courier_edit->text(), "hh:mm:ss");
    QString number_string = number_courier_edit->text();
    int number = number_string.toInt();
    QString fio = fio_courier_edit->text();
    QString min_mass_string = min_mass_courier_edit->text();
    int min_mass = min_mass_string.toInt();

    if (begin_time.isValid() && end_time.isValid() && fio != "" && number_string != "" && min_mass_string != "") {
        Courier good(number, fio, begin_time, end_time, min_mass);
        courieres.push_back(good);
        UpdateTable();
    }
    else {
        QMessageBox::critical(nullptr, "Неверные данные", "Неверные данные");
    }

    number_courier_edit->setText("");
    fio_courier_edit->setText("");
    begin_time_courier_edit->setText("");
    end_time_courier_edit->setText("");
    min_mass_courier_edit->setText("");
}

void MainWindow::ChangeZakazButtonClick()
{
    QDate data = QDate::fromString(data_zakaz_edit->text(), "dd.MM.yyyy");
    QTime time = QTime::fromString(time_zakaz_edit->text(), "hh:mm:ss");
    int index = change_zakaz_edit->text().toInt();

    if (index > -1 && index < zakazes.size() && data.isValid() && time.isValid()) {
        int number = number_zakaz_edit->text().toInt();
        QString adress = adress_zakaz_edit->text();
        int massa = massa_zakaz_edit->text().toInt();
        Zakaz good(number, adress, data, time, massa);
        zakazes[index] = good;
        UpdateTable();
    }
    else {
        QMessageBox::critical(nullptr, "Неверные данные", "Неверные данные");
    }

    number_zakaz_edit->text() = "";
    adress_zakaz_edit->text() = "";
    data_zakaz_edit->text() = "";
    time_zakaz_edit->text() = "";
    massa_zakaz_edit->text() = "";
}

void MainWindow::ChangeCourierButtonClick()
{
    QTime begin_time = QTime::fromString(begin_time_courier_edit->text(), "hh:mm:ss");
    QTime end_time = QTime::fromString(end_time_courier_edit->text(), "hh:mm:ss");
    int index = change_courier_edit->text().toInt();

    if (index > -1 && index < courieres.size() && begin_time.isValid() && end_time.isValid()) {
        int number = number_courier_edit->text().toInt();
        QString fio = fio_courier_edit->text();
        int min_mass = min_mass_courier_edit->text().toInt();
        Courier good(number, fio, begin_time, end_time, min_mass);
        courieres[index] = good;
        UpdateTable();
    }
    else {
        QMessageBox::critical(nullptr, "Неверные данные", "Неверные данные");
    }

    number_courier_edit->text() = "";
    fio_courier_edit->text() = "";
    begin_time_courier_edit->text() = "";
    end_time_courier_edit->text() = "";
    min_mass_courier_edit->text() = "";
}

void MainWindow::DeleteZakazButtonClick()
{
    int index = change_zakaz_edit->text().toInt();

    if (index > -1 && index < zakazes.size()) {
        zakazes.erase(zakazes.begin() + index);
        UpdateTable();
    }
    else {
        QMessageBox::critical(nullptr, "Неверные данные", "Неверные данные");
    }
}

void MainWindow::DeleteCourierButtonClick()
{
   int index = change_courier_edit->text().toInt();

    if (index > -1 && index < courieres.size()) {
       courieres.erase(courieres.begin() + index);
       UpdateTable();
    }
    else {
        QMessageBox::critical(nullptr, "Неверные данные", "Неверные данные");
    }
}

void MainWindow::UpdateCourierTable()
{
    courier_table->setRowCount(0);
    for(int i = 0; i < courieres.size(); ++i) {
        courier_table->insertRow(courier_table->rowCount());
        courier_table->setItem(i, 0, new QTableWidgetItem(QString::number(courieres[i].getnumber())));
        courier_table->setItem(i, 1, new QTableWidgetItem(courieres[i].getfio()));
        courier_table->setItem(i, 2, new QTableWidgetItem(courieres[i].getbegin_time().toString("hh:mm:ss")));
        courier_table->setItem(i, 3, new QTableWidgetItem(courieres[i].getend_time().toString("hh:mm:ss")));
        courier_table->setItem(i, 4, new QTableWidgetItem(QString::number(courieres[i].getmin_mass())));
    }
}

void MainWindow::UpdateZakazTable()
{
    zakaz_table->setRowCount(0);
    for(int i = 0; i < zakazes.size(); ++i) {
        zakaz_table->insertRow(zakaz_table->rowCount());
        zakaz_table->setItem(i, 0, new QTableWidgetItem(QString::number(zakazes[i].getnumber())));
        zakaz_table->setItem(i, 1, new QTableWidgetItem(zakazes[i].getadress()));
        zakaz_table->setItem(i, 2, new QTableWidgetItem(zakazes[i].getdata().toString("dd.MM.yyyy")));
        zakaz_table->setItem(i, 3, new QTableWidgetItem(zakazes[i].gettime().toString("hh:mm:ss")));
        zakaz_table->setItem(i, 4, new QTableWidgetItem(QString::number(zakazes[i].getmassa())));
    }
}

void MainWindow::UpdateBadZakazTable()
{
    bad_zakaz_table->setRowCount(0);
    for(int i = 0; i < bad_zakazes.size(); ++i) {
        bad_zakaz_table->insertRow(bad_zakaz_table->rowCount());
        bad_zakaz_table->setItem(i, 0, new QTableWidgetItem(QString::number(bad_zakazes[i].getnumber())));
        bad_zakaz_table->setItem(i, 1, new QTableWidgetItem(bad_zakazes[i].getadress()));
        bad_zakaz_table->setItem(i, 2, new QTableWidgetItem(bad_zakazes[i].getdata().toString("dd.MM.yyyy")));
        bad_zakaz_table->setItem(i, 3, new QTableWidgetItem(bad_zakazes[i].gettime().toString("hh:mm:ss")));
        bad_zakaz_table->setItem(i, 4, new QTableWidgetItem(QString::number(bad_zakazes[i].getmassa())));
    }
}

void MainWindow::UpdateTable()
{
    if(opened_zakaz_file_string != "" && opened_courier_file_string != "") {
        bad_zakazes.clear();

        UpdateCourierTable();
        UpdateZakazTable();

        for(int i = 0; i < zakazes.size(); ++i) {
            bool courierIsFind = false;
            for(int j = 0; j < courieres.size(); ++j) {
                if (courieres[j].getbegin_time() < zakazes[i].gettime() && courieres[j].getend_time() > zakazes[i].gettime() && zakazes[i].getmassa() <= courieres[j].getmin_mass()) {
                    zakaz_table->setItem(i, 5, new QTableWidgetItem(courieres[j].getfio()));
                    courierIsFind = true;
                }
            }

            if (courierIsFind == false) {
                zakaz_table->setItem(i, 5, new QTableWidgetItem("nobody"));
                bad_zakazes.push_back(zakazes[i]);
            }
        }

        UpdateBadZakazTable();

        UpdateZakazFile();
        UpdateCourierFile();
    }
}

void MainWindow::UpdateZakazFile()
{
    QFile file(opened_zakaz_file_string);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        for (int i = 0; i < zakazes.size(); i++) {
            stream << QString::number(zakazes[i].getnumber())
                   << "\n"
                   << zakazes[i].getadress()
                   << "\n"
                   << zakazes[i].getdata().toString("dd.MM.yyyy")
                   << "\n"
                   << zakazes[i].gettime().toString("hh:mm:ss")
                   << "\n"
                   << QString::number(zakazes[i].getmassa())
                   << "\n";
        }
        file.close();
    }
}

void MainWindow::UpdateCourierFile()
{
    QFile file(opened_courier_file_string);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        for (int i = 0; i < courieres.size(); i++) {
            stream << QString::number(courieres[i].getnumber())
                   << "\n"
                   << courieres[i].getfio()
                   << "\n"
                   << courieres[i].getbegin_time().toString("hh:mm:ss")
                   << "\n"
                   << courieres[i].getend_time().toString("hh:mm:ss")
                   << "\n"
                   << QString::number(courieres[i].getmin_mass())
                   << "\n";
        }
        file.close();
    }
}
