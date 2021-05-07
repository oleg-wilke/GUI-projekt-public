#include "customtableviewwithmenufortabletest.h"

CustomTableViewWithMenuForTableTest::CustomTableViewWithMenuForTableTest(QSqlRelationalTableModel *model)
    : CustomTableView(model)
{
    current_model = model;
}

void CustomTableViewWithMenuForTableTest::setFilterEqual()
{
    setCurrentFilter("=");
}

void CustomTableViewWithMenuForTableTest::setFilterUnequal()
{
    setCurrentFilter("!=");
}

void CustomTableViewWithMenuForTableTest::setFilterLess()
{
    setCurrentFilter("<=");
}

void CustomTableViewWithMenuForTableTest::setFilterMore()
{
    setCurrentFilter(">=");
}

void CustomTableViewWithMenuForTableTest::setFilterCancel()
{
    current_model->setFilter("");
}

void CustomTableViewWithMenuForTableTest::setCurrentFilter(QString sOperation)
{
// s. Summerfield
    QModelIndex current_cell = this->currentIndex();
    if (current_cell.isValid())
    {
        QString sQuery;
//        int current_column = current_cell.column();
        QString current_field = (sColumn[current_cell.column()]);
        if (current_cell.column() >= 1 && current_cell.column() <= 3)
        {
            QString current_value = GetForeignKeyByCellFromTest(&current_cell);
            sQuery = current_field + sOperation + "'" + current_value + "'";
        }
        else
        {
            QString current_value = current_cell.data().toString();
            sQuery = current_field + sOperation + "'" + current_value + "'";
        }

// hier wird der Code eingefügt
        QString currentFilter = current_model->filter();
        if (currentFilter != "" && currentFilter.length() < 200)
        {
            currentFilter = currentFilter + " AND " + sQuery;
        }
        else
        {
            currentFilter = sQuery;
        }

        current_model->setFilter(currentFilter);
    }
}

QString CustomTableViewWithMenuForTableTest::GetForeignKeyByCellFromTest(QModelIndex *cell)
{
//    int current_column = cell->column();
    QString current_field = (sColumn[cell->column()]);
    int current_row = cell->row();
    QString id_from_view = current_model->index(current_row, 0).data().toString();
    QString sQuery = "SELECT " + current_field + " FROM test WHERE id=" + "'" + id_from_view + "'";
    QSqlQuery query;
    query.exec(sQuery);
// s. 295 Summerfield
    if (query.next())
    {
        return query.value(0).toString();
    }
    else
    {
        return "0";
    }
}
