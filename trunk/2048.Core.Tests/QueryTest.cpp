#pragma once

#include "stdafx.h"
#include "CppUnitTest.h"
#include "TestUtils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MilGridTests
{
	using namespace MilCore;

	TEST_CLASS(QueryTest)
	{
	public:

		TEST_METHOD(CanMoveGridTest1)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
			                         {0, 3, 2, 0},
			                         {9, 2, 3, 4},
			                         {9, 8, 4, 2}};
			assertCanMove(grid,
				/*    UP */ true,
				/*  DOWN */ true,
				/*  LEFT */ true,
				/* RIGHT */ true);
		}

		TEST_METHOD(CanMoveGridTest2)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
			                         {0, 3, 2, 1},
			                         {9, 2, 3, 4},
			                         {9, 8, 4, 2}};
			assertCanMove(grid,
				/*    UP */ true,
				/*  DOWN */ true,
				/*  LEFT */ true,
				/* RIGHT */ false);
		}

		TEST_METHOD(CanMoveGridTest3)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
			                         {2, 3, 2, 1},
			                         {9, 2, 3, 4},
			                         {9, 8, 4, 2}};
			assertCanMove(grid,
				/*    UP */ true,
				/*  DOWN */ true,
				/*  LEFT */ false,
				/* RIGHT */ false);
		}

		TEST_METHOD(CanMoveGridTest5)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
			                         {2, 3, 2, 1},
			                         {7, 2, 3, 4},
			                         {9, 8, 4, 2}};
			assertCanMove(grid,
				/*    UP */ false,
				/*  DOWN */ false,
				/*  LEFT */ false,
				/* RIGHT */ false);
		}

		TEST_METHOD(CanMoveGridTest6)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 0},
			                         {2, 3, 2, 0},
			                         {7, 2, 3, 0},
			                         {9, 8, 4, 0}};
			assertCanMove(grid,
				/*    UP */ false,
				/*  DOWN */ false,
				/*  LEFT */ false,
				/* RIGHT */ true);
		}

		TEST_METHOD(CanMoveGridTest7)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
			                         {2, 3, 2, 1},
			                         {7, 2, 3, 4},
			                         {0, 0, 0, 0}};
			assertCanMove(grid,
				/*    UP */ false,
				/*  DOWN */ true,
				/*  LEFT */ false,
				/* RIGHT */ false);
		}

		TEST_METHOD(CanMoveGridTest8)
		{
			TILE grid[SIZE][SIZE] = {{0, 0, 0, 0},
			                         {0, 0, 0, 1},
			                         {0, 0, 3, 4},
			                         {0, 8, 4, 2}};
			assertCanMove(grid,
				/*    UP */ true,
				/*  DOWN */ false,
				/*  LEFT */ true,
				/* RIGHT */ false);
		}

		TEST_METHOD(CanMoveGridTest9)
		{
			TILE grid[SIZE][SIZE] = {{0, 0, 0, 0},
			                         {0, 0, 0, 1},
			                         {0, 0, 3, 4},
			                         {0, 8, 4, 4}};
			assertCanMove(grid,
				/*    UP */ true,
				/*  DOWN */ true,
				/*  LEFT */ true,
				/* RIGHT */ true);
		}

	private:

		void assertCanMove(TILE grid[][SIZE], bool canMoveUp, bool canMoveDown, bool canMoveLeft, bool canMoveRight)
		{
			auto milgrid = getFilledGrid(grid);
			Assert::AreEqual(   canMoveUp, milgrid.canMove(Direction::Up));
			Assert::AreEqual( canMoveDown, milgrid.canMove(Direction::Down));
			Assert::AreEqual( canMoveLeft, milgrid.canMove(Direction::Left));
			Assert::AreEqual(canMoveRight, milgrid.canMove(Direction::Right));
		}

	};
}