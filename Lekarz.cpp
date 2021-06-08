#include "Lekarz.h"
#include <random>
using namespace std;

Lekarz::Lekarz()
{
	random_device device;
	mt19937 gen(device());
	uniform_int_distribution<size_t> losujModLiczebnosc{ 10, 100 };

	modLiczebnosc = losujModLiczebnosc(gen);
}
