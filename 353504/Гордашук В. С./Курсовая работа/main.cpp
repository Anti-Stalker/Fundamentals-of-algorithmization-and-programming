#include "widget.h"
#include "startmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StartMenu st;
    Widget w;
    st.show();
    QObject::connect(&st, &StartMenu::start, &w, &Widget::start);
    return a.exec();
}
