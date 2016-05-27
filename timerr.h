#pragma once
#include<string>
#include<iostream> 
using namespace std;
class timerr
{
	int m, s, h;
public:
	timerr();
	void timer_reset(){
		m = 0, s = 0, h = 0;
	}
	void add_one_second(){
		s += 1;
		if (s >= 60){
			s %= 60;
			m++;
		}
		if (m >= 60){
			m %= 60;
			h++;
		}
		if (h >= 24) h = 0;
	}
	void get_abc(int &a,int &b,int &c){
		a = h;
		b = m;
		c = s;
	}
	string get_time(){
		string ss;
		int i;
		int s1 = h, s2 = m, s3 = s;
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
		h = s1, m = s2, s = s3;
		return ss;
	}
	~timerr();
};

