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

class queue
{
	enum {q_size = 10};
private:
	struct node
	{
		item item;
		struct node * next;
	};
	node * front;
	node * rear;
	int items;
	const int qsize;
	queue(const queue & a):qsize(0){}//α˽���� ��ֹ����Ĭ�ϵĸ��ƹ��캯�� �ֲ��õ��� �򵥵�˵ �����ิ��
	queue & operator=(const queue & a) { return *this; }//α˽���� ��ֹ����Ĭ�ϵĸ��ƹ��캯�� �ֲ��õ��� �򵥵�˵ �����ิ��
public:
	queue(int qs = q_size) : qsize(qs){ front = rear = nullptr; items = 0; }//������������qsize(qs),��ʾ�� qsize��ʼ��Ϊqs
	~queue();
	bool isemptr() const { return (q_size >= 0 && q_size < 10); }
	bool isfull() const { return (q_size >= 10); }
	int queuecout() const;
	bool enqueue(const item &item);
	bool dequeue(item &item);
};
