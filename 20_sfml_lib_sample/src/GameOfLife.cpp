#include "GameOfLife.h"
#include <time.h>
void GameOfLife::setHeight(int height)
{
	curentBoard->setHeight(height);
}
void GameOfLife::setWidth(int width)
{
	curentBoard->setWidth(width);
}
void GameOfLife::generateNextState()
{
	delete previousBoard;
	previousBoard = curentBoard;
	curentBoard =new Board<status>(previousBoard->getWidth(),previousBoard->getHeight());

	for (int i = 0; i < previousBoard->getWidth(); i++)
	{
		for (int j = 0; j < previousBoard->getHeight(); j++)
		{
			int numberOfNeiburgAlive = getNumberOfNeighbourgsAlive(i, j);
			if (previousBoard->getData(i, j) == status::ALIVE)
			{
				if (numberOfNeiburgAlive == 2 || numberOfNeiburgAlive == 3)
				{
					curentBoard->setData(i, j, status::ALIVE);
				}
				else
					curentBoard->setData(i, j, status::DEAD);
				;
			}
			else
			{
				if (numberOfNeiburgAlive == 3)
				{
					curentBoard->setData(i, j, status::ALIVE);
				}
				else
				{
					curentBoard->setData(i, j, status::DEAD);
				}

			}
		}
	}
	
}
int GameOfLife::getNumberOfNeighbourgsAlive(int x,int y)
{
	int numberOfNeibhourgh = 0,X,Y;
	for (int i = -1; i <= 1; i++)
	{
		X = x + i;
		for (int j = -1; j <= 1; j++)
		{
			Y = j + y;
			if ((i == 0 && j == 0) || X < 0 || Y < 0 || X >= previousBoard->getWidth() || Y >= previousBoard->getHeight())
			{
				continue;
			}
			else if (previousBoard->getData(X, Y) == status::ALIVE)
			{
				numberOfNeibhourgh++;
			}
		
		}
	}
	return numberOfNeibhourgh;
};

void GameOfLife::setCellAliveOrDeath(int x, int y, status stare)
{
	curentBoard->setData(x, y, stare);
}

GameOfLife::status GameOfLife::getCell(int x, int y)
{
	return curentBoard->getData(x, y);
}
void GameOfLife::clearBoard()
{
	curentBoard->clear();
}
void GameOfLife::randomizeBoard()
{

	srand(time(NULL));
	for (int i = 0; i < curentBoard->getWidth(); i++)
	{
		for (int j = 0; j < curentBoard->getHeight(); j++)
		{
			if (rand() > RAND_MAX / 2)
			{
				curentBoard->setData(i, j, status::ALIVE);
			}
			else
			{
				curentBoard->setData(i, j, status::DEAD);
			}
		}
	}
}
