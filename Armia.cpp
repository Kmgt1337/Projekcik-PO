#include "Armia.h"
#include <random>
#include <iomanip>
#include "Mapa.h"

using namespace std;

Armia::Armia()
{

}

Armia::Armia(int id, size_t x, size_t y, char symbol, int przynaleznosc, std::string nazwa, size_t liczebnosc)
{
	random_device device;
	mt19937 gen(device());
	uniform_int_distribution<size_t> losujLiczebnoscArmii{ 10000, 12000 };
	uniform_int_distribution<size_t> losujPrzejmowanieS{ 0, 5 };
	uniform_int_distribution<size_t> losujX{ 0, 59 };
	uniform_int_distribution<size_t> losujY{ 0, 29 };
	aktywna = 1;

	this->liczebnosc = liczebnosc;
	przejmowanieS = losujPrzejmowanieS(gen);
	this->przynaleznosc = przynaleznosc;
	szybkosc = 1;
	this->id = id;

	pozycjaX = x;
	pozycjaY = y;

	this->symbol = symbol;
	nazwaArmii = nazwa;
}

size_t Armia::x;
size_t Armia::y;

void Armia::inicjalizuj(size_t a, size_t b)
{
	x = a;
	y = b;
}

int Armia::ruch()
{
	if (aktywna == 0)
	{
		return 0;
	}

	random_device device;
	mt19937 gen(device());
	uniform_int_distribution<size_t> kierunek{ 1, 4 };
	size_t pom = kierunek(gen);

	Mapa::mapa[pozycjaX][pozycjaY].armia_w_prowincji = 0;

	switch (pom)
	{
		// ruch w gore
	case 1:
		if (pozycjaX == 0) break;
		--pozycjaX;
		break;

		//ruch w lewo
	case 2:
		if (pozycjaY == 0) break;
		--pozycjaY;
		break;

		//ruch w dol
	case 3:
		if (pozycjaX == x - 1) break;
		++pozycjaX;
		break;

		//ruch w prawo
	case 4:
		if (pozycjaY == y - 1) break;
		++pozycjaY;
		break;
	}

	Mapa::mapa[pozycjaX][pozycjaY].symbol = symbol;

	if (Mapa::mapa[pozycjaX][pozycjaY].armia_w_prowincji != 0)
	{
		int armia_do_kasacji = Mapa::mapa[pozycjaX][pozycjaY].armia_w_prowincji;
		Mapa::mapa[pozycjaX][pozycjaY].armia_w_prowincji = id;
		return armia_do_kasacji;
	}

	Mapa::mapa[pozycjaX][pozycjaY].armia_w_prowincji = id;

	if (Mapa::mapa[pozycjaX][pozycjaY].przynaleznosc != przynaleznosc)
	{
		Mapa::mapa[pozycjaX][pozycjaY].przynaleznosc = przynaleznosc;
	}
	return 0;
}