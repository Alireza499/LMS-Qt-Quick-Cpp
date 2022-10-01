#include "Handler.h"
#include "Karbar.h"
#include "Azmoon.h"
#include "Daneshjoo.h"
#include "Ostad.h"
#include "Dars.h"
#include <fstream>
#include "string"
#include "Soual.h"
#include "iostream"
#include "vector"
#include "Karname.h"
#include <iostream>

#include <QDebug>



//static std::vector <Soual> SoulatAzmoon;

int zamanAzmoon;
int zamanDaneshjoo;



static std::vector <Javab> JavabHa;







static int currentSoual=0;


static std::vector <Dars> DarsCurrentuser;
static std::vector <Azmoon> AzmoonCurrentDars;
static std::vector <Daneshjoo> DaneshjooCurrentDars;







/////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////
int Handler::findIndexKarname(int idAzmoon , int idDaneshjoo)
{
    int i=0;
    while(i<KolKarnameHa.size()){

        if(KolKarnameHa[i].getIDAzmoon() == idAzmoon && KolKarnameHa[i].getIDDaneshjoo()){
            return i;
        }
        i++;
    }
    return -1;
}


int Handler::findIndexDaneshjoo(int id)
{
    int i=0;
    while(i<KolDaneshjooHa.size()){
        if(id==KolDaneshjooHa[i].getId()){
            return i;
        }
        i++;
    }
    return -1;
}

int Handler::findIndexOstad(int id)
{
    int i=0;
    while(i<KolOstadHa.size()){
        if(id==KolOstadHa[i].getId()){
            return i;
        }
        i++;
    }
    return -1;
}

int Handler::findIndexAzmoon(int id)
{
    int i=0;
    while(i<KolAzmoonHa.size()){
        if(id==KolAzmoonHa[i].getId()){
            return i;
        }
        i++;
    }
    return -1;
}
int Handler::findIndexDars(int id)
{
    int i=0;
    while(i<KolDarsHa.size()){
        if(id==KolDarsHa[i].getId()){
            return i;
        }
        i++;
    }
    return -1;
}
/////////////////////////////////////////////////////////////



QString Handler::getUserName()
{

    if(findIndexDaneshjoo(iDcurrentUser)!=-1){
        return KolDaneshjooHa[findIndexDaneshjoo(iDcurrentUser)].getUsername();
    }
    else if(findIndexOstad(iDcurrentUser!=-1)){
        return KolOstadHa[findIndexOstad(iDcurrentUser)].getUsername();
    }
    else{
        return "ناشناخته";
    }

}
///////////////////////////////////////////////////////////////
void Handler::calculateDarsOfUser(){
    DarsCurrentuser.clear();

    if(findIndexDaneshjoo(iDcurrentUser)!=-1){
        //Daneshjoo tmpDaneshjoo = KolDaneshjooHa[findIndexDaneshjoo(iDcurrentUser)];

        int i=0;
        while(i<KolDarsHa.size()){
            int j=0;
            std::vector<Daneshjoo>tmpDaneshjoo = KolDarsHa[i].getDanesjooHa();
            while(j<KolDarsHa[i].getDanesjooHa().size()){
                if(tmpDaneshjoo[j].getId() == KolDaneshjooHa[findIndexDaneshjoo(iDcurrentUser)].getId()){
                    DarsCurrentuser.push_back(KolDarsHa[i]);
                }
                j++;
            }


            i++;
        }
    }
    else if(findIndexOstad(iDcurrentUser)!=-1){
        int i=0;
        while(i<KolDarsHa.size()){
            if(KolDarsHa[i].getID_Ostad()==KolOstadHa[findIndexOstad(iDcurrentUser)].getId()){
                DarsCurrentuser.push_back(KolDarsHa[i]);
            }

            i++;
        }
    }
    else{
        std::cout<<"something went wrong with calculateDarsOfUser";
        return;
    }

}

int Handler::getDarsOfuserSize()
{
    return DarsCurrentuser.size();
}

QString Handler::getDarsOfuserName(int i)
{
    return DarsCurrentuser[i].getNameDars();
}
////////////////////////////////////////////////////////////////////////
void Handler::addDars(QString nameDars)
{   try {

         Dars newDars(nameDars , iDcurrentUser);


}  catch (...) {
    emit error();
}
    calculateDarsOfUser();
    emit darsadded();

}
/////////////////////////////////////////////////////////////////////////
void Handler::goToAzmoonhaSaveDarsIndex(int i)
{
    tmpIndex = i;
    iDcurrentDars = DarsCurrentuser[i].getId();
    calculateAzmoonOfDars();

}

int Handler::getTmpindex()
{
    return tmpIndex;
}

void Handler::calculateAzmoonOfDars()
{

    AzmoonCurrentDars.clear();
    if(findIndexDars(iDcurrentDars)!=-1){
        //Daneshjoo tmpDaneshjoo = KolDaneshjooHa[findIndexDaneshjoo(iDcurrentUser)];

        int i=0;
        std::vector<Azmoon>tmpAzmoon ;
        if(KolDarsHa[findIndexDars(iDcurrentDars)].getTedadAzmoonha()>0){
            tmpAzmoon = KolDarsHa[findIndexDars(iDcurrentDars)].getAzmoonHa();
        }
        while(i<KolDarsHa[findIndexDars(iDcurrentDars)].getTedadAzmoonha()){
            AzmoonCurrentDars.push_back(tmpAzmoon[i]);


            i++;
        }
    }
    else{
        std::cout<<"something went wrong with calculateAzmoonOfDars";
        return;
    }

}

int Handler::getAzmoonOfDarsSize()
{
    calculateAzmoonOfDars();
    return AzmoonCurrentDars.size();
}

QString Handler::getAzmoonOfDarsName(int i)
{
    calculateAzmoonOfDars();
    return AzmoonCurrentDars[i].getNameAzmoon();
}

void Handler::addAzmoon(QString nameAzmoon)
{
    try {
            Azmoon newAzmoon(nameAzmoon);
            KolDarsHa[findIndexDars(iDcurrentDars)].AddAzmoon(newAzmoon);
            iDcurrentAzmoon = newAzmoon.getId();

            //Azmoon(QString nameAZMOON);
             //void AddAzmoon(Azmoon);

    }  catch (...) {
        emit error();
    }
        calculateAzmoonOfDars();
        emit azmoonadded();

}

int Handler::getKolDarshaSize()
{
    return KolDarsHa.size();
}

QString Handler::getKolDarshaName(int i)
{
    return KolDarsHa[i].getNameDars();
}

void Handler::goToDarsSavekolDarsIndex(int i)
{
    tmpIndex = i;
    iDcurrentDars = KolDarsHa[i].getId();

}

void Handler::goBacktoUserID(int)
{
    iDcurrentUser = iDcurrentUserSave;
}

void Handler::calculateDaneshjooOfDars()
{
    DaneshjooCurrentDars.clear();
    if(findIndexDars(iDcurrentDars)!=-1){
        //Daneshjoo tmpDaneshjoo = KolDaneshjooHa[findIndexDaneshjoo(iDcurrentUser)];

        int i=0;
        std::vector<Daneshjoo>tmpDaneshjoo ;
        if(KolDarsHa[findIndexDars(iDcurrentDars)].getTedadAzmoonha()>0){
            if(KolDarsHa[findIndexDars(iDcurrentDars)].getTedadDaneshjoo()>0){
                tmpDaneshjoo = KolDarsHa[findIndexDars(iDcurrentDars)].getDanesjooHa();
            }
            else return;
        }
        while(i<KolDarsHa[findIndexDars(iDcurrentDars)].getTedadDaneshjoo()){
            DaneshjooCurrentDars.push_back(tmpDaneshjoo[i]);


            i++;
        }
    }
    else{
        std::cout<<"something went wrong with calculateDaneshjooOfDars";
        return;
    }
}

int Handler::getDaneshjooOfDarsSize()
{
    calculateDaneshjooOfDars();
    return DaneshjooCurrentDars.size();
}

QString Handler::getDaneshjooOfDarsName(int i)
{
    calculateDaneshjooOfDars();
    return DaneshjooCurrentDars[i].getUsername();
}

void Handler::goToKarnameSaveDaneshjooIndex(int i)
{
    tmpIndex = i;
    iDcurrentUserSave = iDcurrentUser;
    iDcurrentUser = DaneshjooCurrentDars[i].getId();
}

void Handler::goToAzmoonSaveAzmoonIndex(int i)
{
    tmpIndex = i;
    iDcurrentAzmoon = AzmoonCurrentDars[i].getId();
    calculateAzmoonOfDars();
}

void Handler::addDaneshjooForDars()
{
    try {


            KolDarsHa[findIndexDars(iDcurrentDars)].AddDaneshjoo(KolDaneshjooHa[findIndexDaneshjoo(iDcurrentUser)]);



    }  catch (...) {
        emit error();
    }
        calculateAzmoonOfDars();
        emit daneshjooadded();
}

int Handler::getKarnameOfAzmoonDaneshjooSize()
{   if(findIndexKarname(iDcurrentAzmoon,iDcurrentUser)==-1){

        return 0;
    }
    return KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].getNomreKol();
}

QString Handler::getKarnameOfAzmoonDaneshjooJavab(int i)
{
    if(findIndexKarname(iDcurrentAzmoon,iDcurrentUser)==-1){

            return 0;
        }



    if(KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].getJavabIndex(i)==dorost){
        return "صحیح";
    }
    else if(KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].getJavabIndex(i)==ghalat){
        return "غلط";
    }
    else{
        return "نزده";
    }
}

float Handler::getKarnameOfAzmoonDaneshjooNomreKol()
{
    if(findIndexKarname(iDcurrentAzmoon,iDcurrentUser)==-1){

            return 0;
        }



    return  KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].getNomreKol();
}

float Handler::getKarnameOfAzmoonDaneshjooNomreDaneshjoo()
{
    if(findIndexKarname(iDcurrentAzmoon,iDcurrentUser)==-1){

            return 0;
        }


    return KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].getNomre();
}

float Handler::getKarnameOfAzmoonDaneshjooNomreDarsad()
{
    if(findIndexKarname(iDcurrentAzmoon,iDcurrentUser)==-1){

            return 0;
        }



    return KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].getNomreDarsad();
}

QString Handler::getSoualOfAzmoon(int i)
{
        std::cout<<"\n\n\n OK \n\n\n";

        std::vector <Soual> SoulatAzmoon = KolAzmoonHa[findIndexAzmoon(iDcurrentAzmoon)].getSoualat();
       currentSoual = i;
       std::string A = "صورت سوال "+ std::to_string(i+1)+ " :  "+ this->getMatnSoual().toStdString();
       A = A + "\n";
       A = A + "گزینه اول:  " +getG1().toStdString();
       A = A + "\n";
       A = A + "گزینه دوم:  "+ getG2().toStdString();
       A = A + "\n";
       A = A + "گزینه سوم:  " +getG3().toStdString();
       A = A + "\n";
       A = A + "گزینه چهارم:  "+ getG4().toStdString();
       A = A + "\n";
       A = A + "گزینه صحیح: "+ std::to_string(SoulatAzmoon[i].getGTrue());
       A = A + "\n";

       std::cout<<A;
       std::cout<<"\n\n\n OK2 \n\n\n";
        qDebug().noquote() << "\n\n\n OK2 \n\n\n";

        return  QString::fromStdString(A);;
}

bool Handler::searchforTakenAzmoon()
{
    if(findIndexKarname(iDcurrentAzmoon,iDcurrentUser)!=-1){
        return true;
    }
    else{
        return false;
    }
}

bool Handler::isTimeUp(float A , float B)
{
    if(A==B){
        emit timesUp();
        return true;
    }
    else{
        return false;
    }
}


/////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////










void Handler::ReadAllInformation()
{
    std::string line;
      std::ifstream myfile ("OstadHa.dat");
      if (myfile.is_open())
      {
        while ( getline (myfile,line) )
        {   int tmpID = stoi(line);
            getline (myfile,line);
            QString tmpUser = QString::fromStdString(line);
            getline (myfile,line);
            QString tmpEmail = QString::fromStdString(line);
            getline (myfile,line);
            QString tmpPass = QString::fromStdString(line);

            Ostad newOstad(tmpID,tmpUser,tmpEmail,tmpPass);

        }
        myfile.close();
      }

      else std::cout << "\nUnable to open OstadHa.dat\n";


      std::ifstream myfile2 ("DaneshjooHa.dat");
      if (myfile2.is_open())
      {
        while ( getline (myfile2,line) )
        {
            int tmpID = stoi(line);
            getline (myfile2,line);
            QString tmpUser = QString::fromStdString(line);
            getline (myfile2,line);
            QString tmpEmail = QString::fromStdString(line);
            getline (myfile2,line);
            QString tmpPass = QString::fromStdString(line);

            Daneshjoo newDanesjoo(tmpID,tmpUser,tmpEmail,tmpPass);

        }
        myfile2.close();
      }

      else std::cout << "\nUnable to open DaneshjooHa.dat\n";

      std::ifstream myfile3 ("AzmoonHa.dat");
      if (myfile3.is_open())
      {
        while ( getline (myfile3,line) )
        {
            int tmpAzmoonID = stoi(line);
            getline (myfile3,line);
            QString tmpNameAzmoon = QString::fromStdString(line);

            Azmoon tmpAzmoon(tmpAzmoonID,tmpNameAzmoon);


            getline (myfile3,line);
            int tmpAzmoonTedadSoual = stoi(line);




            int i=0;
            while(i<tmpAzmoonTedadSoual){
                getline (myfile3,line);
                QString tmpMatneSoual = QString::fromStdString(line);
                getline (myfile3,line);
                QString tmpgozineAval = QString::fromStdString(line);
                getline (myfile3,line);
                QString tmpgozineDovom = QString::fromStdString(line);
                getline (myfile3,line);
                QString tmpgozineSevom = QString::fromStdString(line);
                getline (myfile3,line);
                QString tmpgozineChaharom = QString::fromStdString(line);
                getline (myfile3,line);
                int tmpAdadeGozineDorost = stoi(line);
                getline (myfile3,line);
                float tmpBarom = stof(line);

                Soual newSoual(tmpBarom,tmpMatneSoual,tmpgozineAval,tmpgozineDovom,tmpgozineSevom,tmpgozineChaharom,tmpAdadeGozineDorost);
                KolAzmoonHa[findIndexAzmoon(tmpAzmoonID)].AddSoual(newSoual);
                tmpAzmoon.AddSoualRead(newSoual);
                i++;
            }


        }
        myfile3.close();
      }

      else std::cout << "\nUnable to open AzmoonHa.dat\n";

      std::ifstream myfile4 ("DarsHa.dat");
      if (myfile4.is_open())
      {
        while ( getline (myfile4,line) )
        {
            int tmpID = stoi(line);

            getline (myfile4,line);
            QString tmpNameDars = QString::fromStdString(line);

            getline (myfile4,line);
            int tmpIDOstad = stoi(line);


            Dars newDars(tmpNameDars,tmpIDOstad,tmpID );



            getline (myfile4,line);
            int tmpTedadDanesjoo = stoi(line);

            int i=0;
            while(i<tmpTedadDanesjoo){
                getline (myfile4,line);
                int tmpIDDanesjoo = stoi(line);
                int tmpIndexDaneshjoo=findIndexDaneshjoo(tmpIDDanesjoo);
                if(tmpIndexDaneshjoo==-1){
                    continue;
                }
                else{
                    newDars.AddDaneshjooRead(KolDaneshjooHa[tmpIndexDaneshjoo]);
                    KolDarsHa[findIndexDars(tmpID)].AddDaneshjooRead(KolDaneshjooHa[tmpIndexDaneshjoo]);
                }
                i++;
            }


            getline (myfile4,line);
            int tmpTedadAzmoon = stoi(line);
            i=0;
            while(i<tmpTedadAzmoon){
                getline (myfile4,line);
                int tmpIDAzmoon = stoi(line);
                int tmpIndexAzmoon=findIndexAzmoon(tmpIDAzmoon);
                if(tmpIndexAzmoon==-1){
                    continue;

                }

                else{
                    newDars.AddAzmoonRead(KolAzmoonHa[tmpIndexAzmoon]);
                    KolDarsHa[findIndexDars(tmpID)].AddAzmoonRead(KolAzmoonHa[tmpIndexAzmoon]);
                }
                i++;
            }

        }
        myfile4.close();
      }
      else std::cout << "\nUnable to open DarsHa.dat\n";


      std::ifstream myfile5 ("KarnameHa.dat");
      if (myfile5.is_open())
      {


        while ( getline (myfile5,line) )
        {
            int tmpAzmoonID = stoi(line);
            getline (myfile5,line);
            int tmpDaneshjooID = stoi(line);

            Karname tmpKarname(tmpAzmoonID,tmpDaneshjooID, true);


            getline (myfile5,line);
            int tmpKarnameTedadJavab = stoi(line);




            int i=0;
            while(i<tmpKarnameTedadJavab){
                getline (myfile5,line);
                int tmpJavabInt = stoi(line);
                Javab tmpJavab;
                if(tmpJavabInt==0){
                    tmpJavab = dorost;
                }
                else if(tmpJavabInt==1){
                    tmpJavab = ghalat;
                }
                else if(tmpJavabInt==2){
                    tmpJavab = nazade;
                }
                else{
                    continue;
                }

                KolKarnameHa[findIndexKarname(tmpAzmoonID,tmpDaneshjooID)].pushJavabHaRead(tmpJavab);


                tmpKarname.pushJavabHaRead(tmpJavab);

                i++;
            }


        }
        myfile5.close();
      }

      else std::cout << "\nUnable to open KarnameHa.dat\n";
}

//////////////////////////////////////////////////////////////////////////

void Handler::nextSoual(QString Matn,QString Goz1,QString Goz2,QString Goz3,QString Goz4,QString GTrue)
{

    int gt = GTrue.toInt();

    Soual A(1,Matn,Goz1,Goz2,Goz3,Goz4,gt);

    // AddSoual

    //findIndexAzmoon(iDcurrentAzmoon);
    KolAzmoonHa[findIndexAzmoon(iDcurrentAzmoon)].AddSoual(A);

    std::vector< Azmoon> tmpAzmoon = KolDarsHa[findIndexDars(iDcurrentDars)].getAzmoonHa();
    int i=0;
    while(i<tmpAzmoon.size()){
        if(KolAzmoonHa[findIndexAzmoon(iDcurrentAzmoon)].getId() == tmpAzmoon[i].getId()){
            tmpAzmoon[i].AddSoual(A);
            break;
        }
        i++;
    }

    //SoulatAzmoon.push_back(A);

//Soual(float BAROM,QString MATNESOUAL ,QString g1 ,QString g2  ,QString g3 ,QString g4, int AdadeJavab  )
    emit nextsoual();

}

void Handler::taeedVaPyanAzmoon(QString Time)
{
    //zamanAzmoon =Time.toInt();
    emit pyanAzmoon();

}

////////////////////////////////////////////////////////////////////////////////////




void Handler::nextSoualD(bool Goz1,bool Goz2,bool Goz3,bool Goz4)
{
    std::vector <Soual> SoulatAzmoon = KolAzmoonHa[findIndexAzmoon(iDcurrentAzmoon)].getSoualat();




    if(Goz1){
        if(SoulatAzmoon[currentSoual].isTrue(1)){
            KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(dorost);
            JavabHa.push_back(dorost);
        }
        else{
            KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(ghalat);
            JavabHa.push_back(ghalat);
        }
    }
    else if(Goz2){
        if(SoulatAzmoon[currentSoual].isTrue(2)){
            KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(dorost);
            JavabHa.push_back(dorost);
        }
        else{
            KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(ghalat);
            JavabHa.push_back(ghalat);
        }
    }
    else if(Goz3){
        if(SoulatAzmoon[currentSoual].isTrue(3)){
            KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(dorost);
            JavabHa.push_back(dorost);
        }
        else{
            KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(ghalat);
            JavabHa.push_back(ghalat);
        }
    }
    else if(Goz4){
        if(SoulatAzmoon[currentSoual].isTrue(4)){
            KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(dorost);
            JavabHa.push_back(dorost);
        }
        else{
            KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(ghalat);
            JavabHa.push_back(ghalat);
        }
    }
    else{
        KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(nazade);
        JavabHa.push_back(nazade);
    }

    currentSoual++;
    if(currentSoual==SoulatAzmoon.size()-1){
        emit etmamSoualat();
        emit nextsoualD();
        return;
    }
    emit nextsoualD();

}

void Handler::preSoualD()
{
    KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].popJvabHa();
    JavabHa.pop_back();
    currentSoual--;
    if(currentSoual==0){
        emit etmamSoualatAzChap();
        emit presoualD();
        return;
    }
    emit presoualD();
}

void Handler::taeedVaPyanAzmoonD(QString Time, bool Goz1,bool Goz2,bool Goz3,bool Goz4)
{
    //zamanDaneshjoo = Time.toInt();

    std::vector <Soual> SoulatAzmoon = KolAzmoonHa[findIndexAzmoon(iDcurrentAzmoon)].getSoualat();




    if(Goz1){
        if(SoulatAzmoon[currentSoual].isTrue(1)){
            KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(dorost);
            JavabHa.push_back(dorost);
        }
        else{
            KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(ghalat);
            JavabHa.push_back(ghalat);
        }
    }
    else if(Goz2){
        if(SoulatAzmoon[currentSoual].isTrue(2)){
            KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(dorost);
            JavabHa.push_back(dorost);
        }
        else{
            KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(ghalat);
            JavabHa.push_back(ghalat);
        }
    }
    else if(Goz3){
        if(SoulatAzmoon[currentSoual].isTrue(3)){
            KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(dorost);
            JavabHa.push_back(dorost);
        }
        else{
            KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(ghalat);
            JavabHa.push_back(ghalat);
        }
    }
    else if(Goz4){
        if(SoulatAzmoon[currentSoual].isTrue(4)){
            KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(dorost);
            JavabHa.push_back(dorost);
        }
        else{
            KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(ghalat);
            JavabHa.push_back(ghalat);
        }
    }
    else{
        KolKarnameHa[findIndexKarname(iDcurrentAzmoon,iDcurrentUser)].pushJavabHa(nazade);
        JavabHa.push_back(nazade);
    }





    emit pyanAzmoonD();
}

QString Handler::getMatnSoual()
{
    std::vector <Soual> SoulatAzmoon = KolAzmoonHa[findIndexAzmoon(iDcurrentAzmoon)].getSoualat();
    return SoulatAzmoon[currentSoual].getMS();
}

QString Handler::getG1()
{
    std::vector <Soual> SoulatAzmoon = KolAzmoonHa[findIndexAzmoon(iDcurrentAzmoon)].getSoualat();
    return SoulatAzmoon[currentSoual].getG1();
}
QString Handler::getG2()
{
    std::vector <Soual> SoulatAzmoon = KolAzmoonHa[findIndexAzmoon(iDcurrentAzmoon)].getSoualat();
    return SoulatAzmoon[currentSoual].getG2();
}
QString Handler::getG3()
{
    std::vector <Soual> SoulatAzmoon = KolAzmoonHa[findIndexAzmoon(iDcurrentAzmoon)].getSoualat();
    return SoulatAzmoon[currentSoual].getG3();
}
QString Handler::getG4()
{
    std::vector <Soual> SoulatAzmoon = KolAzmoonHa[findIndexAzmoon(iDcurrentAzmoon)].getSoualat();
    return SoulatAzmoon[currentSoual].getG4();
}


















bool Handler::checkUserPass(QString U, QString P)
{
    std::cout<<"yes";
    //cout<<KolDaneshjooHa[0]->getUsername();

    int i=0;
    while(i < KolDaneshjooHa.size()){
        if(KolDaneshjooHa[i].getUsername()== U && KolDaneshjooHa[i].getPassword()== P){

            iDcurrentUser = KolDaneshjooHa[i].getId();

            calculateDarsOfUser();

            emit rightPassDanesjoo();

            return true;

        }
        i++;
    }
    i=0;
    while (i<KolOstadHa.size()) {
        if(KolOstadHa[i].getUsername()== U && KolOstadHa[i].getPassword()== P){

            iDcurrentUser = KolOstadHa[i].getId();

            calculateDarsOfUser();

            emit rightPassOstad();
            return true;
        }
        i++;
    }

    emit wrongPass();
    return false;

}

bool Handler::addDaneshjoo(QString U, QString E, QString P)
{
    std::cout<<"ok";

    if(U.isEmpty() || E.isEmpty() || P.isEmpty()){
        emit emptyInput();
        return false;
    }

    if(searchInUsedKarbaris(U.toStdString())){
        emit usedKarbari();
        return false;
    }



    Daneshjoo newDaneshjoo(U,E,P);
    emit daneshjooAdded();


    return true;
}

bool Handler::searchInUsedKarbaris(std::string S){
    int i=0;
    while(i<usedKarbaris.size()){

        if(S == usedKarbaris[i]){
            return true;
        }


        i++;
    }
    return false;
}

bool Handler::addOstad(QString U, QString E, QString P)
{
    if(U.isEmpty() || E.isEmpty() || P.isEmpty()){
        emit emptyInput();
        return false;
    }
    if(searchInUsedKarbaris(U.toStdString())){
        emit usedKarbari();
        return false;
    }
    std::string tmp = P.toStdString();




    Ostad newOstad(U,E,P);

    emit ostadAdded();

    return true;

}

int Handler::getAzmmonUserName(QString nth)
{


    return nth.toInt()*2;
}

int Handler::getIDcurrentUser()
{
    return iDcurrentUser;

}

int Handler::checkAzmoon()
{
    std::vector <Soual> SoulatAzmoon = KolAzmoonHa[findIndexAzmoon(iDcurrentAzmoon)].getSoualat();
    if(SoulatAzmoon.size()==0){
        emit emptyExam();
        return -1;
    }
    else{
        emit firstSoual();
        currentSoual = 0;
        Karname K(iDcurrentAzmoon,iDcurrentUser);
        return 0;
    }
}


