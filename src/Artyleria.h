#ifndef ARTYLERIA_H
#define ARTYLERIA_H

#include "Oddzial.h"

/*! 
klasa opisujaca artylerie, jeden z rodzajow oddzialow wojskowych. Obiekt tej klasy dodaje podczas bitwy modyfikator do ofensywy.
dziedziczenie publiczne po klasie abstrakcyjnej "Oddzial"
 */
class Artyleria : public Oddzial
{
public:
	//! konstruktor klasy losujacy wartosc zmiennej modDefensywa
	Artyleria();

	//! funkcja skladowa klasy zwracajaca modOfensywa
	virtual size_t dajModyfikator() { return modOfensywa; }

private:
	//! skladnik klasy przechowujacy modyfikator do ofensywy armii podczas bitwy
	size_t modOfensywa;
};

#endif


