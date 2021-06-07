#ifndef PROWINCJA_H
#define PROWINCJA_H

#include <string>
#include "Armia.h"

// klasa odopowiadaj�ca za prowincje
class Prowincja
{
public:
	// konstruktor klasy ustawiaj�cy pocz�tkowe warto�ci opisuj�ce prowincje
	Prowincja()
	{
		przynaleznosc = 0;
		symbol = ' ';
		armia_w_prowincji = 0;
	}

	// sk�adnik klasy oznaczaj�cy do jakiej armii nale�y dana prowincja
	int przynaleznosc{};

	// sk�adnik klasy przechowuj�cy symbol wy�wietlany na ekranie konsoli
	char symbol{};

	// TODO
	int armia_w_prowincji{};
};

#endif

