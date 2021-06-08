#include "General.h"
#include <random>
using namespace std;

General::General()
{
	random_device device;
	mt19937 gen(device());
	uniform_int_distribution<size_t> losujModObrazenia{ 10, 100 };

	modObrazenia = losujModObrazenia(gen);
}