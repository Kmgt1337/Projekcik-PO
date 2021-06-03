#include "Mapa.h"
#include "Armia.h"
#include "Artyleria.h"
#include "General.h"
#include "Kawaleria.h"
#include "Oddzial.h"
#include "Operator_bitwy.h"
#include "Prowincja.h"
#include "Strona_konfliktu.h"
#include "Zegar.h"
#include "Zwiad.h"
#include <vector>
#include <iostream>
#include <Windows.h>
#include <random>

using namespace std;

int main()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 15);

	Armia armia1{ 10, 10, '#', 1, "Armia1" };
	Armia armia2{ 20, 20, '@', 2, "Armia2" };
	Armia armia3{ 5, 5, 'X', 3, "Armia3" };

	std::vector<Armia> armie;
	armie.push_back(armia1);
	armie.push_back(armia2);
	armie.push_back(armia3);

	Zegar zegar;
	ZapisDoPliku* zapisywacz;
	zapisywacz = &zegar;

	Zegar::start();
	while (true)
	{
		Zegar::nowaTura();
		for (auto& armia : armie)
		{
			armia.ruch();
		}
		Mapa::rysuj(armie,hOut);
		Sleep(500); //oczekiwanie przez 500 milisekund Windows.h sie klania :P

		zapisywacz->zapis(armie);
	}
}