#ifndef ENTITY_H
#define ENTITY_H

#include <QWidget>
#include <qlabel.h>

class Entity : public QLabel
{
protected:
    uint32_t m_xPos;
    uint32_t m_yPos;
public:
    using QLabel::QLabel; // Uses constructors from QLabel class

    Entity(QWidget *parent = nullptr, uint32_t xPos = 0,uint32_t yPos = 0);

    uint32_t getPosX();
    uint32_t getPosY();
    void setPosX(uint32_t x);
    void setPosY(uint32_t y);

};

#endif // ENTITY_H
