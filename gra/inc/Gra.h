#ifndef Gra_HH
#define Gra_HH

#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<time.h>

using namespace std;

//Tomasz Perczyñski, PAMSI czw. 14:00-16:00
//Kó³ko i krzy¿yk 

class Game
{
	private:
		char Plansza[3][3]; // plansza jak plansza
		char Znak_X; // krzyzyk
		char Znak_O; // kolko
		char Odp_Poziom; // zmienna podawana przez gracza, decydujaca o poiomie trudnosci
		int Licznik; // zmienna wykorzystywana przy remisie
		bool Win_O; // zmienna wykorzystywana do wyznaczania wygranej gracza
		bool Win_X; // zmienna wykorzystywana do wyznaczania wygranej komputera
		bool Poziom; // zmienna decydujaca o poziomie trudnosci
		bool Draw; // zmienna decydujaca o remisie
		int Wiersz;
		int Kolumna;
	public:
		Game();
		void Rysuj_Plansze(); // metoda rysujaca plansze
		bool Wygrana(); // metoda sprwdzajaca czy ktos spelnil warunki wygranej
		bool Wygrana_M(); // metod sprwdzajaca zwyciestwo stosowana w MiniMaxie
		bool Remis(); // metoda sprawdzajaca czy zostal spelniony warunek remisu
		int MiniMax(char gracz);
		void Przeciwnik(char gracz); // ruch przeciwnika
		void Ruch(); // ruch gracza
		void Start(); // wszystkie metody odpowiednio uporzadkowane
		void Zasady(); // wyswietla zasady gry
		void Czysto(); // czysci plansze w razie ponownej gry
		void Trudnosc(); // decyduje o poziomie trudnosci
		void Komputer(); // okreœla ruch komputera 
};

#endif
