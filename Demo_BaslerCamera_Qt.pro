#-------------------------------------------------
#
# Project created by QtCreator 2017-12-14T17:55:52 沙振宇
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Demo_BaslerCamera_Qt
TEMPLATE = app

CONFIG   += c++11

#--------------------------------------------Basler-------------------------------------------
INCLUDEPATH += $$PWD/include
LIBS += -L$$PWD/lib/Win32 -lGCBase_MD_VC120_v3_0_Basler_pylon_v5_0 -lGenApi_MD_VC120_v3_0_Basler_pylon_v5_0 -lPylonBase_MD_VC120_v5_0 -lPylonC_MD_VC120 -lPylonGUI_MD_VC120_v5_0 -lPylonUtility_MD_VC120_v5_0
#----------------------------------------------------------------------------------------------

CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/bin_debug
    LIBS += -L$$PWD/bin_debug
}
CONFIG(release, debug|release) {
    DESTDIR = $$PWD/bin_release
    LIBS += -L$$PWD/bin_release
}

SOURCES += main.cpp\
        mainwindow.cpp \
    BaslerCamera/sbaslercameracontrol.cpp

HEADERS  += mainwindow.h \
    BaslerCamera/sbaslercameracontrol.h

FORMS    += mainwindow.ui
