// Casino.cpp : Defines the entry point for the console application.
//

/* BAZA U OBLIKU baza.txt

NICK IGRA DOBITAK

npr:
luka 1 34252
marko 2 4823
pero 3 1234
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>

#define PSTAT_MENU 0
#define PSTAT_REGI 1

using namespace std;

void resetPlayer();
void registerPlayer();
void showLogo();
int showMenu();
void uplataChipova();
void isplataNovaca();
void loadScores();
void saveScores();
void showScores();
int showGames();
bool checkChips(int amount);
void playingDuplo();
string cardName(int card);
int cardValue(int card);
void playingKockice();
void playingJednoruki();
void printMachine(int a, int b, int c, int d);
void printPoints(int ulog);
string gameName(int game);

struct Player
{
	int state;
	int cash;
	int chips;
	string name;
};

struct Game
{
	string name;
	int game;
	int score;
};

Player pInfo;

vector<Game> gInfo;

int main()
{
	// Ucitavanje funkcija
	srand(time(NULL));
	resetPlayer();
	loadScores();

	// Postavljanje memorije
	bool exitProgram = false;

	// Izvodenje programa
	while (!exitProgram)
	{
		showLogo();

		if ((pInfo.cash < 10 && pInfo.chips == 0) && pInfo.state != PSTAT_REGI)
		{
			cout << "Ostao si bez novaca i nemozes vise igrati !" << endl;
			cout << "STANJE NOVACA: " << pInfo.cash << endl;
			cout << "STANJE CHIPOVA: " << pInfo.chips << endl << endl;
			cout << "MOLIMO TE NAPUSTI KASINO KLIKOM..." << endl;

			system("pause>nul");
			break;
		}

		switch (pInfo.state)
		{
		case PSTAT_REGI: // Upis imena i kolicine novca
			registerPlayer();
			break;

		case PSTAT_MENU: // Bira igru

			switch (showMenu())
			{
			case 1: // Izabere uplatu chipova
				uplataChipova();
				break;

			case 2: // Izabere isplatu novaca
				isplataNovaca();
				break;

			case 3: // Izabire igru

				showLogo();

				switch (showGames())
				{
				case 1: // Izabire jednoruki jack
					if (!checkChips(10))
					{
						break;
					}
					playingJednoruki();
					break;
				case 2: // Izabire bacanje kockica
					if (!checkChips(10))
					{
						break;
					}
					playingKockice();
					break;
				case 3: // Izabire duplo ili nista
					if (!checkChips(5))
					{
						break;
					}
					playingDuplo();
					break;
				case 4: // Izabire povratak
					break;
				default:
					break;
				}
				break;

			case 4: // Izabere prikaz High score-a
				showScores();
				break;

			case 5: // Izlaz iz programa
				exitProgram = true;
				break;

			default: // Krivi izbor
				break;
			}

			break;
		}
	}

	cout << "KLIKNI ZA IZLAZ IZ PROGRAMA..." << endl;
	system("pause>nul");
	saveScores();

	return 0;
}

void resetPlayer()
{
	pInfo.state = PSTAT_REGI;
	pInfo.cash = 0;
	pInfo.chips = 0;
	pInfo.name = "username";
}

void registerPlayer()
{
	cout << "Pozdrav novi korisnice, upisi svoje podatke kako" << endl;
	cout << "bi krenuo sa igrom u BootCampIT Casinu !" << endl;
	cout << endl;
	cout << "INFO: Svi igraci imaju pristup otvorenom sanku ! :)" << endl;
	cout << endl << endl;

	cout << "Upisi svoje ime: " << endl;
	cin >> pInfo.name;
	cout << endl;

	cout << "Upisi koliko novaca imas: " << endl;
	cin >> pInfo.cash;
	cout << endl << endl;;

	cout << pInfo.name << " dobrodosao u BootCampIT Casino !" << endl;
	cout << "KLIKNI ZA NASTAVAK..." << endl;
	system("pause>nul");

	pInfo.state = PSTAT_MENU;
}

void showLogo()
{
	system("cls");
	cout << "|---------------------------------------------------|" << endl;
	cout << "|               BootCampIT Casino                   |" << endl;
	cout << "|---------------------------------------------------|" << endl;
	cout << endl;
}

int showMenu()
{
	int temp = -1;

	cout << "IZBORNIK: " << endl << endl;
	cout << "\t1\tUplata novaca (novci za chipove)" << endl;
	cout << "\t2\tIsplata novaca (chipovi za novce)" << endl;
	cout << "\t3\tOdabir igre" << endl;
	cout << "\t4\tHigh score" << endl;
	cout << "\t5\tIzlaz iz programa" << endl << endl;
	cout << "UPISI BROJ ZA IZBOR: " << endl;

	cin >> temp;

	return temp;
}

void uplataChipova()
{
	bool odabir = false;

	int temp = 0;

	while (!odabir)
	{
		while (temp < 1 || temp > pInfo.cash / 5)
		{
			showLogo();

			cout << "STANJE NOVACA: " << pInfo.cash << endl;
			cout << "STANJE CHIPOVA: " << pInfo.chips << endl << endl;
			cout << "MIN BROJ CHIPOVA ZA KUPIT: 1" << endl;
			cout << "MAX BROJ CHIPOVA ZA KUPIT: " << pInfo.cash / 5 << endl << endl;
			cout << "Upisi kolicinu chipova koju zelis kupit (0 = IZLAZ): " << endl;

			cin >> temp;

			if (temp == 0)
			{
				showLogo();

				cout << endl << "ODUSTAO SI OD UNOSA !\nKLIKNI ZA POVRATAK...";
				system("pause>nul");
				return;
			}
			if (temp < 1)
			{
				showLogo();

				cout << endl << "IZNOS NEMOZE BITI MANJI OD 0 !\nKLIKNI ZA NOVI UNOS...";
				system("pause>nul");
			}
			if (temp > pInfo.cash / 5)
			{
				showLogo();

				cout << endl << "NEMAS TOLIKO NOVCA !\nKLIKNI ZA NOVI UNOS...";
				system("pause>nul");
			}

		}

		cout << endl << "Zamjeni " << temp * 5 << " novaca za " << temp << " chipova ? (DA/NE)" << endl;

		string dane;
		cin >> dane;

		if (dane == "DA" || dane == "da")
		{
			pInfo.chips += temp;
			pInfo.cash -= temp * 5;

			showLogo();

			cout << "NOVO STANJE NOVACA: " << pInfo.cash << endl;
			cout << "NOVO STANJE CHIPOVA: " << pInfo.chips << endl << endl;
			cout << endl << "CESTITAMO NA KUPOVINI !\nKLIKNI ZA NASTAVAK...";
			system("pause>nul");
			odabir = true;
		}
		else
		{
			cout << "ODUSTAO SI OD ZAMJENE !\n\nKLIKNI ZA POVRATAK..." << endl;
			system("pause>nul");
			return;
		}
	}
}

void isplataNovaca()
{
	bool odabir = false;

	int temp = 0;

	while (!odabir)
	{
		while (temp < 1 || temp > pInfo.chips)
		{
			showLogo();

			cout << "STANJE NOVACA: " << pInfo.cash << endl;
			cout << "STANJE CHIPOVA: " << pInfo.chips << endl << endl;
			cout << "MIN BROJ CHIPOVA ZA PRODAT: 1" << endl;
			cout << "MAX BROJ CHIPOVA ZA PRODAT: " << pInfo.chips << endl << endl;
			cout << "Upisi kolicinu chipova koju zelis prodat (0 = IZLAZ): " << endl;

			cin >> temp;

			if (temp == 0)
			{
				showLogo();

				cout << endl << "ODUSTAO SI OD UNOSA !\nKLIKNI ZA POVRATAK...";
				system("pause>nul");
				return;
			}
			if (temp < 1)
			{
				showLogo();

				cout << endl << "IZNOS NEMOZE BITI MANJI OD 0 !\nKLIKNI ZA NOVI UNOS...";
				system("pause>nul");
			}
			if (temp > pInfo.chips)
			{
				showLogo();

				cout << endl << "NEMAS TOLIKO CHIPOVA !\nKLIKNI ZA NOVI UNOS...";
				system("pause>nul");
			}

		}

		cout << endl << "Zamjeni " << temp << " chipova za " << temp * 5 << " novaca ? (DA/NE)" << endl;

		string dane;
		cin >> dane;

		if (dane == "DA" || dane == "da")
		{
			pInfo.chips -= temp;
			pInfo.cash += temp * 5;

			showLogo();

			cout << "NOVO STANJE NOVACA: " << pInfo.cash << endl;
			cout << "NOVO STANJE CHIPOVA: " << pInfo.chips << endl << endl;
			cout << endl << "CESTITAMO NA KUPOVINI !\nKLIKNI ZA NASTAVAK...";
			system("pause>nul");
			odabir = true;
		}
		else
		{
			cout << "ODUSTAO SI OD ZAMJENE !\n\nKLIKNI ZA POVRATAK..." << endl;
			system("pause>nul");
			return;
		}
	}
}

void loadScores()
{
	ifstream input("baza.txt");

	string line;

	while (input)
	{
		Game nesto;

		getline(input, line, ' ');
		nesto.name = line;
		getline(input, line, ' ');
		nesto.game = stoi(line);
		getline(input, line);
		nesto.score = stoi(line);

		gInfo.push_back(nesto);
	}
	input.close();
	gInfo.pop_back();
}

void saveScores()
{
	string za_spremanje;

	if (gInfo.size() == 0)
	{
		return;
	}

	for (int i = 0; i < gInfo.size(); i++)
	{
		if (i != 0)
		{
			za_spremanje += "\n";
		}

		za_spremanje += gInfo[i].name + " " + to_string(gInfo[i].game) + " " + to_string(gInfo[i].score);
	}

	ofstream output;
	output.open("baza.txt", ios::out);

	output << za_spremanje;
	output.close();
}

void showScores()
{
	if (gInfo.size() < 1)
	{
		showLogo();
		cout << "NEMA REZULTATA ZA PRIKAZ !" << endl << endl;
		cout << "KLIKNI ZA POVRATAK..." << endl;
		system("pause>nul");
		return;
	}

	int best[4][5];
	int temp;
	int *temp2 = new int[gInfo.size()];
	int *temp4 = new int[gInfo.size()];
	int temp3;

	// Resetamo
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			best[i][j] = 0;
		}
	}


	// Prvo preslazemo sve scoreove za svaku igru
	for (int game = 0; game < 3; game++)
	{
		for (int i = 0; i < gInfo.size(); i++)
		{
			if (i == 5)
			{
				break;
			}

			temp = 0;
			temp3 = 0;

			for (int j = 0; j < gInfo.size(); j++)
			{
				if (gInfo[j].score > temp && gInfo[j].game == game + 1 && temp2[j] != 1)
				{
					temp = gInfo[j].score;
					temp3 = j;
				}
			}

			if (temp3 != -1)
			{
				temp2[temp3] = 1;
				best[game][i] = temp3;
			}
		}
	}


	// Trazimo 5 najvecih score-a
	for (int i = 0; i < gInfo.size(); i++)
	{
		if (i == 5)
		{
			break;
		}

		temp = 0;
		temp3 = 0;

		for (int j = 0; j < gInfo.size(); j++)
		{
			if (gInfo[j].score > temp && temp4[j] != 1)
			{
				temp = gInfo[j].score;
				temp3 = j;
			}
		}

		if (temp3 != -1)
		{
			temp4[temp3] = 1;
			best[3][i] = temp3;
		}
	}

	// Ispis scorea za svaku igru
	showLogo();

	for (int i = 0; i < 3; i++)
	{
		switch (i)
		{
		case 0:
			cout << "\t\tJEDNORUKI JACK" << endl;
			break;
		case 1:
			cout << "\t\tBACANJE KOCKICA" << endl;
			break;
		case 2:
			cout << "\t\tDUPLO ILI NISTA" << endl;
			break;
		}

		for (int j = 0; j < 3; j++)
		{
			int id = best[i][j];

			cout << "\t" << j + 1 << ".\t" << gInfo[id].name << "\t" << gInfo[id].score << endl;
		}

		cout << endl;
	}

	cout << "\t\tNAJBOLJIH 5 IKADA" << endl;

	for (int j = 0; j < 5; j++)
	{
		int id = best[3][j];

		cout << "\t" << j + 1 << ".\t" << gInfo[id].name << "\t" << gInfo[id].score << "\t" << gameName(gInfo[id].game) << endl;
	}

	cout << endl << "KLIKNI ZA POVRATAK..." << endl;
	system("pause>nul");
}

int showGames()
{
	int temp = -1;

	cout << "IZBORNIK IGRA: " << endl << endl;
	cout << "\t1\tJednoruki Jack" << endl;
	cout << "\t2\tBacanje kockica" << endl;
	cout << "\t3\tDuplo ili nista" << endl;
	cout << "\t4\tPovratak" << endl << endl;
	cout << "UPISI BROJ ZA IZBOR: " << endl;

	cin >> temp;

	return temp;
}

bool checkChips(int amount)
{
	if (pInfo.chips < amount)
	{
		showLogo();

		cout << "Nemas dovoljno chipova !" << endl;
		cout << "STANJE: " << pInfo.chips << endl;
		cout << "Potrebno ti je minimalno " << amount << " chipova za nastavak igre !" << endl << endl;
		cout << "KLIKNI ZA NASTAVAK !" << endl;
		system("pause>nul");
		return false;
	}
	return true;
}

void playingDuplo()
{
	int exitDuplo = false;
	int ulog = 0;
	int unos = 1;
	int count = 0;

	showLogo();
	cout << "\tDUPLO ILI NISTA" << endl << endl;

	cout << "UPUTE:" << endl;
	cout << "\tNakon uloga i kretanja u igru kompjuter izvlaci" << endl;
	cout << "\tkartu za sebe i kartu za igraca. Ukoliko imas" << endl;
	cout << "\tjacu kartu od kompjutera mozes podignuti dobitak." << endl;
	cout << "\tUkoliko dobijes manju kartu mozes odustati ili" << endl;
	cout << "\tpovecati ulog da duplo." << endl << endl;

	cout << "KLIKNI ZA NASTAVAK..." << endl;
	system("pause>nul");

	while (!exitDuplo)
	{
		bool kInfo[52];
		int card1 = rand() % 52,
			card2 = rand() % 52;
		bool winner;
		string winstr;
		Game nesto;

		showLogo();
		cout << "\tDUPLO ILI NISTA" << endl << endl;

		cout << "KOMANDE: " << endl;
		cout << "\t1\tPlati" << endl;
		cout << "\t2\tPodigni" << endl;
		cout << "\t3\tIzlaz" << endl << endl;;

		cout << "POCETNI ULOG: 5 CHIPS" << endl << endl;

		cout << "\tSTANJE\tULOG\tSTANJE\tTVOJE KARTE\tKOMP. KARTE\tPOBJEDNIK" << endl;

		while (unos != 0)
		{
			cin >> unos;

			switch (unos)
			{
			case 1: // Izvlacenje karata

				count++;
				if (count > 26)
				{
					cout << "SPIL KARATA JE POTROSEN !\nIGRA JE ZAVRSILA !" << endl << endl;
					cout << "KLIKNI ZA POVRATAK..." << endl;
					system("pause>nul");
					return;
				}
				if (ulog == 0)
				{
					ulog = 5;
				}
				else
				{
					ulog *= 2;
				}

				if (!checkChips(ulog))
				{
					return;
				}

				while (kInfo[card1] == true)
				{
					card1 = rand() % 52;
				}
				kInfo[card1] = true;
				while (kInfo[card2] == true)
				{
					card2 = rand() % 52;
				}
				kInfo[card2] = true;

				if (cardValue(card1) > cardValue(card2))
				{
					winner = true;
					winstr = "COVJEK";
				}
				else
				{
					winner = false;
					winstr = "KOMPJ.";
				}

				cout << "\t" << pInfo.chips << "\t" << ulog << "\t" << pInfo.chips - ulog << "\t" << cardName(card1) << "\t\t" << cardName(card2) << "\t\t" << winstr;

				cout << "\t 1 (PLATI " << ulog << " ) ";

				if (winner)
				{
					cout << "\t2 (PODIGNI " << 2 * ulog << " ) " << endl;
				}

				pInfo.chips -= ulog;

				break;
			case 2:
				if (!winner || count == 0)
				{
					cout << "Nemozes podignuti chipove !" << endl;
					break;
				}

				pInfo.chips += ulog * 2;
				cout << "Podignuo si " << ulog * 2 << " chipova !" << endl << endl;

				nesto.name = pInfo.name;
				nesto.game = 3;
				nesto.score = ulog * 2;
				gInfo.push_back(nesto);
				saveScores();

				cout << "KLIKNI ZA NASTAVAK...";
				system("pause>nul");
				return;
			case 3:
				exitDuplo = true;
				cout << "KLIKNI ZA IZLAZ IZ IGRE..." << endl;
				system("pause>nul");
				break;
			default:
				break;
			}
		}
	}
}

string cardName(int card)
{
	string temp;
	int znak = card % 13;

	if (card <= 12)
	{
		temp += "TREF ";
	}
	else if (card >= 13 && card <= 25)
	{
		temp += "PIK ";
	}
	else if (card >= 26 && card <= 38)
	{
		temp += "SRCE ";
	}
	else if (card >= 39)
	{
		temp += "KARO ";
	}

	switch (znak)
	{
	case 0:
		temp += "2";
		break;
	case 1:
		temp += "3";
		break;
	case 2:
		temp += "4";
		break;
	case 3:
		temp += "5";
		break;
	case 4:
		temp += "6";
		break;
	case 5:
		temp += "7";
		break;
	case 6:
		temp += "8";
		break;
	case 7:
		temp += "9";
		break;
	case 8:
		temp += "10";
		break;
	case 9:
		temp += "J";
		break;
	case 10:
		temp += "Q";
		break;
	case 11:
		temp += "K";
		break;
	case 12:
		temp += "A";
		break;
	}

	return temp;
}

int cardValue(int card)
{
	return card % 13;
}

void playingKockice()
{
	int zbroj1,
		zbroj2,
		zbroja,
		zbrojb,
		ulog;

	showLogo();
	cout << "\tBACANJE KOCKICA" << endl << endl;

	cout << "UPUTE:" << endl;
	cout << "\tPrvo izaberes ulog koji zelis uloziti." << endl;
	cout << "\tNakon toga 2 puta bacas kockice naizmjenicno" << endl;
	cout << "\tprotiv kompjutera. Veci zbroj vrijednosti" << endl;
	cout << "\tpobjeduje. Nerjesena igra nema pobjednika." << endl << endl;

	cout << "KLIKNI ZA NASTAVAK..." << endl;
	system("pause>nul");

	while (pInfo.chips > 0)
	{
		zbroj1 = 0;
		zbroj2 = 0;
		zbroja = 0;
		zbrojb = 0;

		showLogo();
		cout << "\tBACANJE KOCKICA" << endl << endl;

		cout << "Upisi iznos koji zelis uloziti (0 = IZLAZ): " << endl;
		cout << "STANJE CHIPOVA: " << pInfo.chips << endl;
		cin >> ulog;

		if (ulog == 0)
		{
			cout << "NAPUSTIO SI IGRU !" << endl;
			cout << "KLIKNI ZA IZLAZ..." << endl;
			system("pause>nul");
			return;
		}

		while (ulog < 1 || ulog > pInfo.chips)
		{
			cout << "Iznos nemoze biti manji od 1 ili veci od " << pInfo.chips << " ! (0 = IZLAZ)" << endl;
			cin >> ulog;
		}

		cout << "KLIKNI ZA BACENJE KOCKICA:" << endl;
		system("pause>nul");
		pInfo.chips -= ulog;

		zbroj1 = rand() % 6 + 1;
		zbroj2 = rand() % 6 + 1;

		cout << "\tCOVJEK\tKOMPJUTER" << endl;
		cout << "\t" << zbroj1 << "\t" << zbroj2 << endl << endl;

		cout << "KLIKNI ZA BACENJE KOCKICA:" << endl;
		system("pause>nul");

		cout << "\tCOVJEK\tKOMPJUTER" << endl;
		cout << "\t" << zbroj1 << "\t" << zbroj2 << endl;
		zbroja += rand() % 6 + 1;
		zbrojb += rand() % 6 + 1;
		zbroj1 += zbroja;
		zbroj2 += zbrojb;
		cout << "\t" << zbroja << "\t" << zbrojb << endl << endl;
		cout << "UKUPNO\t" << zbroj1 << "\t" << zbroj2 << endl << endl;

		if (zbroj1 > zbroj2)
		{
			cout << "POBJEDNIK: " << pInfo.name << endl;
			cout << "STANJE CHIPOVA: " << pInfo.chips << endl;
			cout << "DOBITAK: " << ulog * 2 << endl;
			cout << "NOVO STANJE: " << pInfo.chips + (ulog * 2) << endl << endl;

			pInfo.chips += ulog * 2;

			Game nesto;
			nesto.name = pInfo.name;
			nesto.game = 2;
			nesto.score = ulog * 2;
			gInfo.push_back(nesto);
			saveScores();
		}
		else if (zbroj1 < zbroj2)
		{
			cout << "POBJEDNIK: KOMPJUTER" << endl;
			cout << "DOBITAK: " << ulog * 2 << endl;
		}
		else
		{
			cout << "POBJEDNIK: NEMA DOBITNIKA" << endl;
			cout << "STANJE CHIPOVA: " << pInfo.chips << endl;
			cout << "DOBITAK: ULOG ( " << ulog << " )" << endl;
			cout << "NOVO STANJE: " << pInfo.chips + ulog << endl << endl;
		}

		cout << "KLIKNI ZA NASTAVAK..." << endl;
		system("pause>nul");
	}
}

void playingJednoruki()
{
	showLogo();
	cout << "\tJEDNORUKI JACK" << endl << endl;

	cout << "UPUTE:" << endl;
	cout << "\tPrvo izaberes ulog koji zelis uloziti." << endl;
	cout << "\tNakon toga kliknes da pokrenes masinu. " << endl;
	cout << "\tKarte se moraju slagati slijeva nadesno !" << endl;
	cout << "\tUlog 0 = IZLAZ !" << endl << endl;

	cout << "KLIKNI ZA NASTAVAK..." << endl;
	system("pause>nul");

	while (pInfo.chips > 0)
	{
		int ulog;
		int machine[4];
		int multi = 0;

		showLogo();
		cout << "\tJEDNORUKI JACK" << endl << endl;

		cout << "Upisi iznos koji zelis uloziti (0 = IZLAZ): " << endl;
		cout << "STANJE CHIPOVA: " << pInfo.chips << endl;
		cin >> ulog;

		if (ulog == 0)
		{
			cout << "NAPUSTIO SI IGRU !" << endl;
			cout << "KLIKNI ZA IZLAZ..." << endl;
			system("pause>nul");
			return;
		}

		while (ulog < 1 || ulog > pInfo.chips)
		{
			cout << "Iznos nemoze biti manji od 1 ili veci od " << pInfo.chips << " ! (0 = IZLAZ)" << endl;
			cin >> ulog;
		}
		pInfo.chips -= ulog;

		cout << "KLIKNI ZA POKRETANJE MASINE:" << endl;
		system("pause>nul");

		showLogo();
		cout << "\tJEDNORUKI JACK" << endl << endl;

		machine[0] = rand() % 4;
		machine[1] = rand() % 4;
		machine[2] = rand() % 4;
		machine[3] = rand() % 4;

		printMachine(machine[0], machine[1], machine[2], machine[3]);
		printPoints(ulog);

		if (machine[0] == machine[1] && machine[1] == machine[2] && machine[2] == machine[3])
		{
			multi = 32;
		}
		else if (machine[0] == machine[1] && machine[1] == machine[2])
		{
			multi = 8;
		}
		else if (machine[0] == machine[1])
		{
			multi = 4;
		}

		if (multi == 0)
		{
			cout << "DOBITAK: NEMA DOBITKA !" << endl << endl;
			cout << "KLIKNI ZA NOVU IGRU..." << endl;
			system("pause>cin");
		}
		else
		{
			cout << "DOBITAK: x" << multi << endl;
			cout << "STANJE CHIPOVA: " << pInfo.chips << endl;
			cout << "DOBITAK: " << ulog * multi << endl;
			cout << "NOVO STANJE: " << pInfo.chips + (ulog * multi) << endl << endl;

			pInfo.chips += ulog * multi;

			Game nesto;
			nesto.name = pInfo.name;
			nesto.game = 1;
			nesto.score = ulog * multi;
			gInfo.push_back(nesto);
			saveScores();

			cout << "KLIKNI ZA NOVU IGRU..." << endl;
			system("pause>nul");
		}
	}
}

void printMachine(int a, int b, int c, int d)
{
	char nes[4];

	if (a == 0)
	{
		nes[0] = 'X';
	}
	else if (a == 1)
	{
		nes[0] = 'Y';
	}
	else if (a == 2)
	{
		nes[0] = 'Z';
	}
	else if (a == 3)
	{
		nes[0] = 'A';
	}

	if (b == 0)
	{
		nes[1] = 'X';
	}
	else if (b == 1)
	{
		nes[1] = 'Y';
	}
	else if (b == 2)
	{
		nes[1] = 'Z';
	}
	else if (b == 3)
	{
		nes[1] = 'A';
	}

	if (c == 0)
	{
		nes[2] = 'X';
	}
	else if (c == 1)
	{
		nes[2] = 'Y';
	}
	else if (c == 2)
	{
		nes[2] = 'Z';
	}
	else if (c == 3)
	{
		nes[2] = 'A';
	}

	if (d == 0)
	{
		nes[3] = 'X';
	}
	else if (d == 1)
	{
		nes[3] = 'Y';
	}
	else if (d == 2)
	{
		nes[3] = 'Z';
	}
	else if (d == 3)
	{
		nes[3] = 'A';
	}

	for (int i = 0; i < 3; i++)
	{
		cout << "\t" << nes[0] << nes[0] << nes[0]
			<< "\t" << nes[1] << nes[1] << nes[1]
			<< "\t" << nes[2] << nes[2] << nes[2]
			<< "\t" << nes[3] << nes[3] << nes[3] << endl;
	}
}

void printPoints(int ulog)
{
	cout << endl;
	cout << "\t2 ISTE\t4 x  ULOG (" << ulog << ") = " << ulog * 4 << endl;
	cout << "\t3 ISTE\t8 x  ULOG (" << ulog << ") = " << ulog * 8 << endl;
	cout << "\t4 ISTE\t32 x ULOG (" << ulog << ") = " << ulog * 32 << endl;
	cout << endl;
}

string gameName(int game)
{
	string temp;

	switch (game)
	{
	case 1:
		temp = "JEDNORUKI JACK";
		break;
	case 2:
		temp = "BACANJE KOCKICA";
		break;
	case 3:
		temp = "DUPLO ILI NISTA";
		break;
	}
	return temp;
}