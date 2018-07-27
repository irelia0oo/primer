#pragma once

#include "stdafx.h"

#include <vector>//数组类的容器
#include <deque>//双端队列
#include <list>//双向链表
#include <queue>//适配器  priority_queue 另外一种适配器类
#include <forward_list>//单链表
#include <stack>//适配器 提供栈接口
#include <array>//
#include <set>//关联容器 set multiset
#include <map>//关联容易 map multimap
#include <algorithm>//STL算法 非修改式序列操作、修改式序列操作、排序
#include <numeric>//STL算法 通用数字算法
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