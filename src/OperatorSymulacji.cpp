#include "OperatorSymulacji.h"
#include "OperatorZakonczenia.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#undef max

using namespace std;

bool OperatorSymulacji::zainicjalizujSymulacje()
{
	Mapa::reset();
	Zegar::start();

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 15);

	size_t maxtura;
	cout << "Podaj maksymalna liczbe tur w symulacji [minimum 1000, maksimum 10000]: ";
	cin >> maxtura;
	while (cin.fail() || maxtura < 1000 || maxtura > 10000)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Wprowadziles zle dane wejsciowe, wprowadz jeszcze raz: ";
		cin >> maxtura;
	}
	OperatorZakonczenia::ustawMaksymalnyLimitTur(maxtura);

	size_t x, y;
	cout << "Podaj rozmiar x mapy [minimum " << minimum << ", maksymalnie " << maksimumX << "]: ";
	cin >> x;
	while (cin.fail() || x < minimum || x > maksimumX)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Wprowadziles zle dane wejsciowe, wprowadz jeszcze raz: ";
		cin >> x;
	}

	cout << "Podaj rozmiar y mapy [minimum " << minimum << ", maksymalnie " << maksimumY << "]: ";
	cin >> y;
	while (cin.fail() || y < minimum || y > maksimumY)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Wprowadziles zle dane wejsciowe, wprowadz jeszcze raz: ";
		cin >> y;
	}

	Mapa::inicjalizuj(x, y);
	Armia::inicjalizuj(x, y);

	fstream plik;
	if (plik.is_open()) plik.close();

	plik.open("wynik.txt", ios::out | ios::trunc);
	plik.clear();
	if (plik.good())
	{
		plik << "";
		plik.flush();
		plik.close();
	}
	else
	{
		return false;
	}

	for (int i = 1; i <= 10; i++)
	{
		size_t pomX, pomY;
		string nazwa;
		size_t liczebnosc;

		cout << "\n========\n";
		cout << "Dane armii nr " << i << endl;
		cout << "Podaj pozycje poczatkowa x armii: ";
		cin >> pomX;
		while (cin.fail() || pomX < 0 || pomX >= x)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Wprowadziles zle dane wejsciowe, wprowadz jeszcze raz: ";
			cin >> pomX;
		}
		cout << "Podaj pozycje poczatkowa y armii: ";
		cin >> pomY;
		while (cin.fail() || pomY < 0 || pomY >= y)
		{
			cin.ignore(std::numeric_limits < streamsize >::max(), '\n');
			cout << "Wprowadziles zle dane wejsciowe, wprowadz jeszcze raz: ";
			cin >> pomY;
		}

		cout << "Podaj liczbe zolnierzy w armii [minimalne 10000, maksymalnie 100000]: ";
		cin >> liczebnosc;
		while (cin.fail() || liczebnosc < 10000 || liczebnosc > 100000)
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Wprowadziles zle dane wejsciowe, wprowadz jeszcze raz: ";
			cin >> liczebnosc;
		}

		cin.ignore(std::numeric_limits < streamsize >::max(), '\n');
		cout << "Podaj nazwe dla armii: ";
		getline(cin, nazwa);

		armie.push_back({ i, pomX, pomY, 'X', i, nazwa, liczebnosc });

		if (i >= 2 && i < 10)
		{
			cout << "\nCzy chcesz dodac kolejna armie? [tak - nacisnij dowolny klawisz, nie - nacisnij 'enter']: ";
			if (_getch() == 13)
			{
				break;
			}
		}
	}

	Mapa::clrscr();
	system("cls");
	czySymulacjaJestAktywna = true;
	return true;
}

int OperatorSymulacji::prowadzSymulacje()
{
	size_t pom = 0;
	bool operZakonczenia = false;

	if (!OperatorPliku::zapisPrzedSymulacja(armie)) return -3;
	Zegar::zacznijOdmierzacCzas();

	while (czySymulacjaJestAktywna)
	{
		pom = 0;

		if (_kbhit())
		{
			switch (_getch())
			{
			case 'r':
				Mapa::clrscr();
				system("cls");
				return 1;

			case 'p':
				while (!_kbhit());
				czasTrwaniaPrzerwy = Zegar::dajCzasWykonaniaSymulacjiMiliSekundy();
				break;
			}
		}
		if (OperatorZakonczenia::sprawdzCzySymulacjaSieZakonczylaArmie(armie))
		{
			armiaZwycieska = OperatorZakonczenia::pokazArmieZwycieska(armie);

			operZakonczenia = false;
			czySymulacjaJestAktywna = false;
			break;
		}
		if (OperatorZakonczenia::sprawdzCzySymulacjaSieZakonczylaTury())
		{
			armiaZwycieska = OperatorZakonczenia::pokazArmieZwycieska(armie);

			operZakonczenia = true;
			czySymulacjaJestAktywna = false;
			break;
		}

		Zegar::nowaTura();
		Mapa::rysuj(armie, hOut);
		for (auto& armia : armie)
		{
			int id2 = armia.ruch();

			if (armia.dajLiczebnosc() > 0)
			{
				if (Mapa::mapa[armia.dajPozycjeX()][armia.dajPozycjeY()].zasobProwincji.dajRodzajZasobu() == rodzajeZasobu::LICZEBNOSC5 ||
					Mapa::mapa[armia.dajPozycjeX()][armia.dajPozycjeY()].zasobProwincji.dajRodzajZasobu() == rodzajeZasobu::LICZEBNOSC10 ||
					Mapa::mapa[armia.dajPozycjeX()][armia.dajPozycjeY()].zasobProwincji.dajRodzajZasobu() == rodzajeZasobu::LICZEBNOSC15 ||
					Mapa::mapa[armia.dajPozycjeX()][armia.dajPozycjeY()].zasobProwincji.dajRodzajZasobu() == rodzajeZasobu::OBRAZENIA5 ||
					Mapa::mapa[armia.dajPozycjeX()][armia.dajPozycjeY()].zasobProwincji.dajRodzajZasobu() == rodzajeZasobu::OBRAZENIA10 ||
					Mapa::mapa[armia.dajPozycjeX()][armia.dajPozycjeY()].zasobProwincji.dajRodzajZasobu() == rodzajeZasobu::OBRAZENIA15)
				{
					if (Mapa::mapa[armia.dajPozycjeX()][armia.dajPozycjeY()].zasobProwincji.dajAktywnoscZasobu() == true)
					{
						armia.zbierzZasob(Mapa::mapa[armia.dajPozycjeX()][armia.dajPozycjeY()].zasobProwincji.dajRodzajZasobu());
						OperatorPliku::zapisZasobu(armia, Mapa::mapa[armia.dajPozycjeX()][armia.dajPozycjeY()].zasobProwincji.dajRodzajZasobu());

						Mapa::mapa[armia.dajPozycjeX()][armia.dajPozycjeY()].zasobProwincji.zmienAktywnoscZasobuNa(false);
					}
				}
			}

			if (id2 != 0)
			{
				if (armia.dajLiczebnosc() == 0)
				{
					armia.zmienAktywnosc(0);
					for (size_t i = 0; i < Mapa::dlug; i++)
					{
						for (size_t j = 0; j < Mapa::szer; j++)
							if (Mapa::mapa[i][j].dajPrzynaleznosc() == armia.dajPrzyna())
							{
								Mapa::mapa[i][j].zmienPrzynaleznosc(0);
							}
					}
				}
				if (armie[id2 - 1].dajLiczebnosc() == 0)
				{
					// armia.aktywna = 0; <--- zle, powodowalo blad ktory uniemozliwial zakonczenie symulacji
					armie[id2 - 1].zmienAktywnosc(0); // ma byc tak
					for (size_t i = 0; i < Mapa::dlug; i++)
					{
						for (size_t j = 0; j < Mapa::szer; j++)
							if (Mapa::mapa[i][j].dajPrzynaleznosc() == armie[id2 - 1].dajPrzyna())
							{
								Mapa::mapa[i][j].zmienPrzynaleznosc(0);
							}
					}
				}

				if (armia.dajLiczebnosc() > 0 && armie[id2 - 1].dajLiczebnosc() > 0)
				{
					if (!OperatorPliku::zapisPrzedBitwa(armia, armie[id2 - 1])) return -3;
					zmianaLiczebnosci = Operator_bitwy::bitwa(armia, armie[id2 - 1]);
					if (!OperatorPliku::zapisBitwy(armia, armie[id2 - 1], zmianaLiczebnosci, Operator_bitwy::dajStratyProcentoweArmii())) return -3;
				}
			}
			id2 = 0;
		}
		if (!OperatorPliku::zapis(armie)) return -3;
	}

	if (!czasTrwaniaPrzerwy)
	{
		czasTrwaniaSymulacji = Zegar::dajCzasWykonaniaSymulacjiMiliSekundy();
	}
	else
	{
		czasTrwaniaSymulacji = Zegar::dajCzasWykonaniaSymulacjiMiliSekundy();
		czasTrwaniaSymulacji -= czasTrwaniaPrzerwy;
	}

	if (operZakonczenia)
	{
		if (!OperatorPliku::ostatniZapisTury(armie, armiaZwycieska, czasTrwaniaSymulacji)) return -3;
	}
	else
	{
		if (!OperatorPliku::ostatniZapis(armiaZwycieska, czasTrwaniaSymulacji)) return -3;
	}

	system("cls");
	cout << "Symulacja zakonczona pomyslnie" << endl;
	cout << "Pomyslnie zapisano parametry symulacji do pliku tekstowego" << endl;

	return 0;
}
