#include "Azmoon.h"




std::vector<Azmoon > KolAzmoonHa;

QVector<int> usedIDs;

bool checkIDAzmoon(int id){
    int i=0;
    while(i<usedIDs.size()){
        if(id == usedIDs[i]){ return false;}
        i++;

    }
    return true;
}




Azmoon::Azmoon(QString nameAZMOON)
{
    this->nameAzmoon = nameAZMOON;


    ID = rand() % (9999 - 1000 + 1) + 1000;
    while(!checkIDAzmoon(ID)){
        ID = rand() % (9999 - 1000 + 1) + 1000;
    }

    usedIDs.push_back(ID);

    KolAzmoonHa.push_back(*this);

    this->WriteTofile();

}

Azmoon::Azmoon(int id, QString nameAZMOON)
{
    this->nameAzmoon = nameAZMOON;
    this->ID = id;
    usedIDs.push_back(ID);
    KolAzmoonHa.push_back(*this);
}

Azmoon::Azmoon()
{

}

void Azmoon::AddSoual(Soual S)
{
    try {
        Soualat.push_back(S);
        tedadSoalat++;

    }  catch (...) {
        std::cout<<"error in adding to the soualat of the current Azmoon.\n";
    }
    this->WriteTofile();
}

void Azmoon::AddSoualRead(Soual S)
{
    try {
        Soualat.push_back(S);
        tedadSoalat++;

    }  catch (...) {
        std::cout<<"error in adding to the soualat of the current Azmoon.\n";
    }

}

int Azmoon::getId()
{
    return ID;
}

int Azmoon::getTedadSoalat(){
    return tedadSoalat;
}

QString Azmoon::getNameAzmoon()
{
    return nameAzmoon;
}

std::vector<Soual> Azmoon::getSoualat()
{
    return Soualat;
}

void Azmoon::WriteTofile()
{
    try{
        std::ofstream outfile;
        outfile.open("AzmoonHa.dat");
        int i=0;
        while(i<KolAzmoonHa.size()){
            outfile << KolAzmoonHa[i].getId() << std::endl;
            outfile << KolAzmoonHa[i].getNameAzmoon().toStdString()<<std::endl;
            outfile << KolAzmoonHa[i].tedadSoalat << std::endl;
            int j=0;
            std::vector<Soual> TMPSOUAL = KolAzmoonHa[i].getSoualat();
            while(j<KolAzmoonHa[i].tedadSoalat){
                outfile << TMPSOUAL[j].getMS().toStdString() << std::endl;
                outfile << TMPSOUAL[j].getG1().toStdString() << std::endl;
                outfile << TMPSOUAL[j].getG2().toStdString() << std::endl;
                outfile << TMPSOUAL[j].getG3().toStdString() << std::endl;
                outfile << TMPSOUAL[j].getG4().toStdString() << std::endl;
                outfile << TMPSOUAL[j].getGTrue() << std::endl;
                outfile << TMPSOUAL[j].getBarom() << std::endl;
                j++;
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
