#pragma once

#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<>
static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<>(const AIMilGrid::Angles& t) { RETURN_WIDE_STRING((int)t); }

namespace My2048AITests
{		
	using namespace MilCore;
	using namespace AIMilGrid;
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
			Analyzer analyzer(milgrid);
			Assert::IsFalse(analyzer.isHighestInTheCorner());

			milgrid[0][0] = 8;
			Assert::IsTrue(analyzer.isHighestInTheCorner());
		}

		TEST_METHOD(IsMainColumnOrderedTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 2, 3, 4},
									 {7, 3, 2, 0},
									 {6, 2, 2, 0},
									 {5, 5, 4, 4}};
			auto milgrid = getFilledGrid(grid);
			Analyzer analyzer(milgrid);
			
			Assert::IsTrue(analyzer.isMainColumnOrdered());
			
			milgrid[2][0] = 3;
			Assert::IsFalse(analyzer.isMainColumnOrdered());
		}

		TEST_METHOD(ForcedToUnwantedMoveTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 2, 3, 4},
									 {7, 3, 2, 1},
									 {6, 2, 3, 2},
									 {5, 3, 4, 1}};
			auto milgrid = getFilledGrid(grid);
			Analyzer analyzer(milgrid);
			
			Assert::IsTrue(analyzer.forcedToUnwantedMove());
			
			milgrid[3][3] = 0;
			Assert::IsTrue(analyzer.forcedToUnwantedMove());

			milgrid[3][0] = 0;
			Assert::IsFalse(analyzer.forcedToUnwantedMove());
		}
		
		TEST_METHOD(AvailableMovesTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 2, 3, 4},
									 {7, 3, 2, 3},
									 {6, 2, 3, 1},
									 {5, 3, 4, 3}};
			auto milgrid = getFilledGrid(grid);
			Analyzer analyzer(milgrid);
			
			AreEqual(0, analyzer.availableMoves());

			milgrid[0][0] = 0;
			AreEqual(2, analyzer.availableMoves());

			milgrid[1][1] = 0;
			AreEqual(4, analyzer.availableMoves());
		}

		TEST_METHOD(AsymmetricAvailableMovesTest)
		{
			TILE grid[SIZE][SIZE] = {{0, 0, 0, 0},
									 {0, 0, 0, 0},
									 {0, 0, 0, 3},
									 {0, 0, 4, 5}};
			auto milgrid = getFilledGrid(grid);
			Analyzer analyzer(milgrid);
			
			AreEqual(2, analyzer.availableMoves());

			milgrid[1][3] = 3;
			AreEqual(3, analyzer.availableMoves());

			milgrid[3][0] = 1;
			AreEqual(4, analyzer.availableMoves());
		}

		TEST_METHOD(IsMainColumnHighestTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 2, 3, 4},
									 {7, 3, 2, 3},
									 {6, 2, 3, 1},
									 {5, 3, 4, 3}};
			auto milgrid = getFilledGrid(grid);
			Analyzer analyzer(milgrid);
			
			Assert::IsTrue(analyzer.isMainColumnHighest());

			milgrid[0][2] = 8;
			milgrid[1][2] = 8;
			milgrid[2][2] = 8;
			milgrid[3][2] = 8;
			Assert::IsFalse(analyzer.isMainColumnHighest());
		}

		TEST_METHOD(CountOrderedRowsTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 2, 3, 4},
									 {7, 3, 2, 1},
									 {6, 5, 3, 1},
									 {5, 3, 4, 3}};
			auto milgrid = getFilledGrid(grid);
			Analyzer analyzer(milgrid);
			
			AreEqual(2, analyzer.countOrderedRows());

			milgrid[3][1] = 4;
			AreEqual(3, analyzer.countOrderedRows());
		}

		TEST_METHOD(CountEmptyTilesTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 0, 3, 4},
									 {7, 3, 0, 1},
									 {6, 0, 3, 1},
									 {5, 3, 0, 3}};
			auto milgrid = getFilledGrid(grid);
			Analyzer analyzer(milgrid);
			
			AreEqual(4, analyzer.countEmptyTiles());

			milgrid[3][1] = 0;
			AreEqual(5, analyzer.countEmptyTiles());
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