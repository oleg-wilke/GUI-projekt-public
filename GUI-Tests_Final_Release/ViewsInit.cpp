#include "ViewsInit.h"

ViewsInit::ViewsInit()
{
    QString s_createTables[4] = {"CREATE TABLE test_arten (id INTEGER PRIMARY KEY,"
                                 " test_name VARCHAR(40) NOT NULL,"
                                 " descr VARCHAR(255))",
                                 "CREATE TABLE tester (id INTEGER PRIMARY KEY,"
                                 " name VARCHAR(40) NOT NULL,"
                                 " descr VARCHAR(255))",
                                 "CREATE TABLE produkte (id INTEGER PRIMARY KEY,"
                                 " product_name VARCHAR(40) NOT NULL,"
                                 " serial_number VARCHAR(40) NOT NULL,"
                                 " ram_size_kb INT NOT NULL,"
                                 " flash_size_kb INT NOT NULL,"
                                 " clock BOOLEAN NOT NULL,"
                                 " industrial BOOLEAN NOT NULL)",
                                 "CREATE TABLE test (id INTEGER PRIMARY KEY,"
                                 " id_produkte INT NOT NULL,"
                                 " id_tester INT NOT NULL,"
                                 " id_test_arten INT NOT NULL,"
                                 " test_status BOOLEAN NOT NULL,"
                                 " date_of_test DATE NOT NULL,"
                                 " descr VARCHAR(255))"};
    // bekommen initialisierte DB
        QSqlQuery query;

    // überprüfen ob DB existiert
        if (!query.exec("SELECT id FROM test_arten"))
        {
            for(int i=0; i<4; i++)
            {
               query.exec(s_createTables[i]);
            }

            query.exec("INSERT INTO test_arten (test_name, descr) VALUES ('IO-Test', 'Input Output Test')");
            query.exec("INSERT INTO test_arten (test_name) VALUES ('RAM-Test')");
            query.exec("INSERT INTO test_arten (test_name, descr) VALUES ('Flash-Test', 'Testen des Flash Speichers')");
            query.exec("INSERT INTO test_arten (test_name) VALUES ('WAKE-UP')");
            query.exec("INSERT INTO test_arten (test_name) VALUES ('Download-Test')");
            query.exec("INSERT INTO test_arten (test_name) VALUES ('Analog-Test')");

            query.exec("INSERT INTO tester (name, descr) VALUES ('Oleg', 'Azubi')");
            query.exec("INSERT INTO tester (name, descr) VALUES ('Alexander', 'Mitarbeiter')");
            query.exec("INSERT INTO tester (name, descr) VALUES ('David', 'aufpassen, wegen Fehlerhäufigkeit')");

            query.exec("INSERT INTO produkte (product_name, serial_number, ram_size_kb, flash_size_kb, clock, industrial)"
                        "VALUES ('Produkt1 512kb RAM, 512kb flash, clock, industrial', '12345-abc', '512', '512', '1', '1')");
            query.exec("INSERT INTO produkte (product_name, serial_number, ram_size_kb, flash_size_kb, clock, industrial)"
                        "VALUES ('Produkt2 256kb RAM, 256kb flash, clock', '12345-zzz', '256', '256', '1', '0')");
            query.exec("INSERT INTO produkte (product_name, serial_number, ram_size_kb, flash_size_kb, clock, industrial)"
                        "VALUES ('Produkt3 512kb RAM, 1024kb flash, clock, industrial', '12345-xxx', '512', '1024', '1', '1')");
            query.exec("INSERT INTO produkte (product_name, serial_number, ram_size_kb, flash_size_kb, clock, industrial)"
                        "VALUES ('Produkt4 256kb RAM, 256kb flash', '12345-zexx', '256', '256', '0', '0')");

            query.exec("INSERT INTO test (id_produkte, id_tester, id_test_arten, test_status, date_of_test)"
                        "VALUES ('1','2','3', '1','21/02/2021')");
            query.exec("INSERT INTO test (id_produkte, id_tester, id_test_arten, test_status, date_of_test)"
                        "VALUES ('2','3','3', '0','21/02/2019')");
            query.exec("INSERT INTO test (id_produkte, id_tester, id_test_arten, test_status, date_of_test)"
                        "VALUES ('3','2','3', '1','01/01/2020')");
        }

        Testarten_init();
        Tester_init();
        Produkte_init();
        Test_init();
}

ViewsInit::~ViewsInit()
{
    delete viewTester;
    delete viewTestarten;
    delete viewProdukte;
    delete viewTest;

    delete modelTester;
    delete modelTestarten;
    delete modelProdukte;
    delete modelTest;
}

// Summerfield s. 320
void ViewsInit::Testarten_init()
{
    QString s_headers[3] = {QObject::tr("ID"),
                            QObject::tr("Test Name"),
                            QObject::tr("Descr")};
    modelTestarten = new QSqlRelationalTableModel();
    modelTestarten->setTable("test_arten");
    modelTestarten->setEditStrategy(QSqlTableModel::OnRowChange);

    for(int i=0; i<3; i++)
    {
        modelTestarten->setHeaderData(i, Qt::Horizontal, s_headers[i]);
    }

    modelTestarten->select();
    viewTestarten = new CustomTableView(modelTestarten);
}

void ViewsInit::Tester_init()
{
    QString s_headers[3] = {QObject::tr("ID"),
                            QObject::tr("Name"),
                            QObject::tr("Descr")};
    modelTester = new QSqlRelationalTableModel();
    modelTester->setTable("tester");
    modelTester->setEditStrategy(QSqlTableModel::OnRowChange); // neue Einträge werden durch wechseln in die andere Zeile aktiviert

    for(int i=0; i<3; i++)
    {
        modelTester->setHeaderData(i, Qt::Horizontal, s_headers[i]);
    }

    modelTester->select();
    viewTester = new CustomTableView(modelTester);
}

void ViewsInit::Produkte_init()
{
    QString s_headers[7] = {QObject::tr("ID"),
                            QObject::tr("Produkt Name"),
                            QObject::tr("Seriennummer"),
                            QObject::tr("RAM Größe kb"),
                            QObject::tr("Flash Größe kb"),
                            QObject::tr("Uhr"),
                            QObject::tr("Industrial")};
    modelProdukte = new QSqlRelationalTableModel();
    modelProdukte->setTable("produkte");
    modelProdukte->setEditStrategy(QSqlTableModel::OnRowChange);

    for(int i=0; i<7; i++)
    {
        modelProdukte->setHeaderData(i, Qt::Horizontal, s_headers[i]);
    }

    modelProdukte->select();
    viewProdukte = new CustomTableView(modelProdukte);
    viewProdukte->setItemDelegateForColumn(3, new ItemIntDelegate());
    viewProdukte->setItemDelegateForColumn(4, new ItemIntDelegate());
    viewProdukte->setItemDelegateForColumn(5, new ItemBoolDelegate());
    viewProdukte->setItemDelegateForColumn(6, new ItemBoolDelegate());
}

void ViewsInit::Test_init()
{
    QString s_headers[7] = {QObject::tr("ID"),
                            QObject::tr("Produkt Name"),
                            QObject::tr("Tester"),
                            QObject::tr("Test Arten"),
                            QObject::tr("Status"),
                            QObject::tr("Datum"),
                            QObject::tr("Descr")};
    modelTest = new QSqlRelationalTableModel();
    modelTest->setTable("test");
    modelTest->setRelation(1, QSqlRelation("produkte", "id", "product_name"));
    modelTest->setRelation(2, QSqlRelation("tester", "id", "name"));
    modelTest->setRelation(3, QSqlRelation("test_arten", "id", "test_name"));
    modelTest->setEditStrategy(QSqlTableModel::OnRowChange);

    for(int i=0; i<7; i++)
    {
        modelTest->setHeaderData(i, Qt::Horizontal, s_headers[i]);
    }

    modelTest->select();
    viewTest = new CustomTableViewWithMenuForTableTest(modelTest);
//S. 305 unten Summerfield
    viewTest->setItemDelegate(new QSqlRelationalDelegate());
    viewTest->setItemDelegateForColumn(4, new ItemBoolDelegate());
    viewTest->setItemDelegateForColumn(5, new ItemDateDelegate());
}
