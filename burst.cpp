#include "burst.h"

Burst::Burst(QPoint position, int lifeTime):EphemeralObject(position, lifeTime)
{
    _color = QColor(255,0,0);
}

void Burst::step(){
    EphemeralObject::step();
    _expand++;
    _speed.setX(0);
    _speed.setY(0);
}

QPolygon Burst::getPolygonShape(){
    QPolygon burstShape;
    burstShape << QPoint(_position.x(), _position.y()+_expand)
    << QPoint(_position.x()+(_expand/10), _position.y()+(_expand/10))
    << QPoint(_position.x()+_expand, _position.y())
    << QPoint(_position.x()+(_expand/10), _position.y()-(_expand/10))
    << QPoint(_position.x(), _position.y()-_expand)
    << QPoint(_position.x()-(_expand/10), _position.y()-(_expand/10))
    << QPoint(_position.x()-_expand, _position.y())
    << QPoint(_position.x()-(_expand/10), _position.y()+(_expand/10))
    << QPoint(_position.x(), _position.y()+_expand);
    return burstShape;
}


