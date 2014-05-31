// 2048.CppClassLib.h

#pragma once

using namespace System;

#include "Cpp2048Native.h"
#include "2048Core.h"

namespace Cpp2048ClassLib {

	public ref class Cpp2048
	{
	public:
		Cpp2048();
		~Cpp2048();

		bool CanMove(const CppDirection direction);
	
		bool Stalled();
	
		int Move(const CppDirection direction);
	
		void AddNewTile();

		TILE GetValueForPosition(const int col, const int row);

	private:
		Cpp2048Native* mpNative;
	};
}
