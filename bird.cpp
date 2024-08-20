#include "bird.h"

Bird::Bird(QWidget *parent,unsigned int xPos, unsigned int yPos): Entity(parent, xPos, yPos)
{
    QPixmap birdPixMap;
    if (birdPixMap.load("../../Assets/bird.png"))
    {
        qDebug() << "Bird image is loaded!";
    }
    else
    {
        qDebug() << "Failed to load bird image.";
    }

    // Resizing bird image:
    birdPixMap = birdPixMap.scaled(100, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    this->setPixmap(birdPixMap);
    this->setGeometry(this->getPosX(), this->getPosY(), birdPixMap.width(), birdPixMap.height());
    this->raise();
    this->show();

    // Debugging output:
    qDebug() << "QLabel geometry:" << this->geometry();
    qDebug() << "QLabel visible:" << this->isVisible();

    this->setFocusPolicy(Qt::StrongFocus);

    // Initialization of jump animation:
    m_jumpAnimation = std::make_unique<QPropertyAnimation>(this, "geometry");
    m_jumpAnimation->setDuration(500);
    m_jumpAnimation->setEasingCurve(QEasingCurve::OutQuad);


    m_freeFallAnimation = std::make_unique<QPropertyAnimation>(this,"geometry");
    m_freeFallAnimation->setEasingCurve(QEasingCurve::InQuad);

    connect(m_jumpAnimation.get(), &QPropertyAnimation::stateChanged, this, &Bird::updatePosition);
    connect(m_freeFallAnimation.get(), &QPropertyAnimation::finished, this, &Bird::updatePosition);

    connect(m_jumpAnimation.get(), &QPropertyAnimation::finished, this, &Bird::startFreeFallAnimation);

    // Connect valueChanged signal to update position during animation
    connect(m_freeFallAnimation.get(), &QPropertyAnimation::valueChanged, this, &Bird::updatePositionDuringAnimation);

    // Start the free-fall animation initially
    startFreeFallAnimation();

}

Bird::~Bird()
{

}

void Bird::keyPressEvent(QKeyEvent *event)
{
    const int jumpStep = BIRD_JUMP_STEP;
    QRect startRect = this->geometry();
    QRect endRect = startRect;

    if (event != nullptr)
    {
        switch (event->key())
        {
        case Qt::Key_Space:
            if (m_yPos >= jumpStep) m_yPos -= jumpStep;
            qDebug() << "Space Key is pressed";
            break;
        case Qt::Key_Down:
            if (m_yPos + jumpStep < this->parentWidget()->height()) m_yPos += jumpStep;
            qDebug() << "Down Key is pressed";
            break;
        case Qt::Key_Right:
            if (m_xPos + jumpStep < this->parentWidget()->width()) m_xPos += jumpStep;
            qDebug() << "Right Key is pressed";
            break;
        default:
            QLabel::keyPressEvent(event);  // Call base class implementation for unhandled keys
            return;
        }

        endRect.moveTo(m_xPos, m_yPos);

        m_freeFallAnimation->stop();

        startjumpAnimation(startRect, endRect);

        qDebug() << "Bird position after animation: " << endRect.topLeft();
        qDebug() << "Bird position that class knows:" << this->getPosX() << this->getPosY();
    }
}

void Bird::startjumpAnimation(const QRect &startRect, const QRect &endRect)
{
    m_jumpAnimation->stop();
    m_jumpAnimation->setStartValue(startRect);
    m_jumpAnimation->setEndValue(endRect);
    m_jumpAnimation->start();
}

void Bird::updatePosition()
{
    // Update m_xPos and m_yPos based on the widget's current position
    m_xPos = this->x();
    m_yPos = this->y();
}

void Bird::updatePositionDuringAnimation(const QVariant &value)
{
    // Update m_xPos and m_yPos based on the current geometry during the animation
    QRect currentRect = value.toRect();
    m_xPos = currentRect.x();
    m_yPos = currentRect.y();
}

void Bird::startFreeFallAnimation()
{
    QRect currentRect = this->geometry();

    const unsigned int targetPosY = 450;

    if (m_yPos < targetPosY)
    {
        m_freeFallAnimation->stop();
        m_freeFallAnimation->setStartValue(currentRect);
        m_freeFallAnimation->setEndValue(QRect(m_xPos, targetPosY, currentRect.width(), currentRect.height()));
        m_freeFallAnimation->setDuration(BIRD_FALL_DURATION);
        m_freeFallAnimation->start();
    }
    else
    {
        m_freeFallAnimation->stop();  // Stop moving if we've reached the bottom
        qDebug() << "Reached bottom, stopping downward movement.";
    }
}
