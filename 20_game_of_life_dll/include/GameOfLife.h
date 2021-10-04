#pragma once
#include"build_options_gol_dll.h"
#include "Board.h"

#include <list>

	class GOLS_IMPEXP GameOfLife
	{
	public:
		enum class  status :char {
			DEAD = 0,
			ALIVE = 1
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
		Board<status>* previousBoard = new Board<status>(), * curentBoard = new Board<status>();
		int getNumberOfNeighbourgsAlive(int x, int y);
	private:
		void drawBlok(int x, int y, orientation orient);
		void drawBoat(int x, int y, orientation orient);
		/*
	//	void drawBlinker(int x, int y, orientation orient);
		void drawBeakon(int x, int y, orientation orient);
		void drawPulsar(int x, int y, orientation orient);
		void drawPentadecatholon(int x, int y, orientation orient);
		void drawGlider(int x, int y, orientation orient);
		*/
	public:
		GameOfLife();
		void setWidth(int width);
		void setHeight(int height);
		void generateNextState();
		void setCellAliveOrDeath(int x, int y, status status = status::DEAD);
		void drawPattern(int x, int y, shapes shape, orientation orientation = orientation::DEFAULT);
		status getCell(int x, int y);
		void clearBoard();
		void randomizeBoard();

	};

extern "C" {
	GameOfLife;
}