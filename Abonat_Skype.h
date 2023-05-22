#pragma once
#include <iostream>
#include "Abonat.h"

class Abonat_Skype: public Abonat{
    protected:
        std::string id_skype;

    public:
        Abonat_Skype();
        Abonat_Skype(const std::string ID_skype, const std::string Nr_telefon, const int ID, const std::string Nume);
        Abonat_Skype(const std::string ID_skype, const Abonat& a);
        Abonat_Skype(const Abonat_Skype& other);

        virtual ~Abonat_Skype();
        void Afisare() override;
        std::string GetNume() override;
        Abonat_Skype& operator= (const Abonat_Skype &other);

        friend std::ostream& operator << (std::ostream &out, const Abonat_Skype& data);
        friend std::istream& operator >> (std::istream &in, Abonat_Skype &data);        
}; 