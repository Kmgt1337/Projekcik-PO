#ifndef LEKKAJAZDA_H
#define LEKKAJAZDA_H

#include "Oddzial.h"

/*!
klasa opisujaca lekka jazde, jeden z rodzajow oddzialow wojskowych. Obiekt tej klasy dodaje podczas bitwy modyfikator do defensywy.
dziedziczenie publiczne po klasie abstrakcyjnej "Oddzial"
*/
class LekkaJazda : public Oddzial
{
public:
	//! konstruktor klasy losujacy wartosc zmiennej modDefensywa
	LekkaJazda();

	//! funkcja skladowa klasy zwracajaca modDefensywa
	virtual size_t dajModyfikator() { return modDefensywa; }

private:
	//! skladnik klasy przechowujacy modyfikator do defensywy armii podczas bitwy
	size_t modDefensywa;
};

#endif

