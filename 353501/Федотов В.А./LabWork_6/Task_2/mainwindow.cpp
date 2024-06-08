#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qcombobox.h>
#include <qcoreapplication.h>
#include <qpushbutton.h>

#include "Subtask1/Subtask1.h"
#include "Subtask2/Subtask2.h"
#include "Subtask3/Subtask3.h"
#include "Subtask4/Subtask4.h"

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->exitButton, &QPushButton::pressed, &QCoreApplication::quit);
    connect(ui->menuBox, &QComboBox::activated, this, &MainWindow::subtaskChanged);
}

void MainWindow::subtaskChanged(int index) {
    if (currentSubtask != ui->subtaskLabel) {
        currentSubtask->deleteLater();
    }

    switch (index) {
        case 0:
            currentSubtask = new Subtask1(ui->subtaskWidget);
            ui->subtaskLabel->setText("Subtask 1");
            break;
        case 1:
            currentSubtask = new Subtask2(ui->subtaskWidget);
            ui->subtaskLabel->setText("Subtask 2");
            break;
        case 2:
            currentSubtask = new Subtask3(ui->subtaskWidget);
            ui->subtaskLabel->setText("Subtask 3");
            break;
        case 3:
            currentSubtask = new Subtask4(ui->subtaskWidget);
            ui->subtaskLabel->setText("Subtask 4");
            break;
        default:
            ui->subtaskLabel->setText("Subtask");
            currentSubtask = ui->subtaskLabel;
            return;
    }

    ui->subtaskWidget->layout()->addWidget(currentSubtask);
    currentSubtask->show();
}