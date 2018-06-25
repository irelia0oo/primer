#include "stdafx.h"
#include "derivedclass.h"

using namespace std;
Tabletennisplayer::Tabletennisplayer(const string &fn, const string  &ln, bool ht) : firstname(fn), lastname(ln), hastable(ht)
{

}


void Tabletennisplayer::Name() const
{
	std::cout << lastname << " " << firstname;
}

void deriveclass()
{

}