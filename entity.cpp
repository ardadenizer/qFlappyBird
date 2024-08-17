#include "entity.h"

Entity::Entity(unsigned int xVal, unsigned int yVal)
{
    setPosX(xVal);
    setPosY(yVal);
}

 void Entity::setPosX(unsigned int x)
{
    m_xPos = x;
    this->move(m_xPos,m_yPos);
}

void Entity::setPosY(unsigned int y)
{
    m_yPos = y;
    this->move(m_xPos,m_yPos);
}

unsigned int Entity::getPosX()
{
    return m_xPos;
}

unsigned int Entity::getPosY()
{
    return m_yPos;
}
