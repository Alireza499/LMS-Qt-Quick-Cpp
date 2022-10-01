#include "Ostad.h"
#include "Karbar.h"
#include "Daneshjoo.h"
#include "iostream"
#include "fstream"
#include "Dars.h"




std::vector<Ostad>KolOstadHa ;


bool checkIDOstad(int id){
    int i=0;
    while(i<usedIDs.size()){
        if(id == usedIDs[i]){ return false;}
        i++;

    }
    return true;
}



Ostad::Ostad(QString USERNAME,QString EMAIL,QString PASSWORD)
{

    this->username = USERNAME;
    this->Email = EMAIL;
    this->password = PASSWORD;

    ID = rand() % (9999 - 1000 + 1) + 1000;
    while(!checkIDOstad(ID)){
        ID = rand() % (9999 - 1000 + 1) + 1000;
    }

    usedIDs.push_back(ID);

    KolOstadHa.push_back(*this);
    usedKarbaris.push_back(USERNAME.toStdString());


    this->WriteTofile();

}



Ostad::Ostad(int id, QString USERNAME, QString EMAIL, QString PASSWORD)
{
    this->username = USERNAME;
    this->Email = EMAIL;
    this->password = PASSWORD;
    this->ID = id;
    usedKarbaris.push_back(USERNAME.toStdString());
    KolOstadHa.push_back(*this);

}

void Ostad::WriteTofile()
{

    try{
        std::ofstream outfile;
        outfile.open("OstadHa.dat");
        int i=0;
        while(i<KolOstadHa.size()){
            outfile << KolOstadHa[i].getId() << std::endl;
            outfile << KolOstadHa[i].getUsername().toStdString() <<std::endl;
            outfile << KolOstadHa[i].getEmail().toStdString()<< std::endl;
            outfile << KolOstadHa[i].getPassword().toStdString() << std::endl;

            i++;
        }



        outfile.close();
        return;

    }
    catch(std::exception e){
        std::cout<<"\nError: Cant open file in write mode for write Daneshjoo.\n"<<e.what()<<std::endl;
        return;
    }


}
