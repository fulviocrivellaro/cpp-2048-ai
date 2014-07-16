#ifndef __I_WORST_CASE_MOVE_CHOOSER__
#define __I_WORST_CASE_MOVE_CHOOSER__

#include "INextMoveChooser.h"

namespace AiMath2048
{
	class IGridScoreCalculator;

	using namespace Core2048;

	class WorstCaseNextMoveChooser :
		public INextMoveChooser
	{
	public:
		WorstCaseNextMoveChooser(const IGridScoreCalculator* const scoreCalculator);
		virtual ~WorstCaseNextMoveChooser(void);
		virtual Direction getNextMove(const TILE grid[SIZE][SIZE]) const;
	private:
		const IGridScoreCalculator* mScoreCalculator;

		// mutable internal support variables (for pre-allocation)
		mutable TILE mNormalizedGrid[SIZE][SIZE];
		mutable TILE mSupportGrid[SIZE][SIZE];

		void copyGrid(const TILE sourceGrid[SIZE][SIZE], TILE destGrid[SIZE][SIZE]) const;
			
		AIScore getWorstScore(TILE grid[SIZE][SIZE]) const;
		inline void testScoreForDirection(const TILE grid[SIZE][SIZE], const Direction direction, AIScore* const bestResult, Direction* const bestDirection) const;
		inline AIScore testAnAddition(TILE grid[SIZE][SIZE], const tilePtr r, const tilePtr c, const TILE value) const;
	};
}

#endif