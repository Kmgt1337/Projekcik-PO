#include "Prowincja.h"

Prowincja::Prowincja(size_t x, size_t y, size_t wielkosc, std::string nazwa, char symbol)
{
	this->symbol = symbol;
	this->nazwa = nazwa;

	pozycjaX = x;
	pozycjaY = y;

	for (size_t i = 0; i < wielkosc; i++)
	{
		wspolrzedneX.push_back(pozycjaX++);
		wspolrzedneY.push_back(pozycjaY++);
	}
}