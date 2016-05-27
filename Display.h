#pragma once
#include<string>
#include<iostream>
#include "FileRead.h"
using namespace std;
class Display
{
	string hmenu = "Board_Images\\Home.bmp";
	string hmenu1 = "Board_Images\\menu1.bmp";
	string hmenu2 = "Board_Images\\menu2.bmp";
	string hmenu3 = "Board_Images\\menu3.bmp";
	string hmenu4 = "Board_Images\\menu4.bmp";
	string hmenu5 = "Board_Images\\menu5.bmp";
	string credit = "Board_Images\\credits.bmp";
	string winner_menu = "Board_Images\\winner.bmp";
	string option1 = "Board_Images\\option1.bmp";
	string option2 = "Board_Images\\option2.bmp";
	string def_num[10], input_num[10];
	string stat_menu = "Board_Images\\stats.bmp";
	int sound_menu = 1;



public:
	Display();
	string get_val(int m, int row){
		if (m == 1){
			if (row == 1) return hmenu;
			if (row == 2) return hmenu1;
			if (row == 3) return hmenu2;
			if (row == 4) return hmenu3;
			if (row == 5) return hmenu4;
			if (row == 6) return hmenu5;
		}
		else if (m == 3) return winner_menu;
		else if (m == 6){
			if (row == 1) return option1;
			else return option2;
		}
		else if (m == 11) return credit;
		else if (m == 10){
			return stat_menu;
		}
	}
	string get_number(int num, bool vis){
		if (vis == 0) return def_num[num];
		else return input_num[num];

	}
	int get_corection(int m, int row){
		if (m == 1){
			if (row < 2) return 2;
			if (row > 6) return 6;
			else return row;
		}
		else if (m == 2){
			if (row < 0) return 0;
			else if (row > 8) return 8;
			else return row;
		}
		else if (m == 6){
			if (row > 2) row = 1;
			if (row < 1) row = 2;
			sound_menu = 2;
			return row;
		}
		return row;
	}
	int back(int m){
		if (m == 2) return 1;
		else if (m == 3) return 1;
		else if (m == 1) return 1;
		else if (m == 6) return 1;
		else if (m == 5) return 1;
		return 1;

	}
	void enter(int &m, int &row,int &col){
		if (m == 1){
			if (row == 2){
				row = 0;
				col = 0;
				m = 2;
				return;
			}
			if (row == 3) m=4;
			if (row == 4) m=10;
			if (row == 5) m= 6;
			if (row == 6) m=11;
		}
		else if (m == 4){
			row = 0;
			col = 0;
			m = 5;
			return;
		}
		else m = 1;
		if (m == 6){
			row = sound_menu;
			col = 1;
			return;
		}
		row = 1;
		col = 1;
	}
	~Display();
};

