#pragma once

enum class shapes {
	BLOCK,
	BOAT,
	BLINKER,
	BEACON,
	PULSAR,
	PENTADECATHOLON,
	GLIDER
};

void drawShape(shapes s, int x, int y);
void init();
void afisare();
void nextBoard();