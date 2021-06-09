#ifndef ARTYLERIA_H
#define ARTYLERIA_H

#include "Oddzial.h"

// klasa opisuj¹ca artyleriê, jeden z rodzajów oddzia³ów wojskowych. Obiekt tej klasy dodaje podczas bitwy modyfikator do ofensywy
// dziedziczenie publiczne po klasie abstrakcyjnej "Oddzial"
class Artyleria : public Oddzial
{
public:
	// konstruktor klasy losuj¹cy wartoœæ zmiennej modDefensywa
	Artyleria();

	// funkcja sk³adowa klasy zwracaj¹ca modOfensywa
	virtual size_t dajModyfikator() { return modOfensywa; }

private:
	// sk³adnik klasy przechowuj¹cy modyfikator do ofensywy armii podczas bitwy
	size_t modOfensywa;
};

#endif


