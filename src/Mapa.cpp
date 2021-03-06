#include "Mapa.h"
#include <iomanip>

using namespace std;

vector<vector<Prowincja>> Mapa::mapa;
size_t Mapa::dlug;
size_t Mapa::szer;

void Mapa::clrscr()
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { 0, 0 };
	SetConsoleCursorPosition(hCon, coord);
	HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO hCCI;
	GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	SetConsoleCursorInfo(hConsoleOut, &hCCI);
}

void Mapa::inicjalizuj(size_t x, size_t y)
{
	dlug = y;
	szer = x;

	mapa.resize(dlug);
	for (size_t i = 0; i < mapa.size(); i++)
	{
		mapa[i].resize(szer);
	}
	for (size_t i = 0; i < mapa.size(); i++)
	{
		for (size_t j = 0; j < mapa[i].size(); j++)
		{
			mapa[i][j].zmienwspolrzednax(i);
			mapa[i][j].zmienwspolrzednay(j);
		}
	}
}

vector<size_t> Mapa::dajLiczbeProwincjiKazdejArmii(Armia armia1, Armia armia2)
{
	std::vector<size_t> pom;
	size_t larmia1 = 0;
	size_t larmia2 = 0;

	for (size_t i = 0; i < mapa.size(); i++)
	{
		for (size_t j = 0; j < mapa[i].size(); j++)
		{
			if (mapa[i][j].dajPrzynaleznosc() == armia1.dajPrzyna())
			{
				larmia1++;
			}
			if (mapa[i][j].dajPrzynaleznosc() == armia2.dajPrzyna())
			{
				larmia2++;
			}
		}
	}
	pom.push_back(larmia1);
	pom.push_back(larmia2);
	return pom;
}

size_t Mapa::dajLiczbeProwincjiArmii(Armia armia)
{
	size_t larmia = 0;
	for (size_t i = 0; i < mapa.size(); i++)
	{
		for (size_t j = 0; j < mapa[i].size(); j++)
		{
			if (mapa[i][j].dajPrzynaleznosc() == armia.dajPrzyna())
			{
				larmia++;
			}
		}
	}

	return larmia;
}

void Mapa::reset()
{
	for (size_t i = 0; i < mapa.size(); i++)
	{
		for (size_t j = 0; j < mapa.at(i).size(); j++)
		{
			mapa[i][j].zmienPrzynaleznosc(0);
			mapa[i][j].zmienSymbol(' ');
		}
	}
}

void Mapa::rysuj(const vector<Armia>& armie, HANDLE hOut)
{
	cout << "|";
	for (size_t i = 0; i < szer; i++)
		cout << "=";
	cout << "|" << endl;

	for (size_t i = 0; i < mapa.size(); i++)
	{
		cout << "|";
		for (size_t j = 0; j < mapa[i].size(); j++)
		{
			switch (mapa[i][j].dajPrzynaleznosc()) {
			case 0:
				SetConsoleTextAttribute(hOut, 128);
				break;
			case 7:
				SetConsoleTextAttribute(hOut, 191);
				break;
			case 8:
				SetConsoleTextAttribute(hOut, 207);
				break;
			default:
				SetConsoleTextAttribute(hOut, 15 + 16 * mapa[i][j].dajPrzynaleznosc());
				break;
			}
			cout << mapa[i][j].dajSymbol();
		}
		SetConsoleTextAttribute(hOut, 15);
		cout << "|" << endl;
	}

	for (size_t i = 0; i < dlug; i++)
	{
		for (size_t j = 0; j < szer; j++)
		{
			mapa[i][j].zmienSymbol(' ');
		}
	}

	cout << "|";
	for (size_t i = 0; i < szer; i++)
		cout << "=";
	cout << "|";
	clrscr();
}