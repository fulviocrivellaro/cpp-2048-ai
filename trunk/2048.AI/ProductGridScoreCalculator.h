#include "stdafx.h"

#ifndef __PRODUCT_GRID_SCORE_CALCULATOR__
#define __PRODUCT_GRID_SCORE_CALCULATOR__

#include "IGridScoreCalculator.h"
#include "AiMathQuery.h"

namespace MilCore
{
	class MilGrid;
}

using namespace AiMath2048::Query;

namespace AiMath2048
{
	class ProductGridScoreCalculator :
		public IGridScoreCalculator
	{
	public:
		ProductGridScoreCalculator(const AISetup setup);
		virtual ~ProductGridScoreCalculator(void);
		virtual AIScore getScore(const MilGrid& grid) const;
		AISetup getSetup() const;
	private:
		AISetup mSetup;
	};
}

#endif