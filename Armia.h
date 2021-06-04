#ifndef ARMIA_H
#define ARMIA_H

#include <string>

class Armia
{
public:
	Armia(size_t, size_t, char, int, std::string);
	void ruch();
	void bitwa();
	void przejecie();

	size_t dajPozycjeX() { return pozycjaX; }
	size_t dajPozycjeY() { return pozycjaY; }
	int dajPrzyna() { return przynaleznosc; }
	char dajSymbol() { return symbol; }
	std::string dajNazwe() { return nazwaArmii; }
	size_t dajLiczebnosc() { return liczebnosc; }

	static void inicjalizuj(size_t, size_t);

private:
	int przejmowanieS;
	int przynaleznosc;

	size_t liczebnosc;
	size_t pozycjaX;
	size_t pozycjaY;
	float szybkosc;

	std::string nazwaArmii;
	char symbol;

	static size_t x, y;
};

#endif