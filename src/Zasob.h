#ifndef ZASOB_H
#define ZASOB_H

//! rodzaje dostepnych zasobow, "LICZEBNOSC5" oznacza na przyklad, ze ten rodzaj zasobu zwieksza liczebnosc armii o 5%. Reszta zasobow analogicznie
enum class rodzajeZasobu { BRAK, LICZEBNOSC5, LICZEBNOSC10, LICZEBNOSC15, OBRAZENIA5, OBRAZENIA10, OBRAZENIA15 };

/*!
klasa odpowiedzialna za zasoby ktore armia moze zbierac podczas poruszania sie po mapie. Kazda prowincja posiada swoj zasob,
glownie jest to zasob "BRAK" ktory nic nie robi. Prowincja moze jednak zawierac wartosciowe zasoby wymienione w enum class rodzajeZasobu.
Po zebraniu zasobu przez armie staje siêeon nieaktywny i juz nigdy nie bedzie zebrany
*/
class Zasob
{
public:
	//! konstruktor klasy losujaca rodzaj zasobu
	Zasob();

	//! funkcja skladowa klasy zwracajacy rodzaj zasoby ktory przechowuje obiekt tej klasy
	rodzajeZasobu dajRodzajZasobu() { return rodzajZasobu; }

	//! funkcja skladowa klasy zmieniajaca aktywnosc zasobu na wskazany
	void zmienAktywnoscZasobuNa(bool pom) { aktywnoscZasobu = pom; }

	//! funkcja skladowa klasy zwracajaca aktywnosc zasobu
	bool dajAktywnoscZasobu() { return aktywnoscZasobu; }

private:
	//! skladnik klasy przechowujacy rodzaj zasobu
	rodzajeZasobu rodzajZasobu;

	//! skladnik klasy przechowujacy czy dany zasob jest aktywny
	bool aktywnoscZasobu;
};

#endif
