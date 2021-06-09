#include "Zegar.h"

size_t Zegar::tura = 0;
ULONGLONG Zegar::czasStartu;
ULONGLONG Zegar::czasKonca;

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
	czasStartu = GetTickCount64();
}

ULONGLONG Zegar::dajCzasWykonaniaSymulacjiMiliSekundy()
{
	czasKonca = GetTickCount64();
	return (czasKonca - czasStartu);
}
