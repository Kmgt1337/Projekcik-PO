#ifndef OPERATORPLIKU_H
#define OPERATORPLIKU_H

#include "Armia.h"
#include "Windows.h"
#include <vector>
#include <ctime>

// Klasa odpowiadaj¹ca za zapis parametrów symulacji do pliku tekstowego
class OperatorPliku
{
public:
	// podstawowa statyczna funkcja sk³adowa klasy zapisuj¹ca parametry do pliku, zapisuje parametry wszystkich armii na ka¿d¹ turê
	static bool zapis(const std::vector<Armia>& armie);

	// statyczna funkcja sk³adowa klasy zapisuj¹ca do pliku parametry przed rozpoczêciem symulacji
	static bool zapisPrzedSymulacja(const std::vector<Armia>&);

	// statyczna funkcja sk³adowa klasy zapisuj¹ca do pliku parametry przed rozpoczêciem bitwy
	static bool zapisPrzedBitwa(Armia, Armia);

	// statyczna funkcja sk³adowa klasy zapisuj¹ca do pliku przebieg bitwy pomiêdzy dwoma armiami
	static bool zapisBitwy(Armia, Armia, std::vector<size_t>, std::vector<float>);

	// statyczna funkcja sk³adowa klasy zapisuj¹ca koñcowe parametry symulacji (w sytuacji gdy armia wygra poprzez militarne zwyciêstwo)
	static bool ostatniZapis(Armia, ULONGLONG);

	// statyczna funkcja sk³adowa klasy zapisuj¹ca koñcowe parametry symulacji (w sytuacji gdy osi¹gniêty zostanie limit tur)
	static bool ostatniZapisTury(const std::vector<Armia>&, Armia, ULONGLONG);

	// statyczna funkcja sk³adowa klasy zapisuj¹ca parametry zebranego zasobu przez armiê
	static bool zapisZasobu(Armia, rodzajeZasobu);
};

#endif

