#ifndef DATABASESHORTCUTSSELECTER_H
#define DATABASESHORTCUTSSELECTER_H

#include <QClipboard>
#include <QApplication>

#include "databasecontroller.h"

class DatabaseShortcutsSelecter : public DatabaseController
{
public:
    explicit DatabaseShortcutsSelecter(QObject *parent = nullptr);
    void copyPasswordToClipboard(int noteId);
    void copyUsernameToClipboard(int noteId);

private:
    QClipboard *clipboard = QApplication::clipboard();
};

#endif // DATABASESHORTCUTSSELECTER_H
