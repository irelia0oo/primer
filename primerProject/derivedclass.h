#pragma once
#include "stdafx.h"


using std::string;

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