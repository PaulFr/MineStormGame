
QT       += core gui

CONFIG+=C++11 console debug

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MineStormGame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controller.cpp \
    gameboard.cpp \
    game.cpp \
    minestormgame.cpp \
    physicalobject.cpp \
    spaceship.cpp \
    mine.cpp \
    ephemeralobject.cpp \
    bullet.cpp \
    burst.cpp \
    minilifespaceship.cpp

HEADERS  += mainwindow.h \
    controller.h \
    gameboard.h \
    game.h \
    minestormgame.h \
    physicalobject.h \
    spaceship.h \
    mine.h \
    ephemeralobject.h \
    bullet.h \
    burst.h \
    minilifespaceship.h
