#ifndef BURST_H
#define BURST_H
#include "ephemeralobject.h"

class Burst : public EphemeralObject
{
public:
    Burst(QPoint position, int lifeTime);
    virtual void step() override;
protected:
    QPolygon getPolygonShape();
    bool _isMovingObject = false;
private:
    int _expand = 10;
};

#endif // BURST_H
