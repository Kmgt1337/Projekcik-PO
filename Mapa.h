#ifndef MAPA_H
#define MAPA_H

#include "Armia.h"
#include <vector>
#include <Windows.h>

class Mapa
{
public:
	static void grafika();
	static void rysujArmie(const std::vector<Armia>& armie); // wysylamy do funkcji wszystkie istniejace armie

private:
	static constexpr size_t dlug = 30;
	static constexpr size_t szer = 60;

	static char mapa[dlug][szer];

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

