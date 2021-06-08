#ifndef ARTYLERIA_H
#define ARTYLERIA_H

#include "Oddzial.h"

// klasa opisuj�ca artyleri�, jeden z rodzaj�w oddzia��w wojskowych. Obiekt tej klasy dodaje podczas bitwy modyfikator do ofensywy
// dziedziczenie publiczne po klasie abstrakcyjnej "Oddzial"
class Artyleria : public Oddzial
{
public:
	// konstruktor klasy losuj�cy warto�� zmiennej modDefensywa
	Artyleria();

	// funkcja sk�adowa klasy zwracaj�ca modOfensywa
	virtual size_t dajModyfikator() { return modOfensywa; }

private:
	// sk�adnik klasy przechowuj�cy modyfikator do ofensywy armii podczas bitwy
	size_t modOfensywa;
};

#endif


