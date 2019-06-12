#pragma once
#include "MenageSystem.h"
#include "function.h"
#include "RootSystem.h"
#include "others.h"

extern Teacher T[100];
extern Student S[100];
extern int StudentNumber;
extern int TeacherNumber;

//教师管理系统
void TeacherSystem(int id) {
	int num;
	int x = 45, y = 6;
	int choice;
	system("cls");
	draw();
	gotoxy(x, y);
	cout << "后台管理系统";
	gotoxy(x + 6, y + 1);
	cout << "欢迎你," << T[id].name << "老师!";
	gotoxy(x - 5, y + 5);
	cout << "1.添加本班学生成绩信息";
	gotoxy(x - 5, y + 8);
	cout << "2.查询本班学生成绩信息";
	gotoxy(x - 5, y + 11);
	cout << "3.修改本班学生个人信息";
	gotoxy(x - 5, y + 14);
	cout << "4.删除本班学生成绩信息";
	gotoxy(x - 5, y + 17);
	cout << "5.修改密码";
	gotoxy(x - 5, y + 20);
	cout << "0.退出" << endl;
	gotoxy(x - 15, y + 24);
	cout << "请输入你的选择:";
	cin >> choice;

	switch (choice)
	{
	case 0:
		Menu();
	case 1:
		gotoxy(x - 15, y + 26);
		cout << "请输入添加学生的人数:";
		cin >> num;
		AddStudentInfo(id,num);
		system("cls");
		TeacherSystem(id);
	case 2:
		QueryStudentInfo(id);
	case 3:
		ModifyStudentInfo(id);
		break;
	case 4:
		DeleteStudentInfo(id);
		break;
	case 5:
		gotoxy(x - 15, y + 25);
		T[id].ModifyPwd();
		WirteTeacherInfo();
		TeacherSystem(id);
	default:
		gotoxy(x - 15, y + 26);
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "无该选项,请重新选择! ";
		system("pause");
		TeacherSystem(id);
	}
}
//管理员系统
void ROOT()
{
	int x = 45, y = 6;
	int choice;
	system("cls");
	draw();
	gotoxy(x, y);
	cout << "后台管理系统";
	gotoxy(x + 6, y + 1);
	cout << "欢迎你,管理员";
	gotoxy(x - 5, y + 5);
	cout << "1.添加学生成绩信息";
	gotoxy(x + 16, y + 5);
	cout << "5.添加教师信息";
	gotoxy(x - 5, y + 8);
	cout << "2.查询学生成绩信息";
	gotoxy(x + 16, y + 8);
	cout << "6.查询教师信息";
	gotoxy(x - 5, y + 11);
	cout << "3.修改学生个人信息";
	gotoxy(x + 16, y + 11);
	cout << "7.修改教师信息";
	gotoxy(x - 5, y + 14);
	cout << "4.删除学生成绩信息";
	gotoxy(x + 16, y + 14);
	cout << "8.删除教师信息";
	gotoxy(x - 5, y + 17);
	cout << "9.修改密码";
	gotoxy(x + 16, y + 17);
	cout << "0.退出" << endl;
	gotoxy(x - 15, y + 24);
	cout << "请输入你的选择:";
	cin >> choice;
	switch (choice)
	{
	case 1:
		int num;
		gotoxy(x - 15, y + 26);
		cout << "请输入添加学生的人数:";
		cin >> num;
		AddStudentInfo(num);
	case 2:
		QueryStudentInfo();
	case 3:
		ModifyStudentInfo();
	case 4:
		//DeleteStudentInfo();
	case 5:
		gotoxy(x - 15, y + 26);
		cout << "请输入添加教师的人数:";
		cin >> num;
		AddTeacherInfo(num);
		system("cls");
		ROOT();
	case 6:
		QueryTeacherInfo();
	case 7:
		ModifyTeacherInfo();
	case 8:
		DeleteTeacherInfo();
	case 0:
		Menu();
	default:
		cin.clear();
		cin.ignore(1024, '\n');
		break;
	}
}
//功能: 添加学生信息(教师系统)
void AddStudentInfo(int id, int num)
{
	if (num <= 0)
	{
		TeacherSystem(id);
	}
	system("cls");
	draw();
	for (int i = StudentNumber; i < StudentNumber+num; i++)
	{
		S[i].add(T[id]);
	}
	gotoxy(26, 25);
	StudentNumber+=num;
	SortRank();
	SortRank(id);
	WriteStudentInfo();
	WriteImport();
	cout << "录入成功!";
	system("pause");

}
//功能: 添加学生信息(管理员系统)
void AddStudentInfo(int num)
{

	if (num <= 0)
	{
		ROOT();
	}
	system("cls");
	draw();
	for (int i = StudentNumber; i < StudentNumber + num; i++)
	{
		S[i].add();
	}
	gotoxy(26, 25);
	StudentNumber += num;
	SortRank();
	WriteStudentInfo();
	WriteImport();
	cout << "录入成功!";
	system("pause");
	ROOT();
}
//功能: 重载学生成绩比较运算符
bool operator<(Student& l, Student& r)
{
	return l.sum > r.sum;
}
//功能: 查询学生成绩信息(教师系统)
void QueryStudentInfo(int id)
{
	int choice;
	int i, find = 0;
	int n = 0;
	string tid;
	string tname;
	system("cls");
	draw();
	SortRank();
	SortRank(id);
	int x = 26, y = 8;
	gotoxy(x, y);
	cout << "1.根据学号查询学生成绩";
	gotoxy(x, y+3);
	cout << "2.根据姓名查询学生成绩";
	gotoxy(x, y+6);
	cout << "3.查询所有学生成绩";
	gotoxy(x, y+9);
	cout << "0.退出";
	gotoxy(x, y + 12);
	cout << "请输入你的选择:";
	cin >> choice;
	switch (choice)
	{
		case 0:
			TeacherSystem(id);
		case 1:
			gotoxy(x, y + 14);
			cout << "请输入你要查询的学号:";
			cin >> tid;
			for (i = 0; i < StudentNumber; i++)
			{
				if (T[id].get_classid() == S[i].classid)
				{
					if (tid == S[i].id)
					{
						system("cls");
						draw();
						gotoxy(x - 4, y);
						cout << "学号";
						gotoxy(x + 10, y);
						cout << "姓名";
						gotoxy(x + 18, y);
						cout << "语文";
						gotoxy(x + 24, y);
						cout << "数学";
						gotoxy(x + 30, y);
						cout << "英语";
						gotoxy(x + 36, y);
						cout << "总分";
						gotoxy(x + 42, y);
						cout << "平均分";
						gotoxy(x + 50, y);
						cout << "班排";
						gotoxy(x + 56, y);
						cout << "校排";
						gotoxy(x - 4, y + 1);
						cout << S[i].id;
						gotoxy(x + 10, y + 1);
						cout << S[i].name;
						gotoxy(x + 18, y + 1);
						cout << S[i].chinese;
						gotoxy(x + 24, y + 1);
						cout << S[i].math;
						gotoxy(x + 30, y + 1);
						cout << S[i].english;
						gotoxy(x + 36, y + 1);
						cout << S[i].sum;
						gotoxy(x + 42, y + 1);
						cout << S[i].aver;
						gotoxy(x + 50, y + 1);
						cout << S[i].get_classrank();
						gotoxy(x + 56, y + 1);
						cout << S[i].get_schoolrank();
						gotoxy(x, y + 2);
						system("pause");
						TeacherSystem(id);
					}
				}
			}
			if (i == StudentNumber)
			{
				system("cls");
				draw();
				gotoxy(x + 18, y);
				cout << "无该学号信息!";
				gotoxy(x + 28, y+1);
				system("pause");
				TeacherSystem(id);
			}
		case 2:
			gotoxy(x, y + 14);
			cout << "请输入你要查询的姓名:";
			cin >> tname;
			system("cls");
			draw();
			for (i = 0; i < StudentNumber; i++)
			{
				if (T[id].get_classid() == S[i].classid)
				{
					if (tname == S[i].name)
					{
						gotoxy(x - 4, y);
						cout << "学号";
						gotoxy(x + 10, y);
						cout << "姓名";
						gotoxy(x + 18, y);
						cout << "语文";
						gotoxy(x + 24, y);
						cout << "数学";
						gotoxy(x + 30, y);
						cout << "英语";
						gotoxy(x + 36, y);
						cout << "总分";
						gotoxy(x + 42, y);
						cout << "平均分";
						gotoxy(x + 50, y);
						cout << "班排";
						gotoxy(x + 56, y);
						cout << "校排";
						gotoxy(x - 4, y + 1 + n);
						cout << S[i].id;
						gotoxy(x + 10, y + 1 + n);
						cout << S[i].name;
						gotoxy(x + 18, y + 1 + n);
						cout << S[i].chinese;
						gotoxy(x + 24, y + 1 + n);
						cout << S[i].math;
						gotoxy(x + 30, y + 1 + n);
						cout << S[i].english;
						gotoxy(x + 36, y + 1 + n);
						cout << S[i].sum;
						gotoxy(x + 42, y + 1 + n);
						cout << S[i].aver;
						gotoxy(x + 50, y + 1 + n);
						cout << S[i].get_classrank();
						gotoxy(x + 56, y + 1 + n);
						cout << S[i].get_schoolrank();
						n++;
						find = 1;
					}
				}
				else
				{
					n--;
				}
			}
			if (find == 0)
			{
				system("cls");
				draw();
				gotoxy(x + 18, y);
				cout << "无该学生信息!";
				gotoxy(x + 28, y + 1);
				system("pause");
				TeacherSystem(id);
			}
			else
			{
				find = 0;
				gotoxy(x, y + 1 + i);
				system("pause");
				TeacherSystem(id);
			}
			break;
		case 3:
			system("cls");
			draw();
			gotoxy(x-4, y);
			cout << "学号";
			gotoxy(x+10, y);
			cout << "姓名";
			gotoxy(x + 18, y);
			cout << "语文";
			gotoxy(x + 24, y);
			cout << "数学";
			gotoxy(x + 30, y);
			cout << "英语";
			gotoxy(x + 36, y);
			cout << "总分";
			gotoxy(x + 42, y);
			cout << "平均分";
			gotoxy(x + 50, y);
			cout << "班排";
			gotoxy(x + 56, y);
			cout << "校排";
			for (i = 0; i < StudentNumber; i++)
			{
				if (T[id].get_classid() == S[i].classid)
				{
					gotoxy(x - 4, y + 1 + i);
					cout << S[i].id;
					gotoxy(x + 10, y + 1 + i);
					cout << S[i].name;
					gotoxy(x + 18, y + 1 + i);
					cout << S[i].chinese;
					gotoxy(x + 24, y + 1 + i);
					cout << S[i].math;
					gotoxy(x + 30, y + 1 + i);
					cout << S[i].english;
					gotoxy(x + 36, y + i + 1);
					cout << S[i].sum;
					gotoxy(x + 42, y + 1 + i);
					cout << S[i].aver;
					gotoxy(x + 50, y + 1 + i);
					cout << S[i].get_classrank();
					gotoxy(x + 56, y + 1 + i);
					cout << S[i].get_schoolrank();
				}
				else
				{
					y--;
				}
			}
			gotoxy(x + 30, y + 2 + i);
			system("pause");
			system("cls");
			TeacherSystem(id);
	default:
		gotoxy(x, y + 14);
		cin.clear();
		cin.ignore(1024, '\n');
		cout << "无该选项,请重新选择! ";
		system("pause");
		QueryStudentInfo(id);
	}
}
//功能: 查询学生成绩信息(管理员系统)
void QueryStudentInfo()
{
		int choice;
		int i, find = 0;
		int n = 0;
		string tid;
		string tname;
		SortRank();
		system("cls");
		draw();
		int x = 26, y = 8;
		gotoxy(x, y);
		cout << "1.根据学号查询学生成绩";
		gotoxy(x, y + 3);
		cout << "2.根据姓名查询学生成绩";
		gotoxy(x, y + 6);
		cout << "3.查询所有学生成绩";
		gotoxy(x, y + 9);
		cout << "0.退出";
		gotoxy(x, y + 12);
		cout << "请输入你的选择:";
		cin >> choice;
		switch (choice)
		{
		case 0:
			ROOT();
		case 1:
			gotoxy(x, y + 14);
			cout << "请输入你要查询的学号:";
			cin >> tid;
			for (i = 0; i < StudentNumber; i++)
			{
					system("cls");
					draw();
					gotoxy(x - 4, y);
					cout << "学号";
					gotoxy(x + 10, y);
					cout << "姓名";
					gotoxy(x + 18, y);
					cout << "语文";
					gotoxy(x + 24, y);
					cout << "数学";
					gotoxy(x + 30, y);
					cout << "英语";
					gotoxy(x + 36, y);
					cout << "总分";
					gotoxy(x + 42, y);
					cout << "平均分";
					gotoxy(x + 50, y);
					cout << "校排"; 
					gotoxy(x + 55, y);
					cout << "班级";
					gotoxy(x - 4, y + 1);
					cout << S[i].id;
					gotoxy(x + 10, y + 1);
					cout << S[i].name;
					gotoxy(x + 18, y + 1);
					cout << S[i].chinese;
					gotoxy(x + 24, y + 1);
					cout << S[i].math;
					gotoxy(x + 30, y + 1);
					cout << S[i].english;
					gotoxy(x + 36, y + 1);
					cout << S[i].sum;
					gotoxy(x + 42, y + 1);
					cout << S[i].aver;
					gotoxy(x + 50, y + 1);
					cout << S[i].get_schoolrank();
					gotoxy(x + 55, y + 1);
					cout << S[i].classid;
					gotoxy(x, y + 2);
					system("pause");
					ROOT();
			
			}
			if (i == StudentNumber)
			{
				system("cls");
				draw();
				gotoxy(x + 18, y);
				cout << "无该学号信息!";
				gotoxy(x + 28, y + 1);
				system("pause");
				ROOT();
			}
		case 2:
			gotoxy(x, y + 14);
			cout << "请输入你要查询的姓名:";
			cin >> tname;
			system("cls");
			draw();
			for (i = 0; i < StudentNumber; i++)
			{
				if (tname == S[i].name)
				{
					gotoxy(x - 4, y);
					cout << "学号";
					gotoxy(x + 10, y);
					cout << "姓名";
					gotoxy(x + 18, y);
					cout << "语文";
					gotoxy(x + 24, y);
					cout << "数学";
					gotoxy(x + 30, y);
					cout << "英语";
					gotoxy(x + 36, y);
					cout << "总分";
					gotoxy(x + 42, y);
					cout << "平均分";
					gotoxy(x + 50, y);
					cout << "校排";
					gotoxy(x + 55, y);
					cout << "班级";
					gotoxy(x - 4, y + 1 + n);
					cout << S[i].id;
					gotoxy(x + 10, y + 1 + n);
					cout << S[i].name;
					gotoxy(x + 18, y + 1 + n);
					cout << S[i].chinese;
					gotoxy(x + 24, y + 1 + n);
					cout << S[i].math;
					gotoxy(x + 30, y + 1 + n);
					cout << S[i].english;
					gotoxy(x + 36, y + 1 + n);
					cout << S[i].sum;
					gotoxy(x + 42, y + 1 + n);
					cout << S[i].aver;
					gotoxy(x + 50, y + 1 + n);
					cout << S[i].get_schoolrank();
					gotoxy(x + 55, y + 1 + n);
					cout << S[i].classid;
					n++;
					find = 1;
				}
			}
			if (find == 0)
			{
				system("cls");
				draw();
				gotoxy(x + 18, y);
				cout << "无该学生信息!";
				gotoxy(x + 28, y + 1);
				system("pause");
				ROOT();
			}
			else
			{
				find = 0;
				gotoxy(x, y + 1 + i);
				system("pause");
				ROOT();
			}
			break;
		case 3:
			system("cls");
			draw();
			gotoxy(x - 4, y);
			cout << "学号";
			gotoxy(x + 10, y);
			cout << "姓名";
			gotoxy(x + 18, y);
			cout << "语文";
			gotoxy(x + 24, y);
			cout << "数学";
			gotoxy(x + 30, y);
			cout << "英语";
			gotoxy(x + 36, y);
			cout << "总分";
			gotoxy(x + 42, y);
			cout << "平均分";
			gotoxy(x + 50, y);
			cout << "校排";
			gotoxy(x + 55, y);
			cout << "班级";
			for (i = 0; i < StudentNumber; i++)
			{
				gotoxy(x - 4, y + 1 + i);
				cout << S[i].id;
				gotoxy(x + 10, y + 1 + i);
				cout << S[i].name;
				gotoxy(x + 18, y + 1 + i);
				cout << S[i].chinese;
				gotoxy(x + 24, y + 1 + i);
				cout << S[i].math;
				gotoxy(x + 30, y + 1 + i);
				cout << S[i].english;
				gotoxy(x + 36, y + i + 1);
				cout << S[i].sum;
				gotoxy(x + 42, y + 1 + i);
				cout << S[i].aver;
				gotoxy(x + 50, y + 1 + i);
				cout << S[i].get_schoolrank();
				gotoxy(x + 55, y + 1 + i);
				cout << S[i].classid;
			}
			gotoxy(x + 30, y + 2 + i);
			system("pause");
			system("cls");
			ROOT();
		default:
			gotoxy(x, y + 14);
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "无该选项,请重新选择! ";
			system("pause");
			QueryStudentInfo();
		}
}
//功能: 修改学生信息(教师系统)
void ModifyStudentInfo(int id)
{
	string tid;
	int find = 0;
	int i = 0;
	int x = 45, y = 6;
	int choice;
	string t_name, t_id;
	double t_grade;
	gotoxy(x - 15, y + 26);
	cout << "请输入要修改的学生学号:";
	cin >> tid;
	for (i = 0; i < StudentNumber; i++)
	{
		if (tid == S[i].id&&S[i].classid == T[id].get_classid())
		{
			system("cls");
			draw();
			int x = 26, y = 8;
			gotoxy(x, y);
			cout << "1.修改学号";
			gotoxy(x, y + 3);
			cout << "2.修改姓名";
			gotoxy(x, y + 6);
			cout << "3.修改语文成绩";
			gotoxy(x, y + 9);
			cout << "4.修改数学成绩";
			gotoxy(x, y + 12);
			cout << "5.修改英语成绩";
			gotoxy(x, y + 15);
			cout << "6.全部修改";
			gotoxy(x, y + 18);
			cout << "0.返回主菜单";
			gotoxy(x, y + 21);
			cout << "请选择修改的信息:";
			cin >> choice;
			switch (choice)
			{
			case 1:
				gotoxy(x, y+22);
				cout << "请输入学号:";
				cin >> t_id;
				S[i].set_id(t_id);
				break;
			case 2:
				gotoxy(x, y + 22);
				cout << "请输入姓名:";
				cin >> t_name;
				S[i].set_name(t_name);
				break;
			case 3:
				gotoxy(x, y + 22);
				cout << "请输入语文成绩:";
				cin >> t_grade;
				S[i].set_chinese(t_grade);
				break;
			case 4:
				gotoxy(x, y + 22);
				cout << "请输入数学成绩:";
				cin >> t_grade;
				S[i].set_math(t_grade);
				break;
			case 5:
				gotoxy(x, y + 22);
				cout << "请输入英语成绩:";
				cin >> t_grade;
				S[i].set_english(t_grade);
				break;
			case 6:
				S[i].add(T[id]);
			case 0:
				ROOT();
			default:
				cin.clear();
				cin.ignore(1024, '\n');
				break;
			}
			gotoxy(x, y + 25);
			cout << "修改成功!";
			WriteStudentInfo();
			find = 1;
			break;
		}
	}
	if (find == 0)
	{
		gotoxy(x - 15, y + 28);
		cout << "没有查询到该学号,请核对后,再进行操作。";
	}
	gotoxy(x - 10, y + 30);
	system("pause");
	SortRank();
	SortRank(id);
	WriteStudentInfo();
	WriteImport();
	TeacherSystem(id);
}
//功能: 修改学生信息(管理员系统)
void ModifyStudentInfo()
{
	string tid;
	int find = 0;
	int i = 0;
	int x = 45, y = 6;
	int choice;
	string t_name, t_id;
	double t_grade;
	gotoxy(x - 15, y + 26);
	cout << "请输入要修改的学生学号:";
	cin >> tid;
	for (i = 0; i < StudentNumber; i++)
	{
		if (tid == S[i].id)
		{
			system("cls");
			draw();
			int x = 26, y = 8;
			gotoxy(x, y);
			cout << "1.修改学号";
			gotoxy(x, y + 3);
			cout << "2.修改姓名";
			gotoxy(x, y + 6);
			cout << "3.修改语文成绩";
			gotoxy(x, y + 9);
			cout << "4.修改数学成绩";
			gotoxy(x, y + 12);
			cout << "5.修改英语成绩";
			gotoxy(x, y + 15);
			cout << "6.全部修改";
			gotoxy(x, y + 18);
			cout << "0.返回主菜单";
			gotoxy(x, y + 21);
			cout << "请选择修改的信息:";
			cin >> choice;
			switch (choice)
			{
			case 1:
				gotoxy(x, y + 22);
				cout << "请输入学号:";
				cin >> t_id;
				S[i].set_id(t_id);
				break;
			case 2:
				gotoxy(x, y + 22);
				cout << "请输入姓名:";
				cin >> t_name;
				S[i].set_name(t_name);
				break;
			case 3:
				gotoxy(x, y + 22);
				cout << "请输入语文成绩:";
				cin >> t_grade;
				S[i].set_chinese(t_grade);
				break;
			case 4:
				gotoxy(x, y + 22);
				cout << "请输入数学成绩:";
				cin >> t_grade;
				S[i].set_math(t_grade);
				break;
			case 5:
				gotoxy(x, y + 22);
				cout << "请输入英语成绩:";
				cin >> t_grade;
				S[i].set_english(t_grade);
				break;
			case 6:
				S[i].add();
			case 0:
				ROOT();
			default:
				cin.clear();
				cin.ignore(1024, '\n');
				break;
			}
			gotoxy(x, y + 25);
			cout << "修改成功!";
			WriteStudentInfo();
			find = 1;
			break;
		}
	}
	if (find == 0)
	{
		gotoxy(x - 15, y + 28);
		cout << "没有查询到该学号,请核对后,再进行操作。";
	}
	gotoxy(x - 10, y + 30);
	system("pause");
	SortRank();
	WriteStudentInfo();
	WriteImport();
	ROOT();
}
//功能: 删除学生信息(教师系统)
void DeleteStudentInfo(int id)
{
	string tid;
	int find = 0;
	int i = 0;
	int x = 45, y = 6;
	gotoxy(x - 15, y + 26);
	cout << "请输入要删除的学生学号:";
	cin >> tid;
	for (i = 0; i < StudentNumber; i++)
	{
		if (tid == S[i].id&&S[i].classid==T[id].get_classid())
		{
			for (int deleteid = i;  deleteid < StudentNumber-1; deleteid++)
			{
				swap(S[deleteid + 1], S[deleteid]);
			}
			gotoxy(x - 15, y + 28);
			StudentNumber--;
			cout << "删除成功!";
			find = 1;
			break;
		}
	}
	if (find == 0)
	{
		gotoxy(x - 15, y + 28);
		cout << "没有查询到该学号,请核对后,再进行操作。";
	}
	gotoxy(x - 10, y + 30);
	system("pause");
	SortRank();
	SortRank(id);
	WriteStudentInfo();
	WriteImport();
	TeacherSystem(id);
	
}
//功能: 检查登录者权限,选择进入相应的系统
void CheckPermission(int id) {
	
	if (id == -1)
	{
		ROOT(); //进入总管理员系统
	}
	else
	{
		TeacherSystem(id); //进入教师系统
		system("pause");
	}
	
		
}

//功能: 将教师信息写入文件(TeacherInfo.txt)
void WirteTeacherInfo()
{
	ofstream out("TeacherInfo.txt");
	for (int i = 0; i < TeacherNumber; i++)
	{
		out << T[i].id << " " << T[i].password << " " << T[i].name << " " << T[i].classid << "\n";
	}
}