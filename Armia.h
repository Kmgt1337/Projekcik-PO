#ifndef ARMIA_H
#define ARMIA_H

#include <string>
#include <vector>

#include "General.h"
#include "Artyleria.h"
#include "Oddzial.h"
#include "Lekarz.h"
#include "Zwiad.h"
#include "CiezkaJazda.h"
#include "LekkaJazda.h"

// klasa opisuj¹ca armiê - g³ówny obiekt w symulacji
class Armia
{
public:
	// konstruktor ustawiaj¹cy pocz¹tkowe parametry armii 
	Armia(int, size_t, size_t, char, int, std::string, size_t);

	// konstruktor domyœlny
	Armia();

	// funkcja sk³adowa klasy przeprowadzaj¹ca ruch armii, sprawdzaj¹ca te¿ czy armia wesz³a na prowincje gdzie jest inna armia
	int ruch();
	
	// sk³adnik klasy okreœlaj¹cy czy armia jest aktywna 
	bool aktywna;

	// sk³adnik klasy okreœlaj¹cy symbol armii, który zostanie wypisany na ekran konsoli na mapie
	char symbol;
	
	// sk³adnik klasy okreœlaj¹cy ID armii
	int id;

	// sk³adnik klasy okreœlaj¹cy liczbê ¿o³nierzy w armii
	int liczebnosc;

	// funkcje sk³adowek lasy zwracaj¹ce dane parametry
	size_t dajPozycjeX() { return pozycjaY; }
	size_t dajPozycjeY() { return pozycjaX; }
	int dajPrzyna() { return przynaleznosc; }
	char dajSymbol() { return symbol; }
	std::string dajNazwe() { return nazwaArmii; }
	int dajLiczebnosc() { return liczebnosc; }

	// statyczna funkcja sk³adowa klasy inicjalizuj¹ca granicê mapy (potrzebne do tegy aby armia nie wysz³a poza mapê)
	static void inicjalizuj(size_t, size_t);

	// sk³adniki klasy - obiekty opisuj¹ce armiê, oddzia³y wchodz¹ce w jej sk³ad. Ka¿dy oddzia³ dodaje swój modyfikator podczas bitwy
	Oddzial* oddzial;
	Artyleria artyleria;
	General general;
	Lekarz lekarz;
	Zwiad zwiad{ dajPrzyna() };
	CiezkaJazda ciezkaJazda;
	LekkaJazda lekkaJazda;

private:
	// sk³adnik klasy okreœlaj¹cy przynale¿nosæ danej armii
	int przynaleznosc;

	// sk³adniki klasy okreœlaj¹ce pozycjê armii na mapie
	size_t pozycjaX;
	size_t pozycjaY;

	// sk³adnik klasy okreœlaj¹cy szybkoœæ poruszania siê armii
	float szybkosc;

	// sk³adnik klasy okreœlaj¹cy nazwê armii
	std::string nazwaArmii;

	// statyczne sk³adniki klasy identyczne dla ka¿dej armii (potrzebne do tegy aby armia nie wysz³a poza mapê)
	static size_t x, y;
};

#endif
