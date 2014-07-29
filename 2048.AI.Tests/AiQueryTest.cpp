#pragma once

#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<>
static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<>(const AiMath2048::Angles& t) { RETURN_WIDE_STRING((int)t); }

namespace My2048AITests
{		
	using namespace MilCore;
	using namespace AiMath2048;
	using namespace Query;
	using namespace MilGridTests;

	TEST_CLASS(AIQueryTest)
	{
	public:
		
		TEST_METHOD(IsHighestInAngleTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
									 {0, 3, 2, 0},
									 {0, 2, 2, 0},
									 {1, 5, 4, 4}};
			
			auto milgrid = getFilledGrid(grid);
			Assert::IsFalse(isHighestInTheCorner(milgrid));

			milgrid[0][0] = 8;
			Assert::IsTrue(isHighestInTheCorner(milgrid));
		}

		TEST_METHOD(IsMainColumnOrderedTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 2, 3, 4},
									 {7, 3, 2, 0},
									 {6, 2, 2, 0},
									 {5, 5, 4, 4}};
			auto milgrid = getFilledGrid(grid);
			
			Assert::IsTrue(isMainColumnOrdered(milgrid));
			
			milgrid[2][0] = 3;
			Assert::IsFalse(isMainColumnOrdered(milgrid));
		}

		TEST_METHOD(ForcedToUnwantedMoveTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 2, 3, 4},
									 {7, 3, 2, 1},
									 {6, 2, 3, 2},
									 {5, 3, 4, 1}};
			auto milgrid = getFilledGrid(grid);
			
			Assert::IsTrue(forcedToUnwantedMove(milgrid));
			
			milgrid[3][3] = 0;
			Assert::IsTrue(forcedToUnwantedMove(milgrid));

			milgrid[3][0] = 0;
			Assert::IsFalse(forcedToUnwantedMove(milgrid));
		}
		
		TEST_METHOD(AvailableMovesTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 2, 3, 4},
									 {7, 3, 2, 3},
									 {6, 2, 3, 1},
									 {5, 3, 4, 3}};
			auto milgrid = getFilledGrid(grid);
			
			AreEqual(0, availableMoves(milgrid));

			milgrid[0][0] = 0;
			AreEqual(2, availableMoves(milgrid));

			milgrid[1][1] = 0;
			AreEqual(4, availableMoves(milgrid));
		}

		TEST_METHOD(AsymmetricAvailableMovesTest)
		{
			TILE grid[SIZE][SIZE] = {{0, 0, 0, 0},
									 {0, 0, 0, 0},
									 {0, 0, 0, 3},
									 {0, 0, 4, 5}};
			auto milgrid = getFilledGrid(grid);
			
			AreEqual(2, availableMoves(milgrid));

			milgrid[1][3] = 3;
			AreEqual(3, availableMoves(milgrid));

			milgrid[3][0] = 1;
			AreEqual(4, availableMoves(milgrid));
		}

		TEST_METHOD(IsMainColumnHighestTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 2, 3, 4},
									 {7, 3, 2, 3},
									 {6, 2, 3, 1},
									 {5, 3, 4, 3}};
			auto milgrid = getFilledGrid(grid);
			
			Assert::IsTrue(isMainColumnHighest(milgrid));

			milgrid[0][2] = 8;
			milgrid[1][2] = 8;
			milgrid[2][2] = 8;
			milgrid[3][2] = 8;
			Assert::IsFalse(isMainColumnHighest(milgrid));
		}

		TEST_METHOD(CountOrderedRowsTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 2, 3, 4},
									 {7, 3, 2, 1},
									 {6, 5, 3, 1},
									 {5, 3, 4, 3}};
			auto milgrid = getFilledGrid(grid);
			
			AreEqual(2, countOrderedRows(milgrid));

			milgrid[3][1] = 4;
			AreEqual(3, countOrderedRows(milgrid));
		}

		TEST_METHOD(CountEmptyTilesTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 0, 3, 4},
									 {7, 3, 0, 1},
									 {6, 0, 3, 1},
									 {5, 3, 0, 3}};
			auto milgrid = getFilledGrid(grid);
			
			AreEqual(4, countEmptyTiles(milgrid));

			milgrid[3][1] = 0;
			AreEqual(5, countEmptyTiles(milgrid));
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

		void AreEqual(int a, unsigned int b)
		{
			Assert::AreEqual((unsigned int)a, b);
		}

	};
}