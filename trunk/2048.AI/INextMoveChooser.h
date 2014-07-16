#include "stdafx.h"

#ifndef __I_NEXT_MOVE_CHOOSER__
#define __I_NEXT_MOVE_CHOOSER__

#include "2048Core.h"
#include "AiMathQuery.h"

namespace AiMath2048
{
	class INextMoveChooser
	{
	public:
		virtual ~INextMoveChooser() {}
		virtual Core2048::Direction getNextMove(const Core2048::TILE grid[SIZE][SIZE]) const = 0;
	};
}
#endif