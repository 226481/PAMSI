#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include "../inc/lista_klasa.h"
#include "../inc/kolejka_klasa.h"
#include "../inc/stos_klasa.h"
#include "../inc/stoper.h"

using namespace std;

int main()
{
	srand(time(NULL));
	stoper s;
	//stos temp;
	lista temp;
	//kolejka temp;
	s.mierz_czas_start();
	for(int i=0; i<20;i++)
	{
		temp.wypelnij(100);
		temp.find(1);
		cout <<endl;
		s.mierz_czas_stop();
		cout << endl;
		temp.wyczysc();
	}
	s.srednia();
	return 0;
}
