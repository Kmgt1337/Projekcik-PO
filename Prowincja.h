#ifndef PROWINCJA_H
#define PROWINCJA_H

#include <string>
#include "Armia.h"

// klasa odopowiadająca za prowincje
class Prowincja
{
public:
	// konstruktor klasy ustawiający początkowe wartości opisujące prowincje
	Prowincja()
	{
		przynaleznosc = 0;
		symbol = ' ';
		armia_w_prowincji = 0;
	}

	// składnik klasy oznaczający do jakiej armii należy dana prowincja
	int przynaleznosc{};

	// składnik klasy przechowujący symbol wyświetlany na ekranie konsoli
	char symbol{};

	// TODO
	int armia_w_prowincji{};
};

#endif

