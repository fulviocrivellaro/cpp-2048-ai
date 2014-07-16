#include "stdafx.h"
#include "Cpp2048Native.h"

#include "2048Core.h"

Cpp2048Native::Cpp2048Native(void)
{
	Randomize();

	// prepare the grid
	ResetGrid(mGrid);
}

bool Cpp2048Native::CanMove(const CppDirection direction) const
{
	return Core2048::CanMove(mGrid, (Direction)direction);
}
	
bool Cpp2048Native::Stalled() const
{
	return Core2048::Stalled(mGrid);
}
	
unsigned int Cpp2048Native::Move(const CppDirection direction)
{
	return Core2048::Move(mGrid, (Direction)direction);
}
	
void Cpp2048Native::AddNewTile()
{
	Core2048::AddNewTile(mGrid);
}

TILE Cpp2048Native::GetValueForPosition(const int col, const int row) const
{
	return mGrid[col][row];
}