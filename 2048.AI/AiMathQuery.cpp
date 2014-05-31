#include "stdafx.h"

#include "AiMathQuery.h"

using namespace Core2048;

bool AiMath2048::Query::isHighestInTheCorner(const TILE grid[][SIZE])
{
	TILE highest = grid[0][0];
	for (tilePtr c = 0; c < SIZE; ++c)
	{
		for (tilePtr r = 0; r < SIZE; ++r)
		{
			if (grid[c][r] > highest)
			{
				return false;
			}
		}
	}

	return true;
}

bool AiMath2048::Query::isMainColumnOrdered(const TILE grid[][SIZE])
{
	for (tilePtr c = 1; c < SIZE; ++c)
	{
		if (grid[c][0] > grid[c-1][0])
		{
			return false;
		}
	}

	return true;
}

bool AiMath2048::Query::isMainColumnHighest(const TILE grid[][SIZE])
{
	int sums[SIZE];

	for (tilePtr r = 0; r < SIZE; ++r)
	{
		sums[r] = 0;
		for (tilePtr c = 0; c < SIZE; ++c)
		{
			sums[r] += grid[c][r];
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

bool AiMath2048::Query::mustMoveDown(const TILE grid[][SIZE])
{
	if (CanMove(grid, Direction::Left)) return false;
	if (CanMove(grid, Direction::Right)) return false;
	if (CanMove(grid, Direction::Up)) return false;
	return true;
}

unsigned int AiMath2048::Query::countOrderedRows(const TILE grid[][SIZE])
{
	int result = 0;
	for (tilePtr c=0; c<SIZE; ++c)
	{
		unsigned int ordered = 1;
		for (tilePtr r = 1; r < SIZE; ++r)
		{
			if (grid[c][r] > grid[c][r-1])
			{
				ordered = 0;
				break;
			}
		}
		result += ordered;
	}
	return result;
}

unsigned int AiMath2048::Query::availableMoves(const TILE grid[][SIZE])
{
	int result = 0;
	for (unsigned int i=0; i<4; ++i)
	{
		if (CanMove(grid, (Direction)i))
		{
			++result;
		}
	}
	return result;
}

unsigned int AiMath2048::Query::countEmptyTiles(const TILE grid[][SIZE])
{
	unsigned int count = 0;
	for (tilePtr c=0; c<SIZE; ++c)
	{
		for (tilePtr r = 0; r<SIZE; ++r)
		{
			if (grid[c][r] == 0)
			{
				++count;
			}
		}
	}
	return count;
}