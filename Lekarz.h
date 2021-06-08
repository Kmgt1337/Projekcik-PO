#ifndef LEKARZ_H
#define LEKARZ_H

#include "Oddzial.h"

// klasa opisuj¹ca lekarzy, jeden z rodzajów oddzia³ów wojskowych. Obiekt tej klasy dodaje podczas bitwy modyfikator do liczebnosci armii
// dziedziczenie publiczne po klasie abstrakcyjnej "Oddzial"
class Lekarz : public Oddzial
{
public:
	// konstruktor klasy losuj¹cy wartoœæ zmiennej modLiczebnosc
	Lekarz();

	// funkcja sk³adowa klasy zwracaj¹ca modLiczebnosc
	virtual size_t dajModyfikator() { return modLiczebnosc; }

private:
	// sk³adnik klasy przechowuj¹cy modyfikator do liczebnoœci armii podczas bitwy
	size_t modLiczebnosc;
};

#endif

