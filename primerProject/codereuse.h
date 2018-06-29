#pragma once
#include "stdafx.h"
#include <valarray>

using namespace std;

void codereuse_classmode();
void codereuse_classmode_student();

const int publics = 3;
const int quizees = 5;

class student
{
private:
	typedef valarray<double> ArrayDB;
	string name;
	ArrayDB scores;
	ostream & arr_out(ostream & os) const;
public:
	student() : name("null student"),scores(0) {}
	explicit student(const string & s) : name(s),scores(0) {}
	explicit student(int n) : name("null student"),scores(n) {}
	student(const string & s,int n) : name(s),scores(n) {}
	student(const string & s,const ArrayDB & a) : name(s),scores(a) {}
	student(const char * s,const double * p,int n) : name(s),scores(p,n) {}
	~student(){}
	double average() const;
	const string & Name()const;
	double & operator[](int i);
	double operator[](int i) const;
	friend istream & operator>>(istream & is, student &stu);
	friend istream & getline(istream & is, student &stu);
	friend ostream & operator<<(ostream & os, student &stu);
};


void setstudent(student & sa, int n);

void codereuse_classmode_student2();
class student2 : private string, private valarray<double>
{

};