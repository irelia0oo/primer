#pragma once

#include "stdafx.h"
#include <cstdlib>
//#include <string1.h>
using namespace std;

void xiti12();

class stringbad
{
private:
	char * str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	stringbad();
	stringbad(const char * s);
	stringbad(const stringbad & s);
	~stringbad();
	friend std::ostream & operator<<(std::ostream & os, const stringbad & st);
	friend std::istream & operator>>(std::istream & is, stringbad & st);
	friend bool operator<(const stringbad & a, const stringbad & b);
	friend bool operator>(const stringbad & a, const stringbad & b);
	friend bool operator==(const stringbad & a, const stringbad & b);
	char & operator[](int i);
	const char & operator[](int i) const;
	int length()const { return len; }
	stringbad & operator=(const stringbad & s);
	stringbad & operator=(const char *);
	static int howmanay();
	//void callme();
};

void callme1(stringbad & rs);
void callme2(stringbad rs);

const int ArSize = 10;
const int Maxlen = 81;