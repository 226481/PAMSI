#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include "stoper.h"
#include "stos_klasa.h"

//Tomasz Perczyñski 226481, PAMSI œroda 14:00-16:00.
// STOS

using namespace std;

int main()
{
	srand(time(NULL));
	stoper s;
	stos powaznystos;
	s.mierz_czas_start();
	for(int i=0; i<20;i++)
	{
		powaznystos.wypelnij(10000);
		powaznystos.find(1);
		cout <<endl;
		s.mierz_czas_stop();
		cout << endl;
		powaznystos.wyczysc();
	}
	s.srednia();
	return 0;
}
