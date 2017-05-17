#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<string>
#include"../inc/stoper.h"
#include"../inc/interfejs.h"
#include"../inc/Hash.Table.h"
#include"../inc/My.Hash.Table.h"

using namespace std;


int main()
{
	stoper s;
	int x = 1000000;
	//Hash_Table* hashtable=new Hash_Table (x);
	My_Hash_Table* hashtable=new My_Hash_Table(x);
	s.mierz_czas_start();
	for(int i=0; i<x; i++)
	{
		hashtable->Add();
	}
	hashtable->Display();
	s.mierz_czas_stop();
	return 0;
}
