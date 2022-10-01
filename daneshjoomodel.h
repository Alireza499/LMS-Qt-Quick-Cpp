#ifndef DANESHJOOMODEL_H
#define DANESHJOOMODEL_H

#include <QAbstractListModel>

class DaneshjooList;
class DaneshjooModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(DaneshjooList *list READ list WRITE setlist)

public:
    explicit DaneshjooModel(QObject *parent = nullptr);
    enum
       {
           IDRole= Qt::UserRole,
           usernameRole
       };


        int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;
     virtual QHash<int , QByteArray>roleNames() const override;
    DaneshjooList *list()const;
    void setlist(DaneshjooList * list);

private:

    DaneshjooList * mList;
};

#endif // DANESHJOOMODEL_H
