#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <ctime>
using namespace std;

//Tomasz Perczyñski, 226481, PAMSI 14:00-16:15
class stoper
	{
		clock_t start;
		int pomiar=0;
		
		public:
		void srednia();
		void mierz_czas_start();
		void mierz_czas_stop();
	};
	
void stoper::mierz_czas_start()
{
	start = clock()-start;
}

void stoper::mierz_czas_stop()
{
	cout <<"Zmierzony czas to: "<<clock()<<" ms";
	pomiar+=clock();
}

void stoper::srednia()
{
	cout <<endl;
	cout <<"Srednia po 20 pomiarach to: "<<clock()/20;
}


class tablica: public stoper
	{
		private:
		int* tab;
		long int n;
		long int ilosc;
				
		public:
		tablica(int rozmiar);
		void wypelnianie();
		void wyswietl();
		long int rozmiar();
		void powieksz();
		void czysto();
	};

	tablica::tablica(int rozmiar)
	{
		ilosc = rozmiar;
		n=1;
		tab=new int [n];
	}
	
	void tablica::czysto()
	{	
	 	delete [] tab;
	 	n=1;
		tab = new int [n];
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
	
int main()
{
	stoper s;
	s.mierz_czas_start();
	long int pierogi;
	pierogi = 10000;
	tablica* omlet=new tablica(pierogi);
	
	for(int j=0; j<20; j++)
	{
		while(omlet->rozmiar()!=pierogi)
		{
		omlet->wypelnianie();
		omlet->powieksz();
   	 }
   	 cout<<endl;
   	 s.mierz_czas_stop();
   	 omlet->czysto();
	}
	
    omlet->wypelnianie();
	cout<<endl;
	s.mierz_czas_stop();
	s.srednia();
 	return 0;
}
