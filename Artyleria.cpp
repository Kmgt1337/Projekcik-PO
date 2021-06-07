#include "Artyleria.h"
#include <random>
using namespace std;

Artyleria::Artyleria()
{
	random_device device;
	mt19937 gen(device());
	uniform_int_distribution<size_t> losujModDefensywa{ 10, 100 };

	modOfensywa = losujModDefensywa(gen);
}