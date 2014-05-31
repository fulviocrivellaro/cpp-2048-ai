#ifndef __TOKENIZER__
#define __TOKENIZER__

#include "2048Core.h"
#include "2048.Core.Tokenizer.h"

#define DllExport extern "C" __declspec( dllexport )

namespace Core2048
{
	namespace Tokenizer
	{
		namespace Dll
		{
			// ask if a move is available
			DllExport bool CanMoveUp(TOKEN token);
			DllExport bool CanMoveLeft(TOKEN token);
			DllExport bool CanMoveDown(TOKEN token);
			DllExport bool CanMoveRight(TOKEN token);

			// ask if grid is stalled
			DllExport bool Stalled(TOKEN token);

			// move
			DllExport TOKEN MoveUp(TOKEN token);
			DllExport TOKEN MoveLeft(TOKEN token);
			DllExport TOKEN MoveDown(TOKEN token);
			DllExport TOKEN MoveRight(TOKEN token);

			// random
			DllExport TOKEN AddNewTile(TOKEN);
		}
	}
}

#endif