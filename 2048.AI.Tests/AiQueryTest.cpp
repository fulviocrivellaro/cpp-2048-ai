#include "stdafx.h"
#include "CppUnitTest.h"

#include "AiMath.h"
#include "AiMathQuery.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<>
static std::wstring Microsoft::VisualStudio::CppUnitTestFramework::ToString<>(const AiMath2048::Angles& t) { RETURN_WIDE_STRING((int)t); }

namespace My2048AITests
{		
	using namespace Core2048;
	using namespace AiMath2048;
	using namespace Query;

	TEST_CLASS(AIQueryTest)
	{
	public:
		
		TEST_METHOD(IsHighestInAngleTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
									 {0, 3, 2, 0},
									 {0, 2, 2, 0},
									 {1, 5, 4, 4}};
			
			Assert::IsFalse(isHighestInTheCorner(grid));

			grid[0][0] = 8;
			Assert::IsTrue(isHighestInTheCorner(grid));
		}

		TEST_METHOD(IsMainColumnOrderedTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 2, 3, 4},
									 {7, 3, 2, 0},
									 {6, 2, 2, 0},
									 {5, 5, 4, 4}};
			
			Assert::IsTrue(isMainColumnOrdered(grid));
			
			grid[2][0] = 3;
			Assert::IsFalse(isMainColumnOrdered(grid));
		}

		TEST_METHOD(ForcedToUnwantedMoveTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 2, 3, 4},
									 {7, 3, 2, 1},
									 {6, 2, 3, 2},
									 {5, 3, 4, 1}};
			
			Assert::IsTrue(forcedToUnwantedMove(grid));
			
			grid[3][3] = 0;
			Assert::IsTrue(forcedToUnwantedMove(grid));

			grid[3][0] = 0;
			Assert::IsFalse(forcedToUnwantedMove(grid));
		}
		
		TEST_METHOD(AvailableMovesTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 2, 3, 4},
									 {7, 3, 2, 3},
									 {6, 2, 3, 1},
									 {5, 3, 4, 3}};
			
			AreEqual(0, availableMoves(grid));

			grid[0][0] = 0;
			AreEqual(2, availableMoves(grid));

			grid[1][1] = 0;
			AreEqual(4, availableMoves(grid));
		}

		TEST_METHOD(AsymmetricAvailableMovesTest)
		{
			TILE grid[SIZE][SIZE] = {{0, 0, 0, 0},
									 {0, 0, 0, 0},
									 {0, 0, 0, 3},
									 {0, 0, 4, 5}};
			
			AreEqual(2, availableMoves(grid));

			grid[1][3] = 3;
			AreEqual(3, availableMoves(grid));

			grid[3][0] = 1;
			AreEqual(4, availableMoves(grid));
		}

		TEST_METHOD(IsMainColumnHighestTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 2, 3, 4},
									 {7, 3, 2, 3},
									 {6, 2, 3, 1},
									 {5, 3, 4, 3}};
			
			Assert::IsTrue(isMainColumnHighest(grid));

			grid[0][2] = 8;
			grid[1][2] = 8;
			grid[2][2] = 8;
			grid[3][2] = 8;
			Assert::IsFalse(isMainColumnHighest(grid));
		}

		TEST_METHOD(CountOrderedRowsTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 2, 3, 4},
									 {7, 3, 2, 1},
									 {6, 5, 3, 1},
									 {5, 3, 4, 3}};
			
			AreEqual(2, countOrderedRows(grid));

			grid[3][1] = 4;
			AreEqual(3, countOrderedRows(grid));
		}

		TEST_METHOD(CountEmptyTilesTest)
		{
			TILE grid[SIZE][SIZE] = {{8, 0, 3, 4},
									 {7, 3, 0, 1},
									 {6, 0, 3, 1},
									 {5, 3, 0, 3}};
			
			AreEqual(4, countEmptyTiles(grid));

			grid[3][1] = 0;
			AreEqual(5, countEmptyTiles(grid));
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