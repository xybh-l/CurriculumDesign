#pragma once
#ifndef MENAGESYSTEM_H_
#define MENAGESYSTEM_H_

#include<iostream>
#include<vector>
#include"Global.h"
using std::cout;
using std::cin;

void AddStudentInfo(int id, int num);
void QueryStudentInfo(int id);
void ModifyStudentInfo(int id);
void DeleteStudentInfo(int id);
void CheckPermission(int n);
void WirteTeacherFIle();


#endif // !MENAGESYSTEM_H_
