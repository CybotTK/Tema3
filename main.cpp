#include <iostream>
#include "Persoana.h"
#include "Abonat.h"
#include "Abonat_Skype.h"
#include "Abonat_Skype_Romania.h"
#include "Abonat_Skype_Extern.h"
#include "Agenda.h"

std::string Input;
std::string c;

int main(){
    // std::cout<<"Dati ID-ul si numele unei persoane\n";
    // Persoana p;
    // std::cin>>p;
    // std::cout<<p;
    // Abonat a1("07n-amcartela", p);
    // std::cout<<a1;
    // Abonat a2("07n-amcartele", 123124, "Marinb");
    // std::cout<<a2;
    // Abonat a3(a2);
    // std::cout<<'\n'; 
    // std::cout<<"a3 are "<<a3;

    // Abonat_Skype ab1("idskypeosugi","07n-amcartele", 123124, "Marinb");
    // std::cout<<ab1;
    // Abonat_Skype ab2;
    // std::cin>>ab2;
    // std::cout<<ab2;
    // Abonat_Skype ab3(ab2);
    // std::cout<<ab3;

    // Abonat_Skype ab4=ab1;
    // std::cout<<ab4;

    // Abonat_Skype_Extern ab1;
    // std::cin>>ab1;
    // std::cout<<ab1;

    // std::cout<<'\n';

    // Abonat_Skype_Extern ab2(ab1);
    // std::cout<<ab2<<'\n';

    // Abonat_Skype_Extern ab3;
    // ab3=ab2;
    // std::cout<<ab3<<'\n';
    
    // Abonat a2("07n-amcartele", 123124, "Marina");
    // Abonat a3("07n-amcartela", 11234, "Marinbe");
    // Abonat_Skype as1("idu matii",a3);

    // Abonat a4("07n-amcarte", 123123456, "MarinaSor");
    // Abonat_Skype as2("idu matii 2", a4);
    // Abonat_Skype_Romania abRo("adrsemail@n-amemail.nu", as2);

    // Abonat a5("07123523", 123124, "MarinaJOs");
    // Abonat_Skype as3("IduMatii3", a5);
    // Abonat_Skype_Extern abEx("Bangladesh", as3);

    // Agenda ag;

    // ag+=a2;
    // ag+=as1;
    // ag+=abRo;
    // ag+=abEx;
    
    // std::cout<<ag.GetNrAbonati();

    // ag.GetAgenda();
    // std::cout<<'\n';


    // ag["MarinaSore"];

    std::cout<<"Doriti sa intrati in aplicatie? Y/N\n";
    std::cin>>c;
    int greseli=0;

    Agenda<Abonat> ag;

    if(c=="Y")
    { while(c!="N")
      { system("cls");
        std::cout<<"Apasati tasta 1 pentru a adauga un abonat nou simplu.\n";
        std::cout<<"Apasati tasta 2 pentru a adauga un abonat nou ce are skype.\n";
        std::cout<<"Apasati tasta 3 pentru a adauga un abonat nou ce are skype si este din Romania.\n";
        std::cout<<"Apasati tasta 4 pentru a adauga un abonat nou ce are skype din alta tara.\n";
        std::cout<<"Apasati tasta 5 pentru a cauta un abonat din agenda dupa nume si a afisa detaliile acestuia\n";
        std::cout<<"Apasati tasta 6 pentru a afisa toata agenda\n";
        std::cout<<"Apasati tasta 7 pentru a introduce in agenda un contact fantoma pentru a evita restrictiile\n";
        std::cin>>Input;
        if (Input=="1"){
            try{
                Abonat ab;
                std::cin>>ab;
                ag+=ab;
            }
            catch (std::exception& err){
                std::cout<<"EROARE "<<err.what();\
                std::cout<<"Nu s-a reusit introducera abonatului in agenda.\n";
            }
        }
        else if (Input=="2"){
            try{
            Abonat_Skype ab;
            std::cin>>ab;
            ag+=ab;
            }
            catch (std::exception& err){
                std::cout<<"EROARE "<<err.what();\
                std::cout<<"Nu s-a reusit introducera abonatului in agenda.\n";
            }
        }
        else if (Input=="3"){
            try{
            Abonat_Skype_Romania ab;
            std::cout<<"Acum adaugati un abonat skype romania!! \n";
            std::cin>>ab;
            ag+=ab;
            }
            catch (std::exception& err){
                std::cout<<"EROARE "<<err.what();\
                std::cout<<"Nu s-a reusit introducera abonatului in agenda.\n";
            }        
        }
        else if (Input=="4"){
            try{
            Abonat_Skype_Extern ab;
            std::cin>>ab;
            ag+=ab;
            }
            catch (std::exception& err){
                std::cout<<"EROARE "<<err.what();\
                std::cout<<"Nu s-a reusit introducera abonatului in agenda.\n";
            }
        }
        else if(Input=="5"){
            try{std::cout<<"Introduceti numele: ";
            std::string Nume;
            std::cin.ignore();
            std::getline(std::cin,Nume);
            for (int i=0;i<Nume.size();i++)
                if ((Nume[i]>='a' && Nume[i]<='z') || (Nume[i]>='A' && Nume[i]<='Z') || (Nume[i]==' ' && i>0));
                else throw std::invalid_argument("Numele introdus este invalid\n");
            ag[Nume];
            }
            catch (std::exception& err){
                std::cout<<"EROARE "<<err.what();\
                std::cout<<"Nu se poate accesa agenda cu un astfel de nume.\n";
            }
        }
        else if(Input=="6"){
            if (ag.GetNrAbonati()==0)
                std::cout<<"Agenda e goala.\n";
            else ag.GetAgenda();
        }
        else if(Input=="7")
        { system("cls");
          std::cout<<"Apasati tasta 1 pentru a adauga dvs un nume.\n";
          std::cout<<"Apasati tasta 2 pentru a deschide lista de abonati default.\n";
          std::string Input2;
          std::cin>>Input2;
          if (Input2=="1")
          { std::string nume;
            std::cout<<"Dati un nume: ";
            std::cin.ignore();
            std::getline(std::cin, nume);
            std::cout<<"\n";
            abonat_builder ab_b;
            Abonat ab = ab_b.setNrTelefon("07n-amcartela").setID(1).setNume(nume).build();
            ag+=ab;
          }
          else if (Input2=="2")
          { std::cout<<"Apasati tasta 1 pentru a adauga pe regele iM\n";
            std::cout<<"Apasati tasta 2 pentru a adauga pe Jaxi\n";
            std::cout<<"Apasati tasta 3 pentru a adauga ChatGPT\n";
            std::string Input3;
            std::cin>>Input3;

            if (Input3=="1")
            { Abonat_Skype_Romania ab= abonat_factory::iM();
              ag+=ab;
            }
            else if (Input3=="2")
            { Abonat_Skype_Romania ab= abonat_factory::Jaxi();
              ag+=ab;
            }
            else if (Input3=="3")
            { Abonat_Skype_Extern ab=abonat_factory::ChatGPT();
              ag+=ab;
            }
            else std::cout<<"Input introdus gresit.\n";
          }
          else std::cout<<"Input introdus gresit.\n";
        }
        else{
            std::cout<<"Input introdus gresit.\n\n";
        }
        std::cout<<"Dorit sa continuati?\n Y/N\n";
        std::cin>>c;
        while(c!="Y" && c!="N")
        { greseli++;
          std::cout<<"Input introdus gresit.\n Va rog reintroduceti.\n";
          std::cin>>c;
          if (greseli==4) 
          { std::cout<<"Input introdus gresit de prea multe ori.\n Va rog restartati aplicatia\n";
            return 0;
          }
        }
        greseli=0;
      }
    }
    else if(c=="N")
    {
        std::cout<<"Pa atunci";
    }
    else std::cout<<"Input nerecunoscut, va rog rulati aplicatia din nou";

    return 0;
}