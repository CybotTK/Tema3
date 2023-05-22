#pragma once
#include <iostream>
#include "Abonat_Skype.h"

class Abonat_Skype_Romania: public Abonat_Skype{
    protected:
        std::string adresa_mail;

    public:
        Abonat_Skype_Romania();
        Abonat_Skype_Romania(const std::string Adresa_mail, const std::string ID_skype, const std::string Nr_telefon, const int ID, const std::string Nume);
        Abonat_Skype_Romania(const std::string Adresa_mail, const Abonat_Skype ab_skype);
        Abonat_Skype_Romania(const Abonat_Skype_Romania &other);

        ~Abonat_Skype_Romania();

        void Afisare() override;
        std::string GetNume() override;

        Abonat_Skype_Romania& operator= (const Abonat_Skype_Romania& other);

        friend std::ostream& operator << (std::ostream &out, const Abonat_Skype_Romania &data);
        friend std::istream& operator >> (std::istream &in, Abonat_Skype_Romania &data);
};