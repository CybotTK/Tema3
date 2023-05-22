#pragma once
#include <iostream>
#include "Persoana.h"

class Abonat: public Persoana{
    protected:
        std::string nr_telefon;
    
    public:
        Abonat();
        Abonat(const std::string Nr_telefon, const int ID, const std::string Nume);
        Abonat(const std::string Nr_telefon, const Persoana &p);
        Abonat(const Abonat &other);
        virtual ~Abonat();
        virtual void Afisare();
        virtual std::string GetNume();

        Abonat& operator= (const Abonat &other);

        friend std::ostream& operator << (std::ostream& out, const Abonat& data);
        friend std::istream& operator >> (std::istream& in, Abonat& data);
};