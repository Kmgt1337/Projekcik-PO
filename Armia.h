#ifndef ARMIA_H
#define ARMIA_H

class Armia
{
public:
	Armia(size_t, size_t, char);
	void ruch();
	void bitwa();
	void przejecie();

	size_t dajPozycjeX() { return pozycjaX; }
	size_t dajPozycjeY() { return pozycjaY; }
	char dajSymbol() { return symbol; }

private:
	int przejmowanieS;
	
	size_t liczebnosc;
	size_t pozycjaX;
	size_t pozycjaY;
	float szybkosc;

	char symbol;
};

#endif