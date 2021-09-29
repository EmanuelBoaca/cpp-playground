#pragma once
#include "Board.h"

#include <list>
class GameOfLife
{
public:
	enum class  status:char {
		DEAD = 0,
		ALIVE=1
	};
public:
	enum class shapes {
		BLOCK,
		BOAT,
		BLINKER,
		BEACON,
		PULSAR,
		PENTADECATHOLON,
		GLIDER
	};
	enum class orientation :char {
		DEFAULT = 1,
		LANDSCAPE = 1,
		PORTRAIT,
		LANDSCAPE_REVERSE,
		PORTRATI_REVERSE
	};
	//std::list<Pattern>Patterns;
private:
	Board<status> *previousBoard=new Board<status>(), *curentBoard= new Board<status>();
	int getNumberOfNeighbourgsAlive(int x,int y);
public:
	void setWidth(int width);
	void setHeight(int height);
	void generateNextState();
	void setCellAliveOrDeath(int x, int y, status status =status::DEAD);
	//void drawPattern(int x, int y,Patternp orientation orientation = orientation::DEFAULT)
	status getCell(int x, int y);
	void clearBoard();
	void randomizeBoard();
	
};

