#ifndef MINE_H
#define MINE_H

#include "physicalobject.h"
#include <random>

/**
 * @brief The Mine class represents a mine.
 */
class Mine : public PhysicalObject
{
public:
    /**
     * @brief Mine
     * @param size of the mine
     * @param position of the mine
     */
    Mine(int size, QPoint position);
    QPolygon getPolygonShape();
    /**
     * @brief isAlive : Is the mine active or not born yet?
     * @return true or false
     */
    bool isAlive();
    virtual void draw(QPainter &painter) override;
    virtual void step() override;
protected:
    /**
     * @brief _size of the mine
     */
    int _size;
    /**
     * @brief _framesBeforeAlive : how much step iteration before the mine is enabled
     */
    int _framesBeforeAlive = 0;
};

#endif // MINE_H
