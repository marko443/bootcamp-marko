#include "stdafx.h"
#include <iostream>
#include "heder.h"

using namespace std;


int answer;
int main()
{
	

	cout << "izbornik: " << endl;

	cout << "izaberi 1, 2, or 3,  1= krizic kruzic 2=kockice 3=necu igrat igrice iden vanka.\n";

	cin >> answer;
	if (answer == 1) {
		cout << "krizic kruzic\n";
		krizickruzic();
	}
	 else if (answer ==2) {
		cout << "kockice\n";
		kockice();
	}
	 else {
		 cout << "pauza\n";
	 }
	 return 0;


}