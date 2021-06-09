#ifndef LEKARZ_H
#define LEKARZ_H

#include "Oddzial.h"

// klasa opisuj�ca lekarzy, jeden z rodzaj�w oddzia��w wojskowych. Obiekt tej klasy dodaje podczas bitwy modyfikator do liczebnosci armii
// dziedziczenie publiczne po klasie abstrakcyjnej "Oddzial"
class Lekarz : public Oddzial
{
public:
	// konstruktor klasy losuj�cy warto�� zmiennej modLiczebnosc
	Lekarz();

	// funkcja sk�adowa klasy zwracaj�ca modLiczebnosc
	virtual size_t dajModyfikator() { return modLiczebnosc; }

private:
	// sk�adnik klasy przechowuj�cy modyfikator do liczebno�ci armii podczas bitwy
	size_t modLiczebnosc;
};

#endif

