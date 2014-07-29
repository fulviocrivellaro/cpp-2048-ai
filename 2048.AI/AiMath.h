#include "stdafx.h"

#pragma once

#include "MilCore.h"
#include <algorithm>

namespace MilCore
{
	class MilGrid;
}

using namespace MilCore;

namespace AiMath2048
{
	enum Angles
	{
		TopLeft     = 0,
		TopRight    = 1,
		BottomRight = 2,
		BottomLeft  = 3
	};

	struct NormalizeInfo
	{
		Angles highestAngle;
		bool transposed;
	};

#define PREFERRED_ANGLE Angles::TopLeft

	Angles highestAngle(MilGrid& grid);
	bool shouldTranspose(MilGrid& grid);

	void rotate90CW(MilGrid& grid);
	void rotate90CCW(MilGrid& grid);
	void rotate180(MilGrid& grid);
	void transpose(MilGrid& grid);

	NormalizeInfo normalize(MilGrid& grid);
	void denormalize(MilGrid& grid, const NormalizeInfo normalizeInfo);

	Direction denormalizeDirection(Direction originalDirection, const NormalizeInfo restoreInfo);
}
