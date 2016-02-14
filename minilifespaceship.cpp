#include "minilifespaceship.h"

MiniLifeSpaceship::MiniLifeSpaceship(QPoint position):Spaceship(position)
{
    setSize(7.5);
    _color = QColor(160,220,244);
}

