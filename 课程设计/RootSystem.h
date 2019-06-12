#pragma once

#include"MenageSystem.h"
#include"others.h"
#include<iostream>

using namespace std;
extern Teacher T[100];
extern int TeacherNumber;
void AddTeacherInfo(int num);
void QueryTeacherInfo();
void DeleteTeacherInfo();
void ModifyTeacherInfo();