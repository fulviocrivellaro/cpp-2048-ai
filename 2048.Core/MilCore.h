#pragma once

#include <functional>

namespace MilCore
{
	#define SIZE 4

	typedef unsigned char TILE;
	typedef unsigned char tilePtr;

	// public part

	enum Direction
	{
		Up = 0,
		Right = 1,
		Down = 2,
		Left = 3,
	};

	void runOnTiles(std::function<void (tilePtr c, tilePtr r)> func);

}