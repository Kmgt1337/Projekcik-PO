#ifndef GENERAL_H
#define GENERAL_H

#include "Oddzial.h"

/*!
klasa opisujaca generala, jeden z rodzajow oddzialow wojskowych. Obiekt tej klasy dodaje podczas bitwy modyfikator do obrazen .
dziedziczenie publiczne po klasie abstrakcyjnej "Oddzial"
*/
class General : public Oddzial
{
public:
	//! konstruktor klasy losujacy wartosc zmiennej modObrazenia
	General();

	//! funkcja skladowa klasy zwracajaca modObrazenia
	virtual size_t dajModyfikator() { return modObrazenia; }

private:
	//! skladnik klasy przechowujacy modyfikator do obrazen armii podczas bitwy
	size_t modObrazenia;
};

#endif

