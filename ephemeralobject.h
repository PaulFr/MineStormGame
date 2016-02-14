#ifndef EPHEMERALOBJECT_H
#define EPHEMERALOBJECT_H
#include "physicalobject.h"

class EphemeralObject : public PhysicalObject
{
public:
    EphemeralObject(QPoint position, int lifeTime, int angle=0);
    virtual void step() override;

    bool isAlive();
private:
    int _lifeTime;
};

#endif // EPHEMERALOBJECT_H
