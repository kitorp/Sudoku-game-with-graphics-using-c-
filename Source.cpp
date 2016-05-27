#include "iGraphics.h"
#include "Display.h"
#include<string>
#include "Game.h"
#include<iostream>
#include "Solve.h"
#include<math.h>
#include"timerr.h"
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
using namespace std;
int pic_x, pic_y;
int puzzlex = 60, puzzley = 390, xchange = 42, ychange = 42;
int menu=1,m_row=1,curcol=1;
int textx=370, texty=433;
int raja = 300, rani = 300;
int text_stats_x = raja, text_stats_y = rani, text_stats_ychange = 50;
int iniptx = puzzlex, inipty = 382;
int ptx = iniptx, pty = inipty, dx = 32, dy = 6;
bool yesread = true;
Display temp;
Game newgame;
bool flag = 0, music_on = 1,solve_one=false;
timerr ttime;
FileRead st;
//menu 1=home menu, menu 2= newgame, menu 3 = winner , menu 6 option;


void sound_check(){
	
	if (menu == 6 && m_row == 2 && music_on){
		music_on = 0;
		PlaySound(0, 0, 0);
	}
	if (menu == 6 && m_row == 1 && !music_on){
		music_on = 1;
		string hashem;
		char toufiq[20];
		hashem = st.fetch_music();
		for (int i = 0; i < hashem.size(); i++){
			toufiq[i] = hashem[i];
		}
		toufiq[hashem.size()] = '\0';
		PlaySound(toufiq, NULL, SND_LOOP | SND_ASYNC);
	}

}
void increment_time(){

	ttime.add_one_second();
}
void drawfunc()
{
	if(solve_one)iShowBMP(pic_x, pic_y, "Board_Images\\board.bmp");
	else iShowBMP(pic_x, pic_y, "Board_Images\\solvebg.bmp");
	int num;
	bool v;

	int valx = puzzlex, valy = puzzley;


	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			num = newgame.read(i, j);
			v = newgame.check_vis(i, j);

			string s = temp.get_number(num, v);
			int len = s.size();
			char ara[100];
			for (int i = 0; i < len; i++) ara[i] = s[i];
			ara[len] = '\0';
			iShowBMP(valx, valy, ara);
			valx += xchange;
			if ((j + 1) % 3 == 0 && j > 0) valx += 10;
		}
		valx = puzzlex;
		valy -= ychange;
		if ((i + 1) % 3 == 0 && i>0) valy -= 10;
	}
}

void iDraw()
{
	

	iClear();
	glutReshapeWindow(512, 512);
	if (menu == 2 || menu==4){
		drawfunc();
		if (solve_one){
			string s;
			s=ttime.get_time();
			char time_string[20];
			int j = 0;
			for (int i = s.size() - 1; i >= 0; i--){
				time_string[j++] = s[i];
			}
			time_string[j] = '\0';
			glDisable(GL_LIGHTING);
			glColor3f(1.0f, 1.0f, 1.0f);
			iText(textx, texty, time_string, GLUT_BITMAP_HELVETICA_18);
		}
		
		iSetColor(100, 140, 50);
		iFilledRectangle(ptx, pty, dx, dy);
		
	}
	else if (menu == 5){
		Solve sudoku(newgame);
		drawfunc();
	}
	else if (menu == 10){
		string s = temp.get_val(menu, m_row);
		int len = s.size();
		char ara[100];
		for (int i = 0; i < len; i++) ara[i] = s[i];
		ara[len] = '\0';
		iShowBMP(pic_x, pic_y, ara);
		text_stats_x = raja, text_stats_y = rani;
		
		for (int i = 1; i <= 5; i++){
			string s= st.sorted_abc(i);
			if (s.size()==0) continue;
			char time_string[20];
			int j = 0;
			for (int i = s.size() - 1; i >= 0; i--){
				time_string[j++] = s[i];
			}
			time_string[j] = '\0';
			glDisable(GL_LIGHTING);
			glColor3f(1.0f, 1.0f, 1.0f);
			iText(text_stats_x, text_stats_y, time_string, GLUT_BITMAP_HELVETICA_18);
			text_stats_y -= text_stats_ychange;
			
		}
	}
	else if (menu == 12){
		Sleep(3000);
		exit(0);
	}
	else{
		string s = temp.get_val(menu, m_row);
		int len = s.size();
		char ara[100];
		for (int i = 0; i < len; i++) ara[i] = s[i];
		ara[len] = '\0';
		iShowBMP(pic_x, pic_y, ara); 
	}
	if (menu == 11){
		menu = 12;
	}

}

void iMouseMove(int mx, int my)
{

}
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	
	}
}

void iKeyboard(unsigned char key)
{
	int gg = key;
	cout << "press ikey: " << gg << endl;
	if (key == 'x' || key == 'X')
	{
		menu = 11;
	}
	else if (key == 'n' || key == 'N'){
		PlaySound(0, 0, 0);
		st.music_next();
		string hashem;
		char toufiq[20];
		hashem = st.fetch_music();
		for (int i = 0; i < hashem.size(); i++){
			toufiq[i] = hashem[i];
		}
		toufiq[hashem.size()] = '\0';
		PlaySound(toufiq, NULL, SND_LOOP | SND_ASYNC);

	}
	else if (key == 8){
		menu=temp.back(menu);
		m_row = 1;
		newgame.randomize();
	}
	else if (key == 13 && menu!=2){
		cout << "From: " << menu << endl;
		temp.enter(menu, m_row,curcol);
		
		if (menu == 2){
			flag = 0, ptx = iniptx, pty = inipty;
			ttime.timer_reset();
			solve_one = true;
		}
		if (menu == -1) exit(0);
		if (menu == 4){
			newgame.solve_time();
			flag = 1;
			solve_one = false;
			ptx = iniptx, pty = inipty;
			menu = 2,m_row=0,curcol=0;
		}
		cout << "To: " << menu << endl;
		cout << " mrow : " << m_row << endl;
		if (menu == 10) st.stats_read();
		

	}
	else if (key == 13 && menu == 2 && flag){
		menu = 5;
	}
	if (menu == 2){
		if (key >= '0' && key <= '9') newgame.write(m_row, curcol, key-'0');
		if (newgame.winner_check()){
			menu = 3;
			int a, b, c;
			ttime.get_abc(a,b,c);
			st.stats_write(a, b, c);


		}
		
	}

}

void iSpecialKeyboard(unsigned char key)
{


	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	if (key == GLUT_KEY_LEFT)
	{
		if (menu == 2 ){
			if (curcol % 3 == 0) ptx -= 10;
			ptx -= xchange;
			ptx = max(iniptx, ptx);
			curcol--;
			curcol = temp.get_corection(menu, curcol);
		}
	}
	if (key == GLUT_KEY_RIGHT)
	{
	
		if (menu == 2){
			ptx += xchange ,curcol++;
			if (curcol % 3 == 0) ptx += 10;
			ptx = min(ptx, iniptx + 8 * xchange + 20);
			curcol = temp.get_corection(menu,curcol);
		}
	}
	if (key == GLUT_KEY_UP)
	{
		m_row--;
		m_row = temp.get_corection(menu, m_row);
		if (menu == 2){
			pty += ychange;
			if ((m_row + 1) % 3 == 0) pty += 10;
			pty = min(pty, inipty);
		}
	}
	if (key == GLUT_KEY_DOWN)
	{
		m_row++;
		m_row = temp.get_corection(menu, m_row);
		if (menu == 2){
			pty -= ychange;
			if (m_row % 3 == 0) pty -= 10;
			pty = max(pty, inipty - 8 * ychange-20);
		}
	}
	sound_check();
}

int main()
{
	pic_x = 0;
	pic_y = 0;
	iSetTimer(100, iDraw);
	iSetTimer(1000, increment_time);
	string hashem;
	char toufiq[20];
	hashem = st.fetch_music();
	for (int i = 0; i < hashem.size(); i++){
		toufiq[i] = hashem[i];
	}
	toufiq[hashem.size()] = '\0';
	PlaySound(toufiq, NULL, SND_LOOP | SND_ASYNC);
	iInitialize(512, 512, "PUZZLE 81");
	return 0;
}