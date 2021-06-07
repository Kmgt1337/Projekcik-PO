#ifndef OPERATORSYMULACJI_H
#define OPERATORSYMULACJI_H

#include "Armia.h"
#include "Zegar.h"
#include "Mapa.h"
#include "Operator_bitwy.h"
#include "OperatorZakonczenia.h"
#include "OperatorPliku.h"

#include <vector>
#include <conio.h>

// klasa odpowiadaj�ca za przeprowadzenie symulacji
class OperatorSymulacji
{
public:
	// funkcja sk�adowa klasy inicjalizuj�ca symulacj� wst�pnymi parametrami, w niej u�ytkownik wpisuje pocz�tkowe warto�ci
	bool zainicjalizujSymulacje();

	// funkcja sk�adowa klasy, w kt�rej znajduje si� g��wna p�tla symulacji
	int prowadzSymulacje();

private:
	// sk�adnik klasy przechowuj�cy stan symulacji
	bool czySymulacjaJestAktywna;

	// sk�adnik klasy - tablica przechowuj�ca armie
	std::vector<Armia> armie;

	// sk�adnik klasy - tablica przechowuj�ca zmiany liczebno�ci armii po bitwie
	std::vector<size_t> zmianaLiczebnosci;

	// sk�adnik klasy - obiekt do kt�rego zostaje wpisana armia, kt�ra wygra�a (w przypadku zwyci�stwa militarnego)
	Armia armiaZwycieska;
	
	// sk�adnik klasy przechowuj�cy czas trwania symulacji
	DWORD czasTrwaniaSymulacji;

	// sk�adnik klasy przechowuj�cy czas trwania przerwy podczas symulacji
	DWORD czasTrwaniaPrzerwy;

	// sk�adnik klasy - uchwyt na wyj�cie konsoli
	HANDLE hOut;

	// sk�adnik klasy przechowuj�cy minimalny dozwolony rozmiar mapy
	const size_t minimum = 10;

	// sk�adniki klasy przechowuj�ce maksymalne dozwolone rozmiary mapy
	const size_t maksimumX = 40;
	const size_t maksimumY = 40;
};

#endif

