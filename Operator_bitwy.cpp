#include "Operator_bitwy.h"
#include <fstream>
#include <iomanip>
#include <random>
using namespace std;

size_t Operator_bitwy::licznikBitw = 1;

bool Operator_bitwy::wynik()
{
    random_device device;
    mt19937 gen(device());
    uniform_int_distribution<size_t> losujArmieZwycieska{ 1, 2 };
    size_t pom = losujArmieZwycieska(gen);

    switch (pom)
    {
    case 1:
        return 0;

    case 2:
        return 1;
    }
}

vector<size_t> Operator_bitwy::bitwa(Armia& armia1, Armia& armia2)
{
    ++licznikBitw;
    random_device device;
    mt19937 gen(device());
    /*uniform_int_distribution<size_t> losujStrateDlaArmiiZwycieskiej{ 100, 1000 };
    uniform_int_distribution<size_t> losujStrateDlaArmiiPokonanej{ 1000, 5000 };*/

    uniform_int_distribution<size_t> losujObrazeniaDlaArmii1{ static_cast<size_t>(armia1.dajLiczebnosc() * 0.1), static_cast<size_t>(armia1.dajLiczebnosc() * 0.3 + armia1.dajModObrazenia()) };
    uniform_int_distribution<size_t> losujObrazeniaDlaArmii2{ static_cast<size_t>(armia2.dajLiczebnosc() * 0.1), static_cast<size_t>(armia2.dajLiczebnosc() * 0.3 + armia2.dajModObrazenia()) };

    uniform_int_distribution<size_t> losujBousDlaArmiiZwycieskiej{ 900, 1000 };
    uniform_int_distribution<size_t> losujBonusDlaArmiiPrzegranej{ 100, 200 };

   /* size_t strataArmiiZwycieskiej = losujStrateDlaArmiiZwycieskiej(gen);
    size_t strataArmiiPokonanej = losujStrateDlaArmiiPokonanej(gen);*/

    size_t obrazeniaArmi1 = losujObrazeniaDlaArmii1(gen);
    size_t obrazeniaArmi2 = losujObrazeniaDlaArmii2(gen);
    size_t bonusArmiiZwyceskiej = losujBousDlaArmiiZwycieskiej(gen);
    size_t bonusArmiiPokonanej = losujBonusDlaArmiiPrzegranej(gen);

    size_t strataArmiiZwycieskiej;
    size_t strataArmiiPokonanej;

    float procentowaStrataArmii1 = 0.0f;
    float procentowaStrataArmii2 = 0.0f;
    
    vector<size_t> pom;

    bool wynikBitwy = wynik();

    if (wynikBitwy == 0)
    {
        strataArmiiZwycieskiej = obrazeniaArmi2 + bonusArmiiZwyceskiej;
        strataArmiiPokonanej = obrazeniaArmi1 + bonusArmiiPokonanej;

        if (strataArmiiZwycieskiej >= armia1.dajLiczebnosc())
        {
            procentowaStrataArmii1 = 1.0f;
            strataArmiiZwycieskiej = armia1.dajLiczebnosc();
            armia1.liczebnosc = 0;
        }
        else
        {
            procentowaStrataArmii1 = strataArmiiZwycieskiej / armia1.dajLiczebnosc();
            armia1.liczebnosc -= strataArmiiZwycieskiej;
        }
        
        if (strataArmiiPokonanej >= armia2.dajLiczebnosc())
        {
            procentowaStrataArmii2 = 1.0f;
            strataArmiiPokonanej = armia2.dajLiczebnosc();
            armia2.liczebnosc = 0;
        }
        else
        {
            procentowaStrataArmii2 = strataArmiiPokonanej / armia2.dajLiczebnosc();
            armia2.liczebnosc -= strataArmiiPokonanej;
        }

        pom.push_back(strataArmiiZwycieskiej);
        pom.push_back(strataArmiiPokonanej);
    }
    else
    {
        strataArmiiZwycieskiej = obrazeniaArmi1 + bonusArmiiZwyceskiej;
        strataArmiiPokonanej = obrazeniaArmi2 + bonusArmiiPokonanej;

        if (strataArmiiZwycieskiej >= armia2.dajLiczebnosc())
        {
            procentowaStrataArmii2 = 1.0f;
            strataArmiiZwycieskiej = armia2.dajLiczebnosc();
            armia2.liczebnosc = 0;
        }
        else
        {
            procentowaStrataArmii2 = strataArmiiZwycieskiej / armia2.dajLiczebnosc();
            armia2.liczebnosc -= strataArmiiZwycieskiej;
        }

        if (strataArmiiPokonanej >= armia1.dajLiczebnosc())
        {
            procentowaStrataArmii1 = 1.0f;
            strataArmiiPokonanej = armia1.dajLiczebnosc();
            armia1.liczebnosc = 0;
        }
        else
        {
            procentowaStrataArmii1 = strataArmiiPokonanej / armia1.dajLiczebnosc();
            armia1.liczebnosc -= strataArmiiPokonanej;
        }

        pom.push_back(strataArmiiPokonanej);
        pom.push_back(strataArmiiZwycieskiej);
    }

    // ta liczba w push_backu bedzie potrzebna przy zapisie do pliku, dzieki niej wiadomo ktora armia wygrala
    if (procentowaStrataArmii1 > procentowaStrataArmii2)
    {
        pom.push_back(2);
    }
    else if (procentowaStrataArmii2 > procentowaStrataArmii1)
    {
        pom.push_back(1);
    }
    else if (procentowaStrataArmii1 == procentowaStrataArmii2)
    {
        if (armia1.dajLiczebnosc() > armia2.dajLiczebnosc())
        {
            pom.push_back(1);
        }
        else
        {
            pom.push_back(2);
        }
    }

    return pom;

   /* if (!(wynik()))
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
    
    return pom;

    */
}

