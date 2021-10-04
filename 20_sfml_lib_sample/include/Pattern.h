#pragma once
#include <iostream>
#include "Board.h"

class Pattern
{
public:
	

	std::string name= "";
	virtual bool isAlive(int x, int y) = 0;
	virtual int getWidth() =0;
	virtual int getHeight()=0;

};