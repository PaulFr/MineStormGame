#include "bullet.h"
#include <QColor>
#include <QBrush>
#include <QRectF>

Bullet::Bullet(QPoint position, int angle, int lifeTime):EphemeralObject(position, lifeTime, angle)
{

}

void Bullet::draw(QPainter &painter){
    painter.setBrush(QBrush(QColor(0,255,125)));
    painter.drawEllipse(_position.x(),_position.y(), 5, 5);
}

QPolygon Bullet::getPolygonShape(){
    QPolygon bullet;
    bullet << QPoint(_position.x()-2.5, _position.y()+2.5)
           << QPoint(_position.x()+2.5, _position.y()+2.5)
           << QPoint(_position.x()+2.5, _position.y()-2.5)
           << QPoint(_position.x()-2.5, _position.y()-2.5)
           << QPoint(_position.x()-2.5, _position.y()+2.5);
    return bullet;
}
