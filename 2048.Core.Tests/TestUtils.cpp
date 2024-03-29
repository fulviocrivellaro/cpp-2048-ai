#include "stdafx.h"
#include "TestUtils.h"

namespace MilGridTests
{
	void copy(MilGrid& grid, TILE values[SIZE][SIZE])
	{
		runOnTiles([&](tilePtr c, tilePtr r)
		{
			grid[c][r] = values[c][r];
		});
	}

	MilGrid getEmptyGrid()
	{
		MilGrid result;
		result.resetGrid();
		return result;
	}

	MilGrid getFilledGrid(TILE values[SIZE][SIZE])
	{
		MilGrid grid;
		copy(grid, values);
		return grid;
	}

	MilGrid getFilledGrid()
	{
		TILE values[SIZE][SIZE] = {
				{1, 2, 3, 4},
				{3, 0, 1, 2},
				{3, 2, 1, 4},
				{4, 6, 4, 7}};
		return getFilledGrid(values);
	}


	void writeArbitratyValues(MilGrid& grid, TILE values[SIZE][SIZE])
	{
		TILE arbValues[SIZE][SIZE] = {
				{1, 2, 3, 4},
				{3, 0, 1, 2},
				{3, 2, 1, 4},
				{4, 6, 4, 7}};

		runOnTiles([&](tilePtr c, tilePtr r)
		{
			grid[c][r] = arbValues[c][r];
			values[c][r] = arbValues[c][r];
		});
	}

	template <typename T>
	void matrixAreEqual(T expected[][SIZE], T value[][SIZE], size_t size)
	{
		runOnTiles([&]() { Assert::AreEqual(expected[c][r], value[c][r]); });
	}
}