#include <QDialog>
#include <QApplication>
// Damit dieser header funktioniert muss man im pro-file QT += sql widgets eintragen
#include <QSql>
#include <QSqlDatabase>


#include "test_mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
// Erstellen von Objekt des Fensters

// Initialisieren der DB database
    QSqlDatabase database = QSqlDatabase::addDatabase(DB_DRIVER);
    database.setDatabaseName(DB_FILE);
    if (!database.open())
    {
         return false;
    }

// Übergeben von variable database
    Test_MainWindow ui;
    ui.show();

    return app.exec();
}

/*int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}*/


