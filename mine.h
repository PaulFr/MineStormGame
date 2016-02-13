#ifndef MINE_H
#define MINE_H

#include "physicalobject.h"

class Mine : public PhysicalObject
{
public:
    Mine(int size, QPoint position);
    QPolygon getPolygonShape();
protected:
    int _size;
};

#endif // MINE_H
