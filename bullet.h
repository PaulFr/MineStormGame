#ifndef BULLET_H
#define BULLET_H

#include "ephemeralobject.h"

class Bullet : public EphemeralObject
{
public:
    Bullet(QPoint position, int angle, int lifeTime);
    virtual void draw(QPainter &painter) override;
private:
    QPolygon getPolygonShape();
};

#endif // BULLET_H
