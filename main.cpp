#include "mainwindow.h"
#include "minestormgame.h"

#include <QSize>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MineStormGame game(QSize(900,600));
    MainWindow w(&game);
    return a.exec();
}
