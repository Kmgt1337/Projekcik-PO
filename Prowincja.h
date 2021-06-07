#ifndef PROWINCJA_H
#define PROWINCJA_H

#include <string>
#include "Armia.h"

// klasa odopowiadaj¹ca za prowincje
class Prowincja
{
public:
	// konstruktor klasy ustawiaj¹cy pocz¹tkowe wartoœci opisuj¹ce prowincje
	Prowincja()
	{
		przynaleznosc = 0;
		symbol = ' ';
		armia_w_prowincji = 0;
	}

	// sk³adnik klasy oznaczaj¹cy do jakiej armii nale¿y dana prowincja
	int przynaleznosc{};

	// sk³adnik klasy przechowuj¹cy symbol wyœwietlany na ekranie konsoli
	char symbol{};

	// TODO
	int armia_w_prowincji{};
};

#endif

