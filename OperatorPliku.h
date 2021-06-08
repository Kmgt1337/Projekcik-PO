#ifndef OPERATORPLIKU_H
#define OPERATORPLIKU_H

#include "Armia.h"
#include "Windows.h"
#include <vector>
#include <ctime>

// Klasa odpowiadaj�ca za zapis parametr�w symulacji do pliku tekstowego
class OperatorPliku
{
public:
	// podstawowa statyczna funkcja sk�adowa klasy zapisuj�ca parametry do pliku, zapisuje parametry wszystkich armii na ka�d� tur�
	static bool zapis(const std::vector<Armia>& armie);

	// statyczna funkcja sk�adowa klasy zapisuj�ca do pliku parametry przed rozpocz�ciem symulacji
	static bool zapisPrzedSymulacja(const std::vector<Armia>&);

	// statyczna funkcja sk�adowa klasy zapisuj�ca do pliku parametry przed rozpocz�ciem bitwy
	static bool zapisPrzedBitwa(Armia, Armia);

	// statyczna funkcja sk�adowa klasy zapisuj�ca do pliku przebieg bitwy pomi�dzy dwoma armiami
	static bool zapisBitwy(Armia, Armia, std::vector<size_t>, std::vector<float>);

	// statyczna funkcja sk�adowa klasy zapisuj�ca ko�cowe parametry symulacji (w sytuacji gdy armia wygra poprzez militarne zwyci�stwo)
	static bool ostatniZapis(Armia, ULONGLONG);

	// statyczna funkcja sk�adowa klasy zapisuj�ca ko�cowe parametry symulacji (w sytuacji gdy osi�gni�ty zostanie limit tur)
	static bool ostatniZapisTury(const std::vector<Armia>&, Armia, ULONGLONG);

	// statyczna funkcja sk�adowa klasy zapisuj�ca parametry zebranego zasobu przez armi�
	static bool zapisZasobu(Armia, rodzajeZasobu);
};

#endif

