#ifndef BULLET_H
#define BULLET_H

#include "ephemeralobject.h"

class Bullet : public EphemeralObject
{
public:
    /**
     * @brief Create a Bullet fired by the spaceship
     * @param position where the bullet is fired
     * @param angle : direction the bullet's taking to aim the target
     * @param lifeTime : How much time the bullet is alive
     */
    Bullet(QPoint position, int angle, int lifeTime);
    virtual void draw(QPainter &painter) override;
private:
    QPolygon getPolygonShape();
};

#endif // BULLET_H
