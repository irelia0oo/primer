#pragma once
#include "stdafx.h"
#include <sstream>
#include <set>//关联容器 set multiset
#include <map>//关联容易 map multimap
#include <algorithm>//STL算法 非修改式序列操作、修改式序列操作、排序
#include <numeric>//STL算法 通用数字算法
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