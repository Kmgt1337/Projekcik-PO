#ifndef ZAPISDOPLIKU_H
#define ZAPISDOPLIKU_H

#include <vector>
#include <Windows.h>
#include "Armia.h"

class ZapisDoPliku
{
public:
	virtual bool zapis(const std::vector<Armia>&) = 0;
	virtual bool zapisPrzedSymulacja(const std::vector<Armia>&) = 0;
	virtual bool zapisPrzedBitwa(Armia, Armia) = 0;
	virtual bool zapisBitwy(Armia, Armia, std::vector<size_t>, std::vector<float>) = 0;
	virtual bool ostatniZapis(Armia, DWORD) = 0;
};

#endif
