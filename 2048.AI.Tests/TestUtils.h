#pragma once

#include "MilGrid.h"

#define ZERO TILE(0)

using namespace MilCore;

namespace MilGridTests
{
	void copy(MilGrid& grid, TILE values[SIZE][SIZE]);

	MilGrid getEmptyGrid();

	MilGrid getFilledGrid(TILE values[SIZE][SIZE]);

	MilGrid getFilledGrid();

	void writeArbitratyValues(MilGrid& grid, TILE values[SIZE][SIZE]);
	
	template <typename T>
	void matrixAreEqual(T expected[][SIZE], T value[][SIZE], size_t size);
}