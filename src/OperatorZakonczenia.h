#ifndef OPERATORZAKONCZENIA_H
#define OPERATORZAKONCZENIA_H

#include "Armia.h"
#include "Zegar.h"
#include <vector>

/*!
istnieja dwa mozliwe zakonczenia symulacji:
1. zwyciestwo militarne - w przypadku gdy na polu walki zostanie tylko jedna armia - wygrywa ona symulacje
2. zakonczenie przez osiagniecie limtu tur - w przypadku gdy w symulacji zostanie osiagniety ustalony limit tur a co najmniej dwie armie
zyja - wygrywa armia, ktora przejela wiecej prowincji

klasa odpowiadajaca za sprawdzenie czy wystapily warunki zakonczenia symulacji
*/
class OperatorZakonczenia
{
public:
	//! statyczna funkcja skladowa klasy ustawiajaca maksymalny limit tur
	static void ustawMaksymalnyLimitTur(size_t);

	//! statyczna funkcja skladowa klasy sprawdzajaca czy symulacja zakonczyla sie zwyciestwem militarnym ktorejs z armii
	static bool sprawdzCzySymulacjaSieZakonczylaArmie(const std::vector<Armia>&);

	//! statyczna funkcja skladowa klasy sprawdzajaca czy symulacja zakonczyla sie przez osiagniecie limitu tur
	static bool sprawdzCzySymulacjaSieZakonczylaTury();

	//! statyczna funkcja skladowa klasy zliczajaca ile kazda armia posiada przejetych prowincji
	static std::vector<size_t> podajLiczbeProwincjiArmii(const std::vector<Armia>&);

	//! statyczna funkcja skladowa klasy wyznaczajaca wygrana armie
	static Armia pokazArmieZwycieska(const std::vector<Armia>&);

	//! statyczna funkcja skladowa klasy zwracajaca maksymalna liczbe tur
	static size_t dajMaxTure();

private:
	//! skladnik klasy przechowujacy maksymalna liczbe tur
	static size_t maxTura;
};

#endif

