#ifndef ZWIAD_H
#define ZWIAD_H

#include "Oddzial.h"

// klasa opisuj�ca zwiad, jeden z rodzaj�w oddzia��w wojskowych. Obiekt tej klasy dodaje podczas bitwy modyfikator do liczebno�ci 
// na podstawie ilo�ci zdobytych prowincji przez armi�

// dziedziczenie publiczne po klasie abstrakcyjnej "Oddzial"
class Zwiad : public Oddzial
{
public:
	// konstruktor klasy przypisuj�cy zwiadowi przypisuj�cy zwiadowi przynale�no�� tak� sam� jak armii
	Zwiad(int);

	// funkcja s�adowa klasy, kt�ra zlicza liczb� zdobytych prowincji przez armi�
	void raport();

	// funkcja s�adowa klasy zwracaj�ca modLiczebnosc
	virtual size_t dajModyfikator() { return modLiczebnosc; }

private:
	// sk�adnik klasy przechowuj�cy modyfikator do liczebno�ci armii podczas bitwy, jest on r�wny ilo�ci zdobytych prowincji przez armi�
	size_t modLiczebnosc;

	// sk�adnik klasy przechowuj�cy przynale�no�� zwiadu
	int przynaleznosc;
};

#endif
