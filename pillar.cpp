#include "pillar.h"


Pillar::Pillar(QWidget *parent,unsigned int xPos, unsigned int yPos): Entity(parent, xPos, yPos)
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
    pillarPixMap = pillarPixMap.scaled(100, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    this->setPixmap(pillarPixMap);
    this->setGeometry(this->getPosX(), this->getPosY(), pillarPixMap.width(), pillarPixMap.height());
    this->raise();
    this->show();

    // Debugging output:
    qDebug() << "QLabel pillar geometry:" << this->geometry();
    qDebug() << "QLabel is pillar visible:" << this->isVisible();

}

unsigned int Pillar::calculatePillarGap()
{
    return QRandomGenerator::global()->bounded(150, 350);
}
