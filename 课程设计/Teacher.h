#pragma once

#include<iostream>
#include<fstream>
#include<string>

using std::string;
using std::cout;
using std::endl;
using std::ends;
using std::cin;
using std::ofstream;

class Teacher
{
public:
	void SetInfo(long m_id, string m_name, int m_classid, string m_password = "111111");
	void Show();
	void set_id(long id);
	void set_classid(int classid);
	int get_classid();
	void ModifyPwd();
	friend void WirteTeacherInfo();
	friend void ReadTeacherFile();
	friend void CheckPermission(int id);
	friend void TeacherSystem(int id);
	friend void QueryTeacherInfo();
	friend void DeleteTeacherInfo();
	friend void ModifyTeacherInfo();
private:
	long id;
	string password;
	string name;
	int classid;
};