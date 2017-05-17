#ifndef KONTENER_HH
#define KONTENER_HH

#include<cstdio>
#include<iostream>

using namespace std;

class ikolejka
{
public:
  interfejs();
  int start;
  int* tablica;
  int licznik;
  int element;
  int rozmiar;
  void add(int element);
  int get();
  int size();
  void find(int element);
};

interfejs::interfejs()
{
  rozmiar = 1;
  tablica = new int [rozmiar];
  start = licznik = 0;
};

void interfejs::add(int element)
{
  int i=0;
  i=start+licznik++;
  tablica[i]=element;
  rozmiar++;
}

int interfejs::size()
{
  return rozmiar;
}

int interfejs::get()
{
  return tablica[rozmiar-1];
};

void interfejs::find(int element)
{
  int i=0;
  for(i; i<rozmiar; i++)
    {
      if(tablica[i]==element)
	{
	  cout <<"Szukany element instnieje i znajduje się na pozycji: "<<i;
	  break;
	}
      else
	{
	  cout<<"Szukany element nie istnieje";
	}
    }
};

#endif
