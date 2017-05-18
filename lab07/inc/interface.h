#ifndef INTERFACE_HH
#define INTERFACE_HH

#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include <ctime>

using namespace std;

class Tree_I
{
	public:
				
		Tree_I();
		virtual void Inorder();
		virtual void Preorder();
		virtual void Postorder();
		virtual ~Tree_I();
};

Tree_I::Tree_I()
{
}

Tree_I::~Tree_I()
{
}

void Tree_I::Inorder()
{
}

void Tree_I::Preorder()
{
}

void Tree_I::Postorder()
{
}

#endif
