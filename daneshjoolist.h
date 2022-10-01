#ifndef DANESHJOOLIST_H
#define DANESHJOOLIST_H

#include <QObject>
#include <QVector>
#include <fstream>
#include <iostream>
#include "Azmoon.h"
#include "Dars.h"
#include "Karbar.h"
#include "Soual.h"



class DaneshjooList : public QObject
{
    Q_OBJECT
public:
    explicit DaneshjooList(QObject *parent = nullptr);
    QVector<Daneshjoo>items();
    bool setItemAt(int index , Daneshjoo & item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem();
    void removeItem(int id);

    private:

    QVector<Daneshjoo>mItems;


};

#endif // DANESHJOOLIST_H
