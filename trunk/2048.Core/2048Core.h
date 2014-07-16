#pragma once

#include <math.h>

namespace Core2048
{

	#define SIZE 4
	#define BITS_PER_TILE 4

	typedef unsigned char TILE;
	typedef unsigned char tilePtr;

	// public part

	enum Direction
	{
		Up = 0,
		Right = 1,
		Down = 2,
		Left = 3,
	};

	// reset the grid
	void ResetGrid(TILE grid[][SIZE]);

	// ask if a move is available
	bool CanMove(const TILE grid[][SIZE], const Direction direction);

	// ask if grid is stalled
	bool Stalled(const TILE grid[][SIZE]);

	// try a move
	unsigned int Move(TILE grid[][SIZE], const Direction direction);

	// random
	void AddNewTile(TILE grid[][SIZE]);
	void Randomize();

	// =====================================================================================
	// private part

	static unsigned int BITS_PWR = (unsigned int)pow((double)2, (int)BITS_PER_TILE);

	void WriteLineInGrid(const TILE* const line, TILE grid[][SIZE], const tilePtr idx, const Direction direction);
	void GetLineFromGrid(TILE* const result, const TILE grid[][SIZE], const tilePtr idx, const Direction direction);

	// query
	bool IsEmpty(const TILE* const line);
	bool IsEmpty(const TILE* const line, const tilePtr count);
	bool CanMove(const TILE* const line);

	// move
	void Squeeze(TILE* const line);
	unsigned int Move(TILE* const line);
}
