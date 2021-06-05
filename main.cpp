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

// gdy program zwroci -3 to wtedy jest problem z zapisem do pliku

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

	Armia armia1 {1, 10, 10, 'X', 1, "ArmiaPolska", 5000 };
	Armia armia2 {2, 15, 15, 'X', 2, "ArmiaNiemiecka",10000 };
	Armia armia3 {3, 5, 5, 'X', 3, "ArmiaRosyjska",70000 };
	Armia armiaZwycieska;

	vector<size_t> zmianaLiczebnosci;
	vector<Armia> armie;

	armie.push_back(armia1);
	armie.push_back(armia2);
	armie.push_back(armia3);

	Zegar zegar;
	ZapisDoPliku* zapisywacz;
	zapisywacz = &zegar;

	if(!start()) return -3;
	
	while (true)
	{
		if (Zegar::sprawdzCzySymulacjaSieZakonczyla(armie))
		{
			armiaZwycieska = Zegar::pokazArmieZwycieska(armie);
			break;
		}

		Zegar::nowaTura();
		for (auto& armia : armie)
		{
			int id2 = armia.ruch();
			if (id2 != 0)
			{
				/*bool wynik = Operator_bitwy::wynik(armia.liczebnosc, armie[id2 - 1].liczebnosc);
				if (wynik == 0)
				{
					armie[id2 - 1].aktywna = 0;
				}
				else
				{
					armia.aktywna = 0;
				}*/
				if (armia.dajLiczebnosc() < 0)
				{
					armia.aktywna = 0;
				}
				if (armia.dajLiczebnosc() > 0 && armie[id2 - 1].dajLiczebnosc() > 0)
				{
					if (!zapisywacz->zapisPrzedBitwa(armia, armie[id2 - 1])) return -3;
					zmianaLiczebnosci = Operator_bitwy::bitwa(armia, armie[id2 - 1]);
					if (!zapisywacz->zapisBitwy(armia, armie[id2 - 1], zmianaLiczebnosci)) return -3;
				}
			}
			id2 = 0;
		}
		Mapa::rysuj(armie, hOut);
		if(!zapisywacz->zapis(armie)) return -3;
	}

	Mapa::clrscr();
	system("cls");
	if (!zapisywacz->ostatniZapis(armiaZwycieska)) return -3;
	std::cout << "Armia zwycieska to: " << armiaZwycieska.dajNazwe() << endl;
}
