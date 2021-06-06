#include <conio.h>
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
			cout << "\nNacisnij dowolny klawisz aby kontyunowac...\n";
			if (_getch())
			{
				return -3;
			}

		case 0: // symulacja zostala przeprowadzona do konca prawidlowo
			cout << "\nNacisnij dowolny klawisz aby kontyunowac...\n";
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
