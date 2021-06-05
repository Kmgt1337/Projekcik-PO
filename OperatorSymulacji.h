#pragma once

#include "Armia.h"
#include "Zegar.h"
#include "Mapa.h"
#include "Operator_bitwy.h"
#include <vector>

class OperatorSymulacji
{
public:
	bool zainicjalizujSymulacje();
	int prowadzSymulacje();

private:
	bool czySymulacjaJestAktywna;

	std::vector<Armia> armie;
	std::vector<size_t> zmianaLiczebnosci;
	Armia armiaZwycieska;
	
	Zegar zegar;
	ZapisDoPliku* zapisywacz = &zegar;

	DWORD czasTrwaniaSymulacji;
	HANDLE hOut;

	const size_t minimum = 10;
	const size_t maksimumX = 40;
	const size_t maksimumY = 40;
};
