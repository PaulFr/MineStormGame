#ifndef SPACESHIP_H
#define SPACESHIP_H
#define _USE_MATH_DEFINES

#include "physicalobject.h"
#include <math.h>


class Spaceship : public PhysicalObject
{
public:
    Spaceship(QPoint position);

    /**
     * @brief decreaseOrientation : Change the angle of the spaceship
     */
    void decreaseOrientation();
    /**
     * @brief increaseOrientation : Change the angle of the spaceship
     */
    void increaseOrientation();
    /**
     * @brief updateAcceleration : Give an acceleration
     * @param accelerate : true if positive acceleration, false otherwise
     */
    void updateAcceleration(bool accelerate);
    /**
     * @brief respawn : Reset the spaceship to default position
     */
    void respawn();
protected:
    QPolygon getPolygonShape();
    int _velocity = 0;
    int _shipSize = 15;
    QPoint _defaultPosition;
    void setSize(int shipSize);
private:
    /**
     * @brief getAbsolutePoint : Get the absolute point, with angle
     * @param relativePoint
     * @return QPoint : the absolute point
     */
    QPoint getAbsolutePoint(QPoint relativePoint) const;
};

#endif // SPACESHIP_H
