#ifndef TABLICA_HH
#define TABLICA_HH

#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include <ctime>
#include "interfejs.h"

using namespace std;

class tablica:public sortowanie
{
	private:
		
		int rozmiar;
	public:
		int* tab;
 		tablica(int rozmiar);
 		void sortuj(int tab[], int k, int l);
 		int czesci(int tab[], int k, int l);
 		void wyswietl(int rozmiar);
 		void wypelnij_losowo(int rozmiar);
 		void wypelnij_rosnoca(int rozmiar);
 		void wypelnij_malejaco(int rozmiar);
};

tablica::tablica(int rozmiar)
{
	tab = new int [rozmiar];
}

void tablica::wypelnij_losowo(int rozmiar)
{
	for(int i=0; i<rozmiar; i++)
	{
		tab[i]=rand()%10;
	}
}

void tablica::wypelnij_rosnoca(int rozmiar)
{
	for(int i=0; i<rozmiar; i++)
	{
		tab[i]=i;
	}
}

void tablica::wypelnij_malejaco(int rozmiar)
{
	int j = rozmiar;
	for(int i=0; i<rozmiar; i++)
	{
		tab[i]=j;
		j--;
	}
}

void tablica::wyswietl(int rozmiar)
{
	for(int i=0; i<rozmiar; i++)
	{
		cout<<tab[i]<<" ";
	}
	cout<<endl;
}

void tablica::sortuj(int tab[], int k, int l)
{
	int o;
	if(k<l)
	{
		o = czesci(tab, k, l);
		sortuj(tab, k, o);
		sortuj(tab, k+1, l);
	}
	
}

int tablica::czesci(int tab[], int k, int l)
{
	int o = tab[k];
	int i = k;
	int j = l;
	int w;
	while(true)
	{
		while(tab[j]>o)
		{
			j--;
		}
		while(tab[i]<o)
		{
			i++;
		}
		if(i<j)
		{
			w = tab[i];
			tab[i]=tab[j];
			tab[j]=w;
			i++;
			j--;
		}
		else
		{
			return j;
		}
	}
	
}

#endif
