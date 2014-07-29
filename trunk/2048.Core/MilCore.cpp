#include "MilCore.h"

namespace MilCore
{

	void runOnTiles(std::function<void (tilePtr c, tilePtr r)> func)
	{
		for (tilePtr c=0; c<SIZE; ++c)
		{
			for (tilePtr r=0; r<SIZE; ++r)
			{
				func(c, r);
			}
		}
	}

}