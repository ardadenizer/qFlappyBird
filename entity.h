#ifndef ENTITY_H
#define ENTITY_H

#include <QWidget>
#include <qlabel.h>

class Entity : public QLabel
{
protected:
    unsigned int m_xPos;
    unsigned int m_yPos;
public:
    using QLabel::QLabel; // Uses constructors from QLabel class

    Entity(QWidget *parent = nullptr, unsigned int xPos = 0, unsigned int yPos = 0);

    unsigned int getPosX();
    unsigned int getPosY();
    void setPosX(unsigned int x);
    void setPosY(unsigned int y);

};

#endif // ENTITY_H
