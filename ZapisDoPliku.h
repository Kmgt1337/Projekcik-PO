#ifndef ZAPISDOPLIKU_H
#define ZAPISDOPLIKU_H

#include <vector>

class ZapisDoPliku
{
public:
	virtual bool zapis(const std::vector<Armia>& armie) = 0;
};

#endif
