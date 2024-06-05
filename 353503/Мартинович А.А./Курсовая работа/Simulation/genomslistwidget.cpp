#include "genomslistwidget.h"

void GenomsListWidget::setGenoms(const QVector<QVector<int>> &genoms)
{
    saved_genoms = genoms;
    for (int i = 0; i < Settings::MIN_POPULATIONS_SIZE; i++) {
        QString gen = "";
        for (auto g: saved_genoms[i]) {
            gen += QString::number(g) + " ";
        }
        item(i)->setText(gen);
    }
}

void GenomsListWidget::clearList()
{
    saved_genoms.clear();
    clear();
    for (int i = 0; i < Settings::MIN_POPULATIONS_SIZE; ++i) {
        QListWidgetItem *listItem = new QListWidgetItem();
        addItem(listItem);
    }
}

GenomsListWidget::GenomsListWidget(QObject *parent)
{
    for (int i = 0; i < Settings::MIN_POPULATIONS_SIZE; ++i) {
        QListWidgetItem *listItem = new QListWidgetItem();
        addItem(listItem);
    }
}
