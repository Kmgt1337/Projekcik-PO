#ifndef PROWINCJA_H
#define PROWINCJA_H

#include <string>
#include <vector>

class Prowincja
{
private:
	std::string nazwa;
	size_t pozycjaX;
	size_t pozycjaY;
	std::vector<size_t> wspolrzedneX;
	std::vector<size_t> wspolrzedneY;
	size_t wielkosc;
	char symbol;

	int przychod;
public:
	Prowincja(size_t, size_t, size_t, std::string, char);

	std::vector<size_t> dajWspolrzedneX() { return wspolrzedneX; }
	std::vector<size_t> dajWspolrzedneY() { return wspolrzedneY; }
	char dajSymbol() { return symbol;  }

	int przynaleznosc;
};
#endif

