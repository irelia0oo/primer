#include "stdafx.h"
#include "friendfunction.h"
#include <typeinfo.h>

void friendclassfunction()
{
	abnormal();
	return;
	Tv s42;
	s42.setthings();
	cout << "------------------" << endl;
	s42.onoff();
	s42.chanup();
	s42.setthings();
	cout << "------------------" << endl;
	s42.chanup();
	s42.setthings();
	cout << "------------------" << endl;
	Remote grey;
	grey.set_chan(s42, 10);
	grey.volup(s42);
	grey.volup(s42);
	s42.setthings();
	cout << "------------------" << endl;
	Tv s58(Tv::ON);
	s58.set_mode();
	s58.set_input();
	grey.set_chan(s58, 28);
	s58.setthings();
	return ;
}

bool Tv::volup()
{
	if (volnum < MaxVal)
	{
		volnum++;
		return true;
	}
	return false;
}
bool Tv::voldown()
{
	if (volnum > MinVal)
	{
		volnum--;
		return true;
	}
	return false;
}
void Tv::chanup()
{
	if (channel < maxchannel)
		channel++;
	else
		channel = 1;
}
void Tv::chandown()
{
	if (channel > 1)
		channel--;
	else
		channel = maxchannel;
}
void Tv::setthings() const
{
	using std::cout;
	using std::endl;
	cout << "TV is " << (state == ON ? "ON" : "OFF") << endl;
	if (state == ON)
	{
		cout << "volnum == " << volnum << endl;
		cout << "channel == " << channel << endl;
		cout << "mode == " << (mode == Antenna ? "Antenna" : "cable") << endl;
		cout << "input == " << (input == TV ? "TV" : "DVD") << endl;
	}
}

int f1(int x);
int f2(int x);
int f1(int x)
{
	return x + 5;
}
int f2(int x)
{
	return 2 * x - 1;
}

void abnormal()
{
	//Tv c1,c3;
	//Remote c2;
	//cout << (typeid(c2) == typeid(c1)) << endl;
	//cout << (typeid(c2) == typeid(c1)) << endl;
	return;
	studentpower();
	return;
	
	//double x, y, z = 0.0;
	//cout << "Enter you numbers：" << endl;
	//while (cin>>x>>y)
	//{
	//	try
	//	{
	//		z = hmean(x, y);
	//	}
	//	catch (badhmean & s)
	//	{
	//		s.showbadmsg();
	//		continue;
	//	}
	//	cout << "the result ==" << z << endl;
	//}
}


 double hmean(double x, double y)
{
	 if (x + y == 0)
		 throw badhmean(x,y);	 
	 return 2 * y * x / (x + y);
}



 void studentpower()
 {
	 int N, D, K;
	 int i, j, k;
	 while (cin >> N)
	 {
		 long long result = 0;
		 long long *power = new long long[51];
		 long long **powermax = new long long*[11];
		 long long **powermin = new long long*[11];
		 for (i = 0; i <= 11; i++)
		 {
			 powermax[i] = new long long[51];
			 powermin[i] = new long long[51];
		 }
		 for (i = 0; i < N; i++)
		 {
			 cin >> power[i];
		 }
		 cin >> K >> D;

		 for (i = 0; i < K; ++i)
			 for (j = 0; j < N; powermax[i][j] = powermin[i][j] = 0, ++j);

		 for (i = 1; i <= N; ++i)
		 {
			 powermax[1][i] = powermin[1][i] = power[i - 1];
			 for (k = 2; k <= K; ++k)
			 {
				 for (j = i - 1; j > 0 && i - j <= D; --j)
				 {
					 powermax[k][i] = getpowermax(powermax[k][i], getpowermax(powermax[k - 1][j] * power[i - 1], powermin[k - 1][j] * power[i - 1]));
					 powermin[k][i] = getpowermin(powermin[k][i], getpowermin(powermax[k - 1][j] * power[i - 1], powermin[k - 1][j] * power[i - 1]));

					 //printf("i==%d  k==%d  j==%d \n", i, k, j);
					 //printf("powermax[%d][%d] == %I64d  %I64d  %I64d  %I64d\n", k, i, powermax[k][i], powermax[k - 1][j], powermin[k - 1][j], power[i - 1]);
					 //printf("powermax[%d][%d] == %I64d  %I64d  %I64d  %I64d\n", k, i, powermax[k][i], powermax[k - 1][j], powermin[k - 1][j], power[i - 1]);
					 //cout << "-----------------------" << endl;
				 }
				// cout << "----------------------------------------------------" << endl;
			 }
			 result = getpowermax(result, powermax[K][i]);
		 }
		 cout << result << endl;
		 for (i = 0; i <= 11; i++)
		 {
			 delete[] powermax[i];
			 delete[] powermin[i];
		 }
		 delete[] power;
	 } 
 }

//题目描述
// 有 n 个学生站成一排，每个学生有一个能力值，牛牛想从这 n 个学生中按照顺序选取 k 名学生，
// 要求相邻两个学生的位置编号的差不超过 d，使得这 k 个学生的能力值的乘积最大，你能返回最大的乘积吗？

// 输入描述 :
//每个输入包含 1 个测试用例。每个测试数据的第一行包含一个整数 n(1 <= n <= 50)，表示学生的个数，
//接下来的一行，包含 n 个整数，按顺序表示每个学生的能力值 ai（ - 50 <= ai <= 50）。
//接下来的一行包含两个整数，k 和 d(1 <= k <= 10, 1 <= d <= 50)。
// 输出描述 :
//输出一行表示最大的乘积。
// 示例1
// 输入
// 复制
// 3
// 7 4 7
// 2 50
// 输出
// 复制
// 49
