#include "stdafx.h"

#ifndef __AI_MATH__QUERY__
#define __AI_MATH__QUERY__

#include "2048Core.h"

namespace AiMath2048
{
	namespace Query
	{
		using namespace Core2048;

		bool isHighestInTheCorner(const TILE grid[][SIZE]);
		
		bool isMainColumnOrdered(const TILE grid[][SIZE]);

		bool isMainColumnHighest(const TILE grid[][SIZE]);

		bool mustMoveDown(const TILE grid[][SIZE]);

		unsigned int availableMoves(const TILE grid[][SIZE]);

		unsigned int countOrderedRows(const TILE grid[][SIZE]);

		unsigned int countEmptyTiles(const TILE grid[][SIZE]);
	}
}

#endif