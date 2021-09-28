#include <iostream>
#include<vector>
#include <time.h>
#include <fstream>
#include "game_of_life.h"

#define MINIM_X_SIZE 20
#define MINIM_Y_SIZE 20

int board_size_x = MINIM_X_SIZE;
int board_size_y = MINIM_Y_SIZE;
std::vector<std::vector<bool>> currentBoard;
std::vector<std::vector<bool>> previousBoard;
void setboardSize(int x_size, int y_size)
{

	if (x_size < MINIM_X_SIZE || y_size < MINIM_Y_SIZE)
	{
		std::cout << "The size of dimension must bee bigger than " << MINIM_X_SIZE << " !" << std::endl;
		std::cout << "The X and Y size are set to default : " << MINIM_X_SIZE << " , " << MINIM_Y_SIZE<< std::endl;
		board_size_x = MINIM_X_SIZE;
		board_size_y = MINIM_Y_SIZE;

	}
	else
	{
		board_size_x = x_size;
		board_size_y = y_size;
	}
	for each (std::vector<bool> x in currentBoard)
	{
		x.clear();
	}
	currentBoard.clear();
	for (int indexY = 0; indexY < board_size_y; indexY++)
	{
		std::vector<bool>newRow;
		for (int indexX = 0; indexX < board_size_x; indexX++)
		{
			newRow.push_back(false);
		}
		currentBoard.push_back(newRow);
	}


}

void copyPreviousBoardToCurrentBoard()
{

	for each (std::vector<bool> var in previousBoard)
	{
		var.clear();
	}
	previousBoard.clear();
	for each (std::vector<bool> var in currentBoard)
	{
		previousBoard.push_back(std::vector<bool>(var));
	}

}

bool isAlive(int x, int y)
{
	if (x < 0 || y < 0 || x >= board_size_x || y >= board_size_y)
	{
		return false;
	}
	return currentBoard[y][x];
}

void nextBoard()
{
	copyPreviousBoardToCurrentBoard();
	for (int y = 0; y < board_size_y; y++)
	{
		for (int x = 0; x < board_size_x; x++)
		{
			int neighborh = 0;
			for (int i = -1; i <= 1; i++)
			{
				int neiby = y + i;
				for (int j = -1; j <= 1; j++)
				{
					int neibx = x + j;
					if (neiby < 0 || neibx < 0 || neibx >= board_size_x || neiby >= board_size_y)
					{
						continue;
					}
					if (i == 0 && j == 0)
					{
						continue;
					}
					if (previousBoard[neiby][neibx])
					{
						neighborh++;
					}

				}
			}

			if (currentBoard[y][x])
			{
				if (neighborh == 2 || neighborh == 3)
				{
					currentBoard[y][x] = true;
				}
				else
				{
					currentBoard[y][x] = false;
				}
			}
			else
			{
				if (neighborh == 3)
					currentBoard[y][x] = true;
				else
					currentBoard[y][x] = false;
			}
		}
	}
}
void afisare(int x, int y)
{
	if (isAlive(x, y))
	{
		std::cout << "@";
	}
	else
	{
		std::cout << " ";
	}
}
void afisare()
{
	for (int i = 0; i < board_size_x + 2; i++)
		std::cout << "?";
	std::cout << std::endl;
	for (int i = 0; i < board_size_y; i++)
	{
		std::cout << "?";
		for (int j = 0; j < board_size_x; j++)
			afisare(j, i);
		std::cout << "?" << std::endl;
	}
	for (int i = 0; i < board_size_x + 2; i++)
		std::cout << "?";
	std::cout << std::endl;
}
void init()
{
	setboardSize(MINIM_X_SIZE, MINIM_Y_SIZE);
}
void randomize()
{
	srand(time(NULL));
	for (int i = 0; i < board_size_x; i++)
	{
		for (int j = 0; j < board_size_y; j++)
		{
			currentBoard[j][i] = (rand() > RAND_MAX / 2);
		}
	}
}

void save(std::string path)
{
	// save(0, 0, board_size_x, board_size_y,path);
}
void drawBlock(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int tempx = x + i;
			int tempy = y + j;
			if (tempx >= 0 && tempx < board_size_x && tempy >= 0 && tempy < board_size_y)
			{
				if (i == 0 || i == 3 || j == 0 || j == 3)
				{
					currentBoard[tempy][tempx] = false;
				}
				else
				{
					currentBoard[tempy][tempx] = true;

				}
			}
		}
	}
}
void drawBoat(int x, int y)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int tempx = x + i;
			int tempy = y + j;
			if (tempx >= 0 && tempx < board_size_x && tempy >= 0 && tempy < board_size_y)
			{
				if (i == 0 || i == 4 || j == 0 || j == 4)
				{
					currentBoard[tempy][tempx] = false;
					continue;

				}
				if ((i == 1 && j == 3) || (j == 1 && i == 3) || (j == 3 && i == 3) || (j == 2 && i == 2))
				{
					currentBoard[tempy][tempx] = false;
					continue;
				}
				currentBoard[tempy][tempx] = true;
			}
		}
	}
}
void drawBlinker(int x, int y)
{

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int tempx = x + i;
			int tempy = y + j;
			if (tempx >= 0 && tempx < board_size_x && tempy >= 0 && tempy < board_size_y)
			{
				if (i >= 1 && i <= 3 && j == 2)
				{
					currentBoard[tempy][tempx] = true;
				}
				else
				{
					currentBoard[tempy][tempx] = false;
				}
			}
		}
	}
}
void drawBeacon(int x, int y)
{

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			int tempx = x + i;
			int tempy = y + j;
			if (tempx >= 0 && tempx < board_size_x && tempy >= 0 && tempy < board_size_y)
			{
				if ((i == 1 && (j == 1 || j == 2)) || (i == 2 && j == 1) || (i == 4 && (j == 3 || j == 4)) || (i == 3 && j == 4))


				{
					currentBoard[tempy][tempx] = true;
				}
				else
				{
					currentBoard[tempy][tempx] = false;
				}
			}
		}
	}
}

void drawGlider(int x, int y)
{

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int tempx = x + i;
			int tempy = y + j;
			if (tempx >= 0 && tempx < board_size_x && tempy >= 0 && tempy < board_size_y)
			{
				if (i == 0 || i == 4 || j == 0 || j == 4)
				{
					currentBoard[tempy][tempx] = false;
					continue;
				}
				if ((i == 1 && (j == 1 || j == 3)) || (i == 2 && (j == 1 || j == 2))) {
					currentBoard[tempy][tempx] = false;
					continue;
				}
				currentBoard[tempy][tempx] = true;

			}
		}
	}
}
void drawPulsar(int x, int y)
{
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 17; j++)
		{
			int tempx = x + i;
			int tempy = y + j;
			if (tempx >= 0 && tempx < board_size_x && tempy >= 0 && tempy < board_size_y)
			{
				//drawng the border and empty lines from pozition 4 8 and 12
				if (i == 0 || i == 16 || j == 0 || j == 16 || i == 4 || i == 8 || i == 12 || j == 4 || j == 8 || j == 12)
				{
					currentBoard[tempy][tempx] = false;
					continue;
				}
				//drawing the 3x3 sqare in the corners
				if ((i >= 1 && i <= 3) && (j >= 1 && j <= 3) ||
					(i >= 1 && i <= 3) && (j >= 13 && j <= 15) ||
					(i >= 13 && i <= 15) && (j >= 1 && j <= 3) ||
					(i >= 13 && i <= 15) && (j >= 13 && j <= 15))
				{
					currentBoard[tempy][tempx] = false;
					continue;
				}
				// drawng the rectangle between L shapes
				if ((i >= 6 && i <= 10) && (j == 1 || j == 2 || j == 14 || j == 15) ||
					(j >= 6 && j <= 10) && (i == 1 || i == 2 || i == 14 || i == 15))
				{
					currentBoard[tempy][tempx] = false;
					continue;
				}
				//drawing the litel dreptangle 
				if (((i == 3 || i == 13) && (j == 7 || j == 9)) || ((j == 3 || j == 13) && (i == 7 || i == 9)))
				{
					currentBoard[tempy][tempx] = false;
					continue;
				}
				//drawing the diagonales
				if (i == j || j == 16 - i)
				{
					currentBoard[tempy][tempx] = false;
					continue;
				}
				//fill evriting left whith live cells
				currentBoard[tempy][tempx] = true;

			}

		}
	}
}

void drawPendadecatholon(int x, int y)
{

	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			int tempx = x + i;
			int tempy = y + j;
			if (tempx >= 0 && tempx < board_size_x && tempy >= 0 && tempy < board_size_y)
			{
				if (i < 4 || i>13 || j < 4 || j>6)
				{
					currentBoard[tempy][tempx] = false;
					continue;
				}
				if ((i == 4 || i == 5 || i == 12 || i == 13 || (i > 6 && i < 11)) && (j == 4 || j == 6))
				{
					currentBoard[tempy][tempx] = false;
					continue;
				}
				if ((i == 6 || i == 11) && j == 5)
				{
					currentBoard[tempy][tempx] = false;
					continue;
				}

				currentBoard[tempy][tempx] = true;
			}
		}
	}
}
void drawShape(shapes name, int x, int y)
{
	switch (name)
	{
	case shapes::BLOCK: drawBlock(x, y); break;
	case shapes::BOAT: drawBoat(x, y); break;
	case shapes::BLINKER: drawBlinker(x, y); break;
	case shapes::BEACON: drawBeacon(x, y); break;
	case shapes::GLIDER: drawGlider(x, y); break;
	case shapes::PULSAR: drawPulsar(x, y); break;
	case shapes::PENTADECATHOLON:drawPendadecatholon(x, y); break;
	}
}

