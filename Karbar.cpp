#include "Karbar.h"
#include "iostream"
#include "fstream"
#include "Dars.h"





std::vector<std::string> usedKarbaris;


Karbar::Karbar()
{

}

void Karbar::AddDars(Dars D){
    try {
             DarsHa.push_back(D);
    }
    catch (...) {
     std::cout<<"\nError: cant add this dars to this member.\n";
    }

}

int Karbar::getId()
{
    return ID;
}

QString Karbar::getEmail()
{
    return Email;
}

QString Karbar::getUsername()
{
    return username;
}

QString Karbar::getPassword()
{
    return  password;
}

QVector<Dars> Karbar::getDarsha()
{
    return DarsHa;
}




void Karbar::WriteTofile()
{
    std::cout<<"this never get called \n";
   return; //be erth miresad

}
