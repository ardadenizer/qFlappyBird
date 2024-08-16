#include "entity.h"

Entity::Entity()
{
    // Default Constructor implementation
}

Entity::Entity(unsigned int xVal, unsigned int yVal)
{
    setPosX(xVal);
    setPosY(yVal);
}

 void Entity::setPosX(unsigned int x)
{
    xPos = x;
}

void Entity::setPosY(unsigned int y)
{
    yPos = y;
}

unsigned int Entity::getPosX()
{
    return xPos;
}


unsigned int Entity::getPosY()
{
    return yPos;
}
