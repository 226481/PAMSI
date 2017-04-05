#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include "stoper.h"
#include "lista_klasa.h"

//Tomasz Perczyñski 226481, PAMSI œroda 14:00-16:00.
// LISTA

using namespace std;

int main()
{
	srand(time(NULL));
	stoper s;
	lista powaznalista;
	int ilosc;
	ilosc = 1000000;
	s.mierz_czas_start();
	for(int i=0; i<20; i++)
	{
	powaznalista.wypelnij(ilosc);
	cout << endl;
	powaznalista.find(2);
	s.mierz_czas_stop();
	powaznalista.wyczysc();
	}
	s.srednia();
	
	return 0;
}
