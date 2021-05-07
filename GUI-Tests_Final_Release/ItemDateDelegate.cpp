#include "ItemDateDelegate.h"

ItemDateDelegate::ItemDateDelegate()
{
} // ItemDateDelegate::ItemDateDelegate()

QWidget *ItemDateDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QDateTimeEdit *dateEditor = new QDateTimeEdit(QDate::currentDate(), parent);
    dateEditor->setDisplayFormat("dd/MM/yyyy");
    dateEditor->setCalendarPopup(true);

    return dateEditor;
} // QWidget *ItemDateDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const

void ItemDateDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{

    QString value =index.model()->data(index, Qt::EditRole).toString();
    QDateTimeEdit *dateEditor = (QDateTimeEdit *) editor;
    dateEditor->setDate(QDate::fromString(index.model()->data(index, Qt::EditRole).toString(), "dd/MM/yyyy"));
} // void ItemDateDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const

void ItemDateDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDateTimeEdit *dateEditor = (QDateTimeEdit *) editor;
    QString value = dateEditor->text();
    model->setData(index, value);
} // void ItemDateDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
