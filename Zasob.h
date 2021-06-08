#ifndef ZASOB_H
#define ZASOB_H

// rodzaje dost�pnych zasob�w, "LICZEBNOSC5" oznacza na przyk�ad, �e ten rodzaj zasobu zwieksza liczebno�� armii o 5%. Reszta zasob�w analogicznie
enum class rodzajeZasobu { BRAK, LICZEBNOSC5, LICZEBNOSC10, LICZEBNOSC15, OBRAZENIA5, OBRAZENIA10, OBRAZENIA15 };

// klasa odpowiedzialna za zasoby kt�re armia mo�e zbiera� podczas poruszania si� po mapie. Ka�da prowincja posiada sw�j zas�b,
// g��wnie jest to zas�b "BRAK" kt�ry nic nie robi. Prowincja mo�e jednak zawiera� warto�ciowe zasoby wymienione w enum class rodzajeZasobu.
// Po zebraniu zasobu przez armi� staje si� on nieaktywny i ju� nigdy nie b�dzie zebrany
class Zasob
{
public:
	Zasob();

	rodzajeZasobu dajRodzajZasobu() { return rodzajZasobu; }

	void zmienAktywnoscZasobuNa(bool pom) { aktywnoscZasobu = pom; }

	bool dajAktywnoscZasobu() { return aktywnoscZasobu; }

private:
	rodzajeZasobu rodzajZasobu;
	bool aktywnoscZasobu;
};

#endif
