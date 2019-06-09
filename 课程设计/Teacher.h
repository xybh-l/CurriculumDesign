#pragma once

#include<iostream>
#include<string>

using std::string;
using std::cout;
using std::endl;
using std::ends;

class Teacher
{
public:
	void SetInfo(long m_id, string m_password, string m_name, int m_classid);
	void Show();
	int get_classid();
	friend void ReadTeacherFile();
	friend void CheckPermission(int id);
	friend void TeacherSystem(int id);
private:
	long id;
	string password;
	string name;
	int classid;
};

