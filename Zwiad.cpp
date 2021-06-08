#include "Zwiad.h"
#include "Mapa.h"
#include "Mapa.h"

Zwiad::Zwiad(int przynaleznosc)
{
	this->przynaleznosc = przynaleznosc;
}

void Zwiad::raport()
{
	modLiczebnosc = 0;
	for (size_t i = 0; i < Mapa::dlug; i++)
	{
		for (size_t j = 0; j < Mapa::szer; j++)
		{
			if (this->przynaleznosc == Mapa::mapa[i][j].dajPrzynaleznosc())
			{
				modLiczebnosc++;
			}
		}
	}
}