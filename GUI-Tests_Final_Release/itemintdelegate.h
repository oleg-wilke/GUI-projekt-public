#ifndef ITEMINTDELEGATE_H
#define ITEMINTDELEGATE_H

#include <QStyledItemDelegate>
#include <QLineEdit>
#include <QIntValidator>

class ItemIntDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    ItemIntDelegate();
private:
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // ITEMINTDELEGATE_H
