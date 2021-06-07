#ifndef ZEGAR_H
#define ZEGAR_H

#include "Armia.h"
#include <Windows.h>
#include <ctime>

// klasa odpowiedzialna za mierzenie up�ywu czasu i tur
class Zegar
{
public:
	// statyczna funkcja sk�adowa klasy ustawiaj�ca tur� na 0
	static void start();

	// statyczna funkcja sk�adowa klasy zwi�kszaj�ca tur� o 1
	static void nowaTura();

	// statyczna funkcja sk�adowa klasy zwracaj�ca liczb� tur
	static size_t dajObecnaTure();

	// statyczna funkcja sk�adowa klasy zaczynaj�ca mierzy� czas rzeczywisty
	static void zacznijOdmierzacCzas();

	// statyczna funkcja sk�adowa klasy, kt�ra zwraca czas pomi�dzy jej wywo�aniem a wywo�aniem funkcji zacznijOdmierzacCzas()
	static DWORD dajCzasWykonaniaSymulacjiMiliSekundy();

private:
	// statyczny sk�adnik klasy przechowuj�cy liczb� tur
	static size_t tura;

	// statyczne sk�adniki klasy przechowuj�ce czas startu symulacji i czas jej zako�czenia
	static DWORD czasStartu, czasKonca;
};

#endif
