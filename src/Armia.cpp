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

	vector<Prowincja> prowincje_do_wyboru;
	int cele = 0;
	vector<Prowincja> cel;

	if (pozycjaX != 0)
	{
		prowincje_do_wyboru.push_back(Mapa::mapa[pozycjaX-1][pozycjaY]);
	}
	if (pozycjaY != 0)
	{
		prowincje_do_wyboru.push_back(Mapa::mapa[pozycjaX][pozycjaY - 1]);
	}
	if (pozycjaX != x - 1)
	{
		prowincje_do_wyboru.push_back(Mapa::mapa[pozycjaX + 1][pozycjaY]);
	}
	if (pozycjaY != y - 1)
	{
		prowincje_do_wyboru.push_back(Mapa::mapa[pozycjaX][pozycjaY + 1]);
	}

	int armia_do_kasacji = 0;

	for (int i = 0; i < prowincje_do_wyboru.size(); i++)
	{
		if (prowincje_do_wyboru[i].dajArmieWProwincji() != 0 && prowincje_do_wyboru[i].dajArmieWProwincji() != id)
		{
			zwiad.raport();
			armia_do_kasacji = prowincje_do_wyboru[i].dajArmieWProwincji();
			pozycjaX = prowincje_do_wyboru[i].dajwspolrzednax();
			pozycjaY = prowincje_do_wyboru[i].dajwspolrzednay();
			goto przejscie;

		}
		else if (prowincje_do_wyboru[i].dajPrzynaleznosc() != przynaleznosc)
		{
			cel.push_back(prowincje_do_wyboru[i]);
			cele++;
		}
	}

	if (cele != 0)
	{
		uniform_int_distribution<size_t> kierunek{ 0, cel.size() - 1 };
		pom = kierunek(gen);
		pozycjaX = cel[pom].dajwspolrzednax();
		pozycjaY = cel[pom].dajwspolrzednay();
	}
	else
	{
		uniform_int_distribution<size_t> kierunek{ 0, prowincje_do_wyboru.size() - 1 };
		pom = kierunek(gen);
		pozycjaX = prowincje_do_wyboru[pom].dajwspolrzednax();
		pozycjaY = prowincje_do_wyboru[pom].dajwspolrzednay();
	}

przejscie:

	Mapa::mapa[pozycjaX][pozycjaY].zmienSymbol(symbol);
	Mapa::mapa[pozycjaX][pozycjaY].zmienArmieWProwincji(id);

	if (Mapa::mapa[pozycjaX][pozycjaY].dajPrzynaleznosc() != przynaleznosc)
	{
		Mapa::mapa[pozycjaX][pozycjaY].zmienPrzynaleznosc(przynaleznosc);
	}
	return armia_do_kasacji;
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