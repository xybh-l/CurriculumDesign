#include "Student.h"
#include "others.h"
/*void Student::Show()
{
}*/

extern Student S[100];
void Student::add(Teacher t)
{
	int x = 26, y = 8;
	string t_id;
	system("cls");
	draw();
	gotoxy(x, y);
	cout << "请输入学生学号:";
	cin >> t_id;
	for (int i = 0; i < StudentNumber; i++)
	{
		while (t_id == S[i].id&&t_id!=this->id)
		{
			gotoxy(x, y+2);
			cout << "学号存在重复,请重新输入! ";
			system("pause");
			gotoxy(x, y + 2);
			cout << "                                            ";
			gotoxy(x, y);
			cout << "                                  ";
			gotoxy(x, y);
			cout << "请输入学生学号:";
			cin >> t_id;
		}
	}
	this->id = t_id;
	gotoxy(x, y+3);
	cout << "请输入学生姓名:";
	cin >> this->name;
	this->classid = t.get_classid();
	gotoxy(x, y + 6); 
	cout << "请输入语文成绩:";
	cin >> this->chinese;
	gotoxy(x, y + 9); 
	cout << "请输入数学成绩:";
	cin >> this->math;
	gotoxy(x, y + 12); 
	cout << "请输入英语成绩:";
	cin >> this->english;
	this->sum = this->chinese + this->math + this->english;
	this->aver = this->sum / 3;
	gotoxy(x, y + 15);
}

void Student::add()
{
	int x = 26, y = 8;
	system("cls");
	draw();
	gotoxy(x, y-2);
	cout << "请输入学生班级:";
	cin >> this->classid;
	gotoxy(x, y);
	cout << "请输入学生学号:";
	cin >> this->id;
	for (int i = 0; i < StudentNumber; i++)
	{
		if (id == S[i].id)
		{
			gotoxy(x, y + 2);
			cout << "学号存在重复,请重新输入! ";
			system("pause");
			gotoxy(x, y + 2);
			cout << "                                            ";
			gotoxy(x, y);
			cout << "                                  ";
			gotoxy(x, y);
			cout << "请输入学生学号:";
			cin >> this->id;
		}
	}
	gotoxy(x, y + 3);
	cout << "请输入学生姓名:";
	cin >> this->name;
	gotoxy(x, y + 6);
	cout << "请输入语文成绩:";
	cin >> this->chinese;
	gotoxy(x, y + 9);
	cout << "请输入数学成绩:";
	cin >> this->math;
	gotoxy(x, y + 12);
	cout << "请输入英语成绩:";
	cin >> this->english;
	this->sum = this->chinese + this->math + this->english;
	this->aver = this->sum / 3;
	gotoxy(x, y + 15);
}

string Student::get_id()
{
	return id;
}

double Student::get_sum()
{
	return sum;
}

int Student::get_classid()
{
	return classid;
}

void Student::set_id(string id)
{
	for (int i = 0; i < StudentNumber; i++)
	{
		while (id == S[i].id&&id != this->id)
		{
			gotoxy(26, 32);
			cout << "学号存在重复,请重新输入! ";
			system("pause");
			gotoxy(26, 32);
			cout << "                                            ";
			gotoxy(26, 30);
			cout << "                                  ";
			gotoxy(26, 30);
			cout << "请输入学生学号:";
			cin >> id;
		}
	}
	this->id = id;
}

void Student::set_name(string name)
{
	this->name = name;
}

void Student::set_chinese(double c)
{
	chinese = c;
}

void Student::set_math(double m)
{
	this->math = math;
}

void Student::set_english(double e)
{
	this->english = e;
}

void Student::set_schoolrank(int i)
{
	schoolrank = i;
}

void Student::set_classrank(int i)
{
	classrank = i;
}

void Student::set_password(string newpwd)
{
	pwd = newpwd;
}

int Student::get_classrank()
{
	return classrank;
}

int Student::get_schoolrank()
{
	return schoolrank;
}

