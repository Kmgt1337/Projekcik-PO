#ifndef ZWIAD_H
#define ZWIAD_H

#include "Oddzial.h"

// klasa opisuj¹ca zwiad, jeden z rodzajów oddzia³ów wojskowych. Obiekt tej klasy dodaje podczas bitwy modyfikator do liczebnoœci 
// na podstawie iloœci zdobytych prowincji przez armiê

// dziedziczenie publiczne po klasie abstrakcyjnej "Oddzial"
class Zwiad : public Oddzial
{
public:
	// konstruktor klasy przypisuj¹cy zwiadowi przypisuj¹cy zwiadowi przynale¿noœæ tak¹ sam¹ jak armii
	Zwiad(int);

	// funkcja s³adowa klasy, która zlicza liczbê zdobytych prowincji przez armiê
	void raport();

	// funkcja s³adowa klasy zwracaj¹ca modLiczebnosc
	virtual size_t dajModyfikator() { return modLiczebnosc; }

private:
	// sk³adnik klasy przechowuj¹cy modyfikator do liczebnoœci armii podczas bitwy, jest on równy iloœci zdobytych prowincji przez armiê
	size_t modLiczebnosc;

	// sk³adnik klasy przechowuj¹cy przynale¿noœæ zwiadu
	int przynaleznosc;
};

#endif
