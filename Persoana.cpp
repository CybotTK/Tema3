#include "Persoana.h"

Persoana::Persoana(){
}

Persoana::~Persoana(){
}

Persoana::Persoana(const int ID, const std::string Nume){
    id=ID;
    nume=Nume;
}

Persoana::Persoana(const Persoana &other){
    id=other.id;
    nume=other.nume;
}

Persoana& Persoana::operator= (const Persoana& other){
    id=other.id;
    nume=other.nume;
    return *this;
}

std::ostream& operator << (std::ostream& out, const Persoana &p){
    out<<"Persoana cu id-ul "<<p.id<<" are numele "<<p.nume<<".\n";
    return out;
}

std::istream& operator >> (std::istream& in, Persoana &p){
    std::cout<<"Dati ID: ";
    in>>p.id;
    std::cout<<'\n';
    std::cout<<"Dati nume: ";
    in>>p.nume;
    std::cout<<'\n';

    return in;
}