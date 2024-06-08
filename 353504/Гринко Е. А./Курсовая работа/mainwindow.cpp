#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rsaKeyPair = generateRSAKeyPair();
    aesKey = generateAESKey();
    rc4Key = generateAESKey();

    connect(ui->encryptButton, &QPushButton::clicked, this, &MainWindow::encrypt);
    connect(ui->decryptButton, &QPushButton::clicked, this, &MainWindow::decrypt);
}

MainWindow::~MainWindow()
{
    delete ui;
    RSA_free(rsaKeyPair);
}

void MainWindow::encrypt()
{
    QString plainText = ui->plainTextEdit->toPlainText();
    QByteArray encryptedData;

    if (ui->caesarRadioButton->isChecked()) {
        int shift = ui->shiftSpinBox->value();
        ui->cipherTextEdit->setPlainText(caesarEncrypt(plainText, shift));
    } else if (ui->vigenereRadioButton->isChecked()) {
        QString key = ui->keyLineEdit->text();
        ui->cipherTextEdit->setPlainText(vigenereEncrypt(plainText, key));
    } else if (ui->rsaRadioButton->isChecked()) {
        encryptedData = rsaEncrypt(plainText.toUtf8(), rsaKeyPair);
        ui->cipherTextEdit->setPlainText(encryptedData.toBase64());
    } else if (ui->aesRadioButton->isChecked()) {
        encryptedData = aesEncrypt(plainText.toUtf8(), aesKey);
        ui->cipherTextEdit->setPlainText(encryptedData.toBase64());
    } else if (ui->rc4RadioButton->isChecked()) {
        encryptedData = rc4Encrypt(plainText.toUtf8(), rc4Key);
        ui->cipherTextEdit->setPlainText(encryptedData.toBase64());
    }
}

void MainWindow::decrypt()
{
    QString cipherText = ui->cipherTextEdit->toPlainText();
    QByteArray decryptedData;

    if (ui->caesarRadioButton->isChecked()) {
        int shift = ui->shiftSpinBox->value();
        ui->plainTextEdit->setPlainText(caesarDecrypt(cipherText, shift));
    } else if (ui->vigenereRadioButton->isChecked()) {
        QString key = ui->keyLineEdit->text();
        ui->plainTextEdit->setPlainText(vigenereDecrypt(cipherText, key));
    } else if (ui->rsaRadioButton->isChecked()) {
        decryptedData = rsaDecrypt(QByteArray::fromBase64(cipherText.toUtf8()), rsaKeyPair);
        ui->plainTextEdit->setPlainText(QString::fromUtf8(decryptedData));
    } else if (ui->aesRadioButton->isChecked()) {
        decryptedData = aesDecrypt(QByteArray::fromBase64(cipherText.toUtf8()), aesKey);
        ui->plainTextEdit->setPlainText(QString::fromUtf8(decryptedData));
    } else if (ui->rc4RadioButton->isChecked()) {
        decryptedData = rc4Decrypt(QByteArray::fromBase64(cipherText.toUtf8()), rc4Key);
        ui->plainTextEdit->setPlainText(QString::fromUtf8(decryptedData));
    }
}

QString MainWindow::caesarEncrypt(const QString &text, int shift)
{
    QString result;
    for (const QChar &c : text) {
        if (c.isLetter()) {
            QChar base = c.isLower() ? 'a' : 'A';
            result.append(QChar((c.unicode() - base.unicode() + shift) % 26 + base.unicode()));
        } else {
            result.append(c);
        }
    }
    return result;
}

QString MainWindow::caesarDecrypt(const QString &text, int shift)
{
    return caesarEncrypt(text, 26 - shift);
}

QString MainWindow::vigenereEncrypt(const QString &text, const QString &key)
{
    QString result;
    int keyIndex = 0;
    for (const QChar &c : text) {
        if (c.isLetter()) {
            QChar base = c.isLower() ? 'a' : 'A';
            int shift = key.at(keyIndex).toLower().unicode() - 'a';
            result.append(QChar((c.unicode() - base.unicode() + shift) % 26 + base.unicode()));
            keyIndex = (keyIndex + 1) % key.length();
        } else {
            result.append(c);
        }
    }
    return result;
}

QString MainWindow::vigenereDecrypt(const QString &text, const QString &key)
{
    QString result;
    int keyIndex = 0;
    for (const QChar &c : text) {
        if (c.isLetter()) {
            QChar base = c.isLower() ? 'a' : 'A';
            int shift = key.at(keyIndex).toLower().unicode() - 'a';
            result.append(QChar((c.unicode() - base.unicode() - shift + 26) % 26 + base.unicode()));
            keyIndex = (keyIndex + 1) % key.length();
        } else {
            result.append(c);
        }
    }
    return result;
}

RSA* MainWindow::generateRSAKeyPair()
{
    RSA *rsa = RSA_new();
    BIGNUM *e = BN_new();
    BN_set_word(e, RSA_F4);
    RSA_generate_key_ex(rsa, 2048, e, NULL);
    BN_free(e);
    return rsa;
}

QByteArray MainWindow::rsaEncrypt(const QByteArray &data, RSA *publicKey)
{
    int rsaSize = RSA_size(publicKey);
    QByteArray encrypted(rsaSize, 0);
    int result = RSA_public_encrypt(data.size(), reinterpret_cast<const unsigned char*>(data.constData()),
                                    reinterpret_cast<unsigned char*>(encrypted.data()), publicKey, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {

        return QByteArray();
    }
    return encrypted.left(result);
}

QByteArray MainWindow::rsaDecrypt(const QByteArray &data, RSA *privateKey)
{
    int rsaSize = RSA_size(privateKey);
    QByteArray decrypted(rsaSize, 0);
    int result = RSA_private_decrypt(data.size(), reinterpret_cast<const unsigned char*>(data.constData()),
                                     reinterpret_cast<unsigned char*>(decrypted.data()), privateKey, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {
        // Handle decryption error
        return QByteArray();
    }
    return decrypted.left(result); // Use only the portion of the buffer that was actually written to
}

QByteArray MainWindow::generateAESKey()
{
    QByteArray key(AES_BLOCK_SIZE, 0);
    RAND_bytes(reinterpret_cast<unsigned char*>(key.data()), AES_BLOCK_SIZE);
    return key;
}

QByteArray addPadding(const QByteArray &data, int blockSize)
{
    int paddingSize = blockSize - (data.size() % blockSize);
    QByteArray paddedData = data;
    paddedData.append(paddingSize, paddingSize);
    return paddedData;
}

QByteArray removePadding(const QByteArray &data)
{
    if (data.isEmpty()) return data;
    int paddingSize = static_cast<int>(data.at(data.size() - 1));
    return data.left(data.size() - paddingSize);
}

QByteArray MainWindow::aesEncrypt(const QByteArray &data, const QByteArray &key)
{
    AES_KEY aesKey;
    AES_set_encrypt_key(reinterpret_cast<const unsigned char*>(key.data()), 128, &aesKey);
    QByteArray paddedData = addPadding(data, AES_BLOCK_SIZE);
    QByteArray encrypted((paddedData.size() / AES_BLOCK_SIZE) * AES_BLOCK_SIZE, 0);
    for (int i = 0; i < paddedData.size(); i += AES_BLOCK_SIZE) {
        AES_encrypt(reinterpret_cast<const unsigned char*>(paddedData.constData() + i),
                    reinterpret_cast<unsigned char*>(encrypted.data() + i), &aesKey);
    }
    return encrypted;
}

QByteArray MainWindow::aesDecrypt(const QByteArray &data, const QByteArray &key)
{
    AES_KEY aesKey;
    AES_set_decrypt_key(reinterpret_cast<const unsigned char*>(key.data()), 128, &aesKey);
    QByteArray decrypted(data.size(), 0);
    for (int i = 0; i < data.size(); i += AES_BLOCK_SIZE) {
        AES_decrypt(reinterpret_cast<const unsigned char*>(data.constData() + i),
                    reinterpret_cast<unsigned char*>(decrypted.data() + i), &aesKey);
    }
    return removePadding(decrypted);
}

QByteArray MainWindow::rc4Encrypt(const QByteArray &data, const QByteArray &key)
{
    RC4_KEY rc4Key;
    RC4_set_key(&rc4Key, key.size(), reinterpret_cast<const unsigned char*>(key.data()));
    QByteArray encrypted(data.size(), 0);
    RC4(&rc4Key, data.size(), reinterpret_cast<const unsigned char*>(data.constData()),
        reinterpret_cast<unsigned char*>(encrypted.data()));
    return encrypted;
}

QByteArray MainWindow::rc4Decrypt(const QByteArray &data, const QByteArray &key)
{
    return rc4Encrypt(data, key); // RC4 encryption is symmetric
}
