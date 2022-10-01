#ifndef DANESHJOO_H
#define DANESHJOO_H



#include <QVector>
#include "Karbar.h"
#include <QString>

class Ostad;
class Dars;
class Karbar;


class Daneshjoo : public Karbar {
    friend class DaneshjooList;
    friend class DaneshjooModel;
public:

    Daneshjoo();//khali
    Daneshjoo(QString USERNAME,QString EMAIL,QString PASSWORD);

     // dar constructor farakhani moshavad

    Daneshjoo(int id ,QString USERNAME,QString EMAIL,QString PASSWORD); // baraye vaghti ke az file mokhanim

private:

    virtual void WriteTofile() override;////override

   //int ID // random va yekta dar counstructor initialize shavad



};

extern std::vector<Daneshjoo> KolDaneshjooHa;

#endif // DANESHJOO_H
