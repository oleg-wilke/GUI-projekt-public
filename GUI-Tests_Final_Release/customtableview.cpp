#include "customtableview.h"

CustomTableView::CustomTableView(QSqlRelationalTableModel *model)
{
    setModel(model); // hängt die Tabelle an den konkreten view an
    setSelectionMode(QAbstractItemView::SingleSelection); // Funktion des view
    setSelectionBehavior(QAbstractItemView::SelectRows);
    resizeColumnsToContents();
    setAlternatingRowColors(true); // rein esthätischer Natur
    setSortingEnabled(true);
    setColumnHidden(0, true); // id Spalte wegradiert

    QObject::connect(this, SIGNAL(delete_pressed(int)), this, SLOT(delete_row(int)));
    QObject::connect(this, SIGNAL(insert_pressed()), this, SLOT(insert_row()));
}


//siehe s. 164 Summerfield Erklärung zur Funktion
void CustomTableView::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Insert)
    {
        emit insert_pressed();
    }
    if (event->key() == Qt::Key_Delete)
    {
        // https://www.qtcentre.org/threads/4885-Remove-selected-rows-from-a-QTableView
        QModelIndexList current_selection =  this->selectionModel()->selectedRows();
        if (!current_selection.empty())
        {
         // 0 weil wir nur eine row haben; row gibt zurück den index auf den er sich bezieht
            emit delete_pressed(current_selection.at(0).row());
        }
    }
    QTableView::keyReleaseEvent(event);
}

void CustomTableView::delete_row(int row)
{
    this->model()->removeRow(row);
// https://www.qtcentre.org/threads/25546-Hide-rows-from-QTableView-QSqlRelationalTableModel
    this->hideRow(row);

}

void CustomTableView::insert_row()
{
// S. 303 Summerfield
    int row = this->model()->rowCount();
    this->model()->insertRow(row);
}
