#include "stdafx.h"
#include "CppUnitTest.h"
#include "2048.Core.Tokenizer.h"
#include "2048Core.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My2048CoreTests
{
	using namespace Core2048;

	TEST_CLASS(QueryTest)
	{
	public:

		TEST_METHOD(LineIsEmptyTest)
		{
			TILE l1[SIZE] = {1, 2, 3, 4};
			Assert::IsFalse(IsEmpty(l1));

			TILE l2[SIZE] = {0, 1, 0, 0};
			Assert::IsFalse(IsEmpty(l2));
			
			TILE l3[SIZE] = {0, 0, 0, 0};
			Assert::IsTrue(IsEmpty(l3));
		}

		TEST_METHOD(LineIsEmptyCountTest)
		{
			TILE l1[SIZE] = {1, 2, 3, 0};
			Assert::IsFalse(IsEmpty(l1, 3));

			TILE l2[SIZE] = {0, 0, 1, 0};
			Assert::IsFalse(IsEmpty(l2, 3));
			Assert::IsTrue(IsEmpty(l2, 2));
		}

		TEST_METHOD(LineCanMoveTest)
		{
			TILE l1[SIZE] = {1, 2, 3, 4};
			Assert::IsFalse(CanMove(l1));

			TILE l2[SIZE] = {0, 0, 1, 0};
			Assert::IsTrue(CanMove(l2));

			TILE l3[SIZE] = {0, 0, 0, 0};
			Assert::IsFalse(CanMove(l3));

			TILE l4[SIZE] = {0, 0, 1, 1};
			Assert::IsTrue(CanMove(l4));

			TILE l5[SIZE] = {0, 1, 1, 0};
			Assert::IsTrue(CanMove(l5));

			TILE l6[SIZE] = {2, 2, 3, 4};
			Assert::IsTrue(CanMove(l6));

			TILE l7[SIZE] = {1, 0, 0, 0};
			Assert::IsTrue(CanMove(l7));
		}

		TEST_METHOD(CanMoveGridAndTokenTest1)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
			                         {0, 3, 2, 0},
			                         {9, 2, 3, 4},
			                         {9, 8, 4, 2}};
			AssertCanMove(grid,
				/*    UP */ true,
				/*  DOWN */ true,
				/*  LEFT */ true,
				/* RIGHT */ true);
		}

		TEST_METHOD(CanMoveGridAndTokenTest2)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
			                         {0, 3, 2, 1},
			                         {9, 2, 3, 4},
			                         {9, 8, 4, 2}};
			AssertCanMove(grid,
				/*    UP */ true,
				/*  DOWN */ true,
				/*  LEFT */ true,
				/* RIGHT */ false);
		}

		TEST_METHOD(CanMoveGridAndTokenTest3)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
			                         {2, 3, 2, 1},
			                         {9, 2, 3, 4},
			                         {9, 8, 4, 2}};
			AssertCanMove(grid,
				/*    UP */ true,
				/*  DOWN */ true,
				/*  LEFT */ false,
				/* RIGHT */ false);
		}

		TEST_METHOD(CanMoveGridAndTokenTest5)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
			                         {2, 3, 2, 1},
			                         {7, 2, 3, 4},
			                         {9, 8, 4, 2}};
			AssertCanMove(grid,
				/*    UP */ false,
				/*  DOWN */ false,
				/*  LEFT */ false,
				/* RIGHT */ false);
		}

		TEST_METHOD(CanMoveGridAndTokenTest6)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 0},
			                         {2, 3, 2, 0},
			                         {7, 2, 3, 0},
			                         {9, 8, 4, 0}};
			AssertCanMove(grid,
				/*    UP */ false,
				/*  DOWN */ false,
				/*  LEFT */ false,
				/* RIGHT */ true);
		}

		TEST_METHOD(CanMoveGridAndTokenTest7)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
			                         {2, 3, 2, 1},
			                         {7, 2, 3, 4},
			                         {0, 0, 0, 0}};
			AssertCanMove(grid,
				/*    UP */ false,
				/*  DOWN */ true,
				/*  LEFT */ false,
				/* RIGHT */ false);
		}

		TEST_METHOD(CanMoveGridAndTokenTest8)
		{
			TILE grid[SIZE][SIZE] = {{0, 0, 0, 0},
			                         {0, 0, 0, 1},
			                         {0, 0, 3, 4},
			                         {0, 8, 4, 2}};
			AssertCanMove(grid,
				/*    UP */ true,
				/*  DOWN */ false,
				/*  LEFT */ true,
				/* RIGHT */ false);
		}

		TEST_METHOD(CanMoveGridAndTokenTest9)
		{
			TILE grid[SIZE][SIZE] = {{0, 0, 0, 0},
			                         {0, 0, 0, 1},
			                         {0, 0, 3, 4},
			                         {0, 8, 4, 4}};
			AssertCanMove(grid,
				/*    UP */ true,
				/*  DOWN */ true,
				/*  LEFT */ true,
				/* RIGHT */ true);
		}

	private:

		void AssertCanMove(TILE grid[][SIZE], bool canMoveUp, bool canMoveDown, bool canMoveLeft, bool canMoveRight)
		{
			TOKEN tokn = Tokenizer::GetTokenFromStatus(grid);
			
			Assert::AreEqual(canMoveUp, CanMove(grid, Direction::Up));
			Assert::AreEqual(canMoveUp, Tokenizer::CanMove(tokn, Direction::Up));
			
			Assert::AreEqual(canMoveDown, CanMove(grid, Direction::Down));
			Assert::AreEqual(canMoveDown, Tokenizer::CanMove(tokn, Direction::Down));
			
			Assert::AreEqual(canMoveLeft, CanMove(grid, Direction::Left));
			Assert::AreEqual(canMoveLeft, Tokenizer::CanMove(tokn, Direction::Left));
			
			Assert::AreEqual(canMoveRight, CanMove(grid, Direction::Right));
			Assert::AreEqual(canMoveRight, Tokenizer::CanMove(tokn, Direction::Right));
		}

	};
}