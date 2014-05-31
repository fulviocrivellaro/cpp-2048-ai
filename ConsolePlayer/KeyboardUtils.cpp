#include "stdafx.h"
#include "KeyboardUtils.h"
#include <conio.h>

Direction GetDirectionFromKeyboard()
{
	while (true)
	{
		while (_getch() != 224)
			;

		switch (_getch())
		{
		case 'H':
			return Direction::Up;
		case 'M':
			return Direction::Right;
		case 'P':
			return Direction::Down;
		case 'K':
			return Direction::Left;
		}
	}
}