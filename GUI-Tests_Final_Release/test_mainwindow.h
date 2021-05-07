#ifndef TEST_MAINWINDOW_H
#define TEST_MAINWINDOW_H

#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>

#include "ui_mainwindow.h"
#include "ViewsInit.h"

#define DB_FILE "gui_tests.db"
#define DB_DRIVER "QSQLITE"

class Test_MainWindow : public QMainWindow, public ViewsInit
{
public:
    Test_MainWindow(QWidget *parent = nullptr);
    ~Test_MainWindow();

private:
    void keyReleaseEvent(QKeyEvent *event);
    void set_enable_to_extend_tabs(bool b_enable);
    Ui::MainWindow *ui;

    const QString sToAdminPassword = "QWERTZ";
    QString sCurrentPassword = "";
};

#endif // TEST_MAINWINDOW_H
