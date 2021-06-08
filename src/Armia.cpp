#include "Armia.h"
#include "Mapa.h"
#include "Zwiad.h"
#include <random>
#include <iomanip>

using namespace std;

Armia::Armia()
{

}

Armia::Armia(int id, size_t x, size_t y, char symbol, int przynaleznosc, std::string nazwa, size_t liczebnosc)
{
	aktywna = 1;

	this->liczebnosc = liczebnosc;
	this->przynaleznosc = przynaleznosc;
	szybkosc = 1;
	this->id = id;

	pozycjaY = x;
	pozycjaX = y;

	this->symbol = symbol;
	nazwaArmii = nazwa;
}

size_t Armia::x;
size_t Armia::y;

void Armia::inicjalizuj(size_t a, size_t b)
{
	x = b;
	y = a;
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

	Mapa::mapa[pozycjaX][pozycjaY].zmienArmieWProwincji(0);

	switch (pom)
	{
		// ruch w gore
	case 1:
		if (pozycjaX != 0)
		{
			--pozycjaX;
			break;
		}

		//ruch w lewo
	case 2:
		if (pozycjaY != 0)
		{
			--pozycjaY;
			break;
		}

		//ruch w dol
	case 3:
		if (pozycjaX != x - 1)
		{
			++pozycjaX;
			break;
		}

		//ruch w prawo
	case 4:
		if (pozycjaY != y - 1)
		{
			++pozycjaY;
			break;
		}
	}

	zwiad.raport();

	Mapa::mapa[pozycjaX][pozycjaY].zmienSymbol(symbol);

	if (Mapa::mapa[pozycjaX][pozycjaY].dajArmieWProwincji() != 0)
	{
		int armia_do_kasacji = Mapa::mapa[pozycjaX][pozycjaY].dajArmieWProwincji();
		Mapa::mapa[pozycjaX][pozycjaY].zmienArmieWProwincji(id);
		return armia_do_kasacji;
	}

	Mapa::mapa[pozycjaX][pozycjaY].zmienArmieWProwincji(id);

	if (Mapa::mapa[pozycjaX][pozycjaY].dajPrzynaleznosc() != przynaleznosc)
	{
		Mapa::mapa[pozycjaX][pozycjaY].zmienPrzynaleznosc(przynaleznosc);
	}
	return 0;
}

void Armia::zbierzZasob(rodzajeZasobu zasob)
{
	switch (zasob)
	{
	case rodzajeZasobu::LICZEBNOSC5:
		liczebnosc = static_cast<int>(liczebnosc * 1.05);
		break;

	case rodzajeZasobu::LICZEBNOSC10:
		liczebnosc = static_cast<int>(liczebnosc * 1.1);
		break;

	case rodzajeZasobu::LICZEBNOSC15:
		liczebnosc = static_cast<int>(liczebnosc * 1.15);
		break;

	case rodzajeZasobu::OBRAZENIA5:
		modyfikatorObrazenZasob += 0.05f;
		break;

	case rodzajeZasobu::OBRAZENIA10:
		modyfikatorObrazenZasob += 0.1f;
		break;

	case rodzajeZasobu::OBRAZENIA15:
		modyfikatorObrazenZasob += 0.15f;
		break;

	case rodzajeZasobu::BRAK:
		break;
	}
}