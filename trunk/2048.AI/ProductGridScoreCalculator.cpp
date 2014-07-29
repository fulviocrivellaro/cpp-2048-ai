#include "stdafx.h"
#include "ProductGridScoreCalculator.h"
#include "MilGrid.h"

namespace MilCore
{
	namespace AI
	{
		ProductGridScoreCalculator::ProductGridScoreCalculator(const MilGrid& grid, const AISetup setup)
			: mAnalyzer(grid), mSetup(setup)
		{
		}

		ProductGridScoreCalculator::~ProductGridScoreCalculator(void)
		{
		}

		AISetup ProductGridScoreCalculator::getSetup() const
		{
			return mSetup;
		}

		AIScore ProductGridScoreCalculator::getScore() const
		{
			AIScore result = BASE_SCORE;

			if (mAnalyzer.isHighestInTheCorner())
			{
				result *= mSetup.isHighestInTheCorner;
			}
			if (mAnalyzer.isMainColumnHighest())
			{
				result *= mSetup.isMainColumnHighest;
			}
			if (mAnalyzer.isHighestInTheCorner())
			{
				result *= mSetup.isMainColumnOrdered;
			}
			if (!mAnalyzer.forcedToUnwantedMove())
			{
				result *= mSetup.forcedToUnwantedMove;
			}

			return result
				  * mSetup.availableMoves * mAnalyzer.availableMoves()
				  * mSetup.countEmptyTiles * (mAnalyzer.countEmptyTiles() + 1)
				  * mSetup.countOrderedRows * (mAnalyzer.countOrderedRows() + 1);
		}
	}
}