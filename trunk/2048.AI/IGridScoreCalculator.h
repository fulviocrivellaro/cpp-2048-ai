#include "stdafx.h"

#pragma once

#include "MilCore.h"
#include "Analyzer.h"
#include "MilGrid.h"

namespace MilCore
{
	class MilGrid;
}

namespace AIMilGrid
{
	class IGridScoreCalculator
	{
	public:
		virtual ~IGridScoreCalculator() {}
		virtual AIScore getScore(const MilCore::MilGrid& grid) const = 0;
		virtual AIMilGrid::AISetup getSetup() const = 0;
	};
}
