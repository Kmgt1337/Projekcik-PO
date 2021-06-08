#include "Zasob.h"
#include <random>
using namespace std;

Zasob::Zasob()
{
	random_device device;
	mt19937 gen(device());
	uniform_int_distribution<size_t> losujRodzajZasobuLiczebnosci{ 0, 50 };

	size_t pom1 = losujRodzajZasobuLiczebnosci(gen);

	switch (pom1)
	{
	case 0:
		rodzajZasobu = rodzajeZasobu::LICZEBNOSC5;
		break;

	case 1:
		rodzajZasobu = rodzajeZasobu::LICZEBNOSC10;
		break;

	case 2:
		rodzajZasobu = rodzajeZasobu::LICZEBNOSC15;
		break;

	case 3:
		rodzajZasobu = rodzajeZasobu::OBRAZENIA5;
		break;
	case 4:
		rodzajZasobu = rodzajeZasobu::OBRAZENIA10;
		break;
	case 5:
		rodzajZasobu = rodzajeZasobu::OBRAZENIA15;
		break;

	default:
		rodzajZasobu = rodzajeZasobu::BRAK;
		break;
	}

	aktywnoscZasobu = true;
}