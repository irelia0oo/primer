// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: 在此处引用程序需要的其他头文件
#include <cmath>
#include <limits.h>
#include <cfloat>
#include <cstring>
#include <string>
#include <vector>
#include <array>
#include <ctime>
#include <iso646.h>
#include <cctype>
#include <fstream>
#include <iostream>
#include <new>
using namespace std;

namespace myios
{
	template<typename any>
	void echo(any a, char c = '\n')
	{
		if ('\n' == c)
			std::cout << a << endl;
		else
			std::cout << a << " ";
	}
}
using namespace myios;
//using namespace tr1;
static int xitimaxnumber = 10;//作用域为当前文件的静态变量 可更改 (注：本条代码如果在函数内执行，则创建的是无链接性的局部变量)
const int xitibignumber = 10;//常量 只读属性 不可更改 如果extern const int xxx = 1; 则是全局常量

							 //const 全局常量，作用域当前文件，只读 不可修改
							 //volatile 很神奇的限定符，没用过

							 //auto 自动类型推断  相当于占位符 稍后再定义类型 可以和decltype配合使用
							 //register 寄存器变量 不太懂 没用过
							 //static 静态变量声明 可用于全局和局部 可以修改 
							 //extern 引用声明 引用其他cpp的全局变量
							 // thread_local
							 // mutable   结构或类 定义为常量，但是里面有用mutable的定义的变量，仍然可以修改，不收const影响


template<typename any1, typename any2>
auto leijia(any1 a, any2 b) -> decltype(a + b)
{
	return a + b;
}
template<class any1, class any2, class any3>
auto leijia(any1 a, any2 b, any3 c) -> decltype(a + b)
{
	return a + b + c;
}
void songsong(const char * name = "O.ma papa", int times = 6);

void xiti8();
void xiti8_1(const char *, int i = 1);

template<typename any>
any xiti8_2_1(any str)
{
	transform(str.begin(), str.end(), str.begin(), ::toupper);//把字符串转换为大写，transform 表示指向 str内的每一个字母，toupper表示转换大写
	return str;
}
template<typename any>
any xiti8_2_2(any str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);//把字符串转换为小写，transform 表示指向 str内的每一个字母，tolower表示转换小写
	return str;
}

template<typename any>
auto getarraylen(const any & a, int index = 0) -> decltype(sizeof(a) / sizeof(a[0]) - index)
{
	//cout << sizeof(a) << " " << sizeof(a[0]) << endl;
	//cout << a << endl;
	decltype(sizeof(a) / sizeof(a[0]) - index) x = (sizeof(a) / sizeof(a[0]) - index);
	return x;
}

template<typename any, typename any2>
void amx5(const any & a, any2 & temp)
{
	int b = 0;
	b = static_cast<int>(getarraylen(a));
	if (b <= 0)
	{
		temp = 0;
		return;
	}
	//cout << "b== " << b << endl;
	for (int i = 0; i < b; i++)
	{
		if (a[i] > temp)
			temp = a[i];
		//cout << "i==="<<i<<" "<<temp << endl;;
	}
	//return temp;
}


template<typename any>
inline auto xiti8_3(any & a, int i = 0) -> decltype(a[0] + a[1])
{
	if (i == 0)
		i = static_cast<int>(getarraylen(a));
	decltype(a[0] + a[1]) temp = 0;
	for (int j = 0; j < i; j++)
	{
		if (isdigit(a[j] == 0))//判断是否是数字，如果是返回非0的值，需要头文件ctype（isalpha判断是否字母，如果是返回非0）
			break;
		temp += a[j];
	}
	return temp;
}

int testststicint(int a);


void xiti9();

namespace jill
{
	int sorce = 125;
	char name[64] = "Irelia";
	void xiti9()
	{
		std::cout << "irelia not six" << std::endl;
	}
}
namespace jill
{
	template<typename any>
	void jillcout(any a)
	{
		std::cout << "====" << a << "====" << std::endl;
	}
	struct jillStruct
	{
		char name[64];
		mutable int sorce;
	};
}

struct  chaff
{
	char dross[20];
	int slag;
};


void xiticlass();
class stock
{
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_total()
	{
		total_val = shares * share_val;
	}
	enum
	{
		ownum = 3
	};
	static const int sellnum = 2;
	std::string ower[ownum];
	std::string seller[sellnum];
public:
	stock();
	stock(const string  cn, long number, double price);
	~stock();
	double GetTotal() { return total_val; }
	void acquire(const string & co, long n, double pr);
	void buy(long num, double price);
	void sell(long num, double price);
	void show() const;
	const stock & moreval(stock & t) const;
	stock * topnum(stock & s);
};



enum class cegg
{
	small,
	big,
	large
};
enum struct degg
{
	small,
	big,
	large
};

typedef unsigned long item;
class stack
{
private:
	static const int max = 10;
	item items[max];
	int top;
public:
	stack();
	~stack();
	bool isempty();
	bool isfull();
	bool push(const item & item);
	bool pop(item & item);
	void clear();
	void show();
};

void testclasszhan();

class betelgeusean
{
private:
	static const int max = 19;
	char name[max];
	int ci;
public:
	betelgeusean();
	betelgeusean(char * c, int a);
	~betelgeusean();
	void updateci(int);
	void show();
};

class timesa
{
private:
	int hour;
	int minutes;
public:
	timesa();
	timesa(int, int);
	~timesa();
	void addtime(int, int m = 0);
	timesa sum(timesa &) const;
	timesa operator+(const timesa &) const;//最后面这个 const 表示 this指针也是const类型
										   // 调用格式 a.operator+(b)  或者 a + b

	timesa operator-(const timesa &) const; //重载运算符 -
	timesa operator-();
	timesa operator--();
	timesa operator++();
	timesa operator*(int n) const;
	//friend timesa operator*(int n, const timesa & a);//友元函数,它不属于 成员函数

	//friend void operator<<(ostream & os,const timesa & a);
	friend ostream & operator<<(ostream & os, const timesa & a);//通过友元函数重载<<字符，就可以 直接 cout << timesa了
	friend istream & operator>>(istream & is, timesa & a);//可以直接cin>>输入数据
	void show();
};
timesa operator*(int n, const timesa & a);//函数内直接使用 a.operator*(n) 进行运算，就不需要友元了


void xiti11();

class Stonewt
{
private:
	enum { Lbs_per_stn = 14 };
	int stone;
	double pds_left;
	double pounds;
public:
	Stonewt();
	Stonewt(double lbs);
	Stonewt(int stn, double lbs);
	~Stonewt();
	void show_lbs() const;
	void show_stm() const;
};
string getTime();
string getTime2();

