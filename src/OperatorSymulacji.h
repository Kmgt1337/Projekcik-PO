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

/*!
uzytkownik podaje z klawiatury nastepujace dane poczatkowe:
- maksymalny limit tur
- rozmiar mapy
- parametry kazdej z armii: pozycja poczatkowa x, pozycja poczatkowa y, liczebnosc, nazwa
- minimalnie sa 2 armie, uzytkownik moze dodac ich maksymalnie 10

klasa odpowiadajaca za przeprowadzenie symulacji
*/
class OperatorSymulacji
{
public:
	//! funkcja skladowa klasy inicjalizujaca symulacje wstepnymi parametrami, w niej uzytkownik wpisuje poczatkowe wartosci
	bool zainicjalizujSymulacje();

	//! funkcja skladowa klasy, w ktorej znajduje sie glowna petla symulacji
	int prowadzSymulacje();

private:
	//! skladnik klasy przechowujacy stan symulacji
	bool czySymulacjaJestAktywna;

	//! skladnik klasy - tablica przechowujaca armie
	std::vector<Armia> armie;

	//! skladnik klasy - tablica przechowujaca zmiany liczebnosci armii po bitwie
	std::vector<size_t> zmianaLiczebnosci;

	//! skladnik klasy - obiekt do ktorego zostaje wpisana armia, ktora wygrala (w przypadku zwyciestwa militarnego)
	Armia armiaZwycieska;
	
	//! skladnik klasy przechowujacy czas trwania symulacji
	ULONGLONG czasTrwaniaSymulacji{};

	//! skladnik klasy przechowujacy czas trwania przerwy podczas symulacji
	ULONGLONG czasTrwaniaPrzerwy{};

	//! skladnik klasy - uchwyt na wyjscie konsoli
	HANDLE hOut;

	//! skladnik klasy przechowujacy minimalny dozwolony rozmiar mapy
	const size_t minimum{ 10 };

	//! skladnik klasy przechowujacy maksymalne dozwolone rozmiary mapy x
	const size_t maksimumX{ 40 };

	//! skladnik klasy przechowujacy maksymalne dozwolone rozmiary mapy y
	const size_t maksimumY{ 40 };
};

#endif

