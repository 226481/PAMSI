#include<iostream>
#include<cstdio>

using namespace std;

//Tomasz Perczyñski, PAMSI czw. 14:00-16:00
//Kó³ko i krzy¿yk 

class Game
{
	private:
		char Plansza[3][3];
		char Znak_X;
		char Znak_O;
		int Licznik;
		bool Win;
	public:
		Game();
		void Rysuj_Plansze();
		bool Wygrana();
		bool Remis();
		int MiniMax(char gracz);
		int Przeciwnik();
		void Ruch();
		void Start();
		void Zasady();
		void Czysto();
};

Game::Game()
{
	Win = false;
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

bool Game::Wygrana()
{
	bool Remis;
	int i;
	int j=0;
	Win = false;

	//Sprawdznie wygranej dla X
	for(i=0; i<3; i++) // Sprawdzamy wiersze
	{
		if(Plansza[i][j] == Znak_X && Plansza[i][j+1] == Znak_X && Plansza[i][j+2] == Znak_X)
		{
			Win = true;
			cout<<endl;
			cout <<"Wygral gracz: "<<Znak_X;	
			break;
		}
	}

	for(i=0; i<3; i++) // Sprawdzamy kolumny
	{
		if(Plansza[j][i] == Znak_X && Plansza[j+1][i] == Znak_X && Plansza[j+2][i] == Znak_X)
		{
			Win = true;
			cout<<endl;
			cout <<"Wygral gracz: "<<Znak_X;		
			break;
		}
	}

	if(Plansza[0][0] == Znak_X && Plansza[1][1] == Znak_X && Plansza[2][2] == Znak_X) //Sprawdzamy pierwszy skos
	{	 
		Win = true;
		cout<<endl;
		cout <<"Wygral gracz: "<<Znak_X;		
	}
	
	else if(Plansza[0][2] == Znak_X && Plansza[1][1] == Znak_X && Plansza[0][2] == Znak_X) //Sprawdzamy drugi skos
	{ 
		Win = true;
		cout<<endl;
		cout <<"Wygral gracz: "<<Znak_X;		
	}
	
	//Sprawdznie wygranej dla O
	for(i=0; i<3; i++) // Sprawdzamy wiersze
	{
		if(Plansza[i][j] == Znak_O && Plansza[i][j+1] == Znak_O && Plansza[i][j+2] == Znak_O)
		{
			Win = true;
			cout<<endl;
			cout <<"Wygral gracz: "<<Znak_O;
			break;
		}
	}
	
	for(i=0; i<3; i++) // Sprawdzamy kolumny
	{
		if(Plansza[j][i] == Znak_O && Plansza[j+1][i] == Znak_O && Plansza[j+2][i] == Znak_O)
		{
			Win = true;
			cout<<endl;
			cout <<"Wygral gracz: "<<Znak_O;
			break;
		}
	}
	
	if(Plansza[0][0] == Znak_O && Plansza[1][1] == Znak_O && Plansza[2][2] == Znak_O) //Sprawdzamy pierwszy skos
	{	 
		Win = true;
		cout<<endl;
		cout <<"Wygral gracz: "<<Znak_O;
	}
	
	else if(Plansza[0][2] == Znak_O && Plansza[1][1] == Znak_O && Plansza[0][2] == Znak_O) //Sprawdzamy drugi skos
	{ 
		Win = true;
		cout<<endl;
		cout <<"Wygral gracz: "<<Znak_O;		
	}
}

bool Game::Remis()
{
	if (Win == false && Licznik >= 9)
	{
		cout<<endl;
		cout<<"Remis, zaden z graczy nie wygral.";
		Win = true;
	}
}

void Game::Start()
{
	Licznik = 0;
	char Odpowiedz;
	Win = false;
	Zasady();
	Rysuj_Plansze();
	while(Win == false)
	{
		Wygrana();
		Ruch();
		Rysuj_Plansze();
		Remis();
		Wygrana();
		Licznik = Licznik + 2;
	}
	while(Win == true)
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
				Win = false;
				break;
			}
			else
			cout<<"Niepoprawna odpowiedz, prosze odpowiedziec jeszcze raz: "<<endl;
		}
		if(Win == false)
		{
			break;
		}
	}
}

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
}

int main()
{
	Game gra;
	gra.Start();
	return 0;
}
