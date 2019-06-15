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
	int classrank;
	int schoolrank;
public:
	void add(Teacher t);
	void add();
	string get_id();
	double get_sum();
	int get_classid();
	void set_id(string id);
	void set_name(string name);
	void set_chinese(double c);
	void set_math(double m);
	void set_english(double e);
	void set_schoolrank(int i);
	void set_classrank(int i);
	void set_password(string newpwd);
	int get_classrank();
	int get_schoolrank();
	friend ifstream & operator >>(ifstream & in, Student & S) {
		in >> S.id >> S.name >> S.pwd >> S.classid >> S.chinese >> S.math >> S.english >> S.sum >> S.aver >> S.classrank >> S.schoolrank;
		return in;
	}
	friend bool operator <(Student& l, Student& r);
	friend void QueryStudentInfo(int id);
	friend void QueryStudentInfo();
	friend void DeleteStudentInfo();
	friend void DeleteStudentInfo(int id);
	friend void ModifyStudentInfo();
	friend void ModifyStudentInfo(int id);
	friend void QueryGrade(int id);
	friend void StudentSystem();
	friend void WriteStudentInfo();
};