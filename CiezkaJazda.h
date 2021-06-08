#ifndef CIEZKAJAZDA_H
#define CIEZKAJAZDA_H

#include "Oddzial.h"

// klasa opisuj¹ca ciê¿k¹ jazdê, jeden z rodzajów oddzia³ów wojskowych. Obiekt tej klasy dodaje podczas bitwy modyfikator do ofensywy
// dziedziczenie publiczne po klasie abstrakcyjnej "Oddzial"
class CiezkaJazda : public Oddzial
{
public:
	// konstruktor klasy losuj¹cy wartoœæ zmiennej modObrazenia
	CiezkaJazda();

	// funkcja sk³adowa klasy zwrracaj¹ca modObrazenia
	virtual size_t dajModyfikator() {return modObrazenia; }

private:
	// sk³adnik klasy przechowuj¹cy modyfikator do obra¿eñ armii podczas bitwy
	size_t modObrazenia;
};

#endif

