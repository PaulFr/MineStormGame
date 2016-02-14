#include "ephemeralobject.h"

EphemeralObject::EphemeralObject(QPoint position, int lifeTime, int angle):PhysicalObject(position, angle), _lifeTime(lifeTime)
{

}

bool EphemeralObject::isAlive(){
    return _lifeTime > 0;
}

void EphemeralObject::step(){
    PhysicalObject::step();
    _lifeTime--;
}
