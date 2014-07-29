#include "stdafx.h"

#pragma once

#include "MilCore.h"
#include "AiMathQuery.h"
#include "MilGrid.h"

namespace MilCore
{
	class MilGrid;
}

namespace AiMath2048
{
	class IGridScoreCalculator
	{
	public:
		virtual ~IGridScoreCalculator() {}
		virtual AIScore getScore(const MilCore::MilGrid& grid) const = 0;
		virtual AiMath2048::AISetup getSetup() const = 0;
	};
}
