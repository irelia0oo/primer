
#pragma once
#include <cmath>
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cin;
using std::cout;
using std::atan;
using std::atan2;
using std::sin;
using std::sqrt;
using std::endl;

void shiliang();

namespace VECTOR
{
	class vector
	{
	public:
		enum Mode{rect,pol};
	private:
		double x;
		double y;
		double mag;
		double ang;
		void set_mag();
		void set_ang();
		void set_x();
		void set_y();
		Mode mode;
	public:
		vector();
		vector(double, double, Mode form = rect);
		void reset(double, double, Mode form = rect);
		~vector();
		double xval()const { return x; }
		double yval()const { return y; }
		double magval()const { return mag; }
		double angval()const { return ang; }
		void polar_mode();
		void rect_maoe();

		vector operator+(const vector & b)const;
		vector operator-(const vector & b)const;
		vector operator-() const;
		vector operator*(double n)const;
		friend vector operator*(double n, vector & b);
		friend std::ostream & operator<<(std::ostream & os, const vector & a);
	};
}

class type_conversion
{
private:
	int intvar;
	double doublevar;
public:
	type_conversion();
	type_conversion(int a, double b);
	~type_conversion();
	operator int() const;
	explicit operator double() const;
};


//class type_conversion_a
//{
//private:
//	int intvar;
//	double doublevar;
//public:
//	type_conversion_a() { intvar = 0; doublevar = 0.0; };
//	type_conversion_a(int a, double b) { intvar = a; doublevar = b; };
//	~type_conversion_a() {};
//	operator int() const { return intvar; };
//	operator double() const { return doublevar; };
//};