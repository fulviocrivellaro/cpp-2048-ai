#include "stdafx.h"

#pragma once

#include "IGridScoreCalculator.h"
#include "Analyzer.h"

namespace MilCore
{
	class MilGrid;
}

namespace AIMilGrid
{
	class ProductGridScoreCalculator :
		public IGridScoreCalculator
	{
	public:
		ProductGridScoreCalculator(const MilGrid& grid, const AISetup setup);
		virtual ~ProductGridScoreCalculator(void);
		virtual AIScore getScore() const;
		AISetup getSetup() const;
	private:
		const Analyzer mAnalyzer;
		AISetup mSetup;
	};
}
