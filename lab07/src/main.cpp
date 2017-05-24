#include <cstdio>
#include <iostream>
#include "../inc/interface.h"
#include "../inc/stoper.h"
#include "../inc/Tree.h"

using namespace std;

int main()
{
	stoper s;
	Temp* temp = new Temp;
	
	for(int i=0; i<1000; i++)
	{
	temp->Insert(rand()%100);
	}
		
	temp->Inorder(temp->GetKorzen());
	cout<<endl;
	s.mierz_czas_start();
	cout<<"1 - istnieje, 0 - nie istnieje: "<<temp->Find(0)<<endl;
	s.mierz_czas_stop();
//	cout<<endl;
//	temp->Preorder(temp->GetKorzen());
//	cout<<endl;
//	temp->Postorder(temp->GetKorzen());
	return 0;
}
