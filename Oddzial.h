#ifndef ODDZIAL_H
#define ODDZIAL_H

// Klasa abstrakcyjna
class Oddzial
{
public:
	// funkcja czysto wirtualna, zwraca modyfikator z obiektu na który aktualnie jest ustawiony wskaŸnik do klasy abstrakcyjnej
	virtual size_t dajModyfikator() = 0;
};

#endif
