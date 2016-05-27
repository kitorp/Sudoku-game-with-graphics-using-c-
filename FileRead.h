#pragma once
#include <iostream> 
#include <fstream>
#include<string>
#include<algorithm>
#include<vector>

struct letssee{
	int a, b, c;
	bool operator<(letssee other) const
	{
		if (a == other.a){
			if (b == other.b){
				if (c == other.c) return 0;
				return c<other.c;
			}
			return b < other.b;
		}
		return a < other.a;
	}

};
using namespace std;
class FileRead
{
	vector<letssee> mv;
	int present_music = 0;
	vector<string> DJ;
public:
	FileRead();
	string fetch_music(){
		return DJ[present_music];
	}
	void music_next(){
		present_music++;
		present_music %= (int)DJ.size();
	}
	int number_of_games(){
		ifstream f1;
		int n;
		f1.open("allpuzzles.txt");
		f1 >> n;
		f1.close();
		return n;
	}

	string fetch_game(int ct){
		ifstream f1;
		f1.open("allpuzzles.txt");
		int num_games;
		f1 >> num_games;
		string s;
		for (int k = 0; k < num_games; k++){
			for (int i = 0; i < 9; i++){
				for (int j = 0; j < 9; j++){
					int a;
					f1 >> a;
					if (k == ct){
						char ch = a + '0';
						s += ch;
					}
				}
			}
		}
		f1.close();
		return s;
	}
	string fetch_number(int num, int type){
		ifstream f1;
		f1.open("numbers_map.txt");
		for (int i = 0; i < 2; i++){
			for (int j = 0; j <= 9; j++){
				string s;
				f1 >> s;
				if (i == type && j == num) return s;
			}
		}
		f1.close();
		return "\0";
	}
	string sorted_abc(int i){
		string ss;
		if (i > (int)mv.size()) return ss;
		else{
			int h = mv[i - 1].a;
			int m = mv[i - 1].b;
			int s = mv[i - 1].c;
			int i;
			for (int j = 0; j < 2; j++){
				i = s % 10;
				ss += (i + '0');
				s /= 10;
			}
			ss += ":";
			for (int j = 0; j < 2; j++){
				i = m % 10;
				ss += (i + '0');
				m /= 10;
			}
			ss += ":";
			for (int j = 0; j < 2; j++){
				i = h % 10;
				ss += (i + '0');
				h /= 10;
			}
			return ss;

		}
	}
	void stats_read(){
		mv.clear();
		ifstream f1;
		f1.open("stats.txt");
		letssee tmp;
		while (f1 >> tmp.a){

			f1 >> tmp.b;
			f1 >> tmp.c;
			mv.push_back(tmp);
			cout << tmp.a << "  " << tmp.b << "  " << tmp.c << endl;
		}
		sort(mv.begin(), mv.end());
	}
	void stats_write(int a,int b,int c){
		cout << "Calling write" << endl;
		ofstream outfile;
		outfile.open("stats.txt", std::ios_base::app);
		outfile <<a<<" "<<b<<" "<<c << "\n";
	}
	~FileRead();
};

