#ifndef CUSTOMTABLEVIEW_H
#define CUSTOMTABLEVIEW_H

#include <QTableView>
#include <QKeyEvent>
#include <QSqlRelationalTableModel>

// neue Klasse verebt von QTableView, bleiben public, da hier keine explizite Änderung nötig ist
class CustomTableView : public QTableView
{
// dort wo signals und slots muss Q_OBJECT sein
Q_OBJECT
public:
    CustomTableView(QSqlRelationalTableModel *model);
// s. 21 Summerfield, Erklärung zu slots und signals
public slots:
    void delete_row(int row);
    void insert_row();

signals:
    void delete_pressed(int row);
    void insert_pressed();

private:
    void keyReleaseEvent(QKeyEvent *event);
};

#endif // CUSTOMTABLEVIEW_H
