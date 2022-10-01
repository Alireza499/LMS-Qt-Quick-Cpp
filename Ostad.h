
#ifndef OSTAD_H
#define OSTAD_H



#include <QString>
#include "Karbar.h"
//#include "Daneshjoo.h"

#include <QVector>

class Karbar;




class Ostad : public Karbar {
public:
    Ostad();//khali
    Ostad(QString USERNAME,QString EMAIL,QString PASSWORD);
    Ostad(int id ,QString USERNAME,QString EMAIL,QString PASSWORD); // baraye vaghti ke az file mokhanim


private:
    void WriteTofile() override; //override

};



extern std::vector<Ostad> KolOstadHa;

#endif // OSTAD_H
