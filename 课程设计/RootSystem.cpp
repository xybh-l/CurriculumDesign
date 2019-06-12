#include "RootSystem.h"

void AddTeacherInfo(int num)
{

	if (num <= 0)
	{
		ROOT();
	}
	system("cls");
	draw();
	for (int i = TeacherNumber; i < TeacherNumber + num; i++)
	{
		int t_classid;
		string t_name;
		long t_id;
		int x = 26, y = 8;
		system("cls");
		draw();
		gotoxy(x, y+4);
		cout << "请输入教师执教班级:";
		cin >> t_classid;
		gotoxy(x, y+10);
		cout << "请输入教师工号:";
		cin >> t_id;
		gotoxy(x, y + 16);
		cout << "请输入教师姓名:";
		cin >> t_name;
		T[i].SetInfo(t_id,t_name,t_classid);
	}
	gotoxy(26, 25);
	TeacherNumber += num;
	WirteTeacherFIle();
	WriteImport();
	cout << "录入成功!";
	system("pause");
	ROOT();
}

void QueryTeacherInfo()
{
	system("cls");
	draw();
	int x = 26, y = 8;
	int i;
	gotoxy(x +4, y);
	cout << "工号";
	gotoxy(x + 16, y);
	cout << "姓名";
	gotoxy(x + 28, y);
	cout << "执教班级";
	for (i = 0; i < TeacherNumber; i++)
	{
		gotoxy(x + 4, y+i+1);
		cout << T[i].id;
		gotoxy(x + 16, y+i+1);
		cout << T[i].name;
		gotoxy(x + 28, y+i+1);
		cout << T[i].classid;
	}
	gotoxy(x + 30, y + 2 + i);
	system("pause");
	system("cls");
	ROOT();
}

void DeleteTeacherInfo()
{

}
