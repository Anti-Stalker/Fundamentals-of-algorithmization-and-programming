#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QStringList>
#include <QFileInfo>
#include <QFile>
#include <QSettings>
#include <QCryptographicHash>
#include <QRandomGenerator>

class SettingsManager
{

protected:
    static QSettings settings;

};

#endif // SETTINGSMANAGER_H
