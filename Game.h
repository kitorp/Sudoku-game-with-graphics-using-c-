#pragma once
#include<iostream> 
#include<string>
#include "FileRead.h"
#include <time.h>
using namespace std;

class Game
{
	int ara[9][9];
	bool vis[9][9];
	int num_games = 0;
	int ct;
public:
	Game();
	bool check(int i, int j, int val){
		bool flag = 1;
		if (val < 1 || val>9) flag = 0;
		for (int a = 0; a < 9; a++){
			if (ara[i][a] == val) flag = 0;
		}
		for (int a = 0; a < 9; a++){
			if (ara[a][j] == val) flag = 0;
		}
		int a = i / 3, b = j / 3;
		a *= 3;
		b *= 3;
		for (int ii = a; ii < a + 3; ii++){
			for (int jj = b; jj < b + 3; jj++){
				if (ara[ii][jj] == val) flag = 0;
			}
		}
		if (vis[i][j] == 0) flag = 0;
		return flag;
	}
	bool write(int i, int j, int val){
		if (val == 0  && vis[i][j] == 1){
			ara[i][j] = 0;
			return true;
		}
		if (check(i, j, val) == 1){
			ara[i][j] = val;
			return true;
		}
		else return false;
	}
	int read(int i, int j){
		return ara[i][j];
	}
	bool check_vis(int i, int j){
		return vis[i][j];
	}
	bool winner_check(){
		bool flag = 1;
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				if (ara[i][j] == 0){
					flag = 0;
					i = 10;
					j = 10;
				}
			}
		}
		return flag;
	}
	void solve_time(){
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				vis[i][j] = 1;
				ara[i][j] = 0;
			}
		}
	}
	void randomize(){
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
	~Game();
};

