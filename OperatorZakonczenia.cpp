#include "OperatorZakonczenia.h"
#include "Mapa.h"
#include <algorithm>
using namespace std;

size_t OperatorZakonczenia::maxTura = 3000;

void OperatorZakonczenia::ustawMaksymalnyLimitTur(size_t a)
{
	maxTura = a;
}

size_t OperatorZakonczenia::dajMaxTure()
{
	return maxTura;
}

bool OperatorZakonczenia::sprawdzCzySymulacjaSieZakonczylaArmie(const vector<Armia>& armie)
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

bool OperatorZakonczenia::sprawdzCzySymulacjaSieZakonczylaTury()
{
	if (maxTura <= Zegar::dajObecnaTure())
	{
		return true;
	}
	return false;
}

vector<size_t> OperatorZakonczenia::podajLiczbeProwincjiArmii(const vector<Armia>& armie)
{
	vector<size_t> pom;

	for (size_t i = 0; i < armie.size(); i++)
	{
		pom.push_back(Mapa::dajLiczbeProwincjiArmii(armie.at(i)));
	}

	return pom;
}

Armia OperatorZakonczenia::pokazArmieZwycieska(const vector<Armia>& armie)
{
	vector<size_t> pom(armie.size());
	size_t max;
	size_t indeks = 0;

	if (sprawdzCzySymulacjaSieZakonczylaTury())
	{
		pom = podajLiczbeProwincjiArmii(armie);

		max = pom.at(0);
		for (size_t i = 0; i < pom.size(); i++)
		{
			if (pom.at(i) > max)
			{
				max = pom.at(i);
				indeks = i;
			}
		}

		return armie.at(indeks);
	}

	for (auto armia : armie)
	{
		if (armia.dajLiczebnosc() > 0)
		{
			return armia;
		}
	}
}
