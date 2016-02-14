#ifndef EPHEMERALOBJECT_H
#define EPHEMERALOBJECT_H
#include "physicalobject.h"

/**
 * @brief The EphemeralObject class that represents an object with limited life time (short display time on the game)
 */
class EphemeralObject : public PhysicalObject
{
public:
    EphemeralObject(QPoint position, int lifeTime, int angle=0);
    virtual void step() override;

    /**
     * @brief isAlive : Is the object still displayable?
     * @return true or false
     */
    bool isAlive();
private:
    /**
     * @brief _lifeTime : How much time the object is alive
     */
    int _lifeTime;
};

#endif // EPHEMERALOBJECT_H
