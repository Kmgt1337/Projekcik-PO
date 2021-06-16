#ifndef ARMIA_H
#define ARMIA_H

#include <string>
#include <vector>

#include "Zasob.h"
#include "General.h"
#include "Artyleria.h"
#include "Oddzial.h"
#include "Lekarz.h"
#include "Zwiad.h"
#include "CiezkaJazda.h"
#include "LekkaJazda.h"

//! klasa opisujaca armie - glowny obiekt w symulacji
class Armia
{
public:
	//! konstruktor ustawiajacy poczatkowe parametry armii 
	Armia(int, size_t, size_t, char, int, std::string, size_t);

	//! konstruktor domyslny
	Armia();

	//! funkcja skladowa klasy przeprowadzajaca ruch armii, sprawdzajaca tez czy armia weszla na prowincje gdzie jest inna armia
	int ruch();

	//! funkcja skladowa klasy zwracajaca pozycje X
	size_t dajPozycjeX() { return pozycjaX; }

	//! funkcja skladowa klasy zwracajaca pozycje Y
	size_t dajPozycjeY() { return pozycjaY; }

	//! funkcja skladowa klasy zwracajaca przynaleznosc armii
	int dajPrzyna() { return przynaleznosc; }

	//! funkcja skladowa klasy zwracajaca symbol armii
	char dajSymbol() { return symbol; }

	//! funkcja skladowa klasy zwracajaca nazwe armii
	std::string dajNazwe() { return nazwaArmii; }

	//! funkcja skladowa klasy zwracajaca modyfikator do obrazen z zebranych zasobow
	float dajModyfikatorZasob() { return modyfikatorObrazenZasob; }

	//! funkcja skladowa klasy zwracajaca czy armia jest aktywna
	bool czyArmiaAktywna() { return aktywna; }

	//! funkcja skladowa klasy zwracajaca liczebnosc armii
	int dajLiczebnosc() { return liczebnosc; }

	//! funkcja skladowa klasy zwracajaca ID armii
	int dajID() { return id; }

	//! funkcja skladowa klasy zmieniajaca liczebnosc armii
	void zmienLiczebnosc(int a) { liczebnosc = a; }

	//! funkcja skladowa klasy zmieniajaca symbol armii
	void zmienSymbol(char a) { symbol = a; }

	//! funkcja skladowa klasy zmieniajaca aktywnosc armii
	void zmienAktywnosc(bool a) { aktywna = a; }

	//! funkcja skladowa klasy odpowiedzialna za zbieranie zasobu z prowincji
	void zbierzZasob(rodzajeZasobu);

	//! statyczna funkcja skladowa klasy inicjalizujaca granice mapy (potrzebne do tego aby armia nie wyszla poza mape)
	static void inicjalizuj(size_t, size_t);

	//! skladnik klasy - wskaznik na klase abstrakcyjna Oddzial
	Oddzial* oddzial;

	//! skladnik klasy - artyleria
	Artyleria artyleria;

	//! skladnik klasy - general
	General general;

	//! skladnik klasy - lekarz
	Lekarz lekarz;

	//! skladnik klasy - zwiad
	Zwiad zwiad{ dajPrzyna() };

	//! skladnik klasy - ciezka jazda
	CiezkaJazda ciezkaJazda;

	//! skladnik klasy - lekka jazda
	LekkaJazda lekkaJazda;

private:
	//! skladnik klasy okreslajacy czy armia jest aktywna 
	bool aktywna;

	//! skladnik klasy okreslajacy symbol armii, ktory zostanie wypisany na ekran konsoli na mapie
	char symbol;

	//! skladnik klasy okreslajacy ID armii
	int id;

	//! skladnik klasy okreslajacy liczbe zolnierzy w armii
	int liczebnosc;

	//! skladnik klasy okreslajacy przynaleznosc danej armii
	int przynaleznosc;

	//! skladnik klasy okreslajacy pozycje x armii na mapie
	size_t pozycjaX;

	//! skladnik klasy okreslajacy pozycje y armii na mapie
	size_t pozycjaY;

	//! skladnik klasy okreslajacy szybkosc poruszania sie armii
	float szybkosc;

	//! skladnik klasy okreslajacy nazwe armii
	std::string nazwaArmii;

	//! statyczny skladnik klasy okreslajacy granice x mapy (potrzebne do tego aby armia nie wyszla poza mape)
	static size_t x;

	//! statyczny skladnik klasy okreslajacy granice y mapy (potrzebne do tego aby armia nie wyszla poza mape)
	static size_t y;

	//! skladnik klasy okreslajacy o ile procent armia ma zwiekszone zadane obrazenia, np. 1.1 oznacza obraaenia wieksze o 10%
	float modyfikatorObrazenZasob{ 1.0 };
};

#endif
