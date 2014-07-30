#pragma once

#include "stdafx.h"
#include "CppUnitTest.h"
#include "TestUtils.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MilGridCopyTests
{
	using namespace MilCore;

	TEST_CLASS(MilGridCopyTest)
	{
	public:

		TEST_METHOD(MilGridInitTest)
		{
			auto grid = MilGridTests::getFilledGrid();
			auto copied(grid);

			// should be equal
			runOnTiles([&](tilePtr c, tilePtr r) { Assert::AreEqual(grid[c][r], copied[c][r]); });

			// change one value
			copied[2][1] += 2;
			// verify the result
			runOnTiles([&](tilePtr c, tilePtr r) {
				if (c == 2 && r == 1)
				{
					Assert::AreNotEqual(grid[c][r], copied[c][r]);
				}
				else
				{
					Assert::AreEqual(grid[c][r], copied[c][r]);
				}
			});

		}


	};
}