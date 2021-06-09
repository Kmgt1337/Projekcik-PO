#include "Operator_bitwy.h"
#include "Mapa.h"
#include <fstream>
#include <iomanip>
#include <random>
using namespace std;

size_t Operator_bitwy::licznikBitw = 1;
float Operator_bitwy::procentowaStrataArmii1;
float Operator_bitwy::procentowaStrataArmii2;

size_t Operator_bitwy::dajLiczbeBitw()
{
    return licznikBitw;
}

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

    armia1.oddzial = &armia1.ciezkaJazda;
    armia2.oddzial = &armia2.ciezkaJazda;

    size_t minimalneObrazeniaArmii1 = static_cast<size_t>((armia1.dajLiczebnosc() + armia1.oddzial->dajModyfikator()) * 0.1);
    size_t minimalneObrazeniaArmii2 = static_cast<size_t>((armia2.dajLiczebnosc() + armia2.oddzial->dajModyfikator()) * 0.1);

    armia1.oddzial = &armia1.general;
    armia2.oddzial = &armia2.general;

    size_t maksymalneObrazeniaArmii1 = static_cast<size_t>(armia1.dajLiczebnosc() + armia1.oddzial->dajModyfikator());
    size_t maksymalneObrazeniaArmii2 = static_cast<size_t>(armia2.dajLiczebnosc() + armia2.oddzial->dajModyfikator());

    armia1.oddzial = &armia1.artyleria;
    armia2.oddzial = &armia2.artyleria;

    maksymalneObrazeniaArmii1 += armia1.oddzial->dajModyfikator();
    maksymalneObrazeniaArmii2 += armia2.oddzial->dajModyfikator();

    armia1.oddzial = &armia1.ciezkaJazda;
    armia2.oddzial = &armia2.ciezkaJazda;

    maksymalneObrazeniaArmii1 += armia1.oddzial->dajModyfikator();
    maksymalneObrazeniaArmii2 += armia2.oddzial->dajModyfikator();

    maksymalneObrazeniaArmii1 = static_cast<size_t>(maksymalneObrazeniaArmii1 * 0.2);
    maksymalneObrazeniaArmii2 = static_cast<size_t>(maksymalneObrazeniaArmii2 * 0.2);

    random_device device;
    mt19937 gen(device());
    uniform_int_distribution<size_t> losujObrazeniaDlaArmii1{ minimalneObrazeniaArmii1, maksymalneObrazeniaArmii1 };
    uniform_int_distribution<size_t> losujObrazeniaDlaArmii2{ minimalneObrazeniaArmii2, maksymalneObrazeniaArmii2 };
    uniform_int_distribution<size_t> losujBousDlaArmiiZwycieskiej{ 500, 600 };
    uniform_int_distribution<size_t> losujBonusDlaArmiiPrzegranej{ 100, 200 };
    uniform_int_distribution<size_t> losujBonusProwincji{ 1, 5 };

    size_t obrazeniaArmi1 = static_cast<size_t>(losujObrazeniaDlaArmii1(gen) * armia1.dajModyfikatorZasob());
    size_t obrazeniaArmi2 = static_cast<size_t>(losujObrazeniaDlaArmii2(gen) * armia2.dajModyfikatorZasob());
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
        armia1.oddzial = &armia1.lekarz;
        armia2.oddzial = &armia2.lekarz;

        strataArmiiZwycieskiej = obrazeniaArmi2 + bonusArmiiZwyceskiej + (bonusProwincjiArmia1 * losujBonusProwincji(gen)) + armia1.oddzial->dajModyfikator();
        strataArmiiPokonanej = obrazeniaArmi1 + bonusArmiiPokonanej + (bonusProwincjiArmia2 * losujBonusProwincji(gen)) + armia2.oddzial->dajModyfikator();

        armia1.zwiad.raport();
        armia2.zwiad.raport();

        armia1.oddzial = &armia1.zwiad;
        armia2.oddzial = &armia2.zwiad;

        strataArmiiZwycieskiej += armia2.oddzial->dajModyfikator();
        strataArmiiPokonanej += armia1.oddzial->dajModyfikator();

        armia1.oddzial = &armia1.lekkaJazda;
        armia2.oddzial = &armia2.lekkaJazda;

        strataArmiiZwycieskiej += armia1.oddzial->dajModyfikator();
        strataArmiiPokonanej += armia2.oddzial->dajModyfikator();

        if (armia1.dajLiczebnosc() - strataArmiiZwycieskiej == 0 && armia2.dajLiczebnosc() - strataArmiiPokonanej == 0)
        {
            uniform_int_distribution<size_t> losujNowaStrate{ static_cast<size_t>(armia1.dajLiczebnosc() * 0.2), static_cast<size_t>(armia1.dajLiczebnosc() * 0.8) };
            strataArmiiZwycieskiej = losujNowaStrate(gen);
            strataArmiiPokonanej = armia2.dajLiczebnosc();

            procentowaStrataArmii1 = static_cast<float>(strataArmiiZwycieskiej) / static_cast<float>(armia1.dajLiczebnosc());
            procentowaStrataArmii2 = 1.0f;

            armia1.zmienLiczebnosc(armia1.dajLiczebnosc() - strataArmiiZwycieskiej);
            armia2.zmienLiczebnosc(0);

            pom.push_back(strataArmiiZwycieskiej);
            pom.push_back(strataArmiiZwycieskiej);
            pom.push_back(1);

            return pom;
        }

        if (strataArmiiZwycieskiej >= static_cast<size_t>(armia1.dajLiczebnosc()))
        {
            procentowaStrataArmii1 = 1.0f;
            strataArmiiZwycieskiej = armia1.dajLiczebnosc();
            armia1.zmienLiczebnosc(0);
        }
        else
        {
            procentowaStrataArmii1 = static_cast<float>(strataArmiiZwycieskiej) / static_cast<float>(armia1.dajLiczebnosc());
            armia1.zmienLiczebnosc(armia1.dajLiczebnosc() - strataArmiiZwycieskiej);
        }
        
        if (strataArmiiPokonanej >= static_cast<size_t>(armia2.dajLiczebnosc()))
        {
            procentowaStrataArmii2 = 1.0f;
            strataArmiiPokonanej = armia2.dajLiczebnosc();
            armia2.zmienLiczebnosc(0);
        }
        else
        {
            procentowaStrataArmii2 = static_cast<float>(strataArmiiPokonanej) / static_cast<float>(armia2.dajLiczebnosc());
            armia2.zmienLiczebnosc(armia2.dajLiczebnosc() - strataArmiiPokonanej);
        }

        pom.push_back(strataArmiiZwycieskiej);
        pom.push_back(strataArmiiPokonanej);
    }
    else
    {
        armia1.oddzial = &armia1.lekarz;
        armia2.oddzial = &armia2.lekarz;

        strataArmiiZwycieskiej = obrazeniaArmi1 + bonusArmiiZwyceskiej + (bonusProwincjiArmia2 * losujBonusProwincji(gen)) + armia2.oddzial->dajModyfikator();
        strataArmiiPokonanej = obrazeniaArmi2 + bonusArmiiPokonanej + (bonusProwincjiArmia1 * losujBonusProwincji(gen)) + armia1.oddzial->dajModyfikator();

        armia1.zwiad.raport();
        armia2.zwiad.raport();

        armia1.oddzial = &armia1.zwiad;
        armia2.oddzial = &armia2.zwiad;

        strataArmiiZwycieskiej += armia1.oddzial->dajModyfikator();
        strataArmiiPokonanej += armia2.oddzial->dajModyfikator();

        armia1.oddzial = &armia1.lekkaJazda;
        armia2.oddzial = &armia2.lekkaJazda;

        strataArmiiZwycieskiej += armia2.oddzial->dajModyfikator();
        strataArmiiPokonanej += armia1.oddzial->dajModyfikator();

        if (armia2.dajLiczebnosc() - strataArmiiZwycieskiej == 0 && armia1.dajLiczebnosc() - strataArmiiPokonanej == 0)
        {
            uniform_int_distribution<size_t> losujNowaStrate{ static_cast<size_t>(armia2.dajLiczebnosc() * 0.2), static_cast<size_t>(armia2.dajLiczebnosc() * 0.8) };
            strataArmiiZwycieskiej = losujNowaStrate(gen);
            strataArmiiPokonanej = armia1.dajLiczebnosc();

            procentowaStrataArmii2 = static_cast<float>(strataArmiiZwycieskiej) / static_cast<float>(armia2.dajLiczebnosc());
            procentowaStrataArmii1 = 1.0f;

            armia2.zmienLiczebnosc(armia2.dajLiczebnosc() - strataArmiiZwycieskiej);
            armia1.zmienLiczebnosc(0);

            pom.push_back(strataArmiiPokonanej);
            pom.push_back(strataArmiiZwycieskiej);
            pom.push_back(2);

            return pom;
        }

        if (strataArmiiZwycieskiej >= static_cast<size_t>(armia2.dajLiczebnosc()))
        {
            procentowaStrataArmii2 = 1.0f;
            strataArmiiZwycieskiej = armia2.dajLiczebnosc();
            armia2.zmienLiczebnosc(0);
        }
        else
        {
            procentowaStrataArmii2 = static_cast<float>(strataArmiiZwycieskiej) / static_cast<float>(armia2.dajLiczebnosc());
            armia2.zmienLiczebnosc(armia2.dajLiczebnosc() - strataArmiiZwycieskiej);
        }

        if (strataArmiiPokonanej >= static_cast<size_t>(armia1.dajLiczebnosc()))
        {
            procentowaStrataArmii1 = 1.0f;
            strataArmiiPokonanej = armia1.dajLiczebnosc();
            armia1.zmienLiczebnosc(0);
        }
        else
        {
            procentowaStrataArmii1 = static_cast<float>(strataArmiiPokonanej) / static_cast<float>(armia1.dajLiczebnosc());
            armia1.zmienLiczebnosc(armia1.dajLiczebnosc() - strataArmiiPokonanej);
        }

        pom.push_back(strataArmiiPokonanej);
        pom.push_back(strataArmiiZwycieskiej);
    }

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
