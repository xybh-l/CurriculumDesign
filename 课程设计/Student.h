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
	string pwd = "123456";
	int classid;
	double chinese;
	double math;
	double english;
	double sum;//总成绩
	double aver;//平均成绩
public:
	void add(Teacher t);
	double get_sum();
	friend ifstream & operator >>(ifstream & in, Student & S) {
		in >> S.id >> S.name >> S.pwd >> S.classid >> S.chinese >> S.math >> S.english >> S.sum >> S.aver;
		return in;
	}
	friend bool operator <(Student& l, Student& r);
	friend void QueryStudentInfo(int id);
	friend void DeleteStudentInfo(int id);
	friend void ModifyStudentInfo(int id);
	friend void QueryGrade(int id);
	//friend bool cmp(Student &A, Student &B);
	friend void StudentSystem();
	friend void WriteStudentInfo();
};