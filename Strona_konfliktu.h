#ifndef STRONA_KONFLIKTU_H
#define STRONA_KONFLIKTU_H

class Strona_konfliktu
{
public:
	int budzet;
	int przychod();
	int wydatki();
private:
	bool kapitulacja();
};
#endif

