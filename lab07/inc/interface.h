#ifndef INTERFACE_HH
#define INTERFACE_HH

#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include <ctime>

using namespace std;

class Temp_I
{
	public:
				
		Temp_I();
		virtual void Inorder();
		virtual void Preorder();
		virtual void Postorder();
		virtual ~Temp_I();
};

Temp_I::Temp_I()
{
}

Temp_I::~Temp_I()
{
}

void Temp_I::Inorder()
{
}

void Temp_I::Preorder()
{
}

void Temp_I::Postorder()
{
}

#endif
