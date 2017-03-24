

#include "stdafx.h"
#include <iostream>
using namespace std;
int main()
{
	char op;
	cout <<  "unos broja 1unos / 2pozdrav / 3 izlaz"  << endl;
	cin >>op;
	switch (op) {
		case 1:
			cout << "unesi broj:" << endl;
			int a;
			cin >> a;
		cout  <<"broj je"<< a << endl;
			break;
		
		
		case 2:
		cout  << "pozdrav, korisnik" <<  endl;
		break;
		case 3:
		break;
		
	}
	system("PAUSE");
	return 0;
}
