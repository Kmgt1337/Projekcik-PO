#ifndef ZEGAR_H
#define ZEGAR_H

class Zegar
{
private:
	int tura;
	int tura_koncowa;
	void odliczanie();
public:
	bool koniec;
	void start();
	void stop();
};
#endif

