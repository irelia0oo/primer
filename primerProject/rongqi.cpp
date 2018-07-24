#include "stdafx.h"
#include "rongqi.h"

void rongqi()
{
	const int n = 6;
	string s1[n] = { "xx","sdasd","fross","for","ssfor","for" };
	set<string> a(s1, s1 + n);
	copy(a.begin(), a.end(), ostream_iterator<string, char>(cout, " "));
}