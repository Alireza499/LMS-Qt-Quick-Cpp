#ifndef AZMOONMODEL_H
#define AZMOONMODEL_H

#include <QAbstractListModel>
#include "Azmoon.h"
class AzmoonList;
class AzmoonModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(AzmoonList *list READ list WRITE setlist)


public:
    explicit AzmoonModel(QObject *parent = nullptr);
    enum
       {
           IDRole= Qt::UserRole,
           nameAzmoonRole,
           tedadSoalatRole,
       };


    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;
     virtual QHash<int , QByteArray>roleNames() const override;

    AzmoonList *list()const;
    void setlist(AzmoonList *list);


private:
     AzmoonList * mList;
};

#endif // AZMOONMODEL_H
