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
#include <functional>

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
void sstreamlearn();
void homewalk();
void newcharacter();
void baozhuangqifuntion();
double dub(double x);
double squre(double);
void variadictemplate();

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

class  FB
{
private:
	double z;
public:
	FB(double zz = 1.0) :z(zz) {}
	double operator()(double p) { return z * p; }
};

class FP
{
private:
	double z;
public:
	FP(double zz = 1.0) :z(zz) {}
	double operator()(double b) { return z * b; }
};
inline double dub(double x) { return x * 2.0; }
inline double squre(double x) { return x * x; }


template<typename T,typename F>
T use_f(T v, F f)
{
	static int couts = 0;
	couts++;
	cout << "use_f " << couts << " " << &couts << endl;
	return  f(v);
}

template<typename any>
void show_list(const any & value)
{
	cout << value << endl;
}

template<typename any, typename... Args> 
void show_list(const any& value, const Args&... args)
{
	//չ��������
	cout << value << ' ';
	if (sizeof...(args) > 0)
		show_list(args...);
}