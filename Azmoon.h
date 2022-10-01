#ifndef AZMOON_H
#define AZMOON_H

#include <QObject>
#include <QString>
#include <iostream>
#include <fstream>
#include <QVector>
#include "Dars.h"
#include "Soual.h"
#include "Karbar.h"
#include "Daneshjoo.h"
#include "Ostad.h"
#include "iostream"
#include "fstream"




class Dars;
class Soual;

class Azmoon{
    friend class AzmoonModel ;
    friend class AzmoonList;
public:
    Azmoon(QString nameAZMOON);
    Azmoon(int id,QString nameAZMOON);
    Azmoon();
    void AddSoual(Soual);
    void AddSoualRead(Soual);
     int getId();
     int getTedadSoalat();
     QString getNameAzmoon();
    // QVector<Soual> getSoualat();
     std::vector<Soual>getSoualat();
private:
    int ID; // random va yekta dar counstructor initialize shavad
    QString nameAzmoon;

    int tedadSoalat=0;
   //QVector<Soual> Soualat;
    std::vector<Soual> Soualat;
    void WriteTofile(); //dar counstaructor



};
extern QVector<int> usedIDs;
extern std::vector<Azmoon> KolAzmoonHa;
#endif // AZMOON_H
