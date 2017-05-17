#ifndef INTERFEJS_HH
#define INTERFEJS_HH

#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include <ctime>
#include "stoper.h"

using namespace std;

class Hasz
{
	public:
		Hasz();
		virtual void Display();
		virtual void Add();
		virtual int Hash(string Znak);
		virtual string Generate();
		virtual ~Hasz();
};

Hasz::Hasz()
{
}

Hasz::~Hasz()
{
}

void Hasz::Add()
{
}

void Hasz::Display()
{
}

string Hasz::Generate()
{
}

int Hasz::Hash(string Znak)
{
}

#endif
