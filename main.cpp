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
	Armia armia3{ 5, 5, 'X' };
	std::vector<Armia> armie;
	for (size_t i = 0; i < 5; i++)
	{
		armie.push_back(armia1);
		armie.push_back(armia2);
		armie.push_back(armia3);
	}

	Prowincja prowincja1{ 1, 1, 10, "Prowincja1", '1' };
	Prowincja prowincja2{ 20, 20, 10, "Prowincja2", '2' };
	Prowincja prowincja3{ 15, 40, 5, "Prowincja3", '3' };
	std::vector<Prowincja> prowincje;
	prowincje.push_back(prowincja1);
	prowincje.push_back(prowincja2);
	prowincje.push_back(prowincja3);

	Mapa::inicjalizujMape();
	while (true)
	{
		for (auto& armia : armie)
		{
			armia.ruch();
		}
		Mapa::rysuj(armie, prowincje);
	}
}