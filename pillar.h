#ifndef PILLAR_H
#define PILLAR_H

#include "entity.h"
#include <QRandomGenerator>

class Pillar : public Entity
{
public:
    Pillar(QWidget *parent = nullptr,unsigned int xPos = 300,unsigned int yPos = 350);
    unsigned int calculatePillarGap();
};

#endif // PILLAR_H
