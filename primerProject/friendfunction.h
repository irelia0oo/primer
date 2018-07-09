#pragma once
#include "stdafx.h"

void friendclassfunction();
void abnormal();
double hmean(double x,double y);
class Tv
{
private:
	int state;
	int volnum;
	int maxchannel;
	int channel;
	int mode;
	int input;
public:
	friend class Remote;
	enum{OFF,ON};
	enum { MinVal, MaxVal = 20 };
	enum{Antenna,Cable};
	enum{TV,DVD};
	Tv(int s = OFF,int mc = 125):state(s),volnum(5),maxchannel(mc),channel(2),mode(Cable),input(TV){}
	void onoff() { state = (state == ON) ? OFF : ON; }
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
	void set_input() { input = (input == TV) ? DVD : TV; }
	void setthings() const;
};

class Remote
{
private:
	int mode;
public:
	Remote(int m = Tv::TV) :mode(m) {}
	bool volup(Tv & t) { return t.volup(); }
	bool voldown(Tv & t) { return t.voldown(); }
	void onoff(Tv & t) { t.onoff(); }
	void chanup(Tv & t) { t.chanup(); }
	void chandown(Tv & t) { return t.chandown(); }
	void set_chan(Tv & t, int c) { t.channel = c; }
	void set_mode(Tv & t) { t.set_mode(); }
	void set_input(Tv & t) { t.set_input(); }
};


class badhmean
{
private:
	double val1;
	double val2;
public:
	badhmean(double v1 = 0.0, double v2 = 0.0) :val1(v1), val2(v2) {}
	void showbadmsg();
};
inline void badhmean::showbadmsg()
{
	if (val1 == -val2)
	{
		cout << "the arguments is wrong,a + b = 0" << endl
			<< "Enter new number:" << endl;
	}
}