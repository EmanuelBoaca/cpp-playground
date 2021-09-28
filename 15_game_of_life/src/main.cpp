#include <iostream>
#include<vector>
#include <time.h>
#include <fstream>
#include "game_of_life.h"
#include "GameOfLive.h"

int main()
{
	//GameOfLive gol = GameOfLive();
	
	init();
	//randomize();
	drawShape(shapes::BOAT, 0, 0);
	for (int i = 0; i < 100; i++)
	{
		
		afisare();

		std::cout << std::endl;
		nextBoard();
	}
//	std::cout << gol;
//	gol.nextBoard();
//	std::cout << gol;
}
