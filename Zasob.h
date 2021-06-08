#ifndef ZASOB_H
#define ZASOB_H

// rodzaje dostêpnych zasobów, "LICZEBNOSC5" oznacza na przyk³ad, ¿e ten rodzaj zasobu zwieksza liczebnoœæ armii o 5%. Reszta zasobów analogicznie
enum class rodzajeZasobu { BRAK, LICZEBNOSC5, LICZEBNOSC10, LICZEBNOSC15, OBRAZENIA5, OBRAZENIA10, OBRAZENIA15 };

// klasa odpowiedzialna za zasoby które armia mo¿e zbieraæ podczas poruszania siê po mapie. Ka¿da prowincja posiada swój zasób,
// g³ównie jest to zasób "BRAK" który nic nie robi. Prowincja mo¿e jednak zawieraæ wartoœciowe zasoby wymienione w enum class rodzajeZasobu.
// Po zebraniu zasobu przez armiê staje siê on nieaktywny i ju¿ nigdy nie bêdzie zebrany
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
