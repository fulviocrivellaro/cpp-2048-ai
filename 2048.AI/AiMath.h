#include "stdafx.h"

#ifndef __AI_MATH__
#define __AI_MATH__

#include "2048Core.h"
#include <algorithm>

using namespace Core2048;

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

	Angles highestAngle(TILE grid[][SIZE]);
	bool shouldTranspose(TILE grid[][SIZE]);

	void rotate90CW(TILE grid[][SIZE]);
	void rotate90CCW(TILE grid[][SIZE]);
	void rotate180(TILE grid[][SIZE]);
	void transpose(TILE grid[][SIZE]);

	NormalizeInfo normalize(TILE grid[][SIZE]);
	void denormalize(TILE grid[][SIZE], const NormalizeInfo normalizeInfo);
}

#endif