#include "Karname.h"
#include "iostream"
#include "fstream"

std::vector<Karname> KolKarnameHa;


Karname::Karname(int idA, int idD)
{
    this->IDAzmoon = idA;
    this->IDDaneshjoo = idD;
    KolKarnameHa.push_back(*this);
    this->WriteToFile();
}

Karname::Karname(int idA, int idD, bool)
{
    this->IDAzmoon = idA;
    this->IDDaneshjoo = idD;
    KolKarnameHa.push_back(*this);
}

int Karname::getIDAzmoon()
{
    return  IDAzmoon;
}

int Karname::getIDDaneshjoo()
{
    return IDDaneshjoo;
}

void Karname::pushJavabHa(Javab J)
{
    this->JavabHa.push_back(J);
    this->WriteToFile();
}

void Karname::pushJavabHaRead(Javab J)
{
    this->JavabHa.push_back(J);

}

void Karname::popJvabHa()
{

   this->JavabHa.pop_back();
}

std::vector<Javab> Karname::getJavabHa()
{
    return  JavabHa;
}

float Karname::getNomre()
{   float Nomre = 0;
    int i=0;
    while(i<JavabHa.size()){
        if(JavabHa[i] == dorost){
            Nomre = Nomre + 1;
        }
        i++;
    }
    return Nomre;
}

float Karname::getNomreKol()
{
    return JavabHa.size();
}

int Karname::getNomreDarsad()
{
    return getNomre() / getNomreKol() * 100;
}

Javab Karname::getJavabIndex(int i)
{
    return JavabHa[i];
}

void Karname::WriteToFile()
{
    try{
        std::ofstream outfile;
        outfile.open("KarnameHa.dat");
        int i=0;
        while(i<KolKarnameHa.size()){
            outfile << KolKarnameHa[i].getIDAzmoon() << std::endl;
            outfile << KolKarnameHa[i].getIDDaneshjoo()<<std::endl;
            outfile << KolKarnameHa[i].getNomreKol() << std::endl;
            int j=0;
            std::vector<Javab> TMPJavabHa = KolKarnameHa[i].getJavabHa();
            while(j<KolKarnameHa[i].getNomreKol()){
                outfile << TMPJavabHa[j] << std::endl;

                j++;
            }
            i++;
        }



        outfile.close();
        return;

    }
    catch(std::exception &e){
        std::cout<<"\nError: Cant open file in write mode for write Karname.\n"<<e.what()<<std::endl;
        return;
    }
}
