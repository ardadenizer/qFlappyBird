#include "bird.h"

Bird::Bird(QWidget *parent,uint32_t xPos, uint32_t yPos): Entity(parent, xPos, yPos)
{
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
    qDebug() << "QLabel bird geometry:" << this->geometry();
    qDebug() << "QLabel bird is visible:" << this->isVisible();

    this->setFocusPolicy(Qt::StrongFocus);

    m_audioOutput = std::make_unique<QAudioOutput>(this);
    m_birdJumpEffect = std::make_unique<QMediaPlayer>(this);

    m_birdJumpEffect->setAudioOutput(m_audioOutput.get());

    m_birdJumpEffect->setSource(QUrl::fromLocalFile("../../Assets/sounds/flap.wav"));

    m_audioOutput->setVolume(0.5);

    if (m_birdJumpEffect->mediaStatus() == QMediaPlayer::LoadedMedia) {
        qDebug() << "Media loaded successfully";
    } else {
        qDebug() << "Failed to load media";
    }

    // Initialization of jump animation:
    m_jumpAnimation = std::make_unique<QPropertyAnimation>(this, "geometry");
    m_jumpAnimation->setDuration(BIRD_JUMP_DURATION);
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
            m_birdJumpEffect->play();
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

    rotateBird(-45);
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

    if (m_yPos < BIRD_FALL_Y_TARGET)
    {
        m_freeFallAnimation->stop();
        m_freeFallAnimation->setStartValue(currentRect);
        m_freeFallAnimation->setEndValue(QRect(m_xPos, BIRD_FALL_Y_TARGET, currentRect.width(), currentRect.height()));
        m_freeFallAnimation->setDuration(BIRD_FALL_DURATION);
        m_freeFallAnimation->start();

        rotateBird(45);
    }
    else
    {
        m_freeFallAnimation->stop();  // Stop moving if we've reached the bottom
        // Raise a flag so game can know when bird has fallen to the ground.
        qDebug() << "Reached bottom, stopping downward movement.";
    }
}


void Bird::rotateBird(int direction)
{
    QTransform transform;
    transform.rotate(direction);  // Rotate by the value entered
    QPixmap rotatedPixmap = birdPixMap.transformed(transform, Qt::SmoothTransformation);

    this->setPixmap(rotatedPixmap);

    this->setGeometry(this->x(), this->y(), rotatedPixmap.width(), rotatedPixmap.height());
}

