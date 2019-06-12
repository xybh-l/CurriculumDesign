#include "RootSystem.h"

//功能: 添加教师信息
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
	WirteTeacherInfo();
	WriteImport();
	cout << "录入成功!";
	system("pause");
	ROOT();
}

//功能: 查询教师信息
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

//功能: 删除教师信息
void DeleteTeacherInfo()
{
	long tid;
	int find = 0;
	int i = 0;
	int x = 45, y = 6;
	gotoxy(x - 15, y + 26);
	cout << "请输入要删除的教师工号:";
	cin >> tid;
	for (i = 0; i < TeacherNumber; i++)
	{
		if (tid == T[i].id)
		{
			for (int deleteid = i; deleteid < TeacherNumber - 1; deleteid++)
			{
				swap(T[deleteid + 1], T[deleteid]);
			}
			gotoxy(x - 15, y + 28);
			TeacherNumber--;
			cout << "删除成功!";
			find = 1;
			break;
		}
	}
	if (find == 0)
	{
		gotoxy(x - 15, y + 28);
		cout << "没有查询到该工号,请核对后,再进行操作。";
	}
	gotoxy(x - 10, y + 30);
	system("pause");
	WirteTeacherInfo();
	WriteImport();
	ROOT();
}

void ModifyTeacherInfo()
{
	int choice;
	long t_id;
	int t_classid;
	int i;
	int x = 45, y = 6;
	gotoxy(x - 15, y + 26);
	cout << "请输入要修改教师学号:";
	cin >> t_id;
	for (i = 0; i < TeacherNumber; i++)
	{
		if (t_id == T[i].id)
		{
			system("cls");
			draw();
			int x = 26, y = 8;
			gotoxy(x, y);
			cout << "1.修改教师工号";
			gotoxy(x, y+3);
			cout << "2.修改教师执教班级";
			gotoxy(x, y+6);
			cout << "3.请输入你的选择:";
			cin >> choice;
			switch (choice)
			{
			case 1:
				gotoxy(x, y + 22);
				cout << "请输入修改的工号:";
				cin >> t_id;
				T[i].set_id(t_id);
				break;
			case 2:
				gotoxy(x, y + 22);
				cout << "请输入执教班级:";
				cin >> t_classid;
				T[i].set_classid(t_classid);
				break;
			default:
				cin.clear();
				cin.ignore(1024, '\n');
				break;
			}
		}
	}
}
