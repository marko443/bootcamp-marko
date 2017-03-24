// ConsoleApplication17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;
struct knjiga {
	
	int id;
	string naslov;
	string autor;
	int isbn[13];
	string podrjucje;

};
struct SpaceShip
{
	int x_coordinate = (rand() % 20) + 1;
	int y_coordinate = (rand() % 20) + 1;
	bool outOfRange = false;
};
	

int main()
{
	spaceShip();
}
void spaceShip()
{
	srand(time(NULL));

	SpaceShip ship[5];
	int outOfRangeCounter = 0, lastX[5], lastY[5];

	while (outOfRangeCounter < 5)
	{

		for (int i = 0; i < 5; i++)
		{
			if (ship[i].outOfRange == true)
			{
				continue;
			}
			else
			{
				if (ship[i].x_coordinate > 10 || ship[i].y_coordinate > 10)
				{
					outOfRangeCounter += 1;
					ship[i].outOfRange = true;
					lastX[i] = ship[i].x_coordinate;
					lastY[i] = ship[i].y_coordinate;
				}
				else
				{
					crtanjeLokacije(ship[i]);
					cout << "Koordinate broda " << i + 1 << " su: " << ship[i].x_coordinate << ", " << ship[i].y_coordinate << endl << endl;
					ship[i].x_coordinate = (rand() % 15) + 1;
					ship[i].y_coordinate = (rand() % 15) + 1;
				}
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << "Zadnje koordinate broda " << i + 1 << " su: " << lastX[i] << ", " << lastY[i] << endl;
	}
}

void crtanjeLokacije(SpaceShip ship)
{
	// crtanje - do y koordinate
	for (int i = 1; i < ship.y_coordinate; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << "()";
		}
		cout << endl;
	}

	// crtanje - do x koordinate
	for (int i = 0; i < ship.x_coordinate - 1; i++)
	{
		cout << "()";
	}

	// crtanje lokacije koordinata
	cout << "<>";

	// crtanje -- poslije lokacije x koordinate
	for (int i = ship.x_coordinate; i < 10; i++)
	{
		cout << "()";
	}
	cout << endl;

	// crranje -- u ostalim redovima do kraja tablice
	for (int i = ship.y_coordinate; i < 10; i++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << "()";
		}
		cout << endl;
	}
}
