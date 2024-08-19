#ifndef BIRD_H
#define BIRD_H

#include "entity.h"
#include <QKeyEvent>
#include <QDebug>

class Bird: public Entity
{
    Q_OBJECT

    public:
        Bird(QWidget *parent = nullptr,unsigned int xPos = 0,unsigned int yPos = 300);
        ~Bird();
        using Entity::Entity; // Uses constructors from Entity class

    protected:
        void keyPressEvent(QKeyEvent *event) override;
};

#endif // BIRD_H
