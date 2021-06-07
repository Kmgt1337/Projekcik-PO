#include "CiezkaJazda.h"
#include <random>
using namespace std;

CiezkaJazda::CiezkaJazda()
{
	random_device device;
	mt19937 gen(device());
	uniform_int_distribution<size_t> losujModObrazenia{ 100, 500 };
	modObrazenia = losujModObrazenia(gen);
}