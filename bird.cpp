#include "bird.h"

Bird::Bird(QWidget *parent,unsigned int xPos, unsigned int yPos): Entity(parent, xPos, yPos)
{
    QPixmap birdPixMap;
    if (birdPixMap.load("../../Assets/bird.png")) {
        qDebug() << "Bird image is loaded!";
    } else {
        qDebug() << "Failed to load bird image.";
    }

    birdPixMap = birdPixMap.scaled(100, 70, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    this->setPixmap(birdPixMap);
    this->setGeometry(this->getPosX(), this->getPosY(), birdPixMap.width(), birdPixMap.height());
    this->raise();
    this->show();

    // Debugging output:
    qDebug() << "QLabel geometry:" << this->geometry();
    qDebug() << "QLabel visible:" << this->isVisible();

    this->setFocusPolicy(Qt::StrongFocus);
}

Bird::~Bird()
{

}

void Bird::keyPressEvent(QKeyEvent *event)
{
    const int jumpStep = 150;

    if (event != nullptr)
    {
        switch (event->key())
        {
        case Qt::Key_Space:
            if (m_yPos >= jumpStep) m_yPos -= jumpStep;
            qDebug() << "Space Key is pressed";
            break;
        case Qt::Key_Up:
            if (m_yPos >= 20) m_yPos -= 20;
            qDebug() << "Up Key is pressed";
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

        this-> move(m_xPos,m_yPos);
    }
}
