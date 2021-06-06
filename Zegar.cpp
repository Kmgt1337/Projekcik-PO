#include "Zegar.h"
#include "Mapa.h"
#include <fstream>
#include <iomanip>
#include "Operator_bitwy.h"

using namespace std;

size_t Zegar::tura = 0;
DWORD Zegar::czasStartu;
DWORD Zegar::czasKonca;

bool Zegar::sprawdzCzySymulacjaSieZakonczyla(const vector<Armia>& armie)
{
	size_t pom = 0;

	for (auto armia : armie)
	{
		if (armia.dajLiczebnosc() > 0)
		{
			pom++;
		}
	}
	if (pom == 1)
	{ 
		return true;
	}
	return false;
}

Armia Zegar::pokazArmieZwycieska(const vector<Armia>& armie)
{
	for (auto armia : armie)
	{
		if (armia.dajLiczebnosc() > 0)
		{
			return armia;
		}
	}
}

bool Zegar::zapis(const std::vector<Armia>& armie)
{
	vector<size_t> iloscProwincji(armie.size());
	for (size_t i = 0; i < Mapa::dlug; i++)
	{
		for (size_t j = 0; j < Mapa::szer; j++)
		{
			switch (Mapa::mapa[i][j].przynaleznosc)
			{
			case 1:
				iloscProwincji.at(0)++;
				break;
			case 2:
				iloscProwincji.at(1)++;
				break;
			case 3:
				iloscProwincji.at(2)++;
				break;
			case 4:
				//iloscProwincji.at(3)++;
				break;
			}
		}
	}

	fstream plik;
	plik.open("baza.txt", ios::app);
	if (plik.fail()) return false;

	plik << " Tura nr " << Zegar::dajObecnaTure() << "\t";
	for (auto armia : armie)
	{
		if (armia.dajLiczebnosc() > 0)
		{
			plik << setw(10) << armia.dajNazwe() << ":["
				<< armia.dajPozycjeX() << ","
				<< armia.dajPozycjeY() << ","
				<< armia.dajLiczebnosc() << ","
				<< armia.dajPrzyna() << ",";

			switch(armia.dajPrzyna())
			{
			case 1:
				plik << iloscProwincji.at(0);
				break;
			case 2:
				plik << iloscProwincji.at(1);
				break;
			case 3:
				plik << iloscProwincji.at(2);
				break;
			case 4:
				//plik << iloscProwincji.at(3);
				break;
			}

			plik << "]\t";
		}
		else
		{
			plik << setw(10) << armia.dajNazwe() << ":["
				<< "armia wyeliminowana]\t";
		}
	}
	plik << endl;
	plik.close();
	return true;
}

bool Zegar::zapisPrzedBitwa(Armia armia1, Armia armia2)
{
	fstream plik;
	plik.open("baza.txt", ios::app);
	if (plik.fail()) return false;

	plik << endl;
	plik << "=============================== ";
	plik << "BITWA nr " << Operator_bitwy::dajLiczbeBitw() << ", pomiedzy " << armia1.dajNazwe() << " a " << armia2.dajNazwe() << endl;
	plik.close();
	return true;
}

bool Zegar::zapisBitwy(Armia armia1, Armia armia2, vector<size_t> zmianaHP)
{
	fstream plik;
	plik.open("baza.txt", ios::app);
	if (plik.fail()) return false;

	if (zmianaHP.at(2) == 1)
	{
		plik << "Wygrala " << armia1.dajNazwe() << endl;
	}
	if (zmianaHP.at(2) == 2)
	{
		plik << "Wygrala " << armia2.dajNazwe() << endl;
	}
	plik << armia1.dajNazwe() << " stracila " << zmianaHP.at(0) << " zolnierzy" << endl;
	plik << armia2.dajNazwe() << " stracila " << zmianaHP.at(1) << " zolnierzy" << endl;
	plik << "===============================" << endl;
	plik.close();
	return true;
}

bool Zegar::ostatniZapis(Armia armia, DWORD czas)
{
	fstream plik;
	plik.open("baza.txt", ios::app);
	if (plik.fail()) return false;

	plik << endl << endl;
	plik << setw(50) << setfill('=') << endl;
	plik << "WYGRALA " << armia.dajNazwe() << endl;
	plik << setw(50) << setfill('=') << endl;
	plik << "Czas trwania symulacji: " << czas << " milisekund" << endl;
	plik.close();
	return true;
}

bool Zegar::zapisPrzedSymulacja(const std::vector<Armia>& armie)
{
	fstream plik;
	plik.open("baza.txt", ios::app);
	if (plik.fail()) return false;
	
	plik << "=====PROGRAM SYMULACYJNY: WOJNY====" << endl << endl;
	plik << "Parametry przed rozpoczêciem symulacji: ";
	plik << "Rozmiar mapy:[" << Mapa::szer << " x " << Mapa::dlug << "]";
	for (auto armia : armie)
	{
		plik << setw(10) 
			<< armia.dajNazwe() << ":["
			<< armia.dajPozycjeX() << ","
			<< armia.dajPozycjeY() << ","
			<< armia.dajLiczebnosc() << ","
			<< armia.dajPrzyna() << "]\t";
	}
	plik << endl << endl;
	plik.close();
	return true;
}