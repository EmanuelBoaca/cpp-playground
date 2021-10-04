#include "GameOfLive.h"

GameOfLive::GameOfLive(int x, int y) {

}

void GameOfLive::setDimension(int x, int y)
{
	
	if (x < MIN_X)
	{
		curent_x = MIN_X;
		std::cout << x << " is less then "<<MIN_X;
	}
	else {
		curent_x = x;
	}
	if(y < MIN_Y)
	{
		curent_y = MIN_Y;
		std::cout << y << " is less then " << MIN_Y;
	}
	else {
		curent_y = y;
	}
	delete[] prevewBoard;
	delete[] curentBoard;
	prevewBoard = new bool[x * y];
	curentBoard = new bool[x * y];
	

}
void GameOfLive::ClearBoard()
{
	for (int i = 0; i < curent_x * curent_y; i++)
		curentBoard[i] = false;
};
void GameOfLive::SetAlive(int x, int y, bool alive)
{
	curentBoard[y * curent_x + x] = alive;
}
bool GameOfLive::IsAlive(int x, int y)
{
	if (x < 0 || y < 0 || x >= curent_x || y >= curent_y)
	{
		return false;
	}
	return curentBoard[y * curent_x + x];
}

void GameOfLive::nextBoard()
{
	tempBoard = curentBoard;
	curentBoard = prevewBoard;
	prevewBoard = tempBoard;
	int neibourg = 0;
	for (int i = 0; i < curent_x; i++)
	{
		for (int j = 0; j < curent_y; j++)
		{
			neibourg = neibourgs(i, j);
			if (prevewBoard[j * curent_x + i])
			{
				if (neibourg == 2 || neibourg == 3)
				{
					curentBoard[j * curent_x + i] = true;
				}
				else
				{
					curentBoard[j * curent_x + i] = false;
				}
			}
			else
			{
				if (neibourg == 3)
				{
					curentBoard[j * curent_x + i] = true;
				}
				else
				{
					curentBoard[j * curent_x + i] = false;
				}
			}
		}
	}
	
}
int GameOfLive::neibourgs(int x, int y)
{
	int X, Y, neiburgs = 0;;
	for (int i = -1; i <= 1; i++)
	{
		X = x + i;
		for (int j = -1; j <= 1; j++)
		{
			Y = y + j;
			if (X < 0||Y<0||X>=curent_x||Y>=curent_y)
			{
				continue;
			}
			if (i == 0 || j == 0)
			{
				continue;
			}
			neiburgs += prevewBoard[y * curent_x + x];
		}

	}
	return neiburgs;
}
GameOfLive::GameOfLive()
{
	setDimension(MIN_X, MIN_Y);
}
std::ostream& operator<<(std::ostream& in, GameOfLive& gol)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < gol.curent_x; i++)
	{
		SetConsoleTextAttribute(consoleHandle, gol.border_color);
		std::cout << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < gol.curent_x; i++)
	{
		SetConsoleTextAttribute(consoleHandle, gol.border_color);
		std::cout << " ";

		for (int j = 0; j < gol.curent_y; j++)
		{
			if (gol.IsAlive(i, j))
			{
				SetConsoleTextAttribute(consoleHandle, gol.life_color);
				std::cout << " ";
			}
			else
			{
				SetConsoleTextAttribute(consoleHandle, gol.dead_color);
				std::cout << " ";
			}
		}
		SetConsoleTextAttribute(consoleHandle, gol.border_color);
		std::cout << " ";
		std::cout << std::endl;
	}
	for (int i = 0; i < gol.curent_x; i++)
	{
		SetConsoleTextAttribute(consoleHandle, gol.border_color);
		std::cout << " ";
	}
	std::cout << std::endl;

	SetConsoleTextAttribute(consoleHandle,FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_GREEN);
		std::cout << std::endl;
	return in;
}