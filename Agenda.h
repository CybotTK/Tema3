#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <memory>
#include "Abonat.h"
#include "Abonat_Skype.h"
#include "Abonat_Skype_Extern.h"
#include "Abonat_Skype_Romania.h"

template<typename T>
class Agenda{
    private:
        //std::vector <T*> abonati;
        std::vector<std::shared_ptr<T>> abonati;

        static int NrAbonati;

    public:

        Agenda() = default;
        ~Agenda() = default;
        
        template<typename Derived>
            Agenda& operator+=(const Derived& ab);
        
        // Agenda& operator+=(const Abonat_Skype& ab);
        // Agenda& operator+=(const Abonat_Skype_Extern& ab);
        // Agenda& operator+=(const Abonat_Skype_Romania& ab);
        void GetAgenda();
        static int GetNrAbonati();
        Agenda& operator[](const std::string& Nume);

};

class abonat_factory
{ public:
    static Abonat_Skype_Romania iM(){ return Abonat_Skype_Romania("ime@yahoo.com", "420", "07nu-lstiu", 1, "iM");}
    static Abonat_Skype_Romania Jaxi(){ return Abonat_Skype_Romania("ieusuntjaxi@yahoo.com", "421", "07nu-lstiu", 2, "Jaxi");}
    static Abonat_Skype_Extern ChatGPT(){ return Abonat_Skype_Extern("GPT", "(╯°□°)╯︵ ┻━┻", "suntAIfine", 3, "GPT");}
};

#include "Agenda.cpp.h"