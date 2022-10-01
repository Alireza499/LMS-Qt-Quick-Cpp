#include "Dars.h"


std::vector<Dars> KolDarsHa;


bool checkIDDars(int id){
    int i=0;
    while(i<usedIDs.size()){
        if(id == usedIDs[i]){ return false;}
        i++;

    }
    return true;
}

Dars::Dars()
{

}

Dars::Dars(QString NameDarseVoroudi, int idOstadVoroudi) {
    this->ID_Ostad= idOstadVoroudi;
    this->NameDars=NameDarseVoroudi;


    ID = rand() % (9999 - 1000 + 1) + 1000;
    while(!checkIDDars(ID)){
        ID = rand() % (9999 - 1000 + 1) + 1000;
    }

    usedIDs.push_back(ID);

    KolDarsHa.push_back(*this);

    this->WriteTofile();
}

Dars::Dars(QString NameDarseVoroudi, int idOstadVoroudi, int id)
{
    this->ID_Ostad= idOstadVoroudi;
    this->NameDars=NameDarseVoroudi;

    this->ID = id;

    usedIDs.push_back(ID);

    KolDarsHa.push_back(*this);


}

void Dars::AddAzmoon(Azmoon A) {
    try {
        AzmoonHa.push_back(A);
        TedadAzmoonHa++;
    } catch (...) {
        std::cout<<"Error: cant add this azmoon to this dars.\n";
    }
    this->WriteTofile();
}

void Dars::AddAzmoonRead(Azmoon A)
{
    try {
        AzmoonHa.push_back(A);
        TedadAzmoonHa++;
    } catch (...) {
        std::cout<<"Error: cant add this azmoon to this dars.\n";
    }
}

void Dars::AddDaneshjoo(Daneshjoo D) {
    try {
        DanesjooHa.push_back(D);
        TedadDaneshjoo++;
    } catch (...) {
        std::cout<<"Error: cant add this Daneshjoo to this dars.\n";
    }
    this->WriteTofile();
}

void Dars::AddDaneshjooRead(Daneshjoo D)
{
    try {
        DanesjooHa.push_back(D);
        TedadDaneshjoo++;
    } catch (...) {
        std::cout<<"Error: cant add this Daneshjoo to this dars.\n";
    }

}

 int Dars::getId() {
    return ID;
}

  QString Dars::getNameDars() {
    return NameDars;
}

 int Dars::getTedadAzmoonha() {
    return TedadAzmoonHa;
}

 int Dars::getTedadDaneshjoo() {
    return TedadDaneshjoo;
}

 int Dars::getID_Ostad() {
    return ID_Ostad;
}

std::vector<Daneshjoo> Dars::getDanesjooHa()
{
    return DanesjooHa;
}

std::vector<Azmoon> Dars::getAzmoonHa()
{
    return AzmoonHa;
}

void Dars::WriteTofile()
{
    try{
        std::ofstream outfile;
        outfile.open("DarsHa.dat");
        int i=0;
        while(i<KolDarsHa.size()){
            outfile << KolDarsHa[i].getId() << std::endl;
            outfile << KolDarsHa[i].getNameDars().toStdString() << std::endl;
            outfile << KolDarsHa[i].getID_Ostad() << std::endl;
            outfile << KolDarsHa[i].getTedadDaneshjoo() << std::endl;
            int j=0;
            std::vector<Daneshjoo> TMPDANESHJOOHA =KolDarsHa[i].getDanesjooHa() ;
            while(j<KolDarsHa[i].getTedadDaneshjoo()){
                outfile << TMPDANESHJOOHA[j].getId() << std::endl;
                j++;
            }
            outfile << KolDarsHa[i].getTedadAzmoonha() << std::endl;
            int k=0;
            std::vector<Azmoon> TMPAZMOONHA = KolDarsHa[i].getAzmoonHa();
            while(k<KolDarsHa[i].getTedadAzmoonha()){
                outfile << TMPAZMOONHA[k].getId() << std::endl;
                k++;
            }

            i++;
        }



        outfile.close();
        return;

    }
    catch(std::exception &e){
        std::cout<<"\nError: Cant open file in write mode for write Daneshjoo.\n"<<e.what()<<std::endl;
        return;
    }
}

