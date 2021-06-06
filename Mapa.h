#ifndef MAPA_H
#define MAPA_H

#include "Armia.h"
#include "Prowincja.h"
#include <vector>
#include <iostream>
#include <Windows.h>
#include <random>

using namespace std;

class Mapa
{
public:
	static  vector<vector<Prowincja>> mapa;
	static  size_t dlug;
	static  size_t szer;

	static std::vector<size_t> dajLiczbeProwincjiKazdejArmii(Armia, Armia);
	static size_t dajLiczbeProwincjiArmii(Armia);

	//static Prowincja mapa[dlug][szer];
	static void rysuj(const vector<Armia>& armie, HANDLE hOut);
	static void inicjalizuj(size_t, size_t);
	static void reset();
	static void clrscr() //nie ogarniam jak to dziala, ale ladnie czysci ekran, lepiej niz system("cls")
	{
		HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD coord = { 0, 0 };
		SetConsoleCursorPosition(hCon, coord);
		HANDLE hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO hCCI;
		GetConsoleCursorInfo(hConsoleOut, &hCCI);
		hCCI.bVisible = FALSE;
		SetConsoleCursorInfo(hConsoleOut, &hCCI);
	}
};

#endif