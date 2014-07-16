#include "TileLineIterator.h"
#include "MilGrid.h"

namespace MilCore
{
	TileLineIterator::TileLineIterator(MilGrid* const grid, const tilePtr lineIndex, const Direction direction)
		: ConstTileLineIterator(grid, lineIndex, direction), mGrid(*grid)
	{
	}

	TILE& TileLineIterator::operator[] (tilePtr index)
	{
		return mGrid[m1stIdx[index]][m2ndIdx[index]];
	}
}