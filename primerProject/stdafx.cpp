// stdafx.cpp : 只包括标准包含文件的源文件
// primerproject.pch 将作为预编译标头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用


void songsong(const char * name, int times)
{
	for (int i = 0; i < times; i++)
	{
		cout << name[i];
	}
	cout << endl;
}


void xiti8()
{
	return;
	//xiti8_1("aassdfdfdg", 2);
	//xiti8_1("aassdfdfdg");
	//xiti8_1("aassdfdfdg", 0);
	//string str1 = "AAAAAaaaaa";
	//string a = xiti8_2_1(str1);
	//string b = xiti8_2_2((string)"AAAAAaaaaa");
	//cout << a << endl;
	//cout << b << endl;

	double a[11] = { 11.111,2.54,33,0.4,55,6,75.4,888.5,9.9,15,1699.8 };
	double b = 0;
	amx5(a, b);
	//double c = getarraylen(a, 1);
	cout << b << endl;
	cout << xiti8_3(a) << endl;
	cout << xiti8_3(a, 2) << endl;
	cout << xiti8_3(a, xitimaxnumber) << endl;
	cout << xiti8_3(a, xitibignumber) << endl;
	cout << a << " " << &a[0] << endl;
	xitimaxnumber++;
	cout << "xitimaxnumber==" << xitimaxnumber << endl;
	for (int i = 0;; i++)
	{
		int a;
		cin >> a;
		if (cin.fail() == true)
			break;
		cout << a * a << endl;
	}
	cout << a << " " << &a[0] << endl;

	testststicint(5);
	testststicint(5);
	return;
}



void xiti8_1(const char * a, int i)
{
	if (i <= 0)
		return;
	printf("%s\n", a);
}

int testststicint(int a)
{
	static int b = 0;//静态的局部变量，只初始化一次， 第一调用时 b == 0 第二次调用 b == 上一次的 a + b
	b = a + b;
	cout << "b===" << b << endl;
	return b;
}

void xiti9()
{
	//char a[] = "asdfghjkl;";

	return;
	struct chaff *mya;
	static char schr[64];
	mya = new (schr) chaff;

	cin.get(mya->dross, 20);
	cin >> mya->slag;
	cout << mya->dross << " " << (*mya).slag << endl;

	cout << &schr << endl;
	echo(mya);

	echo(&(mya->dross));
	echo(&(mya->slag));


	cout << "Irelia is 666" << endl;
	jill::xiti9();
	jill::jillcout((string)"Irelia is 666");
	jill::sorce = jill::sorce * jill::sorce;
	jill::jillcout(jill::sorce);

	const jill::jillStruct structxiti9_1[]
	{
		{ "buu",11 },
	{ "doo",33 }
	};
	structxiti9_1[0].sorce = structxiti9_1[0].sorce * structxiti9_1[1].sorce;
	jill::jillcout(structxiti9_1[0].name);
	jill::jillcout(structxiti9_1[0].sorce);
	echo(structxiti9_1[1].name, ' ');
	echo(structxiti9_1[1].sorce);
}

/*
class stock
{
private:
std::string company;
long shares;
double share_val;
double total_val;
void set_total()
{
total_val = shares * share_val;
}
public:
void acquire(const string & co, long n, double pr);
void buy(long num, double price);
void sell(long num, double price);
void show();
};*/

void stock::acquire(const string & co, long n, double pr)
{
	//stock::company = co;
	//stock::shares = n;
	//stock::share_val = pr;
	company = co;
	shares = n;
	share_val = pr;
	set_total();
}
void stock::buy(long num, double price)
{
	shares += num;
	share_val = (price * num + total_val) / shares;
	set_total();
}
void stock::sell(long num, double price)
{
	if (num > shares)
	{
		cout << "the number is wrong!!!";
		return;
	}
	shares = shares - num;
	share_val = price;
	set_total();
}
void stock::show() const
{
	cout << "------------------------------" << endl;
	cout.setf(ios_base::fixed, ios_base::floatfield);//切换正常的小数计数和科学计数法
	cout.precision(3);//小数点保留3位
	cout << "company " << company << endl
		<< "shares " << shares << endl
		<< "share_val " << share_val << endl
		<< "total_val " << total_val << endl;

	cout.setf(ios_base::fixed, ios_base::floatfield);//切换正常的小数计数和科学计数法

	for (int i = 0; i < ownum; i++)
	{
		cout << ower[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < sellnum; i++)
	{
		cout << seller[i] << " ";
	}
	cout << endl;
	cout << "------------------------------" << endl;
}
stock::stock()
{
	company = "null";
	shares = 0;
	share_val = 0;
	set_total();
	for (int i = 0; i < ownum; i++)
	{
		ower[i] = company + (char)i;
	}
	for (int i = 0; i < sellnum; i++)
	{
		seller[i] = company + (char)i;
	}
}
stock::stock(const string  cn, long number, double price)
{
	company = cn;
	shares = number;
	share_val = price;
	set_total();

	for (int i = 0; i < ownum; i++)
	{
		ower[i] = company + (char)i;
	}
	for (int i = 0; i < sellnum; i++)
	{
		seller[i] = company + (char)i;
	}
}
stock::~stock()
{
	cout << "bye bye !" << endl;
}

const stock & stock::moreval(stock & t) const
{
	if (t.total_val >= this->total_val)
		return t;
	else
		return *this;
}
stock * stock::topnum(stock & s)
{
	if (this->shares >= s.shares)
	{
		this->shares += s.shares;
		s.shares = 0;
		s.set_total();
		this->set_total();
		return this;
	}
	else
	{
		s.shares += this->shares;
		this->shares = 0;
		s.set_total();
		this->set_total();
		return &s;
	}
}

stack::stack()
{
	top = 0;
}
stack::~stack()
{

}

bool stack::isempty()
{
	return top == 0;
}
bool stack::isfull()
{
	return top == max;
}
bool stack::push(const item & item)
{
	if (top < max)
	{
		items[top] = item;
		top++;
		return true;
	}
	else
		return false;
}
bool stack::pop(item & item)
{
	if (top > 0)
	{
		top--;
		item = items[top];
		return true;
	}
	else
		return false;
}

void stack::clear()
{
	for (int i = 0; i < max; i++)
		items[i] = 0;
	top = 0;
}
void stack::show()
{
	cout << "top==" << top << " Items[]==";
	for (int i = 0; i < top; i++)
		cout << items[i] << " ";
	cout << endl;
}



betelgeusean::betelgeusean()
{
	memcpy(name, "plorga", strlen("plorga") );
	name[strlen("plorga")] = '\0';
	ci = 0;
}
betelgeusean::betelgeusean(char * n, int c)
{
	ci = c;
	memcpy(name,n,strlen(n));//把char数组 n 覆盖到 数组name里，长度为 n的长度
}
betelgeusean::~betelgeusean()
{

}
void betelgeusean::updateci(int c)
{
	ci = c;
}

void betelgeusean::show()
{
	//cout << name << " " << ci << endl;
	printf("%s %d \n", name, ci);
}


timesa::timesa()
{
	hour = 0;
	minutes = 0;
}
timesa::timesa(int h, int m)
{
	hour = h;
	minutes = m;
}
timesa::~timesa()
{
}
void timesa::addtime(int h, int m )
{
	hour += h;
	minutes += m;
//	hour += floor(minutes / 60);
	hour += minutes / 60;
	minutes = minutes % 60;
}
timesa timesa::sum(timesa & t2) const
{
	timesa sum;
	sum.hour = this->hour + t2.hour;
	sum.minutes = this->minutes + t2.minutes;
	sum.hour += sum.minutes / 60;
	sum.minutes = sum.minutes % 60;
	return sum;
}
timesa timesa::operator+(const timesa & t2) const
{
	timesa sum;
	sum.hour = this->hour + t2.hour;
	sum.minutes = this->minutes + t2.minutes;
	sum.hour += sum.minutes / 60;
	sum.minutes = sum.minutes % 60;
	return sum;
}
timesa timesa::operator-(const timesa & t) const
{
	timesa sum;
	sum.minutes = this->hour * 60 + this->minutes - t.hour * 60 - t.minutes;
	if (sum.minutes <= 0)
	{
		sum.hour = 0;
		sum.minutes = 0;
	}
	else
	{
		sum.hour = sum.minutes / 60;
		sum.minutes = sum.minutes % 60;
	}
	return sum;
}
timesa timesa::operator-()
{
	this->hour = -this->hour;
	this->minutes = -this->minutes;
	return *this;
}
timesa timesa::operator--()
{
	int minuit = this->hour * 60 + this->minutes;
	minuit--;
	this->hour = minuit / 60;
	this->minutes = minuit % 60;
	return *this;
}
timesa timesa::operator++()
{
	int minuit = this->hour * 60 + this->minutes;
	minuit++;
	this->hour = minuit / 60;
	this->minutes = minuit % 60;
	return *this;
}
timesa timesa::operator*(int n) const
{
	timesa sum;
	sum.minutes = (this->hour * 60 + this->minutes) * n;
	sum.hour = sum.minutes / 60;
	sum.minutes = sum.minutes % 60;
	return sum;
}
timesa operator*(int n, const timesa & a)
{
	return a.operator*(n);
}
void timesa::show()
{
	cout << hour << ":" << minutes << endl;
}

ostream & operator<<(ostream & os,const timesa & a)
{
	//printf("%s\n", os);
	os << a.hour << ":" << a.minutes << endl;
	return os;
}
istream & operator>>(istream & is, timesa & a)
{
	is >> a.hour >> a.minutes;
	a.addtime(0);
	return is;
}
