#pragma once
#include "stdafx.h"
#include <memory>

void strlearn();
void strlearnA();
int strlearnB();
void learnautoptr();
int xitifabulacc();
void vectorlear();
int getnumbers(int nowx, int nowy, int x, int y);

class report
{
private:
	std::string str;
public:
	report(const std::string s):str(s)
	{
		std::cout << "OBject Create!" << endl;
	}
	~report() { std::cout << "Object DeleteD!" << endl; }
	void comment()const { std::cout << str << endl; }
};