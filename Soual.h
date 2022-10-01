#ifndef SOUAL_H
#define SOUAL_H
#include "Karbar.h"
#include "Azmoon.h"
#include <QString>





class Soual{
public:
    Soual();
    Soual(float BAROM,QString MATNESOUAL ,QString g1 ,QString g2  ,QString g3 ,QString g4, int AdadeJavab );
    bool isTrue(int); //check kardan javab dar sourat sahih bodan true va darsourat ghlalat bodan false

    QString getMS();
    QString getG1();
    QString getG2();
    QString getG3();
    QString getG4();
    int getGTrue();
    float getBarom();


private:

    int ID; // random va yekta dar counstructor initialize shavad


    float Barom;
    QString MatneSoual;

    QString gozineAval;
    QString gozineDovom;
    QString gozineSevom;
    QString gozineChaharom;

    int AdadeGozineDorost;




};
#endif // SOUAL_H
