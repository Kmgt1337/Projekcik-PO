#include "OperatorSymulacji.h"
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <conio.h>
#undef max

using namespace std;

bool OperatorSymulacji::zainicjalizujSymulacje()
{
	Mapa::reset();
	Zegar::start();

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, 15);
	size_t x, y;

	cout << "Podaj rozmiar x mapy [minimum " << minimum << ", maksymalnie " << maksimumX << "]: ";
	cin >> x;
	while (cin.fail() || x < minimum || x > maksimumX)
	{
		cin.clear();
		cin.ignore();
		cout << "Wprowadziles zle dane wejsciowe, wprowadz jeszcze raz: ";
		cin >> x;
	}

	cout << "Podaj rozmiar y mapy [minimum " << minimum << ", maksymalnie " << maksimumY << "]: ";
	cin >> y;
	while (cin.fail() || y < minimum || y > maksimumY)
	{
		cin.clear();
		cin.ignore();
		cout << "Wprowadziles zle dane wejsciowe, wprowadz jeszcze raz: ";
		cin >> y;
	}

	Mapa::inicjalizuj(x, y);
	Armia::inicjalizuj(x, y);

	fstream plik;
	if (plik.is_open()) plik.close();

	plik.open("baza.txt", ios::out | ios::trunc);
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

	for (int i = 1; i < 4; i++)
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
			cin.ignore(std::numeric_limits < streamsize >::max(), '\n');
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

		cout << "Podaj liczbe zolnierzy w armii [maksymalnie 100000]: ";
		cin >> liczebnosc;
		while (cin.fail() || liczebnosc <= 0 || liczebnosc > 100000)
		{
			cin.ignore(std::numeric_limits < streamsize >::max(), '\n');
			cout << "Wprowadziles zle dane wejsciowe, wprowadz jeszcze raz: ";
			cin >> liczebnosc;
		}

		cin.ignore(std::numeric_limits < streamsize >::max(), '\n');
		cout << "Podaj nazwe dla armii: ";
		getline(cin, nazwa);

		armie.push_back({ i, pomX, pomY, 'X', i, nazwa, liczebnosc });

		if (i >= 2)
		{
			size_t pom;
			cout << "\nCzy chcesz dodac kolejna armie? [tak - wpisz 1, nie - wpisz 0]: ";
			cin >> pom;
			if (pom == 0) break;
		}
	}

	Mapa::clrscr();
	system("cls");
	czySymulacjaJestAktywna = true;
	return true;
}

int OperatorSymulacji::prowadzSymulacje()
{
	char znak;

	if(!zapisywacz->zapisPrzedSymulacja(armie)) return -3;
	Zegar::zacznijOdmierzacCzas();

	while (czySymulacjaJestAktywna)
	{
		if (_kbhit())
		{
			znak = _getch();
			if (znak == 'r' || znak == 'R')
			{
				Mapa::clrscr();
				system("cls");
				return 1;
			}
		}
		if (Zegar::sprawdzCzySymulacjaSieZakonczyla(armie))
		{
			armiaZwycieska = Zegar::pokazArmieZwycieska(armie);
			czySymulacjaJestAktywna = false;
			break;
		}

		Zegar::nowaTura();
		for (auto& armia : armie)
		{
			int id2 = armia.ruch();
			if (id2 != 0)
			{
				if (armia.dajLiczebnosc() == 0)
				{
					armia.aktywna = 0;
					for (size_t i = 0; i < Mapa::dlug; i++)
					{
						for (size_t j = 0; j < Mapa::szer; j++)
							if (Mapa::mapa[i][j].przynaleznosc == armia.dajPrzyna())
							{
								Mapa::mapa[i][j].przynaleznosc = 0;
							}
					}
				}
				if (armie[id2 - 1].dajLiczebnosc() == 0)
				{
					armia.aktywna = 0;
					for (size_t i = 0; i < Mapa::dlug; i++)
					{
						for (size_t j = 0; j < Mapa::szer; j++)
							if (Mapa::mapa[i][j].przynaleznosc == armie[id2 - 1].dajPrzyna())
							{
								Mapa::mapa[i][j].przynaleznosc = 0;
							}
					}
				}
				if (armia.dajLiczebnosc() > 0 && armie[id2 - 1].dajLiczebnosc() > 0)
				{
					if (!zapisywacz->zapisPrzedBitwa(armia, armie[id2 - 1])) return -3;
					zmianaLiczebnosci = Operator_bitwy::bitwa(armia, armie[id2 - 1]);
					if (!zapisywacz->zapisBitwy(armia, armie[id2 - 1], zmianaLiczebnosci)) return -3;
				}
			}
			id2 = 0;
		}
		Mapa::rysuj(armie, hOut);
		if (!zapisywacz->zapis(armie)) return -3;
	}

	czasTrwaniaSymulacji = Zegar::dajCzasWykonaniaSymulacjiMiliSekundy();
	if (!zapisywacz->ostatniZapis(armiaZwycieska, czasTrwaniaSymulacji)) return -3;

	system("cls");
	std::cout << "Armia zwycieska to: " << armiaZwycieska.dajNazwe() << endl;

	return 0;
}

