#include "daneshjoomodel.h"
#include "daneshjoolist.h"
DaneshjooModel::DaneshjooModel(QObject *parent)
    : QAbstractListModel(parent)
    ,mList(nullptr)
{
}

int DaneshjooModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;


    return mList->items().size();

}


QVariant DaneshjooModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const Daneshjoo item=mList->items().at(index.row());


    switch (role)
    {
        case IDRole:
            return QVariant(item.ID);

        case usernameRole:
            return QVariant(item.username);
    }
 return QVariant();
}

bool DaneshjooModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!mList)
    {
        return false;
    }

         Daneshjoo item=mList->items().at(index.row());

         switch (role)
         {
             case IDRole:
                item.ID=value.toInt();
             case usernameRole:
                item.username=value.toString();

         }

         if (mList->setItemAt(index.row(),item)) {

                 emit dataChanged(index, index, QVector<int>() << role);
                 return true;
             }
             return false;
}

Qt::ItemFlags DaneshjooModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> DaneshjooModel::roleNames() const
{
  QHash<int , QByteArray>names;
  names[IDRole]="ID";
  names[usernameRole]="username";

  return names;
}

DaneshjooList *DaneshjooModel::list() const
{
     return mList;
}

void DaneshjooModel::setlist(DaneshjooList *list)
{
    beginResetModel();

    if(mList)
    {
        mList->disconnect(this);
    }
    mList=list;

    if(mList)
    {
        connect(mList,&DaneshjooList::preItemAppended,this,[=](){
            const int index=mList->items().size();
            beginInsertRows(QModelIndex(),index,index);
        });

        connect(mList,&DaneshjooList::postItemAppended,this,[=](){
                endInsertRows();
        });

        connect(mList,&DaneshjooList::preItemRemoved,this,[=](int index){
               beginRemoveRows(QModelIndex(),index,index);
        });

        connect(mList,&DaneshjooList::postItemRemoved,this,[=](){
             endRemoveRows();
        });
    }

    endResetModel();
}


