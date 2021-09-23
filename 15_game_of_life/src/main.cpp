#include <iostream>
#include<vector>
#include <time.h>


#define MINIM_X_SIZE 20
#define MINIM_Y_SIZE 20

int board_size_x = MINIM_X_SIZE;
int board_size_y = MINIM_Y_SIZE;
std::vector<std::vector<bool>> curentboard;
std::vector<std::vector<bool>> prevewsboard;

 void setboardSize(int x_size, int y_size)
{
	
	 if(x_size<MINIM_X_SIZE||y_size<MINIM_Y_SIZE)
	 {
		 std::cout << "The size of dimension must bee bigger than "<<MINIM_X_SIZE<<" !"<<std::endl;
		 std::cout << "The X and Y size are set to default : " << MINIM_X_SIZE << std::endl;
		 board_size_x = MINIM_X_SIZE;
		 board_size_y = MINIM_Y_SIZE;
		 
	 }
	 else 
	 {
		 board_size_x = x_size;
		 board_size_y = y_size;
	 }
	 for each (std::vector<bool> x in curentboard)
	 {
		 x.clear();
	 }
	 curentboard.clear();
	 for (int indexY = 0; indexY < board_size_y; indexY++)
	 {
		 std::vector<bool>newRow;
		 for (int indexX = 0; indexX < board_size_x; indexX++)
		 {
			 newRow.push_back(false);
		 }
		 curentboard.push_back(newRow);
	 }
	 

}
 void copyBoard()
 {
	
		 for each (std::vector<bool> var in prevewsboard)
		 {
			 var.clear();
		 }
		 prevewsboard.clear();
		 for each (std::vector<bool> var in curentboard)
		 {
			 prevewsboard.push_back(var);
		 }
	 
 }

 bool isAlive(int x, int y)
 {
	 if (x < 0 || y < 0 || x >= board_size_x || y >= board_size_y)
	 {
		 return false;
	 }
	 return curentboard[y][x];
 }
 
 void nextBoard()
 {
	 copyBoard();
	 for (int y = 0; y < board_size_y; y++)
	 {
		 for (int x = 0; x < board_size_x; x++)
		 {
			 int neighborh = 0;
			 for (int i = -1; i < 1; i++)
			 {
				 int neiby = y + i;
				 for (int j = -1; j < 1; j++)
				 {
					 int neibx = x + j;
					 if (neiby < 0 || neibx < 0 || neibx >= board_size_x || neiby >= board_size_y)
					 {
						 continue;
					 }
					 if (i == j == 0)
					 {
						 continue;
					 }
					 if (prevewsboard[neiby][neibx])
					 {
						 neighborh++;
					 }

				 }
			 }
			
			 if (curentboard[y][x])
			 {
				 if (neighborh == 2 || neighborh == 3)
				 {
					 curentboard[y][x] = true;
				 }
				 else
				 {
					 curentboard[y][x] = false;
				 }
			 }
			 else
			 {
				 if (neighborh == 3)
					 curentboard[y][x] = true;
			 }
		 }
	 }
 }
 void afisare(int x, int y)
 {
	 if (isAlive(x, y))
	 {
		 std::cout<<"@";
	 }
	 else
	 {
		 std::cout << " ";
	 }
 }
 void afisare()
 {
	 
	 for (int i = 0; i < board_size_y; i++)
	 {
		 for (int j = 0; j < board_size_x; j++)
			 afisare(j, i);
		 std::cout << std::endl;
	 }
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
			 curentboard[j][i] = (rand() > RAND_MAX/2);
		 }
	 }
 }

int main()
{
	init();
	randomize();
	for (int i = 0; i < 100; i++)
	{
		
		afisare();
		std::cout << std::endl;
		nextBoard();
	}
}
