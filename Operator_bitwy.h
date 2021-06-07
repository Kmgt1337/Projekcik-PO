#ifndef OPERATOR_BITWY_H
#define OPERATOR_BITWY_H

#include "Armia.h"
#include <vector>

// klasa odpowiadaj¹ca za przeprowadzanie bitw pomiêdzy armiami
class Operator_bitwy
{
public:
	// statyczna funkcja sk³adowa klasy zwracaj¹ca liczbê przeprowadzonych bitw
	static size_t dajLiczbeBitw();

	// statyczna funkcja sk³adowa klasy losuj¹ca która armia bêdzie mia³a status wygranej podczas danej bitwy (straty armii mog¹ jednak¿e zmieniæ ten status)
	static bool wynik();

	// statyczna funkcja sk³adowa klasy zwracaj¹ca procentowe straty poniesione przez dwie armie podczas bitwy
	static std::vector<float> dajStratyProcentoweArmii();

	// statyczna funckcja sk³adowa klasy przeprowadzaj¹ca bitwê pomiêdzy dwoma armiami 
	static std::vector<size_t> bitwa(Armia&, Armia&);

private:
	// statyczny sk³adnik klasy przechowuj¹cy liczbê przeprowadzonych bitw
	static size_t licznikBitw;

	// statyczny sk³adnik klasy przechowuj¹cy procentow¹ stratê armii pierwszej podczas bitwy
	static float procentowaStrataArmii1;

	// statyczny sk³adnik klasy przechowuj¹cy procentow¹ stratê armii drugiej podczas bitwy
	static float procentowaStrataArmii2;
};
#endif

