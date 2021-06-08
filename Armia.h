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

// klasa opisuj�ca armi� - g��wny obiekt w symulacji
class Armia
{
public:
	// konstruktor ustawiaj�cy pocz�tkowe parametry armii 
	Armia(int, size_t, size_t, char, int, std::string, size_t);

	// konstruktor domy�lny
	Armia();

	// funkcja sk�adowa klasy przeprowadzaj�ca ruch armii, sprawdzaj�ca te� czy armia wesz�a na prowincje gdzie jest inna armia
	int ruch();

	// funkcje sk�adowe klasy zwracaj�ce dane parametry
	size_t dajPozycjeX() { return pozycjaX; }
	size_t dajPozycjeY() { return pozycjaY; }
	int dajPrzyna() { return przynaleznosc; }
	char dajSymbol() { return symbol; }
	std::string dajNazwe() { return nazwaArmii; }
	float dajModyfikatorZasob() { return modyfikatorObrazenZasob; }
	bool czyArmiaAktywna() { return aktywna; }
	int dajLiczebnosc() { return liczebnosc; }
	int dajID() { return id; }

	// funkcje sk�adowe klasy zmieniaj�ce dane parametry
	void zmienLiczebnosc(int a) { liczebnosc = a; }
	void zmienSymbol(char a) { symbol = a; }
	void zmienAktywnosc(bool a) { aktywna = a; }

	// funkcja sk�adowa klasy odpowiedzialna za zbieranie zasobu z prowincji
	void zbierzZasob(rodzajeZasobu);

	// statyczna funkcja sk�adowa klasy inicjalizuj�ca granic� mapy (potrzebne do tegy aby armia nie wysz�a poza map�)
	static void inicjalizuj(size_t, size_t);

	// sk�adniki klasy - obiekty opisuj�ce armi�, oddzia�y wchodz�ce w jej sk�ad. Ka�dy oddzia� dodaje sw�j modyfikator podczas bitwy
	Oddzial* oddzial;
	Artyleria artyleria;
	General general;
	Lekarz lekarz;
	Zwiad zwiad{ dajPrzyna() };
	CiezkaJazda ciezkaJazda;
	LekkaJazda lekkaJazda;

private:
	// sk�adnik klasy okre�laj�cy czy armia jest aktywna 
	bool aktywna;

	// sk�adnik klasy okre�laj�cy symbol armii, kt�ry zostanie wypisany na ekran konsoli na mapie
	char symbol;

	// sk�adnik klasy okre�laj�cy ID armii
	int id;

	// sk�adnik klasy okre�laj�cy liczb� �o�nierzy w armii
	int liczebnosc;

	// sk�adnik klasy okre�laj�cy przynale�nos� danej armii
	int przynaleznosc;

	// sk�adniki klasy okre�laj�ce pozycj� armii na mapie
	size_t pozycjaX;
	size_t pozycjaY;

	// sk�adnik klasy okre�laj�cy szybko�� poruszania si� armii
	float szybkosc;

	// sk�adnik klasy okre�laj�cy nazw� armii
	std::string nazwaArmii;

	// statyczne sk�adniki klasy identyczne dla ka�dej armii (potrzebne do tegy aby armia nie wysz�a poza map�)
	static size_t x, y;

	// sk�adnik klasy okre�laj�cy o ile procent armia ma zwi�kszone zadane obra�enia, np. 1.1 oznacza obra�enia wi�ksze o 10%
	float modyfikatorObrazenZasob{ 1.0 };
};

#endif
