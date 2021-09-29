#pragma once
#include <iostream>
template <typename T>
class Board
{
	T* data = nullptr;
public:
	static const int MIN_WIDTH = 20;
	static const int MIN_HEIGHT = 20;
private:
	int width, height;
	
public:
	//int getNeighbours(int x, int y);
	void setWidth(int x);
	void setHeight(int y);
	int getWidth();
	int getHeight();
	T getData(int x, int y);
	void setData(int x, int y,T data);
	void clear();
	Board();
	Board(int x, int y);
	//Board(Board & board);
	//Board nextBoadr();
	~Board();
	
};
template <typename t>
Board<t>::Board()
{
	data = new t[MIN_WIDTH * MIN_HEIGHT];
	width = MIN_WIDTH;
	height = MIN_HEIGHT;
	clear();
}
template <typename T> void Board<T>::setWidth(int value)
{

	if (value < MIN_WIDTH)
	{
		std::cout << value << " is less then " << MIN_WIDTH << " !" << std::endl;
		width = MIN_WIDTH;
	}
	else
	{
		width = value;
	}
	delete[] data;
	
	data = new T[width * height];
	clear();
}
template < typename T>void Board<T>::setHeight(int value)
{

	if (value < MIN_HEIGHT)
	{
		std::cout << value << " is less then " << MIN_HEIGHT << " !" << std::endl;
		height = MIN_HEIGHT;
	}
	else
	{
		height = value;
	}
	delete[] data;
	data = new T[width * height];
	clear();
}
template < typename T>void Board<T>::clear()
{
	for (int index = 0; index < width * height; index++)
	{
		data[index] =  T();
	}
}

template<typename T> Board<T>::Board(int width, int height)
{
	this->width = width;
	this->height = height;
	data = new T[width * height];
	clear();
}
/*
Board Board::nextBoadr()
{
	Board next =  Board(*this);
	int neighbours = 0;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			neighbours = getNeighbours(i, j);

			if (data[j * width + i])
			{
				if (neighbours == 2 || neighbours == 3)
				{
					next.setAlive(i, j, true);
				}
				else
				{
					next.setAlive(i, j, false);
				}

			}
			if (!data[j * width + i])
			{
				if (neighbours == 3)
				{
					next.setAlive(i, j, true);
				}
				else
				{
					next.setAlive(i, j, false);
				}
			}
		}
	}
	return next;
}

template < class T>
int Board<T>::getNeighbours(int x, int y)
{
	int X, Y, neighbors = 0;;
	for (int i = -1; i <= 1; i++)
	{
		X = x + i;
		for (int j = -1; j <= 1; j++)
		{
			Y = y + j;
			if (X < 0 || Y < 0 || X >= width || Y >= height)
			{
				continue;
			}
			if (x == 0 && y == 0)
			{
				continue;
			}
			neighbors += data[Y * width + X];
		}
	}
	return neighbors;
}
*/
template < typename T>int Board<T>::getHeight()
{
	return height;
};
template < typename T>
int Board<T>::getWidth()
{
	return width;
};
template < typename T>
void Board<T>::setData(int x, int y, T value)
{
	if (x < 0 || y < 0 || x >= width || y >= height)
	{
		std::cout << x << " or " << y << "out of range !" << std::endl;
	}
	data[y * width + x] = value;
}
template < typename T>
T Board<T>::getData(int x, int y)
{
	if (x < 0 || y < 0 || x >= width || y >= height)
	{
		return T();
	}
	return data[y * width + x];
}
template < typename T>
Board<T> :: ~Board()
{
	delete[] data;
}

