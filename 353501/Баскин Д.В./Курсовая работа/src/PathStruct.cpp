#include "PathStruct.h"

FPathStruct::FPathStruct()
{
	From = -1;
	To = -1;
}

FPathStruct::FPathStruct(int From, int To)
{
	this->From = From;
	this->To = To;
}

bool FPathStruct::operator==(const FPathStruct& other) const
{
	if (this->From == other.From && this->To == other.To)
	{
		return true;
	}

	return false;
}