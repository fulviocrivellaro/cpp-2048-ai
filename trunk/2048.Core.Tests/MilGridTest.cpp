#include "stdafx.h"
#include "CppUnitTest.h"
#include "TestUtils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MilGridTests
{
	using namespace MilCore;

	TEST_CLASS(MilGridTest)
	{
	public:

		TEST_METHOD(MilGridInitTest)
		{
			MilGrid grid = getEmptyGrid();

			for (auto i=0; i<SIZE; ++i)
			{
				for (auto j=0; j<SIZE; ++j)
				{
					Assert::AreEqual(grid[i][j], ZERO);
				}
			}
		}

		TEST_METHOD(MilGridWriteAndReadTest)
		{
			MilGrid grid;

			TILE values[SIZE][SIZE] = {
				{1, 2, 3, 4},
				{3, 0, 1, 2},
				{3, 2, 1, 4},
				{4, 6, 4, 7}};
			
			for (auto i=0; i<SIZE; ++i)
			{
				for (auto j=0; j<SIZE; ++j)
				{
					grid[i][j] = values[i][j];
				}
			}

			for (auto i=0; i<SIZE; ++i)
			{
				for (auto j=0; j<SIZE; ++j)
				{
					Assert::AreEqual(grid[i][j], values[i][j]);
				}
			}
		}

		TEST_METHOD(MilGridConstLineIteratorTest)
		{
			MilGrid grid;

			TILE values[SIZE][SIZE] = {
				{1, 2, 3, 4},
				{3, 0, 1, 2},
				{3, 2, 1, 4},
				{4, 6, 4, 7}};
			
			for (auto i=0; i<SIZE; ++i)
			{
				for (auto j=0; j<SIZE; ++j)
				{
					grid[i][j] = values[i][j];
				}
			}

			//auto it = grid.getConstLine(2, Direction::Down);
		}

	};
}