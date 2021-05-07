#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H

#include <QSqlTableModel> //QTableView nicht gefunden

#include <QSqlRelationalTableModel>


class CustomTableModel: public QSqlTableModel
{
Q_OBJECT
public:
    CustomTableModel(QSqlRelationalTableModel *model);
};

#endif // CUSTOMTABLEMODEL_H
