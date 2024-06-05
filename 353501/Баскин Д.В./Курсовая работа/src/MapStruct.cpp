#include "MapStruct.h"

FMapStruct::FMapStruct()
{
	for (int i = 0; i < 10; ++i)
	{
		act.Add(FFloorStruct());
	}

	act[9].nodes.Empty();
	act[9].nodes.Add(FNodeStruct());
}