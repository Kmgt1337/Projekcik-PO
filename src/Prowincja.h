#ifndef PROWINCJA_H
#define PROWINCJA_H

#include <string>
#include "Armia.h"
#include "Zasob.h"

// klasa odopowiadająca za prowincje
class Prowincja
{
public:
	// konstruktor klasy ustawiający początkowe wartości opisujące prowincje
	Prowincja();

	// funkcje składowe klasy zwracające dane składniki klasy
	int dajPrzynaleznosc() { return przynaleznosc; }
	char dajSymbol() { return symbol; }
	int dajArmieWProwincji() { return armia_w_prowincji; }
	int dajwspolrzednax() { return wspolrzednax; }
	int dajwspolrzednay() { return wspolrzednay; }

	// funkcje składowe klasy zmieniające dany składnik klasy
	void zmienPrzynaleznosc(int a) { przynaleznosc = a; }
	void zmienSymbol(char a) { symbol = a; }
	void zmienArmieWProwincji(int a) { armia_w_prowincji = a; }
	void zmienwspolrzednax(int a) { wspolrzednax = a; }
	void zmienwspolrzednay(int a) { wspolrzednay = a; }

	// składnik klasy - zasób który posiada prowincja
	Zasob zasobProwincji;

private:
	// składnik klasy oznaczający do jakiej armii należy dana prowincja
	int przynaleznosc{};

	// składnik klasy przechowujący symbol wyświetlany na ekranie konsoli
	char symbol{};

	int wspolrzednax;
	int wspolrzednay;

	// TODO
	int armia_w_prowincji{};
};

#endif
