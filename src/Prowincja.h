#ifndef PROWINCJA_H
#define PROWINCJA_H

#include <string>
#include "Armia.h"
#include "Zasob.h"

//! klasa odopowiadajaca za prowincje
class Prowincja
{
public:
	//! konstruktor klasy ustawiajacy poczatkowe wartosci opisujace prowincje
	Prowincja();

	//! funkcja skladowa klasy zwracajaca przynaleznsoc prowincji
	int dajPrzynaleznosc() { return przynaleznosc; }

	//! funkcja skladowa klasy zwracajaca symbol prowincji
	char dajSymbol() { return symbol; }

	//! funkcja skladowa klasy zwracajaca armie w prowincji
	int dajArmieWProwincji() { return armia_w_prowincji; }

	//! funkcja skladowa klasy zwracajaca wspolrzedna x prowincji
	int dajwspolrzednax() { return wspolrzednax; }

	//! funkcja skladowa klasy zwracajaca wspolrzedna y prowincji
	int dajwspolrzednay() { return wspolrzednay; }

	//! funkcja skladowa klasy zmieniajaca przynaleznosc
	void zmienPrzynaleznosc(int a) { przynaleznosc = a; }

	//! funkcja skladowa klasy zmieniajaca symbol
	void zmienSymbol(char a) { symbol = a; }

	//! funkcja skladowa klasy zmieniajaca armie w prowincji
	void zmienArmieWProwincji(int a) { armia_w_prowincji = a; }

	//! funkcja skladowa klasy zmieniajaca wspolrzedna x prowincji
	void zmienwspolrzednax(int a) { wspolrzednax = a; }

	//! funkcja skladowa klasy zmieniajaca wspolrzedna y prowincji
	void zmienwspolrzednay(int a) { wspolrzednay = a; }

	//! skladnik klasy - zasob ktory posiada prowincja
	Zasob zasobProwincji;

private:
	//! skladnik klasy oznaczajacy do jakiej armii nalezy dana prowincja
	int przynaleznosc{};

	//! skladnik klasy przechowujacy symbol wyswietlany na ekranie konsoli
	char symbol{};

	//! skladnik klasy przechowujacy wspolrzedna x prowincji
	int wspolrzednax;

	//! skladnik klasy przechowujacy wspolrzedna y prowincji
	int wspolrzednay;

	//! skladnik klasy przechowujacy id armii w prowincji
	int armia_w_prowincji{};
};

#endif
