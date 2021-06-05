#ifndef ARMIA_H
#define ARMIA_H

#include <string>

class Armia
{

public:
	Armia(int, size_t, size_t, char, int, std::string, size_t);
	Armia();
	int ruch();
	void bitwa();
	void przejecie();
	bool aktywna;
	char symbol;
	int id;
	int liczebnosc;

	size_t dajPozycjeX() { return pozycjaY; }
	size_t dajPozycjeY() { return pozycjaX; }
	int dajPrzyna() { return przynaleznosc; }
	char dajSymbol() { return symbol; }
	std::string dajNazwe() { return nazwaArmii; }
	int dajLiczebnosc() { return liczebnosc; }

	static void inicjalizuj(size_t, size_t);

private:
	int przejmowanieS;
	int przynaleznosc;

	size_t pozycjaX;
	size_t pozycjaY;
	float szybkosc;

	std::string nazwaArmii;

	static size_t x, y;
};

#endif