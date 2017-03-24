// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void pive();

int main ()
{
	pive();
	
	system("pause");
	return 0;
	
   }
void pive() {
	cout << 1 << "bootle of beer on the wall";
	for (int i = 2; i < 100; i++)
	{
		cout << i << "bootles of beer on the wall";
	}
}