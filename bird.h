#ifndef BIRD_H
#define BIRD_H

#include "constants.h"
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
    void startjumpAnimation(const QRect &startRect, const QRect &endRect);
    void startFreeFallAnimation();
    void updatePosition();
    void updatePositionDuringAnimation(const QVariant &value);

private:
    std::unique_ptr<QPropertyAnimation> m_jumpAnimation;
    std::unique_ptr<QPropertyAnimation> m_freeFallAnimation;

};

#endif // BIRD_H
