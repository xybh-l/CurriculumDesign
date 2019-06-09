#include"others.h"
#include "Global.h"
#include<iostream>
#include<fstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;

int TeacherNumber, StudentNumber;
Student S[100];
void gotoxy(int, int); void gotoxy(int x, int y)
{
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	HANDLE hConsoleOut;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	csbiInfo.dwCursorPosition.X = x;
	csbiInfo.dwCursorPosition.Y = y;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}

void draw()
{
	static int i = 0;
	char x = 20, y = 3;
	gotoxy(x, y); 
	cout << "***********************************************************"<<endl;
	for (i=1; i < 30; i++)
	{
		gotoxy(x, y+i);
		cout << "*                                                         *"<<endl;
	}
	gotoxy(x, y+i);
	cout << "***********************************************************"<<endl;
}

void WriteStudentInfo()
{
	const char * filename = "StudentInfo.txt";
	ofstream out(filename, ios::out);
	for (int i = 0; i < StudentNumber; i++)
	{
		out << S[i].id << ends << S[i].name << ends << S[i].classid << ends << S[i].chinese << ends << S[i].math << ends << S[i].english << ends << S[i].sum << ends <<S[i].aver << endl;
	}
	out.close();
}

