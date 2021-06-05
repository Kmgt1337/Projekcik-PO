#ifndef ZAPISDOPLIKU_H
#define ZAPISDOPLIKU_H

#include <vector>
#include "Armia.h"

class ZapisDoPliku
{
public:
	virtual bool zapis(const std::vector<Armia>& armie) = 0;
	virtual bool zapisPrzedBitwa(Armia, Armia) = 0;
	virtual bool zapisBitwy(Armia, Armia, std::vector<size_t>) = 0;
	virtual bool ostatniZapis(Armia) = 0;
};

#endif
