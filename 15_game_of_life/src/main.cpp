#include <iostream>
#include<vector>
#include <time.h>
#include <fstream>
#include "game_of_life.h"



int main()
{
	init();
	//randomize();
	drawShape(shapes::PENTADECATHOLON, 0, 0);
	for (int i = 0; i < 100; i++)
	{
		
		afisare();

		std::cout << std::endl;
		nextBoard();
	}
}
