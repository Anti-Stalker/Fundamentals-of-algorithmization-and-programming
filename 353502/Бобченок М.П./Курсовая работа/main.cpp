#include <QApplication>
#include <QPushButton>
#include "userInterface/main_window.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto *mainWindow = new main_window();
    mainWindow->setWindowTitle("fullBread");
    mainWindow->show();
    return QApplication::exec();
}
