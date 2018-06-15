#pragma once

#include "stdafx.h"

using namespace std;

void xiti12();

class stringbad
{
private:
	char * str;
	int len;
	static int num_strings;
public:
	stringbad();
	stringbad(const char * s);
	stringbad(const stringbad & s);
	~stringbad();
	friend std::ostream & operator<<(std::ostream & os,const stringbad & st);
	stringbad operator=(const stringbad & s);
	//void callme();
};

void callme1(stringbad & rs);
void callme2(stringbad rs);