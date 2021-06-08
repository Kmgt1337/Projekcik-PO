///////////////////////////////////////////////////////////////////////////////////////////////////
//																								 //
//								PROGRAM SYMULACJYJNY: WOJNY										 //
//						Projekt na przedmiot programowanie obiektowe							 //
//		Wydzia� Elektroniki Politechniki Wroc�awskiej, teleinformatyka, semestr letni 2021		 //
//						Autorzy: Kamil Gawlik, Sebastian Dorabia�a								 //
//																								 //	
///////////////////////////////////////////////////////////////////////////////////////////////////

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
		case -3: // wyst�pi� gdzie� problem z zapisem do pliku
			return -3;

		case 0: // symulacja zosta�a przeprowadzona do ko�ca prawid�owo
			std::cout << "\nNacisnij dowolny klawisz aby kontyunowac...\n";
			if (_getch())
			{
				return 0;
			}

		case 1: // reset ca�ej symulacji (tak naprawd� usuni�cie obecnej symulacji i za moment stworzenie nowej)
			delete symulacjaTest;
			break;
		}

	} while (decyzja == 1);
}
