#include "stdafx.h"
#include "WorstCaseNextMoveChooser.h"
#include "IGridScoreCalculator.h"
#include "AiMath.h"

namespace MilCore
{
	namespace AI
	{

		WorstCaseNextMoveChooser::WorstCaseNextMoveChooser(const IGridScoreCalculator* const scoreCalculator)
		{
			mScoreCalculator = scoreCalculator;
		}

		WorstCaseNextMoveChooser::~WorstCaseNextMoveChooser(void)
		{
		}

		Direction WorstCaseNextMoveChooser::getNextMove(const MilGrid& grid) const
		{
			Direction bestDirection;
			AIScore bestResult = MIN_SCORE;

			auto normalizedGrid(grid);
			NormalizeInfo restoreInfo = normalize(normalizedGrid);

			testScoreForDirection(normalizedGrid, Up, &bestResult, &bestDirection);
			testScoreForDirection(normalizedGrid, Right, &bestResult, &bestDirection);
			testScoreForDirection(normalizedGrid, Left, &bestResult, &bestDirection);
			testScoreForDirection(normalizedGrid, Down, &bestResult, &bestDirection);

			auto res = denormalizeDirection(bestDirection, restoreInfo);
			return res;
		}

		inline void WorstCaseNextMoveChooser::testScoreForDirection(const MilGrid& grid, const Direction direction, AIScore* const bestResult, Direction* const bestDirection) const
		{
			if (!grid.canMove(direction)) return;

			// store original variable to local grid
			auto supportGrid(grid);
			copyGrid(grid, supportGrid);
			// try up
			supportGrid.move(direction);

			AIScore currentScore = getWorstScore(supportGrid);
			if (currentScore > *bestResult)
			{
				*bestDirection = direction;
				*bestResult = currentScore;
			}
		}

		AIScore WorstCaseNextMoveChooser::getWorstScore(MilGrid& grid) const
		{
			AIScore worstScore = MAX_SCORE;
	
			for (tilePtr r = 0; r < SIZE; ++r)
			{
				for (tilePtr c = 0; c < SIZE; ++c)
				{
					if (grid[c][r] == 0)
					{
						// this can be modified
						//copyGrid(grid, mSupportGrid);

						// test 2
						AIScore currentScore = testAnAddition(grid, r, c, 1);
						if (currentScore < worstScore)
						{
							worstScore = currentScore;
						}

						// test 4
						currentScore = testAnAddition(grid, r, c, 2);
						if (currentScore < worstScore)
						{
							worstScore = currentScore;
						}
					}
				}
			}

			return worstScore;
		}

		inline AIScore WorstCaseNextMoveChooser::testAnAddition(MilGrid& grid, const tilePtr r, const tilePtr c, const TILE value) const
		{
			TILE orig = grid[c][r];
			grid[c][r] = value;
			AIScore currentScore = mScoreCalculator->getScore(grid);
			grid[c][r] = orig;
			return currentScore;
		}

		void WorstCaseNextMoveChooser::copyGrid(const MilGrid& sourceGrid, MilGrid& destGrid) const
		{
			for (tilePtr r = 0; r < SIZE; ++r)
			{
				for (tilePtr c = 0; c < SIZE; ++c)
				{
					destGrid[r][c] = sourceGrid[r][c];
				}
			}
		}
	}
}
