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

	Armia armia1{ 10, 10, '#', 1 };
	Armia armia2{ 20, 20, '@', 2 };
	Armia armia3{ 5, 5, 'X', 3 };

	std::vector<Armia> armie;

	armie.push_back(armia1);
	armie.push_back(armia2);
	armie.push_back(armia3);

	while (true)
	{
		for (auto& armia : armie)
		{
			armia.ruch();
		}
		Mapa::rysuj(armie,hOut);
		Sleep(500);
	}
}