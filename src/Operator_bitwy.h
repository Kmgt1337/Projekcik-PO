#ifndef OPERATOR_BITWY_H
#define OPERATOR_BITWY_H

#include "Armia.h"
#include <vector>

//! klasa odpowiadajaca za przeprowadzanie bitw pomiedzy armiami
class Operator_bitwy
{
public:
	//! statyczna funkcja skladowa klasy zwracajaca liczbe przeprowadzonych bitw
	static size_t dajLiczbeBitw();

	//! statyczna funkcja skladowa klasy losujaca ktora armia bedzie miala status wygranej podczas danej bitwy (straty armii moga jednakze zmienic ten status)
	static bool wynik();

	//! statyczna funkcja skladowa klasy zwracajaca procentowe straty poniesione przez dwie armie podczas bitwy
	static std::vector<float> dajStratyProcentoweArmii();

	//! statyczna funckcja skladowa klasy przeprowadzajaca bitwe pomiedzy dwiema armiami 
	static std::vector<size_t> bitwa(Armia&, Armia&);

private:
	//! statyczny skladnik klasy przechowujacy liczbe przeprowadzonych bitw
	static size_t licznikBitw;

	//! statyczny skladnik klasy przechowujacy procentowa strate armii pierwszej podczas bitwy
	static float procentowaStrataArmii1;

	//! statyczny skladnik klasy przechowujacy procentowa strate armii drugiej podczas bitwy
	static float procentowaStrataArmii2;
};
#endif

