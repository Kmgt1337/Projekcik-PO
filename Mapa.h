#ifndef MAPA_H
#define MAPA_H

#include "Armia.h"
#include "Prowincja.h"
#include <vector>
#include <iostream>
#include <Windows.h>
#include <random>

// Mapa wygl�da w nast�puj�cy spos�b:
// 1. ka�de pole na mapie to unikalna prowincja, kolor szary oznacza �e prowincja jest niczyja, je�li prowincja ma kolor inny ni� szary - jest ona przej�ta przez dan� armi�
// 2. armie reprezentowane s� przez znaki 'X', armie poruszaj� si� po mapie w spos�b ca�kowicie losowy przy okazji zajmuj�c prowincje 
// 3. ka�da prowincja zawiera jaki� zas�b, najcz�ciej jest to zas�b "BRAK" czyli zas�b nie daj�cy �adnych korzy�ci. Oko�o 10% prowincji posiada warto�ciowy zas�b

// klasa odpowiadaj�ca za map� i jej rysowanie na ekranie konsoli
class Mapa
{
public:
	// statyczny sk�adnik klasy - tablica dwuwymiarowa prowincji, ka�de pole w tej tablicy to unikalna prowincja
	static  std::vector<std::vector<Prowincja>> mapa;

	// statyczny sk�adnik klasy przechowuj�cy wielko�� y mapy
	static  size_t dlug;

	// statyczny sk�adnik klasy przechowuj�cy wielko�� x mapy
	static  size_t szer;

	// statyczna funkcja sk�adowa klasy zwracaj�ca liczb� prowincji przej�tych dla dw�ch armii
	static std::vector<size_t> dajLiczbeProwincjiKazdejArmii(Armia, Armia);

	// statyczna funkcja sk�adowa klasy zwracaj�ca liczb� prowincji jednej armii
	static size_t dajLiczbeProwincjiArmii(Armia);

	// statyczna funkcja sk�adowa klasy odpowiedzialna za wy�wietlenie prowincji oraz armii w konsoli
	static void rysuj(const std::vector<Armia>& armie, HANDLE hOut);

	// statyczna funkcja sk�adowa klasy, kt�ra ustawia po��dany rozmiar tablicy dwywymiarowej
	static void inicjalizuj(size_t, size_t);

	// statyczna funkcja sk�adowa klasy, kt�ra resetuje wszystkie prowincje w tablicy dwuwymiarowej
	static void reset();

	// statyzcna funkcja sk�adowa klasy, kt�ra czy�ci ekran konsoli po ka�dej turze
	static void clrscr();
};

#endif