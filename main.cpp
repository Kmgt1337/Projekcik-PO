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

int main()
{
	Armia armia1{ 10, 10, '#' };
	Armia armia2{ 20, 20, '@' };
	Armia armie3{ 5, 5, 'X' };
	std::vector<Armia> armie;

	armie.push_back(armia1);
	armie.push_back(armia2);

	Mapa::rysujArmie(armie);

	while (true)
	{
		for (auto& armia : armie)
		{
			armia.ruch();
		}
		Mapa::rysujArmie(armie);
	}

	//Mapa::grafika();
}