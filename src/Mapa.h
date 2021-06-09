#ifndef MAPA_H
#define MAPA_H

#include "Armia.h"
#include "Prowincja.h"
#include <vector>
#include <iostream>
#include <Windows.h>
#include <random>

// Mapa wygl¹da w nastêpuj¹cy sposób:
// 1. ka¿de pole na mapie to unikalna prowincja, kolor szary oznacza ¿e prowincja jest niczyja, jeœli prowincja ma kolor inny ni¿ szary - jest ona przejêta przez dan¹ armiê
// 2. armie reprezentowane s¹ przez znaki 'X', armie poruszaj¹ siê po mapie w sposób ca³kowicie losowy przy okazji zajmuj¹c prowincje 
// 3. ka¿da prowincja zawiera jakiœ zasób, najczêœciej jest to zasób "BRAK" czyli zasób nie daj¹cy ¿adnych korzyœci. Oko³o 10% prowincji posiada wartoœciowy zasób

// klasa odpowiadaj¹ca za mapê i jej rysowanie na ekranie konsoli
class Mapa
{
public:
	// statyczny sk³adnik klasy - tablica dwuwymiarowa prowincji, ka¿de pole w tej tablicy to unikalna prowincja
	static  std::vector<std::vector<Prowincja>> mapa;

	// statyczny sk³adnik klasy przechowuj¹cy wielkoœæ y mapy
	static  size_t dlug;

	// statyczny sk³adnik klasy przechowuj¹cy wielkoœæ x mapy
	static  size_t szer;

	// statyczna funkcja sk³adowa klasy zwracaj¹ca liczbê prowincji przejêtych dla dwóch armii
	static std::vector<size_t> dajLiczbeProwincjiKazdejArmii(Armia, Armia);

	// statyczna funkcja sk³adowa klasy zwracaj¹ca liczbê prowincji jednej armii
	static size_t dajLiczbeProwincjiArmii(Armia);

	// statyczna funkcja sk³adowa klasy odpowiedzialna za wyœwietlenie prowincji oraz armii w konsoli
	static void rysuj(const std::vector<Armia>& armie, HANDLE hOut);

	// statyczna funkcja sk³adowa klasy, która ustawia po¿¹dany rozmiar tablicy dwywymiarowej
	static void inicjalizuj(size_t, size_t);

	// statyczna funkcja sk³adowa klasy, która resetuje wszystkie prowincje w tablicy dwuwymiarowej
	static void reset();

	// statyzcna funkcja sk³adowa klasy, która czyœci ekran konsoli po ka¿dej turze
	static void clrscr();
};

#endif