#ifndef VIEWSINIT_H
#define VIEWSINIT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>
#include <QTableView>
#include <QSqlRelationalDelegate>

#include "CustomTableView.h"
#include "Customtableviewwithmenufortabletest.h"
#include "ItemBoolDelegate.h"
#include "ItemDateDelegate.h"
#include "itemintdelegate.h"

class ViewsInit
{
public:
    ViewsInit();
    ~ViewsInit();

private:
    void Testarten_init();
    void Tester_init();
    void Produkte_init();
    void Test_init();

protected:
    QSqlRelationalTableModel *modelTester;
    QSqlRelationalTableModel *modelTestarten;
    QSqlRelationalTableModel *modelProdukte;
    QSqlRelationalTableModel *modelTest;
    CustomTableView *viewTester;
    CustomTableView *viewTestarten;
    CustomTableView *viewProdukte;
    CustomTableViewWithMenuForTableTest *viewTest;
};

#endif // VIEWSINIT_H
