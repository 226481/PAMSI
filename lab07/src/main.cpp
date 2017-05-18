#include <cstdio>
#include <iostream>
#include "../inc/interface.h"
#include "../inc/stoper.h"
#include "../inc/Tree.h"

using namespace std;

int main()
{
	Tree* tree=NULL;
	Inorder(tree);
	Preorder(tree);
	Postorder(tree);
	return 0;
}
