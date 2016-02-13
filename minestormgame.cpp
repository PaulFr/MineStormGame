#include "minestormgame.h"

MineStormGame::MineStormGame(const QSize &size, QObject *parent):Game(size,parent)
{
    this->initialize();
}

MineStormGame::~MineStormGame()
{

}

void MineStormGame::initialize()
{

}

void MineStormGame::step()
{

}

void MineStormGame::draw(QPainter &painter, QRect &rect)
{
    QBrush blackColor(QColor(0,0,0));
    // We set the background color to black
    painter.fillRect(rect, blackColor);

}

void MineStormGame::mousePressed(int x, int y)
{

}

void MineStormGame::keyPressed(int key)
{

}

void MineStormGame::keyReleased(int key)
{

}

void MineStormGame::mouseReleased(int x, int y)
{

}

void MineStormGame::mouseMoved(int x, int y)
{

}
