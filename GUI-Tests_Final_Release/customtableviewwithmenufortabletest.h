#ifndef CUSTOMTABLEVIEWWITHMENUFORTABLETEST_H
#define CUSTOMTABLEVIEWWITHMENUFORTABLETEST_H

#include <QAction>
#include <QSqlQuery>
#include "customtableview.h"

class CustomTableViewWithMenuForTableTest : public CustomTableView
{
Q_OBJECT
public:
    CustomTableViewWithMenuForTableTest(QSqlRelationalTableModel *model);

public slots:
    void setFilterEqual();
    void setFilterUnequal();
    void setFilterLess();
    void setFilterMore();
    void setFilterCancel();

private:
    void setCurrentFilter(QString sOperation);
    QString GetForeignKeyByCellFromTest(QModelIndex *cell);

    const QString sColumn[7] = {"id", "id_produkte", "id_tester", "id_test_arten", "test_status", "date_of_test", "descr"};

    QSqlRelationalTableModel *current_model;
};

#endif // CUSTOMTABLEVIEWWITHMENUFORTABLETEST_H
