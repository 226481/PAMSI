#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include <ctime>
#include "../inc/interfejs.h"
#include "../inc/stoper.h"
#include "../inc/tablica.h"

using namespace std;

int main()
{
	srand(time(NULL));
	stoper s;
	s.mierz_czas_start();
	int rozmiar = 100;
	tablica* Tab=new tablica(rozmiar);
	Tab->wypelnij_losowo(rozmiar);
	//Tab->wypelnij_malejaco(rozmiar);
	//Tab->wypelnij_rosnoca(rozmiar);
	Tab->wyswietl(rozmiar);
	Tab->sortuj(Tab->tab, 0, rozmiar-1);
	Tab->wyswietl(rozmiar);
	s.mierz_czas_stop();
	
	return 0;
}
