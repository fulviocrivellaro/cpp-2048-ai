#include "stdafx.h"

#pragma once

#include "MilCore.h"
#include "Analyzer.h"

namespace MilCore
{
	class MilGrid;

	namespace AI
	{
		class IGridScoreCalculator
		{
		public:
			virtual ~IGridScoreCalculator() {}
			virtual AIScore getScore(const MilGrid& grid) const = 0;
			virtual AISetup getSetup() const = 0;
		};
	}
}
