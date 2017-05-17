#ifndef HASZ_HH
#define HASZ_HH

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <ctime>
#include "interfejs.h"

//Tomasz Perczyñski, 226481, PAMSI 14:00-16:15
using namespace std;


class Hash_Table
{
	private:
		int Size;
		string Znak;
		string* Tab;
	public:
		Hash_Table(int x);
		int Hash(string Znak);
		string Generate();
		void Display();
		void Add();
};

Hash_Table::Hash_Table(int x)
{
		Tab = new string [x];
		for(int i=0; i<x; i++)
		{
			Tab[i] = "";
		}
		Size = x;
}

void Hash_Table::Add()
{
	string Temp = Generate();
	int Indeks = Hash(Temp);
	while(true)
	{
		if(Tab[Indeks]=="")
		{
			Tab[Indeks]=Temp;
			break;
		}
		if(Tab[Indeks]==Temp)
		break;
		
		Indeks = ++Indeks % 10;
		
		if(Indeks == Hash(Temp))
		break;
	}
}

int Hash_Table::Hash(string Znak)
{
	int h=0;
	for (int i = 0; i<Znak.length(); i++)
	{
		h = 2*h+1-(Znak[i] & 1);
	}
	return h%31;
}

string Hash_Table::Generate()
{
	int x;
	x = rand()%10;
	string Znak ="";
	int m = 8;
	while(m)
	{
		Znak+=(x&m)? 'B' : 'A';
		m>>=1;
	}
	return Znak;
}

void Hash_Table::Display()
{
	for(int i=0; i<Size; i++)
	{
		cout<<Tab[i]<<endl;
	}
}

#endif
