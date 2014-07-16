// This is the main DLL file.

#include "stdafx.h"

#include "2048.CppClassLib.h"
#include "WorstCaseNextMoveChooser.h"
#include "ProductGridScoreCalculator.h"

namespace Cpp2048ClassLib {

	Cpp2048::Cpp2048()
	{
		using namespace AiMath2048;

		mpNative = new Cpp2048Native();

		AISetup setup;
		setup.availableMoves       =  45;
		setup.countEmptyTiles      =  20;
		setup.countOrderedRows     =  40;
		setup.isHighestInTheCorner = 100;
		setup.isMainColumnHighest  =  50;
		setup.isMainColumnOrdered  =  50;
		setup.forcedToUnwantedMove = 200;

		IGridScoreCalculator* score = new ProductGridScoreCalculator(setup);
		mpNextMoveChooser = new AiMath2048::WorstCaseNextMoveChooser(score);
	}

	Cpp2048::~Cpp2048()
	{
		delete mpNative;
		delete mpNextMoveChooser;
	}

	bool Cpp2048::CanMove(const CppDirection direction)
	{
		return mpNative->CanMove(direction);
	}
	
	bool Cpp2048::Stalled()
	{
		return mpNative->Stalled();
	}
	
	unsigned int Cpp2048::Move(const CppDirection direction)
	{
		return mpNative->Move(direction);
	}
	
	void Cpp2048::AddNewTile()
	{
		mpNative->AddNewTile();
	}

	TILE Cpp2048::GetValueForPosition(const tilePtr col, const tilePtr row)
	{
		return mpNative->GetValueForPosition(col, row);
	}

	unsigned int Cpp2048::AutoPlay()
	{
		if (Stalled()) return 0;

		TILE grid[SIZE][SIZE];
		for (tilePtr r = 0; r < SIZE; ++r)
		{
			for (tilePtr c = 0; c < SIZE; ++c)
			{
				grid[c][r] = GetValueForPosition(c, r);
			}
		}
		int direction = (int)mpNextMoveChooser->getNextMove(grid);
		Direction dir = (Direction)direction;
		CppDirection intDir = (CppDirection)direction;
		return Move((CppDirection)direction);
	}
}
