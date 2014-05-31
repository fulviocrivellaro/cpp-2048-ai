#include "stdafx.h"
#include "CppUnitTest.h"

#include "AiMath.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<>
static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<>(const AiMath2048::Angles& t) { RETURN_WIDE_STRING((int)t); }

namespace My2048AITests
{		
	using namespace Core2048;
	using namespace AiMath2048;

	TEST_CLASS(AIMathTest)
	{
	public:
		
		TEST_METHOD(HighestAngleSimpleTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
									 {0, 3, 2, 0},
									 {0, 2, 2, 0},
									 {1, 5, 4, 4}};
			
			Angles res = highestAngle(grid);
			Assert::AreEqual((int)Angles::BottomLeft, (int)res);
		}

		TEST_METHOD(HighestAngleSumTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
									 {4, 5, 4, 5},
									 {0, 1, 2, 0},
									 {1, 5, 4, 4}};
			
			Angles res = highestAngle(grid);
			Assert::AreEqual((int)Angles::TopRight, (int)res);
		}

		TEST_METHOD(HighestAngleUndefinedTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
									 {4, 5, 4, 5},
									 {3, 5, 2, 0},
									 {3, 5, 4, 4}};
			
			Angles res = highestAngle(grid);
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

			rotate90CW(grid);
			MatrixAreEqual(expected, grid, SIZE);
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

			rotate90CCW(grid);
			MatrixAreEqual(expected, grid, SIZE);
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

			rotate180(grid);
			MatrixAreEqual(expected, grid, SIZE);
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

			transpose(grid);
			MatrixAreEqual(expected, grid, SIZE);
		}

		TEST_METHOD(ShouldTransposeTest)
		{
			TILE grid[SIZE][SIZE] = {{6, 2, 3, 4},
									 {4, 5, 4, 5},
									 {3, 5, 2, 0},
									 {3, 5, 4, 4}};
			
			Assert::IsFalse(shouldTranspose(grid));

			transpose(grid);
			Assert::IsTrue(shouldTranspose(grid));
		}

		TEST_METHOD(NormalizeTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
									 {4, 5, 4, 5},
									 {3, 5, 2, 0},
									 {3, 5, 4, 6}};
			
			auto res = normalize(grid);

			Assert::AreEqual(Angles::BottomRight, res.highestAngle);
			Assert::IsTrue(res.transposed);
			
			// highest angle should now be TopLeft
			Assert::AreEqual(Angles::TopLeft, highestAngle(grid));
		}

		TEST_METHOD(DeNormalize180Test)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
									 {4, 5, 4, 5},
									 {3, 5, 2, 0},
									 {3, 5, 4, 6}};
			TILE copy[SIZE][SIZE];
			for (tilePtr c = 0; c < SIZE; ++c)
			{
				for (tilePtr r = 0; r < SIZE; ++r)
				{
					copy[c][r] = grid[c][r];
				}
			}
			
			auto info = normalize(grid);
			denormalize(grid, info);

			MatrixAreEqual(copy, grid, SIZE);
		}

		TEST_METHOD(DeNormalize90Test)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 6},
									 {4, 5, 4, 5},
									 {3, 5, 2, 4},
									 {3, 5, 4, 1}};
			TILE copy[SIZE][SIZE];
			for (tilePtr c = 0; c < SIZE; ++c)
			{
				for (tilePtr r = 0; r < SIZE; ++r)
				{
					copy[c][r] = grid[c][r];
				}
			}
			
			auto info = normalize(grid);
			denormalize(grid, info);

			MatrixAreEqual(copy, grid, SIZE);
		}

	private:
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