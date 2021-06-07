#ifndef ZEGAR_H
#define ZEGAR_H

#include "Armia.h"
#include <Windows.h>
#include <ctime>

// klasa odpowiedzialna za mierzenie up³ywu czasu i tur
class Zegar
{
public:
	// statyczna funkcja sk³adowa klasy ustawiaj¹ca turê na 0
	static void start();

	// statyczna funkcja sk³adowa klasy zwiêkszaj¹ca turê o 1
	static void nowaTura();

	// statyczna funkcja sk³adowa klasy zwracaj¹ca liczbê tur
	static size_t dajObecnaTure();

	// statyczna funkcja sk³adowa klasy zaczynaj¹ca mierzyæ czas rzeczywisty
	static void zacznijOdmierzacCzas();

	// statyczna funkcja sk³adowa klasy, która zwraca czas pomiêdzy jej wywo³aniem a wywo³aniem funkcji zacznijOdmierzacCzas()
	static DWORD dajCzasWykonaniaSymulacjiMiliSekundy();

private:
	// statyczny sk³adnik klasy przechowuj¹cy liczbê tur
	static size_t tura;

	// statyczne sk³adniki klasy przechowuj¹ce czas startu symulacji i czas jej zakoñczenia
	static DWORD czasStartu, czasKonca;
};

#endif
