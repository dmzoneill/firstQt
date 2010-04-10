# -------------------------------------------------
# Project created by QtCreator 2010-04-10T17:14:35
# -------------------------------------------------
TARGET = firstQt
TEMPLATE = app
INCLUDEPATH = /usr/include/mysql
LIBS = -L/usr/include/mysql \
    -lmysqlclient \
    -I/usr/include/mysql \
    -lcurl
SOURCES += main.cpp \
    mainwindow.cpp \
    db.cpp \
    curlfetch.cpp
HEADERS += mainwindow.h \
    db.h \
    curlfetch.h
FORMS += mainwindow.ui
QT += sql
