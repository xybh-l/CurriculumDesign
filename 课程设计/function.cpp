#pragma once
#include "function.h"

extern Teacher T[100];
extern Student S[100];
extern int TeacherNumber, StudentNumber;
//功能: 显示菜单选项
void Menu()
{
	ifstream in("StudentInfo.txt");
	for (int i = 0; i < StudentNumber; i++)
	{
		in >> S[i];
	}
	system("cls");
	cout << TeacherNumber << ends << StudentNumber << endl;
	int choice;
	char x = 35, y = 10;
	gotoxy(x, y);
	cout << "**********************************" << endl;
	gotoxy(x, y + 1);
	cout << "*                                *" << endl;
	gotoxy(x, y + 2);
	cout << "*  欢迎使用学生成绩管理系统V0.1  *" << endl;
	gotoxy(x, y + 3);
	cout << "*                                *" << endl;
	gotoxy(x, y + 4);
	cout << "*  1.教师登录        2.学生登录  *" << endl;
	gotoxy(x, y + 5);
	cout << "*                                *" << endl;
	gotoxy(x, y + 6);
	cout << "**********************************" << endl;
	gotoxy(x, y + 7);
	cout << "请输入你的选择:";
	cin >> choice;
	Checkpwd(choice);
}

//功能: 读取教师信息
void ReadTeacherFile()
{
	const char * filename = "TeacherInfo.txt";
	ifstream in(filename, ios::in);
	if (!in.is_open())
		cout << "文件不存在!" << endl;
	else
	{
		int find = 0;
		long t_id;
		string t_password;
		
		for (int i = 0; i < TeacherNumber; i++)
		{
			in >> T[i].id >> T[i].password >> T[i].name >> T[i].classid;
			T[i].Show();
		}
		cout << "请输入教师工号:";
		cin >> t_id;
		cout << "请输入登录密码:";
		cin >> t_password;
		for (int i = 0; i < 50; i++)
		{
			if (t_id == T[i].id)
			{
				if (t_password == T[i].password)
				{
					cout << "登录成功!" << endl;
					CheckPermission(i);
				}
				else
					break;
			}
		}
		//cout << "工号或密码错误!" << endl;
		//system("pause");
		Menu();
	}
}

//功能: 接受用户选择。进行身份验证，正确则进入相应的系统，否则无法进入。
void Checkpwd(int choice)
{
	if (choice == 1)
	{
		ReadTeacherFile();
	}
}