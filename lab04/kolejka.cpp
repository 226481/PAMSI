#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include "kolejka_klasa.h"
#include "stoper.h"

//Tomasz Perczyñski 226481, PAMSI œroda 14:00-16:00.
// KOLEJKA

using namespace std;

int main()
{
	srand(time(NULL));
	stoper s;
	kolejka powaznakolejka;
	s.mierz_czas_start();
	for(int i=0; i<20;i++)
	{
		powaznakolejka.wypelnij(100);
		powaznakolejka.find(5);
		cout <<endl;
		s.mierz_czas_stop();
		cout << endl;
		powaznakolejka.wyczysc();
	}
	s.srednia();
	return 0;
}
