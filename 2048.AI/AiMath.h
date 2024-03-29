#include "stdafx.h"

#pragma once

#include "MilCore.h"
#include <algorithm>

namespace MilCore
{
	class MilGrid;

	namespace AI
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

		Angles highestAngle(const MilGrid& grid);
		bool shouldTranspose(const MilGrid& grid);

		void rotate90CW(MilGrid& grid);
		void rotate90CCW(MilGrid& grid);
		void rotate180(MilGrid& grid);
		void transpose(MilGrid& grid);

		NormalizeInfo normalize(MilGrid& grid);
		void denormalize(MilGrid& grid, const NormalizeInfo normalizeInfo);

		Direction denormalizeDirection(Direction originalDirection, const NormalizeInfo restoreInfo);
	}
}
