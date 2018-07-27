#include "stdafx.h"
#include "isofile.h"

using namespace std;

int rev(int);
int ShuZiFanZhuan();

int rev(int a)
{
	ostringstream os;//输出流
	string s1,s2;
	int r = 0;

	os << a;
	s1 = os.str();//int 转换成字符串
	copy(s1.rbegin(), s1.rend(), insert_iterator<string>(s2, s2.begin()));//反转s1，存入s2
	r = atoi(s2.c_str());//再把s2转换成int ，就是反转好的数字了
	return r;
}
int ShuZiFanZhuan()
{
	int a, b;
	cin >> a >> b;
	cout << rev(rev(a) + rev(b)) << endl;
	return 0;
}
void fileliearn()
{
	ShuZiFanZhuan();
}