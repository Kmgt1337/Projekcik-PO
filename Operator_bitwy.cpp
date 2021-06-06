#include "Operator_bitwy.h"
#include "Mapa.h"
#include <fstream>
#include <iomanip>
#include <random>
using namespace std;

size_t Operator_bitwy::licznikBitw = 1;
float Operator_bitwy::procentowaStrataArmii1;
float Operator_bitwy::procentowaStrataArmii2;

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

bool Operator_bitwy::ostatniWynik(int l1, int l2)
{
    if (l1 > l2)
    {
        return 0;
    }
    if (l2 > l1)
    {
        return 1;
    }

    return 0;
}

vector<float> Operator_bitwy::dajStratyProcentoweArmii()
{
    vector<float> pom;
    pom.push_back(procentowaStrataArmii1 * 100.0f);
    pom.push_back(procentowaStrataArmii2 * 100.0f);

    return pom;
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

    uniform_int_distribution<size_t> losujBonusProwincji{ 1, 5 };

   /* size_t strataArmiiZwycieskiej = losujStrateDlaArmiiZwycieskiej(gen);
    size_t strataArmiiPokonanej = losujStrateDlaArmiiPokonanej(gen);*/

    size_t obrazeniaArmi1 = losujObrazeniaDlaArmii1(gen);
    size_t obrazeniaArmi2 = losujObrazeniaDlaArmii2(gen);
    size_t bonusArmiiZwyceskiej = losujBousDlaArmiiZwycieskiej(gen);
    size_t bonusArmiiPokonanej = losujBonusDlaArmiiPrzegranej(gen);

    size_t strataArmiiZwycieskiej;
    size_t strataArmiiPokonanej;

    vector<size_t> liczbaProwincjiKazdejArmii = Mapa::dajLiczbeProwincjiKazdejArmii(armia1, armia2);
    size_t bonusProwincjiArmia1 = liczbaProwincjiKazdejArmii.at(0);
    size_t bonusProwincjiArmia2 = liczbaProwincjiKazdejArmii.at(1);

    vector<size_t> pom;

    bool wynikBitwy = wynik();

    if (wynikBitwy == 0)
    {
        strataArmiiZwycieskiej = obrazeniaArmi2 + bonusArmiiZwyceskiej + (bonusProwincjiArmia1 * losujBonusProwincji(gen));
        strataArmiiPokonanej = obrazeniaArmi1 + bonusArmiiPokonanej + (bonusProwincjiArmia2 * losujBonusProwincji(gen));

        if (strataArmiiZwycieskiej >= armia1.dajLiczebnosc())
        {
            procentowaStrataArmii1 = 1.0f;
            strataArmiiZwycieskiej = armia1.dajLiczebnosc();
            armia1.liczebnosc = 0;
        }
        else
        {
            procentowaStrataArmii1 = static_cast<float>(strataArmiiZwycieskiej) / static_cast<float>(armia1.dajLiczebnosc());
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
            procentowaStrataArmii2 = static_cast<float>(strataArmiiPokonanej) / static_cast<float>(armia2.dajLiczebnosc());
            armia2.liczebnosc -= strataArmiiPokonanej;
        }

        pom.push_back(strataArmiiZwycieskiej);
        pom.push_back(strataArmiiPokonanej);
    }
    else
    {
        strataArmiiZwycieskiej = obrazeniaArmi1 + bonusArmiiZwyceskiej + (bonusProwincjiArmia2 * losujBonusProwincji(gen));
        strataArmiiPokonanej = obrazeniaArmi2 + bonusArmiiPokonanej + (bonusProwincjiArmia1 * losujBonusProwincji(gen));

        if (strataArmiiZwycieskiej >= armia2.dajLiczebnosc())
        {
            procentowaStrataArmii2 = 1.0f;
            strataArmiiZwycieskiej = armia2.dajLiczebnosc();
            armia2.liczebnosc = 0;
        }
        else
        {
            procentowaStrataArmii2 = static_cast<float>(strataArmiiZwycieskiej) / static_cast<float>(armia2.dajLiczebnosc());
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
            procentowaStrataArmii1 = static_cast<float>(strataArmiiPokonanej) / static_cast<float>(armia1.dajLiczebnosc());
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
}

vector<size_t> Operator_bitwy::ostatniaBitwa(Armia& armia1, Armia& armia2)
{
    vector<size_t> pom;
    bool wynikBitwy = ostatniWynik(armia1.dajLiczebnosc(), armia2.dajLiczebnosc());

    size_t strataArmiiWygranej;
    size_t strataArmiiPrzegranej;

    if (armia1.dajLiczebnosc() > armia2.dajLiczebnosc())
    {
        strataArmiiWygranej = armia1.dajLiczebnosc() * 0.8;
        
        pom.push_back(strataArmiiWygranej);
        pom.push_back(armia2.dajLiczebnosc());
        pom.push_back(1);

        procentowaStrataArmii1 = static_cast<float>(strataArmiiWygranej / static_cast<float>(armia1.dajLiczebnosc()));
        procentowaStrataArmii2 = 1.0f;

        armia1.liczebnosc -= strataArmiiWygranej;
        armia2.liczebnosc = 0;
    }
    else
    {
        strataArmiiWygranej = armia2.dajLiczebnosc() * 0.8;
        pom.push_back(armia1.dajLiczebnosc());
        pom.push_back(strataArmiiWygranej);
        pom.push_back(2);

        procentowaStrataArmii1 = 1.0f;
        procentowaStrataArmii2 = static_cast<float>(strataArmiiWygranej / static_cast<float>(armia2.dajLiczebnosc()));

        armia1.liczebnosc = 0;
        armia2.liczebnosc -= strataArmiiWygranej;
    }

    return pom;
}

