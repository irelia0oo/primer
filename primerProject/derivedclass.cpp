#include "stdafx.h"
#include "derivedclass.h"


format Setformat()
{
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}

Tabletennisplayer::Tabletennisplayer(const string &fn, const string  &ln, bool ht) : firstname(fn), lastname(ln), hastable(ht)
{

}

void Tabletennisplayer::Name() const
{
	std::cout << lastname << " " << firstname;
}

std::ostream & operator<<(std::ostream & os, const Tabletennisplayer & tp)
{
	os << tp.lastname << "," << tp.firstname;
	if (tp.HasTable())
		os << ":has a table" << endl;
	else
		os << ":hasn't a table" << endl;
	return os;
}

RatedPlayer::RatedPlayer(unsigned int r, const string & fn, const string & ln, bool ht) :Tabletennisplayer(fn, ln, ht)
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const Tabletennisplayer & tp) : Tabletennisplayer(tp), rating(r)
{

}

std::ostream & operator<<(std::ostream & os, const RatedPlayer & rp)
{
	os << rp.rating << "  ";
	Tabletennisplayer now;
	now = Tabletennisplayer(rp);
	cout << now;
	return os;
}




void deriveclass()
{
	return;
	class_b_base();
	return;
	classis_a_brass();
	return;
	using std::cout;
	Tabletennisplayer player1{ "Chuck","Blizzard",true };
	Tabletennisplayer player2{ "Tara","Boomdea",false };
	player1.Name();
	if (player1.HasTable())
		cout << ":has a table" << endl;
	else
		cout << ":hasn't a table" << endl;
	player2.Name();
	if (player2.HasTable())
		cout << ":has a table" << endl;
	else
		cout << ":hasn't a table" << endl;
	cout << "------------------------" << endl;
	RatedPlayer rplayer1;
	RatedPlayer rpalyer2;
	rplayer1 = RatedPlayer(1254, "Chuck", "Blizzard", true);
	rpalyer2 = RatedPlayer(12312, player2);


	rplayer1.Name();
	if (rplayer1.HasTable())
		cout << ":has a table" << endl;
	else
		cout << ":hasn't a table" << endl;
	cout << "rplayer1.rating===" << rplayer1.Rating() << endl;
	rpalyer2.Name();
	if (rpalyer2.HasTable())
		cout << ":has a table" << endl;
	else
		cout << ":hasn't a table" << endl;
	cout << "rplayer2.rating===" << rpalyer2.Rating() << endl;
	cout << "------------------------" << endl;

	cout << RatedPlayer(rplayer1) << endl;

	cout << "bye bye!!" << endl;
}


Brass::Brass(const std::string & s , long an , double bal ) :fullname(s), acctnum(an),balance(bal)
{
}
void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "Negative deposit not allowed:"
		<< "deposit is cancelled:\n";
	else
		balance += amt;
}
void Brass::Withdraw(double amt)
{
	format initialState = Setformat();
	precis prec = cout.precision(2);
	if (amt < 0)
		cout << "Withdraw amount must be positive;"
		<< "Withdraw cancelled.\n";
	else if (amt <= balance)
		balance -= amt;
	else
		cout << "whithdraw amount of $" << amt
		<< "exceeds yours balance.\n"
		<< "withdrawl canceled.\n";
	restore(initialState, prec);
}
double Brass::Balance() const
{
	return balance;
}
void Brass::ViewAcct() const
{
	format initialState = Setformat();
	precis prec = cout.precision(2);

	cout << "Client :" << fullname << endl;
	cout << "Account Number:" << acctnum << endl;
	cout << "Balance :" << balance << endl;

	restore(initialState, prec);
}
BrassPlus::BrassPlus(const std::string & s, long an, double bal, double ml, double r, double ow) : Brass(s,an,bal)
{
	maxLoan = ml;
	rate = r;
	owesBank = ow;
}
BrassPlus::BrassPlus(Brass &tp, double ml , double r , double ow ) : Brass(tp),maxLoan(ml),rate(r),owesBank(ow)
{
}
void BrassPlus::ViewAcct()const
{
	format initialState = Setformat();
	precis prec = cout.precision(2);

	Brass::ViewAcct();
	cout << "maxinum loan:$" << maxLoan << endl;
	cout << "Owed to bank:$" << owesBank << endl;
	cout.precision(3);
	cout << "Loan Rate:" << 100 * rate << "%"<<endl;
	restore(initialState, prec);
}
void BrassPlus::Withdraw(double amt)
{
	format initialState = Setformat();
	precis prec = cout.precision(2);

	double bal = Brass::Balance();
	if (amt <= bal)
		Brass::Withdraw(amt);
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance * (1 + rate);
		cout << "Bank advance:$" << advance << endl;
		cout << "Finance charge:$" << advance * rate << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
		cout << "Credit limit exceeded.Transaction canceled." << endl;

	restore(initialState, prec);
}

void classis_a_brass()
{
	BrassPlus b{ "zhang",13456,5000,500,0.1,0 };
	Brass * bb;
	bb = &b;
	bb->ViewAcct();
	cout << endl;
	Brass bbb = b;
	bbb.ViewAcct();
	return;
	BrassPlus * a = new BrassPlus{ "irelia",100001,253.11 ,1200,0.25,0};
	a->ViewAcct();
	delete a;
	return;
	Brass Pigggy{ "procelot pigg",381229,4000.00 };
	BrassPlus Hoggy{ "horatio hogg",382288,3000.00 };
	Pigggy.ViewAcct();
	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;
	
	Hoggy.Deposit(1000);
	cout << "now balance:" << Hoggy.Balance() << endl;
	Pigggy.Withdraw(4200);
	cout << "pigg account balance==" << Pigggy.Balance() << endl;
	Hoggy.Withdraw(4200);
	cout << "Hoggy account balance==" << Hoggy.Balance() << endl;

	cout << endl;
	Hoggy.ViewAcct();
	cout << endl;
}


baseDMA::baseDMA(const char * c , int r)
{
	int len = static_cast<int>(strlen(c)) + 1;
	lable = new char[len];
	strcpy_s(lable, len, c);
	rating = r;
}
baseDMA::baseDMA(const baseDMA & r)
{
	int len = static_cast<int>(strlen(r.lable)) + 1;
	lable = new char[len];
	strcpy_s(lable, len, r.lable);
	rating = r.rating;
}
baseDMA::~baseDMA()
{
	delete[] lable;
}
baseDMA & baseDMA::operator=(const baseDMA & r)
{
	if (this == &r)
		return *this;

	delete[] lable;

	int len = static_cast<int>(strlen(r.lable)) + 1;
	lable = new char[len];
	strcpy_s(lable, len, r.lable);
	rating = r.rating;

	return *this;
}
std::ostream & operator<<(std::ostream & os, const baseDMA & r)
{
	os << "lable =="<<r.lable << " rating ==" << r.rating;
	return os;
}
lacksDMA::lacksDMA(const char *c, const char *l, int r) : baseDMA(l,r)
{
	strcpy_s(this->color, 39, c);
	color[39] = '\0';
}
lacksDMA::lacksDMA(const char *c, const baseDMA & r) 
	: baseDMA(r)
{
	strcpy_s(this->color, COL_LEN - 1, c);
	color[COL_LEN - 1] = '\0';
}
lacksDMA::~lacksDMA()
{

}
std::ostream & operator<<(std::ostream & os, const lacksDMA & lr)
{
	os << (const baseDMA &)lr << " ";
	os << "color ==" << lr.color;
	return os;
}

hasDMA::hasDMA(const char *s, const char *l, int r ) 
	: baseDMA(l,r)
{
	int len = static_cast<int>(strlen(s)) + 1;
	style = new char[len];
	strcpy_s(style, len, s);
}
hasDMA::hasDMA(const char *s, const baseDMA & r)
	:baseDMA(r)
{
	int len = static_cast<int>(strlen(s)) + 1;
	style = new char[len];
	strcpy_s(style, len, s);
}
hasDMA::hasDMA(const hasDMA & h)
{
	int len = static_cast<int>(strlen(h.style)) + 1;
	style = new char[len];
	strcpy_s(style, len, h.style);
}
hasDMA::~hasDMA()
{
	delete[] style;
}
hasDMA & hasDMA::operator=(const hasDMA & r)
{
	if (this == &r)
		return *this;
	baseDMA::operator=(r);//或者可以这样写 *this = r;
	delete[] style;
	int len = static_cast<int>(strlen(r.style)) + 1;
	style = new char[len];
	strcpy_s(style, len, r.style);
	return *this;
}
std::ostream & operator<<(std::ostream & os, const hasDMA & sr)
{
	os << (const baseDMA &)sr << " ";
	os << "style =="<<sr.style;
	return os;
}

void class_b_base()
{
	baseDMA shirt("Portabelly", 8); 
	lacksDMA balloon("red", "Blimpo", 4); 
	hasDMA map("Mercator", "Buffalo Keys", 5); 
	cout << "shirt is:  " << shirt << endl;
	cout << "balloon is:  " << balloon << endl;
	cout << "map is:  " << map << endl;

	lacksDMA balloon2(balloon);
	cout << "balloon2 is:  " << balloon2 << endl;

	hasDMA map2;
	cout << "map2 is:  " << map2 << endl;

	cout << "bye bye" << endl;
}