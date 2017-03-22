#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <ctime>

//Tomasz Perczyñski, 226481, PAMSI 14:00-16:15
using namespace std;

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
	start = clock();
}

void stoper::mierz_czas_stop()
{
	cout <<"Zmierzony czas to: "<<clock()<<" ms";
	pomiar+=clock()-start;
}

void stoper::srednia()
{
	cout <<endl;
	cout <<"Srednia po 20 pomiarach to: "<<clock()/20;
}



class tablica
	{
		private:
		int* tab;
		int n;
		int ilosc;
		
		public:
		tablica(int rozmiar);
		void wypelnianie();
		void wyswietl(int pierogi);
		int rozmiar();
		void powieksz();
		void pomniejsz(int pierogi);
		void czysto();
	};

	tablica::tablica(int rozmiar)
	{
		ilosc = rozmiar;
		n=1;
		tab=new int [n];
		tab[0]=rand()%10;
	}
	
	void tablica::czysto()
	{	
		delete [] tab;
	 	n=1;
		tab = new int [n];
	}
	
	int tablica::rozmiar()
	{
		return n;
	}
	
	void tablica::powieksz()
	{		
		int* tab1 = new int [2*n];
		for (int i=0; i<n; i++)
		{
			tab1[i]=tab[i];
		}
		tab = tab1;
		n=2*n;
	}
	
	void tablica::wypelnianie()
	{
		for(int i=(n/2)-1; i<n; i++)
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
		
	void tablica::pomniejsz(int pierogi)
	{
		if(n>2*pierogi)
		{
			n=n/2;
		}
	}
	
int main()
{
	stoper s;
	s.mierz_czas_start();
	int pierogi;
	pierogi=1000000;
	tablica* omlet=new tablica(pierogi);
	
	for(int j=0; j<20; j++)
	{
		while(omlet->rozmiar()<=pierogi)
		{
		omlet->powieksz();
		omlet->wypelnianie();
		}
    cout<<endl;
    s.mierz_czas_stop();
	omlet->czysto();
	}
	
    omlet->pomniejsz(pierogi);
	cout << endl;
	s.srednia();
 	return 0;
}
