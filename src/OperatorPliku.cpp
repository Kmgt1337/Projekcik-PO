#include "OperatorPliku.h"
#include "Zegar.h"
#include "Mapa.h"
#include "Operator_bitwy.h"
#include "OperatorZakonczenia.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;

bool OperatorPliku::zapis(const std::vector<Armia>& armie)
{
	fstream plik;
	plik.open("wynik.txt", ios::app);
	if (plik.fail()) return false;

	plik << " Tura nr " << Zegar::dajObecnaTure() << "\t";
	for (auto armia : armie)
	{
		if (armia.dajLiczebnosc() > 0)
		{
			plik << setw(10) << armia.dajNazwe() << ":["
				<< armia.dajPozycjeX() << ","
				<< armia.dajPozycjeY() << ","
				<< armia.dajLiczebnosc() << ","
				<< armia.dajPrzyna() << ",";

			plik << Mapa::dajLiczbeProwincjiArmii(armia);
			plik << "]\t";
		}
		else
		{
			plik << setw(10) << armia.dajNazwe() << ":["
				<< "armia wyeliminowana]\t";
		}
	}
	plik << endl;
	plik.close();
	return true;
}

bool OperatorPliku::zapisPrzedBitwa(Armia armia1, Armia armia2)
{
	fstream plik;
	plik.open("wynik.txt", ios::app);
	if (plik.fail()) return false;

	plik << endl;
	plik << "=============================== ";
	plik << "BITWA nr " << Operator_bitwy::dajLiczbeBitw() << ", pomi�dzy " << armia1.dajNazwe() << " a " << armia2.dajNazwe() << endl;
	plik.close();
	return true;
}

bool OperatorPliku::zapisBitwy(Armia armia1, Armia armia2, vector<size_t> zmianaHP, vector<float> procentoweStraty)
{
	fstream plik;
	plik.open("wynik.txt", ios::app);
	if (plik.fail()) return false;

	if (zmianaHP.at(2) == 1)
	{
		plik << "Wygra�a " << armia1.dajNazwe() << endl;
	}
	if (zmianaHP.at(2) == 2)
	{
		plik << "Wygra�a " << armia2.dajNazwe() << endl;
	}
	plik << armia1.dajNazwe() << " straci�a " << zmianaHP.at(0) << " �o�nierzy" << endl;
	plik << armia2.dajNazwe() << " straci�a " << zmianaHP.at(1) << " �o�nierzy" << endl;
	plik << endl;
	plik << "Procenowa strata " << armia1.dajNazwe() << ": " << setprecision(4) << procentoweStraty.at(0) << endl;
	plik << "Procenowa strata " << armia2.dajNazwe() << ": " << setprecision(4) << procentoweStraty.at(1) << endl;
	plik << "===============================" << endl << endl;
	plik.close();
	return true;
}

bool OperatorPliku::ostatniZapis(Armia armia, ULONGLONG czas)
{
	fstream plik;
	plik.open("wynik.txt", ios::app);
	if (plik.fail()) return false;

	plik << endl << endl;
	plik << setw(50) << setfill('=') << endl;
	plik << "WYGRALA " << armia.dajNazwe() << endl;
	plik << setw(50) << setfill('=') << endl;
	plik << "Czas trwania symulacji: " << czas << " milisekund" << endl;
	plik.close();
	return true;
}

bool OperatorPliku::zapisPrzedSymulacja(const std::vector<Armia>& armie)
{
	fstream plik;
	plik.open("wynik.txt", ios::app);
	if (plik.fail()) return false;

	plik << "=====PROGRAM SYMULACYJNY: WOJNY====" << endl;
	plik << "Autorzy: Kamil Gawlik, Sebastian Dorabia�a" << endl << endl;
	plik << "Parametry przed rozpocz�ciem symulacji: " << endl << endl;
	
	auto start = std::chrono::system_clock::now();
	auto czasUruchomieniaSymulacji = std::chrono::system_clock::to_time_t(start);
	char buffer[30];
	ctime_s(buffer, sizeof(buffer), &czasUruchomieniaSymulacji);

	plik << "Data i czas uruchomienia symulacji: " << buffer << endl;
	
	plik << "Rozmiar mapy:[" << Mapa::szer << " x " << Mapa::dlug << "]" << endl << endl;
	
	for (auto armia : armie)
	{
		plik << armia.dajNazwe() << ":["
			<< armia.dajPozycjeX() << ","
			<< armia.dajPozycjeY() << ","
			<< armia.dajLiczebnosc() << ","
			<< armia.dajPrzyna() << ","
			<< "0]"
			<< "    <---- gdzie: [pozycja X armii, pozycja Y armii, liczba �o�nierzy, przynale�no�� armii, liczba przej�tych prowincji]" << endl;
	}

	plik << endl << endl;
	plik << setw(50) << setfill('=') << "SYMULACJA";
	plik << endl << endl;
	plik.close();
	return true;
}

bool OperatorPliku::ostatniZapisTury(const std::vector<Armia>& armie, Armia armiaZwycieska, ULONGLONG czas)
{
	fstream plik;
	plik.open("wynik.txt", ios::app);
	if (plik.fail()) return false;

	plik << endl << endl;
	plik << setw(50) << setfill('=') << endl;
	plik << "Zosta� osi�gni�ty limit tur, kt�ry wynosi " << OperatorZakonczenia::dajMaxTure() << endl;
	plik << "Liczba prowincji ka�dej armii: " << endl;
	for (auto armia : armie)
	{
		plik << armia.dajNazwe() << ": " << Mapa::dajLiczbeProwincjiArmii(armia) << endl;
	}
	plik << endl;
	plik << "Armia zwyci�ska: " << armiaZwycieska.dajNazwe() << ", jej liczba prowincji: " << Mapa::dajLiczbeProwincjiArmii(armiaZwycieska) << endl;
	plik << setw(50) << setfill('=') << endl;
	plik << "Czas trwania symulacji: " << czas << " milisekund" << endl;
	plik.close();
	return true;
}

bool OperatorPliku::zapisZasobu(Armia armia, rodzajeZasobu zasob)
{
	fstream plik;
	plik.open("wynik.txt", ios::app);
	if (plik.fail()) return false;

	plik << endl;
	plik << "=============================== ";
	plik << armia.dajNazwe() << " zebra�a zas�b";
	switch (zasob)
	{
	case rodzajeZasobu::LICZEBNOSC5:
		plik << " - zwi�kszenie liczebno�ci o 5%" << endl;
		break;

	case rodzajeZasobu::LICZEBNOSC10:
		plik << " - zwi�kszenie liczebno�ci o 10%" << endl;
		break;

	case rodzajeZasobu::LICZEBNOSC15:
		plik << " - zwi�kszenie liczebno�ci o 15%" << endl;
		break;

	case rodzajeZasobu::OBRAZENIA5:
		plik << " - zwi�kszenie obra�e� o 5%" << endl;
		break;

	case rodzajeZasobu::OBRAZENIA10:
		plik << " - zwi�kszenie obra�e� o 10%" << endl;
		break;

	case rodzajeZasobu::OBRAZENIA15:
		plik << " - zwi�kszenie obra�e� o 15%" << endl;
		break;
	}

	plik << endl << endl;
	plik.close();
	return true;
}
