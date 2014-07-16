#ifndef __GRID_WRAPPER__
#define __GRID_WRAPPER__

#include "2048Core.h"

using namespace Core2048;

namespace Cpp2048ClassLib {

	public ref class GridWrapper
	{
	public:
		GridWrapper();
		virtual ~GridWrapper();
		inline TILE GetTileForPosition(const tilePtr c, const tilePtr r);
		inline void SetTileForPosition(const TILE value, const tilePtr c, const tilePtr r);
		inline void CopyFrom(GridWrapper other);

	private:
		TILE* mGrid;
	};
}

#endif