#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include "Abonat.h"
#include "Abonat_Skype.h"
#include "Abonat_Skype_Extern.h"
#include "Abonat_Skype_Romania.h"

template<typename T>
class Agenda{
    private:
        std::vector <T*> abonati;
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

#include "Agenda.cpp.h"