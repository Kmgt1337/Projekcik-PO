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

// UWAGA:
// przy wyborze maksymalnych wartoœci symulacja mo¿e trwaæ nawet kilkanaœcie minut oraz generowaæ
// plik tekstowy rozmiaru paru mb

// u¿ytkownik podaje z klawiatury nastêpuj¹ce dane pocz¹tkowe:
// - maksymalny limit tur
// - rozmiar mapy
// - parametry ka¿dej z armii: pozycja pocz¹tkowa x, pozycja pocz¹tkowa y, liczebnoœæ, nazwa
// - minimalnie s¹ 2 armie, u¿ytkownik mo¿e dodaæ ich maksymalnie 10

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
	ULONGLONG czasTrwaniaSymulacji{};

	// sk³adnik klasy przechowuj¹cy czas trwania przerwy podczas symulacji
	ULONGLONG czasTrwaniaPrzerwy{};

	// sk³adnik klasy - uchwyt na wyjœcie konsoli
	HANDLE hOut;

	// sk³adnik klasy przechowuj¹cy minimalny dozwolony rozmiar mapy
	const size_t minimum{ 10 };

	// sk³adniki klasy przechowuj¹ce maksymalne dozwolone rozmiary mapy
	const size_t maksimumX{ 40 };
	const size_t maksimumY{ 40 };
};

#endif

