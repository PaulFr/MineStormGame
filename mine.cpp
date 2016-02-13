#include "mine.h"
#include <QRect>



Mine::Mine(int size, QPoint position):PhysicalObject(position)
{
    _size = size;
    _framesBeforeAlive = 3+(rand()%300);
    //qDebug() << "Hop : " << _framesBeforeAlive;
}

bool Mine::isAlive(){
    return _framesBeforeAlive <= 0;
}

void Mine::draw(QPainter &painter){
    painter.setBrush(QBrush(QColor(255,255,255)));

    if(isAlive()){
        QPainterPath path;
        path.addPolygon(this->getPolygonShape());
        painter.drawPath(path);
    }else{
        painter.setBrush(QBrush(QColor(255,0,0)));
        painter.drawRect(QRect(QPoint(_position.x()-2,_position.y()+2), QPoint(_position.x()+2,_position.y()-2)));
    }

}

void Mine::step(){
    if(isAlive()){
        PhysicalObject::step();
    }else{
        _framesBeforeAlive--;
    }
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
