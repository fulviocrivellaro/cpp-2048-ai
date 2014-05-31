#include "stdafx.h"
#include "ProductGridScoreCalculator.h"

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
	AIScore result = HIGHEST_SCORE;

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

	return result
		  * mSetup.availableMoves * availableMoves(grid)
		  * mSetup.countEmptyTiles * countEmptyTiles(grid)
		  * mSetup.countOrderedRows * countOrderedRows(grid)
		  * mSetup.forcedToUnwantedMove * forcedToUnwantedMove(grid);
		  
}