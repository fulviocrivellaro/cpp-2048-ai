#include "2048Core.h"
#include <cstdlib>
#include <time.h>

namespace Core2048
{

	void ResetGrid(TILE grid[][SIZE])
	{
		for (tilePtr r = 0; r < SIZE; ++r)
		{
			for (tilePtr c = 0; c < SIZE; ++c)
			{
				grid[c][r] = 0;
			}
		}
	}

	void WriteLineInGrid(const TILE* const line, TILE grid[][SIZE], const tilePtr idx, const Direction direction)
	{
		switch (direction)
		{
		case Left:
			for (tilePtr i=0; i<SIZE; ++i)
			{
				grid[idx][SIZE-i-1] = line[i];
			}
			break;
		case Right:
			for (tilePtr i=0; i<SIZE; ++i)
			{
				grid[idx][i] = line[i];
			}
			break;
		case Up:
			for (tilePtr i=0; i<SIZE; ++i)
			{
				grid[SIZE-i-1][idx] = line[i];
			}
			break;
		case Down:
			for (tilePtr i=0; i<SIZE; ++i)
			{
				grid[i][idx] = line[i];
			}
			break;
		}
	}

	void GetLineFromGrid(TILE* const result, const TILE grid[][SIZE], const tilePtr idx, const Direction direction)
	{
		switch (direction)
		{
		case Left:
			for (tilePtr i=0; i<SIZE; ++i)
			{
				result[i] = grid[idx][SIZE-i-1];
			}
			break;
		case Right:
			for (tilePtr i=0; i<SIZE; ++i)
			{
				result[i] = grid[idx][i];
			}
			break;
		case Up:
			for (tilePtr i=0; i<SIZE; ++i)
			{
				result[i] = grid[SIZE-i-1][idx];
			}
			break;
		case Down:
			for (tilePtr i=0; i<SIZE; ++i)
			{
				result[i] = grid[i][idx];
			}
			break;
		}
	}

	bool IsEmpty(const TILE* const line)
	{
		return IsEmpty(line, SIZE);
	}
	
	bool IsEmpty(const TILE* const line, const tilePtr count)
	{
		for (tilePtr i=0; i<count; ++i)
		{
			if (line[i] != 0)
			{
				return false;
			}
		}
		return true;
	}

	void Squeeze(TILE* const line)
	{
		if (IsEmpty(line))
		{
			return;
		}

		for (tilePtr iPos=SIZE-1; iPos>0; --iPos)
		{
			while (line[iPos] == 0 && !IsEmpty(line, iPos))
			{
				// shift others
				for (tilePtr iShift=iPos; iShift>0; --iShift)
				{
					line[iShift] = line[iShift-1];
				}
				line[0] = 0;
			}
		}
	}

	int Move(TILE* const line)
	{
		if (IsEmpty(line))
		{
			return 0;
		}

		int points = 0;
		Squeeze(line);

		for (tilePtr iPos=SIZE-1; iPos>0; --iPos)
		{
			if (line[iPos] != 0 && line[iPos] == line[iPos-1])
			{
				// increment point
				points += 2*line[iPos];
				++line[iPos];

				// shift others
				for (tilePtr iShift=iPos-1; iShift>0; --iShift)
				{
					line[iShift] = line[iShift-1];
				}
				line[0] = 0;
			}
		}

		return points;
	}

	int Move(TILE grid[][SIZE], const Direction direction)
	{
		int points = 0;
		for (tilePtr i=0; i<SIZE; ++i)
		{
			TILE line[SIZE];
			GetLineFromGrid(line, grid, i, direction);
			points += Move(line);
			WriteLineInGrid(line, grid, i, direction);
		}
		return points;
	}

	bool CanMove(const TILE* const line)
	{
		//if (IsEmpty(line))
		//{
		//	return false;
		//}

		for (tilePtr iPos=SIZE-1; iPos>0; --iPos)
		{
			if (line[iPos] == 0 && !IsEmpty(line, iPos)
				|| line[iPos] != 0 && line[iPos] == line[iPos-1])
			{
				return true;
			}
		}
		return false;
	}

	bool CanMove(const TILE grid[][SIZE], const Direction direction)
	{
		TILE line[SIZE];
		for (tilePtr i=0; i<SIZE; ++i)
		{
			GetLineFromGrid(line, grid, i, direction);
			if (CanMove(line))
			{
				return true;
			}
		}
		return false;
	}

	bool Stalled(const TILE grid[][SIZE])
	{
		if (CanMove(grid, Direction::Down)) return false;
		if (CanMove(grid, Direction::Up)) return false;
		if (CanMove(grid, Direction::Left)) return false;
		if (CanMove(grid, Direction::Right)) return false;
		return true;
	}

	void AddNewTile(TILE grid[][SIZE])
	{
		TILE* tiles[SIZE*SIZE];
		unsigned char count = 0;
		for (tilePtr r = 0; r < SIZE; ++r)
		{
			for (tilePtr c = 0; c < SIZE; ++c)
			{
				if (grid[c][r] == 0)
				{
					tiles[count++] = &grid[c][r];
				}
			}
		}

		if (count)
		{
			int pos = rand() % count;
			int val = rand() % 10;

			*tiles[pos] = val > 8 ? 2 : 1;
		}
	}

	void Randomize()
	{
		srand((unsigned int)time(NULL));
	}

}