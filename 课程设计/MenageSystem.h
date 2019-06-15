#pragma once
#ifndef MENAGESYSTEM_H_
#define MENAGESYSTEM_H_

#include<iostream>
#include<vector>
#include<Windows.h>
#include"Student.h"
using std::cout;
using std::cin;
using std::sort;

void ROOT();
void QueryStudentInfo();
void ModifyStudentInfo();
void DeleteStudentInfo();
void AddStudentInfo(int id, int num);
void AddStudentInfo(int num);
void QueryStudentInfo(int id);
void QueryStudentInfo();
void ModifyStudentInfo(int id);
void DeleteStudentInfo(int id);
void CheckPermission(int n);
void WirteTeacherInfo();
void SortRank(Student& s);

#endif // !MENAGESYSTEM_H_
