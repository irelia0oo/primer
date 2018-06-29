#include "stdafx.h"
#include "codereuse.h"


void codereuse_classmode()
{
	codereuse_classmode_student2();
	return;
	codereuse_classmode_student();
	return;
	valarray<double> weight = { 2.5,3.4,11,225.1,0.11,22 };
	for (int i = 0; i < weight.size(); i++)
	{
		cout << weight[i] << " ";
	}
	cout << endl;
	cout << weight.size() << endl;
	cout << weight.sum() << endl;
	cout << weight.max() << endl;
	cout << weight.min() << endl;

	int y[3] = { 1,2,3 };
	valarray<int>  pvint(y, 3);
	cout << endl;
	cout << pvint.size() << endl;
	cout << pvint.sum() << endl;
	cout << pvint.max() << endl;
	cout << pvint.min() << endl;
}

void codereuse_classmode_student()
{
	//student * ada = new student[publics]{ student(quizees) ,student(quizees) ,student(quizees) };
	student ada[publics] = { student(quizees) ,student(quizees) ,student(quizees) };
	int i = 0;
	for (i = 0; i < publics; i++)
	{
		setstudent(ada[i], quizees);
	}
	cout << endl << "The student list:" << endl;
	for (i = 0; i < publics; i++)
	{
		cout << ada[i].Name() << " ";
	}
	cout << endl;
	cout << endl;

	for (i = 0; i < publics; i++)
	{

		cout << ada[i];
		cout << "anearge:" << ada[i].average() << endl << endl;
	}
	cout << "bye bye" << endl;
	return;
}
void setstudent(student & sa, int n)
{
	cout << "Enter Student Name:" << endl;
	getline(cin, sa);
	cout << "Enter " << n << " sorce" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> sa[i];
	}
	while (cin.get() != '\n')
	{
		continue;
	}
	cout << endl;
}
ostream & student::arr_out(ostream & os) const
{
	int size = scores.size();
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			os << scores[i] << " ";
			if (i % 5 == 4)
				os << endl;
		}
	}
	else
		os << "Scores is emptry" << endl;
	return os;
}

double student::average() const
{
	if (scores.size() > 0)
		return scores.sum() / scores.size();
	else
		return 0;
}
const string & student::Name()const
{
	return name;
}
double & student::operator[](int i)
{
	return scores[i];
}
double student::operator[](int i) const
{
	return scores[i];
}
istream & operator>>(istream & is, student &stu)
{
	is >> stu.name;
	return is;
}
istream & getline(istream & is, student &stu)
{
	getline(is, stu.name);
	return is;
}
ostream & operator<<(ostream & os, student &stu)
{
	os << "Name:" << stu.name << endl;
	stu.arr_out(os);
	return os;
}



void codereuse_classmode_student2()
{

	return;
}