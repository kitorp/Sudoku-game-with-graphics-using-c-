#include "Solve.h"


Solve::Solve()
{

}
Solve::Solve(Game &newgame)
{
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			grid[i][j] = newgame.read(i, j);
		}
	}
	if (SolveSudoku()){
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				newgame.write(i, j, grid[i][j]);
			}
		}
	}
}


Solve::~Solve()
{
}