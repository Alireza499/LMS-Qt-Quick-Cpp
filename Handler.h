#ifndef HANDLER_H
#define HANDLER_H
#include "QString"
#include "QObject"
#include "string"


class Karbar;
class Azmoon;
class Soual;

class Handler: public QObject{


    Q_OBJECT
public:
    explicit Handler(QObject *parent=0);
    //explicit Handler();
    virtual ~Handler() {};

signals:

    void rightPass();
    void wrongPass();




    void rightPassDanesjoo();
    void rightPassOstad();

    void daneshjooAdded();
    void ostadAdded();
    void emptyInput();
    void pyanAzmoon();
    void nextsoual();
    void invalidEmail();
    void usedKarbari();



    void nextsoualD();
    void presoualD();
    void pyanAzmoonD();
    void etmamSoualat();
    void etmamSoualatAzChap();
    void taken();
    void firstSoual();
    void emptyExam();


    void notlong();

    ////////////////////////

    void error();
    void darsadded();
    ////////////////////////
    void azmoonadded();
    ///////////////
    void daneshjooadded();
    ////////////////
    void timesUp();


public slots:

    void ReadAllInformation();


    bool searchInUsedKarbaris(std::string);

    ////////////////////////
    void nextSoual(QString Matn,QString Goz1,QString Goz2,QString Goz3,QString Goz4,QString GTrue);
    void taeedVaPyanAzmoon(QString Time);
    ///////////
    void nextSoualD(bool Goz1,bool Goz2,bool Goz3,bool Goz4);
    void preSoualD();
    void taeedVaPyanAzmoonD(QString Time, bool Goz1,bool Goz2,bool Goz3,bool Goz4);
    Q_INVOKABLE QString getMatnSoual();
    Q_INVOKABLE QString getG1();
    Q_INVOKABLE QString getG2();
    Q_INVOKABLE QString getG3();
    Q_INVOKABLE QString getG4();
    /////////////////////
    int findIndexKarname(int idAzmoon , int idDaneshjoo);
    int findIndexDaneshjoo(int id);
    int findIndexOstad(int id);
    int findIndexAzmoon(int id);
    int findIndexDars(int id);
    /////////////////////////////
    Q_INVOKABLE bool checkUserPass(QString U, QString P);
    Q_INVOKABLE bool addDaneshjoo(QString U,QString E, QString P);
    Q_INVOKABLE bool addOstad(QString U,QString E, QString P);
    ////////////////////
    Q_INVOKABLE int getAzmmonUserName( QString nth);
    Q_INVOKABLE int getIDcurrentUser();
    Q_INVOKABLE int checkAzmoon();
    ////////////////

    Q_INVOKABLE QString getUserName();
    ///////
    Q_INVOKABLE void calculateDarsOfUser();
    Q_INVOKABLE int getDarsOfuserSize();
    Q_INVOKABLE QString getDarsOfuserName(int);
    //////
    Q_INVOKABLE void addDars(QString);
    ///////
    Q_INVOKABLE void goToAzmoonhaSaveDarsIndex(int);
    Q_INVOKABLE int getTmpindex();
    //////////////
    Q_INVOKABLE void calculateAzmoonOfDars();
    Q_INVOKABLE int getAzmoonOfDarsSize();
    Q_INVOKABLE QString getAzmoonOfDarsName(int);
    /////////////////////
    Q_INVOKABLE void addAzmoon(QString);
    ///////////////////
    Q_INVOKABLE int getKolDarshaSize();
    Q_INVOKABLE QString getKolDarshaName(int);
    Q_INVOKABLE void goToDarsSavekolDarsIndex(int);
    Q_INVOKABLE void goBacktoUserID(int);
    ///////////////////
    Q_INVOKABLE void calculateDaneshjooOfDars();
    Q_INVOKABLE int getDaneshjooOfDarsSize();
    Q_INVOKABLE QString getDaneshjooOfDarsName(int);
    Q_INVOKABLE void goToKarnameSaveDaneshjooIndex(int);
    /////////////////
    Q_INVOKABLE void goToAzmoonSaveAzmoonIndex(int);
    Q_INVOKABLE void addDaneshjooForDars();
    /////////////////////
    //void calculateKarnameOfAzmoonDaneshjoo();
    Q_INVOKABLE int getKarnameOfAzmoonDaneshjooSize();
    Q_INVOKABLE QString getKarnameOfAzmoonDaneshjooJavab(int);
    Q_INVOKABLE float getKarnameOfAzmoonDaneshjooNomreKol();
    Q_INVOKABLE float getKarnameOfAzmoonDaneshjooNomreDaneshjoo();
    Q_INVOKABLE float getKarnameOfAzmoonDaneshjooNomreDarsad();

    Q_INVOKABLE QString getSoualOfAzmoon(int);
    ////////////////////////
    Q_INVOKABLE bool searchforTakenAzmoon();
    //////////////////////
    Q_INVOKABLE bool isTimeUp(float,float);

private:
    explicit Handler(const Handler& rhs) = delete;
    Handler& operator= (const Handler& rhs) = delete;
    int iDcurrentUser=-1;
    int iDcurrentDars=-1;
    int iDcurrentAzmoon=-1;

    int iDcurrentUserSave=-1;
    int tmpIndex = -1;

};

inline Handler::Handler(QObject *parent):QObject(parent)
{

}




#endif // HANDLER_H
#include "Karbar.h"
