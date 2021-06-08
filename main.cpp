// projekt na przedmiot programowanie obiektowe, Wydzia³ Elektroniki Politechniki Wroc³awskiej, teleinformatyka, semestr letni 2021
// autorzy: Kamil Gawlik, Sebastian Dorabia³a

#include "OperatorSymulacji.h"

int main()
{
	int decyzja;

	do
	{
		OperatorSymulacji* symulacjaTest = new OperatorSymulacji;
		if(!symulacjaTest->zainicjalizujSymulacje()) return -3;

		switch (decyzja = symulacjaTest->prowadzSymulacje())
		{
		case -3: // wystapil gdzies problem z zapisem do pliku
			return -3;

		case 0: // symulacja zostala przeprowadzona do konca prawidlowo
			std::cout << "\nNacisnij dowolny klawisz aby kontyunowac...\n";
			if (_getch())
			{
				return 0;
			}

		case 1: // reset calej symulacji (tak naprawde usuniecie obecnej symulacji i za moment stworzenie nowej)
			delete symulacjaTest;
			break;
		}

	} while (decyzja == 1);
}
