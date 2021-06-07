#ifndef OPERATORZAKONCZENIA_H
#define OPERATORZAKONCZENIA_H

#include "Armia.h"
#include "Zegar.h"
#include <vector>

// klasa odpowiadaj�ca za sprawdzenie czy wyst�pi�y warunki zako�czenia symulacji
class OperatorZakonczenia
{
public:
	// statyczna funkcja sk�adowa klasy ustawiaj�ca maksymalny limit tur
	static void ustawMaksymalnyLimitTur(size_t);

	// statyczna funkcja sk�adowa klasy sprawdzaj�ca czy symulacja zako�czy�a si� zwyci�stwem militarnym kt�rej� z armii
	static bool sprawdzCzySymulacjaSieZakonczylaArmie(const std::vector<Armia>&);

	// statyczna funkcja sk�adowa klasy sprawdzaj�ca czy symulacji zako�czy�a si� przez osi�gni�cie limitu tur
	static bool sprawdzCzySymulacjaSieZakonczylaTury();

	// statyczna funkcja sk�adowa klasy zliczaj�ca ile ka�da armia posiada przej�tych prowincji
	static std::vector<size_t> podajLiczbeProwincjiArmii(const std::vector<Armia>&);

	// statyczna funkcja sk�adowa klasy wyznaczaj�ca wygran� armi�
	static Armia pokazArmieZwycieska(const std::vector<Armia>&);

	// statyczna funkcja sk�adowa klasy zwracaj�ca maksymaln� liczb� tur
	static size_t dajMaxTure();

private:
	// sk�adnik klasy przechowuj�cy maksymaln� liczb� tur
	static size_t maxTura;
};

#endif

