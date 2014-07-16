#pragma once

#include "MilGrid.h"

#define ZERO TILE(0)

using namespace MilCore;

namespace MilGridTests
{
	MilGrid getEmptyGrid()
	{
		MilGrid result;
		result.resetGrid();
		return result;
	}

	MilGrid getFilledGrid()
	{
		MilGrid grid;
		TILE values[SIZE][SIZE] = {
				{1, 2, 3, 4},
				{3, 0, 1, 2},
				{3, 2, 1, 4},
				{4, 6, 4, 7}};
			
		for (unsigned int i=0; i<SIZE; ++i)
		{
			for (auto j=0; j<SIZE; ++j)
			{
				grid[i][j] = values[i][j];
			}
		}
		return grid;
	}

	void copy(MilGrid& grid, TILE values[SIZE][SIZE])
	{
		for (unsigned int i=0; i<SIZE; ++i)
		{
			for (auto j=0; j<SIZE; ++j)
			{
				grid[i][j] = values[i][j];
			}
		}
	}

	void writeArbitratyValues(MilGrid& grid, TILE values[SIZE][SIZE])
	{
		TILE arbValues[SIZE][SIZE] = {
				{1, 2, 3, 4},
				{3, 0, 1, 2},
				{3, 2, 1, 4},
				{4, 6, 4, 7}};
			
		for (unsigned int i=0; i<SIZE; ++i)
		{
			for (auto j=0; j<SIZE; ++j)
			{
				grid[i][j] = arbValues[i][j];
				values[i][j] = arbValues[i][j];
			}
		}
	}
}