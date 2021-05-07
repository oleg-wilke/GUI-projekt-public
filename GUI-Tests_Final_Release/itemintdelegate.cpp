#include "ItemIntDelegate.h"

ItemIntDelegate::ItemIntDelegate()
{

}

QWidget *ItemIntDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // s. 28 Summerfield
    // Validator wird auf dieser Seite erklärt
    QLineEdit *line_edit = new QLineEdit(parent);
    QIntValidator *validator = new QIntValidator(line_edit);
    // s. 27 Summerfield
    // wie man setValidator aktiviert zum EditLine
    line_edit->setValidator(validator);
    return line_edit;
} // QWidget *ItemBoolDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const

