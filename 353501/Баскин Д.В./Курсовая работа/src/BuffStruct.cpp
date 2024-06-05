#include "BuffStruct.h"
#include "Buff.h"
#include "BuffWidget.h"

FBuffStruct::FBuffStruct(UBuff* buff)
{
	name = buff->name;
	applyToSelf = buff->applyToSelf;
	amount = buff->amount;
	icon = buff->icon;
	widget = nullptr;
}

bool FBuffStruct::operator==(const FBuffStruct& other) const
{
	if (!(name == other.name && applyToSelf == other.applyToSelf && icon == other.icon))
	{
		return false;
	}

	return true;
}