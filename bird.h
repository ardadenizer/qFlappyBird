#ifndef BIRD_H
#define BIRD_H

#include "entity.h"
#include <QKeyEvent>
#include <QDebug>
#include <QPropertyAnimation>
#include <memory>

class Bird: public Entity
{
    Q_OBJECT

    public:
        Bird(QWidget *parent = nullptr,unsigned int xPos = 0,unsigned int yPos = 300);
        ~Bird();
        using Entity::Entity; // Uses constructors from Entity class if required

    protected:
        void keyPressEvent(QKeyEvent *event) override;

    private slots:
        void startAnimation(const QRect &startRect, const QRect &endRect);
        void updatePosition();

    private:
        std::unique_ptr<QPropertyAnimation> animation;

};

#endif // BIRD_H
