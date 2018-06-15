
#include "stdafx.h"
#include "classmemory.h"

//using namespace std;
int stringbad::num_strings = 0;//���Ǹ��ӣ���̬���Ա����ǰҪ���� �����ƣ���������Ҫ�������ʼ��
stringbad::stringbad()
{
	len = 4;
	str = new char[len];
	strcpy_s(str, len, "c++");
	stringbad::num_strings++;
	cout << "��ʼ�� " << stringbad::num_strings << endl;
}

stringbad::stringbad(const char * s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	//std::strcpy(str, s);
	//std::strncpy(str, s, len);
	strcpy_s(str, len + 1, s);


	stringbad::num_strings++;

	cout << "����ֵ " << stringbad::num_strings << endl;
}
stringbad::stringbad(const stringbad & s)//���ƹ��캯�� һ���� ���캯��������new ��Ҫд������� ҲҪnew
{
	//*this = s;
	len = s.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, s.str);

	stringbad::num_strings++;
	cout << "����ֵ " << stringbad::num_strings << endl;
}
stringbad::~stringbad()
{
	stringbad::num_strings--;
	cout << "ɾ��ʱ " << str << " " << stringbad::num_strings << endl;
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
	os << "������ " << st.str << " " << st.len << " " << stringbad::num_strings << endl;
	return os;
}
void callme1(stringbad & rs)
{
	cout << "Call1 ������ " << rs;
}
void callme2(stringbad rs)
{
	cout << "Call2 ������ " << rs;
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