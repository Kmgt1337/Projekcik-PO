#ifndef PROWINCJA_H
#define PROWINCJA_H

#include <string>
#include "Armia.h"
#include "Zasob.h"

// klasa odopowiadaj¹ca za prowincje
class Prowincja
{
public:
	// konstruktor klasy ustawiaj¹cy pocz¹tkowe wartoœci opisuj¹ce prowincje
	Prowincja();

	// funkcje sk³adowe klasy zwracaj¹ce dane sk³adniki klasy
	int dajPrzynaleznosc() { return przynaleznosc; }
	char dajSymbol() { return symbol; }
	int dajArmieWProwincji() { return armia_w_prowincji; }

	// funkcje sk³adowe klasy zmieniaj¹ce dany sk³adnik klasy
	void zmienPrzynaleznosc(int a) { przynaleznosc = a; }
	void zmienSymbol(char a) { symbol = a; }
	void zmienArmieWProwincji(int a) { armia_w_prowincji = a; }

	// sk³adnik klasy - zasób który posiada prowincja
	Zasob zasobProwincji;

private:
	// sk³adnik klasy oznaczaj¹cy do jakiej armii nale¿y dana prowincja
	int przynaleznosc{};

	// sk³adnik klasy przechowuj¹cy symbol wyœwietlany na ekranie konsoli
	char symbol{};

	// TODO
	int armia_w_prowincji{};
};

#endif

