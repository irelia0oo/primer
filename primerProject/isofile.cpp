#include "stdafx.h"
#include "isofile.h"

using namespace std;

int rev(int);
int ShuZiFanZhuan();

int rev(int a)
{
	ostringstream os;//�����
	string s1,s2;
	int r = 0;

	os << a;
	s1 = os.str();//int ת�����ַ���
	copy(s1.rbegin(), s1.rend(), insert_iterator<string>(s2, s2.begin()));//��תs1������s2
	r = atoi(s2.c_str());//�ٰ�s2ת����int �����Ƿ�ת�õ�������
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