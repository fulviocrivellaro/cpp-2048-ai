#include "stdafx.h"
#include "CppUnitTest.h"
#include "TestUtils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My2048CoreTests
{
	using namespace MilCore;

	TEST_CLASS(WriteTest)
	{
	public:

		TEST_METHOD(AddRandomTileTest)
		{
			auto grid = MilGridTests::getEmptyGrid();
			
			for (unsigned int i=1; i<=SIZE*SIZE; ++i)
			{
				grid.addRandomTile();

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
	};
}