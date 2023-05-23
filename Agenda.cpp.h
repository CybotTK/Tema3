#include "Agenda.h"
#include "Abonat_Skype.h"
#include "Abonat_Skype_Extern.h"
#include "Abonat_Skype_Romania.h"

template<typename T>
void Agenda<T>::GetAgenda(){
    int counter=0;
    for (auto i:abonati)
    { std::cout<<++counter<<") ";
      if (typeid(*i)==typeid(Abonat_Skype_Extern))
      { std::shared_ptr<Abonat> auxab;
        auxab=std::dynamic_pointer_cast<Abonat_Skype_Extern>(i);
        auxab->Afisare();
      }
      else if (typeid(*i)==typeid(Abonat_Skype_Romania))
      { std::shared_ptr<Abonat> auxab;
        auxab=std::dynamic_pointer_cast<Abonat_Skype_Romania>(i);
        auxab->Afisare();
      }
      else if (typeid(*i)==typeid(Abonat_Skype))
      { std::shared_ptr<Abonat> auxab;
        auxab=std::dynamic_pointer_cast<Abonat_Skype>(i);
        auxab->Afisare();
      }
      else std::cout<<*i;
    }
}

template<typename T>
template<typename Derived>
Agenda<T>& Agenda<T>::operator+=(const Derived& ab){
  NrAbonati++;
  abonati.push_back(std::make_shared<Derived>(ab));
  return *this;
}

// template<>
// Agenda<Abonat_Skype>& Agenda<Abonat_Skype>::operator+=(const Abonat_Skype& ab){
//   NrAbonati++;
//   abonati.push_back(new Abonat_Skype(ab));
//   return *this;
// }

// template<>
// Agenda<Abonat_Skype_Extern>& Agenda<Abonat_Skype_Extern>::operator+=(const Abonat_Skype_Extern& ab){
//   NrAbonati++;
//   abonati.push_back(new Abonat_Skype_Extern(ab));
//   return *this;
// }

// template<>
// Agenda<Abonat_Skype_Romania>& Agenda<Abonat_Skype_Romania>::operator+=(const Abonat_Skype_Romania& ab){
//   NrAbonati++;
//   abonati.push_back(new Abonat_Skype_Romania(ab));
//   return *this;
// }

template<typename T>
int Agenda<T>::GetNrAbonati(){
  return NrAbonati;
}

template<typename T>
Agenda<T>& Agenda<T>::operator[](const std::string& Nume){
  bool ok=0;
  for (auto x:abonati)
  { if (x->GetNume() == Nume) 
    { ok = true;
      x->Afisare();
      break;
    }
    if (typeid(*x)==typeid(Abonat_Skype_Extern))
    { std::shared_ptr<Abonat> auxab;
      auxab=std::dynamic_pointer_cast<Abonat_Skype_Extern>(x);
      if (auxab->GetNume()==Nume)
      { ok=1;
        auxab->Afisare();
        break;
      }
    }
    else if (typeid(*x)==typeid(Abonat_Skype_Romania))
    { std::shared_ptr<Abonat> auxab;
      auxab=std::dynamic_pointer_cast<Abonat_Skype_Romania>(x);
      if (auxab->GetNume()==Nume)
      { ok=1;
        auxab->Afisare();
        break;
      }
    }
    else if (typeid(*x)==typeid(Abonat_Skype))
    { std::shared_ptr<Abonat> auxab;
      auxab=std::dynamic_pointer_cast<Abonat_Skype>(x);
      if (auxab->GetNume()==Nume)
      { ok=1;
        auxab->Afisare();
        break;
      }
    }
    else
    { if (x->GetNume()==Nume)
      { ok=1;
        x->Afisare();
        break;
      }
    }
  }
  
  if (ok==0){
    throw std::invalid_argument("Numele introdus nu se gaseste in agenda.\n");
  }

}

template <typename T>
int Agenda<T>::NrAbonati = 0;