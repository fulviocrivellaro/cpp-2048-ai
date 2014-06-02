#include "stdafx.h"
#include "AiMath.h"

using namespace AiMath2048;

Angles AiMath2048::highestAngle(TILE grid[][SIZE])
{
	TILE maxs[4];
	unsigned int sums[4];
	for (unsigned char i=0; i<4; ++i)
	{
		maxs[i] = 0;
		sums[i] = 0;
	}

	// compute max values and sums
	for (unsigned char c=0; c<SIZE/2; ++c)
	{
		for (unsigned char r=0; r<SIZE/2; ++r)
		{
			maxs[Angles::TopLeft] = std::max(maxs[Angles::TopLeft], grid[c][r]);
			sums[Angles::TopLeft] += grid[c][r];
		}
	}
	for (unsigned char c=SIZE/2; c<SIZE; ++c)
	{
		for (unsigned char r=0; r<SIZE/2; ++r)
		{
			maxs[Angles::BottomLeft] = std::max(maxs[Angles::BottomLeft], grid[c][r]);
			sums[Angles::BottomLeft] += grid[c][r];
		}
	}
	for (unsigned char c=0; c<SIZE/2; ++c)
	{
		for (unsigned char r=SIZE/2; r<SIZE; ++r)
		{
			maxs[Angles::TopRight] = std::max(maxs[Angles::TopRight], grid[c][r]);
			sums[Angles::TopRight] += grid[c][r];
		}
	}
	for (unsigned char c=SIZE/2; c<SIZE; ++c)
	{
		for (unsigned char r=SIZE/2; r<SIZE; ++r)
		{
			maxs[Angles::BottomRight] = std::max(maxs[Angles::BottomRight], grid[c][r]);
			sums[Angles::BottomRight] += grid[c][r];
		}
	}

	Angles result = Angles::TopLeft;
	for (unsigned char i=1; i<4; ++i)
	{
		if (maxs[i] > maxs[result])
		{
			result = (Angles)i;
		}
		else if (maxs[i] == maxs[result])
		{
			if (sums[i] > sums[result])
			{
				result = (Angles)i;
			}
		}
	}
		
	return result;
}

bool AiMath2048::shouldTranspose(TILE grid[][SIZE])
{
	unsigned int sumCol = 0;
	unsigned int sumRow = 0;
	for (tilePtr i=0; i<SIZE; ++i)
	{
		sumCol += grid[i][0];
		sumRow += grid[0][i];
	}
	return sumRow > sumCol;
}

void AiMath2048::rotate90CW(TILE grid[][SIZE])
{
	for (tilePtr c=0; c<SIZE/2; ++c)
	{
		for (tilePtr r=c; r<SIZE-c-1; ++r)
		{
			tilePtr cc = SIZE - c - 1;
			tilePtr rr = SIZE - r - 1;

			TILE tmp = grid[c][r];
			grid[c][r] = grid[rr][c];
			grid[rr][c] = grid[cc][rr];
			grid[cc][rr] = grid[r][cc];
			grid[r][cc] = tmp;
		}
	}
}

void AiMath2048::rotate90CCW(TILE grid[][SIZE])
{
	for (tilePtr c=0; c<SIZE/2; ++c)
	{
		for (tilePtr r=c; r<SIZE-c-1; ++r)
		{
			tilePtr cc = SIZE - c - 1;
			tilePtr rr = SIZE - r - 1;

			TILE tmp = grid[c][r];
			grid[c][r] = grid[r][cc];
			grid[r][cc] = grid[cc][rr];
			grid[cc][rr] = grid[rr][c];
			grid[rr][c] = tmp;
		}
	}
}

void AiMath2048::rotate180(TILE grid[][SIZE])
{
#if SIZE % 2 != 0
	// odd size
	rotate90CW(grid);
	rotate90CW(grid);
#else
	// even size - optimized
	for (tilePtr c=0; c<SIZE; ++c)
	{
		for (tilePtr r=0; r<SIZE/2; ++r)
		{
			tilePtr cc = SIZE - c - 1;
			tilePtr rr = SIZE - r - 1;

			TILE tmp = grid[c][r];
			grid[c][r] = grid[cc][rr];
			grid[cc][rr] = tmp;
		}
	}
#endif
}

void AiMath2048::transpose(TILE grid[][SIZE])
{
	for (tilePtr c=1; c<SIZE; ++c)
	{
		for (tilePtr r=0; r<c; ++r)
		{
			TILE tmp = grid[c][r];
			grid[c][r] = grid[r][c];
			grid[r][c] = tmp;
		}
	}
}

NormalizeInfo AiMath2048::normalize(TILE grid[][SIZE])
{
	NormalizeInfo result;
	result.highestAngle = highestAngle(grid);

	switch (result.highestAngle)
	{
	case Angles::TopRight:
		rotate90CCW(grid);
		break;
	case Angles::BottomRight:
		rotate180(grid);
		break;
	case Angles::BottomLeft:
		rotate90CW(grid);
		break;
	}

	result.transposed = shouldTranspose(grid);
	if (result.transposed)
	{
		transpose(grid);
	}
	return result;
}

void AiMath2048::denormalize(TILE grid[][SIZE], const NormalizeInfo normalizeInfo)
{
	if (normalizeInfo.transposed)
	{
		transpose(grid);
	}

	switch (normalizeInfo.highestAngle)
	{
	case Angles::TopRight:
		rotate90CW(grid);
		break;
	case Angles::BottomRight:
		rotate180(grid);
		break;
	case Angles::BottomLeft:
		rotate90CCW(grid);
		break;
	}
}

Direction AiMath2048::denormalizeDirection(Direction direction, const NormalizeInfo restoreInfo)
{
	// need to decode result
	if (restoreInfo.transposed)
	{
		switch (direction)
		{
		case Up:
			direction = Left;
			break;
		case Right:
			direction = Down;
			break;
		case Down:
			direction = Right;
			break;
		case Left:
		default:
			direction = Up;
			break;
		}
	}

	return (Direction)(((int)direction + (int)(restoreInfo.highestAngle)) % 4);
}