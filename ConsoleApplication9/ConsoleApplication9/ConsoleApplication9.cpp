#include "stdafx.h"
#include <iostream>
using namespace std;
void tablica();
void lozinka();
void kalkulator();
void mainvar(int a, int b);
void krizickruzic;
char square[10] = { 'o','1','2','3','4','5','6','7','8','9' };
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

void kalkulator() {
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

void krizickruzic() {
	int igrac;
	char polja[10] = { 'o','1','2','3','4','5','6','7','8','9' };

	int provjeripobjedu();
	void board();
	int igrac = 1, i, izbor;

	char mark;
	do
	{
		board();
		igrac = (igrac % 2) ? 1 : 2;

		cout << "igrac " << igrac << ", upisi broj  ";
		cin >> izbor;
		// igrac upisuje mjesto
		mark = (igrac == 1) ? 'X' : 'O';
		if (izbor == 1 && polja[1] == '1')

			polja[1] = mark;
		else if (izbor == 2 && polja[2] == '2')

			polja[2] = mark;
		else if (izbor == 3 && polja[3] == '3')

			polja[3] = mark;
		else if (izbor == 4 && polja[4] == '4')

			polja[4] = mark;
		else if (izbor == 5 && polja[5] == '5')

			polja[5] = mark;
		else if (izbor == 6 && polja[6] == '6')

			polja[6] = mark;
		else if (izbor == 7 && polja[7] == '7')

			polja[7] = mark;
		else if (izbor == 8 && polja[8] == '8')

			polja[8] = mark;
		else if (izbor == 9 && polja[9] == '9')

			polja[9] = mark;
		else
		{
			cout << "Nemoguc potez nebudi lud";
			// u slucaju da je unos nepoznat ili ti ga manji od 1 i veci od 9
			igrac--;
			cin.ignore();
			cin.get();
		}
		i = provjeripobjedu();

		igrac++;
	} while (i == -1);
	board();
	if (i == 1)
		// while za pobjedu
		cout << "==>\a igrac  " << --igrac << " pobjedio ";
	else
		cout << "==>\a Nerjeseno";

	cin.ignore();
	cin.get();
	return 0;

	//provjera pobjede
	int checkwin()
	{
		if (polja[1] == polja[2] && polja[2] == polja[3])

			return 1;
		else if (polja[4] == polja[5] && polja[5] == polja[6])

			return 1;
		else if (polja[7] == polja[8] && polja[8] == polja[9])

			return 1;
		else if (polja[1] == polja[4] && polja[4] == polja[7])

			return 1;
		else if (polja[2] == polja[5] && polja[5] == polja[8])

			return 1;
		else if (polja[3] == polja[6] && polja[6] == polja[9])

			return 1;
		else if (polja[1] == polja[5] && polja[5] == polja[9])

			return 1;
		else if (polja[3] == polja[5] && polja[5] == polja[7])

			return 1;
		else if (polja[1] != '1' && polja[2] != '2' && polja[3] != '3'
			&& polja[4] != '4' && polja[5] != '5' && polja[6] != '6'
			&& polja[7] != '7' && polja[8] != '8' && polja[9] != '9')

			return 0;
		else
			return -1;
	}
	void board()
	{
		system("cls");
		cout << "\n\n\Krizic Kruzic\n\n";

		cout << "Igrac 1 (X)  -  igrac 2 (O)" << endl << endl;
		cout << endl;

		cout << "     |     |     " << endl;
		cout << "  " << polja[1] << "  |  " << polja[2] << "  |  " << polja[3] << endl;

		cout << "_____|_____|_____" << endl;
		cout << "     |     |     " << endl;

		cout << "  " << polja[4] << "  |  " << polja[5] << "  |  " << polja[6] << endl;

		cout << "_____|_____|_____" << endl;
		cout << "     |     |     " << endl;

		cout << "  " << polja[7] << "  |  " << polja[8] << "  |  " << polja[9] << endl;

		cout << "     |     |     " << endl << endl;
	}
}
	





