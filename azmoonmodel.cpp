#include "azmoonmodel.h"
#include "azmoonlist.h"

AzmoonModel::AzmoonModel(QObject *parent)
    : QAbstractListModel(parent)
    ,mList(nullptr)
{
}

int AzmoonModel::rowCount(const QModelIndex &parent) const
{

    if (parent.isValid() || !mList)
        return 0;


    return mList->items().size();
}

QVariant AzmoonModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    const Azmoon item=mList->items().at(index.row());

       switch (role)
       {
           case IDRole:
               return QVariant(item.ID);

           case nameAzmoonRole:
               return QVariant(item.nameAzmoon);

            case tedadSoalatRole:
                return QVariant(item.tedadSoalat);
       }
    return QVariant();
}

bool AzmoonModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!mList)
    {
        return false;
    }
     Azmoon item=mList->items().at(index.row());

       switch (role)
       {
           case IDRole:
               item.ID=value.toInt();

           case nameAzmoonRole:
               item.nameAzmoon=value.toString();

            case tedadSoalatRole:
               item.tedadSoalat=value.toInt();
       }

    if (data(index, role) != value) {

        emit dataChanged(index, index, QVector<int>() << role);
          return true;
    }
    return false;
}

Qt::ItemFlags AzmoonModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> AzmoonModel::roleNames() const
{
        QHash<int , QByteArray>names;
        names[IDRole]="ID";
        names[nameAzmoonRole]="nameAzmoon";
        names[tedadSoalatRole]="tedadSoalat";

         return names;
}

AzmoonList *AzmoonModel::list() const
{
        return mList;
}

void AzmoonModel::setlist(AzmoonList *list)
{
    beginResetModel();

    if(mList)
    {
        mList->disconnect(this);
    }
    mList=list;

    if(mList)
    {
        connect(mList,&AzmoonList::preItemAppended,this,[=](){
            const int index=mList->items().size();
            beginInsertRows(QModelIndex(),index,index);
        });

        connect(mList,&AzmoonList::postItemAppended,this,[=](){
                endInsertRows();
        });

        connect(mList,&AzmoonList::preItemRemoved,this,[=](int index){
               beginRemoveRows(QModelIndex(),index,index);
        });

        connect(mList,&AzmoonList::postItemRemoved,this,[=](){
             endRemoveRows();
        });
    }
    endResetModel();
}
