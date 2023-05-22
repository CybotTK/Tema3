#include "Abonat.h"
#include "Persoana.h"
#include "Abonat_Skype.h"

Abonat_Skype::Abonat_Skype(){
}

Abonat_Skype::~Abonat_Skype(){
}

Abonat_Skype::Abonat_Skype(const std::string ID_skype, const std::string Nr_telefon, const int ID, const std::string Nume)
    :Abonat(Nr_telefon, ID, Nume)
{
    id_skype=ID_skype;
}

Abonat_Skype::Abonat_Skype(const std::string ID_skype, const Abonat& a)
    :Abonat(a)
{
    id_skype=ID_skype;
}

Abonat_Skype::Abonat_Skype(const Abonat_Skype& other)
    :Abonat(other)
{
    id_skype=other.id_skype;
}

Abonat_Skype& Abonat_Skype::operator=(const Abonat_Skype &other)
{
    nr_telefon=other.nr_telefon;
    id=other.id;
    nume=other.nume;
    id_skype=other.id_skype;
    return *this;
}

void Abonat_Skype::Afisare(){
    std::cout<<"Persoana cu id-ul "<<this->id<<" si numele "<<this->nume;
    std::cout<<" are nr de telefon: "<<this->nr_telefon<<" si id_skype este ";
    std::cout<<this->id_skype<<'\n';
}

std::string Abonat_Skype::GetNume(){
    return this->nume;
}

std::istream& operator >> (std::istream &in, Abonat_Skype& data){
    
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
    std::cout<<"\n";

    std::cout<<"Dati ID Skype: ";
    in>>data.id_skype;
    std::cout<<"\n";

    return in;
}

std::ostream& operator << (std::ostream &out, const Abonat_Skype& data)
{
    out<<"Persoana cu id-ul "<<data.id<<" si numele "<<data.nume;
    out<<" are nr de telefon: "<<data.nr_telefon<<" si id_skype este ";
    out<<data.id_skype<<'\n';

    return out;
}