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

		TEST_METHOD(GridMoveRightTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
								     {0, 3, 2, 0},
									 {0, 2, 2, 0},
									 {1, 5, 4, 4}};
			TILE expc[SIZE][SIZE] = {{1, 2, 3, 4},
					 	 		     {0, 0, 3, 2},
					 	 			 {0, 0, 0, 3},
					 	 			 {0, 1, 5, 5}};
			testMove(grid, expc, Direction::Right, 40);
		}

		TEST_METHOD(GridMoveLeftTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
								     {0, 3, 2, 0},
									 {0, 2, 2, 0},
									 {1, 5, 4, 4}};
			TILE expc[SIZE][SIZE] = {{1, 2, 3, 4},
								     {3, 2, 0, 0},
									 {3, 0, 0, 0},
									 {1, 5, 5, 0}};
			testMove(grid, expc, Direction::Left, 40);
		}

		TEST_METHOD(GridMoveUpTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
								     {0, 3, 2, 0},
									 {0, 2, 2, 0},
									 {1, 5, 4, 4}};
			TILE expc[SIZE][SIZE] = {{2, 2, 3, 5},
								     {0, 3, 3, 0},
									 {0, 2, 4, 0},
									 {0, 5, 0, 0}};
			testMove(grid, expc, Direction::Up, 44);
		}

		TEST_METHOD(GridMoveDownTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
								     {0, 3, 2, 0},
									 {0, 2, 2, 0},
									 {1, 5, 4, 4}};
			TILE expc[SIZE][SIZE] = {{0, 2, 0, 0},
								     {0, 3, 3, 0},
									 {0, 2, 3, 0},
									 {2, 5, 4, 5}};
			testMove(grid, expc, Direction::Down, 44);
		}

		TEST_METHOD(GridMoveDownCriticalTest)
		{
			TILE grid[SIZE][SIZE] = {{0, 0, 0, 0},
								     {0, 0, 0, 0},
									 {0, 0, 0,14},
									 {0, 0, 0,14}};

			TILE expc[SIZE][SIZE] = {{0, 0, 0, 0},
								     {0, 0, 0, 0},
									 {0, 0, 0, 0},
									 {0, 0, 0,15}};
			testMove(grid, expc, Direction::Down, 32768);
		}

	private:
		void testMove(TILE grid[SIZE][SIZE], TILE expc[SIZE][SIZE], Direction direction, unsigned int expectedPoints)
		{
			auto milgrid = getFilledGrid(grid);
			auto points = milgrid.move(direction);
			runOnTiles([&](tilePtr c, tilePtr r) { Assert::AreEqual(expc[c][r], milgrid[c][r]); });
			Assert::AreEqual(expectedPoints, points);
		}
	};
}