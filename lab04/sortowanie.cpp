#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstdlib>

//Tomasz Perczyński 226481, PAMSI śr 14:00-16:00
//Sortowanie
//Wykonane na pewno błędne

using namespace std;

int main()
{
  srand(time(NULL));
  int tab[10];
  int zast;
  for(int i=0; i<10; i++)
    {
      tab[i]=rand()%10;
    }
  
  for(int s=0; s<5; s++)
    {
      for(int d=10; d>4; d--)
	{
          if(tab[s]>tab[d])
	{
	  zast=tab[s];
	  tab[s]=tab[d];
	  tab[d]=zast;
	}}
      
      for(int p=0;p<9;p++)
	{
	  cout << tab[p];
	}
      cout << endl;
    }


  for(int j=0; j<4; j++)
    {
      zast=0;
      if(tab[j]>tab[j+1])
	{
	  zast=tab[j];
	  tab[j+1]=tab[j];
	  tab[j]=zast;
	}
    }

  for(int i=5; i<10; i++)
    {
      if(tab[i]>tab[i+1])
	{
	  zast=tab[i];
	  tab[i+1]=tab[i];
	  tab[i]=zast;
	}
    }
  return 0;
}
