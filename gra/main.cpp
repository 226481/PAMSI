#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<time.h>
#include "inc/Gra.h"
#include "src/Gra.cpp"

using namespace std;

//Tomasz Perczy�ski, PAMSI czw. 14:00-16:00
//K�ko i krzy�yk

int main() {
	srand(time(NULL));
	Game gra;
	gra.Start();
	return 0;
}
