#pragma once

#include "stdafx.h"

#include <vector>//�����������
#include <deque>//˫�˶���
#include <list>//˫������
#include <queue>//������  priority_queue ����һ����������
#include <forward_list>//������
#include <stack>//������ �ṩջ�ӿ�
#include <array>//
#include <set>//�������� set multiset
#include <map>//�������� map multimap
#include <algorithm>//STL�㷨 ���޸�ʽ���в������޸�ʽ���в���������
#include <numeric>//STL�㷨 ͨ�������㷨
#include <iterator>
#include <functional>

void rongqi();
void JieJiuXiaoYi();
void CardFenZu();
void rongqiset();
void rongqimulmap();
void funadap();
void show(double);
int xingyunshuf(int x);
int xingyunshug(int x);
int xingyunshu();
void strgstl1();
void YouXiRenWuRecord();
void usestl();
string & ToLower(string & st);
void display(const string & s);
void useinitializerlist();
double getinitializersum(std::initializer_list<double> il);
double getinitializerage(std::initializer_list<double> il);
void xiti16();


inline void show(double v)
{
	std::cout.width(6);
	cout << v << ' ';
}

char toLower(char ch);

inline char toLower(char ch)
{
	return tolower(ch);
}

inline double getinitializersum(std::initializer_list<double> il)
{
	double sum = 0;
	for (auto x : il)sum += x;
	return sum;
}
inline double getinitializerage(std::initializer_list<double> il)
{
	if (il.size())
		return getinitializersum(il) / il.size();
	else
		return 0.0;
}

template<typename T>
int reduce(T ar[], int n)
{
	set<T> p(ar, ar + n);
	return static_cast<int>(n - p.size());
}