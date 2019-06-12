#include "function.h"
#include "others.h"
#include <iostream>
#include <windows.h>
#pragma warning(disable:4996)

extern int TeacherNumber;
extern int StudentNumber;

int main(void)
{
	system("mode con cols=110 lines=40");
	//系统开始前,读取系统重要参数(教师数量,学生数量)
	ReadImport();
	//打印菜单
	Menu();
	system("pause");
	return 0;
}