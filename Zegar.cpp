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

	for (auto armia : armie)
	{
		plik << setw(10) << armia.dajNazwe() << ":[" << armia.dajPozycjeX() << "," << armia.dajPozycjeY() << "]\t";
	}
	plik << setw(10) << "<------ tura nr " << Zegar::dajObecnaTure();
	plik << endl;
	plik.close();
	return true;
}