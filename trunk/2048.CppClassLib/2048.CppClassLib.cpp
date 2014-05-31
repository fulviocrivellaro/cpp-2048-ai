// This is the main DLL file.

#include "stdafx.h"

#include "2048.CppClassLib.h"

namespace Cpp2048ClassLib {

	Cpp2048::Cpp2048()
	{
		mpNative = new Cpp2048Native();
	}

	Cpp2048::~Cpp2048()
	{
		delete mpNative;
	}

	bool Cpp2048::CanMove(const CppDirection direction)
	{
		return mpNative->CanMove(direction);
	}
	
	bool Cpp2048::Stalled()
	{
		return mpNative->Stalled();
	}
	
	int Cpp2048::Move(const CppDirection direction)
	{
		return mpNative->Move(direction);
	}
	
	void Cpp2048::AddNewTile()
	{
		mpNative->AddNewTile();
	}

	TILE Cpp2048::GetValueForPosition(const int col, const int row)
	{
		return mpNative->GetValueForPosition(col, row);
	}
}
