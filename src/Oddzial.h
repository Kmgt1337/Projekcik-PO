#ifndef ODDZIAL_H
#define ODDZIAL_H

// Klasa abstrakcyjna
class Oddzial
{
public:
	// funkcja czysto wirtualna, zwraca modyfikator z obiektu na kt�ry aktualnie jest ustawiony wska�nik do klasy abstrakcyjnej
	virtual size_t dajModyfikator() = 0;
};

#endif
