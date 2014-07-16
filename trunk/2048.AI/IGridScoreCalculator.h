#include "stdafx.h"

#ifndef __I_GRID_SCORE_CALCULATOR__
#define __I_GRID_SCORE_CALCULATOR__

#include "2048Core.h"
#include "AiMathQuery.h"

namespace AiMath2048
{
	class IGridScoreCalculator
	{
	public:
		virtual ~IGridScoreCalculator() {}
		virtual AIScore getScore(const Core2048::TILE grid[SIZE][SIZE]) const = 0;
		virtual AiMath2048::AISetup getSetup() const = 0;
	};
}
#endif