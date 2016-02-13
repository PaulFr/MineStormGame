#ifndef MINE_H
#define MINE_H

#include "physicalobject.h"
#include <random>

class Mine : public PhysicalObject
{
public:
    Mine(int size, QPoint position);
    QPolygon getPolygonShape();
    bool isAlive();
    virtual void draw(QPainter &painter) override;
    virtual void step() override;
protected:
    int _size;
    int _framesBeforeAlive = 0;
};

#endif // MINE_H
