#include "Mapa.h"
#include <random>
#include <iostream>

void Mapa::grafika()
{
	constexpr size_t dlug = 25;
	constexpr size_t szer = 50;

	char mapa[dlug][szer];

	for (int i = 0; i < dlug; i++)
		for (int j = 0; j < szer; j++)
			mapa[i][j] = ' ';

	for (int i = 10; i < 15; i++)
		for (int j = 10; j < 15; j++)
			mapa[i][j] = 'X';

	std::random_device seed;
	std::mt19937 gen(seed());
	std::uniform_int_distribution<size_t> losuj_dlug{ 10, dlug - 1 };
	std::uniform_int_distribution<size_t> losuj_szer{ 20, szer - 1 };

	for (int i = 0; i < 5; i++)
		mapa[losuj_dlug(gen)][losuj_szer(gen)] = '#';

	std::cout << "|";
	for (int i = 0; i < szer; i++)
		std::cout << "=";
	std::cout << "|" << std::endl;

	for (int i = 0; i < dlug; i++)
	{
		std::cout << "|";
		for (int j = 0; j < szer; j++)
		{
			std::cout << mapa[i][j];
		}
		std::cout << "|" << std::endl;
	}

	std::cout << "|";
	for (int i = 0; i < szer; i++)
		std::cout << "=";
	std::cout << "|";
}