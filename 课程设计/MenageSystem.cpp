#pragma once
#include "MenageSystem.h"
#include "others.h"

Teacher T[100];
extern Student S[100];
extern int StudentNumber;
void TeacherSystem(int id) {
	int num;
	int x = 45, y = 6;
	int choice;
	system("cls");
	draw();
	gotoxy(x, y);
	cout << "后台管理系统" << endl;
	gotoxy(x + 6, y + 1);
	cout << "欢迎你," << T[id].name << "老师!" << endl;
	gotoxy(x - 5, y + 5);
	cout << "1.添加本班学生成绩信息" << endl;
	gotoxy(x - 5, y + 8);
	cout << "2.查询本班学生成绩信息" << endl;
	gotoxy(x - 5, y + 11);
	cout << "3.修改本班学生成绩信息" << endl;
	gotoxy(x - 5, y + 14);
	cout << "4.删除本班学生成绩信息" << endl;
	gotoxy(x - 5, y + 17);
	cout << "0.退出" << endl;
	gotoxy(x - 15, y + 24);
	cout << "请输入你的选择:";
	cin >> choice;

	switch (choice)
	{
	case 1:
		gotoxy(x - 15, y + 26);
		cout << "请输入添加学生的人数:";
		cin >> num;
		AddStudentInfo(id,num);
		system("cls");
		TeacherSystem(id);
		break;
	case 2:
		QueryStudentInfo(id);
		break;
	case 3:
		//ModifyStudentInfo();
		break;
	case 4:
		//DeleteStudentInfo();
		break;

	default:
		gotoxy(x - 15, y + 26);
		cout << "无该选项,请重新选择! ";
		system("pause");
		TeacherSystem(id);
	}
}
void AddStudentInfo(int id, int num)
{
	system("cls");
	draw();
	for (int i = StudentNumber; i < StudentNumber+num; i++)
	{
		S[i].add(T[id]);
	}
	gotoxy(26, 25);
	StudentNumber+=num;
	WriteStudentInfo();
	WriteImport();
	cout << "录入成功!";
	system("pause");

}
void QueryStudentInfo(int id)
{
	int choice;
	int i;
	string tid;
	string tname;
	system("cls");
	draw();
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
					gotoxy(x, y + 2);
					system("pause");
					TeacherSystem(id);
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
			for (i = 0; i < StudentNumber; i++)
			{
				gotoxy(x-4, y+1+i);
				cout << S[i].id;
				gotoxy(x + 10, y+1+i);
				cout << S[i].name;
				gotoxy(x + 18, y+1+i);
				cout << S[i].chinese;
				gotoxy(x + 24, y+1+i);
				cout << S[i].math;
				gotoxy(x + 30, y+1+i);
				cout << S[i].english;
				gotoxy(x + 36, y+i+1);
				cout << S[i].sum;
				gotoxy(x + 42, y+1+i);
				cout << S[i].aver;
			}
			gotoxy(x + 30, y + 2 + i);
			system("pause");
			system("cls");
			TeacherSystem(id);
	default:
		gotoxy(x, y + 14);
		cout << "无该选项,请重新选择! ";
		system("pause");
		QueryStudentInfo(id);
	}
}
//功能: 检查登录者权限,选择进入相应的系统
void CheckPermission(int id) {
	
	if (T[id].id == 0)
	{
		//ROOT(); //进入总管理员系统
	}
	else
	{
		TeacherSystem(id); //进入教师系统
		system("pause");
	}
	
		
}
