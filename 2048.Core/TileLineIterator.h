#pragma once

#include "ConstTileLineIterator.h"

namespace MilCore
{
	class TileLineIterator : public ConstTileLineIterator
	{
	public:
		TileLineIterator(MilGrid* const grid, const tilePtr lineIndex, const Direction direction);
		~TileLineIterator(void) {}

		// differently from const version, it works on a non-const MilGrid
		TILE& operator[] (tilePtr index);

	private:
		// hold on the model
		MilGrid& mGrid;
	};
}