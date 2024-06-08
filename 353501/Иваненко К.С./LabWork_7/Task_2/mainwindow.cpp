#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tree.h"

MainWindow::MainWindow() : ui(new Ui::MainWindow), tree(new BinarySearchTree)
{
    ui->setupUi(this);
    ui->textEdit->setFont(QFont("Courier New", 10));

    for (int i = -2; i < 3; ++i)
    {   
        tree->insert(QString("auto - %0").arg(i), i);
    }

    ui->textEdit->setText(tree->drawTree());
    on_task_clicked();

    qDebug() << "Обход в порядке предшественника: ";
    qDebug() << tree->preOrderTraversal().toStdString();

    qDebug() << '\n';
}

void MainWindow::on_insert_clicked()
{
    tree->insert("inserted", ui->spinBox->value());
    ui->textEdit->setPlainText(tree->drawTree());
    on_task_clicked();
}

void MainWindow::on_find_clicked()
{
    ui->label_find->setText((tree->find(ui->findSpinBox->value())) ? "true" : "false");
}

void MainWindow::on_task_clicked()
{
    QVector<int> levels;
    QString result = "";
    int numLevels = tree->countLeavesAtEachLevel(levels);

    result += QString("Количество уровней в дереве: %0\n").arg(numLevels);
    result += QString("Количество листьев на каждом уровне:\n");
    for (int i = 0; i < levels.size(); ++i)
    {
        result += QString("Уровень %0: %1\n").arg(i).arg(levels[i]);
    }
    ui->taskEdit->setText(result);
}

void MainWindow::on_remove_clicked()
{
    int searchKey = ui->removeSpinBox->value();
    if (tree->find(searchKey))
    {
        qDebug() << "Узел с ключом " << searchKey << " найден." << std::endl;
    }
    else
    {
        qDebug() << "Узел с ключом " << searchKey << " не найден." << std::endl;
    }
    tree->remove(searchKey);
    ui->textEdit->setPlainText(tree->drawTree());
    on_task_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tree;
}
