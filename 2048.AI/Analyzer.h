#pragma once

#include "stdafx.h"

#include "AiMath.h"

#define AIScore unsigned int
#define BASE_SCORE 1
#define MIN_SCORE 0
#define MAX_SCORE ULONG_MAX

namespace AIMilGrid
{
	struct AISetup
	{
		AIScore isHighestInTheCorner;
		AIScore isMainColumnOrdered;
		AIScore isMainColumnHighest;
		AIScore forcedToUnwantedMove;
		AIScore availableMoves;
		AIScore countOrderedRows;
		AIScore countEmptyTiles;
	};

	using namespace MilCore;
	
	class Analyzer
	{
	public:
		Analyzer(const MilGrid & milgrid);
		~Analyzer() {}

		bool isHighestInTheCorner() const;
		
		bool isMainColumnOrdered() const;

		bool isMainColumnHighest() const;

		bool forcedToUnwantedMove() const;

		unsigned int availableMoves() const;

		unsigned int countOrderedRows() const;

		unsigned int countEmptyTiles() const;
	
	private:
		const MilGrid& mGrid;
	};
}
