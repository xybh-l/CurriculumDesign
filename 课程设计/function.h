#pragma once
#ifndef FUNCTION_H_
#define FUNCTION_H_
#include "others.h"
#include "Teacher.h"
#include "MenageSystem.h"
#include "StudentSystem.h"
#include "Global.h"
#include<iostream>
#include<fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

void Checkpwd(int choice);
void Menu();
void ReadTeacherFile();

#endif // !FUNCTION_H_
