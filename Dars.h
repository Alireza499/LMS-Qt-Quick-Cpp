#ifndef DARS_H
#define DARS_H


#include <QObject>
#include <QVector>
#include <iostream>
#include <fstream>
#include "Azmoon.h"
#include "Daneshjoo.h"
#include "Ostad.h"

class Azmoon;
class Daneshjoo;




class Dars{
    friend class DarsModel;
    friend class DarsList;
public:

    Dars();
    Dars(QString NameDarseVoroudi,int idOstadVoroudi);
    Dars(QString NameDarseVoroudi,int idOstadVoroudi,int id);

    void AddAzmoon(Azmoon);
    void AddAzmoonRead(Azmoon);
    void AddDaneshjoo(Daneshjoo);
    void AddDaneshjooRead(Daneshjoo);

      int getId();
      int getTedadAzmoonha();
      int getTedadDaneshjoo();
      int getID_Ostad();
      QString getNameDars();
      std::vector<Daneshjoo> getDanesjooHa();
      std::vector<Azmoon> getAzmoonHa();

private:
    int ID; // random va yekta dar counstructor initialize shavad

    QString NameDars;
    int  ID_Ostad;

    int TedadAzmoonHa=0;
    std::vector<Azmoon> AzmoonHa;

    int TedadDaneshjoo=0;
    std::vector<Daneshjoo> DanesjooHa;

    void WriteTofile(); //dar counstaructor


};

extern std::vector<Dars> KolDarsHa;

#endif // DARS_H
