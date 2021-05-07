QT       += core gui
QT       += sql widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ItemBoolDelegate.cpp \
    ItemDateDelegate.cpp \
    ViewsInit.cpp \
    customtableview.cpp \
    customtableviewwithmenufortabletest.cpp \
    itemintdelegate.cpp \
    main.cpp \
    test_mainwindow.cpp

HEADERS += \
    ItemBoolDelegate.h \
    ItemDateDelegate.h \
    ViewsInit.h \
    customtableview.h \
    customtableviewwithmenufortabletest.h \
    itemintdelegate.h \
    test_mainwindow.h \
    ui_mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
