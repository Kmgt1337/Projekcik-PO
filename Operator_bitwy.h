#ifndef OPERATOR_BITWY_H
#define OPERATOR_BITWY_H

#include "ZapisDoPliku.h"
#include "Armia.h"

class Operator_bitwy
{
	static size_t licznikBitw;

public:
	static size_t dajLiczbeBitw() { return licznikBitw; }

	static bool wynik();
	static std::vector<size_t> bitwa(Armia&, Armia&);
};
#endif

