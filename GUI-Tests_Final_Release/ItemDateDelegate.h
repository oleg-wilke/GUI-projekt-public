#ifndef ITEMDATEDELEGATE_H
#define ITEMDATEDELEGATE_H

#include <QStyledItemDelegate>
#include <QDateTimeEdit>

class ItemDateDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    ItemDateDelegate();
private:
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget * editor, const QModelIndex & index) const;
    void setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const;
};

#endif // ITEMDATEDELEGATE_H
