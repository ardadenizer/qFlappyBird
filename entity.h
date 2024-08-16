#ifndef ENTITY_H
#define ENTITY_H

#include <QWidget>
#include <qlabel.h>

class Entity : public QLabel
{
private:
    unsigned int x_cordinate;
    unsigned int y_cordinate;
public:
     Entity();
};

#endif // ENTITY_H
