#include "stdafx.h"
#include "friendfunction.h"

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

void abnormal()
{
	double x, y, z = 0.0;
	cout << "Enter you numbers£º" << endl;
	while (cin>>x>>y)
	{
		try
		{
			z = hmean(x, y);
		}
		catch (badhmean & s)
		{
			s.showbadmsg();
			continue;
		}
		cout << "the result ==" << z << endl;
	}
}


 double hmean(double x, double y)
{
	 if (x + y == 0)
		 throw badhmean(x,y);	 
	 return 2 * y * x / (x + y);
}

