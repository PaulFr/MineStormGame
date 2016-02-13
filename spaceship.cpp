#include "spaceship.h"

Spaceship::Spaceship(QPoint position):PhysicalObject(position)
{
    _angle = 0;
}

void Spaceship::increaseOrientation(){
    _angle += 15;
    _velocity /= 2;
}

void Spaceship::decreaseOrientation(){
    _angle -= 15;
    _velocity /= 2;
}

QPoint Spaceship::getAbsolutePoint(QPoint relativePoint) const {
    QPoint absolutePoint = QPoint(_position.x()+relativePoint.x(), _position.y()+relativePoint.y());

    return QPoint(sin((_angle-90)*M_PI/180)*(absolutePoint.x()-_position.x()) - cos((_angle-90)*M_PI/180)*(absolutePoint.y()-_position.y()) + _position.x(),
                  cos((_angle-90)*M_PI/180)*(absolutePoint.x()-_position.x()) + sin((_angle-90)*M_PI/180)*(absolutePoint.y()-_position.y()) + _position.y());
}

void Spaceship::updateAcceleration(bool accelerate) {

    if(accelerate){
        _velocity++;
    }else{
        _velocity--;
    }

    if(_velocity >= 10){
        _velocity = 10;
    }
    if(_velocity <= 0){
        _velocity = 0;
    }
    setSpeed(_velocity);


    /*if (getSpeed() > _maxspeed) {
        setDirection(_angle);
        setSpeed(_maxspeed);
    }*/
}

QPolygon Spaceship::getPolygonShape(){
    QPolygon shipShape;

    shipShape << getAbsolutePoint(QPoint(-15, 0))
    << getAbsolutePoint(QPoint(-7.5, 15))
    << getAbsolutePoint(QPoint(0, 7.5))
    << getAbsolutePoint(QPoint(7.5, 15))
    << getAbsolutePoint(QPoint(15, 0))
    << getAbsolutePoint(QPoint(0, -30))
    << getAbsolutePoint(QPoint(-15, 0));



    return shipShape;
}
