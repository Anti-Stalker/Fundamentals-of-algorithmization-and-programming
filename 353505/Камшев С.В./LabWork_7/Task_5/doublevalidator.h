#ifndef DOUBLEVALIDATOR_H
#define DOUBLEVALIDATOR_H

#include <QValidator>

class doubleValidator: public QValidator
{
public:
    doubleValidator();
    QValidator::State validate(QString &input, int &pos) const override;

};

#endif // DOUBLEVALIDATOR_H
