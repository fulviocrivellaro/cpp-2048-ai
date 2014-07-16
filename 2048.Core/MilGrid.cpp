#include "MilGrid.h"
#include "TileLineIterator.h"
#include <time.h>
#include <cstdlib>
#include <math.h>

namespace MilCore
{
	MilGrid::MilGrid()
	{
		srand((unsigned int)time(NULL));
		resetGrid();
	}

	void MilGrid::resetGrid()
	{
		for (tilePtr r = 0; r < SIZE; ++r)
		{
			for (tilePtr c = 0; c < SIZE; ++c)
			{
				mGrid[c][r] = 0;
			}
		}
	}

	void MilGrid::addRandomTile()
	{
		TILE* tiles[SIZE*SIZE];
		unsigned int count = 0;
		for (tilePtr r = 0; r < SIZE; ++r)
		{
			for (tilePtr c = 0; c < SIZE; ++c)
			{
				if (mGrid[c][r] == 0)
				{
					tiles[count++] = &mGrid[c][r];
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

	bool MilGrid::canMove(Direction direction) const
	{
		for (tilePtr lineIndex=0; lineIndex<SIZE; ++lineIndex)
		{
			if (canMoveLine(lineIndex, direction))
			{
				return true;
			}
		}
		return false;
	}

	unsigned int MilGrid::move(const Direction direction)
	{
		int points = 0;
		for (tilePtr i=0; i<SIZE; ++i)
		{
			points += moveLine(getLine(i, direction));
		}
		return points;
	}

	TileLineIterator MilGrid::getLine(const tilePtr lineIndex, const Direction direction)
	{
		return TileLineIterator(this, lineIndex, direction);
	}

	const ConstTileLineIterator MilGrid::getConstLine(const tilePtr lineIndex, const Direction direction) const
	{
		return ConstTileLineIterator(this, lineIndex, direction);
	}

	bool MilGrid::isStalled() const
	{
		if (canMove(Direction::Down)) return false;
		if (canMove(Direction::Up)) return false;
		if (canMove(Direction::Left)) return false;
		if (canMove(Direction::Right)) return false;
		return true;
	}

	bool MilGrid::canMoveLine(const ConstTileLineIterator& line) const
	{
		for (tilePtr iPos=SIZE-1; iPos>0; --iPos)
		{
			if (line[iPos] == 0 && !isLineEmpty(line, iPos)
				|| line[iPos] != 0 && line[iPos] == line[iPos-1])
			{
				return true;
			}
		}
		return false;
	}

	bool MilGrid::canMoveLine(const tilePtr lineIndex, const Direction direction) const
	{
		return canMoveLine(getConstLine(lineIndex, direction));
	}

	bool MilGrid::isLineEmpty(const ConstTileLineIterator& line) const
	{
		return isLineEmpty(line, SIZE);
	}

	bool MilGrid::isLineEmpty(const ConstTileLineIterator& line, const tilePtr count) const
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

	// move
	unsigned int MilGrid::moveLine(TileLineIterator& line)
	{
		if (isLineEmpty(line))
		{
			return 0;
		}

		int points = 0;
		squeezeLine(line);

		for (tilePtr iPos=SIZE-1; iPos>0; --iPos)
		{
			if (line[iPos] != 0 && line[iPos] == line[iPos-1])
			{
				// increment point
				++line[iPos];
				points += (int)pow(2.0f, line[iPos]);

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

	// squeeze a line
	void MilGrid::squeezeLine(TileLineIterator& line)
	{
		if (isLineEmpty(line))
		{
			return;
		}

		for (tilePtr iPos=SIZE-1; iPos>0; --iPos)
		{
			while (line[iPos] == 0 && !isLineEmpty(line, iPos))
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
}