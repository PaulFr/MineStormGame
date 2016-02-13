#include "mine.h"

Mine::Mine(int size, QPoint position):PhysicalObject(position)
{
    _size = size;
}

QPolygon Mine::getPolygonShape(){
    QPolygon mineShape;

    mineShape << QPoint(_position.x(), _position.y()+_size)
    << QPoint(_position.x()+(_size/3), _position.y()+(_size/3))
    << QPoint(_position.x()+_size, _position.y())
    << QPoint(_position.x()+(_size/3), _position.y()-(_size/3))
    << QPoint(_position.x(), _position.y()-_size)
    << QPoint(_position.x()-(_size/3), _position.y()-(_size/3))
    << QPoint(_position.x()-_size, _position.y())
    << QPoint(_position.x()-(_size/3), _position.y()+(_size/3))
    << QPoint(_position.x(), _position.y()+_size);



    return mineShape;
}
