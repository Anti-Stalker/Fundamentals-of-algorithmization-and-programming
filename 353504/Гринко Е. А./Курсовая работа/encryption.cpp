#include "encryption.h"

QString Encryption::caesarEncrypt(const QString& plaintext, int shift) {
    QString result;
    for (QChar ch : plaintext) {
        if (ch.isLetter()) {
            QChar base = ch.isLower() ? 'a' : 'A';
            int offset = (ch.toLatin1() - base.toLatin1() + shift) % 26;
            result.append(QChar(base.toLatin1() + offset));
        } else {
            result.append(ch);
        }
    }
    return result;
}

QString Encryption::caesarDecrypt(const QString& ciphertext, int shift) {
    return caesarEncrypt(ciphertext, -shift);
}

QString Encryption::vigenereEncrypt(const QString& plaintext, const QString& key) {
    QString result;
    int keyLength = key.length();
    int j = 0;
    for (QChar ch : plaintext) {
        if (ch.isLetter()) {
            QChar base = ch.isLower() ? 'a' : 'A';
            int offset = (ch.toLatin1() - base.toLatin1() + key[j].toLatin1() - 'a') % 26;
            result.append(QChar(base.toLatin1() + offset));
            j = (j + 1) % keyLength;
        } else {
            result.append(ch);
        }
    }
    return result;
}

QString Encryption::vigenereDecrypt(const QString& ciphertext, const QString& key) {
    QString result;
    int keyLength = key.length();
    int j = 0;
    for (QChar ch : ciphertext) {
        if (ch.isLetter()) {
            QChar base = ch.isLower() ? 'a' : 'A';
            int offset = (ch.toLatin1() - base.toLatin1() - (key[j].toLatin1() - 'a') + 26) % 26;
            result.append(QChar(base.toLatin1() + offset));
            j = (j + 1) % keyLength;
        } else {
            result.append(ch);
        }
    }
    return result;
}
