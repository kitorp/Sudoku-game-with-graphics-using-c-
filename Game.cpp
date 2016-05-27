#include "Game.h"


Game::Game()
{
	FileRead fp;
	srand(time(NULL));
	ct = rand() % fp.number_of_games();
	ct %= 10;
	string s = fp.fetch_game(ct);
	int k = 0;
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			int a = s[k++] - '0';
			ara[i][j] = a;
			if (a == 0) vis[i][j] = 1;
			else vis[i][j] = 0;
		}
	}
}


Game::~Game()
{
}
