#ifndef TREE_HH
#define TREE_HH

#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include <ctime>
#include "interface.h"

using namespace std;

class Tree:public Tree_I
{
	private:
	int Wartosc;
	public:
	Tree* Left;
	Tree* Right;
	
	Tree(Tree* tree, int Wartosc);
	void Inorder(Tree* tree);
	void Preorder(Tree* tree);
	void Postorder(Tree* tree);
};

Tree::Tree(Tree* tree, int Wartosc)
{
	if(tree==NULL)
	{
		tree=new Tree [Wartosc];
		tree->Wartosc=Wartosc;
		tree->Left=NULL;
		tree->Right=NULL;
	}
	else
	{
		if(Wartosc>=tree->Wartosc)
		{
			Insert(tree->Right, Wartosc);
		}
		else
		{
			Insert(tree->Left, Wartosc);
		}
	}
}

void Tree::Inorder(Tree* tree)
{
	if(tree != NULL)
	{
		Inorder(tree->Left);
		cout << tree->Wartosc;
		cout <<endl;
		Inorder(tree->Right);
		}	
}

void Tree::Preorder(Tree* tree)
{
	if(tree!=NULL)
	{
		cout<<tree->Wartosc;
		cout<<end;;
		Preorder(tree->Left);
		Preorder(tree->Right);
		}	
}

void Tree::Postorder(Tree *tree)
{
	if(x!=NULL)
	{
		Postorder(tree->Left);
		Postorder(tree->Right);
		cout<<tree->Wartosc;
		cout<<endl;
	}
}

#endif
