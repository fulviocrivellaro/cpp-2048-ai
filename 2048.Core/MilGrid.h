#pragma once

#include "MilCore.h"

namespace MilCore
{
	class TileLineIterator;
	class ConstTileLineIterator;

	class MilGrid
	{
	public:
		// constructor
		MilGrid();

		// reset the current grid to zero
		void resetGrid();

		// add new random tile
		void addRandomTile();

		// MOVE

		// try a move
		unsigned int move(const Direction direction);

		// QUERIES

		// ask if a move is available
		bool canMove(Direction direction) const;

		// ask if grid is stalled
		bool isStalled() const;

		// OPERATORS

		const TILE* operator [](const tilePtr index) const
		{
			return mGrid[index];
		}

		TILE* operator [](const tilePtr index)
		{
			return mGrid[index];
		}

	private:

		// extracts a TILE line from the grid
		TileLineIterator getLine(const tilePtr idx, const Direction direction);

		const ConstTileLineIterator getConstLine(const tilePtr idx, const Direction direction) const;

		// tells if a line can be moved, with known iterator
		bool canMoveLine(const ConstTileLineIterator& line) const;

		// tells if a line can be moved, with unknown iterator
		bool canMoveLine(const tilePtr lineIndex, const Direction direction) const;

		// tells if a line is empty
		bool isLineEmpty(const ConstTileLineIterator& line) const;

		// tells if a line is empty, up to given count
		bool isLineEmpty(const ConstTileLineIterator& line, const tilePtr count) const;

		// move
		unsigned int moveLine(TileLineIterator& line);

		// squeeze a line
		void squeezeLine(TileLineIterator& line);

		// data
		TILE mGrid[SIZE][SIZE];
	};
}