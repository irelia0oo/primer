#pragma once
#include "stdafx.h"
#include <sstream>
#include <set>//�������� set multiset
#include <map>//�������� map multimap
#include <algorithm>//STL�㷨 ���޸�ʽ���в������޸�ʽ���в���������
#include <numeric>//STL�㷨 ͨ�������㷨
#include <iterator>
#include <iomanip>

#include <fstream>


void fileliearn();
int rev(int);
int ShuZiFanZhuan();
void HaoWeiLai();
void ShuChuan();
bool getmaxstr(const string a, const string b);
void reschflush();
void eatline();
void erjinzhiinandout();
void suijiduquwenjian();

inline void eatline()
{
	while (std::cin.get() != '\n')
		continue;
}
struct planet
{
	char name[20];
	double population;
	double g;
};
static const char * File = "planets.dat";
static const int LIM = 20;