#ifndef OPERATOR_BITWY_H
#define OPERATOR_BITWY_H

#include "ZapisDoPliku.h"
#include "Armia.h"

class Operator_bitwy
{
private:
	static size_t licznikBitw;
	static float procentowaStrataArmii1;
	static float procentowaStrataArmii2;

public:
	static size_t dajLiczbeBitw() { return licznikBitw; }

	static bool wynik();
	static bool ostatniWynik(int, int);
	static std::vector<float> dajStratyProcentoweArmii();
	static std::vector<size_t> bitwa(Armia&, Armia&);
	static std::vector<size_t> ostatniaBitwa(Armia&, Armia&);
};
#endif

