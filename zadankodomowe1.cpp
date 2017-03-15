#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <ctime>
using namespace std;
class tablica
	{
		private:
		long int* tab;
		int n;
		int ilosc;
		
		public:
		tablica(int rozmiar);
		void wypelnianie(int pierogi);
		void wyswietl(int pierogi);
		void maks();
		int rozmiar();
		void powieksz();
		void pomniejsz(int pierogi);
	};

	tablica::tablica(int rozmiar)
	{
		ilosc = rozmiar;
		n=1;
		tab=new long int [n];
		tab[0]=rand()%10;
	}
	
	int tablica::rozmiar()
	{
		return n;
	}
	
	void tablica::powieksz()
	{		
		long int* tab1 = new long int [2*n];
		for (int i=0; i<n; i++)
		{
			tab1[i]=tab[i];
		}
		tab = tab1;
		n=2*n;
	}
	
	void tablica::wypelnianie(int pierogi)
	{
		for(int i=(n/2)-1; i<pierogi; i++)
		{
			tab[i]=rand()%10;
		}
	}
	
	
	void tablica::wyswietl(int pierogi)
	{
        for(int j=0; j<pierogi; j++)
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
	
	void tablica::pomniejsz(int pierogi)
	{
		if(n>2*pierogi)
		{
			n=n/2;
		}
	}
	
int main()
{
	clock_t start = clock();
	int pierogi;
	pierogi=10000;
	tablica* omlet=new tablica(pierogi);
	while(omlet->rozmiar()>=pierogi)
	{
	omlet->powieksz();
	omlet->wypelnianie(pierogi);
    }
    omlet->pomniejsz(pierogi);
	omlet->wyswietl(pierogi);
	cout << endl;
	cout<<"Czas wykonywania: ms\n"<< clock() - start;
 	return 0;
}
