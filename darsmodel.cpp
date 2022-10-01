#include "darsmodel.h"
#include "darslist.h"
DarsModel::DarsModel(QObject *parent)
    : QAbstractListModel(parent)
    ,mList(nullptr)
{
}





int DarsModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !mList)
        return 0;


    return mList->items().size();

}



QVariant DarsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const Dars item=mList->items().at(index.row());

    switch (role)
    {
        case IDRole:
            return QVariant(item.ID);

        case NamedarsRole:
            return QVariant(item.NameDars);

         case IDostadRole:
             return QVariant(item.ID_Ostad);

        case TedadazmoonaaRole:
            return QVariant(item.TedadAzmoonHa);

        case TAedadaaneshjooRole:
            return QVariant(item.TedadDaneshjoo);
    }


    return QVariant();
}

bool DarsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!mList)
    {
        return false;
    }
     Dars item=mList->items().at(index.row());

     switch (role)
     {
         case IDRole:

            item.ID=value.toInt();

         case NamedarsRole:
            item.NameDars=value.toString();

          case IDostadRole:

            item.ID_Ostad=value.toInt();

         case TedadazmoonaaRole:
             item.TedadAzmoonHa=value.toInt();

         case TAedadaaneshjooRole:
             item.TedadDaneshjoo=value.toInt();

     }
    if (mList->setItemAt(index.row(),item)) {

            emit dataChanged(index, index, QVector<int>() << role);
            return true;
        }
        return false;

    }



QHash<int, QByteArray>DarsModel::roleNames() const
{

    QHash<int , QByteArray>names;
    names[IDRole]="ID";
    names[IDostadRole]="ID_Ostad";
    names[NamedarsRole]="NameDars";
    names[TedadazmoonaaRole]="TedadAzmoonHa";
    names[TAedadaaneshjooRole]="TedadDaneshjoo";

    return names;
}

DarsList *DarsModel::list() const
{
    return mList;
}

Qt::ItemFlags DarsModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

void DarsModel::setlist(DarsList *list)
{
    beginResetModel();

    if(mList)
    {
        mList->disconnect(this);
    }
    mList=list;

    if(mList)
    {
        connect(mList,&DarsList::preItemAppended,this,[=](){
            const int index=mList->items().size();
            beginInsertRows(QModelIndex(),index,index);
        });

        connect(mList,&DarsList::postItemAppended,this,[=](){
                endInsertRows();
        });

        connect(mList,&DarsList::preItemRemoved,this,[=](int index){
               beginRemoveRows(QModelIndex(),index,index);
        });

        connect(mList,&DarsList::postItemRemoved,this,[=](){
             endRemoveRows();
        });
    }
    endResetModel();
}

