// ConsolePlayer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "2048Core.h"
#include "2048Addons.h"

#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	
	TILE grid[SIZE][SIZE];
	ResetGrid(grid);
	AddNewTile(grid);
	PrintGrid(grid);

	do
	{
		WaitForAMove(grid);
	} while (!Stalled(grid));

	std::cout << std::endl << "FINISHED!";
	std::getchar();

	return 0;
}

