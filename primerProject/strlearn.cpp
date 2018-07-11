#include "stdafx.h"
#include "strlearn.h"

void strlearn()
{
	int a = 10, k = 2, m = 1;
	printf("%d\n", SQR(k + m) / SQR(k + m));
	a /= SQR(k + m) / SQR(k + m);
	printf("%d\n", a);
}
