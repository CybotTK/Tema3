#include "Abonat.h"
#include "Abonat_Skype.h"
#include "Abonat_Skype_Romania.h"
#include "Persoana.h"

Abonat_Skype_Romania::Abonat_Skype_Romania(){
}

Abonat_Skype_Romania::Abonat_Skype_Romania(const std::string Adresa_mail, const std::string ID_skype, const std::string Nr_telefon, const int ID, const std::string Nume)
    :Abonat_Skype(ID_skype, Nr_telefon, ID, Nume)
{
    adresa_mail=Adresa_mail;
}

Abonat_Skype_Romania::Abonat_Skype_Romania(const std::string Adresa_mail, const Abonat_Skype ab_skype)
    :Abonat_Skype(ab_skype)
{
    adresa_mail=Adresa_mail;
}

Abonat_Skype_Romania::Abonat_Skype_Romania(const Abonat_Skype_Romania &other)
    :Abonat_Skype(other)
{
    adresa_mail=other.adresa_mail;
}

Abonat_Skype_Romania::~Abonat_Skype_Romania(){
}

void Abonat_Skype_Romania::Afisare(){
    std::cout<<"Persoana cu id-ul "<<this->id<<" si numele "<<this->nume;
    std::cout<<" are nr de telefon: "<<this->nr_telefon<<" si id_skype este ";
    std::cout<<this->id_skype<<" cu adresa de email: "<<this->adresa_mail<<'\n';
}

std::string Abonat_Skype_Romania::GetNume(){
    return this->nume;
}

Abonat_Skype_Romania& Abonat_Skype_Romania::operator= (const Abonat_Skype_Romania& other)
{
    nr_telefon=other.nr_telefon;
    id=other.id;
    nume=other.nume;
    id_skype=other.id_skype;
    adresa_mail=other.adresa_mail;
    return *this;
}

std::istream& operator >> (std::istream &in, Abonat_Skype_Romania& data){
    
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

    std::cout<<"Dat adresa de email a utilizatorului: ";
    in>>data.adresa_mail;
    std::cout<<'\n';

    return in;
}

std::ostream& operator << (std::ostream &out, const Abonat_Skype_Romania& data)
{
    out<<"Persoana cu id-ul "<<data.id<<" si numele "<<data.nume;
    out<<" are nr de telefon: "<<data.nr_telefon<<" si id_skype este ";
    out<<data.id_skype<<"cu adresa de email: "<<data.adresa_mail<<'\n';
    
    return out;
}