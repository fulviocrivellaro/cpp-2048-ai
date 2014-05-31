#include "stdafx.h"

#ifndef __AI_MATH__QUERY__
#define __AI_MATH__QUERY__

#include "2048Core.h"

#define AIScore float
#define HIGHEST_SCORE 1.0f

namespace AiMath2048
{
	namespace Query
	{
		using namespace Core2048;

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