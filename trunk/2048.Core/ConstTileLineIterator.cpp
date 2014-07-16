#include "MilGrid.h"
#include "ConstTileLineIterator.h"

namespace MilCore
{
	ConstTileLineIterator::ConstTileLineIterator(const MilGrid* const grid, const tilePtr lineIndex, const Direction direction)
		: mConstGrid(*grid)
	{
		init(lineIndex, direction);
	}

	void ConstTileLineIterator::init(const tilePtr lineIndex, const Direction direction)
	{
		switch (direction)
		{
		case Left:
			for (tilePtr i=0; i<SIZE; ++i)
			{
				m1stIdx[i] = lineIndex;
				m2ndIdx[i] = SIZE-i-1;
			}
			break;
		case Right:
			for (tilePtr i=0; i<SIZE; ++i)
			{
				m1stIdx[i] = lineIndex;
				m2ndIdx[i] = i;
			}
			break;
		case Up:
			for (tilePtr i=0; i<SIZE; ++i)
			{
				m1stIdx[i] = SIZE-i-1;
				m2ndIdx[i] = lineIndex;
			}
			break;
		case Down:
			for (tilePtr i=0; i<SIZE; ++i)
			{
				m1stIdx[i] = i;
				m2ndIdx[i] = lineIndex;
			}
			break;
		}
	}

	const TILE& ConstTileLineIterator::operator[] (tilePtr index) const
	{
		return mConstGrid[m1stIdx[index]][m2ndIdx[index]];
	}
}