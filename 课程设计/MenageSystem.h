#pragma once
#ifndef MENAGESYSTEM_H_
#define MENAGESYSTEM_H_

#include<iostream>
#include"Global.h"
using std::cout;
using std::cin;

void AddStudentInfo(int id, int num);
void QueryStudentInfo(int id);
//void ModifyStudentInfo();
//void DeleteStudentInfo();
void CheckPermission(int n);


#endif // !MENAGESYSTEM_H_
