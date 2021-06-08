#ifndef PROWINCJA_H
#define PROWINCJA_H

#include <string>
#include "Armia.h"
#include "Zasob.h"

// klasa odopowiadaj�ca za prowincje
class Prowincja
{
public:
	// konstruktor klasy ustawiaj�cy pocz�tkowe warto�ci opisuj�ce prowincje
	Prowincja();

	// funkcje sk�adowe klasy zwracaj�ce dane sk�adniki klasy
	int dajPrzynaleznosc() { return przynaleznosc; }
	char dajSymbol() { return symbol; }
	int dajArmieWProwincji() { return armia_w_prowincji; }

	// funkcje sk�adowe klasy zmieniaj�ce dany sk�adnik klasy
	void zmienPrzynaleznosc(int a) { przynaleznosc = a; }
	void zmienSymbol(char a) { symbol = a; }
	void zmienArmieWProwincji(int a) { armia_w_prowincji = a; }

	// sk�adnik klasy - zas�b kt�ry posiada prowincja
	Zasob zasobProwincji;

private:
	// sk�adnik klasy oznaczaj�cy do jakiej armii nale�y dana prowincja
	int przynaleznosc{};

	// sk�adnik klasy przechowuj�cy symbol wy�wietlany na ekranie konsoli
	char symbol{};

	// TODO
	int armia_w_prowincji{};
};

#endif

