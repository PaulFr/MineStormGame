#ifndef BURST_H
#define BURST_H
#include "ephemeralobject.h"

class Burst : public EphemeralObject
{
public:
    /**
     * @brief Burst an explosion (when a mine or a spaceship explodes)
     * @param position of the burst
     * @param lifeTime : How much time the burst is displayed
     */
    Burst(QPoint position, int lifeTime);
    virtual void step() override;
protected:
    QPolygon getPolygonShape();
    bool _isMovingObject = false;
private:
    /**
     * @brief _expand : Maximum size of the burst
     */
    int _expand = 10;
};

#endif // BURST_H
