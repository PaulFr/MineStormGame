#include "physicalobject.h"
#include <QPainterPath>
#include <QColor>
#include <QBrush>

PhysicalObject::PhysicalObject(QPoint position, int angle, int speed):_position(position)
{
    _angle = angle;
    setSpeed(speed);
}

void PhysicalObject::draw(QPainter &painter)
{
    painter.setBrush(QBrush(QColor(255,255,255)));
    QPainterPath path;
    path.addPolygon(this->getPolygonShape());

    painter.drawPath(path);
}

void PhysicalObject::step()
{
    //Moving the object
    _position.setX(_position.x()+_speed.x());
    _position.setY(_position.y()+_speed.y());

    if(_position.y() <= 0){
        _position.setY(_position.y() + _boundaries.height());
    }
    if(_position.y() >= _boundaries.height()){
        _position.setY(_position.y() - _boundaries.height());
    }
    if(_position.x() <= 0){
        _position.setX(_position.x() + _boundaries.width());
    }
    if(_position.x() >= _boundaries.width()){
        _position.setX(_position.x() - _boundaries.width());
    }
}

bool PhysicalObject::isIntersecting(PhysicalObject &physicalObject)
{
    return !(getPolygonShape().intersected(physicalObject.getPolygonShape()).isEmpty());
}

void PhysicalObject::setPosition(QPoint position)
{
    _position = position;
}

void PhysicalObject::setSpeed(int speed)
{
    _speed.setX(speed*sin(_angle*M_PI/180));
    _speed.setY(speed*cos(_angle*M_PI/180));
}

int PhysicalObject::getSpeed()
{
    return sqrt(_speed.x()*_speed.x()+_speed.y()*_speed.y());
}

void PhysicalObject::setAngle(int angle)
{
    _angle = angle;
}

void PhysicalObject::setBoundaries(QSize boundaries){
    _boundaries = boundaries;
}

int PhysicalObject::getAngle()
{
    return _angle;
}

QPoint PhysicalObject::getPosition()
{

}

