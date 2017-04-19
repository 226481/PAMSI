#ifndef INTERFEJS_HH
#define INTERFEJS_HH

#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include <ctime>
#include "stoper.h"

using namespace std;

class sortowanie
{
	public:
		sortowanie();
		virtual void sortuj();
		virtual int czesci();
		virtual ~sortowanie();
};

sortowanie::sortowanie()
{
}

sortowanie::~sortowanie()
{
}

int sortowanie::czesci()
{
}

void sortowanie::sortuj()
{
}

#endif
