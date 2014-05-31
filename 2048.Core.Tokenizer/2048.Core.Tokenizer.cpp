#include "2048.Core.Tokenizer.h"

namespace Core2048
{
	namespace Tokenizer
	{

		TOKEN Move(TOKEN token, const Direction direction)
		{
			TILE grid[SIZE][SIZE];
			GetStatusFromToken(grid, token);
			Move(grid, direction);
			return GetTokenFromStatus(grid);
		}

		TOKEN GetTokenFromStatus(const TILE grid[][SIZE])
		{
			TOKEN result = 0;
			auto ctr = 0;
			for (tilePtr r = 0; r < SIZE; ++r)
			{
				for (tilePtr c = 0; c < SIZE; ++c)
				{
					result |= ((TOKEN)grid[c][r]) << (ctr++ * BITS_PER_TILE);
				}
			}
			return result;
		}

		TILE GetValueForPosition(const TOKEN token, const tilePtr column, const tilePtr row)
		{
			unsigned int idx = SIZE * row + column;
			TOKEN mask = BITS_PWR - 1;

			for (unsigned int i=0; i<idx; ++i)
			{
				mask = mask << BITS_PER_TILE;
			}
			mask &= token;
			for (unsigned int i=0; i<idx; ++i)
			{
				mask = mask >> BITS_PER_TILE;
			}
	
			return (TILE)mask;
		}

		void SetValueForPosition(const TILE value, TOKEN* const token, const tilePtr column, const tilePtr row)
		{
			unsigned int idx = SIZE * row + column;
			TOKEN mask = BITS_PWR - 1;
			TOKEN tValue = (TOKEN)value;
			for (unsigned int i=0; i<idx; ++i)
			{
				mask = mask << BITS_PER_TILE;
				tValue = tValue << BITS_PER_TILE;
			}
			*token = (*token & !mask) | (tValue & mask);
		}

		void GetStatusFromToken(TILE grid[][SIZE], const TOKEN token)
		{
			for (tilePtr r = 0; r < SIZE; ++r)
			{
				for (tilePtr c = 0; c < SIZE; ++c)
				{
					grid[c][r] = GetValueForPosition(token, c, r);
				}
			}
		}

		void WriteLineInToken(TILE* const line, TOKEN* const token, const tilePtr idx, const Direction direction)
		{
			TILE grid[SIZE][SIZE];
			GetStatusFromToken(grid, *token);
			WriteLineInGrid(line, grid, idx, direction);
			*token = GetTokenFromStatus(grid);
		}

		void GetLineFromToken(TILE* const result, const TOKEN token, const tilePtr idx, const Direction direction)
		{
			TILE grid[SIZE][SIZE];
			GetStatusFromToken(grid, token);
			GetLineFromGrid(result, grid, idx, direction);
		}

		bool CanMove(const TOKEN token, const Direction direction)
		{
			TILE grid[SIZE][SIZE];
			GetStatusFromToken(grid, token);
			return CanMove(grid, direction);
		}

	}
}