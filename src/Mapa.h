#ifndef MAPA_H
#define MAPA_H

#include "Armia.h"
#include "Prowincja.h"
#include <vector>
#include <iostream>
#include <Windows.h>
#include <random>

/*!
Mapa wyglada w nastepujacy sposob:
1. kazde pole na mapie to unikalna prowincja, kolor szary oznacza ze prowincja jest niczyja, jesli prowincja ma kolor inny niz szary - jest ona przejeta przez dana armie
2. armie reprezentowane sa przez znaki 'X', armie poruszaja sie po mapie w sposob calkowicie losowy przy okazji zajmujac prowincje 
3. kaada prowincja zawiera jakis zasob, najczesciej jest to zasob "BRAK" czyli zasob nie dajacy zadnych korzysci. Okolo 10% prowincji posiada wartosciowy zasob

klasa odpowiadajaca za mape i jej rysowanie na ekranie konsoli
*/
class Mapa
{
public:
	//! statyczny skladnik klasy - tablica dwuwymiarowa prowincji, kazde pole w tej tablicy to unikalna prowincja
	static  std::vector<std::vector<Prowincja>> mapa;

	//! statyczny skladnik klasy przechowujacy wielkosc y mapy
	static  size_t dlug;

	//! statyczny skladnik klasy przechowujacy wielkosc x mapy
	static  size_t szer;

	//! statyczna funkcja skladowa klasy zwracajaca liczbe prowincji przejetych dla dwoch armii
	static std::vector<size_t> dajLiczbeProwincjiKazdejArmii(Armia, Armia);

	//! statyczna funkcja skladowa klasy zwracajaca liczbe prowincji jednej armii
	static size_t dajLiczbeProwincjiArmii(Armia);

	//! statyczna funkcja skladowa klasy odpowiedzialna za wyswietlenie prowincji oraz armii w konsoli
	static void rysuj(const std::vector<Armia>& armie, HANDLE hOut);

	//! statyczna funkcja skladowa klasy, ktora ustawia pozadany rozmiar tablicy dwywymiarowej
	static void inicjalizuj(size_t, size_t);

	//! statyczna funkcja skladowa klasy, ktora resetuje wszystkie prowincje w tablicy dwuwymiarowej
	static void reset();

	//! statyzcna funkcja skladowa klasy, ktora czysci ekran konsoli po kazdej turze
	static void clrscr();
};

#endif