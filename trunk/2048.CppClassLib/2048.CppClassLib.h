// 2048.CppClassLib.h

#ifndef __CPP_2048__
#define __CPP_2048__

using namespace System;

#include "Cpp2048Native.h"
#include "2048Core.h"
#include "INextMoveChooser.h"

namespace Cpp2048ClassLib {

	public ref class Cpp2048
	{
	public:
		Cpp2048();
		~Cpp2048();

		bool CanMove(const CppDirection direction);
	
		bool Stalled();
	
		unsigned int Move(const CppDirection direction);
	
		void AddNewTile();

		TILE GetValueForPosition(const tilePtr col, const tilePtr row);

		unsigned int AutoPlay();

	private:
		Cpp2048Native* mpNative;
		AiMath2048::INextMoveChooser* mpNextMoveChooser;
	};
}

#endif