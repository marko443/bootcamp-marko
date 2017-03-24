// ConsoleApplication12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	
	int multi;
	int bdobitaka1 = 0;
	int bdobitaka2 = 0;
	int bdobitaka3 = 0;
	int bvrtcenja = 0;
	int pare;
	int slot_1, slot_2, slot_3;
	cout << "unesi broj para za start" << endl;
	cin >> pare;
	cout << "unesi multiplikator" << endl;
	cin >> multi;
	cout << "sretno" << endl;
	while (pare> 0 ) {
		pare = pare - (1 * multi);
		slot_1 = rand() % 3+1;
		slot_2 = rand() % 3+1;
		slot_3 = rand() % 3+1;
				
				bvrtcenja++;
				cout << slot_1 << slot_2 << slot_3 << endl;
				if (slot_1==1 &&  slot_1==slot_2 && slot_2 == slot_3) {
					pare = pare + (10 * multi);
					cout << "Bravo majmune " << pare << endl;
					bdobitaka1++;
				}
				else if (slot_1 == 2 && slot_1 == slot_2 && slot_2 == slot_3) {
					pare = pare + (10 * multi) * 2;
					cout << "Bravo majmune " << pare << endl;
					bdobitaka2++;
				}
				else if (slot_1 == 3 && slot_1 == slot_2 && slot_2 == slot_3) {
						pare = pare + (10 * multi) * 3;
						cout << "Bravo majmune " << pare << endl;
						bdobitaka3++;
				}
				else if (pare == 0)
				{
					cout << "wha wha wha whaaaaaaaaa" << endl;
					cout << "odvrtija si " << bvrtcenja << "dobija si " << bdobitaka1+bdobitaka2+bdobitaka3 << endl;
				}
				else if (pare < multi)
				{
					cout << "nemas za vrcenje, ostalo ti je" << pare << endl;

					cout << "odvrtija si " << bvrtcenja << "dobija si " << bdobitaka1 + bdobitaka2 + bdobitaka3 << endl;
				}
				else if (pare > 100000)
					cout << "bizi ca" << endl;
			}
	
	system("PAUSE");
    return 0;
}

