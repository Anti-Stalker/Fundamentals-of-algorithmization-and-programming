#include "NodeStruct.h"

FNodeStruct::FNodeStruct()
{
	type = (ENodeType) -1;
	seed = 0;
}

bool FNodeStruct::operator==(const FNodeStruct& other) const
{
	return type == other.type && seed.GetCurrentSeed() == other.seed.GetCurrentSeed();
}
