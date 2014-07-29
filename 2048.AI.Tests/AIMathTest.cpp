#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<>
static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<>(const AIMilGrid::Angles& t) { RETURN_WIDE_STRING((int)t); }

namespace My2048AITests
{		
	using namespace MilCore;
	using namespace AIMilGrid;
	using namespace MilGridTests;

	TEST_CLASS(AIMathTest)
	{
	public:
		
		TEST_METHOD(HighestAngleSimpleTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
									 {0, 3, 2, 0},
									 {0, 2, 2, 0},
									 {1, 5, 4, 4}};
			
			Angles res = highestAngle(getFilledGrid(grid));
			Assert::AreEqual((int)Angles::BottomLeft, (int)res);
		}

		TEST_METHOD(HighestAngleSumTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
									 {4, 5, 4, 5},
									 {0, 1, 2, 0},
									 {1, 5, 4, 4}};
			
			Angles res = highestAngle(getFilledGrid(grid));
			Assert::AreEqual((int)Angles::TopRight, (int)res);
		}

		TEST_METHOD(HighestAngleUndefinedTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
									 {4, 5, 4, 5},
									 {3, 5, 2, 0},
									 {3, 5, 4, 4}};
			
			Angles res = highestAngle(getFilledGrid(grid));
			bool expectedTrue = res == Angles::TopRight || res == Angles::BottomLeft;
			Assert::IsTrue(expectedTrue);
		}

		TEST_METHOD(Rotate90CWTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
									 {4, 5, 4, 5},
									 {3, 5, 2, 0},
									 {3, 5, 4, 4}};
			
			TILE expected[SIZE][SIZE] = {{3, 3, 4, 1},
									     {5, 5, 5, 2},
									     {4, 2, 4, 3},
									     {4, 0, 5, 4}};

			auto milgrid = getFilledGrid(grid);
			rotate90CW(milgrid);
			MatrixAreEqual(expected, milgrid, SIZE);
		}

		TEST_METHOD(Rotate90CCWTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
									 {4, 5, 4, 5},
									 {3, 5, 2, 0},
									 {3, 5, 4, 4}};
			
			TILE expected[SIZE][SIZE] = {{4, 5, 0, 4},
									     {3, 4, 2, 4},
									     {2, 5, 5, 5},
									     {1, 4, 3, 3}};

			auto milgrid = getFilledGrid(grid);
			rotate90CCW(milgrid);
			MatrixAreEqual(expected, milgrid, SIZE);
		}

		TEST_METHOD(Rotate180Test)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
									 {4, 5, 4, 5},
									 {3, 5, 2, 0},
									 {3, 5, 4, 4}};
			
			TILE expected[SIZE][SIZE] = {{4, 4, 5, 3},
									     {0, 2, 5, 3},
									     {5, 4, 5, 4},
									     {4, 3, 2, 1}};

			auto milgrid = getFilledGrid(grid);
			rotate180(milgrid);
			MatrixAreEqual(expected, milgrid, SIZE);
		}
		
		TEST_METHOD(TransposeTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
									 {4, 5, 4, 5},
									 {3, 5, 2, 0},
									 {3, 5, 4, 4}};
			
			TILE expected[SIZE][SIZE] = {{1, 4, 3, 3},
									     {2, 5, 5, 5},
									     {3, 4, 2, 4},
									     {4, 5, 0, 4}};

			auto milgrid = getFilledGrid(grid);
			transpose(milgrid);
			MatrixAreEqual(expected, milgrid, SIZE);
		}

		TEST_METHOD(ShouldTransposeTest)
		{
			TILE grid[SIZE][SIZE] = {{6, 2, 3, 4},
									 {4, 5, 4, 5},
									 {3, 5, 2, 0},
									 {3, 5, 4, 4}};
			
			auto milgrid = getFilledGrid(grid);
			Assert::IsFalse(shouldTranspose(milgrid));

			transpose(milgrid);
			Assert::IsTrue(shouldTranspose(milgrid));
		}

		TEST_METHOD(NormalizeTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
									 {4, 5, 4, 5},
									 {3, 5, 2, 0},
									 {3, 5, 4, 6}};
			
			auto milgrid = getFilledGrid(grid);
			NormalizeInfo res = normalize(milgrid);

			Assert::AreEqual(Angles::BottomRight, res.highestAngle);
			Assert::IsTrue(res.transposed);
			
			// highest angle should now be TopLeft
			Assert::AreEqual(Angles::TopLeft, highestAngle(milgrid));
		}

		TEST_METHOD(DeNormalize180Test)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
									 {4, 5, 4, 5},
									 {3, 5, 2, 0},
									 {3, 5, 4, 6}};
			auto milgrid = getFilledGrid(grid);
			
			NormalizeInfo info = normalize(milgrid);
			denormalize(milgrid, info);

			MatrixAreEqual(grid, milgrid, SIZE);
		}

		TEST_METHOD(DeNormalize90Test)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 6},
									 {4, 5, 4, 5},
									 {3, 5, 2, 4},
									 {3, 5, 4, 1}};
			auto milgrid = getFilledGrid(grid);
			
			NormalizeInfo info = normalize(milgrid);
			denormalize(milgrid, info);

			MatrixAreEqual(grid, milgrid, SIZE);
		}

		TEST_METHOD(DeNormalizeDirectionPlainTest)
		{
			TILE grid[SIZE][SIZE] = {{5, 0, 0, 0},
									 {4, 0, 0, 1},
									 {4, 0, 0, 0},
									 {0, 0, 0, 0}};
			
			auto milgrid = getFilledGrid(grid);
			NormalizeInfo info = normalize(milgrid);

			Direction bestDirection = Direction::Up;
			Direction normalizedDirection = Direction::Up;
			Assert::AreEqual((int)bestDirection, (int)denormalizeDirection(normalizedDirection, info));
		}

		TEST_METHOD(DeNormalizeDirectionPlainTransposedTest)
		{
			TILE grid[SIZE][SIZE] = {{5, 3, 3, 1},
									 {0, 0, 0, 0},
									 {0, 0, 0, 0},
									 {0, 0, 0, 0}};
			auto milgrid = getFilledGrid(grid);
			NormalizeInfo info = normalize(milgrid);

			Direction bestDirection = Direction::Left;
			Direction normalizedDirection = Direction::Up;
			Assert::AreEqual((int)bestDirection, (int)denormalizeDirection(normalizedDirection, info));
		}

		TEST_METHOD(DeNormalizeDirection90CCWTest)
		{
			TILE grid[SIZE][SIZE] = {{0, 4, 4, 5},
									 {0, 0, 0, 1},
									 {0, 0, 0, 0},
									 {0, 0, 0, 0}};
			auto milgrid = getFilledGrid(grid);
			NormalizeInfo info = normalize(milgrid);

			Direction bestDirection = Direction::Right;
			Direction normalizedDirection = Direction::Up;
			Assert::AreEqual((int)bestDirection, (int)denormalizeDirection(normalizedDirection, info));
		}

		TEST_METHOD(DeNormalizeDirection90CCWTransposedTest)
		{
			TILE grid[SIZE][SIZE] = {{0, 0, 0, 5},
									 {0, 0, 0, 4},
									 {0, 0, 0, 4},
									 {0, 0, 0, 0}};
			auto milgrid = getFilledGrid(grid);
			NormalizeInfo info = normalize(milgrid);

			Direction bestDirection = Direction::Up;
			Direction normalizedDirection = Direction::Up;
			Assert::AreEqual((int)bestDirection, (int)denormalizeDirection(normalizedDirection, info));
		}

		TEST_METHOD(DeNormalizeDirection180TransposedTest)
		{
			TILE grid[SIZE][SIZE] = {{0, 0, 0, 0},
									 {0, 0, 0, 0},
									 {0, 0, 0, 4},
									 {1, 2, 3, 4}};
			auto milgrid = getFilledGrid(grid);
			NormalizeInfo info = normalize(milgrid);

			Direction bestDirection = Direction::Down;
			Direction normalizedDirection = Direction::Left;
			Assert::AreEqual((int)bestDirection, (int)denormalizeDirection(normalizedDirection, info));
		}

		TEST_METHOD(DeNormalizeDirection180Test)
		{
			TILE grid[SIZE][SIZE] = {{0, 0, 0, 2},
									 {0, 0, 0, 3},
									 {0, 0, 0, 4},
									 {1, 2, 3, 4}};
			auto milgrid = getFilledGrid(grid);
			NormalizeInfo info = normalize(milgrid);

			Direction bestDirection = Direction::Down;
			Direction normalizedDirection = Direction::Up;
			Assert::AreEqual((int)bestDirection, (int)denormalizeDirection(normalizedDirection, info));
		}

		TEST_METHOD(DeNormalizeDirection90CWTest)
		{
			TILE grid[SIZE][SIZE] = {{0, 0, 0, 0},
									 {0, 0, 0, 1},
									 {0, 0, 0, 0},
									 {5, 4, 4, 2}};
			auto milgrid = getFilledGrid(grid);
			NormalizeInfo info = normalize(milgrid);

			Direction bestDirection = Direction::Left;
			Direction normalizedDirection = Direction::Up;
			Assert::AreEqual((int)bestDirection, (int)denormalizeDirection(normalizedDirection, info));
		}

		TEST_METHOD(DeNormalizeDirection90CWTransposedTest)
		{
			TILE grid[SIZE][SIZE] = {{2, 0, 0, 0},
									 {4, 0, 0, 0},
									 {4, 0, 0, 0},
									 {5, 0, 0, 0}};
			auto milgrid = getFilledGrid(grid);
			NormalizeInfo info = normalize(milgrid);

			Direction bestDirection = Direction::Down;
			Direction normalizedDirection = Direction::Up;
			Assert::AreEqual((int)bestDirection, (int)denormalizeDirection(normalizedDirection, info));
		}



	private:
		template <typename T>
		void MatrixAreEqual(T expected[][SIZE], const MilGrid& milgrid, size_t size)
		{
			for (tilePtr c = 0; c < SIZE; ++c)
			{
				for (tilePtr r = 0; r < SIZE; ++r)
				{
					Assert::AreEqual(expected[c][r], milgrid[c][r]);
				}
			}
		}

	};
}