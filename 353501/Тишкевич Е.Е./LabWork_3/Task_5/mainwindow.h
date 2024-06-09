
#include <QMainWindow>
#include <QtWidgets>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();
    QPair<long, long> updTree(const QString&, QTreeWidgetItem *);
    void openFolder();

protected:
    Ui::MainWindow *ui;
};
