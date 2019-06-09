#include "function.h"
#include "others.h"
#include <iostream>
#include <windows.h>
#pragma warning(disable:4996)

extern int TeacherNumber;
extern int StudentNumber;

int main(void)
{
	system("mode con cols=100 lines=40");
	const char * filename = "import.txt";
	FILE * read = fopen(filename, "r");
	if (read == NULL)
	{
		fopen(filename, "w");
		TeacherNumber = StudentNumber = 0;
	}
	else 
		fscanf(read, "%d %d",&TeacherNumber, &StudentNumber);
	cout << TeacherNumber << ends << StudentNumber << endl;
	
	Menu();
	system("pause");
	return 0;
}