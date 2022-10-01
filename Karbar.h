#ifndef KARBAR_H
#define KARBAR_H

#include <QString>
#include <QVector>



class Dars;

class Karbar{
public:
    Karbar();
    void AddDars(Dars);
    int getId();
    QString getEmail();
    QString getUsername();
    QString getPassword();
    QVector<Dars> getDarsha();
private:

protected:
   virtual void WriteTofile();
   QString Email;
   QString username;
   QString password;
   QVector<Dars> DarsHa;
   int ID;

};

extern std::vector<std::string> usedKarbaris;

#endif // KARBAR_H
