#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;
vector<int> vektor;
int unos = 0;
int main() {
	do {
		cout << "unesite elemnt u vektor";
		cin >> unos;
		vektor.push_back(unos);

	} while (unos != 0);
	for (int i = 0; i < vektor.size(); i++) {
		cout << "elemnt vektora na pozicij" << i << "je:" << vektor[i] << endl;
	}
	cout << endl;


}