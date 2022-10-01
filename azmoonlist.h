#ifndef AZMOONLIST_H
#define AZMOONLIST_H

#include <QObject>
#include "Azmoon.h"



class AzmoonList : public QObject
{
    Q_OBJECT
public:
    explicit AzmoonList(QObject *parent = nullptr);
    QVector<Azmoon>items()  ;
    bool setItemAt(int index ,  Azmoon & item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();


public slots:

    void appendItem();
    void removeItem(int id);



private:
     QVector<Azmoon>mItems;
};


#endif // AZMOONLIST_H
