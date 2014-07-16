#pragma once

#include "MilCore.h"

namespace MilCore
{
	class MilGrid;

	class ConstTileLineIterator
	{
	public:
		ConstTileLineIterator(const MilGrid* const grid, const tilePtr lineIndex, const Direction direction);
		virtual ~ConstTileLineIterator(void) {}

		const TILE& operator[] (tilePtr index) const;
	
	private:
		// initializes indices
		void init(const tilePtr lineIndex, const Direction direction);

		// hold on the model
		const MilGrid& mConstGrid;

	protected:
		// pre-computed indeces
		tilePtr m1stIdx[SIZE];
		tilePtr m2ndIdx[SIZE];
	};
}