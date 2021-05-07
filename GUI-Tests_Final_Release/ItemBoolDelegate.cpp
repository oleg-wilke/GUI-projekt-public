#include "ItemBoolDelegate.h"

ItemBoolDelegate::ItemBoolDelegate()
{
} // ItemBoolDelegate::ItemBoolDelegate(QObject *parent)

QWidget *ItemBoolDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const
{
    // s. 247 Summerfield
    // anstelle des Standard Editline wird checkbox angewandt
    // Qtableview besteht ursprünglich aus Editline, hier wird aber checkbox verwendet
    QCheckBox *checkbox = new QCheckBox(parent);
    return checkbox;
} // QWidget *ItemBoolDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option

void ItemBoolDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QCheckBox *checkbox = (QCheckBox *) editor;
    // index -> die zur Auswahl stehende Zelle
    checkbox->setChecked(index.data().toBool());
} // void ItemBoolDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const

void ItemBoolDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                    const QModelIndex &index) const
{
    QCheckBox *checkbox = (QCheckBox *) (editor);
    // Änderung aus der View werden in der DB eingepflegt
    model->setData(index, checkbox->isChecked());
} // void ItemBoolDelegate::setModelData(QWidget *editor, QAbstractItemModel *model
