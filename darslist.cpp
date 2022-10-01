#include "darslist.h"

DarsList::DarsList(QObject *parent) : QObject(parent)
{
    int i=0;
    while(i<KolDarsHa.size()){
         Dars item;
         item.ID=KolDarsHa[i].ID;
         item.NameDars=KolDarsHa[i].NameDars;
         item.TedadAzmoonHa=KolDarsHa[i].TedadAzmoonHa;
         item.TedadDaneshjoo=KolDarsHa[i].TedadDaneshjoo;
         item.ID_Ostad=KolDarsHa[i].ID_Ostad;
         i++;
         mItems.append(item);
    }
    Dars item2;
    item2.ID=5;
    item2.NameDars="ypiadf";
    item2.TedadAzmoonHa=4;
    item2.TedadDaneshjoo=6;
    item2.ID_Ostad=1;
    mItems.append(item2);
}


QVector<Dars> DarsList::items()
{
    return mItems;
}


bool DarsList::setItemAt(int index,  Dars &item)
{
    if(index <0 || index >= mItems.size())
    {
        return false;
    }


     const Dars & oldItem=mItems.at(index);
        if(item.ID== oldItem.ID && item.NameDars ==
                oldItem.NameDars && item.TedadAzmoonHa==
                oldItem.TedadAzmoonHa && oldItem.TedadDaneshjoo == item.TedadDaneshjoo
                && item.ID_Ostad== oldItem.ID_Ostad)
        {
            return false;
        }

     mItems[index]= item;
     return true;
}

void DarsList::appendItem()
{
    emit preItemAppended();
         Dars item;
         item.ID=0;
         item.NameDars="";
         item.TedadAzmoonHa=0;
         item.TedadDaneshjoo=0;
         item.ID_Ostad=0;
         mItems.append(item);
         emit postItemAppended();
}

void DarsList::removeItem(int id)
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


