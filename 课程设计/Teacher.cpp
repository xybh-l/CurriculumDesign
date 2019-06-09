#include "Teacher.h"

void Teacher::SetInfo(long m_id, string m_password, string m_name, int m_classid)
{
	id = m_id;
	password = m_password;
	name = m_name;
	classid = m_classid;
}

void Teacher::Show() 
{ 
	cout << id << ends << password << ends << name << ends << classid << endl; 
}

int Teacher::get_classid()
{
	return classid;
}
