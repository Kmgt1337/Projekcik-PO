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

// klasa odpowiadaj¹ca za przeprowadzenie symulacji
class OperatorSymulacji
{
public:
	// funkcja sk³adowa klasy inicjalizuj¹ca symulacjê wstêpnymi parametrami, w niej u¿ytkownik wpisuje pocz¹tkowe wartoœci
	bool zainicjalizujSymulacje();

	// funkcja sk³adowa klasy, w której znajduje siê g³ówna pêtla symulacji
	int prowadzSymulacje();

private:
	// sk³adnik klasy przechowuj¹cy stan symulacji
	bool czySymulacjaJestAktywna;

	// sk³adnik klasy - tablica przechowuj¹ca armie
	std::vector<Armia> armie;

	// sk³adnik klasy - tablica przechowuj¹ca zmiany liczebnoœci armii po bitwie
	std::vector<size_t> zmianaLiczebnosci;

	// sk³adnik klasy - obiekt do którego zostaje wpisana armia, która wygra³a (w przypadku zwyciêstwa militarnego)
	Armia armiaZwycieska;
	
	// sk³adnik klasy przechowuj¹cy czas trwania symulacji
	DWORD czasTrwaniaSymulacji;

	// sk³adnik klasy przechowuj¹cy czas trwania przerwy podczas symulacji
	DWORD czasTrwaniaPrzerwy;

	// sk³adnik klasy - uchwyt na wyjœcie konsoli
	HANDLE hOut;

	// sk³adnik klasy przechowuj¹cy minimalny dozwolony rozmiar mapy
	const size_t minimum = 10;

	// sk³adniki klasy przechowuj¹ce maksymalne dozwolone rozmiary mapy
	const size_t maksimumX = 40;
	const size_t maksimumY = 40;
};

#endif

