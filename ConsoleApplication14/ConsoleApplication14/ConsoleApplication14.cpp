// ConsoleApplication14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include<vector>
#include <string>
#include <ctime>
using namespace std;


int main()
{
	string podaci;
	ofstream brojevi("primjer.txt");
	ifstream citanje;
	int broj;
	int bacanjekocke; {
		int ran;
		srand(time(NULL));
		ran = rand() % 6 + 1;
		cout << "dobio si" << ran << "." << std::endl;
		return ran;
	
	for (int i = 0; i <= broj; i++) {
		brojevi << i << "\n";
	}
	brojevi.close();

	citanje.open("primjer.txt", ios::beg);

	while (citanje) {
		getline(citanje, podaci);
		cout << podaci << "\n";
	}
	

	system("pause");
    return 0;
}

