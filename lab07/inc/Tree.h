#ifndef Temp_HH
#define Temp_HH

#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include <ctime>
#include "interface.h"

using namespace std;

struct Wezel
{
	int Klucz;
	Wezel* Left;
	Wezel* Right;
	
};

class Temp
{
	private:
	Wezel* Korzen;
	public:
	Temp();
	Wezel* GetKorzen();
	bool Find(int klucz);
	void Insert(int klucz);
	void Preorder(Wezel* Temp);
	void Inorder(Wezel* Temp);
	void Postorder(Wezel* Temp);
};

Temp::Temp()
{
	Korzen = NULL;
}

Wezel* Temp::GetKorzen()
{
	return Korzen;
}

bool Temp::Find(int klucz)
{
	Wezel* Temp;
	Temp = Korzen;
	do
	{
		if(klucz > Temp->Klucz)
		{
			if(Temp->Right != NULL)
			{
				Temp = Temp->Right;
			}
			else
			{
				return false;
			}
		}
		else if (klucz < Temp->Klucz)
		{
			if(Temp->Left != NULL)
			{
				Temp = Temp->Left;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}
	while(true);
}

void Temp::Insert(int Klucz)
{
	if(Korzen == NULL)
	{
		Wezel* Nowy = new Wezel;
		Nowy->Klucz = Klucz;
		Nowy->Right = NULL;
		Nowy->Left = NULL;
		Korzen = Nowy;
		return;
	}
	Wezel* Temp;
	Temp = Korzen;
	do
	{		
		if(Klucz<Temp->Klucz)
		{
			if(Temp->Left==NULL)
			{
				Wezel* Nowy = new Wezel;
				Nowy->Klucz = Klucz;
				Nowy->Right = NULL;
				Nowy->Left = NULL;
				Temp->Left = Nowy;
				break;
			}
		}
		else
		{
			if(Temp->Right==NULL)
			{
				Wezel* Nowy = new Wezel;
				Nowy->Klucz = Klucz;
				Nowy->Right = NULL;
				Nowy->Left = NULL;
				Temp->Right = Nowy;
				break;
			}
		}
		if(Klucz<Temp->Klucz)
		{
			Temp = Temp->Left;
		}
		else
		{
			Temp = Temp->Right;
		}
	}
	while(true);
}

void Temp::Inorder(Wezel* A)
{
	Wezel* Temp = A;
	if(Temp != NULL)
	{
		Inorder(Temp->Left);
		cout << Temp->Klucz;
		cout <<endl;
		Inorder(Temp->Right);
		}	
}

void Temp::Preorder(Wezel* A)
{
	Wezel* Temp = A;
	if(Temp!=NULL)
	{
		cout<<Temp->Klucz;
		cout<<endl;
		Preorder(Temp->Left);
		Preorder(Temp->Right);
		}	
}

void Temp::Postorder(Wezel* A)
{
	Wezel* Temp = A;
	if(Temp != NULL)
	{
		Postorder(Temp->Left);
		Postorder(Temp->Right);
		cout<<Temp->Klucz;
		cout<<endl;
	}
}

#endif
