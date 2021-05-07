/********************************************************************************
** Form generated from reading UI file 'mainwindowmYHkpD.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWMYHKPD_H
#define MAINWINDOWMYHKPD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabTabellen;
    QWidget *tabTest;
    QGridLayout *gridLayout_Test;
    QWidget *tabProdukt;
    QGridLayout *gridLayout_Produkt;
    QWidget *tabTester;
    QGridLayout *gridLayout_Tester;
    QWidget *tabTestarten;
    QGridLayout *gridLayout_Testarten;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pbEqual;
    QPushButton *pbUnequal;
    QPushButton *pbLess;
    QPushButton *pbMore;
    QPushButton *pbCancel;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_Schliessen;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(889, 606);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabTabellen = new QTabWidget(centralwidget);
        tabTabellen->setObjectName(QString::fromUtf8("tabTabellen"));
        tabTest = new QWidget();
        tabTest->setObjectName(QString::fromUtf8("tabTest"));
        gridLayout_Test = new QGridLayout(tabTest);
        gridLayout_Test->setObjectName(QString::fromUtf8("gridLayout_Test"));
        tabTabellen->addTab(tabTest, QString());
        tabProdukt = new QWidget();
        tabProdukt->setObjectName(QString::fromUtf8("tabProdukt"));
        gridLayout_Produkt = new QGridLayout(tabProdukt);
        gridLayout_Produkt->setObjectName(QString::fromUtf8("gridLayout_Produkt"));
        tabTabellen->addTab(tabProdukt, QString());
        tabTester = new QWidget();
        tabTester->setObjectName(QString::fromUtf8("tabTester"));
        gridLayout_Tester = new QGridLayout(tabTester);
        gridLayout_Tester->setObjectName(QString::fromUtf8("gridLayout_Tester"));
        tabTabellen->addTab(tabTester, QString());
        tabTestarten = new QWidget();
        tabTestarten->setObjectName(QString::fromUtf8("tabTestarten"));
        gridLayout_Testarten = new QGridLayout(tabTestarten);
        gridLayout_Testarten->setObjectName(QString::fromUtf8("gridLayout_Testarten"));
        tabTabellen->addTab(tabTestarten, QString());

        gridLayout->addWidget(tabTabellen, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        pbEqual = new QPushButton(centralwidget);
        pbEqual->setObjectName(QString::fromUtf8("pbEqual"));

        verticalLayout->addWidget(pbEqual);

        pbUnequal = new QPushButton(centralwidget);
        pbUnequal->setObjectName(QString::fromUtf8("pbUnequal"));

        verticalLayout->addWidget(pbUnequal);

        pbLess = new QPushButton(centralwidget);
        pbLess->setObjectName(QString::fromUtf8("pbLess"));

        verticalLayout->addWidget(pbLess);

        pbMore = new QPushButton(centralwidget);
        pbMore->setObjectName(QString::fromUtf8("pbMore"));

        verticalLayout->addWidget(pbMore);

        pbCancel = new QPushButton(centralwidget);
        pbCancel->setObjectName(QString::fromUtf8("pbCancel"));

        verticalLayout->addWidget(pbCancel);

        verticalSpacer = new QSpacerItem(20, 88, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton_Schliessen = new QPushButton(centralwidget);
        pushButton_Schliessen->setObjectName(QString::fromUtf8("pushButton_Schliessen"));

        verticalLayout->addWidget(pushButton_Schliessen);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 889, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(tabTabellen, pbEqual);
        QWidget::setTabOrder(pbEqual, pbUnequal);
        QWidget::setTabOrder(pbUnequal, pbLess);
        QWidget::setTabOrder(pbLess, pbMore);
        QWidget::setTabOrder(pbMore, pbCancel);
        QWidget::setTabOrder(pbCancel, pushButton_Schliessen);

        retranslateUi(MainWindow);

        tabTabellen->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "GUI-Tests", nullptr));
        tabTabellen->setTabText(tabTabellen->indexOf(tabTest), QCoreApplication::translate("MainWindow", "Test", nullptr));
        tabTabellen->setTabText(tabTabellen->indexOf(tabProdukt), QCoreApplication::translate("MainWindow", "Produkt", nullptr));
        tabTabellen->setTabText(tabTabellen->indexOf(tabTester), QCoreApplication::translate("MainWindow", "Tester", nullptr));
        tabTabellen->setTabText(tabTabellen->indexOf(tabTestarten), QCoreApplication::translate("MainWindow", "Testarten", nullptr));
        pbEqual->setText(QCoreApplication::translate("MainWindow", "Filter =", nullptr));
        pbUnequal->setText(QCoreApplication::translate("MainWindow", "Filter !=", nullptr));
        pbLess->setText(QCoreApplication::translate("MainWindow", "Filter <=", nullptr));
        pbMore->setText(QCoreApplication::translate("MainWindow", "Filter >=", nullptr));
        pbCancel->setText(QCoreApplication::translate("MainWindow", "Filter aufl\303\266sen", nullptr));
        pushButton_Schliessen->setText(QCoreApplication::translate("MainWindow", "Schliessen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWMYHKPD_H
