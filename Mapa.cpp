#include "Mapa.h"
#include "random"

using namespace std;

void Mapa::grafika()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 15);

	constexpr size_t dlug = 25;
	constexpr size_t szer = 50;

	//Wartosc 0-neutralna(szara), 1-jedna strona(czerwona), 2-druga strona(niebieska) etc.//
	int strona[dlug][szer];
	char mapa[dlug][szer];

	for (int i = 0; i < dlug; i++)
		for (int j = 0; j < szer; j++)
			mapa[i][j] = ' ';

	for (int i = 10; i < 15; i++)
		for (int j = 10; j < 15; j++)
			mapa[i][j] = 'X';

	random_device seed;
	mt19937 gen(seed());
	uniform_int_distribution<size_t> losuj_dlug{ 10, dlug - 1 };
	uniform_int_distribution<size_t> losuj_szer{ 20, szer - 1 };
	uniform_int_distribution<int> strony{ 0, 2 };

	for (int i = 0; i < 5; i++)
		mapa[losuj_dlug(gen)][losuj_szer(gen)] = '#';

	cout << "|";
	for (int i = 0; i < szer; i++)
		cout << "=";
	cout << "|" << endl;

	for (int i = 0; i < dlug; i++)
	{
		cout << "|";
		for (int j = 0; j < szer; j++)
		{
			strona[i][j] = strony(gen);
			switch (strona[i][j])
			{
			case 0:
				SetConsoleTextAttribute(hOut, BACKGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
				break;
			case 1:
				SetConsoleTextAttribute(hOut, BACKGROUND_RED | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
				break;
			case 2:
				SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
				break;
			default:
				break;
			}
			cout << mapa[i][j];
		}
		SetConsoleTextAttribute(hOut, 15);
		cout << "|" << endl;
	}

	cout << "|";
	for (int i = 0; i < szer; i++)
		cout << "=";
	cout << "|";
}

Prowincja Mapa::mapa[Mapa::dlug][Mapa::szer];

void Mapa::rysuj(const std::vector<Armia>& armie, HANDLE hOut)
{
	for (auto armia : armie)
	{
		mapa[armia.dajPozycjeX()][armia.dajPozycjeY()].symbol = armia.dajSymbol();
		mapa[armia.dajPozycjeX()][armia.dajPozycjeY()].przynaleznosc = armia.dajPrzyna();
	}

	clrscr();

	cout << "|";
	for (int i = 0; i < szer; i++)
		cout << "=";
	cout << "|" << endl;

	for (size_t i = 0; i < dlug; i++)
	{
		cout << "|";
		for (size_t j = 0; j < szer; j++)
		{
			switch (mapa[i][j].przynaleznosc)
			{
			case 0:
				SetConsoleTextAttribute(hOut, 128);
				break;
			case 1:
				SetConsoleTextAttribute(hOut, BACKGROUND_RED | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
				break;
			case 2:
				SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
				break;
			case 3:
				SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_RED | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
				break;
			}
			cout << mapa[i][j].symbol;
		}
		SetConsoleTextAttribute(hOut, 15);
		cout << "|" << endl;
	}

	for (size_t i = 0; i < dlug; i++)
	{
		for (size_t j = 0; j < szer; j++)
		{
			mapa[i][j].symbol = ' ';
		}
	}

	cout << "|";
	for (int i = 0; i < szer; i++)
		cout << "=";
	cout << "|";

	// opoznienie w rysowaniu, to sie doda do tej klasy "zegar" czy cos, albo w ogole sie z tego zrezygnuje aby symulacja sie
	// szybko przeprowadzila, bo rysowanie zajmuje duzo czasu
	for (int i = 0; i < 10000000; i++);
}

