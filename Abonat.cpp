#include "Abonat.h"
#include "Persoana.h"

// constructor de initializare
Abonat::Abonat(){
}

// destructor
Abonat::~Abonat(){
}


//constructor de initializare
Abonat::Abonat(const std::string Nr_telefon, const int ID, const std::string Nume)
    :Persoana(ID, Nume)
{
    nr_telefon=Nr_telefon;
}

Abonat::Abonat(const std::string Nr_telefon, const Persoana &p)
    :Persoana(p)
{
    nr_telefon=Nr_telefon;
}

//constructor de copiere
Abonat::Abonat(const Abonat &other)
    :Persoana(other)
{
    nr_telefon=other.nr_telefon;
}

void Abonat::Afisare(){
    std::cout<<"Persoana cu id-ul "<<this->id<<" si numele "<<this->nume;
    std::cout<<" are nr de telefon: "<<this->nr_telefon<<'\n';
}

std::string Abonat::GetNume(){
    return this->nume;
}

Abonat& Abonat::operator= (const Abonat& other)
{
    nr_telefon=other.nr_telefon;
    id=other.id;
    nume=other.nume;
    return *this;
}

// operator afisare
std::ostream& operator << (std::ostream& out, const Abonat& data){
    out<<"Persoana cu id-ul "<<data.id<<" si numele "<<data.nume;
    out<<" are nr de telefon: "<<data.nr_telefon<<'\n';
    return out;
}

//operator citire
std::istream& operator >> (std::istream& in, Abonat& data){
    
    std::cout<<"Dati nr de telefon: ";
    in>>data.nr_telefon;
    if (data.nr_telefon.size()<10 || data.nr_telefon.size()>10)
        throw std::invalid_argument("Numarul de telefon este invalid\n");
    std::cout<<'\n';
    
    std::cout<<"Dati ID: ";
    in>>data.id;
    std::cout<<'\n';

    std::cout<<"Dati nume: ";
    in>>data.nume;
    for (int i=0;i<data.nume.size();i++)
        if ((data.nume[i]>='a' && data.nume[i]<='z') || (data.nume[i]>='A' && data.nume[i]<='Z'));
        else throw std::invalid_argument("Numele introdus este invalid\n");

    return in;
}
