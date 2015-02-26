#-------------------------------------------------
#
# Project created by QtCreator 2014-05-03T13:23:53
#
#-------------------------------------------------

QT       += core gui sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MedicineDiary
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wndmedicrecord.cpp \
    basefunctions.cpp \
    dndao.cpp \
    dnmodel.cpp \
    dnserver.cpp

HEADERS  += mainwindow.h \
    wndmedicrecord.h \
    sqlfunctions.h \
    comdefine.h \
    basefunctions.h \
    dnserver.h \
    dnmodel.h \
    dndao.h

FORMS    += mainwindow.ui \
    wndmedicrecord.ui

LIBS += $${PWD}/libSqlFunctions.a
