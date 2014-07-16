#pragma once

#include "CppDirection.h"
#include "2048Core.h"
#include <map>

using namespace Core2048;

class Cpp2048Native
{

public:
	Cpp2048Native();
	~Cpp2048Native() {}

	bool CanMove(const CppDirection direction) const;
	
	bool Stalled() const;
	
	unsigned int Move(const CppDirection direction);
	
	void AddNewTile();

	TILE GetValueForPosition(const int col, const int row) const;

private:
	TILE mGrid[SIZE][SIZE];
};

