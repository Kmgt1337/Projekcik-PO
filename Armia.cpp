#include "Armia.h"
#include <random>
#include <iomanip>
#include "Mapa.h"
#include <windows.h>

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
	aktywna = 1;

	this->liczebnosc = liczebnosc;
	przejmowanieS = losujPrzejmowanieS(gen);
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

	int roz = 0;
	random_device device;
	mt19937 gen(device());
	size_t pom;
	vector<Prowincja> prowincje_do_wyboru;
	vector<Prowincja> cel;
	if (pozycjaX != 0)
	{
		if (Mapa::mapa[pozycjaX-1][pozycjaY].armia_w_prowincji != 0)
		{
			Mapa::mapa[pozycjaX][pozycjaY].armia_w_prowincji = 0;

			Mapa::mapa[pozycjaX-1][pozycjaY].symbol = symbol;

			if (Mapa::mapa[pozycjaX-1][pozycjaY].armia_w_prowincji != 0)
			{
				int armia_do_kasacji = Mapa::mapa[pozycjaX-1][pozycjaY].armia_w_prowincji;
				Mapa::mapa[pozycjaX-1][pozycjaY].armia_w_prowincji = id;
				return armia_do_kasacji;
			}
		}
		else if (Mapa::mapa[pozycjaX - 1][pozycjaY].przynaleznosc != przynaleznosc)
		{
			cel.push_back(Mapa::mapa[pozycjaX - 1][pozycjaY]);
			roz++;
		}
	}
	if (pozycjaY != 0)
	{
		if (Mapa::mapa[pozycjaX][pozycjaY - 1].armia_w_prowincji != 0)
		{
			Mapa::mapa[pozycjaX][pozycjaY].armia_w_prowincji = 0;

			Mapa::mapa[pozycjaX][pozycjaY - 1].symbol = symbol;

			if (Mapa::mapa[pozycjaX][pozycjaY - 1].armia_w_prowincji != 0)
			{
				int armia_do_kasacji = Mapa::mapa[pozycjaX][pozycjaY - 1].armia_w_prowincji;
				Mapa::mapa[pozycjaX][pozycjaY - 1].armia_w_prowincji = id;
				return armia_do_kasacji;
			}
		}
		else if (Mapa::mapa[pozycjaX][pozycjaY - 1].przynaleznosc != przynaleznosc)
		{
			cel.push_back(Mapa::mapa[pozycjaX][pozycjaY - 1]);
			roz++;
		}
	}
	if (pozycjaX != x - 1)
	{
		if (Mapa::mapa[pozycjaX + 1][pozycjaY].armia_w_prowincji != 0)
		{
			Mapa::mapa[pozycjaX][pozycjaY].armia_w_prowincji = 0;

			Mapa::mapa[pozycjaX + 1][pozycjaY].symbol = symbol;

			if (Mapa::mapa[pozycjaX + 1][pozycjaY].armia_w_prowincji != 0)
			{
				int armia_do_kasacji = Mapa::mapa[pozycjaX + 1][pozycjaY].armia_w_prowincji;
				Mapa::mapa[pozycjaX + 1][pozycjaY].armia_w_prowincji = id;
				return armia_do_kasacji;
			}
		}
		else if (Mapa::mapa[pozycjaX + 1][pozycjaY].przynaleznosc != przynaleznosc)
		{
			cel.push_back(Mapa::mapa[pozycjaX + 1][pozycjaY]);
			roz++;
		}
	}
	if (pozycjaY != y - 1)
	{
		if (Mapa::mapa[pozycjaX][pozycjaY + 1].armia_w_prowincji != 0)
		{
			Mapa::mapa[pozycjaX][pozycjaY].armia_w_prowincji = 0;

			Mapa::mapa[pozycjaX][pozycjaY + 1].symbol = symbol;

			if (Mapa::mapa[pozycjaX][pozycjaY + 1].armia_w_prowincji != 0)
			{
				int armia_do_kasacji = Mapa::mapa[pozycjaX][pozycjaY + 1].armia_w_prowincji;
				Mapa::mapa[pozycjaX][pozycjaY + 1].armia_w_prowincji = id;
				return armia_do_kasacji;
			}
		}
		else if (Mapa::mapa[pozycjaX][pozycjaY + 1].przynaleznosc != przynaleznosc)
		{
			cel.push_back(Mapa::mapa[pozycjaX][pozycjaY + 1]);
			roz++;
		}
	}

	if(roz == 0)
	{
		uniform_int_distribution<size_t> kierunek{ 1, 4 };
		pom = kierunek(gen);
		Mapa::mapa[pozycjaX][pozycjaY].armia_w_prowincji = 0;
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
	}
	else
	{
		uniform_int_distribution<size_t> kierunek{ 0, static_cast<size_t>(roz)-1 };
		pom = kierunek(gen);
		Mapa::mapa[pozycjaX][pozycjaY].armia_w_prowincji = 0;
		pozycjaX = cel[pom].wspolrzednax;
		pozycjaY = cel[pom].wspolrzednay;


		Mapa::mapa[pozycjaX][pozycjaY].symbol = symbol;

		Mapa::mapa[pozycjaX][pozycjaY].armia_w_prowincji = id;

		if (Mapa::mapa[pozycjaX][pozycjaY].przynaleznosc != przynaleznosc)
		{
			Mapa::mapa[pozycjaX][pozycjaY].przynaleznosc = przynaleznosc;
		}
	}
	return 0;
}