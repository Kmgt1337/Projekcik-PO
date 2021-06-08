#ifndef CIEZKAJAZDA_H
#define CIEZKAJAZDA_H

#include "Oddzial.h"

// klasa opisuj�ca ci�k� jazd�, jeden z rodzaj�w oddzia��w wojskowych. Obiekt tej klasy dodaje podczas bitwy modyfikator do ofensywy
// dziedziczenie publiczne po klasie abstrakcyjnej "Oddzial"
class CiezkaJazda : public Oddzial
{
public:
	// konstruktor klasy losuj�cy warto�� zmiennej modObrazenia
	CiezkaJazda();

	// funkcja sk�adowa klasy zwrracaj�ca modObrazenia
	virtual size_t dajModyfikator() {return modObrazenia; }

private:
	// sk�adnik klasy przechowuj�cy modyfikator do obra�e� armii podczas bitwy
	size_t modObrazenia;
};

#endif

