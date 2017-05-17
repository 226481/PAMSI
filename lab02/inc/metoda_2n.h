#ifndef METODA_2N_KLASA_HH
#define METODA_2N_KLASA_HH

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <ctime>
#include "stoper.h"
#include "interfejs.h"

//Tomasz Perczyñski, 226481, PAMSI 14:00-16:15
using namespace std;

class tablica_2n
	{
		private:
		int* tab;
		int n;
		int ilosc;
		
		public:
		tablica_2n(int rozmiar);
		void wypelnianie();
		void wyswietl(int pierogi);
		int rozmiar();
		void powieksz();
		void pomniejsz(int pierogi);
		void czysto();
	};

	tablica_2n::tablica_2n(int rozmiar)
	{
		ilosc = rozmiar;
		n=1;
		tab=new int [n];
		tab[0]=rand()%10;
	}
	
	void tablica_2n::czysto()
	{	
		delete [] tab;
	 	n=1;
		tab = new int [n];
	}
	
	int tablica_2n::rozmiar()
	{
		return n;
	}
	
	void tablica_2n::powieksz()
	{		
		int* tab1 = new int [2*n];
		for (int i=0; i<n; i++)
		{
			tab1[i]=tab[i];
		}
		tab = tab1;
		n=2*n;
	}
	
	void tablica_2n::wypelnianie()
	{
		for(int i=(n/2)-1; i<n; i++)
		{
			tab[i]=rand()%10;
		}
	}
		
	void tablica_2n::wyswietl(int pierogi)
	{
        for(int j=0; j<pierogi; j++)
		{
				cout<<tab[j]<<" ";
		}
	}
		
	void tablica_2n::pomniejsz(int pierogi)
	{
		if(n>2*pierogi)
		{
			n=n/2;
		}
	}
	
#endif

