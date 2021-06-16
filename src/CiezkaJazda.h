#ifndef CIEZKAJAZDA_H
#define CIEZKAJAZDA_H

#include "Oddzial.h"

/*! 
klasa opisujaca ciezka jazde, jeden z rodzajow oddzialow wojskowych. Obiekt tej klasy dodaje podczas bitwy modyfikator do ofensywy
dziedziczenie publiczne po klasie abstrakcyjnej "Oddzial"
 */
class CiezkaJazda : public Oddzial
{
public:
	//! konstruktor klasy losujacy wartosc zmiennej modObrazenia
	CiezkaJazda();

	//! funkcja skladowa klasy zwracajaca modObrazenia
	virtual size_t dajModyfikator() {return modObrazenia; }

private:
	//! skladnik klasy przechowujacy modyfikator do obrazen armii podczas bitwy
	size_t modObrazenia;
};

#endif

