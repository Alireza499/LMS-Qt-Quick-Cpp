#ifndef KARNAME_H
#define KARNAME_H

#include <iostream>
#include "vector"

enum Javab { dorost, ghalat, nazade };

class Karname{

public:


    Karname();
    Karname(int , int);
    Karname(int , int, bool);

    int getIDAzmoon();
    int getIDDaneshjoo();
    void pushJavabHa(Javab);
    void pushJavabHaRead(Javab);
    void popJvabHa();
    std::vector <Javab> getJavabHa();
    float getNomre();
    float getNomreKol();
    int getNomreDarsad();

    Javab getJavabIndex(int);


private:
    int IDAzmoon;
    int IDDaneshjoo;
    std::vector <Javab> JavabHa;
    void WriteToFile();
};

extern std::vector <Karname> KolKarnameHa;







#endif // KARNAME_H
