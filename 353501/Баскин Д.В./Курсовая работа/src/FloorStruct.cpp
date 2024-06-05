#include "FloorStruct.h"

FFloorStruct::FFloorStruct()
{
	for (size_t i = 0; i < 9; ++i)
	{
		nodes.Add(FNodeStruct());
	}
}