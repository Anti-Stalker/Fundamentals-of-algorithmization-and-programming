#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QSpinBox>
#include <QLineEdit>
#include <QRadioButton>
#include <QPushButton>
#include <QByteArray>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <openssl/rc4.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void encrypt();
    void decrypt();

private:
    Ui::MainWindow *ui;
    RSA* generateRSAKeyPair();
    QByteArray rsaEncrypt(const QByteArray &data, RSA *publicKey);
    QByteArray rsaDecrypt(const QByteArray &data, RSA *privateKey);
    QByteArray generateAESKey();
    QByteArray aesEncrypt(const QByteArray &data, const QByteArray &key);
    QByteArray aesDecrypt(const QByteArray &data, const QByteArray &key);
    QByteArray rc4Encrypt(const QByteArray &data, const QByteArray &key);
    QByteArray rc4Decrypt(const QByteArray &data, const QByteArray &key);
    QString caesarEncrypt(const QString &text, int shift);
    QString caesarDecrypt(const QString &text, int shift);
    QString vigenereEncrypt(const QString &text, const QString &key);
    QString vigenereDecrypt(const QString &text, const QString &key);

    RSA *rsaKeyPair;
    QByteArray aesKey;
    QByteArray rc4Key;
};
#endif // MAINWINDOW_H
