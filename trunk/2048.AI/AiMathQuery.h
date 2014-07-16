#include "stdafx.h"

#ifndef __AI_MATH__QUERY__
#define __AI_MATH__QUERY__

#include <climits>
#include "2048Core.h"

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
		using namespace Core2048;

		bool isHighestInTheCorner(const TILE grid[][SIZE]);
		
		bool isMainColumnOrdered(const TILE grid[][SIZE]);

		bool isMainColumnHighest(const TILE grid[][SIZE]);

		bool forcedToUnwantedMove(const TILE grid[][SIZE]);

		unsigned int availableMoves(const TILE grid[][SIZE]);

		unsigned int countOrderedRows(const TILE grid[][SIZE]);

		unsigned int countEmptyTiles(const TILE grid[][SIZE]);
	}
}

#endif