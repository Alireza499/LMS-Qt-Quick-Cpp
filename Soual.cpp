
#include "Soual.h"


bool checkIDSoual(int id){
    int i=0;
    while(i<usedIDs.size()){
        if(id == usedIDs[i]){ return false;}
        i++;

    }
    return true;
}



Soual::Soual(float BAROM,QString MATNESOUAL ,QString g1 ,QString g2  ,QString g3 ,QString g4, int AdadeJavab  ){



    this->Barom = BAROM;
    this->AdadeGozineDorost= AdadeJavab;

    this->MatneSoual = MATNESOUAL;
    this->gozineAval = g1;
    this->gozineDovom = g2;
    this->gozineSevom = g3;
    this->gozineChaharom = g4;


    ID = rand() % (9999 - 1000 + 1) + 1000;
    while(!checkIDSoual(ID)){
        ID = rand() % (9999 - 1000 + 1) + 1000;
    }

    usedIDs.push_back(ID);


}

bool Soual::isTrue(int a){
    return a==AdadeGozineDorost;
}

QString Soual::getMS(){
    return MatneSoual;
}
QString Soual::getG1(){
    return gozineAval;
}
QString Soual::getG2(){
    return gozineDovom;
}
QString Soual::getG3(){
    return gozineSevom;
}
QString Soual::getG4(){
    return gozineChaharom;
}

int Soual::getGTrue()
{
    return AdadeGozineDorost;
}
float Soual::getBarom() {
    return Barom;
}
