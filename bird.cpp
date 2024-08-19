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

    // Initialize the QPropertyAnimation object
    animation = std::make_unique<QPropertyAnimation>(this, "geometry");
    animation->setDuration(500);
    animation->setEasingCurve(QEasingCurve::OutQuad);

    connect(animation.get(), &QPropertyAnimation::finished, this, &Bird::updatePosition);

    // Start the free fall movement timer
    freeFallTimer = std::make_unique<QTimer>(this);

    connect(freeFallTimer.get(), &QTimer::timeout, this, &Bird::freeFall);

    freeFallTimer->start(150);
}

Bird::~Bird()
{

}

void Bird::keyPressEvent(QKeyEvent *event)
{
    const int jumpStep = 150;
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
        startAnimation(startRect, endRect);
        qDebug() << "Bird position after animation: " << endRect.topLeft();
        qDebug() << "Bird position that class knows:" << this->getPosX() << this->getPosY();
    }
}

void Bird::startAnimation(const QRect &startRect, const QRect &endRect)
{
    animation->stop();
    animation->setStartValue(startRect);
    animation->setEndValue(endRect);
    animation->start();
}

void Bird::updatePosition()
{
    // Update m_xPos and m_yPos based on the widget's current position
    m_xPos = this->x();
    m_yPos = this->y();
}

void Bird::freeFall()
{
    const unsigned int stepSize = 20;  // Move downward by 5 pixels each interval
    const unsigned int bottomY = 500;  // Desired bottom Y coordinate

    if (m_yPos + stepSize <= bottomY)
    {
        m_yPos += stepSize;
        this->move(m_xPos, m_yPos);
        qDebug() << "Moving down, current position:" << QPoint(m_xPos, m_yPos);
    }
    else
    {
        freeFallTimer->stop();  // Stop moving if we've reached the bottom
        qDebug() << "Reached bottom, stopping downward movement.";
    }
}
