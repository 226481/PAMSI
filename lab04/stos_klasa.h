#ifndef STOS_KLASA_HH
#define STOS_KLASA_HH

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <tchar.h>
#include <cstdlib>
#include <string>
#include "interfejs.h"

//Tomasz Perczyñski 226481, PAMSI œroda 14:00-16:00.
// STOS KLASA

using namespace std;

class stos:public interfejs
{
	int start;
	int rozmiar;
	int* tablica_stos;
	
	public:
	stos();
	void add(int element);
	int get();
	void find(int element);
	int size();
	void wypelnij(int ilosc);
	void pop();
	void wyczysc();
};

stos::stos()
{
	rozmiar = 0;
	tablica_stos = new int [rozmiar];
}

void stos::wyczysc()
{
	for(int i=0; i<rozmiar; i++)
	{
		pop();
	}
}

void stos::wypelnij(int ilosc)
{
	for(int i=0; i<ilosc; i++)
	{
		add(rand()%2);
	}
}

void stos::add(int element)
{
	int* tablica_stos1 = new int[rozmiar+1];
	for(int i=0; i<rozmiar;i++)
	{
		tablica_stos1[i]=tablica_stos[i];
	}
	tablica_stos1[rozmiar+1]=element;
	delete [] tablica_stos;
	tablica_stos = tablica_stos1;
	rozmiar++;
}

void stos::find(int element)
{
	int* tablica_stos1[rozmiar];
	for(int i=0; i<rozmiar; i++)
	{
		if(element==get())
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

void stos::pop()
{
	int* tablica_stos1 = new int [rozmiar-1];
	for (int i=0; i<rozmiar-1;i++)
	{
		tablica_stos1[i]=tablica_stos[i];
	}
	delete [] tablica_stos;
	tablica_stos=tablica_stos1;
	rozmiar--;
}

int stos::get()
{
	return tablica_stos[rozmiar-1];
}

int stos::size()
{
	return rozmiar;
}

#endif
