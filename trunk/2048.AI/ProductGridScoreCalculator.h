#include "stdafx.h"

#ifndef __PRODUCT_GRID_SCORE_CALCULATOR__
#define __PRODUCT_GRID_SCORE_CALCULATOR__

#include "IGridScoreCalculator.h"
#include "AiMathQuery.h"

using namespace AiMath2048::Query;

namespace AiMath2048
{
	class ProductGridScoreCalculator :
		public IGridScoreCalculator
	{
	public:
		ProductGridScoreCalculator(const AISetup setup);
		virtual ~ProductGridScoreCalculator(void);
		virtual AIScore getScore(const Core2048::TILE grid[SIZE][SIZE]) const;
		AISetup getSetup() const;
	private:
		AISetup mSetup;
	};
}

#endif