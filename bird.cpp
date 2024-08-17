#include "bird.h"

Bird::Bird() {}

void Bird::keyPressEvent(QKeyEvent *event)
{
    const int jumpStep = 20;

    if (event != nullptr)
    {
        switch (event->key())
        {
        case Qt::Key_Up:
            if (m_yPos >= jumpStep) m_yPos -= jumpStep;
            qDebug() << "Up Key is pressed";
            break;
        case Qt::Key_Space:
            m_yPos += jumpStep;
            qDebug() << "Space Key is pressed";
            break;
        case Qt::Key_Down:
            if (m_xPos >= jumpStep) m_xPos -= jumpStep;
            qDebug() << "Down Key is pressed";
            break;
        case Qt::Key_Right:
            m_xPos += jumpStep;
            break;
        default:
            QLabel::keyPressEvent(event);  // Call base class implementation for unhandled keys
            return;
        }

        this-> move(m_xPos,m_yPos);
    }
}
