#include"others.h"
#include "Global.h"
#include<iostream>
#include<fstream>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::vector;

int TeacherNumber, StudentNumber;
Student S[100];
Teacher T[100];

//功能: 定位函数(将光标定位至指定位置)
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

//功能: 绘制系统边框
void draw()
{
	static int i = 0;
	char x = 20, y = 3;
	gotoxy(x, y); 
	cout << "***********************************************************************"<<endl;
	for (i=1; i < 34; i++)
	{
		gotoxy(x, y+i);
		cout << "*                                                                     *"<<endl;
	}
	gotoxy(x, y+i);
	cout << "***********************************************************************"<<endl;
}

//功能: 将学生信息写入文件(StudentInfo.txt)
void WriteStudentInfo()
{
	const char * filename = "StudentInfo.txt";
	ofstream out(filename, ios::out);
	for (int i = 0; i < StudentNumber; i++)
	{
		out << S[i].id << " " << S[i].name << " " << S[i].pwd << " " << S[i].classid << " " << S[i].chinese << " " << S[i].math << " " << S[i].english << " " << S[i].sum << " " <<S[i].aver << " " << S[i].classrank << " " << S[i].schoolrank << "\n";
	}
	out.close();
}

//功能: 读取系统重要参数(import.txt)
void ReadImport()
{
	const char * filename = "import.txt";
	FILE * read = fopen(filename, "r");
	if (read == NULL)
	{
		fopen(filename, "w");
		TeacherNumber = StudentNumber = 0;
	}
	else
		fscanf(read, "%d %d", &TeacherNumber, &StudentNumber);
	cout << TeacherNumber << ends << StudentNumber << endl;
}

//功能: 将系统重要参数写入文件(import.txt)
void WriteImport()
{
	ofstream out("import.txt", ios::out);
	out << TeacherNumber << " " << StudentNumber;
	out.close();
}

//功能: 将学生成绩进行校内排序(不区分班级)
void SortRank()
{
	sort(S, S + StudentNumber);
	for (int i = 0; i < StudentNumber; i++)
	{
		S[i].set_schoolrank(i + 1);
	}
}

bool emp(Student &A, Student &B) {
	return A.get_sum() > B.get_sum();
}

//功能: 将学生成绩进行班内排序(区分班级)
void SortRank(int id)
{
	
	vector<Student> ClassStudent;
	for (int i = 0; i < StudentNumber; i++)
	{
		if (S[i].get_classid() == T[id].get_classid())
		{
			ClassStudent.push_back(S[i]);
		}
	}
	sort(ClassStudent.begin(), ClassStudent.end(),emp);
	for (int i = 0; i < ClassStudent.size(); i++)
	{
		ClassStudent[i].set_classrank(i+1);
	}
	for (int i = 0; i < StudentNumber; i++)
	{
		for (int j = 0; j < ClassStudent.size(); j++)
		{
			if (S[i].get_id() == ClassStudent[j].get_id())
				S[i].set_classrank(ClassStudent[j].get_classrank());
		}
	}
}


