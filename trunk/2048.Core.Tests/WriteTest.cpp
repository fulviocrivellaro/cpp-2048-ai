#include "stdafx.h"
#include "CppUnitTest.h"
#include "2048Core.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My2048CoreTests
{
	using namespace Core2048;

	TEST_CLASS(WriteTest)
	{
	public:

		TEST_METHOD(WriteRightTest)
		{
			TILE grid[SIZE][SIZE];
			ResetGrid(grid);
			TILE line[SIZE];
			TILE expected[SIZE] = {1, 2, 3, 0};
			Direction direction = Direction::Right;

			WriteLineInGrid(expected, grid, 2, direction);
			GetLineFromGrid(line, grid, 2, direction);

			ArrayAreEqual(expected, line, SIZE);

			GetLineFromGrid(line, grid, 0, direction);
			Assert::IsTrue(IsEmpty(line));
			GetLineFromGrid(line, grid, 1, direction);
			Assert::IsTrue(IsEmpty(line));
			GetLineFromGrid(line, grid, 3, direction);
			Assert::IsTrue(IsEmpty(line));
		}

		TEST_METHOD(WriteLeftTest)
		{
			TILE grid[SIZE][SIZE];
			ResetGrid(grid);
			TILE line[SIZE];
			TILE expected[SIZE] = {1, 2, 3, 0};
			Direction direction = Direction::Left;

			WriteLineInGrid(expected, grid, 2, direction);
			GetLineFromGrid(line, grid, 2, direction);

			ArrayAreEqual(expected, line, SIZE);

			GetLineFromGrid(line, grid, 0, direction);
			Assert::IsTrue(IsEmpty(line));
			GetLineFromGrid(line, grid, 1, direction);
			Assert::IsTrue(IsEmpty(line));
			GetLineFromGrid(line, grid, 3, direction);
			Assert::IsTrue(IsEmpty(line));
		}

		TEST_METHOD(WriteUpTest)
		{
			TILE grid[SIZE][SIZE];
			ResetGrid(grid);
			TILE line[SIZE];
			TILE expected[SIZE] = {1, 2, 3, 0};
			Direction direction = Direction::Up;

			WriteLineInGrid(expected, grid, 2, direction);
			GetLineFromGrid(line, grid, 2, direction);

			ArrayAreEqual(expected, line, SIZE);

			GetLineFromGrid(line, grid, 0, direction);
			Assert::IsTrue(IsEmpty(line));
			GetLineFromGrid(line, grid, 1, direction);
			Assert::IsTrue(IsEmpty(line));
			GetLineFromGrid(line, grid, 3, direction);
			Assert::IsTrue(IsEmpty(line));
		}

		TEST_METHOD(WriteDownTest)
		{
			TILE grid[SIZE][SIZE];
			ResetGrid(grid);
			TILE line[SIZE];
			TILE expected[SIZE] = {1, 2, 3, 0};
			Direction direction = Direction::Down;

			WriteLineInGrid(expected, grid, 2, direction);
			GetLineFromGrid(line, grid, 2, direction);

			ArrayAreEqual(expected, line, SIZE);

			GetLineFromGrid(line, grid, 0, direction);
			Assert::IsTrue(IsEmpty(line));
			GetLineFromGrid(line, grid, 1, direction);
			Assert::IsTrue(IsEmpty(line));
			GetLineFromGrid(line, grid, 3, direction);
			Assert::IsTrue(IsEmpty(line));
		}

		TEST_METHOD(AddRandomTileTest)
		{
			TILE grid[SIZE][SIZE];
			ResetGrid(grid);
			for (unsigned int i=1; i<=SIZE*SIZE; ++i)
			{
				AddNewTile(grid);

				unsigned int zeros = 0;
				unsigned int gtzeros = 0;
				for (tilePtr r = 0; r < SIZE; ++r)
				{
					for (tilePtr c = 0; c < SIZE; ++c)
					{
						if (grid[c][r] > 0)
						{
							++gtzeros;
						}
						else
						{
							++zeros;
						}
					}
				}

				Assert::AreEqual(i, gtzeros);
				Assert::AreEqual(SIZE*SIZE-i, zeros);
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