#ifndef PHYSICALOBJECT_H
#define PHYSICALOBJECT_H
#define _USE_MATH_DEFINES

#include <QPainter>
#include <QPoint>
#include <QPolygon>
#include <QSize>

class PhysicalObject
{
public:
    /**
     * @brief create a PhysicalObject
     * @param position : current position
     */
    PhysicalObject(QPoint position = QPoint(0,0), int angle = 0, int speed = 0);

    /**
     * @brief draw the object
     * @param painter : QPainter used to draw the object in
     */
    void draw(QPainter &painter);
    /**
     * @brief step : called each time we are entering a new frame
     */
    void step();

    /**
     * @brief isIntersecting : return wether the object is intersecting another one or not
     * @param PhysicalObject : the other physical object
     * @return boolean
     */
    bool isIntersecting(PhysicalObject &physicalObject);
    /**
     * @brief setPosition : Set the position of the object
     * @param position
     */
    void setPosition(QPoint position);
    /**
     * @brief setSpeed : set the speed of the object
     * @param speed
     */
    void setSpeed(int speed);
    /**
     * @brief setAngle : set the angle of the object
     * @param angle
     */
    void setAngle(int angle);
    /**
     * @brief getSpeed : get the current speed of the object
     * @return int speed
     */
    int getSpeed();
    /**
     * @brief getAngle : get the current angle (determine the direction) of the object
     * @return int angle
     */
    int getAngle();
    /**
     * @brief getPosition : return the current position of the object
     * @return QPoint
     */
    QPoint getPosition();

    void setBoundaries(QSize boundaries);
protected:
    QPoint _position;
    QSize _boundaries;
    int _angle;
    QPoint _speed = QPoint(0,0);
    virtual QPolygon getPolygonShape() = 0;

};


#endif // PHYSICALOBJECT_H
