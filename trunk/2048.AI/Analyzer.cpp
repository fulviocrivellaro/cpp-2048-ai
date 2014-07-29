#include "stdafx.h"

#include "Analyzer.h"
#include "MilGrid.h"

namespace MilCore
{
	namespace AI
	{
		Analyzer::Analyzer(const MilGrid & milgrid)
			: mGrid(milgrid)
		{
		}

		bool Analyzer::isHighestInTheCorner() const
		{
			TILE highest = mGrid[0][0];
			for (tilePtr c = 0; c < SIZE; ++c)
			{
				for (tilePtr r = 0; r < SIZE; ++r)
				{
					if (mGrid[c][r] > highest)
					{
						return false;
					}
				}
			}
			return true;
		}

		bool Analyzer::isMainColumnOrdered() const
		{
			for (tilePtr c = 1; c < SIZE; ++c)
			{
				if (mGrid[c][0] > mGrid[c-1][0])
				{
					return false;
				}
			}
			return true;
		}

		bool Analyzer::isMainColumnHighest() const
		{
			int sums[SIZE];

			for (tilePtr r = 0; r < SIZE; ++r)
			{
				sums[r] = 0;
				for (tilePtr c = 0; c < SIZE; ++c)
				{
					sums[r] += mGrid[c][r];
				}
			}

			for (tilePtr c = 1; c < SIZE; ++c)
			{
				if (sums[c] > sums[0])
				{
					return false;
				}
			}

			return true;
		}

		bool Analyzer::forcedToUnwantedMove() const
		{
			if (mGrid.canMove(Direction::Left)) return false;
			if (mGrid.canMove(Direction::Up)) return false;
			return true;
		}

		unsigned int Analyzer::countOrderedRows() const
		{
			int result = 0;
			for (tilePtr c=0; c<SIZE; ++c)
			{
				unsigned int ordered = 1;
				for (tilePtr r = 1; r < SIZE; ++r)
				{
					if (mGrid[c][r] > mGrid[c][r-1])
					{
						ordered = 0;
						break;
					}
				}
				result += ordered;
			}
			return result;
		}

		unsigned int Analyzer::availableMoves() const
		{
			int result = 0;
			for (unsigned int i=0; i<4; ++i)
			{
				if (mGrid.canMove((Direction)i))
				{
					++result;
				}
			}
			return result;
		}

		unsigned int Analyzer::countEmptyTiles() const
		{
			unsigned int count = 0;
			for (tilePtr c=0; c<SIZE; ++c)
			{
				for (tilePtr r = 0; r<SIZE; ++r)
				{
					if (mGrid[c][r] == 0)
					{
						++count;
					}
				}
			}
			return count;
		}
	}
}
