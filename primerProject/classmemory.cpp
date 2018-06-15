
#include "stdafx.h"
#include "classmemory.h"

//using namespace std;
int stringbad::num_strings = 0;//这是个坑，静态类成员引用前要加上 类名称：：，并且要在外面初始化
stringbad::stringbad()
{
	len = 4;
	str = new char[len];
	strcpy_s(str, len, "c++");
	stringbad::num_strings++;
	cout << "初始化 " << stringbad::num_strings << endl;
}

stringbad::stringbad(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	//std::strcpy(str, s);
	//std::strncpy(str, s, len);
	strcpy_s(str, len + 1, s);


	stringbad::num_strings++;

	cout << "设置值 " << stringbad::num_strings << endl;
}
stringbad::stringbad(const stringbad & s)//复制构造函数 一个坑 构造函数里用了new 就要写这个函数 也要new
{
	//*this = s;
	len = s.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, s.str);

	stringbad::num_strings++;
	cout << "复制值 " << stringbad::num_strings << endl;
}
stringbad::~stringbad()
{
	stringbad::num_strings--;
	cout << "删除时 " << str << " " << stringbad::num_strings << endl;
	delete[] str;
}

stringbad stringbad::operator=(const stringbad & s)
{
	this->len = s.len;
	this->num_strings = s.num_strings;
	this->str = s.str;

	return (*this);
}

std::ostream & operator<<(std::ostream & os, const stringbad & st)
{
	os << "输出结果 " << st.str << " " << st.len << " " << stringbad::num_strings << endl;
	return os;
}
void callme1(stringbad & rs)
{
	cout << "Call1 输出结果 " << rs;
}
void callme2(stringbad rs)
{
	cout << "Call2 输出结果 " << rs;
}

void xiti12()
{
	//stringbad sb ;
	//sb = stringbad("aabbba");

	//return;
	stringbad sb1 = { "sb1sb1sb1sb1sb1sb1" };
	/*stringbad sb2 = { "sb2sb2sb2sb2sb2sb2" };
	stringbad sb3 = { "sb3sb3sb3sb3sb3sb3" };
	stringbad sports = { "sb3sb3sb3sb3sb3sb3" };

	cout << "sb1:" << sb1 << endl;
	cout << "sb2:" << sb2 << endl;
	cout << "sports:" << sports << endl;

	callme1(sb1);
	cout << "sb1:" << sb1 << endl;*/
	//callme2(sb2);
	//cout << "sb2:" << sb2 << endl;

	
	stringbad sport = sb1;
	cout << "sport:" << sport << endl;

	//stringbad badsb;
	//badsb = sb1;
	//cout << "badsb:" << badsb << endl;
}