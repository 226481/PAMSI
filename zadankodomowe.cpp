#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <ctime>
using namespace std;
class tablica
	{
		private:
		int* tab;
		long int n;
		long int ilosc;
		
		public:
		tablica(int rozmiar);
		void wypelnianie();
		void wyswietl();
		void maks();
		long int rozmiar();
		void powieksz();
	};

	tablica::tablica(int rozmiar)
	{
		ilosc = rozmiar;
		n=1;
		tab=new int [n];
	}
	
	long int tablica::rozmiar()
	{
		return n;
	}
	
	void tablica::powieksz()
	{		
		int* tab1 = new int [n+1];
		for (int i=0; i<n; i++)
		{
			tab1[i]=tab[i];
		}
		tab = tab1;
		n++;
	}
	
	void tablica::wypelnianie()
	{
		tab[n-1]=rand()%10;
		}
	void tablica::wyswietl()
	{
        for(int j=0; j<n; j++)
		{
				cout<<tab[j]<<" ";
		}
	}
	void tablica::maks()
	{
		int maks=0;
		for(int j=0; j<n; j++)
		{
				if(tab[j]>maks)
				maks=tab[j];
			}
		cout <<endl<<"Maksymalna wartosc: "<<maks;
	}
	
int main()
{
	clock_t start = clock();
	long int pierogi;
	pierogi = 100000;
	tablica* omlet=new tablica(pierogi);
	while(omlet->rozmiar()!=pierogi)
	{
	omlet->wypelnianie();
	omlet->powieksz();
    }
    omlet->wypelnianie();
	omlet->wyswietl();
	cout << endl;
	cout<<"Czas wykonywania: ms\n"<< clock() - start;
 	return 0;
}
