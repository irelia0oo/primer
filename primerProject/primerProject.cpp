// primerproject.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "ShiLiang.h"
#include "classmemory.h"
#include <windows.h>
#include "derivedclass.h"
#include "codereuse.h"
using namespace std;


//ltime = localtime(&local_tv_sec);//转换，vs2013会报错，说不安全，所以用 localtime_s 替换
string getTime()
{
	struct tm ltime ;//定义结构体变量
	time_t local_tv_sec = time(NULL);//定义时间戳
	//cout << &ltime << endl;
	localtime_s(&ltime, &local_tv_sec);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", &ltime);
	return tmp;
}

string getTime2()
{
	struct tm *ltime= new struct tm;//定义结构体变量
	time_t local_tv_sec = time(NULL);//定义时间戳
	localtime_s(ltime, &local_tv_sec);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S", ltime);

	delete ltime;
	return tmp;
}

int main()
{
	//模板重载函数
	/*
	string str1 = "aaaavbb", str2 = "cccccc",str3 = "xxxxx";
	int a = 5;
	double b = 5.5;
	cout << leijia(str1, str2) << endl;
	cout << leijia(a, b) << endl;
	cout << leijia(str1, str2, str3) << endl;
	*/
	/*
	double price,wantprice;
	cin >> price>>wantprice;
	if (cin.fail() == true)
	exit(EXIT_FAILURE);
	int i = 1;
	while (price > wantprice)
	{
	price = price * (1 - 0.001);
	//cout << price << endl;
	i++;
	}
	cout << i << endl;
	*/
	//songsong();

	//extern int xxxx;	//使用extern引用其他文件的变量 其他的文件内 这个变量必须如此声明 int xxxx = 12; 定义变量前面不可以添加 static 或 const关键字,否则引用时报错
	//cout << xxxx << endl;
	xiti8();
	xiti9();
	xiticlass();
	//shiliang();
	xiti11();
	xiti12();

	/*
	struct tm ltime;//定义结构体变量
	time_t local_tv_sec = time(NULL);//定义时间戳
	long long int sec = 0;

	do 
	{
		local_tv_sec = time(NULL);
		localtime_s(&ltime, &local_tv_sec);
		sec = (ltime.tm_mon + 1) * 30 * 24 * 3600 + ltime.tm_mday * 24 * 3600 + (ltime.tm_hour + 1) * 3600 + (ltime.tm_min + 1) * 60 + ltime.tm_sec;
		sec = 6 * 30 * 24 * 3600 + 24 * 24 * 3600 + 14 * 3600 - sec;

		struct tm t = { 0 };
		t.tm_hour = sec / 3600;
		t.tm_min = (sec - t.tm_hour * 3600) / 60;
		t.tm_sec = sec - t.tm_hour * 3600 - t.tm_min * 60;
		cout << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec << endl;
		Sleep(1000);

	} while (sec> 0);
	*/
	deriveclass();
	codereuse_classmode();
	system("pause");
	return 0;
}

