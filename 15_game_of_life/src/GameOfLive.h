#include<iostream>
#include <Windows.h>
class GameOfLive
{
	bool* prevewBoard=nullptr, * curentBoard=nullptr, * tempBoard=nullptr;
	int curent_x, curent_y;
	WORD life_color = BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY;
	WORD dead_color = 0x0000;
	WORD border_color = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
private:
	int const MIN_X = 20;
	const int MIN_Y = 20;


public:
	void ClearBoard();
	void SetAlive(int x, int y, bool alive);
	GameOfLive();
	GameOfLive(int x, int y);
	void setDimension(int x,int y);
	bool IsAlive(int x,int  y);
	void nextBoard();
	int neibourgs(int x, int y);
	friend std::ostream& operator<<(std::ostream& in, GameOfLive& gol);
private :

};
