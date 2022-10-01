#include "Daneshjoo.h"
#include "fstream"
#include "iostream"
#include "Dars.h"
#include "Ostad.h"
#include <QVector>



std::vector<Daneshjoo > KolDaneshjooHa;


bool checkIDDaneshjoo(int id){
    int i=0;
    while(i<usedIDs.size()){
        if(id == usedIDs[i]){ return false;}
        i++;

    }
    return true;
}



Daneshjoo::Daneshjoo()
{

}

Daneshjoo::Daneshjoo(QString USERNAME, QString EMAIL, QString PASSWORD)
{

    this->username = USERNAME;
    this->Email = EMAIL;
    this->password = PASSWORD;

    ID = rand() % (9999 - 1000 + 1) + 1000;
    while(!checkIDDaneshjoo(ID)){
        ID = rand() % (9999 - 1000 + 1) + 1000;
    }

    usedIDs.push_back(ID);

    KolDaneshjooHa.push_back(*this);

    usedKarbaris.push_back(USERNAME.toStdString());
    WriteTofile();

}



Daneshjoo::Daneshjoo(int id, QString USERNAME, QString EMAIL, QString PASSWORD)
{
    this->username = USERNAME;
    this->Email = EMAIL;
    this->password = PASSWORD;
    this->ID = id;

    usedKarbaris.push_back(USERNAME.toStdString());
    KolDaneshjooHa.push_back(*this);
}

void Daneshjoo::WriteTofile()
{

    try{
        std::ofstream outfile;
        outfile.open("DaneshjooHa.dat");
        int i=0;
        while(i<KolDaneshjooHa.size()){
            outfile << KolDaneshjooHa[i].getId() << std::endl;
            outfile << KolDaneshjooHa[i].getUsername().toStdString() << std::endl;
            outfile << KolDaneshjooHa[i].getEmail().toStdString() << std::endl;
            outfile << KolDaneshjooHa[i].getPassword().toStdString() << std::endl;

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
