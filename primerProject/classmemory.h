#pragma once

#include "stdafx.h"
#include <cstdlib>
#include<new>
//#include <string1.h>
using namespace std;

void xiti12();

class stringbad
{
private:
	char * str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
public:
	stringbad();
	stringbad(const char * s);
	stringbad(const stringbad & s);
	~stringbad();
	friend std::ostream & operator<<(std::ostream & os, const stringbad & st);
	friend std::istream & operator>>(std::istream & is, stringbad & st);
	friend bool operator<(const stringbad & a, const stringbad & b);
	friend bool operator>(const stringbad & a, const stringbad & b);
	friend bool operator==(const stringbad & a, const stringbad & b);
	char & operator[](int i);
	const char & operator[](int i) const;
	int length()const { return len; }
	stringbad & operator=(const stringbad & s);
	stringbad & operator=(const char *);
	static int howmanay();
	//void callme();
};

void callme1(stringbad & rs);
void callme2(stringbad rs);

const int ArSize = 10;
const int Maxlen = 81;


void xiticlassputr();
void class_fifo();

const int BUF = 512;
class JustTesting
{
private:
	string words;
	int number;
public:
	JustTesting(const string & a = "Jest Testing", int b = 0) { words = a; number = b; cout << words << " Constructed"<<endl; }
	~JustTesting() { cout << words << " destoryed!" << endl; }
	void show() { cout << words << " ," << number << endl; }
};

class Customer
{
private:
	long arrive;
	int processtime;
public:
	Customer() { arrive = processtime = 0; }
	~Customer() {}
	void set(long when)
	{
		arrive = when;
		processtime = std::rand() % 3 + 1;
	}
	long when() const { return arrive; }
	int ptime() const { return processtime; }
};
typedef Customer people;

class queue
{
	enum {q_size = 10};
private:
	struct node
	{
		people people;
		struct node * next;
	};
	node * front;
	node * rear;
	int peoples;
	const int qsize;
	queue(const queue & a):qsize(0){}//伪私有类 防止生成默认的复制构造函数 又不让调用 简单的说 进制类复制
	queue & operator=(const queue & a) { return *this; }//伪私有类 防止生成默认的复制构造函数 又不让调用 简单的说 进制类复制
public:
	queue(int qs = q_size) : qsize(qs){ front = rear = nullptr; peoples = 0; }//函数参数后面qsize(qs),表示把 qsize初始化为qs
	~queue();
	bool isemptr() const;
	bool isfull() const;
	int queuecout() const;
	bool enqueue(const people &people);
	bool dequeue(people &people);
};

bool newcustomer(int x);
const int MIN_PER_HR = 60;