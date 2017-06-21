#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include "../inc/Gra.h"

using namespace std;

//Tomasz Perczyñski, PAMSI czw. 14:00-16:00
//Kó³ko i krzy¿yk

Game::Game()
{
	Win_O = false;
	Win_X = false;
	Licznik = 0;
	Znak_X = 'X';
	Znak_O = 'O';
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			Plansza[i][j] = ' ';
		}
	}
}

//metoda sluzaca do czyszczenia tablicy
void Game::Czysto()
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			Plansza[i][j] = ' ';
		}
	}	
}

//metoda sprawdzajaca wygrana uzywana w algorytmie minimax
bool Game::Wygrana_M()
{
	bool Remis;
	int i;
	int j=0;
	Win_X = false;
	Win_O = false;

	//Sprawdznie wygranej dla X
	for(i=0; i<3; i++) // Sprawdzamy wiersze
	{
		if(Plansza[i][j] == Znak_X && Plansza[i][j+1] == Znak_X && Plansza[i][j+2] == Znak_X)
		{
			Win_X = true;	
			break;
		}
	}

	for(i=0; i<3; i++) // Sprawdzamy kolumny
	{
		if(Plansza[j][i] == Znak_X && Plansza[j+1][i] == Znak_X && Plansza[j+2][i] == Znak_X)
		{
			Win_X = true;		
			break;
		}
	}

	if(Plansza[0][0] == Znak_X && Plansza[1][1] == Znak_X && Plansza[2][2] == Znak_X) //Sprawdzamy pierwszy skos
	{	 
		Win_X = true;		
	}
	
	else if(Plansza[0][2] == Znak_X && Plansza[1][1] == Znak_X && Plansza[2][0] == Znak_X) //Sprawdzamy drugi skos
	{ 
		Win_X = true;		
	}
	
	//Sprawdznie wygranej dla O
	for(i=0; i<3; i++) // Sprawdzamy wiersze
	{
		if(Plansza[i][j] == Znak_O && Plansza[i][j+1] == Znak_O && Plansza[i][j+2] == Znak_O)
		{
			Win_O = true;
			break;
		}
	}
	
	for(i=0; i<3; i++) // Sprawdzamy kolumny
	{
		if(Plansza[j][i] == Znak_O && Plansza[j+1][i] == Znak_O && Plansza[j+2][i] == Znak_O)
		{
			Win_O = true;
			break;
		}
	}
	
	if(Plansza[0][0] == Znak_O && Plansza[1][1] == Znak_O && Plansza[2][2] == Znak_O) //Sprawdzamy pierwszy skos
	{	 
		Win_O = true;
	}
	
	else if(Plansza[0][2] == Znak_O && Plansza[1][1] == Znak_O && Plansza[2][0] == Znak_O) //Sprawdzamy drugi skos
	{ 
		Win_O = true;		
	}
}

//metoda wyswietlajaca zasady gry
void Game::Zasady()
{
	
	cout<<"Kolko i krzyzyk - Tomasz Perczynki"<<endl;
	cout<<"********************************"<<endl<<endl;
	int k = 1;
	int tab[3][3];
	
	cout<<"Pola planszy sa przypisane odpowiednio do kolejnych cyfr: "<<endl<<endl;
	
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			tab[i][j] = k;
			k++;
		}
	}
	
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<" "<<tab[i][j]<<" ";
			if(j<2)
			cout<<"|";
		}
		cout <<endl;
		if(i<2)
		cout <<"---+---+---"<<endl;
	}
}

//metoda odpowiadajaca za rysowanie planszy
void Game::Rysuj_Plansze()
{
	cout<<endl;
	cout<<"********************************"<<endl<<endl;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<" "<<Plansza[i][j]<<" ";
			if(j<2)
			cout<<"|";
		}
		cout <<endl;
		if(i<2)
		cout <<"---+---+---"<<endl;
	}
}

//metoda odpowiadajaca za sprawdzanie wygranej
bool Game::Wygrana()
{
	bool Remis;
	int i;
	int j=0;
	Win_X = false;
	Win_O = false;

	//Sprawdznie wygranej dla X
	for(i=0; i<3; i++) // Sprawdzamy wiersze
	{
		if(Plansza[i][j] == Znak_X && Plansza[i][j+1] == Znak_X && Plansza[i][j+2] == Znak_X)
		{
			Win_X = true;
			cout<<endl;
			cout <<"Wygral gracz: "<<Znak_X;	
			break;
		}
	}

	for(i=0; i<3; i++) // Sprawdzamy kolumny
	{
		if(Plansza[j][i] == Znak_X && Plansza[j+1][i] == Znak_X && Plansza[j+2][i] == Znak_X)
		{
			Win_X = true;
			cout<<endl;
			cout <<"Wygral gracz: "<<Znak_X;		
			break;
		}
	}

	if(Plansza[0][0] == Znak_X && Plansza[1][1] == Znak_X && Plansza[2][2] == Znak_X) //Sprawdzamy pierwszy skos
	{	 
		Win_X = true;
		cout<<endl;
		cout <<"Wygral gracz: "<<Znak_X;		
	}
	
	else if(Plansza[0][2] == Znak_X && Plansza[1][1] == Znak_X && Plansza[2][0] == Znak_X) //Sprawdzamy drugi skos
	{ 
		Win_X = true;
		cout<<endl;
		cout <<"Wygral gracz: "<<Znak_X;		
	}
	
	//Sprawdznie wygranej dla O
	for(i=0; i<3; i++) // Sprawdzamy wiersze
	{
		if(Plansza[i][j] == Znak_O && Plansza[i][j+1] == Znak_O && Plansza[i][j+2] == Znak_O)
		{
			Win_O = true;
			cout<<endl;
			cout <<"Wygral gracz: "<<Znak_O;
			break;
		}
	}
	
	for(i=0; i<3; i++) // Sprawdzamy kolumny
	{
		if(Plansza[j][i] == Znak_O && Plansza[j+1][i] == Znak_O && Plansza[j+2][i] == Znak_O)
		{
			Win_O = true;
			cout<<endl;
			cout <<"Wygral gracz: "<<Znak_O;
			break;
		}
	}
	
	if(Plansza[0][0] == Znak_O && Plansza[1][1] == Znak_O && Plansza[2][2] == Znak_O) //Sprawdzamy pierwszy skos
	{	 
		Win_O = true;
		cout<<endl;
		cout <<"Wygral gracz: "<<Znak_O;
	}
	
	else if(Plansza[0][2] == Znak_O && Plansza[1][1] == Znak_O && Plansza[2][0] == Znak_O) //Sprawdzamy drugi skos
	{ 
		Win_O = true;
		cout<<endl;
		cout <<"Wygral gracz: "<<Znak_O;		
	}
}

//metoda odpowiadajaca za sprawdzanie remisu
bool Game::Remis()
{
	if (Win_O == false && Licznik >= 9 && Win_X == false)
	{
		cout<<endl;
		cout<<"Remis, zaden z graczy nie wygral.";
		Draw == true;
	}
}

//metoda odpowiadajaca za wybor trudnosci
void Game::Trudnosc()
{
	bool Temp = false;
	cout <<endl;
	cout <<"Prosze wybrac poziom trudnosci - l-latwy, t-trudny: "<<endl;
	while(Temp == false)
	{
	cin >> Odp_Poziom;
	if(Odp_Poziom == 'l')
	{
		Poziom = true;
		Temp = true;
	}
	else if(Odp_Poziom == 't')
	{
		Poziom = false;
		Temp = true;
	}
		else
	{
		cout<<"Niepoprawna odpowiedz, prosze podac jeszcze raz poziom trudnosci: "<<endl;
	}
	}
}

//metoda odpowiedzialna za kolejne uruchomienie odpowiednich metod aby gra funkcjonowala
void Game::Start()
{
	Licznik = 0;
	char Odpowiedz;
	char gracz = 'X';
	Win_O = false;
	Win_X = false;
	Zasady();
	Trudnosc();
	Rysuj_Plansze();
	while(Win_O == false && Win_X == false && Draw == false)
	{
		Wygrana();
		Remis();
		Ruch();
		Przeciwnik(gracz);
		Rysuj_Plansze();
		Remis();
		Wygrana();
		Licznik = Licznik + 2;
	}
	while(Win_O == true || Win_X == true || Draw == true)
	{
		cout<<endl;
		cout<<"Chcesz zagrac jeszcze raz? t - Tak, n - Nie"<<endl;
		Odpowiedz = ' ';
		while(Odpowiedz != 't' || Odpowiedz != 'n')
		{
			cin >> Odpowiedz;
			if(Odpowiedz == 't')
			{
				Czysto();
				Start();
			}
			else if(Odpowiedz == 'n')
			{
				cout<<"Koniec gry";
				Win_O = false;
				Win_X = false;
				break;
				exit (0);
			}
			else
			cout<<"Niepoprawna odpowiedz, prosze odpowiedziec jeszcze raz: "<<endl;
		}
		if(Win_O == false && Win_X == false)
		{
			break;
		}
	}
}

//metoda sluzaca do wykonania ruchu przez gracza
void Game::Ruch()
{
	bool Puste;
	int Pole;
	cout<<endl;
	cout<<"Ruch gracz: "<<endl;
	Puste = false;
	while(Puste == false)
	{
		cin >> Pole;
		if(Pole > 0 && Pole < 10)
		{
		if(Pole == 1)
		{
			if(Plansza[0][0]==' ')
			{
				Plansza[0][0]='O';
				Puste = true;
				break;
			}
			else
			{
				cout<<"Podano niewlasciwa wartosc lub pole jest juz zajete. Prosze podac inne pole: "<<endl;
			}
		}
		
		else if (Pole == 2)
		{
			if(Plansza[0][1]==' ')
			{
				Plansza[0][1]='O';
				Puste = true;
				break;
			}
			else
			{
				cout<<"Podano niewlasciwa wartosc lub pole jest juz zajete. Prosze podac inne pole: "<<endl;
			}
		}
		
			else if (Pole == 3)
		{
			if(Plansza[0][2]==' ')
			{
				Plansza[0][2]='O';
				Puste = true;
				break;
			}
			else
			{
				cout<<"Podano niewlasciwa wartosc lub pole jest juz zajete. Prosze podac inne pole: "<<endl;
			}
		}
		
			else if (Pole == 4)
		{
			if(Plansza[1][0]==' ')
			{
				Plansza[1][0]='O';
				Puste = true;
				break;
			}
			else
			{
				cout<<"Podano niewlasciwa wartosc lub pole jest juz zajete. Prosze podac inne pole: "<<endl;
			}
		}
		
			else if (Pole == 5)
		{
			if(Plansza[1][1]==' ')
			{
				Plansza[1][1]='O';
				Puste = true;
				break;
			}
			else
			{
				cout<<"Podano niewlasciwa wartosc lub pole jest juz zajete. Prosze podac inne pole: "<<endl;
			}
		}
		
			else if (Pole == 6)
		{
			if(Plansza[1][2]==' ')
			{
				Plansza[1][2]='O';
				Puste = true;
				break;
			}
			else
			{
				cout<<"Podano niewlasciwa wartosc lub pole jest juz zajete. Prosze podac inne pole: "<<endl;
			}
		}
		
			else if (Pole == 7)
		{
			if(Plansza[2][0]==' ')
			{
				Plansza[2][0]='O';
				Puste = true;
				break;
			}
			else
			{
				cout<<"Podano niewlasciwa wartosc lub pole jest juz zajete. Prosze podac inne pole: "<<endl;
			}
		}
		
			else if (Pole == 8)
		{
			if(Plansza[2][1]==' ')
			{
				Plansza[2][1]='O';
				Puste = true;
				break;
			}
			else
			{
				cout<<"Podano niewlasciwa wartosc lub pole jest juz zajete. Prosze podac inne pole: "<<endl;
			}
		}
		
			else if (Pole == 9)
		{
			if(Plansza[2][2]==' ')
			{
				Plansza[2][2]='O';
				Puste = true;
				break;
			}
			else
			{
				cout<<"Podano niewlasciwa wartosc lub pole jest juz zajete. Prosze podac inne pole: "<<endl;
			}
		}
	}
		else
		{
			cout <<"Podano niewlasciwa wartosc lub pole jest juz zajete. Prosze podac inne pole: "<<endl;
		}
	}
}

//algorytm minimax
int Game::MiniMax(char gracz)
{
	int m;
	int mmx;
	
	Wygrana_M();
	Remis();
	
	if(Win_X == true)
	{
		if(gracz == 'X')
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	
	if(Draw == true)
	{
		return 0;
	}
	
	if(gracz == 'X')
	{
		gracz == 'O';
	}
	else
	{
		gracz == 'X';
	}
	
	if(gracz == 'O')
	{
		mmx = 10;
	}
	else
	{
		mmx = -10;
	}
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(Plansza[j][i] == ' ')
			{
				Plansza[j][i] = gracz;
				m = MiniMax(gracz);
				Plansza[j][i] = ' ';
				if(((gracz == 'O') && (m < mmx)) || ((gracz == 'X') && (m > mmx))) 
				{
					mmx = m;
				}
				return mmx;
			}
		}
	}
}

//Metoda decydujaca o ruchu komputera oprata na algrytmie minimax
void Game::Komputer()
{
	int m;
	int mmx;
	
	mmx = -10;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(Plansza[i][j] == ' ')
			{
				Plansza[i][j] = 'X';
				m = MiniMax('X');
				Plansza[i][j] = ' ';
				if(m > mmx)
				{
					mmx = m; 
					Kolumna = i;
					Wiersz = j;
				}
			}
		}
	}
	
}

//metoda okreslajaca ruch przzeciwinika w zaleznosci od wyboru poziomu trudnosci
void Game::Przeciwnik(char gracz) {
	if(Poziom == true) { //poziom latwy, zrobiony na losowych polach
		bool Puste;
		int Pole;
		cout<<endl;
		cout<<"Ruch komputera: "<<endl;
		Puste = false;
		while(Puste == false) {
			Pole = rand()%9+1;
			if(Pole > 0 && Pole < 10) {
				if(Pole == 1) {
					if(Plansza[0][0]==' ') {
						Plansza[0][0]='X';
						Puste = true;
						break;
					}
				}

				else if (Pole == 2) {
					if(Plansza[0][1]==' ') {
						Plansza[0][1]='X';
						Puste = true;
						break;
					}
				}

				else if (Pole == 3) {
					if(Plansza[0][2]==' ') {
						Plansza[0][2]='X';
						Puste = true;
						break;
					}
				}

				else if (Pole == 4) {
					if(Plansza[1][0]==' ') {
						Plansza[1][0]='X';
						Puste = true;
						break;
					}
				}

				else if (Pole == 5) {
					if(Plansza[1][1]==' ') {
						Plansza[1][1]='X';
						Puste = true;
						break;
					}
				}

				else if (Pole == 6) {
					if(Plansza[1][2]==' ') {
						Plansza[1][2]='X';
						Puste = true;
						break;
					}
				}

				else if (Pole == 7) {
					if(Plansza[2][0]==' ') {
						Plansza[2][0]='X';
						Puste = true;
						break;
					}
				}


				else if (Pole == 8) {
					if(Plansza[2][1]==' ') {
						Plansza[2][1]='X';
						Puste = true;
						break;
					}
				}

				else if (Pole == 9) {
					if(Plansza[2][2]==' ') {
						Plansza[2][2]='X';
						Puste = true;
						break;
					}
				}
			}
		}
		cout <<Pole<<endl;
		
		
	} else if (Poziom == false) {   //poziom trudny (MiniMax ci¹gle chce wygrac od lewej do prawej, nie jest zainteresowany moimi ruchami
		cout <<"Ruch komputera: "<<endl;
		Komputer();
		if(Plansza[Kolumna][Wiersz]=' ') {
		Plansza[Kolumna][Wiersz]= gracz;	
		if(gracz == 'O')
		{
			gracz = 'X';
		}
		else
		{
			gracz = 'O';
		}
	}
}
}


