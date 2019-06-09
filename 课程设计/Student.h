#pragma once
#include"others.h"
#include"Teacher.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

extern int StudentNumber;
class Student
{
private:
	string id;
	string name;
	int classid;
	double chinese;
	double math;
	double english;
	double sum;//总成绩
	double aver;//平均成绩
public:
	//void Show();
	void add(Teacher t);
	friend ifstream & operator >>(ifstream & in, Student & S) {
		in >> S.id >> S.name >> S.classid >> S.chinese >> S.math >> S.english >> S.sum >> S.aver;
		return in;
	}
	friend void QueryStudentInfo(int id);
	friend void DeleteStudentInfo(int id);
	friend void WriteStudentInfo();
};