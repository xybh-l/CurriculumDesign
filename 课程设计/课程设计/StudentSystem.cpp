#include "StudentSystem.h"

extern Student S[100];

void StudentSystem()
{
	int x = 30;
	int y = 10;
	int i;
	int find = 0;
	string tid, tpwd;
	system("cls");
	gotoxy(x, y);
	cout << "***************************************";
	for (i = 1; i < 10; i++)
	{
		gotoxy(x, y+i);
		cout << "*                                     *";
	}
	gotoxy(x, y + i);
	cout << "***************************************";
	gotoxy(35, 12);
	cout << "学号:";
	gotoxy(35, 16);
	cout << "密码:";
	gotoxy(42, 12);
	cin >> tid;
	gotoxy(42, 16);
	cin >> tpwd;
	for (int i = 0; i < StudentNumber; i++)
	{
		if (S[i].id == tid)
		{
			if (S[i].pwd == tpwd)
			{
				StudentChoice(i);
				find = 1;
			}
		}
	}
	if (find == 0)
	{
		gotoxy(33, 19);
		cout << "账号或密码错误!";
		system("pause");
		Menu();
	}
}

void StudentChoice(int id)
{
	int x = 30;
	int y = 10;
	string newpassword;
	int choice;
	int i;
	system("cls");
	gotoxy(x, y);
	cout << "***************************************";
	for (i = 1; i < 10; i++)
	{
		gotoxy(x, y + i);
		cout << "*                                     *";
	}
	gotoxy(x, y + i);
	cout << "***************************************";
	gotoxy(35, 12);
	cout << "1.查询个人成绩";
	gotoxy(35, 14);
	cout << "2.修改密码";
	gotoxy(35, 16);
	cout << "0.退出";
	gotoxy(35, 18);
	cout << "请输入你的选择:";
	cin >> choice;
	if (choice == 1)
	{
		QueryGrade(id);
		system("pause");
		StudentChoice(id);
	}
	else if (choice == 2)
	{
		gotoxy(35, 18);
		cout << "请输入新的密码:              ";
		gotoxy(50, 18);
		cin >> newpassword;
		S[id].set_password(newpassword);
		WriteStudentInfo();
		StudentChoice(id);
	}
	else if (choice == 0)
		exit(0);
	else
	{
		cin.clear();
		cin.ignore(1024, '\n');
		StudentChoice(id);
	}
}

void QueryGrade(int id)
{
	int x = 26, y = 3;
	system("cls");
	draw();
	gotoxy(x, y + 3);
	cout << "姓名:" << S[id].name;
	gotoxy(x, y + 7);
	cout << "班级:" << S[id].classid;
	gotoxy(x, y + 11);
	cout << "语文成绩:"<<S[id].chinese;
	gotoxy(x, y + 15);
	cout << "数学成绩:"<<S[id].math;
	gotoxy(x, y + 19);
	cout << "英语成绩:"<<S[id].english;
	gotoxy(x, y + 23);
	cout << "总分:" << S[id].sum;
	gotoxy(x, y + 27);
	cout << "平均分:" << S[id].aver;
	gotoxy(x, y + 30);
	cout << "班排:" << S[id].classrank;
	gotoxy(x, y + 33);
	cout << "年排:" << S[id].schoolrank;
	gotoxy(x+10, y + 33);
}
