#include "stdafx.h"
#include "isofile.h"

using namespace std;



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
	return 0;
	int a, b;
	cin >> a >> b;
	cout << rev(rev(a) + rev(b)) << endl;
	return 0;
}
void HaoWeiLai()
{
	return;
	vector<int> vs;
	int num;
	while (cin.get() != '\n' && cin >> num)
	{
		vs.push_back(num);
	}
	set<int> sets;
	map<int, int> maps;
	copy(vs.begin(), vs.end(), insert_iterator<set<int>>(sets, sets.begin()));

	for (set<int>::iterator pr = sets.begin(); pr != sets.end(); pr++)
	{
		maps[*pr] = static_cast<int>(count(vs.begin(), vs.end(), *pr));
	}
	int result, couts = 0;
	for (auto ps = sets.begin(); ps != sets.end(); ps++)
	{
		//cout << *ps << " " << maps[*ps] << endl;
		if (maps[*ps] > couts)
		{
			result = *ps;
			couts = maps[*ps];
		}
	}
	cout << result << endl;
}
bool getmaxstr(const string a, const string b)
{
	return a + b > b + a;
}
void ShuChuan()
{
	return;
	int n, c;
	while (cin >> n)
	{
		vector<string> b;
		string s;
		for (int i = 0; i < n; i++)
		{
			cin >> c;
			ostringstream os;
			os << c;
			s = os.str();
			b.push_back(s);
		}
		sort(b.begin(), b.end(), getmaxstr);
		for (auto p = b.begin(); p != b.end(); p++)
		{
			cout << *p;
		}
		cout << endl;

	}
	return ;
}
void fileliearn()
{
	ShuZiFanZhuan();
	HaoWeiLai();
	ShuChuan();
	reschflush();
}

void reschflush()
{
	//cout << "aaaaaa";
	double n;
	cin >> n ;
	flush(cout);//ˢ�»�����
	hex(cout);//16�������
	cout << n << endl;
	oct(cout);//8�������
	cout << n << endl;
	cout << dec;//ʮ�������
	cout << n << endl;
	cout.width(20);//����������
	cout << n << endl;
	cout.fill('*');//����ַ�
	cout.width(20);
	cout << n << endl;
	cout.width(20);
	cout.precision(2);//���þ���Ϊ10λ
	cout << n << endl;
	cout.setf(ios_base::showpoint);//��ʾĩβ��С����
	cout.precision(10);
	cout << n << endl;
	cout.setf(ios_base::showbase);//���ʹ��C++6.0��ǰ׺ 0 0x
	cout.setf(ios_base::showpos);//����ǰ���� +
	cout << n << endl;
}