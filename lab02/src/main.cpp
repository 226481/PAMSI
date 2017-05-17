#include <iostream>
#include <cstdio>
#include "../inc/metoda_2n.h"
#include "../inc/metoda_n.h"

using namespace std;

int main()

{
	int pierogi = 100;
	stoper s;
	tablica_n* omlet = new tablica_n (pierogi);
	//tablica_2n* omlet = new tablica_2n (pierogi);
	s.mierz_czas_start();
	for(int i=0; i<20; i++)
	{
		while(omlet->rozmiar()<=pierogi)
		{
			omlet->powieksz();
			omlet->wypelnianie();
		}
		cout<<endl;
		s.mierz_czas_stop();
		omlet->czysto();
	}
	cout<<endl;
	s.srednia();
	
	return 0;
}
