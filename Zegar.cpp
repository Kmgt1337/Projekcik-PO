#include "Zegar.h"
#include <fstream>
#include <iomanip>

using namespace std;

size_t Zegar::tura = 0;

bool Zegar::zapis(const std::vector<Armia>& armie)
{
	fstream plik;
	plik.open("baza.txt", ios::app);
	if (plik.fail()) return false;

	plik << " Tura nr " << Zegar::dajObecnaTure() << "\t";
	for (auto armia : armie)
	{
		plik << setw(10) << armia.dajNazwe() << ":["
			<< armia.dajPozycjeX() << ","
			<< armia.dajPozycjeY() << ","
			<< armia.dajLiczebnosc() << ","
			<< armia.dajPrzyna() << "]\t";
	}
	plik << endl;
	plik.close();
	return true;
}