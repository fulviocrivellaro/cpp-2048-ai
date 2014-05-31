#include "stdafx.h"
#include "CppUnitTest.h"
#include "2048.Core.Tokenizer.h"
#include "2048Core.h"

#ifndef __TOKEN_IS_UNSIGNED__
#include "TokenToString.h"
#endif

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My2048CoreTests
{
	using namespace Core2048;
	using namespace Core2048::Tokenizer;

	TEST_CLASS(TokenTest)
	{
	public:

		TEST_METHOD(BitsPwrTest)
		{
			auto test = (unsigned int)pow((double)2, (int)BITS_PER_TILE);
			Assert::AreEqual(test, BITS_PWR);
		}

		TEST_METHOD(TokenResetTest)
		{
			TILE grid[4][4];
			
			ResetGrid(grid);

			for (tilePtr c = 0; c < SIZE; ++c)
			{
				for (tilePtr r = 0; r < SIZE; ++r)
				{
					Assert::AreEqual(0, (int)grid[r][c]);
				}
			}
		}

		TEST_METHOD(TokenGenerationTest)
		{
			TILE grid[SIZE][SIZE];
			ResetGrid(grid);
			
			TOKEN t = GetTokenFromStatus(grid);
			Assert::AreEqual((TOKEN)0, t);

			grid[0][0] = 2;
			t = GetTokenFromStatus(grid);
			Assert::AreEqual((TOKEN)2, t);

			grid[1][0] = 4;
			t = GetTokenFromStatus(grid);
			Assert::AreEqual((TOKEN)(4*pow(2, 1*BITS_PER_TILE) + 2), t);

			grid[0][0] = 0;
			t = GetTokenFromStatus(grid);
			Assert::AreEqual((TOKEN)(4*pow(2, 1*BITS_PER_TILE)), t);

			grid[1][0] = 0;
			t = GetTokenFromStatus(grid);
			Assert::AreEqual((TOKEN)0, t);

			grid[2][0] = 5;
			t = GetTokenFromStatus(grid);
			Assert::AreEqual((TOKEN)(5*pow(2, 2*BITS_PER_TILE)), t);

			grid[2][2] = 4;
			t = GetTokenFromStatus(grid);
			Assert::AreEqual((TOKEN)(4*pow(2, 10*BITS_PER_TILE) + 5*pow(2, 2*BITS_PER_TILE)), t);
		}

		TEST_METHOD(TokenGetStatusTest)
		{
			// empty
			for (tilePtr c = 0; c < SIZE; ++c)
			{
				for (tilePtr r = 0; r < SIZE; ++r)
				{
					Assert::AreEqual((TILE)0, GetValueForPosition(0, c, r));
				}
			}
			
			TILE grid[SIZE][SIZE];
			ResetGrid(grid);
			
			auto t = GetTokenFromStatus(grid);
			grid[0][0] = 2;
			t = GetTokenFromStatus(grid);
			Assert::AreEqual((TILE)2, GetValueForPosition(t, 0, 0));

			grid[1][0] = 4;
			t = GetTokenFromStatus(grid);
			Assert::AreEqual((TILE)2, GetValueForPosition(t, 0, 0));
			Assert::AreEqual((TILE)4, GetValueForPosition(t, 1, 0));

			grid[0][0] = 0;
			t = GetTokenFromStatus(grid);
			Assert::AreEqual((TILE)0, GetValueForPosition(t, 0, 0));
			Assert::AreEqual((TILE)4, GetValueForPosition(t, 1, 0));

			grid[1][0] = 0;
			t = GetTokenFromStatus(grid);
			Assert::AreEqual((TILE)0, GetValueForPosition(t, 0, 0));
			Assert::AreEqual((TILE)0, GetValueForPosition(t, 1, 0));

			grid[2][0] = 5;
			t = GetTokenFromStatus(grid);
			Assert::AreEqual((TILE)5, GetValueForPosition(t, 2, 0));

			grid[2][2] = 4;
			t = GetTokenFromStatus(grid);
			Assert::AreEqual((TILE)5, GetValueForPosition(t, 2, 0));
			Assert::AreEqual((TILE)4, GetValueForPosition(t, 2, 2));
		}

		TEST_METHOD(TokenGetStatusFromTokenTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
			                         {0, 3, 2, 0},
			                         {9, 2, 3, 4},
			                         {9, 8, 4, 2}};
			TOKEN t = GetTokenFromStatus(grid);
			TILE rebuilt[SIZE][SIZE];
			GetStatusFromToken(rebuilt, t);

			for (tilePtr c = 0; c < SIZE; ++c)
			{
				for (tilePtr r = 0; r < SIZE; ++r)
				{
					Assert::AreEqual(grid[c][r], rebuilt[c][r]);
				}
			}
		}

		TEST_METHOD(TokenSetStatusTest)
		{
			TILE grid[SIZE][SIZE];
			ResetGrid(grid);

			TOKEN t1 = GetTokenFromStatus(grid);

			grid[2][3] = 4;
			
			TOKEN t2 = GetTokenFromStatus(grid);
			SetValueForPosition(4, &t1, 2, 3);

			Assert::AreEqual(t2, t1);
		}

		TEST_METHOD(TokenGetLineFromGridAndTokenTest)
		{
			TILE grid[SIZE][SIZE] = {{1, 2, 3, 4},
			                         {0, 3, 2, 0},
			                         {9, 2, 3, 4},
			                         {9, 8, 4, 2}};
			TOKEN token = GetTokenFromStatus(grid);

			TILE gResult[SIZE];
			TILE tResult[SIZE];

			// left
			GetLineFromGrid(gResult, grid, 1, Direction::Left);
			GetLineFromToken(tResult, token, 1, Direction::Left);
			for (tilePtr i = 0; i < SIZE; ++i)
			{
				Assert::AreEqual(grid[1][SIZE-i-1], gResult[i]);
				Assert::AreEqual(grid[1][SIZE-i-1], tResult[i]);
			}

			// right
			GetLineFromGrid(gResult, grid, 3, Direction::Right);
			GetLineFromToken(tResult, token, 3, Direction::Right);
			for (tilePtr i = 0; i < SIZE; ++i)
			{
				Assert::AreEqual(grid[3][i], gResult[i]);
				Assert::AreEqual(grid[3][i], tResult[i]);
			}

			// up
			GetLineFromGrid(gResult, grid, 2, Direction::Up);
			GetLineFromToken(tResult, token, 2, Direction::Up);
			for (tilePtr i = 0; i < SIZE; ++i)
			{
				Assert::AreEqual(grid[SIZE-i-1][2], gResult[i]);
				Assert::AreEqual(grid[SIZE-i-1][2], tResult[i]);
			}

			// left
			GetLineFromGrid(gResult, grid, 0, Direction::Down);
			GetLineFromToken(tResult, token, 0, Direction::Down);
			for (tilePtr i = 0; i < SIZE; ++i)
			{
				Assert::AreEqual(grid[i][0], gResult[i]);
				Assert::AreEqual(grid[i][0], tResult[i]);
			}
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
		
	};
}