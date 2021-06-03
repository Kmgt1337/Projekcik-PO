#include "Armia.h"
#include <random>

using namespace std;

Armia::Armia(size_t x, size_t y, char symbol)
{
	random_device device;
	mt19937 gen(device());
	uniform_int_distribution<size_t> losujLiczebnoscArmii{ 10000, 12000 };
	uniform_int_distribution<int> losujPrzejmowanieS{ 0, 5 };

	liczebnosc = losujLiczebnoscArmii(gen);
	przejmowanieS = losujPrzejmowanieS(gen);

	pozycjaX = x;
	pozycjaY = y;

	this->symbol = symbol;
}

void Armia::ruch()
{
	random_device device;
	mt19937 gen(device());
	uniform_int_distribution<size_t> kierunek{ 1, 4 };
	size_t pom = kierunek(gen);

	switch (pom)
	{
		// ruch w gore
		case 1:
			--pozycjaX;
			break;

		//ruch w lewo
		case 2:
			--pozycjaY;
			break;

		//ruch w dol
		case 3:
			++pozycjaX;
			break;
		
		//ruch w prawo
		case 4:
			++pozycjaY;
			break;
	}
}

