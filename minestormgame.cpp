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
    _mines.clear();

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
    if(_keySpace)
        fireBullet();

    _spaceship->step();

    //animate the mines
    for(auto &mine: _mines){
        mine.step();
    }

    //animate the bullets
    auto bullet = begin(_bullets);
    while (bullet != end(_bullets)) {
        bullet->step();
        if (!bullet->isAlive()){
            bullet = _bullets.erase(bullet);
        }
        else{
            //tests if the bullet collides a mine
            auto mine = begin(_mines);
            bool isShot = false;
            while(mine != end(_mines) && isShot == false){
                if(mine->isAlive() && mine->isIntersecting(*bullet)){
                    //The bullet got it
                    isShot = true;
                    mine = _mines.erase(mine);
                }else{
                    ++mine;
                }
            }
            if(isShot){
                bullet = _bullets.erase(bullet);
            }else{
                ++bullet;
            }

        }
    }
}

void MineStormGame::fireBullet(){
    ++_lastFire;
    if(_lastFire%5 == 0 || _bullets.size() == 0){
        Bullet currentBullet(Bullet(_spaceship->getPosition(), _spaceship->getAngle(), 60));
        currentBullet.setSpeed(10);
        currentBullet.setBoundaries(size());
        _bullets.push_back(currentBullet);
    }
}

void MineStormGame::draw(QPainter &painter, QRect &rect)
{
    QBrush blackColor(QColor(0,0,0));
    // We set the background color to black
    painter.fillRect(rect, blackColor);

    //draw spaceship
    _spaceship->draw(painter);

    //draw the mines
    for(auto &mine: _mines){
        mine.draw(painter);
    }

    //draw the bullets
    for(auto &bullet: _bullets){
        bullet.draw(painter);
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
