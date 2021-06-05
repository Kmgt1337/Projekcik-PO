#ifndef PROWINCJA_H
#define PROWINCJA_H

#include <string>
#include "Armia.h"

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
	int armia_w_prowincji;
	Prowincja()
	{
		przynaleznosc = 0;
		symbol = ' ';
		armia_w_prowincji = 0;
	}
};
#endif

