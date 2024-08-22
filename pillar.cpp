#include "pillar.h"


Pillar::Pillar(QWidget *parent,uint32_t xPos, uint32_t yPos): Entity(parent, xPos, yPos)
{
    QPixmap pillarPixMap;
    if (pillarPixMap.load("../../Assets/pillar.png"))
    {
        qDebug() << "Pillar image is loaded!";
    }
    else
    {
        qDebug() << "Failed to load the pillar image.";
    }

    // Resizing bird image:
    pillarPixMap = pillarPixMap.scaled((parent->width() * 0.1), (parent->height() * 0.3), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    this->setPixmap(pillarPixMap);
    this->setGeometry(this->getPosX(), this->getPosY(), pillarPixMap.width(), pillarPixMap.height());
    this->raise();
    this->show();

    // Debugging output:
    qDebug() << "QLabel pillar geometry:" << this->geometry();
    qDebug() << "QLabel is pillar visible:" << this->isVisible();

}

uint32_t Pillar::calculatePillarGap()
{
    return QRandomGenerator::global()->bounded(150, 350);
}
