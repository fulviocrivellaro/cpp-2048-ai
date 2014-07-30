#pragma once

#include "INextMoveChooser.h"
#include "MilGrid.h"

namespace MilCore
{
	namespace AI
	{
		class IGridScoreCalculator;

		class WorstCaseNextMoveChooser :
			public INextMoveChooser
		{
		public:
			WorstCaseNextMoveChooser(const IGridScoreCalculator* const scoreCalculator);
			virtual ~WorstCaseNextMoveChooser(void);
			virtual Direction getNextMove(const MilGrid& grid) const;
		private:
			const IGridScoreCalculator* mScoreCalculator;

			// mutable internal support variables (for pre-allocation)
			mutable MilGrid mNormalizedGrid;
			mutable MilGrid mSupportGrid;

			void copyGrid(const MilGrid& sourceGrid, MilGrid& destGrid) const;
			
			AIScore getWorstScore(MilGrid& grid) const;
			inline void testScoreForDirection(const MilGrid& grid, const Direction direction, AIScore* const bestResult, Direction* const bestDirection) const;
			inline AIScore testAnAddition(MilGrid& grid, const tilePtr r, const tilePtr c, const TILE value) const;
		};
	}
}