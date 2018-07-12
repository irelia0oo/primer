#include "stdafx.h"
#include "strlearn.h"

void strlearn()
{
	strlearnA();
	
}


void strlearnA()
{
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