#ifndef METODA_N_KLASA_HH
#define METODA_N_KLASA_HH


#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <ctime>
#include "stoper.h"
#include "interfejs.h"

using namespace std;

//Tomasz Perczyñski, 226481, PAMSI 14:00-16:15


class tablica_n
	{
		private:
		int* tab;
		long int n;
		long int ilosc;
				
		public:
		tablica_n(int rozmiar);
		void wypelnianie();
		void wyswietl();
		long int rozmiar();
		void powieksz();
		void czysto();
	};

	tablica_n::tablica_n(int rozmiar)
	{
		ilosc = rozmiar;
		n=1;
		tab=new int [n];
	}
	
	void tablica_n::czysto()
	{	
	 	delete [] tab;
	 	n=1;
		tab = new int [n];
	}
	
	long int tablica_n::rozmiar()
	{
		return n;
	}
	
	void tablica_n::powieksz()
	{		
		int* tab1 = new int [n+1];
		for (int i=0; i<n; i++)
		{
			tab1[i]=tab[i];
		}
		tab = tab1;
		n++;
	}
	
	void tablica_n::wypelnianie()
	{
		tab[n-1]=rand()%10;
	}
		
	void tablica_n::wyswietl()
	{
        for(int j=0; j<n; j++)
		{
				cout<<tab[j]<<" ";
		}
	}
	
#endif
