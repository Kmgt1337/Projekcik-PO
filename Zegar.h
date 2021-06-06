#ifndef ZEGAR_H
#define ZEGAR_H

#include "Armia.h"
#include "ZapisDoPliku.h"
#include <Windows.h>

class Zegar : public ZapisDoPliku
{
private:
	static size_t tura;
	static DWORD czasStartu, czasKonca;
public:
	bool koniec;
	static void start() { tura = 0; }

	static void nowaTura() { ++tura; }
	static size_t dajObecnaTure() { return tura; }

	static void zacznijOdmierzacCzas() { czasStartu = GetTickCount(); }
	static DWORD dajCzasWykonaniaSymulacjiMiliSekundy()
	{
		czasKonca = GetTickCount();
		return (czasKonca - czasStartu);
	}

	static bool sprawdzCzySymulacjaSieZakonczyla(const std::vector<Armia>&);
	static Armia pokazArmieZwycieska(const std::vector<Armia>&);

	virtual bool zapis(const std::vector<Armia>& armie);
	virtual bool zapisPrzedSymulacja(const std::vector<Armia>&);
	virtual bool zapisPrzedBitwa(Armia, Armia);
	virtual bool zapisBitwy(Armia, Armia, std::vector<size_t>, std::vector<float>);
	virtual bool ostatniZapis(Armia, DWORD);
};
#endif

