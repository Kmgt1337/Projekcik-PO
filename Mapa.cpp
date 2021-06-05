#include "Mapa.h"

using namespace std;

vector<vector<Prowincja>> Mapa::mapa;
size_t Mapa::dlug;
size_t Mapa::szer;

void Mapa::inicjalizuj(size_t x, size_t y)
{
	dlug = y;
	szer = x;

	mapa.resize(dlug);
	for (size_t i = 0; i < mapa.size(); i++)
	{
		mapa[i].resize(szer);
	}
}

void Mapa::reset()
{
	for (size_t i = 0; i < mapa.size(); i++)
	{
		for (size_t j = 0; j < mapa.at(i).size(); j++)
		{
			mapa[i][j].przynaleznosc = 0;
			mapa[i][j].symbol = ' ';
		}
	}
}

void Mapa::rysuj(const vector<Armia> armie, HANDLE hOut)
{

	cout << "|";
	for (int i = 0; i < szer; i++)
		cout << "=";
	cout << "|" << endl;

	for (size_t i = 0; i < mapa.size(); i++)
	{
		cout << "|";
		for (size_t j = 0; j < mapa[i].size(); j++)
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
	clrscr();

	// opoznienie w rysowaniu, to sie doda do tej klasy "zegar" czy cos, albo w ogole sie z tego zrezygnuje aby symulacja sie
	// szybko przeprowadzila, bo rysowanie zajmuje duzo czasu
	//for (int i = 0; i < 10000000; i++);
}