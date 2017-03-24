// ConsoleApplication11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;
void polje();
void poljetrid();
void dvadpolja();
void vektor1();
void  lista1();
void pogadanjebroja();
void CoinFlip();
void 	vockice();
int main()
{
	//polje();
	//dvadpolja();
	//poljetrid();
	//vektor1();
	//lista1();
 //pogadanjebroja();
	//CoinFlip();
	vockice();
	system("PAUSE");
	return 0;
}

void polje()
{
	int x;
	cout << "unesite velicinu polja,";
	cin >> x;
	int *polje = new int[x];
		for (int i = 0; i < x; i++)
		{
			cout << "polje" << i << ":";
			cin >> polje[i];
		}
	for (int i=0; i <x; i++)
	{
		cout << polje[i] << "\t";
	}
	delete polje;
	polje = nullptr;
}

void dvadpolja()
{
int x, y;
cout << "unestie velicine polja:";
cin >> x >> y;

int **p_p_polje = new int*[x];
for (int i = 0; i < x; i++)
{
	p_p_polje[i] = new int[y];

}
for (int i = 0; i < x; i++)
{
	for (int j = 0; j < y; j++)
	{
		cout << "unestie vrijednost polja[" << i << "],[" << j << "]:";
		cout << p_p_polje[i][j];
	}
}
for (int i = 0; i < x; i++)
{
	
	delete p_p_polje[i];
}
delete p_p_polje;
p_p_polje = nullptr;
}





void poljetrid() {

	int x, y, z;
	cout << "Unesite velicinu polja : " << endl;
	cin >> x >> y>> z;

	int ***p_p_polje = new int**[x];

	for (int i = 0; i < x; i++) {
		p_p_polje[i] = new int*[y];
	}
	
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++)
		{
			p_p_polje[i][j] = new int[z];
		}
	}


	for (int i = 0; i < x; i++) {

		for (int j = 0; j < y; j++) {
			
		
		for (int k = 0; k < z; k++) {
			cout << "Unesite vrijednost polja" << "[" << i << "], [" << j << "],[" << k <<"]";
			cin >> p_p_polje[i][j][k];
		}
		}
	}

	for (int i = 0; i < x; i++) {

		for (int j = 0; j < y; j++) {
			for (int k = 0; k < z; k++) {
				cout << p_p_polje[i][j][k] << "\t";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < x; i++) {

		delete p_p_polje[i];
		
	}


	delete p_p_polje;
	p_p_polje = nullptr;


}

void vektor1()
{
	vector<int> vektor;
	int unos = 0;
	do {
		cout << "unesite element u vektor:";
		cin >> unos;
		vektor.push_back(unos);
		
	} while (unos != 0);
	for (int i = 0; i < vektor.size(); i++) {
		cout << "element vektora na poziciji " << i << "je: " << vektor[i] << endl;
	}
	cout << endl;

}
void  lista1() {
	list<int> lista;
	cout << "unos elemenata u listu" << endl << endl;
	int element_liste;
	cout << "unesite element na pocetak liste:";
	cin >> element_liste;
	lista.push_front(element_liste);

	cout << "unesite element na pocetak liste:";
	cin >> element_liste;
	lista.push_front(element_liste);

	cout << "unesite element na kraj liste:";
	cin >> element_liste;
	lista.push_back(element_liste);

	cout << "unesite element na kraj liste:";
	cin >> element_liste;
	lista.push_back(element_liste);
	cout << endl;

	for (list<int>::iterator i = lista.begin(); i != lista.end(); i++)
		cout << *i << endl;
}

void pogadanjebroja() {
	srand(time(NULL));
	int broj = 0;
	int trazeniBroj = (rand() % 99) + 1;
	cout << "pogodite broj od 1 do 100:";
	cin >> broj;
	while(trazeniBroj != broj)
	{
		if (broj < trazeniBroj)
		{
			cout << "broj koji pogadas je veci. pokusaj ponovo." << endl;
			cin >> broj;
		}
		else if (broj >trazeniBroj)
		{
			cout << "broj koji pogadas je manji. Pokusaj ponovo" << endl;
		}
		else if (broj == trazeniBroj)
		{
			cout << "BRAVO!!! WOOO IGRAJ LOTO,TOVARE" << endl;

		}
	}

}
void CoinFlip()
{
	srand(time(NULL));
	char unos = 'x';
	cin >> unos;
	while (unos == 'x')
	{
		if (rand() % 2 == 0)
			cout << "pismo" << endl;
		else
			cout << "glava" << endl;
	}
	cout << " unesite x za bacanje novcica ili drugi znak za " << endl;
	cin >> unos;
}

void vockice();
{
	int pare = 
	char unos = 'x';
	int slot_1, slot_2, slot_3;
	cout << "unesi x za start" << endl;
	cin >> pare >> endl;
	cout << "sretno"
	while (pare >0 ) {
		slot_1 = rand() % 3
		slot_2 = rand() % 3
		slot_3 = rand() % 3
		cout << slot_1 << slot_2 << slot_3 << endl;
		if (slot_1 == slot_2 && slot_2 == _slo3) {
			cout << "Bravo majmune" << pare + 10 << endl;
		}
		else if (pare == 0)
			cout << "wha wha wha whaaaaaaaaa" << endl;
			
	}
}
