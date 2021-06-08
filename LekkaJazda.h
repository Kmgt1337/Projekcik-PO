#ifndef LEKKAJAZDA_H
#define LEKKAJAZDA_H

#include "Oddzial.h"

// klasa opisuj�ca lekk� jazd�, jeden z rodzaj�w oddzia��w wojskowych. Obiekt tej klasy dodaje podczas bitwy modyfikator do defensywy
// dziedziczenie publiczne po klasie abstrakcyjnej "Oddzial"
class LekkaJazda : public Oddzial
{
public:
	// konstruktor klasy losuj�cy warto�� zmiennej modDefensywa
	LekkaJazda();

	// funkcja sk�adowa klasy zwracaj�ca modDefensywa
	virtual size_t dajModyfikator() { return modDefensywa; }

private:
	// sk�adnik klasy przechowuj�cy modyfikator do defensywy armii podczas bitwy
	size_t modDefensywa;
};

#endif

