#include "Zegar.h"
#include <fstream>
#include <iomanip>
#include "Operator_bitwy.h"

using namespace std;

size_t Zegar::tura = 0;

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
				<< armia.dajPrzyna() << "]\t";
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
		plik << "Wygrala armia " << armia1.dajNazwe() << endl;
	}
	if (zmianaHP.at(2) == 2)
	{
		plik << "Wygrala armia " << armia2.dajNazwe() << endl;
	}
	plik << armia1.dajNazwe() << " stracila " << zmianaHP.at(0) << " zolnierzy" << endl;
	plik << armia2.dajNazwe() << " stracila " << zmianaHP.at(1) << " zolnierzy" << endl;
	plik << "===============================" << endl;
	plik.close();
	return true;
}

bool Zegar::ostatniZapis(Armia armia)
{
	fstream plik;
	plik.open("baza.txt", ios::app);
	if (plik.fail()) return false;

	plik << endl << endl;
	plik << setw(50) << setfill('=') << endl;
	plik << "WYGRALA ARMIA " << armia.dajNazwe() << endl;
	plik << "HP armii: " << armia.dajLiczebnosc() << endl;
	plik.close();
	return true;
}