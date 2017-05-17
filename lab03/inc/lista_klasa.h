#ifndef LISTA_KLASA_HH
#define LISTA_KLASA_HH

#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <tchar.h>
#include <cstdlib>
#include <string>
#include "interfejs.h"

//Tomasz Perczy�ski 226481, PAMSI �roda 14:00-16:00.
// LISTA KLASA
using namespace std;

class costam
{
	public:
	costam* nastepny;
	int a;
	costam(int liczba);
};

costam::costam(int liczba)
{
	nastepny = 0;
	a=liczba;
}

class lista:public interfejs
{
	costam* pierwszy;
	costam* nowy;
	
	public:
	int licznik;
	lista();
	void wyswietl_liste();
	void add(int element);
	int get();
	void find(int element);
	int size();
	void wypelnij(int ilosc);
	void wyczysc();
};

lista::lista()
{
	pierwszy=NULL;
	licznik=0;
}

void lista::wyczysc()
{
	costam* uno;
	costam* dos;
	uno=pierwszy;
	while(uno)
	{
		dos=uno;
		uno=uno->nastepny;
		delete dos;
	}
	pierwszy = NULL;
}

void lista::wypelnij(int ilosc)
{
	for(int i=0; i<ilosc; i++)
	{
		
		add(rand()%100);
	}
}
 
	int lista::get()
	{
		costam* temp=pierwszy;
		while(temp ->nastepny)
		{
			temp = temp -> nastepny;
		}
		return temp->a; 
	}
	
	void lista::find(int element)
	{
		costam* temp=pierwszy;
		while(temp -> nastepny)
		{
			if(element == temp->a )
			{
				cout << "Poszukiwany element znajduje sie w liscie."<<endl;
				break;
				}
			temp = temp-> nastepny;	
		}	
	}
	
	int lista::size()
	{
		return licznik;
	}

void lista::wyswietl_liste()
{
	costam *t = pierwszy;
	while(t)
	{
		cout << t->a<<endl;
		t=t->nastepny;
		
	}
}

void lista::add(int liczba)
{
	nowy = new costam(liczba);
	nowy->nastepny=NULL;
	if(pierwszy==NULL)
	{
		pierwszy=nowy;
	}
	else
	{
		costam* t = pierwszy;
		while(t->nastepny)
		{
			t=t->nastepny;
		}
	t->nastepny=nowy;
	nowy->nastepny=NULL;
	licznik++;
	}
}

#endif
