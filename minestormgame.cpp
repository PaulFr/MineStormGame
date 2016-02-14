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
    _bullets.clear();
    _bursts.clear();

    spawnMines(8,5);
    spawnMines(13, 20);
    spawnMines(20, 5);

    _spaceship = new Spaceship(QPoint(size().width()/2, size().height()/2));
    _spaceship->setBoundaries(size());
    _playerAlive = true;

}

void MineStormGame::step()
{
    if(_playerAlive){
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
    }
    //animate the mines
    auto mine = begin(_mines);
    while(mine != end(_mines)){
        mine->step();
        if(_playerAlive && mine->isAlive() && mine->isIntersecting(*_spaceship)){
            Burst nBurst(Burst(mine->getPosition(), 40));
            nBurst.setBoundaries(size());
            _bursts.push_back(nBurst);

            nBurst = Burst(_spaceship->getPosition(), 40);
            nBurst.setBoundaries(size());
            _bursts.push_back(nBurst);


            _playerAlive = false;
            mine = _mines.erase(mine);
        }else{
            ++mine;
        }
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
            mine = begin(_mines);
            bool isShot = false;
            while(mine != end(_mines) && isShot == false){
                if(mine->isAlive() && mine->isIntersecting(*bullet)){
                    //The bullet got it
                    isShot = true;

                    //new burst
                    Burst nBurst(Burst(mine->getPosition(), 40));
                    nBurst.setBoundaries(size());
                    _bursts.push_back(nBurst);

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

    //animate bursts
    auto burst = begin(_bursts);
    while(burst != end(_bursts)){
        burst->step();
        if (!burst->isAlive()){
            burst = _bursts.erase(burst);
        }else{
            ++burst;
        }
    }
}

void MineStormGame::fireBullet(){
    ++_lastFire;
    if(_lastFire%5 == 0 || _bullets.size() == 0){
        Bullet currentBullet(Bullet(_spaceship->getPosition(), _spaceship->getAngle(), 30));
        currentBullet.setSpeed(15);
        currentBullet.setBoundaries(size());
        _bullets.push_back(currentBullet);
    }
}

void MineStormGame::draw(QPainter &painter, QRect &rect)
{
    QBrush blackColor(QColor(0,0,0));
    // We set the background color to black
    painter.fillRect(rect, blackColor);

    if(_playerAlive){
        //draw spaceship
        _spaceship->draw(painter);
    }
    //draw the mines
    for(auto &mine: _mines){
        mine.draw(painter);
    }

    //draw the bullets
    for(auto &bullet: _bullets){
        bullet.draw(painter);
    }

    //draw the air (maybe space but that is weird considering there is no air in space) bursts
    for(auto &burst: _bursts){
        burst.draw(painter);
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
