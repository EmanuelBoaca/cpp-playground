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
bool isAlive(int x, int y);
void drawShape(shapes s, int x, int y);
void init();
void setboardSize(int x_size, int y_size);
void afisare();
void nextBoard();
void drawPixel(int x, int y, bool alife);