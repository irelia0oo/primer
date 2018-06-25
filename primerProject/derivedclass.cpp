#include "stdafx.h"
#include "derivedclass.h"


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

RatedPlayer::RatedPlayer(unsigned int r, const string & fn, const string & ln, bool ht):Tabletennisplayer(fn,ln,ht)
{
	rating = r;
}

RatedPlayer::RatedPlayer(unsigned int r, const Tabletennisplayer & tp):Tabletennisplayer(tp),rating(r)
{

}

std::ostream & operator<<(std::ostream & os, const RatedPlayer & rp)
{
	os << rp.rating<<"  ";
	Tabletennisplayer now;
	now = Tabletennisplayer(rp);
	cout << now;
	return os;
}


void deriveclass()
{
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

