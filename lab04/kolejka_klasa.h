#ifndef KOLEJKA_KLASA_HH
#define KOLEJKA_KLASA_HH

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <tchar.h>
#include <cstdlib>
#include <string>
#include "interfejs.h"

//Tomasz Perczyñski 226481, PAMSI œroda 14:00-16:00.
// KOLEJKA KLASA

using namespace std;

class kolejka:public interfejs
{
	int start;
	int rozmiar;
	int* tablica_kolejka;
	
	public:
	kolejka();
	void add(int liczba);
	void find(int liczba);
	int get();
	int size();
	void wypelnij(int ilosc);
	void pop();
	void wyczysc();
	
};

kolejka::kolejka()
{
	rozmiar = 0;
	tablica_kolejka = new int[rozmiar];
}

void kolejka::wypelnij(int ilosc)
{
	for(int i=0; i<ilosc; i++)
	{
		cout << "elo";
		add(rand()%2);
	}
}

void kolejka::wyczysc()
{
		for(int i=0; i<rozmiar; i++)
		{
			pop();
		}
	
}

void kolejka::pop()
{
	int* tablica_kolejka1 = new int [rozmiar-1];
	for (int i=1; i<rozmiar;i++)
	{
		tablica_kolejka1[i]=tablica_kolejka[i];
	}
	delete [] tablica_kolejka;
	tablica_kolejka=tablica_kolejka1;
	rozmiar--;
}

void kolejka::add(int liczba)
{
	int* tablica_kolejka1 = new int[rozmiar+1];
	for(int i=0; i<rozmiar;i++)
	{
		tablica_kolejka1[i]=tablica_kolejka[i];
	}
	tablica_kolejka1[rozmiar+1]=liczba;
	delete [] tablica_kolejka;
	tablica_kolejka = tablica_kolejka1;
	rozmiar++;
}

void kolejka::find(int liczba)
{
	int* tablica_kolejka1[rozmiar];
	for(int i=0; i<rozmiar; i++)
	{
		if(liczba==get())
		{
			cout<<"Element znajduje sie na stosie"<<endl;
			break;
		}
		else
		{
			pop();
		}
	}
}

int kolejka::get()
{
	return tablica_kolejka[rozmiar-1];
}

int kolejka::size()
{
	return rozmiar;
}

#endif
