#ifndef GENERAL_H
#define GENERAL_H

#include "Oddzial.h"

// klasa opisuj�ca lekk� jazd�, jeden z rodzaj�w oddzia��w wojskowych. Obiekt tej klasy dodaje podczas bitwy modyfikator do defensywy
// dziedziczenie publiczne po klasie abstrakcyjnej "Oddzial"
class General : public Oddzial
{
public:
	// konstruktor klasy losuj�cy warto�� zmiennej modObrazenia
	General();

	// funkcja sk�adowa klasy zwrracaj�ca modObrazenia
	virtual size_t dajModyfikator() { return modObrazenia; }

private:
	// sk�adnik klasy przechowuj�cy modyfikator do obra�e� armii podczas bitwy
	size_t modObrazenia;
};

#endif

