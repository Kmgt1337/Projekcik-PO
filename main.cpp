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
#include <string>
#include <fstream>

using namespace std;

bool start()
{
	size_t x, y;
	std::cout << "Podaj rozmiar mapy [x, y]: ";
	std::cin >> x >> y;

	Zegar::start();
	Mapa::inicjalizuj(x, y);
	Armia::inicjalizuj(x, y);
	Mapa::clrscr();
	system("cls");

	fstream plik;
	if (plik.is_open()) plik.close();

	plik.open("baza.txt", ios::out | ios::trunc);
	plik.clear();
	if (plik.good())
	{
		plik << "";
		plik.flush();
		plik.close();
		return true;
	}
	return false;
}

int main()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 15);

	Armia armia1 {1, 10, 10, 'X', 1, "Armia1",5000 };
	Armia armia2 {2, 15, 15, 'X', 2, "Armia2",10000 };
	Armia armia3 {3, 5, 5, 'X', 3, "Armia3",70000 };

	vector<Armia> armie;

		armie.push_back(armia1);
		armie.push_back(armia2);
		armie.push_back(armia3);

	Zegar zegar;
	ZapisDoPliku* zapisywacz;
	zapisywacz = &zegar;

	if(!start()) return -1;
	
	while (true)
	{
		Zegar::nowaTura();
		for (auto& armia : armie)
		{
			int id2 = armia.ruch();
			if (id2 != 0)
			{
				bool wynik = Operator_bitwy::wynik(armia.liczebnosc, armie[id2 - 1].liczebnosc);
				if (wynik == 0)
				{
					armie[id2 - 1].aktywna = 0;
				}
				else
				{
					armia.aktywna = 0;
				}
			}
			id2 = 0;
		}
		Mapa::rysuj(armie, hOut);
		//Sleep(500); //oczekiwanie przez 500 milisekund Windows.h sie klania :P
		// to w komentarzu zeby szybciej sie symulacja skonczyla

		if(!zapisywacz->zapis(armie)) return -1;
	}
}
