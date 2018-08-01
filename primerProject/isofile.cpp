#include "stdafx.h"
#include "isofile.h"

using namespace std;



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
	erjinzhiinandout();
	suijiduquwenjian();
	sstreamlearn();
	homewalk();
	newcharacter();
}

void reschflush()
{
	return;
	string filename;
	cin >> filename;
	ofstream fout(filename.c_str(), ios_base::out | ios_base::app);

	string sercrt;
	cin >> sercrt;
	fout << sercrt << endl;
	fout.close();
	fout.clear();

	ifstream fin(filename.c_str());
	fout.open("222.txt", ios_base::out | ios_base::app);
	if (!fin.is_open())
		exit(EXIT_FAILURE);
	char ch;
	while (fin.get(ch))
	{
		fout << ch;
	}
	fin.close();
}

void erjinzhiinandout()
{
	return;
	planet p1;
	cout << fixed << right;
	ifstream fin;
	fin.open(File, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		while (fin.read((char *) &p1,sizeof p1))
		{
			cout << setw(20) << p1.name
				<< setprecision(0) << setw(12) << p1.population
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		fin.close();
	}
	ofstream fout(File, ios_base::out | ios_base::app | ios_base::binary);
	if (!fout.is_open())
	{
		cerr << "can not open the " << File << " for output" << endl;
		exit(EXIT_FAILURE);
	}
	cin.get(p1.name, 20);
	while (p1.name[0] != '\0')
	{
		eatline();
		cin >> p1.population;
		cin >> p1.g;
		eatline();
		fout.write((char *)&p1, sizeof p1);
		cin.get(p1.name, 20);
	}
	fout.close();

	fin.clear();
	fin.open(File, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		while (fin.read((char *)&p1, sizeof p1))
		{
			cout << setw(20) << p1.name
				<< setprecision(0) << setw(12) << p1.population
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		fin.close();
	}
	cout << "======================" << endl;
}

void suijiduquwenjian()
{
	return;
	planet p1;
	cout << fixed;
	fstream finout;
	finout.open(File, ios_base::in | ios_base::out | ios_base::binary);
	int ct = 0;
	if (finout.is_open())
	{
		finout.seekg(0);
		while (finout.read((char *) & p1,sizeof p1))
		{
			cout << ct++ << setw(LIM) << p1.name << ":"
				<< setprecision(0) << setw(12) << p1.population
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		if (finout.eof())
			finout.clear();
		else
		{
			cerr << "error reading file :" << File << endl;
			exit(EXIT_FAILURE);
		}
	}
	else 
	{
		cerr << File << " can not be open!" << endl;
		exit(EXIT_FAILURE);
	}

	long rec;
	cin >> rec;
	eatline();
	if (rec < 0 )
	{
		cerr << "bye bye!" << endl;
		exit(EXIT_FAILURE);
	}
	if (rec > ct)
		rec = ct + 1;
	streampos place = rec * sizeof p1;//计算每个结构占据多少字节位置
	finout.seekg(place);
	if (finout.fail())
	{
		cerr << "seek a age";
		exit(EXIT_FAILURE);
	}

	finout.read((char *)& p1, sizeof p1);
	cout << rec << setw(LIM) << p1.name << ":"
		<< setprecision(0) << setw(12) << p1.population
		<< setprecision(2) << setw(6) << p1.g << endl;
	if (finout.eof())
		finout.clear();
	cin.get(p1.name, LIM);
	eatline();
	cin >> p1.population;
	cin >> p1.g;
	finout.seekp(place);
	finout.write((char *)& p1, sizeof p1) << flush;
	if (finout.fail())
	{
		cerr << "write a age";
		exit(EXIT_FAILURE);
	}



	ct = 0;
	finout.seekg(0);
	while (finout.read((char *)& p1, sizeof p1))
	{
		cout << ct++ << setw(LIM) << p1.name << ":"
			<< setprecision(0) << setw(12) << p1.population
			<< setprecision(2) << setw(6) << p1.g << endl;
	}
	if (finout.eof())
		finout.clear();
	else
	{
		cerr << "error reading file :" << File << endl;
		exit(EXIT_FAILURE);
	}
}
void sstreamlearn()
{
	return;
	string a = "ia asa fewr dcfs fdgfg rers ssd"
		"the wgfuus  sads aaa wdwd ";
	//getline(cin, a);
	istringstream in_str(a);
	string word;
	while (in_str >> word)
		cout << word << endl;
}
void homewalk()
{
	return;
	ofstream fout("mat.dat", ios_base::out | ios_base::app | ios_base::binary);
	string q;
	getline(cin, q);
	while (q[0] != '\0')
	{
		fout.seekp(ios_base::end);
		fout.write((char *)&q, sizeof q);
		getline(cin, q);
	}
	fout.close();

	ifstream fin;
	fin.open("mat.dat",ios_base::in|ios_base::binary);
	string p;
	set<string> sets;
	while (fin.read((char *)&p, sizeof p))
	{
		sets.insert(p);
	}
	for (auto x : sets)cout << x << endl;
}


void newcharacter()
{
	variadictemplate();
	return;
	baozhuangqifuntion();
	return;
	vector<int> a(1000);
	srand(static_cast<unsigned int>(time(NULL)));
	std::generate(a.begin(), a.end(), std::rand);
	auto mmo = [](int x) {return x % 3 == 0; };//Lambda
	__int64 counts = count_if(a.begin(), a.end(), mmo);
	cout << counts << endl;
}
void baozhuangqifuntion()
{
	double y = 1.21;
	cout << "   " << use_f(y, dub) << endl;
	cout << "   " << use_f(y, squre) << endl;
	cout << "   " << use_f(y, FP(5.0)) << endl;
	cout << "   " << use_f(y, FB(5.0)) << endl;
	cout << "   " << use_f(y, [](double u) {return u * u; }) << endl;
	cout << "   " << use_f(y, [](double u) {return u * u / 2.0; }) << endl;


	echo("use function the result is：\n");
	function<double(double)> ef1 = dub;
	function<double(double)> ef2 = squre;
	function<double(double)> ef3 = FP(10.0);
	function<double(double)> ef4 = FB(10.0);
	function<double(double)> ef5 = [](double u) {return u * u; };
	function<double(double)> ef6 = [](double u) {return u * u / 2.0; };
	cout << "   " << use_f(y, ef1) << endl;
	cout << "   " << use_f(y, ef2) << endl;
	cout << "   " << use_f(y, ef3) << endl;
	cout << "   " << use_f(y, ef4) << endl;
	cout << "   " << use_f(y, ef5) << endl;
	cout << "   " << use_f(y, ef6) << endl;
}

void variadictemplate()
{
	int n = 14;
	double x = 2.71828;
	string mr = "Mr.String objects!";
	show_list(n, x);
	show_list(x*x, '!', 7, mr);
}