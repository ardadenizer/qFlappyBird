#include "entity.h"

Entity::Entity(QWidget *parent, uint32_t xPos, uint32_t yPos) :
    QLabel(parent), m_xPos(xPos), m_yPos(yPos)
{
    // Additional initialization if necessary
}

void Entity::setPosX(uint32_t x)
{
    m_xPos = x;
    this->move(m_xPos,m_yPos);
}

void Entity::setPosY(uint32_t y)
{
    m_yPos = y;
    this->move(m_xPos,m_yPos);
}

uint32_t Entity::getPosX()
{
    return m_xPos;
}

uint32_t Entity::getPosY()
{
    return m_yPos;
}
