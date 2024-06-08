#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <QString>

class Encryption {
public:
    QString caesarEncrypt(const QString& plaintext, int shift);
    QString caesarDecrypt(const QString& ciphertext, int shift);
    QString vigenereEncrypt(const QString& plaintext, const QString& key);
    QString vigenereDecrypt(const QString& ciphertext, const QString& key);
};

#endif // ENCRYPTION_H
