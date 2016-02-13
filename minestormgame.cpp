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
    _spaceship = new Spaceship(QPoint(size().width()/2, size().height()/2));
    _spaceship->setBoundaries(size());

    spawnMines(8,5);
    spawnMines(13, 20);
    spawnMines(20, 5);
}

void MineStormGame::step()
{
    if(_keyLeft)
        _spaceship->increaseOrientation();
    if(_keyRight)
        _spaceship->decreaseOrientation();
    if(_keyUp)
        _spaceship->updateAcceleration(true);
    if(_keyDown)
        _spaceship->updateAcceleration(false);

    _spaceship->step();

    //draw the mines
    for(auto &mine: _mines){
        mine.step();
    }
}

void MineStormGame::draw(QPainter &painter, QRect &rect)
{
    QBrush blackColor(QColor(0,0,0));
    // We set the background color to black
    painter.fillRect(rect, blackColor);

    //draw spaceship
    _spaceship->draw(painter);

    //animate the mines
    for(auto &mine: _mines){
        mine.draw(painter);
    }

}

void MineStormGame::mousePressed(int x, int y)
{

}

void MineStormGame::keyPressed(int key)
{
    keyHandler(key, true);
}

void MineStormGame::keyReleased(int key)
{
    keyHandler(key, false);
}

bool MineStormGame::keyHandler(int key, bool isPressed){
    switch(key) {
            case Qt::Key_Left:
                _keyLeft = isPressed;
                break;
            case Qt::Key_Right:
                _keyRight = isPressed;
                break;
            case Qt::Key_Up:
                _keyUp = isPressed;
                break;
            case Qt::Key_Down:
                _keyDown = isPressed;
                break;
            case Qt::Key_Space:
                _keySpace = isPressed;
                break;
        }
}

void MineStormGame::mouseReleased(int x, int y)
{

}

void MineStormGame::mouseMoved(int x, int y)
{

}

void MineStormGame::spawnMines(int sizeItem, int nbItem){
    for(int i =0; i < nbItem; i++){
        Mine iMine(Mine(sizeItem, QPoint(rand()%size().width(),rand()%size().height())));
        iMine.setAngle(rand()%360);
        iMine.setSpeed(2+(rand()%15));
        iMine.setBoundaries(size());
        _mines.push_back(iMine);
    }
}
