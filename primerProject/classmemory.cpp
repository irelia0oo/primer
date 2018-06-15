
#include "stdafx.h"
#include "classmemory.h"

//using namespace std;
int stringbad::num_strings = 0;//这是个坑，静态类成员引用前要加上 类名称：：，并且要在外面初始化
stringbad::stringbad()
{
	len = 4;
	str = new char[len];
	strcpy_s(str, 3, "c++");
	stringbad::num_strings++;
	cout << stringbad::num_strings << endl;
}

stringbad::stringbad(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	//std::strcpy(str, s);
	//std::strncpy(str, s, len);
	strcpy_s(str, len+1,s);


	stringbad::num_strings++;

	cout << stringbad::num_strings << endl;
}
stringbad::~stringbad()
{
	cout << str << " " << stringbad::num_strings << endl;
	stringbad::num_strings--;
	delete[] str;
}
std::ostream & operator<<(std::ostream & os, const stringbad & st)
{
	os << st.str << " " << st.len << " " << stringbad::num_strings << endl;
	return os;
}



void xiti12()
{
	//stringbad sb;
	//stringbad::stringbad("123asa");
}