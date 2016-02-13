#ifndef SPACESHIP_H
#define SPACESHIP_H
#define _USE_MATH_DEFINES

#include "physicalobject.h"
#include <math.h>


class Spaceship : public PhysicalObject
{
public:
    Spaceship(QPoint position);

    // PhysicalObject interface
    void decreaseOrientation();
    void increaseOrientation();
    void updateAcceleration(bool accelerate);
protected:
    QPolygon getPolygonShape();
    int _velocity = 0;
private:
    QPoint getAbsolutePoint(QPoint relativePoint) const;
};

#endif // SPACESHIP_H
