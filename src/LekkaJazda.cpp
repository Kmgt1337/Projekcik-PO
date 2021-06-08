#include "LekkaJazda.h"
#include <random>
using namespace std;

LekkaJazda::LekkaJazda()
{
	random_device device;
	mt19937 gen(device());
	uniform_int_distribution<size_t> losujModDefensywa{ 10, 100 };

	modDefensywa = losujModDefensywa(gen);
}
