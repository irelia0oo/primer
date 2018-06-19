
#include "stdafx.h"
#include "classmemory.h"

//using namespace std;
int stringbad::num_strings = 0;//这是个坑，静态类成员引用前要加上 类名称：：，并且要在外面初始化
stringbad::stringbad()
{
	len = 0;
	str = new char[len + 1];
	//strcpy_s(str, len, "c++");
	str[0] = '\0';
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
int stringbad::howmanay()
{
	return stringbad::num_strings;
}
stringbad & stringbad::operator=(const stringbad & s)
{
	if (this == &s)
		return *this;
	delete[] str;

	this->len = s.len;
	this->str = new char[this->len + 1];
	strcpy_s(this->str, this->len + 1, s.str);
	//this->num_strings++;

	//cout << "赋值1 " << str << " " << stringbad::num_strings << endl;
	return *this;
}

stringbad & stringbad::operator=(const char * ch)
{
	delete[] str;
	this->len = std::strlen(ch);
	this->str = new char[this->len + 1];
	strcpy_s(this->str, this->len + 1, ch);
	//stringbad::num_strings++;

	//cout << "赋值2 " << str << " " << stringbad::num_strings << endl;
	return *this;
}

char & stringbad::operator[](int i)
{
	return this->str[i];
}
const char & stringbad::operator[](int i) const
{
	return this->str[i];
}

bool operator<(const stringbad & a, const stringbad & b)
{
	return (std::strcmp(a.str, b.str) < 0);
}
bool operator>(const stringbad & a, const stringbad & b)
{
	return (std::strcmp(a.str, b.str) > 0);
}
bool operator==(const stringbad & a, const stringbad & b)
{
	return (std::strcmp(a.str, b.str) == 0);
}

std::ostream & operator<<(std::ostream & os, const stringbad & st)
{
	os << "输出结果 " << st.str << " " << stringbad::num_strings << endl;
	return os;
}
std::istream & operator>>(std::istream & is, stringbad & st)
{
	char temp[stringbad::CINLIM];
	is.get(temp, stringbad::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
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
	//stringbad sb1 = { "sb1sb1sb1sb1sb1sb1" };
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


	//stringbad sport = sb1;
	//cout << "sport:" << sport << endl;
	//cout << (bool)(sport == sb1) << endl;
	//stringbad badsb;
	//badsb = sb1;
	//cout << "badsb:" << badsb << endl;

	stringbad c1, c2;
	c2 = "aabbcc";
	c1 = c2;
	cout << c1 << " " << c2 << endl;

	stringbad s1;
	cin >> s1;
	cout << s1;
	cout << int(stringbad::howmanay());
}