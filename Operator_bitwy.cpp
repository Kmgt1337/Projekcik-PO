#include "Operator_bitwy.h"
#include <fstream>
#include <iomanip>
#include <random>
using namespace std;

size_t Operator_bitwy::licznikBitw = 1;

bool Operator_bitwy::wynik(int licz1, int licz2)
{
    if (licz1 > licz2)
    {
        return 0;
    }
    else return 1;
}

vector<size_t> Operator_bitwy::bitwa(Armia& armia1, Armia& armia2)
{
    ++licznikBitw;
    random_device device;
    mt19937 gen(device());
    uniform_int_distribution<size_t> losujStrateDlaArmiiZwycieskiej{ 100, 1000 };
    uniform_int_distribution<size_t> losujStrateDlaArmiiPokonanej{ 1000, 5000 };

    size_t strataArmiiZwycieskiej = losujStrateDlaArmiiZwycieskiej(gen);
    size_t strataArmiiPokonanej = losujStrateDlaArmiiPokonanej(gen);

    vector<size_t> pom;

    if (!(wynik(armia1.dajLiczebnosc(), armia2.dajLiczebnosc())))
    {
        if (strataArmiiZwycieskiej >= armia1.dajLiczebnosc())
        {
            strataArmiiZwycieskiej = armia1.dajLiczebnosc();
            armia1.liczebnosc = 0;
        }
        else
        {
            armia1.liczebnosc -= strataArmiiZwycieskiej;
        }

        if (strataArmiiPokonanej >= armia2.dajLiczebnosc())
        {
            strataArmiiPokonanej = armia2.dajLiczebnosc();
            armia2.liczebnosc = 0;
        }
        else
        {
            armia2.liczebnosc -= strataArmiiPokonanej;
        }

        pom.push_back(strataArmiiZwycieskiej);
        pom.push_back(strataArmiiPokonanej);
        pom.push_back(1);
  
    }
    else
    {
        if (strataArmiiPokonanej > armia1.dajLiczebnosc())
        {
            strataArmiiPokonanej = armia1.dajLiczebnosc();
            armia1.liczebnosc = 0;
        }
        else
        {
            armia1.liczebnosc -= strataArmiiPokonanej;
        }

        if (strataArmiiZwycieskiej > armia2.dajLiczebnosc())
        {
            strataArmiiZwycieskiej = armia2.dajLiczebnosc();
            armia2.liczebnosc = 0;
        }
        else
        {
            armia2.liczebnosc -= strataArmiiZwycieskiej;
        }

        pom.push_back(strataArmiiPokonanej);
        pom.push_back(strataArmiiZwycieskiej);
        pom.push_back(2);
    }

    if (armia1.liczebnosc < 0)
    {
        armia1.liczebnosc = 0;
    }
    if (armia2.liczebnosc < 0)
    {
        armia2.liczebnosc = 0;
    }

    return pom;
}

