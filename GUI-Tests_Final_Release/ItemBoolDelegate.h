#ifndef ITEMBOOLDELEGATE_H
#define ITEMBOOLDELEGATE_H

#include <QStyledItemDelegate>
#include <QCheckBox>

// s. 245 Summerfield anstelle QItemDelegate QStyleItemDelegate weil auf StackOverflow
// (https://stackoverflow.com/questions/11800946/checkbox-and-itemdelegate-in-a-tableview)
// gelesen, dass dies eine bessere Variante sei
// beim Ausprobieren festgestellt, dass void paint nicht notwendig sei
class ItemBoolDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    ItemBoolDelegate();
private:
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget * editor, const QModelIndex & index) const;
    void setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const;
};

#endif // ITEMBOOLDELEGATE_H
