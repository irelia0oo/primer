#include "stdafx.h"
#include "ShiLiang.h"
void xiticlass()
{

	testclasszhan();

	return;

	cegg s = cegg::large;
	cout << (int)s << endl;

	const int number = 5;
	stock cat[number] =
	{
		stock("sdffsdf", 212, 25.1),
		stock("bvbcf", 3423, 342.0),
		stock("ccdfg", 23112, 11.0),
		stock("cvbcdd", 435, 23.0),
		stock()
	};
	
	stock joe = stock("Irelia", 120, 20.0);
	stock kate = stock("xxxx", (long)2, 10.0);
	stock need;
	need = kate.moreval(joe);
	need.show();
	
	stock * pn = joe.topnum(kate);
	pn->show();

	joe.show();
	kate.show();
	//stock::acquire("dab/aojian", 100, 5);
	
	//stock kate = stock("xxxx", (long)2, 10.0);
	kate.show();
	kate.acquire("dabajian", 10000, 50);
	kate.show();
	kate.buy(1000000, 3.44056);
	kate.show();
	kate.sell(200, 12.444);
	kate.show();
	echo("~~~~~~~~~~~~~~~~");
	kate = stock("zzzzz", 120, 55.6);
	kate.show();

}

void testclasszhan()
{
	return;
	timesa a = { 5,30 };
	timesa a1 = { 5,59 };
	timesa a2 = { 5,00 };
	a = -a;
	a.show();

	//return;
	timesa b = timesa(6, 55);
	a.show();
	b.show();
	timesa c,d,e,f,g;
	c = b.sum(a);
	c.show();
	d = a + b;
	d.show();
	e = a + b + c + d;
	e.show();
	f = a.operator*(2);
	g = (c.operator+(a.operator+(b)).operator-(d)).operator*(2);
	f.show();
	g.show();

	timesa h;
	h = 3 * g;
	cout << "=============="<< h;

	ofstream fout;
	fout.open("123.txt");
	if (!fout.is_open())
		exit(EXIT_FAILURE);
	cin >> b;
	while (cin.fail() == false)
	{
		fout << b;
		cin >> b;
	}
	
	fout.close();
	return;

	betelgeusean plorg;
	plorg.updateci(22);
	plorg.show();

	unsigned long pp;
	stack st;
	for(;;)
	{
		//if (isalnum(pp))
		//{
		//	cout << "wrong number!" << endl;
		//	continue;
		//}
		cin >> pp;
		if(cin.fail())
			continue;
		if (pp == 0)
			break;
		if (st.isfull())
		{
			cout << "the stack is full,now clear it." << endl;
			st.clear();
			continue;
		}
		else
			st.push(pp);
		st.show();
	}
}




Stonewt::Stonewt()
{
	stone = pounds = pds_left = 0;
}
Stonewt::Stonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}
Stonewt::Stonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn * lbs;
}
Stonewt::~Stonewt()
{

}
void Stonewt::show_lbs() const
{
	cout << "pounds===" << pounds << endl;
}
void Stonewt::show_stm() const
{
	cout << "stone ==" << stone << "  pds_left==" << pds_left << endl;
}

void xiti11()
{
	return;
	type_conversion test = { 12,1.5 };
	int ta = test;
	double td = test;
	cout << ta << " " << td << endl;
	cout << (int)test << endl;
}