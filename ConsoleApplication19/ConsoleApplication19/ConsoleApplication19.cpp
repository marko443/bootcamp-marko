// ConsoleApplication19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;
void izbornik();
void uplata_para(int &chip, int &total);
void isplata_para(int &chip, int &total,char ime[10]);
void meni();
void izborigre();
void jack(int &chip, int &total, char ime[10]);
void kockice(int &chip, int &total, char ime[10]);
//void veca(int &chip, int &total, char ime[10]);
char ime[10];
int novac;
int chip;
int total=0;
int ostatak;


int main()

{
	int chip = 0;
	int novac=0;
	
	cout << "unesite ime:"<<endl;
	cin >> ime;
	meni();
	izbornik();
	return 0;
}


void izbornik()
{
	int izbor;
	cin >> izbor;
switch(izbor){
case 1:{
		 cout << "1.Uplata novca" << endl;
		 uplata_para( chip,total);
		 break;
	 }
	 case 2: {
		 cout << "2.Isplata  novca" << endl;
		 isplata_para(chip,total,ime);
		 break;
	 }
	 case 3: {
		 cout << "3.Odabir Igre" << endl;
		izborigre();
		 break;
	 }
	 case 4: {
		 cout << "4.High Score" << endl;
		 break;
	 }
	
	 case 5:
	 {
		 cout << "5.Izlaz iz programa" << endl;
		 system("pause");
		 break;
	 }

}
}
void meni()
{
	cout << "1.Uplata novca" << endl << "2.Isplata  novca" << endl << "3.Odabir Igre" << endl; cout << "4.High Score" << endl << "5.Izlaz iz programa" << endl;
	
}

void uplata_para(int &chip, int &total)
{
	
	
	cout << "koliko zelis novaca uplatiti?";
		cin >> novac;
		chip = novac / 5;
		ostatak = novac % 5;

	cout << "BRAVO uplatio si " << novac << "imas Chipova " << chip << " i ostalo ti je " << ostatak << "kuna";
	meni();
	izbornik();

}

void isplata_para(int &chip, int &total,char ime[10])
{
	
	char dane;
	cout <<  "Zelite li isplatu? trenutacno stanje sa chipovima je " << chip << "i  imate " << ostatak << endl;
	cout << "dali stvarno zelite isplatu y/n?" << endl;
	cin >> dane;
	if (dane='y')
	{ 
		cout << " CESTITAMOOOOOO WOOOO BRAVO osvojili ste!!!" << endl;
	total = ostatak+chip*5;
	ofstream rezultati;
	rezultati.open("rezultati.txt", ios::in | ios::app);
	rezultati << ime <<"\t"<< total<< "\n";
	rezultati.close();
	cout << "vas ukupna zarada je" << total << "kn" << endl;
}
	else if (dane='n')
	{
		 meni();
		 izbornik();

	}
}



void izborigre() {
cout << "1.Jednoruki Jack" << endl << "2.Bacanje Kockice" << "3.Duplo ili nista" << "4.Nazad" << endl;
	int a;
	cin >> a;
	
switch (a)
		{
case 1: {
	cout << "1.Jednoruki Jack" << endl;
	jack(chip,total,ime);
	break;
}
case 2: {
	cout << "2.Bacanje Kockice" << endl;
	kockice(chip, total,ime);
	break;
}
case 3: {
	cout << "3.Duplo ili nista" << endl;
	//veca(chip, total, ime);
	break;
}
		
case 4: {
	cout << "4.Nazad" << endl;
	meni();
	izbornik();
	break;
}
		}

}

void highscore() {
	ifstream rezultati;
	rezultati.open("rezultati.txt");
	rezultati.close();
}

void jack(int &chip, int &total, char ime[10])
{
	int slot_1, slot_2, slot_3;
	char unos;
	cout << "stisni d za vrcenje i stisni x za povratak za meni" << endl;
	cin >> unos;
	

	while (unos == 'd' || unos == 'D' && chip>0) 
	{
		slot_1 = rand() % 4 + 1;
		slot_2 = rand() % 4 + 1;
		slot_3 = rand() % 4 + 1;
		
		cout << "\t" << slot_1 << "\t" << slot_2 << "\t" << slot_3 <<  endl;
		
		

		 if (slot_1 == slot_2 && slot_2 == slot_3 ) 
		{
			chip = chip + 10;
			
			cout << "Bravo pobijedio si!" << endl;
			cout << "imas :" <<chip << " chipova!" << endl;
			cin >> unos;
			


		}

		 else
		{
			cout << " izgubio si  chip"<< endl;
			--chip;
			
		}
		 while (unos == 'x' || unos == 'x')
		 {

			 meni();
			 izbornik();
			 total = ostatak + chip * 5;
			 cout << total << endl;
			 ofstream rezultati;
			 rezultati.open("rezultatijack.txt", ios::in | ios::app);
			 rezultati << ime << "\t" << total << "\n";
			 rezultati.close();
			 cout << "vas ukupna zarada je" << total << "kn" << endl;
		 }

	}

	}
	
void kockice(int &chip, int &total, char ime[10]) {
	char x;
	int kockica1, kockica2;
	cout << " upisi d za igranje i x za povratak na meni" << endl;
	
	cin >> x;
	while (x == 'd' || x == 'D')
	{
		kockica1 = rand() % 6 + 1;
		kockica2 = rand() % 6 + 1;
		cout << "igrac je dobio " << kockica1 << "aparat je dobio" << kockica2 << endl;

		if (kockica1 > kockica2)
		{
			chip++;
			cout << chip;
			cin >> x;
			
		}
		else if (kockica2 = kockica2) {
			cout << "izjednacenje" << endl;
			cin >> x;
		}
		else {
			chip--;
			cout << chip;
			cin >> x;
		}
		while (x == 'x' || x == 'X')
		{

			meni();
			izbornik();
			total = ostatak + chip * 5;
			cout << total << endl;
			ofstream rezultati;
			rezultati.open("rezultatikockice.txt", ios::in | ios::app);
			rezultati << ime << "\t" << total << "\n";
			rezultati.close();
			cout << "vas ukupna zarada je" << total << "kn" << endl;
		}
	}
}

/* nis nevalja brisi
void veca(int &chip, int &total, char ime[10]) {
	char x;
	int igrac1, igrac2, veca;
	int duplo = 0;
	cout << "dobro dosli u veca manja za igranje stisni d za povratak na meni x" << endl;
	cin >> x;
	while (x = 'd') {
		igrac1 = rand() % 13 + 1;
		igrac2 = rand() % 13 + 1;
		cout << igrac1 << endl << igrac2 << endl;
		if (igrac1 > igrac2) {
			++duplo;
			cout << "zelite li duplati?" << endl;
			cin >> x;
			if (x = 'd') {
				veca = rand() % 2;
				if (veca = 1) {
					duplo=duplo * 2;
					chip = chip + duplo;
					cout << duplo;
					cout << chip;
				 veca;
				}
				else (--chip);
			}
		}
		else if (igrac1 < igrac2) { --chip; }


	}
}
*/


