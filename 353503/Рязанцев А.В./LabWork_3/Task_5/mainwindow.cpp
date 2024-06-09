#include "mainwindow.h"
#include "./ui_mainwindow.h"

const QString INSYMBOL = "| - ";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Func to choose folder
void MainWindow::setPath()
{
    QString Path = QFileDialog::getExistingDirectory(this, "Get Any File", QDir::homePath());

    Directory.setPath(Path);
}

//Function recursevely counts amount of files and folders
void MainWindow::FilesCounter(QString Path)
{
    QDir sub_dir(Path);

    //Setup filters for appropriete data
    sub_dir.setFilter(QDir::AllDirs | QDir::Files | QDir::NoDotAndDotDot);

    //Getting each substance in folder if another folder call this function
    for(const QFileInfo &info : sub_dir.entryInfoList()){
        for(size_t i = 0; i < depth; ++i){
            output += "  ";
        }
        if(info.isDir()){
            output += INSYMBOL + info.fileName() + "\n";

            //ui->textBrowser->setText(output);

            total_dirs++;
            depth++;

            FilesCounter(Path + '/' + info.fileName());

            depth--;
        }
        else{
            output += INSYMBOL + info.fileName() + "\n";

            total_files++;
        }
    }
}

void MainWindow::on_openButton_clicked()
{

    //Refresh to 0
    total_dirs = 0;
    total_files = 0;

    //get folder to count from
    setPath();    
    output = Directory.dirName() + "\n";
    FilesCounter(Directory.path());

    //converting ints to string for convinience
    QString files_str, folders_str;
    files_str.setNum(total_files);
    folders_str.setNum(total_dirs);

    //dispalaing result in menu
    ui->textBrowser->setText(output);

    ui->lineEdit->setText(files_str);
    ui->lineEdit_2->setText(folders_str);
}

