#pragma once
#include <iostream>
#include "Abonat_Skype.h"

class Abonat_Skype_Extern: public Abonat_Skype{
    private:
        std::string tara;

    public:

        Abonat_Skype_Extern();
        Abonat_Skype_Extern(const std::string Tara, const std::string ID_skype, const std::string Nr_telefon, const int ID, const std::string Nume);
        Abonat_Skype_Extern(const std::string Tara, const Abonat_Skype ab_skype);
        Abonat_Skype_Extern(const Abonat_Skype_Extern &other);

        ~Abonat_Skype_Extern();

        void Afisare() override;
        std::string GetNume() override;

        Abonat_Skype_Extern& operator= (const Abonat_Skype_Extern& other);

        friend std::ostream& operator << (std::ostream &out, const Abonat_Skype_Extern &data);
        friend std::istream& operator >> (std::istream &in, Abonat_Skype_Extern &data);

};