#include "stdafx.h"
#include "ShiLiang.h"



namespace VECTOR
{
	const double red_to_deg = 45.0;
	void vector::set_mag()
	{
		mag = sqrt(x * x + y * y);
	}
	void vector::set_ang()
	{
		if (x * y == 0.0)
			ang = 0.0;
		else
			ang = atan2(y, x);
	}
	void vector::set_x()
	{
		x = mag * cos(ang);
	}
	void vector::set_y()
	{
		y = mag * sin(ang);
	}
	vector::vector()
	{
		x = y = mag = ang = 0.0;
		mode = rect;
	}
	vector::vector(double a , double b, Mode form )
	{
		switch (form)
		{
		case rect:
			x = a;
			y = b;
			set_mag();
			set_ang();
			mode = rect;
			break;
		case pol:
			mag = a;
			ang = b / red_to_deg;
			set_x();
			set_y();
			mode = pol;
			break;
		default:
			x = y = mag = ang = 0.0;
			mode = rect;
			break;
		}
	}
	void vector::reset(double a, double b, Mode form )
	{
		switch (form)
		{
		case rect:
			x = a;
			y = b;
			set_mag();
			set_ang();
			break;
		case pol:
			mag = a;
			ang = b / red_to_deg;
			set_x();
			set_y();
			break;
		default:
			x = y = mag = ang = 0.0;
			mode = rect;
			break;
		}
	}
	vector::~vector()
	{

	}
	void vector::polar_mode()
	{
		mode = pol;
	}
	void vector::rect_maoe()
	{
		mode = rect;
	}
	vector vector::operator+(const vector & b)const
	{
		return vector(x + b.x,y + b.y);
	}
	vector vector::operator-(const vector & b)const
	{
		return vector(x - b.x, y - b.y);
	}
	vector vector::operator-() const
	{
		return vector(-x, -y);
	}
	vector vector::operator*(double n)const
	{
		return vector(x * n, y *n);
	}
	vector operator*(double n, vector & b)
	{
		return b.operator*(n);
	}
	std::ostream & operator<<(std::ostream & os, const vector & a)
	{
		if (a.mode == a.rect)
			os << "(x,y) ==" << a.x << "," << a.y << endl;
		else if (a.mode == a.pol)
			os << "(m,a) ==" << a.mag << "," << a.ang*red_to_deg << endl;
		else
			os << "some things is wrong!" << endl;

		return os;
	}
}

void shiliang()
{
	using VECTOR::vector;

	//vector test;
	//double n1, n2;
	//srand(time(0));
	//cin >> n1;
	//n2 = rand() % 360;
	//test.reset(n1, n2, vector::pol);
	//cout << test;
	//return;


	srand(time(NULL));
	double direction;
	vector step;
	vector result(0.0, 0.0);
	
	unsigned long steps = 0;
	double target;
	double dstep;
	cout << "enter target distance(q to quit):";
	while (cin>>target)
	{
		cout << "enter step length:";
		if (!(cin >> dstep))
			break;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, vector::pol);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps,thesubject has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << " or \n" << result << endl;
		cout << "average outward distance per step = " << result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "enter target distance(q to quit):";
	}
	cout << "bye ! \n";
	cin.clear();
	while (cin.get() != '\n')
	{
		continue;
	}

	//std::cout << "ÎÒÈ¥ÄãÂðµ°µ°" << endl;
	return;
}



type_conversion::type_conversion()
{
	intvar = 0;
	doublevar = 0.0;
}
type_conversion::type_conversion(int a,double b)
{
	intvar = a;
	doublevar = b;
}
type_conversion::~type_conversion()
{

}
type_conversion::operator int() const
{
	return intvar;
}

type_conversion::operator double() const
{
	return doublevar;
}