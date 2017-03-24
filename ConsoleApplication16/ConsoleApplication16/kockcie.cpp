#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;



void kockice()
{


	int M, S;
	 
	cin >> M;


	cin >> S;

	switch (M) {

	case 1:
		M = 6;
		break;
	case 2:
		M = 5;
		break;
	case 3:
		M = 4;
		break;
	case 4:
		M = 4;
		break;
	case 5:
		M = 5;
		break;
	case 6:
		M = 6;
		break;
	}

	if (S < 4) {

		S = -S + 7;

	}

	if (M > S)
		cout << "mirko" << endl;
	else if (S > M)
		cout << "slavko" << endl;
	else
		cout << "nerijeseno" << endl;


	system("PAUSE");
}