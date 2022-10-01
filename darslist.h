#ifndef DARSLIST_H
#define DARSLIST_H
#include <QObject>
#include <QVector>
#include <fstream>
#include <iostream>
#include "Azmoon.h"
#include "Dars.h"



class DarsList : public QObject
{
    Q_OBJECT
public:
    explicit DarsList(QObject *parent = nullptr);
    QVector<Dars>items();
    bool setItemAt(int index ,  Dars & item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();


public slots:

    void appendItem();
    void removeItem(int id);



private:

     QVector<Dars>mItems;

};

#endif // DARSLIST_H
