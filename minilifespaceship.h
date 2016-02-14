#ifndef MINILIFESPACESHIP_H
#define MINILIFESPACESHIP_H
#include "spaceship.h"

class MiniLifeSpaceship : public Spaceship
{
public:
    MiniLifeSpaceship(QPoint position);
protected:
    bool _isMovingObject = false;
};

#endif // MINILIFESPACESHIP_H
