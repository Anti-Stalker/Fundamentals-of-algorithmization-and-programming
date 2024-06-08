#include "doublevalidator.h"

doubleValidator::doubleValidator() {}

QValidator::State doubleValidator::validate(QString &input, int &pos) const
{
    if (input.isEmpty()) return QValidator::Acceptable;
    bool a;
    input.toDouble(&a);
    if (a == true) return QValidator::Acceptable;
    else return QValidator::Invalid;
}
