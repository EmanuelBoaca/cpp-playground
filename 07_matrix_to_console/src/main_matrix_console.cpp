#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
/**
	Define a simple matrix.
*/
class Matrix
{
private:
	size_t column_count=0;
	size_t line_count=0;

	// TODO: store the data
	// hints: you can use std::string, std::vectors + string, char**, vector<vector<char>>, etc
	std::vector<std::vector<char>> content;
public:
	Matrix(size_t numColumnsX, size_t numLinesY)
		// TODO: add functionality
	{
		if (numColumnsX <= 0 || numLinesY <= 0)
		{
			column_count = line_count = 0;
			return;
		}

		column_count = numColumnsX;
		line_count = numLinesY;
		
		content.clear();
		for (size_t indexY = 0; indexY < numLinesY; indexY++)
		{
			std::vector<char> row;
			for (size_t indexX = 0; indexX < numColumnsX; indexX++)
				row.push_back(' ');
			content.push_back(row);
		}
	}

	// Set an entire line
	void setLine(size_t line_number, const std::string& data)
	{
		if (line_number < 0 || line_number >= line_count)
		{
			std::cout << "Line number out of range. Allowed values ar between 0 and " << line_count - 1 << std::endl; 
			return;
		}
		size_t size = std::min(data.length(), column_count);
		for (size_t indexX = 0; indexX < size; indexX++)
		{
			content[line_number][indexX] = data[indexX];
		}

	}

	//OPTIONAL
	//char getCellXY(size_t x, size_t y, char cell_content)
	//{
	//	// TODO: add functionality
	//	return 0;
	//}

	/**
		Sets the cell content for a specific cell identified by its coordinates (X and Y)
		@param x The horizontal coordinate of the cell to set. Index starts at zer0.
		@param y The vertical coordinate of the cell to set. Index starts at zer0.
		@param cell_content A cell char to set.

		E.g.
		 X axis: 0 -------- ... -------> Width
		 Y axis
		 0       0,0  1,0                W-1, 0
		 |       0,1  1,1                     
		 |       0,2                      
		 .                             
		 .                             
		 .                             
		 |       0, H-1     ...          W-1, H-1           
		 V

		 Height
	*/
	void setCellXY(size_t x, size_t y, char cell_content)
	{
		if (x < 0 || y<0 || x>column_count||y>line_count)
		{
			std::cout << "Selected cell out of range! "<<std::endl;
			return;
		}
		
		content[y][x] = cell_content;
	}

	void print()
	{
		// print all lines and columns
		
		for (size_t y = 0; y < line_count; y++)
		{
			for (size_t x = 0; x < column_count; x++)
			{
				std::cout << content[y][x];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
};

int main()
{
	// Create a matrix with the width of 20 and height of 10.
	Matrix matrix(20, 10);

	matrix.setLine(0, "X-----X----X-----XX-");
	matrix.setLine(1, "--X-----------------");
	matrix.setLine(2, "-----X--------------");
	matrix.setLine(3, "--------X-----------");
	matrix.setLine(4, "-----------X--------");
	matrix.setLine(5, "--------------X-----");
	matrix.setLine(6, "-----------------X--");
	matrix.setLine(7, "-------------------X");
	matrix.setLine(8, "------------------X-");
	matrix.setLine(9, "-----------------X--");

	matrix.print();
	// Would print
/*
X-----X----X-----XX-
--X-----------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
-------------------X
------------------X-
-----------------X--
*/
	matrix.setCellXY(2, 1, '-');
	matrix.print();
	// Would print
/*
X-----X----X-----XX-
--------------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
-------------------X
------------------X-
-----------------X--
*/

	matrix.setCellXY(3, 7, 'O');
	matrix.print();
/*
X-----X----X-----XX-
--------------------
-----X--------------
--------X-----------
-----------X--------
--------------X-----
-----------------X--
---O---------------X
------------------X-
-----------------X--
*/

	// This should silently fail (not trigger an error): cell Y=11 invalid due to limited height.
	matrix.setCellXY(3, 11, 'O');
	return 0;
}