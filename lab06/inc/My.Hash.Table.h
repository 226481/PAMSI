#ifndef MY_HASZ_HH
#define MY_HASZ_HH

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <ctime>
#include "interfejs.h"

//Tomasz Perczyñski, 226481, PAMSI 14:00-16:15
using namespace std;

struct List_El
{
	List_El* next;	
	string Value;
};



class My_Hash_Table
{
		int Size;
		string Znak;
		List_El** Tab;
	public:
		My_Hash_Table(int x);
		int Hash(string Znak);
		string Generate();
		void Display();
		void Add();
};

My_Hash_Table::My_Hash_Table(int x)
{
		Size=x;
		Tab = new List_El* [x];
		for(int i=0; i<Size; i++)
		{
			Tab[i] = NULL;
		}
}


void My_Hash_Table::Add()
{
	string Temp = Generate();
	int Indeks = Hash(Temp);
	List_El* list=new List_El;
	list->Value = Temp;
	list->next=Tab[Indeks];
	Tab[Indeks]=list;
	}

int My_Hash_Table::Hash(string Znak)
{
	int h=0;
	for (int i = 0; i<Znak.length(); i++)
	{
		h += Znak[i];
	}
	return h%Size;
}

string My_Hash_Table::Generate()
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

void My_Hash_Table::Display()
{
	List_El* Temp;
	
	for(int i=0; i<Size; i++)
	{
		for(Temp=Tab[i];Temp;Temp=Temp->next)
		cout<<Temp->Value<<" ";
		cout<<endl;
	}
}

#endif
