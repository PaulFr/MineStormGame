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
private:
    int _expand = 6;
};

#endif // BURST_H
