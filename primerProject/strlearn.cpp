#include "stdafx.h"
#include "strlearn.h"

void strlearn()
{
	strlearnA();
	strlearnB();
	learnautoptr();
	vectorlear();
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
void vectorlear()
{
	vector<int> rating(5);
	int n;
	cin >> n;
	vector<double> scores(n);
}