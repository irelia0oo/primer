#include "stdafx.h"
#include "rongqi.h"

const int LIM = 6;

void rongqi()
{
	rongqiset();
	rongqimulmap();
	funadap();
	//xingyunshu();
	strgstl1();
	YouXiRenWuRecord();
	usestl();
	useinitializerlist();
	xiti16();
}
typedef int keytype;
typedef std::pair<const keytype, std::string> Pair;
typedef std::multimap<keytype, std::string> MapCodes;


void JieJiuXiaoYi()
{
	return;
	int n;
	cin >> n;
	if (cin.fail() == true)
		exit(EXIT_FAILURE);
	vector<int> x(n);
	vector<int> y(n);
	int len = 0;
	int minlen = 99999;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> y[i];
	}
	for (int i = 0;i<x.size();i++)
	{
		len = abs(x[i] - 1) + abs(y[i] - 1);
		if (len < minlen)
			minlen = len;
	}
	cout << minlen << endl;
}



void CardFenZu()
{
	return;
	string cradid;
	//cin.getline(cradid,18);
	while (getline(cin, cradid))
	{
		//cradid.erase(std::remove(cradid.begin(),cradid.end(),' '), cradid.end());
		int length = static_cast<int>(cradid.length());
		for (int i = 0; i < length; i++)
		{
			if (cradid[i] == ' ')
				cradid.erase(cradid.begin() + i);
		}
		if (cradid.length() > 6)
			cradid.insert(cradid.begin() + 6, ' ');
		if (cradid.length() > 15)
			cradid.insert(cradid.begin() + 15, ' ');
		cout << cradid << endl;
	}
}
void rongqiset()
{
	return;
	using std::cout;
	using std::endl;
	const int n = 6;
	string s1[n] = { "buffoon","thinkers","for","heavy","can","for" };
	string s2[n] = { "metal","any","food","elegant","deliver","for" };

	set<string> a(s1, s1 + n);
	set<string> b(s2, s2 + n), c;

	ostream_iterator<string, char>out(cout, " ");
	cout << "Set A: ";
	copy(a.begin(), a.end(), out);
	cout << endl;
	cout << "Set B: ";
	copy(b.begin(), b.end(), out);
	cout << endl;

	set_union(a.begin(), a.end(), b.begin(), b.end(), out);
	cout << endl;
	set_intersection(a.begin(), a.end(), b.begin(), b.end(), out);
	cout << endl;
	set_difference(a.begin(), a.end(), b.begin(), b.end(), out);
	cout << endl;

	cout << "Set C: ";
	set_union(a.begin(), a.end(), b.begin(), b.end(), insert_iterator<set<string>>(c, c.begin()));
	for (auto x : c)cout << x << " ";
	cout << endl;

	string s3 = "grungy";
	c.insert(s3);
	copy(c.begin(), c.end(), out);
	cout << endl;
	copy(c.lower_bound("ghost"), c.upper_bound("spook"), out);
	cout << endl;
}
void rongqimulmap()
{
	return;
	using namespace std;

	MapCodes codes;
	codes.insert(Pair(415, "San Franciscon"));
	codes.insert(Pair(510, "Oakland"));
	codes.insert(Pair(718, "Brooklyn"));
	codes.insert(Pair(718, "Staten Island"));
	codes.insert(Pair(415, "San Rafael"));
	codes.insert(Pair(510, "Bearkeley"));

	cout << codes.count(415) << endl;
	cout << codes.count(510) << endl;
	cout << codes.count(718) << endl;
	cout << endl;
	MapCodes::iterator it;
	for (it = codes.begin(); it != codes.end(); ++it)
	{
		cout << (*it).first << " " << (*it).second << endl;;
	}
	cout << endl;
	pair<MapCodes::iterator, MapCodes::iterator> range = codes.equal_range(718);

	for (it = range.first;it != range.second;++it)
	{
		cout << (*it).first << " "<<(*it).second << endl;
	}
	cout << endl;
}

void funadap()
{
	return;
	using namespace std;
	double arr1[LIM] = { 28,29,30,35,38,59 };
	double arr2[LIM] = { 63,65,69,75,80,99 };
	vector<double> gr8(arr1, arr1 + LIM);
	vector<double> m8(arr2, arr2 + LIM);
	cout.setf(ios_base::fixed);
	cout.precision(1);
	for_each(gr8.begin(),gr8.end(),show);
	cout << endl;

	for_each(m8.begin(), m8.end(), show);
	cout << endl;

	vector<double> sum(LIM);
	transform(gr8.begin(),gr8.end(),m8.begin(),sum.begin(),plus<double>());
	for_each(sum.begin(), sum.end(), show);
	cout << endl;

	vector<double> pro(LIM);
	transform(gr8.begin(), gr8.end(), pro.begin(), bind1st(multiplies<double>(), 2.5));
	for_each(pro.begin(), pro.end(), show);
	cout << endl;
}

int xingyunshuf(int x)
{
	int s = 0;
	while (x > 0)
	{
		s = s + x % 10;
		x = static_cast<int>(x / 10);
	}
	return s;
}
int xingyunshug(int x)
{
	int s = 0;
	while (x > 0)
	{
		s = s + x % 2;
		x = static_cast<int>(x / 2);
	}
	return s;
}
int xingyunshu()
{
	int n;
	int sumnum = 0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		if (xingyunshuf(i) == xingyunshug(i))
			sumnum++;
	}
	cout << sumnum << endl;
	return 0;
}

void strgstl1()
{
	return;
	using namespace std;
	string letters;
	while (cin >> letters && letters != "zzz")
	{
		sort(letters.begin(), letters.end());
		cout << "==" << letters << endl;
		while (next_permutation(letters.begin(),letters.end()))
		{
			cout << "=="<<letters << endl;
		}
		cout << endl << "----------------" << endl;
	}
}
void YouXiRenWuRecord()
{
	return;
	unsigned int A[32];  //# 32个unsigned int类型
	unsigned int id1, id2;   //   #  输入，因为题干中说范围在[1, 1024]，因此我干脆就用unsigned int， 都用无符号处理，不用考虑符号位的影响，简单方便
	unsigned int tmp = 1;    //# 用于后面的移位
	while (cin >> id1 >> id2) {
		if (id1 > 1024 || id1 < 1 || id2 >1024 || id2 < 1) {
			cout << -1 << endl;
			continue;      // #输入不在范围内， - 1
		}
		int loc = (id1 - 1) >> 5;   //# 判断id1存在32个unsigned int中的哪一个，换句话说，一共有32个盒子，id1要落入哪一个盒子里。我们用 除以32 取商来得到， 而这一步可以通过位运算得到，十分高效。
		int inLoc = (id1 - 1) & 31; // # 上一步确定好落入哪一个盒子之后，我们需要进一步确定 id1在盒子里的具体位置，即 32个bit位中的哪一位。通过对32取余可以做到，等价为 用 & 31这个位运算。
		A[loc] = A[loc] | (tmp << inLoc);  // #确定好id1落入的具体位置， 我们需要将那一位标记为1， 此时用 或运算。
		if ((A[(id2 - 1) >> 5] & tmp << ((id2 - 1) & 31)) == tmp << ((id2 - 1) & 31))    //     # 同样的方式，我们需要确定好id2所在的具体位置，注意，此时是 与运算， 因为我们需要判断 那一位是否为1。
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}

}



string & ToLower(string & st)
{
	transform(st.begin(), st.end(), st.begin(), toLower);
	return st;
}
void display(const string & s)
{
	cout << s << " ";
}
void usestl()
{
	return;
	vector<string> words;
	string input;
	while (cin >> input && input != "exit")
	{
		words.push_back(input);
	}
	for (auto x : words)cout << x << ' ';
	cout << endl;

	set<string> wordset;
	transform(words.begin(), words.end(), insert_iterator<set<string>>(wordset, wordset.begin()), ToLower);
	for_each(wordset.begin(), wordset.end(), display);
	cout << endl;

	map<string, int> wordmap;
	set<string>::iterator si;
	for (si = wordset.begin();si != wordset.end();++si)
	{
		wordmap[*si] = static_cast<int>(count(words.begin(), words.end(), *si));
	}
	for (auto ci : wordset) cout << ci << " " << wordmap[ci] << endl;
}

void useinitializerlist()
{
	return;
	std::initializer_list<double> d1 = { 1.1,2.2,3.3,4.4,5.5 };
	cout << getinitializersum(d1) << endl;
	cout << getinitializerage(d1) << endl;
}


void xiti16()
{
	return;
	const long long nn = 1000000;
	vector<int> vi0;
	srand(static_cast<unsigned int>(time(NULL)));

	clock_t start = clock();
	int ran = 0;
	for (int i = 0; i < nn; ++i)
	{
		ran = rand();
		//cout << i << ' ' << ran << endl;
		vi0.push_back(ran);
	}
	clock_t end = clock();
	cout << end << "-" << start << "=" << end - start << endl;
	cout << static_cast<double>((end - start) / CLOCKS_PER_SEC) << endl;

	vector<int> vi1(nn);
	list<int> li(nn);
	copy(vi0.begin(), vi0.end(), li.begin());
	
	start = clock();
	//sort(li.begin(), li.end());
	li.sort();
	end = clock();
	cout << end << "-" << start << "=" << end - start << endl;
	cout << static_cast<double>((end - start) / CLOCKS_PER_SEC) << endl;

	li.clear();
	copy(vi0.begin(), vi0.end(), insert_iterator<list<int>>(li,li.begin()));
	//for (auto x : li) cout << x << ' ';
	start = clock();
	copy(li.begin(), li.end(), vi1.begin());
	sort(vi1.begin(), vi1.end());
	copy(vi1.begin(), vi1.end(), li.begin());
	end = clock();
	cout << end << "-" << start << "=" << end - start << endl;
	cout << static_cast<double>((end - start) / CLOCKS_PER_SEC) << endl;
	return;
	long ar[] = { 5,5,6,7,7,8,3,2,1,3,3 };
	cout << reduce(ar, static_cast<int>(size(ar))) << endl;

	string sr[] = { "aa","bb","cc","dd","dd","cc","bb","aa","ee" };
	cout << reduce(sr, static_cast<int>(size(sr))) << endl;

	char cr[] = { 'a','b','c','d','d','c','b','a' };
	cout << reduce(cr, static_cast<int>(size(cr))) << endl;
	return;
	string hw,wh;
	while (getline(cin,hw)  && hw != "exit" && hw != "")
	{
		cout << "===" << hw<<endl;
		for (auto pi = hw.begin(); pi != hw.end(); pi++)
		{
			if (!isalnum(*pi) && !isalpha(*pi))
			{
				hw.erase(pi);
				pi--;
			}
		}
		transform(hw.begin(), hw.end(), hw.begin(), tolower);

		if (wh.size())
			wh.clear();
		copy(hw.rbegin(), hw.rend(), insert_iterator<string>(wh, wh.begin()));
		//cout << hw << endl;
		//cout << wh << endl;
		if (hw == wh)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
}


