#include "stdafx.h"
#include "CppUnitTest.h"
#include "2048Core.h"
#include "2048.Core.Tokenizer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My2048CoreTests
{
	using namespace Core2048;

	TEST_CLASS(MoveTest)
	{
	public:

		TEST_METHOD(LineMoveTest)
		{
			TILE l1[SIZE] = {1, 2, 3, 4};
			TILE e1[SIZE] = {1, 2, 3, 4};
			Move(l1);
			ArrayAreEqual(e1, l1, SIZE);

			TILE l2[SIZE] = {2, 2, 3, 4};
			TILE e2[SIZE] = {0, 3, 3, 4};
			Move(l2);
			ArrayAreEqual(e2, l2, SIZE);

			TILE l3[SIZE] = {1, 2, 2, 4};
			TILE e3[SIZE] = {0, 1, 3, 4};
			Move(l3);
			ArrayAreEqual(e3, l3, SIZE);

			TILE l4[SIZE] = {2, 2, 4, 4};
			TILE e4[SIZE] = {0, 0, 3, 5};
			Move(l4);
			ArrayAreEqual(e4, l4, SIZE);

			TILE l5[SIZE] = {2, 3, 2, 2};
			TILE e5[SIZE] = {0, 2, 3, 3};
			Move(l5);
			ArrayAreEqual(e5, l5, SIZE);

			TILE l6[SIZE] = {3, 3, 2, 2};
			TILE e6[SIZE] = {0, 0, 4, 3};
			Move(l6);
			ArrayAreEqual(e6, l6, SIZE);
		}

		TEST_METHOD(LineSqueezeTest)
		{
			TILE l1[SIZE] = {1, 0, 3, 4};
			TILE e1[SIZE] = {0, 1, 3, 4};
			Squeeze(l1);
			ArrayAreEqual(e1, l1, SIZE);

			TILE l2[SIZE] = {2, 2, 3, 4};
			TILE e2[SIZE] = {2, 2, 3, 4};
			Squeeze(l2);
			ArrayAreEqual(e2, l2, SIZE);

			TILE l3[SIZE] = {0, 0, 0, 0};
			TILE e3[SIZE] = {0, 0, 0, 0};
			Squeeze(l3);
			ArrayAreEqual(e3, l3, SIZE);

			TILE l4[SIZE] = {2, 0, 0, 4};
			TILE e4[SIZE] = {0, 0, 2, 4};
			Squeeze(l4);
			ArrayAreEqual(e4, l4, SIZE);

			TILE l5[SIZE] = {2, 3, 2, 0};
			TILE e5[SIZE] = {0, 2, 3, 2};
			Squeeze(l5);
			ArrayAreEqual(e5, l5, SIZE);

			TILE l6[SIZE] = {0, 4, 0, 3};
			TILE e6[SIZE] = {0, 0, 4, 3};
			Squeeze(l6);
			ArrayAreEqual(e6, l6, SIZE);
		}

		TEST_METHOD(LineMoveWithZerosTest)
		{
			TILE l1[SIZE] = {1, 0, 3, 4};
			TILE e1[SIZE] = {0, 1, 3, 4};
			Move(l1);
			ArrayAreEqual(e1, l1, SIZE);

			TILE l2[SIZE] = {2, 2, 3, 4};
			TILE e2[SIZE] = {0, 3, 3, 4};
			Move(l2);
			ArrayAreEqual(e2, l2, SIZE);

			TILE l3[SIZE] = {1, 2, 2, 4};
			TILE e3[SIZE] = {0, 1, 3, 4};
			Move(l3);
			ArrayAreEqual(e3, l3, SIZE);

			TILE l4[SIZE] = {2, 2, 4, 4};
			TILE e4[SIZE] = {0, 0, 3, 5};
			Move(l4);
			ArrayAreEqual(e4, l4, SIZE);

			TILE l5[SIZE] = {2, 3, 2, 2};
			TILE e5[SIZE] = {0, 2, 3, 3};
			Move(l5);
			ArrayAreEqual(e5, l5, SIZE);

			TILE l6[SIZE] = {3, 3, 2, 2};
			TILE e6[SIZE] = {0, 0, 4, 3};
			Move(l6);
			ArrayAreEqual(e6, l6, SIZE);

			TILE l7[SIZE] = {3, 0, 3, 0};
			TILE e7[SIZE] = {0, 0, 0, 4};
			Move(l7);
			ArrayAreEqual(e7, l7, SIZE);

			TILE l8[SIZE] = {3, 2, 2, 0};
			TILE e8[SIZE] = {0, 0, 3, 3};
			Move(l8);
			ArrayAreEqual(e8, l8, SIZE);
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
			Move(grid, Direction::Right);
			MatrixAreEqual(expc, grid, SIZE);
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
			Move(grid, Direction::Left);
			MatrixAreEqual(expc, grid, SIZE);
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
			Move(grid, Direction::Up);
			MatrixAreEqual(expc, grid, SIZE);
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
			Move(grid, Direction::Down);
			MatrixAreEqual(expc, grid, SIZE);
		}

		TEST_METHOD(GridMoveDownCriticalTest)
		{
			TILE grid[SIZE][SIZE] = {{0, 0, 0, 0},
								     {0, 0, 0, 0},
									 {0, 0, 0,14},
									 {0, 0, 0,14}};

			TOKEN orig = Tokenizer::GetTokenFromStatus(grid);

			TILE expc[SIZE][SIZE] = {{0, 0, 0, 0},
								     {0, 0, 0, 0},
									 {0, 0, 0, 0},
									 {0, 0, 0,15}};
			Move(grid, Direction::Down);
			MatrixAreEqual(expc, grid, SIZE);

			// token version
			TOKEN moved = Tokenizer::Move(orig, Direction::Down);
			Tokenizer::GetStatusFromToken(grid, moved);
			MatrixAreEqual(expc, grid, SIZE);
		}

	private:

		template <typename T>
		void ArrayAreEqual(T* expected, T* value, size_t size)
		{
			for (tilePtr i = 0; i < SIZE; ++i)
			{
				Assert::AreEqual(expected[i], value[i]);
			}
		}

		template <typename T>
		void MatrixAreEqual(T expected[][SIZE], T value[][SIZE], size_t size)
		{
			for (tilePtr c = 0; c < size; ++c)
			{
				for (tilePtr r = 0; r < size; ++r)
				{
					Assert::AreEqual(expected[c][r], value[c][r]);
				}
			}
		}

	};
}