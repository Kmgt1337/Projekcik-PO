#ifndef ODDZIAL_H
#define ODDZIAL_H

//! Klasa abstrakcyjna
class Oddzial
{
public:
	//! funkcja czysto wirtualna, zwraca modyfikator z obiektu na ktory aktualnie jest ustawiony wskaznik do klasy abstrakcyjnej
	virtual size_t dajModyfikator() = 0;
};

#endif
