#pragma once

#include "MilGrid.h"
#include "CppDirection.h"

namespace MilCore
{
	public ref class CSMilGrid
	{
	public:
		CSMilGrid(void);
		~CSMilGrid(void);

		void Reset();

		bool CanMove(const CppDirection direction);
	
		bool IsStalled();
	
		unsigned int Move(const CppDirection direction);
	
		void AddRandomTile();

		TILE GetValue(const tilePtr col, const tilePtr row);

		static const unsigned int getSize()
		{
			return SIZE;
		}

	private:
		MilGrid* mGrid;
	};

}