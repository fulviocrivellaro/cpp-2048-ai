#include "stdafx.h"
#include "CSMilGrid.h"

namespace MilCore
{
	CSMilGrid::CSMilGrid(void)
		: mGrid(new MilGrid())
	{
	}

	CSMilGrid::~CSMilGrid(void)
	{
		delete(mGrid);
	}

	void CSMilGrid::Reset()
	{
		mGrid->resetGrid();
	}

	bool CSMilGrid::CanMove(const CppDirection direction)
	{
		return mGrid->canMove((Direction)direction);
	}
	
	bool CSMilGrid::IsStalled()
	{
		return mGrid->isStalled();
	}
	
	unsigned int CSMilGrid::Move(const CppDirection direction)
	{
		return mGrid->move((Direction)direction);
	}
	
	void CSMilGrid::AddRandomTile()
	{
		mGrid->addRandomTile();
	}

	TILE CSMilGrid::GetValue(const tilePtr col, const tilePtr row)
	{
		return (*mGrid)[col][row];
	}
}