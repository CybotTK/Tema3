#pragma once
#include <iostream>
#include "Persoana.h"

class Abonat: public Persoana{
    protected:
        std::string nr_telefon;
    
    friend class abonat_builder;

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

class abonat_builder{
    protected:
        Abonat ab;
    
    public:
        abonat_builder()=default;
        abonat_builder& setNrTelefon(const std:: string nrtelefon)
        { ab.nr_telefon=nrtelefon;
          return *this;
        }

        abonat_builder& setID(int ID)
        { ab.id=ID;
          return *this;
        }

        abonat_builder& setNume(const std::string &Nume)
        { ab.nume=Nume;
          return *this;
        }

        Abonat build()
        { return ab;
        }
};

