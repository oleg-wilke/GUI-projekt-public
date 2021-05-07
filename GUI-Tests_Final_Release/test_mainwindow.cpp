#include "test_mainwindow.h"


Test_MainWindow::Test_MainWindow(QWidget *parent)
    : QMainWindow(parent)
// mein Konstruktor
{
    ui = new Ui::MainWindow;
    ui->setupUi(this);
    ui->gridLayout_Testarten->addWidget(viewTestarten);
    ui->gridLayout_Tester->addWidget(viewTester);
    ui->gridLayout_Produkt->addWidget(viewProdukte);
    ui->gridLayout_Test->addWidget(viewTest);

    set_enable_to_extend_tabs(false);
    QObject::connect(ui->pushButton_Schliessen, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(ui->pbEqual, SIGNAL(clicked()), viewTest, SLOT(setFilterEqual()));
    QObject::connect(ui->pbUnequal, SIGNAL(clicked()), viewTest, SLOT(setFilterUnequal()));
    QObject::connect(ui->pbLess, SIGNAL(clicked()), viewTest, SLOT(setFilterLess()));
    QObject::connect(ui->pbMore, SIGNAL(clicked()), viewTest, SLOT(setFilterMore()));
    QObject::connect(ui->pbCancel, SIGNAL(clicked()), viewTest, SLOT(setFilterCancel()));
}

Test_MainWindow::~Test_MainWindow()
{
    delete ui;
}

void Test_MainWindow::set_enable_to_extend_tabs(bool b_enable)
{
    ui->tabProdukt->setDisabled(!b_enable);
    ui->tabTester->setDisabled(!b_enable);
    ui->tabTestarten->setDisabled(!b_enable);
}

void Test_MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (sCurrentPassword.length() <= sToAdminPassword.length()
            && event->key() >= Qt::Key_A
            && event->key() <= Qt::Key_Z)
    {
        sCurrentPassword.append(event->key());
        if (sCurrentPassword == sToAdminPassword)
        {
            set_enable_to_extend_tabs(true);
        }
    }
    QMainWindow::keyReleaseEvent(event);
}
