#include "stdafx.h"
#include "2048Addons.h"
#include "2048Core.h"
#include "KeyboardUtils.h"
#include <iostream>
#include <conio.h>

using namespace std;

void PrintGrid(TILE grid[][SIZE])
{
	system("cls");

	for (tilePtr c = 0; c < SIZE; ++c)
	{
		cout << "[ ";
		for (tilePtr r = 0; r < SIZE; ++r)
		{
			int s = (int)pow(2, grid[c][r]);
			if (s == 1)
			{
				cout << "     ";
			}
			else
			{
				if (s < 1000)
				{
					cout << " ";
					if (s < 100)
					{
						cout << " ";
						if (s < 10)
						{
							cout << " ";
						}
					}
				}
				cout << s << " ";
			}
		}
		cout << "]" << endl;
	}
}

void WaitForAMove(TILE grid[][SIZE])
{
	// read from KB
	Direction direction;
	do
	{
		direction = GetDirectionFromKeyboard();
	} while (!CanMove(grid, direction));

	Move(grid, direction);
	AddNewTile(grid);
	PrintGrid(grid);
}