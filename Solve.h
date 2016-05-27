#pragma once
#include "Game.h"
#include <iostream>
using namespace std;
class Solve
{
	int grid[9][9];
	int N = 9;
public:
	Solve();
	Solve(Game &newgame);
	bool FindUnsignedLocation(int &row, int &col){
		for (row = 0; row < N; row++){
			for (col = 0; col < N; col++){
				if (grid[row][col] == 0) return 1;
			}
		}
		return 0;
	}

	bool UsedInRow(int row, int num)
	{
		for (int col = 0; col < N; col++){
			if (grid[row][col] == num) return true;
		}
		return false;
	}


	bool UsedInCol(int col, int num)
	{
		for (int row = 0; row < N; row++){
			if (grid[row][col] == num) return true;
		}

		return false;
	}

	bool UsedInBox(int boxStartRow, int boxStartCol, int num)
	{
		for (int row = 0; row < 3; row++){
			for (int col = 0; col < 3; col++){
				if (grid[row + boxStartRow][col + boxStartCol] == num) return true;
			}

		}
		return false;
	}
	bool isSafe(int row, int col, int num)
	{
		bool a = !UsedInRow(row, num) && !UsedInCol(col, num);
		bool b = !UsedInBox(row - row % 3, col - col % 3, num);
		return a && b;

	}

	bool SolveSudoku(){
		int row, col;
		if (FindUnsignedLocation(row, col) == 0) return 1;
		for (int num = 1; num <= 9; num++){
			if (isSafe(row, col, num)){
				grid[row][col] = num;
				if (SolveSudoku()) return 1;
				grid[row][col] = 0;
			}
		}
		return 0;
	}
	~Solve();
};

