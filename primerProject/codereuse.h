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
private:
	typedef std::valarray<double> ArrayDB;
	std::ostream & arr_out(std::ostream & os) const;
public:
	student2() :std::string("null student"), ArrayDB() {}
	explicit student2(const string & str) : std::string(str), ArrayDB() {}
	explicit student2(int n) : std::string("nullly"), ArrayDB(n) {}
	student2(const string & str, int n) :std::string(str), ArrayDB(n) {}
	student2(const string & str, const ArrayDB & a) : std::string(str), ArrayDB(a) { }
	student2(const string & str, double * pd, int n) : std::string(str), ArrayDB(pd, n) {}
	~student2(){}
	double avearge()const;
	double & operator[](int i);
	double operator[](int i) const;
	const std::string & Name() const;
	friend std::istream & operator>>(std::istream & is, student2 & stu);
	friend std::istream & getline(std::istream & is, student2 & stu);
	friend std::ostream & operator<<(std::ostream & os, const student2 & stu);
	using ArrayDB::min;
	using std::valarray<double>::max;
	using std::valarray<double>::size;
	using std::valarray<double>::sum;
};

void setstudent2(student2 & sa, int n);
void niukeprogram();

class worker
{
private:
	string name;
	int year;
public:
	worker(string n = "null",int y = 0):name(n), year(y) {}
	worker(const worker & w):name(w.name),year(w.year){}
	virtual ~worker(){}
	virtual void show() { cout << name << " ," << year << "  year old." << endl; }
	virtual void set(int y) { year = y; }
};
class sing : public worker
{
private:
	string song;
	int songtime;
public:
	sing(string s = "none",int st = 0, string n = "null", int y = 0):worker(n,y),song(s),songtime(st){}
	sing(const sing & w) :worker(w),song(w.song), songtime(w.songtime) {}
	sing(const worker & w, string s, int st):worker(w), song(s), songtime(st){}
	virtual ~sing(){}
	virtual void show() { cout <<"The sing is "<< song << " ," << songtime << endl; }
	virtual void set(int y) { songtime = y; }
};

class waiter : public worker
{
protected:
	enum {other,alto,contralto,soprano,bass,bratione,tenor};
	enum { valtype = 7 };
private:
	//string pv[valtype] = { "asd","asd","asd","asd","asd","asd","asd" };
	static string pv[valtype];
public:
	waiter(const worker & w):worker(w){}
	waiter(string n = "null", int y = 0) :worker(n,y) {}
	waiter(const waiter & w) :worker(w) {}
	virtual ~waiter(){}
	virtual void show() { cout << pv[1] << endl; }
};


template<class type>
class tack
{
private:
	enum { max = 30};
	type t[max];
	int top;
public:
	tack();
	bool isempty() { return top == 0; }
	bool isfull() { return top == max; }
	bool push(const type & i);
	bool pop(type & i);
	void show();
};
template<class type>
tack<type>::tack()
{
	top = 0;
}
template<class type>
bool tack<type>::push(const type & i)
{
	if (top < max)
	{
		t[top] = i;
		top++;
		return true;
	}
	return false;
}
template<class type>
bool tack<type>::pop(type & i)
{
	if (top > 0)
	{
		top--;
		i = t[top];
		return true;
	}
	return false;
}
template<class type>
void tack<type>::show()
{
	if (top <= 0)
	{
		cout << "the array is empty!" << endl;
		return;
	}
	for (int i = 0;i <top;i++)
	{
		cout << t[i] << " ";
	}
	cout << endl;
}