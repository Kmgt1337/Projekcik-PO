#ifndef OPERATORZAKONCZENIA_H
#define OPERATORZAKONCZENIA_H

#include "Armia.h"
#include "Zegar.h"
#include <vector>

// istniej¹ dwa mo¿liwe zakoñczenia symulacji:
// 1. zwyciêstwo militarne - w przypadku gdy na polu walki zostanie tylko jedna armia - wygrywa ona symulacjê
// 2. zakoñczenie przez osi¹gniêcie limtu tur - w przypadku gdy w symulacji zostanie osi¹gniêty ustalony limit tur a co najmniej dwie armie
// ¿yj¹ - wygrywa armia, która przejê³a wiêcej prowincji

// klasa odpowiadaj¹ca za sprawdzenie czy wyst¹pi³y warunki zakoñczenia symulacji
class OperatorZakonczenia
{
public:
	// statyczna funkcja sk³adowa klasy ustawiaj¹ca maksymalny limit tur
	static void ustawMaksymalnyLimitTur(size_t);

	// statyczna funkcja sk³adowa klasy sprawdzaj¹ca czy symulacja zakoñczy³a siê zwyciêstwem militarnym którejœ z armii
	static bool sprawdzCzySymulacjaSieZakonczylaArmie(const std::vector<Armia>&);

	// statyczna funkcja sk³adowa klasy sprawdzaj¹ca czy symulacji zakoñczy³a siê przez osi¹gniêcie limitu tur
	static bool sprawdzCzySymulacjaSieZakonczylaTury();

	// statyczna funkcja sk³adowa klasy zliczaj¹ca ile ka¿da armia posiada przejêtych prowincji
	static std::vector<size_t> podajLiczbeProwincjiArmii(const std::vector<Armia>&);

	// statyczna funkcja sk³adowa klasy wyznaczaj¹ca wygran¹ armiê
	static Armia pokazArmieZwycieska(const std::vector<Armia>&);

	// statyczna funkcja sk³adowa klasy zwracaj¹ca maksymaln¹ liczbê tur
	static size_t dajMaxTure();

private:
	// sk³adnik klasy przechowuj¹cy maksymaln¹ liczbê tur
	static size_t maxTura;
};

#endif

