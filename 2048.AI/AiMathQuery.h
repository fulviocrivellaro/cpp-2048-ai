#include "stdafx.h"

#pragma once

#include "AiMath.h"

#define AIScore unsigned int
#define BASE_SCORE 1
#define MIN_SCORE 0
#define MAX_SCORE ULONG_MAX

namespace AiMath2048
{
	struct AISetup
	{
		AIScore isHighestInTheCorner;
		AIScore isMainColumnOrdered;
		AIScore isMainColumnHighest;
		AIScore forcedToUnwantedMove;
		AIScore availableMoves;
		AIScore countOrderedRows;
		AIScore countEmptyTiles;
	};

	namespace Query
	{
		using namespace MilCore;

		bool isHighestInTheCorner(const MilGrid& grid);
		
		bool isMainColumnOrdered(const MilGrid& grid);

		bool isMainColumnHighest(const MilGrid& grid);

		bool forcedToUnwantedMove(const MilGrid& grid);

		unsigned int availableMoves(const MilGrid& grid);

		unsigned int countOrderedRows(const MilGrid& grid);

		unsigned int countEmptyTiles(const MilGrid& grid);
	}
}
