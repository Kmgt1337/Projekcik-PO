#ifndef ZEGAR_H
#define ZEGAR_H

#include "Armia.h"
#include "ZapisDoPliku.h"

class Zegar : public ZapisDoPliku
{
private:
	static size_t tura;
	int tura_koncowa;
	void odliczanie();

public:
	bool koniec;
	static void start() { tura = 0; }
	void stop();

	static void nowaTura() { ++tura; }
	static size_t dajObecnaTure() { return tura; }

	static bool sprawdzCzySymulacjaSieZakonczyla(const std::vector<Armia>&);
	static Armia pokazArmieZwycieska(const std::vector<Armia>&);

	virtual bool zapis(const std::vector<Armia>& armie);
	virtual bool zapisPrzedBitwa(Armia, Armia);
	virtual bool zapisBitwy(Armia, Armia, std::vector<size_t>);
	virtual bool ostatniZapis(Armia);
};
#endif

