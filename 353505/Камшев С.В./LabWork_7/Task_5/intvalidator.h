#ifndef INTVALIDATOR_H
#define INTVALIDATOR_H

#include <QValidator>

class IntValidator: public QValidator
{
public:
    IntValidator();
    QValidator::State validate(QString &input, int &pos) const override;
};

#endif // INTVALIDATOR_H
