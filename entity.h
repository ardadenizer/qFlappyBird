#ifndef ENTITY_H
#define ENTITY_H

#include <QWidget>
#include <qlabel.h>

class Entity : public QLabel
{
private:
    unsigned int xPos;
    unsigned int yPos;
public:
    Entity();
    Entity(unsigned int xVal, unsigned int yVal);
    unsigned int getPosX();
    unsigned int getPosY();
    void setPosX(unsigned int x);
    void setPosY(unsigned int y);

};

#endif // ENTITY_H
