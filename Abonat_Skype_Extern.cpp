#include "Abonat.h"
#include "Abonat_Skype.h"
#include "Abonat_Skype_Extern.h"
#include "Persoana.h"

Abonat_Skype_Extern::Abonat_Skype_Extern(){
}

Abonat_Skype_Extern::Abonat_Skype_Extern(const std::string Tara, const std::string ID_skype, const std::string Nr_telefon, const int ID, const std::string Nume)
    :Abonat_Skype(ID_skype, Nr_telefon, ID, Nume)
{
    tara=Tara;
}

Abonat_Skype_Extern::Abonat_Skype_Extern(const std::string Tara, const Abonat_Skype ab_skype)
    :Abonat_Skype(ab_skype)
{
    tara=Tara;
}

Abonat_Skype_Extern::Abonat_Skype_Extern(const Abonat_Skype_Extern &other)
    :Abonat_Skype(other)
{
    tara=other.tara;
}

Abonat_Skype_Extern::~Abonat_Skype_Extern(){
}

void Abonat_Skype_Extern::Afisare(){
    std::cout<<"Persoana cu id-ul "<<this->id<<" si numele "<<this->nume;
    std::cout<<" are nr de telefon: "<<this->nr_telefon<<" si id_skype este ";
    std::cout<<this->id_skype<<" din tara: "<<this->tara<<'\n';
}

std::string Abonat_Skype_Extern::GetNume(){
    return this->nume;
}

Abonat_Skype_Extern& Abonat_Skype_Extern::operator= (const Abonat_Skype_Extern& other)
{
    nr_telefon=other.nr_telefon;
    id=other.id;
    nume=other.nume;
    id_skype=other.id_skype;
    tara=other.tara;
    return *this;
}

std::istream& operator >> (std::istream &in, Abonat_Skype_Extern& data){
    
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

    std::cout<<"Dati tara utilizatorului: ";
    in>>data.tara;
    for (int i=0;i<data.tara.size();i++)
        if ((data.tara[i]>='a' && data.tara[i]<='z') || (data.tara[i]>='A' && data.tara[i]<='Z'));
        else throw std::invalid_argument("Tara introdusa este invalida\n");
    std::cout<<'\n';

    return in;
}

std::ostream& operator << (std::ostream &out, const Abonat_Skype_Extern& data)
{
    out<<"Persoana cu id-ul "<<data.id<<" si numele "<<data.nume;
    out<<" are nr de telefon: "<<data.nr_telefon<<" si id_skype este ";
    out<<data.id_skype<<" din tara: "<<data.tara<<'\n';
    
    return out;
}
