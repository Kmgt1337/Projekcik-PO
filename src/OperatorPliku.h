#ifndef OPERATORPLIKU_H
#define OPERATORPLIKU_H

#include "Armia.h"
#include "Windows.h"
#include <vector>
#include <ctime>

//! klasa odpowiadajaca za zapis parametrow symulacji do pliku tekstowego
class OperatorPliku
{
public:
	//! podstawowa statyczna funkcja skladowa klasy zapisujaca parametry do pliku, zapisuje parametry wszystkich armii na kazda turê
	static bool zapis(const std::vector<Armia>& armie);

	//! statyczna funkcja skladowa klasy zapisujaca do pliku parametry przed rozpoczeciem symulacji
	static bool zapisPrzedSymulacja(const std::vector<Armia>&);

	//! statyczna funkcja skladowa klasy zapisujaca do pliku parametry przed rozpoczeciem bitwy
	static bool zapisPrzedBitwa(Armia, Armia);

	//! statyczna funkcja skladowa klasy zapisujaca do pliku przebieg bitwy pomiedzy dwoma armiami
	static bool zapisBitwy(Armia, Armia, std::vector<size_t>, std::vector<float>);

	//! statyczna funkcja skladowa klasy zapisujaca koncowe parametry symulacji (w sytuacji gdy armia wygra poprzez militarne zwyciestwo)
	static bool ostatniZapis(Armia, ULONGLONG);

	//! statyczna funkcja skladowa klasy zapisujaca koncowe parametry symulacji (w sytuacji gdy osi¹gniety zostanie limit tur)
	static bool ostatniZapisTury(const std::vector<Armia>&, Armia, ULONGLONG);

	//! statyczna funkcja skladowa klasy zapisujaca parametry zebranego zasobu przez armie
	static bool zapisZasobu(Armia, rodzajeZasobu);
};

#endif

