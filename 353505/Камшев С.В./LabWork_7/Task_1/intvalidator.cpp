#include "intvalidator.h"

IntValidator::IntValidator() {}

QValidator::State IntValidator::validate(QString &input, int &pos) const
{
    if (input.isEmpty()) return QValidator::Acceptable;
    bool a;
    input.toInt(&a);
    if (a == true) return QValidator::Acceptable;
    else return QValidator::Invalid;
}
