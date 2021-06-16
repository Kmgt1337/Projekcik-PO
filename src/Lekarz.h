#ifndef LEKARZ_H
#define LEKARZ_H

#include "Oddzial.h"

/*! 
klasa opisujaca lekarzy, jeden z rodzajow oddzialow wojskowych. Obiekt tej klasy dodaje podczas bitwy modyfikator do liczebnosci armii.
dziedziczenie publiczne po klasie abstrakcyjnej "Oddzial"
*/
class Lekarz : public Oddzial
{
public:
	//! konstruktor klasy losujacy wartosc zmiennej modLiczebnosc
	Lekarz();

	//! funkcja skladowa klasy zwracajaca modLiczebnosc
	virtual size_t dajModyfikator() { return modLiczebnosc; }

private:
	//! skladnik klasy przechowujacy modyfikator do liczebnosci armii podczas bitwy
	size_t modLiczebnosc;
};

#endif

