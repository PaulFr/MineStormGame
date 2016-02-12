
QT       += core gui
CONFIG += C++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TD5
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controller.cpp \
    gameboard.cpp \
    game.cpp \
    dummygame.cpp

HEADERS  += mainwindow.h \
    controller.h \
    gameboard.h \
    game.h \
    dummygame.h

FORMS    +=
