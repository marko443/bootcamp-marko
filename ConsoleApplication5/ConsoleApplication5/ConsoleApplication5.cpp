// ConsoleApplication5.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
using namespace std;
int main() {
	int x, a, b, i;
	cout << "Upisite brojeve koje zelite zbrajati/oduzimati:\n";
	cin >> a >> b;
	i = 10;
	while (i != 50) {
		cout << "Upisite 1 za zbrajanje, 2 za oduzimanje, 3 za izlaz\n";
		cin >> x;
		switch (x) {
		case 1:
			cout << a + b;
			break;
		case 2:
			cout << a - b;
			break;
		case 3:
			int v;
			cout << "dali ste signurni, 1 za ne" << endl;
			cin >> v;
			if (v == 1)
			{
				i = 50;
			}
			else {}

			i = 20;
		}   
			break;
		
	}

	return 0;

}
