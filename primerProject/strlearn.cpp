#include "stdafx.h"
#include "strlearn.h"

void strlearn()
{
	strlearnA();
	strlearnB();
	learnautoptr();
	vectorlear();
	learingstl();
}


void strlearnA()
{
	return;
	string one("Lottey winner!");
	cout << one << endl;
	string two(20, '$');
	cout << two << endl;
	string three(one);
	cout << three << endl;
	one += "0ops";
	cout << one << endl;
	two = "Sorry!That Was ";
	three[0] = 'p';
	string four;
	four = two + three;
	cout << four << endl;
	char alls[] = "All's well that ends well.";
	string five(alls, 20);
	cout << five << endl;
	string six(alls + 6, alls + 10);
	cout << six << ",";
	string seven(&five[6], &five[10]);
	cout << seven << "..." << endl;
	string eight(four, 7, 16);
	cout << eight << endl;


	//string lname1, lname2, lname3;
	//cin >> lname1;
	//getline(cin,lname2, '.');
	//getline(cin, lname3,' ');
	//cout << lname1 << endl;
	//cout << lname2 << endl;
	//cout << lname3 << endl;

	ifstream fin;
	fin.open("111.txt");
	if (fin.is_open() == false)
	{
		cout << "The Txt File Can Not OPen." << endl;
		exit(EXIT_FAILURE);
	}
	string item;
	int counts = 0;
	getline(fin, item, ':');
	while (fin)
	{
		counts++;
		cout << counts << ":" << item << endl;
		getline(fin, item, ':');
	}
	cout << "byebye" << endl;
	fin.close();
}


int strlearnB()
{
	return 0;
	int  a[3][2] = { 0 }, (*ptr)[2], i, j;
	for (i = 0; i < 2; i++)
	{
		ptr = a + i;
		scanf_s("%d", ptr);
		ptr++;
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
			printf("%2d", a[i][j]);
		printf("\n");
	}
	return 0;
	string text;
	getline(cin, text, '\n');
	//cout << text.find("Irelia", 0);
	//cout << text.find("I", 0);
	cout << text.capacity() << endl;
	text.reserve(text.capacity() * 2);
	cout << text.capacity() << endl;

	return 0;
}

void learnautoptr()
{
	return;
	std::auto_ptr<report> ps{ new report("using auto_ptr") };
	ps->comment();
	
	std::shared_ptr<report> pr{ new report("using shared_ptr") };
	pr->comment();

	std::unique_ptr<report> pz{ new report("using unique_ptr") };
	pz->comment();

	auto_ptr<int> f[5] =
	{
		auto_ptr<int>(new int(1)),
		auto_ptr<int>(new int(2)),
		auto_ptr<int>(new int(3)),
		auto_ptr<int>(new int(4)),
		auto_ptr<int>(new int(5))
	};
	shared_ptr<int> fm;

	//fm = f[2];

	for (int i = 0; i < 5; i++)
	{
		cout << *f[i] << endl;
	}
	//cout << *fm << endl;
	//cout << xitifabulacc() << endl;
	return;
}

int xitifabulacc()
{
	int n, klastone, klasttwo, know,k;
	cin >> n;
	klastone = 2;
	klasttwo = 1;
	know = 3;
	k = 0;
	if (n <= 3)
		return 0;
	do 
	{
		klasttwo = klastone;
		klastone = know;
		know = klastone + klasttwo;
	} while (klastone < n);

	k = klastone - n;
	if (n - klasttwo < k)
		k = n - klasttwo;
	return k;
}



int getnumbers(int nowx, int nowy, int x, int y)
{
	int number = 0;
	if (nowx == x)
		number = 1;
	else if (nowy == y)
		number = 1;
	else number = getnumbers(nowx++, nowy, x, y) + getnumbers(nowx, nowy++, x, y);

	printf("nowx ==%d nowy==%d numbers==%d\n", nowx, nowy, number);
	return number;
}
void showvector(int pr)
{
	std::cout << pr << endl;
}
bool comparesize(const int a, const int b)
{
	if (a < b)
		return false;
	else
		return true;
}
void vectorlear()
{
	return;
	int x = 0, y = 5, z = 3;
	while (z-- > 0 && ++x < 5)
	{
		y = y - 1;
	}
	printf("%d  %d  %d", x, y, z);
	return;
	vector<int> vc(10);
	for (int i = 0; i < 10; i++)
	{
		vc[i] = i;
	}
	//for each(vc.begin(),vc.end(), showvector);
	for (int pr : vc) showvector(pr);//c++11的新特性 基于范围的for循环

	random_shuffle(vc.begin(), vc.end());//随机排序
	for (int i = 0; i < vc.size(); i++)
	{
		cout << vc[i] << " ";
	}
	cout << endl << endl;

	sort(vc.begin(), vc.end());//从小到大 升序排序
	for (int i = 0; i < vc.size(); i++)
	{
		cout << vc[i] << " ";
	}
	cout << endl << endl;

	sort(vc.begin(), vc.end(), comparesize);//从大到小，反向排序
	for (int i = 0; i < vc.size(); i++)
	{
		cout << vc[i] << " ";
	}
	cout << endl << endl;
	return;
	int n;
	cin >> n;
	vector<int> scores(n);
	scores[0] = 99;
	for (int i = 0; i < n; i++)
	{
		cout << scores[i] << " ";
	}
	cout << endl;
	auto pd = scores.end() - 1;
	cout << scores.size() << "  " << *pd << endl;

	scores.push_back(n*n);
	cout << scores.size() << "  " << (*(scores.end() - 1)) << endl;

	scores.erase(scores.begin(), scores.begin() + 3);
	for (int i = 0; i < scores.size(); i++)
	{
		cout << scores[i] << " ";
	}
	cout << endl << endl;
	vector<int> ss2(2);
	ss2[0] = 527966;
	ss2[1] = 527966;
	ss2.insert(ss2.begin() + 1, scores.begin(), scores.end());
	for (int i = 0; i < ss2.size(); i++)
	{
		cout << ss2[i] << " ";
	}
	cout << endl;
	
	return;
	FILE *fp;
	int i, a[6] = { 1,2,3,4,5,6 }, k;
	fopen_s(&fp,"data.dat", "w+b");
	for (i = 0; i < 6; i++)
	{
		fseek(fp, 0L, 0);
		fwrite(&a[ 5 - i], sizeof(int), 1, fp);
	}
	rewind(fp);
	fread(&k, sizeof(int), 1, fp);
	fclose(fp);
	printf("%d", k);

	
	return;
	int count = 0;
	int x1, y1;
	cin >> x1 >> y1;
	count = getnumbers(0, 0, x1, y1);
	cout << count << endl;

	return;

}

void learingstl()
{
	vector<int> vc(10);
	for (int i = 0; i < 10; i++)
	{
		vc[i] = i;
	}
	
	vector<int>::iterator pr;
	for (pr = vc.begin(); pr != vc.end(); pr++)
	{
		cout << *pr << " ";
	}
	cout << endl;
	for (auto pl = vc.begin(); pl != vc.end(); pl++)
	{
		cout << *pl << " ";
	}
	cout << endl;
	for (auto x : vc) cout << x << " ";
	cout << endl;
}