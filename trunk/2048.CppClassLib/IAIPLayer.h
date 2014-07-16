#ifndef __I_AI_PLAYER__
#define __I_AI_PLAYER__

using namespace System;

#include "Cpp2048Native.h"
#include "2048Core.h"

namespace Cpp2048ClassLib {

	public ref class IAIPlayer
	{
	public:
		virtual ~IAIPlayer();

		virtual CppDirection GetNextMove() = 0;
	};
}

#endif