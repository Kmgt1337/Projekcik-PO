#ifndef LEKKAJAZDA_H
#define LEKKAJAZDA_H

#include "Oddzial.h"

// klasa opisuj¹ca lekk¹ jazdê, jeden z rodzajów oddzia³ów wojskowych. Obiekt tej klasy dodaje podczas bitwy modyfikator do defensywy
// dziedziczenie publiczne po klasie abstrakcyjnej "Oddzial"
class LekkaJazda : public Oddzial
{
public:
	// konstruktor klasy losuj¹cy wartoœæ zmiennej modDefensywa
	LekkaJazda();

	// funkcja sk³adowa klasy zwracaj¹ca modDefensywa
	virtual size_t dajModyfikator() { return modDefensywa; }

private:
	// sk³adnik klasy przechowuj¹cy modyfikator do defensywy armii podczas bitwy
	size_t modDefensywa;
};

#endif

