#ifndef __2048_CORE_TOKENIZER__
#define __2048_CORE_TOKENIZER__

#include "2048Core.h"

#define __TOKEN_IS_UNSIGNED__
#ifdef __TOKEN_IS_UNSIGNED__
typedef unsigned long long TOKEN;
#else
typedef long long TOKEN;
#endif

namespace Core2048
{
	namespace Tokenizer
	{

		// try a move
		TOKEN Move(TOKEN token, const Direction direction);

		void GetStatusFromToken(TILE grid[][SIZE], const TOKEN token);
		TOKEN GetTokenFromStatus(const TILE grid[][SIZE]);
		TOKEN GetMaskForPosition(const tilePtr column, const tilePtr row);
		TILE GetValueForPosition(const TOKEN token, const tilePtr column, const tilePtr row);
		void SetValueForPosition(const TILE value, TOKEN *token, const tilePtr column, const tilePtr row);
		void WriteLineInToken(const TILE* const line, TOKEN* const token, const tilePtr idx, const Direction direction);
		void GetLineFromToken(TILE* const result, const TOKEN token, const tilePtr idx, const Direction direction);
		bool CanMove(const TOKEN token, const Direction direction);
	}
}

#endif