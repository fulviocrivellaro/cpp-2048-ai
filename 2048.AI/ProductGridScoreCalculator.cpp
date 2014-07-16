#include "stdafx.h"
#include "ProductGridScoreCalculator.h"

using namespace AiMath2048;

ProductGridScoreCalculator::ProductGridScoreCalculator(const AISetup setup)
{
	mSetup = setup;
}


ProductGridScoreCalculator::~ProductGridScoreCalculator(void)
{
}

AISetup ProductGridScoreCalculator::getSetup() const
{
	return mSetup;
}

AIScore ProductGridScoreCalculator::getScore(const Core2048::TILE grid[][SIZE]) const
{
	AIScore result = BASE_SCORE;

	if (isHighestInTheCorner(grid))
	{
		result *= mSetup.isHighestInTheCorner;
	}
	if (isMainColumnHighest(grid))
	{
		result *= mSetup.isMainColumnHighest;
	}
	if (isHighestInTheCorner(grid))
	{
		result *= mSetup.isMainColumnOrdered;
	}
	if (!forcedToUnwantedMove(grid))
	{
		result *= mSetup.forcedToUnwantedMove;
	}

	return result
		  * mSetup.availableMoves * availableMoves(grid)
		  * mSetup.countEmptyTiles * (countEmptyTiles(grid) + 1)
		  * mSetup.countOrderedRows * (countOrderedRows(grid) + 1);
}