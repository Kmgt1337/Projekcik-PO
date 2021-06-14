#ifndef ZEGAR_H
#define ZEGAR_H

#include "Armia.h"
#include <Windows.h>
#include <ctime>

/*!
zliczanie czasu rzeczywistego odbywa sie za pomoca funkcji GetTickCount64() z biblioteki Windows.h
klasa odpowiedzialna za mierzenie uplywu czasu i tur
*/
class Zegar
{
public:
	//! statyczna funkcja skladowa klasy ustawiajaca ture na 0
	static void start();

	//! statyczna funkcja skladowa klasy zwiekszajaca ture o 1
	static void nowaTura();

	//! statyczna funkcja skladowa klasy zwracajaca liczbe tur
	static size_t dajObecnaTure();

	//! statyczna funkcja skladowa klasy zaczynajaca mierzyc czas rzeczywisty
	static void zacznijOdmierzacCzas();

	//! statyczna funkcja skladowa klasy, ktora zwraca czas pomiedzy jej wywolaniem a wywolaniem funkcji zacznijOdmierzacCzas()
	static ULONGLONG dajCzasWykonaniaSymulacjiMiliSekundy();

private:
	//! statyczny skladnik klasy przechowujacy liczbe tur
	static size_t tura;

	//! statyczny skladnik klasy przechowujacy czas startu symulacji 
	static ULONGLONG czasStartu;

	//! statyczny skladnik klasy przechowujacy czas startu symulacji 
	static ULONGLONG czasKonca;
};

#endif
