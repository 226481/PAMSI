#ifndef INTERFEJS_HH
#define INTERFEJS_HH

#include<cstdio>
#include<iostream>
#include<fstream>
//Tomasz Perczy�ski 226481, PAMSI �roda 14:00-16:00.

using namespace std;

class interfejs
{
	public:
	interfejs();
	virtual	void wypelnianie();
	virtual	void wyswietl(int pierogi);
	virtual	int rozmiar();
	virtual	void czysto();
	virtual ~interfejs();
};

interfejs::interfejs()
{
}

interfejs::~interfejs()
{
}

void interfejs::wypelnianie()
{
}

void interfejs::wyswietl(int pierogi)
{
}

int interfejs::rozmiar()
{
}

void interfejs::czysto()
{
}



#endif
