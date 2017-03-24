// ConsoleApplication15.cpp : Defines the entry point for the console application.
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

	int choice;
	string ime, prezime, prosjek, ects, rbr, ispis;
	ifstream myfile("test.txt");
		cout << "Main Menu\n";
		cout << "Please make your selection\n";
		cout << "1 prikaz studenata\n";
		cout << "2 -unos studenata\n";
		cout << "3 pretrazivanje po rbr\n";
		cout << "4 Izracun prosjecne ocjene\n";
		cout << "Izbor: ";
		cin >> choice;

		switch (choice) {
		case 1:
			while (myfile) {
				getline(myfile, rbr, ' ');
				getline(myfile, ime, ' ');
				cout << rbr << " " << ime << " ";
			}
			break;
		case 2:
			cout << "????\n";// redi broj, ime, prezime , prosjek , ects
			break;
		case 3:
			cout << "Goodbye!";
		case 4:
			cout << "Goodbye!";
			break;
		default:
			cout << "Main Menu\n";
			cout << "Please make your selection\n";
			cout << "1 prikaz studenata\n";
			cout << "2 -unos studenata\n";
			cout << "3 pretrazivanje po rbr\n";
			cout << "4 Izracun prosjecne ocjene\n";
			cout << "Izbor: ";
			cin >> choice;
		}
}
	
	

