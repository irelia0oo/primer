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
};