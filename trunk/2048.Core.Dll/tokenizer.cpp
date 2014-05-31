#include "tokenizer.h"

namespace Core2048
{
	namespace Tokenizer
	{
		namespace Dll
		{

			bool CanMoveUp(TOKEN token)
			{
				return CanMove(token, Direction::Up);
			}

			bool CanMoveLeft(TOKEN token)
			{
				return CanMove(token, Direction::Left);
			}
			bool CanMoveDown(TOKEN token)
			{
				return CanMove(token, Direction::Down);
			}
			bool CanMoveRight(TOKEN token)
			{
				return CanMove(token, Direction::Right);
			}

			bool Stalled(TOKEN token)
			{
				TILE grid[SIZE][SIZE];
				GetStatusFromToken(grid, token);
				return Core2048::Stalled(grid);
			}

			TOKEN MoveUp(TOKEN token)
			{
				return Move(token, Direction::Up);
			}

			TOKEN MoveLeft(TOKEN token)
			{
				return Move(token, Direction::Left);
			}
			TOKEN MoveDown(TOKEN token)
			{
				return Move(token, Direction::Down);
			}
			TOKEN MoveRight(TOKEN token)
			{
				return Move(token, Direction::Right);
			}

			TOKEN AddNewTile(TOKEN token)
			{
				TILE grid[SIZE][SIZE];
				GetStatusFromToken(grid, token);
				Core2048::AddNewTile(grid);
				return GetTokenFromStatus(grid);
			}
		}
	}
	}