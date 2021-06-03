#ifndef PROWINCJA_H
#define PROWINCJA_H

#include <string>

class Prowincja
{
private:
	std::string nazwa;
	int wspolrzedne;
	int wielkosc;
	int przychod;
public:
	int przynaleznosc;
	char symbol;
	Prowincja()
	{
		przynaleznosc = 0;
		symbol = ' ';
	}
};
#endif

