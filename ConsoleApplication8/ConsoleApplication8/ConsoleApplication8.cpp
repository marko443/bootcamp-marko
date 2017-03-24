#include "stdafx.h"
#include <iostream>
using namespace std;
void tablica();
void lozinka();
void kalkulator();
void mainvar(int a, int b);
void krizickruzic;
char square[10] = { 'o','1','2','3','4','5','6','7','8','9' };

int checkwin();
void board();
int main()
{
	int b1 = 10;
	int b2 = 20;
	int izbornik = 0;
	cin >> izbornik;

	switch (izbornik) {
	case 1:
			tablica();
			   break;
	case 2:
				   lozinka();
			    break;
	case 3:
					kalkulator();
			    break;
	case 4:
		cout << b1 << " " << b2 << endl;
					mainvar(b1, b2);
		cout << b1 << " " << b2 << endl;
				break;
	case 5:
		krizickruzic();
		break;
	}
	system("PAUSE");
	return 0;
}

void tablica() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << i*j << "\t";
		}
		cout << endl;
	}
}


void lozinka() {
	int a;
	cout << "unesi lozinku:" << endl;
	cin >> a;


	if (a == 4415 || a == 1944)
	{
		cout << "lozinka je tocna" << endl;
	}
	else
	{
		cout << "pogresna lozinka" << endl;
	}
}

void kalkulator(){
	int a, b;
	char op;
	cout << "unesi prvi broj" << endl;
	cin >> a;
	cout << "unesi drugi broj" << endl;
	cin >> b;

	cout << "unesi operator +,-,/,*" << endl;
	cin >> op;


	switch (op) {
	case '+':
		cout << a << "+" << b << "=" << a + b << endl;
		break;
	case '-':
		cout << a << "-" << b << "=" << a - b << endl;
		break;
	case '*':
		cout << a << "*" << b << "=" << a * b << endl;
		break;
	case '/':
		cout << a << "/" << b << "=" << a / b << endl;
		break;
	}
}

void mainvar(int a, int b) {
cin >> a >> b;
}

void krizickruzic
{
	int player = 1,i,choice;

char mark;
do
{
	board();
	player = (player % 2) ? 1 : 2;

	cout << "igrac " << player << ", upisi broj:  ";
	cin >> choice;

	mark = (player == 1) ? 'X' : 'O';

	if (choice == 1 && square[1] == '1')

		square[1] = mark;
	else if (choice == 2 && square[2] == '2')

		square[2] = mark;
	else if (choice == 3 && square[3] == '3')

		square[3] = mark;
	else if (choice == 4 && square[4] == '4')

		square[4] = mark;
	else if (choice == 5 && square[5] == '5')

		square[5] = mark;
	else if (choice == 6 && square[6] == '6')

		square[6] = mark;
	else if (choice == 7 && square[7] == '7')

		square[7] = mark;
	else if (choice == 8 && square[8] == '8')

		square[8] = mark;
	else if (choice == 9 && square[9] == '9')

		square[9] = mark;
	else
	{
		cout << "Invalid move ";

		player--;
		cin.ignore();
		cin.get();
	}
	i = checkwin();

	player++;
} while (i == -1);
board();
if (i == 1)

cout << "==>\aPlayer " << --player << " win ";
else
cout << "==>\aGame draw";

cin.ignore();
cin.get();
return 0;
}

/*********************************************

funkicija za vracanje statusa igre  1= kraj -1=igra se 0 kraj  bez pobjednika
**********************************************/

int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])

		return 1;
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
		&& square[4] != '4' && square[5] != '5' && square[6] != '6'
		&& square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0;
	else
		return -1;
}


/*******************************************************************
 polja za igranje
********************************************************************/


void board()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}



