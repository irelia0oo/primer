// primerproject.cpp: 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "ShiLiang.h"
#include "classmemory.h"
using namespace std;

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
	system("pause");
	return 0;
}

