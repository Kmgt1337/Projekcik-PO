#include "Zegar.h"
#include <chrono>

size_t Zegar::tura = 0;
DWORD Zegar::czasStartu;
DWORD Zegar::czasKonca;

void Zegar::start()
{
	tura = 0;
}

void Zegar::nowaTura()
{
	++tura;
}

size_t Zegar::dajObecnaTure()
{
	return tura;
}

void Zegar::zacznijOdmierzacCzas()
{
	czasStartu = GetTickCount();
}

DWORD Zegar::dajCzasWykonaniaSymulacjiMiliSekundy()
{
	czasKonca = GetTickCount();
	return (czasKonca - czasStartu);
}
