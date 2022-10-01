#include "azmoonlist.h"
#include "Dars.h"
#include "Soual.h"

AzmoonList::AzmoonList(QObject *parent) : QObject(parent)
{
    int i=0;
    while(i<KolAzmoonHa.size()){
         Azmoon item;
         item.ID=KolAzmoonHa[i].ID;
         item.nameAzmoon=KolAzmoonHa[i].nameAzmoon;
         item.tedadSoalat=KolAzmoonHa[i].tedadSoalat;

         i++;
         mItems.append(item);
    }




    Azmoon item2;
    item2.ID=3;
    item2.nameAzmoon="ypiadf";
    item2.tedadSoalat=4;
    mItems.append(item2);
}

QVector<Azmoon> AzmoonList::items()
{
 return mItems;
}

bool AzmoonList::setItemAt(int index, Azmoon &item)
{
    if(index <0 || index >= mItems.size())
    {
        return false;
    }


     const Azmoon & oldItem=mItems.at(index);
        if(item.ID== oldItem.ID && item.nameAzmoon ==
                oldItem.nameAzmoon && item.tedadSoalat==
                oldItem.tedadSoalat)
        {
            return false;
        }

     mItems[index]= item;
     return true;
}

void AzmoonList::appendItem()
{
    emit preItemAppended();
         Azmoon item;
         item.ID=0;
         item.nameAzmoon="";
         item.tedadSoalat=0;
         mItems.append(item);
         emit postItemAppended();
}

void AzmoonList::removeItem(int id)
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
