#ifndef MAPA_H
#define MAPA_H

#include "Armia.h"
#include "Prowincja.h"
#include <vector>
#include <iostream>
#include <Windows.h>
#include <random>

class Mapa
{
public:
	static constexpr size_t dlug = 30;
	static constexpr size_t szer = 60;
	static void grafika();
	static void rysuj(const std::vector<Armia>& armie, HANDLE hOut);

private:

	static Prowincja mapa[dlug][szer];

	static void clrscr() //nie ogarniam jak to dziala, ale ladnie czysci ekran, lepiej niz system("cls")
	{
		HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD coord = { 0, 0 };
		SetConsoleCursorPosition(hCon, coord);
		::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
		::CONSOLE_CURSOR_INFO hCCI;
		::GetConsoleCursorInfo(hConsoleOut, &hCCI);
		hCCI.bVisible = FALSE;
		::SetConsoleCursorInfo(hConsoleOut, &hCCI);
	}
};

#endif