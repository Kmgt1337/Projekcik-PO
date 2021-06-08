///////////////////////////////////////////////////////////////////////////////////////////////////
//																								 //
//								PROGRAM SYMULACJYJNY: WOJNY										 //
//						Projekt na przedmiot programowanie obiektowe							 //
//		Wydzia³ Elektroniki Politechniki Wroc³awskiej, teleinformatyka, semestr letni 2021		 //
//						Autorzy: Kamil Gawlik, Sebastian Dorabia³a								 //
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
		case -3: // wyst¹pi³ gdzieœ problem z zapisem do pliku
			return -3;

		case 0: // symulacja zosta³a przeprowadzona do koñca prawid³owo
			std::cout << "\nNacisnij dowolny klawisz aby kontyunowac...\n";
			if (_getch())
			{
				return 0;
			}

		case 1: // reset ca³ej symulacji (tak naprawdê usuniêcie obecnej symulacji i za moment stworzenie nowej)
			delete symulacjaTest;
			break;
		}

	} while (decyzja == 1);
}
