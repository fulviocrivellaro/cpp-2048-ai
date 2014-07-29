#include "stdafx.h"

#ifndef __I_NEXT_MOVE_CHOOSER__
#define __I_NEXT_MOVE_CHOOSER__

#include "MilCore.h"
#include "AiMathQuery.h"

namespace AiMath2048
{
	class INextMoveChooser
	{
	public:
		virtual ~INextMoveChooser() {}
		virtual MilCore::Direction getNextMove(const MilCore::TILE grid[SIZE][SIZE]) const = 0;
	};
}
#endif