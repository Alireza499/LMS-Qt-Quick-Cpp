

#ifndef DARSMODEL_H
#define DARSMODEL_H

#include <QAbstractListModel>

class DarsList;
class DarsModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(DarsList *list READ list WRITE setlist)


public:
    explicit DarsModel(QObject *parent = nullptr);
    enum
     {
         IDRole= Qt::UserRole,
         NamedarsRole,
         IDostadRole,
         TedadazmoonaaRole,
         TAedadaaneshjooRole
     };


    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;
      virtual QHash<int , QByteArray>roleNames() const override;

    DarsList *list()const;
    void setlist(DarsList *list);

private:
    DarsList * mList;

};

#endif // DARSMODEL_H
