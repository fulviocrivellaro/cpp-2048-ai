#pragma once

#include "stdafx.h"

#include "MilCore.h"
#include "Analyzer.h"

namespace MilCore
{
	namespace AI
	{
		class INextMoveChooser
		{
		public:
			virtual ~INextMoveChooser() {}
			virtual MilCore::Direction getNextMove(const MilCore::TILE grid[SIZE][SIZE]) const = 0;
		};
	}
}
