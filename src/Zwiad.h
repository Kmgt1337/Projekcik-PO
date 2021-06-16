#ifndef ZWIAD_H
#define ZWIAD_H

#include "Oddzial.h"

/*!
klasa opisujaca zwiad, jeden z rodzajow oddzialow wojskowych. Obiekt tej klasy dodaje podczas bitwy modyfikator do liczebnosci 
na podstawie ilosci zdobytych prowincji przez armie

dziedziczenie publiczne po klasie abstrakcyjnej "Oddzial"
*/
class Zwiad : public Oddzial
{
public:
	//! konstruktor klasy przypisujacy zwiadowi przynaleznosc taka sama jak armii
	Zwiad(int);

	//! funkcja skladowa klasy, ktora zlicza liczbe zdobytych prowincji przez armie
	void raport();

	//! funkcja skladowa klasy zwracajaca modLiczebnosc
	virtual size_t dajModyfikator() { return modLiczebnosc; }

private:
	//! skladnik klasy przechowujacy modyfikator do liczebnosci armii podczas bitwy, jest on rowny ilosci zdobytych prowincji przez armie
	size_t modLiczebnosc;

	//! skladnik klasy przechowujacy przynaleznosc zwiadu
	int przynaleznosc;
};

#endif
