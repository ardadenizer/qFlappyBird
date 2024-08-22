#ifndef PILLAR_H
#define PILLAR_H

#include "entity.h"
#include <QRandomGenerator>

class Pillar : public Entity
{
public:
    Pillar(QWidget *parent = nullptr, uint32_t xPos = 300, uint32_t yPos = 400);
    uint32_t calculatePillarGap();
};

#endif // PILLAR_H
