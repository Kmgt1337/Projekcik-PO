#ifndef OPERATOR_BITWY_H
#define OPERATOR_BITWY_H

#include "Armia.h"
#include <vector>

// klasa odpowiadaj�ca za przeprowadzanie bitw pomi�dzy armiami
class Operator_bitwy
{
public:
	// statyczna funkcja sk�adowa klasy zwracaj�ca liczb� przeprowadzonych bitw
	static size_t dajLiczbeBitw();

	// statyczna funkcja sk�adowa klasy losuj�ca kt�ra armia b�dzie mia�a status wygranej podczas danej bitwy (straty armii mog� jednak�e zmieni� ten status)
	static bool wynik();

	// statyczna funkcja sk�adowa klasy zwracaj�ca procentowe straty poniesione przez dwie armie podczas bitwy
	static std::vector<float> dajStratyProcentoweArmii();

	// statyczna funckcja sk�adowa klasy przeprowadzaj�ca bitw� pomi�dzy dwoma armiami 
	static std::vector<size_t> bitwa(Armia&, Armia&);

private:
	// statyczny sk�adnik klasy przechowuj�cy liczb� przeprowadzonych bitw
	static size_t licznikBitw;

	// statyczny sk�adnik klasy przechowuj�cy procentow� strat� armii pierwszej podczas bitwy
	static float procentowaStrataArmii1;

	// statyczny sk�adnik klasy przechowuj�cy procentow� strat� armii drugiej podczas bitwy
	static float procentowaStrataArmii2;
};
#endif

