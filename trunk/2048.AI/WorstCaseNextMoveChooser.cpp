#include "stdafx.h"
#include "WorstCaseNextMoveChooser.h"
#include "IGridScoreCalculator.h"
#include "AiMath.h"

using namespace Core2048;
using namespace AiMath2048::Query;

WorstCaseNextMoveChooser::WorstCaseNextMoveChooser(const IGridScoreCalculator* const scoreCalculator)
{
	mScoreCalculator = scoreCalculator;
}

WorstCaseNextMoveChooser::~WorstCaseNextMoveChooser(void)
{
}

Core2048::Direction WorstCaseNextMoveChooser::getNextMove(const TILE grid[SIZE][SIZE]) const
{
	Direction bestDirection;
	AIScore bestResult = 0.0f;

	copyGrid(grid, mNormalizedGrid);
	NormalizeInfo restoreInfo = normalize(mNormalizedGrid);

	testScoreForDirection(mNormalizedGrid, Up, &bestResult, &bestDirection);
	testScoreForDirection(mNormalizedGrid, Right, &bestResult, &bestDirection);
	testScoreForDirection(mNormalizedGrid, Left, &bestResult, &bestDirection);
	testScoreForDirection(mNormalizedGrid, Down, &bestResult, &bestDirection);

	unsigned int ref = (unsigned int)bestDirection;
	ref += restoreInfo.highestAngle;
	ref = ref % 4;

	bestDirection = (Direction)(((int)bestDirection + (int)(restoreInfo.highestAngle)) % 4);

	// need to decode result
	if (restoreInfo.transposed)
	{
		switch (bestDirection)
		{
		case Up:
			bestDirection = Left;
			break;
		case Right:
			bestDirection = Down;
			break;
		case Down:
			bestDirection = Right;
			break;
		case Left:
		default:
			bestDirection = Up;
			break;
		}
	}

	return bestDirection;
}

inline void WorstCaseNextMoveChooser::testScoreForDirection(TILE grid[SIZE][SIZE], const Direction direction, AIScore* const bestResult, Direction* const bestDirection) const
{
	if (!CanMove(grid, direction)) return;

	// store original variable to local grid
	copyGrid(grid, mSupportGrid);
	// try up
	Move(grid, direction);

	AIScore currentScore = getWorstScore(mNormalizedGrid);
	if (currentScore > *bestResult)
	{
		*bestDirection = direction;
		*bestResult = currentScore;
	}
}

AIScore WorstCaseNextMoveChooser::getWorstScore(const TILE grid[SIZE][SIZE]) const
{
	AIScore worstScore = 1e36f;
	
	for (tilePtr r = 0; r < SIZE; ++r)
	{
		for (tilePtr c = 0; c < SIZE; ++c)
		{
			if (grid[c][r] == 0)
			{
				// this can be modified
				copyGrid(grid, mSupportGrid);

				// test 2
				AIScore currentScore = testAnAddition(mSupportGrid, r, c, 1);
				if (currentScore < worstScore)
				{
					worstScore = currentScore;
				}

				// test 4
				currentScore = testAnAddition(mSupportGrid, r, c, 1);
				if (currentScore < worstScore)
				{
					worstScore = currentScore;
				}
			}
		}
	}

	return worstScore;
}

inline AIScore WorstCaseNextMoveChooser::testAnAddition(TILE grid[SIZE][SIZE], const tilePtr r, const tilePtr c, const TILE value) const
{
	TILE orig = grid[c][r];
	grid[c][r] = value;
	AIScore currentScore = mScoreCalculator->getScore(grid);
	grid[c][r] = orig;
	return currentScore;
}

void WorstCaseNextMoveChooser::copyGrid(const TILE sourceGrid[SIZE][SIZE], TILE destGrid[SIZE][SIZE]) const
{
	for (tilePtr r = 0; r < SIZE; ++r)
	{
		for (tilePtr c = 0; c < SIZE; ++c)
		{
			destGrid[r][c] = sourceGrid[r][c];
		}
	}
}