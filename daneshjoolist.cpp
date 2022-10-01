#include "daneshjoolist.h"

DaneshjooList::DaneshjooList(QObject *parent) : QObject(parent)
{

    int i=0;
    while(i<KolDaneshjooHa.size()){
        Daneshjoo item;
        item.ID= KolDaneshjooHa[i].ID;
        item.username=KolDaneshjooHa[i].username;

        i++;
        mItems.append(item);
    }

    Daneshjoo item2;
    item2.ID=2;
    item2.username="younes";
    mItems.append(item2);
}

QVector<Daneshjoo> DaneshjooList::items()
{
    return  mItems;
}

bool DaneshjooList::setItemAt(int index, Daneshjoo &item)
{
    if(index <0 || index >= mItems.size())
    {
        return false;
    }
    const Daneshjoo & oldItem=mItems.at(index);
        if(item.ID == oldItem.ID
        && item.username == oldItem.username)
        {
            return  false;
        }

       mItems[index]=item;
       return  true;

}

void DaneshjooList::appendItem()
{
    emit preItemAppended();
         Daneshjoo item;
         item.ID=0;
         item.username="";
         mItems.append(item);
         emit postItemAppended();
}

void DaneshjooList::removeItem(int id)
{
    for(int i=0;i<mItems.size();i++)
    {
        if(mItems.at(i).ID==id)
        {
             emit preItemRemoved(i);
            mItems.removeAt(i);
            emit postItemRemoved();
        }
    }
}


