#pragma once
#include "stdafx.h"


using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;

format Setformat();
void restore(format f, precis p);

void deriveclass();

class Tabletennisplayer
{
private:
	string firstname;
	string lastname;
	bool hastable;
public:
	Tabletennisplayer(const string &fn = "none", const string &ln = "none", bool ht = false);
	void Name() const;
	bool HasTable()const { return hastable; }
	void Resettable(bool v) { hastable = v; }
	friend std::ostream & operator<<(std::ostream & os, const Tabletennisplayer & tp);
};


class RatedPlayer : public Tabletennisplayer
{
private:
	unsigned int rating;
public:
	RatedPlayer(unsigned int r = 0, const string & fn = "none",
		const string & ln = "none", bool ht = false);
	RatedPlayer(unsigned int r, const Tabletennisplayer & tp);
	unsigned int Rating()const { return rating; }
	void Resetrating(unsigned int r){rating = r;}
	friend std::ostream & operator<<(std::ostream & os, const RatedPlayer &tp);
	
};

void classis_a_brass();

class Brass
{
private:
	std::string fullname;
	long int acctnum;
	double balance;
public:
	Brass(const std::string & s = "nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance() const;
	virtual void ViewAcct() const;
	virtual ~Brass() { 
		//cout << "基类函数析构函数" << endl; 
	}
};

class BrassPlus : public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string & s = "nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125, double ow = 0.0);
	BrassPlus(Brass &tp, double ml = 500, double r = 0.11125, double ow = 0.0);
	virtual void ViewAcct()const;
	virtual void Withdraw(double amt);
	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; }
	void ResetOwes() { owesBank = 0; }
	virtual ~BrassPlus(){ 
		//cout << "派生类函数析构函数" << endl;
	}
};



