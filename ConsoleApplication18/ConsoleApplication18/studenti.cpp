#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <new>

using namespace std;
//void unos(admstud y[]);
void meni();
//void pokaziStudenta();
void unos();
void izbornik();
void prikaz_studenta();
void brisanje_studenta();

struct admstud {
	int id;
	string ime,prezime,spol;
	double prvik, drugik,zavrsni;
	
	
};
vector<admstud>studenti;
int main()
{
	

	
		
	meni();
	izbornik();
	
	
	
}



void unos() {
admstud novi_student;
	cout << "Unesi ID" << endl;
	cin >> novi_student.id;
	cout << "Unesi ime" << endl;
	cin.ignore();
	getline(cin, novi_student.ime);
	cout << "Unesi prezime" << endl;
	cin.ignore();
	getline(cin, novi_student.prezime);
	cout << "Unesi spol" << endl;
	cin.ignore();
	getline(cin, novi_student.spol);
	cout << "prvi kolokviji" << endl;
	cin >> novi_student.prvik;
	cout << "drugi kolokviji" << endl;
	cin >> novi_student.drugik;
	cout << "Zavrsni" << endl;
	cin >> novi_student.zavrsni;
	studenti.push_back(novi_student);
	system("cls");
	meni();
	izbornik();
}
void meni() {
	cout << "meni\t" << endl << "1. unos \t" << endl << "2. brisanje po id \t" << endl << "3. izmjena podataka \t" << endl << "4. prikaz prosjeka po ispit \t" << endl << "5. prikaz najboljeg  \t" << endl << "6.prikaz najgoreg \t" << endl << "7.prikaz po ID \t" << endl << "8.sortiranje po ukupnom uspjehu \t" << endl << "9. prikaz svih studenata" << endl;
}
void izbornik(){
	int a;
	cin >> a;
	switch (a)
{
case 1:
	cout << "unos studenata" << endl;
	unos();
	break;
case 2:
	cout << "Brisanje po ID" << endl;
	brisanje_studenta();
	break;
case 3:
	cout << "Izmjena podataka o studentu" << endl;
	//cin >> 
	break;
case 4:
	cout << "Prikaz prosjeka po ispitu" << endl;

	break;
case 5:
	cout << "Prikaz najboljeg" << endl;

	break;
case 6:
	cout << "Prikaz najgoreg" << endl;

	break;
case 7:
	cout << "Prikaz po  ID" << endl;

	break;
case 8:
	cout << "Sortiranje po ukupnom uspjehu" << endl;
case 9:
	cout << "Prikaz svih studenata" << endl;
	prikaz_studenta();

	break;
default:
	break;
}
}
void prikaz_studenta() {
	for (int i = 0; i < studenti.size(); i++)
	{
		cout << "\t" <<studenti[i].id << "\t" << studenti[i].ime << "\t" << studenti[i].prezime << "\t" << studenti[i].spol << "\t" << studenti[i].prvik << "\t" << studenti[i].drugik << "\t"<< studenti[i].zavrsni << endl;
	}
}
void brisanje_studenta() {
	int n;
	cin >> n;
	
	if (n==1)
	{
		studenti.erase(studenti.begin());
	}
	else
	studenti.erase(studenti.begin() + n);
	
	meni();
	izbornik();
}